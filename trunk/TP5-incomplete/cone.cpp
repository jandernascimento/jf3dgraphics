#include "cone.h"
#include "material.h"

#include <GL/glut.h>

#include <cmath>
#include <float.h>

// use qglviewer namespace to avoid having to write qglviewer:: to use
// qglviewer-defined classes
using namespace qglviewer;
using namespace std;

Cone::Cone()
{
  setRadius(1.0f);
  setHeight(1.2f);
}

void Cone::draw() const
{
  glColor3fv(material().diffuseColor());
 
  glPushMatrix ( ) ;
  {
  glMultMatrixd(frame_.matrix());
  
  int nbFaces = 50;
  float stepAngle = 2*M_PI/nbFaces;
  float angle = 0.0;

  // draw base :
  // TO DO
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, 0.0, 0.0);
    for (int i = 0; i <= nbFaces; i++) {
      glVertex3f(radius_ * cos(angle), 0.0, radius_ * sin(angle));
      angle += stepAngle;
    }
  glEnd();
  
  // draw apex :
  // TO DO
  angle = 0.0;
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, height_, 0.0);
    for (int i = 0; i <= nbFaces; i++) {
      glVertex3f(radius_ * cos(angle), 0.0, radius_ * sin(angle));
      angle += stepAngle;
    }
  glEnd();
 
  }
  glPopMatrix();
  
}

bool Cone::intersect(const Ray& ray, Hit& hit) const
{
  float dist = FLT_MAX;

  // to remove "unused parameter" warnings - to be removed
  Q_UNUSED(ray)
  Q_UNUSED(hit)

  // TODO

  return dist != FLT_MAX;
}

