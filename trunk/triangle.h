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
  float* getFirst() { return first_; }
  void setFirst(float *first) { 
    first_[0] = first[0];
    first_[1] = first[1];
    first_[2] = first[2];
  }
  
  float* getSecond() { return second_; }
  void setSecond (float *second) { 
    second_[0] = second[0];
    second_[1] = second[1];
    second_[2] = second[2];
  }
  
  float* getThird() { return third_; }
  void setThird (float *third) { 
    third_[0] = third[0];
    third_[1] = third[1];
    third_[2] = third[2];
  }
  
  virtual float boundingRadius() const { return 1.0; }
  
  virtual bool intersect(const Ray&, Hit& hit) const;

  // Draw using OpenGL
  virtual void draw() const;

private:

  //Coordinates of the triangle 
  float first_[3];
  float second_[3];
  float third_[3];
};
