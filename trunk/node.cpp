#include "node.h"
#include "sphere.h"

#include <float.h>
#include <qmessagebox.h>

using namespace std;

/* Constructor
 */
Node::Node() 
{
}

/* Destructor
 */
Node::~Node()
{
  std::list<const Object*>::const_iterator iter = _leaves.begin();
  for(; iter != _leaves.end(); )
    {
      delete (*iter++);
    }
}

/* Add a node in the current tree
 */
void Node::addObject(const Object* node) 
{
  _leaves.push_back(node);
}

/* OpenGL display of the Node
 * We display all of the leaves of the current Node 
 */ 
void Node::draw() const 
{
  // TODO
  
  std::list<const Object*>::const_iterator iter;

  for (iter = _leaves.begin(); iter != _leaves.end(); ++iter) {
    (*iter)->draw();
  }
}

/* Radius of the scene node
 * We use radius caching to speed up things
 */
float Node::boundingRadius() const 
{
  static float radius = 0.0f;

  // TODO
	
  return radius;
}

/* Intersection between the ray and the list of all object in this
 * node 
 */
bool Node::intersect(const Ray& ray, Hit& min_dist_hit) const 
{
  float dist = FLT_MAX;

  // to remove "unused parameter" warnings - to be removed
  Q_UNUSED(ray)
  Q_UNUSED(min_dist_hit)

  // TODO

  return dist != FLT_MAX; 
}

/* Load the Node from a XML
 */
void Node::initFromDOMElement(const QDomElement& e)
{
  Object::initFromDOMElement(e);

  QDomNode n = e.firstChild();
  while (!n.isNull())
    {      
      QDomElement e = n.toElement();
      if (!e.isNull())
	{
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
	  else
	    {
	      cout << "TODO element : "; //<< qPrintable(e.tagName()) << endl;
	    }
	  // TODO others nodes
	}
      else
	QMessageBox::warning(NULL, "Object XML error", "Error while parsing Object XML document");
      n = n.nextSibling();
    }
}
