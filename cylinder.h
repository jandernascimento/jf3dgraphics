#pragma once

#include "object.h"

#include <vector>

class Cylinder: public Object
{
public :
  // Set default parameters. Radius is 1.0, Height is 1.0
  //position is 0,0,0. 
  Cylinder();
  virtual ~Cylinder() {};
  
  // Accessors
  float radius() const { return radius_; }
  void setRadius(float radius) { radius_ = radius; }
  
  float height() const { return height_; }
  void setHeight(float height) { height_ = height; }

  virtual float boundingRadius() const { return height(); }
  
  virtual bool intersect(const Ray&, Hit& hit) const;

  // Draw using OpenGL
  virtual void draw() const;

private:

  // Radius of the cylinder
  float radius_;
  // Height of the cylinder
  float height_;
};
