#include "triangle.h"
#include "material.h"

#include <GL/glut.h>

#include <cmath>
#include <float.h>

// use qglviewer namespace to avoid having to write qglviewer:: to use
// qglviewer-defined classes
using namespace qglviewer;
using namespace std;

Triangle::Triangle()
{
  float first[3] = {0.0, 0.0, 0.0}; 
  float second[3] = {0.0, 1.0, 0.0};
  float third[3] = {1.0, 0.0, 0.0};

  setFirst(first);
  setSecond(second);
  setThird(third);

}

void Triangle::draw() const
{
  glColor3fv(material().diffuseColor());
 
  glPushMatrix ( ) ; 
  {
  glMultMatrixd(frame_.matrix());
  
  glBegin(GL_TRIANGLES);
    glVertex3fv(first_);
    glVertex3fv(second_);
    glVertex3fv(third_);
  glEnd();

  }
  glPopMatrix();
  
}

bool Triangle::intersect(const Ray& ray, Hit& hit) const
{
  float dist = FLT_MAX;

  // to remove "unused parameter" warnings - to be removed
  Q_UNUSED(ray)
  Q_UNUSED(hit)

  // TODO

  return dist != FLT_MAX;
}

