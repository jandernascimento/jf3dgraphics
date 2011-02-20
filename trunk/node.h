#pragma once

#include "object.h"

#include <list>

class Node : public Object
{
public:
  // Constructor & Destructor
  Node() ;
  ~Node() ;

  // Add a leave to the current node
  // We force the node to be non modifiable
  void addObject(const Object* node) ;

  // OpenGL render method
  virtual void draw() const ;

  // Bounding sphere radius (even if rough estimate)
  virtual float boundingRadius() const ;

  // Raytracing: main method to intersect a viewing ray and this object
  virtual bool intersect(const Ray& ray, Hit& hit) const ;

  // Load from the XML
  virtual void initFromDOMElement(const QDomElement& e) ;

protected:
  // Object list
  std::list<const Object*> _leaves;

} ;
