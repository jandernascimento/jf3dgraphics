#pragma once

#include "object.h"

#include <vector>

class Triangle: public Object
{
public :
  // Set default parameters. Radius is 1.0, Height is 1.0
  //position is 0,0,0. 
  Triangle();
  virtual ~Triangle() {};
  
  // Accessors
  float* getFirst() const { return first_; }
  void setFirst(float *first) { first_ = first; }
  
  float* getSecond() const { return second_; }
  void setSecond(float *second) { second_ = second; }
  
  float* getThird() const { return third_; }
  void setThird(float *third) { third_ = third; }
  
  virtual float boundingRadius() const { return height(); }
  
  virtual bool intersect(const Ray&, Hit& hit) const;

  // Draw using OpenGL
  virtual void draw() const;

private:

  //Coordinates of the triangle 
  float first[3];
  float second[3];
  float third[3];
}
