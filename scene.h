#pragma once

#include "camera.h"
#include "node.h"
#include "ray.h"
#include "hit.h"

/// The Scene class, use for both the raytracing algorithm and
/// the openGL drawer
///
class Scene
{
public:
  // Constructor and destructor
  Scene() ;
  ~Scene() ;

  // Draw the current scene
  void draw() const;

  // Add an object to the top Node
  void addObject(Object* o);

  // Load a scene from a file 'filename'
  void loadFromFile(const QString& filename);

  // Get the center of the scene
  qglviewer::Vec center() const;

  // Radius of the scene
  float radius(const qglviewer::Vec& center) const;

  // Set the camera associated to the scene
  void setCamera(const Camera& camera) { camera_ = camera; }

  // Get the current camera in a constant form
  const Camera& camera() const { return camera_; }

  // Get the current camera associated to the scene
  Camera& camera() { return camera_; }

  // Does the ray intersect the scene
  bool intersect(const Ray& ray, Hit& hit);

private:
  // Camera object
  Camera camera_;

  // The Base node of the SceneGraph
  Node* _top_node;
};

