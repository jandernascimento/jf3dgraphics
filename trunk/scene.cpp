#include "scene.h"
#include "sphere.h"
#include <qfile.h>

using namespace qglviewer;
using namespace std;

/* Constructor
 */
Scene::Scene()
{
  // create top node as top-level container
  _top_node = new Node();
}

/* Destructor
 */
Scene::~Scene()
{
  // Delete the SceneGraph
  if(_top_node != NULL)
    delete _top_node;
}

/* OpenGL drawing calls
 */
void Scene::draw() const
{
  // TODO
  _top_node->draw();
}

/* Add an change the top node
 */
void Scene::addObject(Object* o)
{
  // TODO
  
  _top_node = (Node *)o;
  
  // To avoid warning. -> erase once used
  //Q_UNUSED(o)
  //addObject(_top_node);

}

/* Load a file from a filename
 */
void Scene::loadFromFile(const QString& filename)
{
  QDomDocument doc;
  QFile file(filename);
  //if (!file.open(QIODevice::ReadOnly))
    //return;
  if (!doc.setContent(&file)) {
    file.close();
    return;
  }
  file.close();

  // Parse all first elements
  QDomElement docElem = doc.documentElement();
  QDomNode n = docElem.firstChild();
  while(!n.isNull()) {
    QDomElement e = n.toElement();

    if(!e.isNull()) {
      if (e.tagName() == "Sphere")
	{
	  Sphere* s = new Sphere();
	  s->initFromDOMElement(e);
	  addObject(s);
	}
      else if(e.tagName() == "Node")
	{
	  Node* n = new Node();
	  n->initFromDOMElement(e);
	  addObject(n);
	}
      else if(e.tagName() == "Camera")
	{
	  camera_.initFromDOMElement(e);
	}
      else
	{
	  cout << "TODO element : ";// << qPrintable(e.tagName()) << endl;
	}
    }
    else
      {
	cerr << "Unable to parse this element" << endl;
      }
    n = n.nextSibling();
  }
}

/* Get the center of the scene
 */
Vec Scene::center() const
{
  // TODO

  return Vec();
}

/* Compute the radius of the scene
 */
float Scene::radius(const Vec& center) const
{
  // TODO

  // To erase
  Q_UNUSED(center)
  
  return 1.0;
}
