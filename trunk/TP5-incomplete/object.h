#ifndef OBJECT_H
#define OBJECT_H

#include "QGLViewer/qglviewer.h"
#include "material.h"
#include "hit.h"
#include "ray.h"

// Classe générique abstraite dont vont deriver les objets de la scene.
class Object
{
public :
  virtual ~Object() {};
  
  // Accessors
  const Material& material() const { return material_; }
  const qglviewer::Frame& frame() const { return frame_; }

  // Modifiers
  void setMaterial(const Material& material) { material_ = material; }
  void setFrame(const qglviewer::Frame& frame) { frame_ = frame; }

  // OpenGL render method
  virtual void draw() const = 0;

  // Bounding sphere radius (even if rough estimate)
  virtual float boundingRadius() const = 0;

  // Raytracing: main method to intersect a viewing ray and this object
  virtual bool intersect(const Ray&, Hit& hit) const = 0;

  virtual void initFromDOMElement(const QDomElement& e);

protected :
  // all objects possess a frame and material
  qglviewer::Frame frame_;
  Material material_;
};

#endif // OBJECT_H
