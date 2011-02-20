#include "viewer.h"
#include "scene.h"
#include <qfiledialog.h>
#if QT_VERSION > 0x040000
#include <QKeyEvent>
#endif
#include <math.h>

#include "sphere.h"
#include "cylinder.h"
#include "cone.h"
#include "triangle.h"

using namespace std;
using namespace qglviewer;

Viewer::~Viewer()
{
  delete scene_;
}

void Viewer::draw()
{
  // A FAIRE
  
  Scene *myscene = new Scene();
  Node *mynode = new Node();
  
  Sphere *mysph = new Sphere();
  mysph->setRadius(0.3f);
  Frame new_frame = Frame();
  new_frame.setPosition(0.0,2.0,0.0);
  mysph->setFrame(new_frame);
  mynode->addObject(mysph);
  //mysph->draw();
  
  
  Triangle *mytr = new Triangle();
  Frame new_frame2 = Frame();
  new_frame2.setPosition(0.0,-1.0,0.0);
  mytr->setFrame(new_frame2);
  mynode->addObject(mytr);
  
  Cone *mycone = new Cone();
  mycone->setRadius(0.3f);
  mycone->setHeight(0.9f);
  Frame new_frame3 = Frame();
  new_frame3.setPosition(0.0,0.0,2.0);
  mycone->setFrame(new_frame3);
  //mycone->draw();
  

  //mynode->draw();
  //mysph->draw();
  myscene->addObject(mynode);
  myscene->draw();


  

  /*
  const float nbSteps = 200.0;

  glBegin(GL_QUAD_STRIP);
  for (float i=0; i<nbSteps; ++i)
    {
      float ratio = i/nbSteps;
      float angle = 21.0*ratio;
      float c = cos(angle);
      float s = sin(angle);
      float r1 = 1.0 - 0.8*ratio;
      float r2 = 0.8 - 0.8*ratio;
      float alt = ratio - 0.5;
      const float nor = .5;
      const float up = sqrt(1.0-nor*nor);
      glColor3f(1.0-ratio, 0.2 , ratio);
      glNormal3f(nor*c, up, nor*s);
      glVertex3f(r1*c, alt, r1*s);
      glVertex3f(r2*c, alt+0.05, r2*s);
    }
  glEnd();
  */
}

void Viewer::init()
{
  // Key description for help window (press 'H')
  setKeyDescription(Qt::Key_L, "Loads a new scene");
  setKeyDescription(Qt::Key_S, "Shoot rays in the scene and saves the result");
  setKeyDescription(Qt::SHIFT+Qt::Key_S, "Shoot rays from <i>current</i> view point");

  setScene(new Scene());
  rayTracer_.setScene(scene());

  // So that transparent materials are correctly displayed.
  // Disable if rendering is too slow.
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Restore previous viewer state (camera, key frames...)
  restoreStateFromFile();

  // Loads scene (prevents from pressing 'L' at each start).
  loadScene("troisSpheres.scn");

  // Set Camera to scene Camera. Set scene center and radius.
  initFromScene();
}

QString Viewer::helpString() const
{
  QString text("<h2>L a n c e r   d e   r a y o n s</h2>");
  text += "Ajoutez ici toute aide utile à l'utilisateur. ";
  text += "N'oubliez pas de commenter vos raccourcis clavier avec setKeyDescription().<br>";
  text += "Appuyez sur <b>Escape</b> pour quitter.";
  return text;
}

void Viewer::keyPressEvent(QKeyEvent *e)
{
  switch (e->key())
    {
    case Qt::Key_L :
#if QT_VERSION < 0x040000
      loadScene(QFileDialog::getOpenFileName("", "Scenes (*.scn);;All files (*)", this));
#else
      loadScene(QFileDialog::getOpenFileName(this, "Select a scene", ".", "Scenes (*.scn);;All files (*)"));
#endif
      break;
    case Qt::Key_S :
#if QT_VERSION < 0x040000
      if ((e->state() == Qt::NoButton) || (e->state() == Qt::ShiftButton))
#else
      if ((e->modifiers() == Qt::NoModifier) || (e->modifiers() == Qt::ShiftModifier))
#endif	
	{
#if QT_VERSION < 0x040000
	  if (e->state() == Qt::ShiftButton)
#else
	  if (e->modifiers() == Qt::ShiftModifier)
#endif
	    {
	      // Shift+S renders image from current view point
	      scene()->camera().frame().setPosition(camera()->position());
	      scene()->camera().frame().setOrientation(camera()->orientation());
	    }
	  
	  rayTracer().renderImage();
	  // Remplacer cette ligne par : const QString name = "result.jpg";
	  // pour ne pas avoir à choisir un nom à chaque fois.
	  const QString name = QFileDialog::getSaveFileName();
	  rayTracer().saveImage(name);
	  
#if QT_VERSION < 0x040000
	  if ((e->state() == Qt::ShiftButton) && (camera()->keyFrameInterpolator(1)))
#else
	  if ((e->modifiers() == Qt::ShiftModifier) && (camera()->keyFrameInterpolator(1)))
#endif
	    {
	      // Restore initial scene camera
	      scene()->camera().frame().setPosition(camera()->keyFrameInterpolator(1)->keyFrame(0).position());
	      scene()->camera().frame().setOrientation(camera()->keyFrameInterpolator(1)->keyFrame(0).orientation());
	    }
	  break;
	}
    default :
      QGLViewer::keyPressEvent(e);
    }
}

void Viewer::loadScene(const QString& name)
{
  if (name.isEmpty())
    return;

  scene()->loadFromFile(name);
  
  // Change QGLViewer settings according to scene
  setSceneCenter(scene()->center());
  setSceneRadius(scene()->radius(sceneCenter()));

  // Set first camera key frame (F1) to camera position.
  initFromScene();
}

// Make the first keyFrameInterpolator (binded to F1) contain one position, that cooresponds to the
// scene's camera position. Attention, camera() is moved to camera position.
void Viewer::initFromScene()
{
  camera()->setPosition(scene()->camera().frame().position());
  camera()->setOrientation(scene()->camera().frame().orientation());
  camera()->setFieldOfView(scene()->camera().fieldOfView());
  
  // Remove previous keyFrames in path 1 (if any)
  if (camera()->keyFrameInterpolator(1))
    camera()->keyFrameInterpolator(1)->deletePath();

  // Add current (i.e. scene camera) position to F1.
  camera()->addKeyFrameToPath(1);
}
