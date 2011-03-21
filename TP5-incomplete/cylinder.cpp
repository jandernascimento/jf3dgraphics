#include "cylinder.h"
#include "material.h"

#include <GL/glut.h>

#include <cmath>
#include <float.h>

// use qglviewer namespace to avoid having to write qglviewer:: to use
// qglviewer-defined classes
using namespace qglviewer;
using namespace std;

Cylinder::Cylinder()
{
  setRadius(1.0f);
  setHeight(1.2f);
}

void Cylinder::draw() const
{
  glColor3fv(material().diffuseColor());

  glPushMatrix ( ) ;
  {
  glMultMatrixd(frame_.matrix());
  // TODO add your cylinder code
  
  int nbStrips = 20;
  int nbFacesPerStrip = 50;
  float stepAngle = 2*M_PI/nbFacesPerStrip;
  float angle = 0.0;

  // draw top :
  // TO DO
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, height_, 0.0);
    for (int i = 0; i <= nbFacesPerStrip; i++) {
      glVertex3f(radius_ * cos(angle), height_, radius_ * sin(angle));
      angle += stepAngle;
    }
  glEnd();

  // draw base :
  // TO DO
  angle = 0.0;
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, 0.0, 0.0);
    for (int i = 0; i <= nbFacesPerStrip; i++) {
      glVertex3f(radius_ * cos(angle), 0.0, radius_ * sin(angle));
      angle += stepAngle;
    }
  glEnd();

  // draw cylinder
  // TO DO
  angle = 0.0;
  glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(radius_ * cos(angle), height_, radius_ * sin(angle));
    for (int i = 0; i <= nbFacesPerStrip; i++) {
      glVertex3f(radius_ * cos(angle), 0.0,radius_ * sin(angle)); 
      angle += stepAngle;
      glVertex3f(radius_ * cos(angle), height_,radius_ * sin(angle)); 
    }
  glEnd();
  
  }
  glPopMatrix();
  
}

bool Cylinder::intersect(const Ray& ray, Hit& hit) const
{
  float dist = FLT_MAX;

  // to remove "unused parameter" warnings - to be removed
  Q_UNUSED(ray)
  Q_UNUSED(hit)

  // TODO

  return dist != FLT_MAX;
}

