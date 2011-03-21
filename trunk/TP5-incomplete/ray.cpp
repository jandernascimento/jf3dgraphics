#include "ray.h"
#include <qmessagebox.h>

using namespace qglviewer;

Ray::Ray()
{
  setStart(Vec());
  setDirection(Vec(0.0, 0.0, 1.0));
}

Ray::Ray(const Vec start, const Vec direction)
{
  setStart(start);
  setDirection(direction);
}

void Ray::setDirection(const Vec& direction)
{
  if (direction.norm() < 1e-8)
    {
      QMessageBox::critical(NULL, "Ray::setDirection error", "Null length direction in Ray::setDirection");
      return;
    }
  direction_ = direction;
  direction_.normalize();
}

void Ray::draw() const
{
  
	glBegin(GL_LINES);
	glVertex3f(direction_.x, direction_.y,direction_.z);
	glVertex3f(start_.x, start_.y,start_.z);

	glEnd();

}
