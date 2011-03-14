#include "sphere.h"
#include "material.h"

#include <GL/glut.h>

#include <cmath>
#include <float.h>

// oleg jander use qglviewer namespace to avoid having to write qglviewer:: to use
// qglviewer-defined classes
using namespace qglviewer;
using namespace std;

Sphere::Sphere()
{
  setRadius(1.0f);
}

void Sphere::init(float r, int ntheta, int nphi)
{
  // Set the radius for openGL
  setRadius(r);

  // to remove "unused parameter" warnings - to be removed
  Q_UNUSED(ntheta)
  Q_UNUSED(nphi)

  // TODO
}


void Sphere::draw() const
{
  
  glPushMatrix ( ) ;
{
glMultMatrixd(frame_.matrix());
// TODO add your sphere code
  
  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();
  
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glColor3fv(material().diffuseColor());
  gluSphere(quadratic,radius_,50,50);
/*
  glColor3fv(material().diffuseColor());
  
  int nbStrips = 20;
  int nbFacesPerStrip = 50;
  float stepAngle = 2*M_PI/nbFacesPerStrip;
  float angle = 0.0;

  // draw top :
  // TO DO
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, 1.0, 0.0);
    for (int i = 0; i <= nbFacesPerStrip; i++) {
      glVertex3f(cos(angle), 1.0, sin(angle));
      angle += stepAngle;
    }
  glEnd();

  // draw base :
  // TO DO
  angle = 0.0;
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, 0.0, 0.0);
    for (int i = 0; i <= nbFacesPerStrip; i++) {
      glVertex3f(cos(angle), 0.0, sin(angle));
      angle += stepAngle;
    }
  glEnd();

  // draw cylinder
  // TO DO
  angle = 0.0;
  glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(cos(angle), 1.0, sin(angle));
    for (int i = 0; i <= nbFacesPerStrip; i++) {
      glVertex3f(cos(angle), 0.0, sin(angle)); 
      angle += stepAngle;
      glVertex3f(cos(angle), 1.0, sin(angle)); 
    }
  glEnd();

*/
}
glPopMatrix();
  
  
  
}

/* Does the ray intersect any of the triangles composing
 * the current sphere ?
 */
bool Sphere::intersect(const Ray& ray, Hit& hit) const
{
  float dist = FLT_MAX;

  // to remove "unused parameter" warnings - to be removed
  Q_UNUSED(ray)
  Q_UNUSED(hit)

  // TODO

  return dist != FLT_MAX;
}

/* Parse the XML for elements of the Sphere
 */
void Sphere::initFromDOMElement(const QDomElement& e)
{
  // init the object part
  Object::initFromDOMElement(e);

  // Parse for ntheta, nphi, radius
  float radius = e.attribute("radius", "1.0").toFloat();
  int ntheta = e.attribute("ntheta", "10").toInt();
  int nphi = e.attribute("nphi", "10").toInt();
  init(radius, ntheta, nphi);

  draw();
}

