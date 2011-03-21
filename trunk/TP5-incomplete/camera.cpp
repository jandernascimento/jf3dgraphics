#include "camera.h"
#include "scene.h"
#include "math.h"
#include <qmessagebox.h>

Camera::Camera()
{
  setXResolution(64);
  setYResolution(64);
  setFieldOfView(M_PI / 4.0);
}

void Camera::initFromDOMElement(const QDomElement& e)
{
  if (e.tagName() != "Camera")
    {
      QMessageBox::critical(NULL, "Camera init error", "Camera::initFromDOMElement, bad DOM tagName.\nExpecting 'Camera', got "+e.tagName());
      return;
    }

  if (!e.hasAttribute("fieldOfView"))
    QMessageBox::warning(NULL, "Camera error", "Camera has undefined fieldOfView. Using pi/4.");
  setFieldOfView(e.attribute("fieldOfView", "0.7854").toFloat());

  if (!e.hasAttribute("xResolution"))
    QMessageBox::warning(NULL, "Camera error", "Camera has undefined xResolution. Using 64.");
  setXResolution(e.attribute("xResolution", "64").toInt());

  if (!e.hasAttribute("yResolution"))
    QMessageBox::warning(NULL, "Camera error", "Camera has undefined yResolution. Using 64.");
  setYResolution(e.attribute("yResolution", "64").toInt());

  QDomNode n = e.firstChild();
  while (!n.isNull())
    {
      QDomElement e = n.toElement();
      if (!e.isNull())
	{
	  if (e.tagName() == "Frame")
	    frame_.initFromDOMElement(e);
	  else
	    QMessageBox::warning(NULL, "Camera child error", "Unsupported Camera child : "+e.tagName());
	}
      else
	QMessageBox::warning(NULL, "Camera XML error", "Error while parsing Camera XML document");
      n = n.nextSibling();
    }
}

void Camera::setXResolution(int xResolution)
{
  if (xResolution <= 0)
    {
      QMessageBox::warning(NULL, "Camera error", "Negative image xResolution - Skipping");
      return;
    }
  xResolution_ = xResolution;
}

void Camera::setYResolution(int yResolution)
{
  if (yResolution <= 0)
    {
      QMessageBox::warning(NULL, "Camera error", "Negative image yResolution - Skipping");
      return;
    }
  yResolution_ = yResolution;
}

void Camera::draw(float radius) const
{
  // A FAIRE

  // to remove "unused parameter" warnings - to be removed
  Q_UNUSED(radius)
}

Ray Camera::getPixelRay(float x, float y) const
{
  // A FAIRE
  float fov=fieldOfView_;
  float xresdiv2=(float)xResolution_/2;
  float yresdiv2=(float)yResolution_/2;

  float fovdistance=(yresdiv2)/tan(fov/2);

  const qglviewer::Vec go=qglviewer::Vec(xresdiv2,yresdiv2,fovdistance);
  const qglviewer::Vec go0=qglviewer::Vec(0,0,0);
  //frame_.setTranslation(go);
  
  float xp = xresdiv2 - x;
  float yp = yresdiv2 - y;
  
  const qglviewer::Vec distance_ = qglviewer::Vec(xp,yp,-1*fovdistance);
  const qglviewer::Vec distance_in_world = frame_.inverseCoordinatesOf(distance_);
  
  qglviewer::Vec start=go0;
  qglviewer::Vec direction=distance_in_world; 
  
  direction.normalize();
  direction = frame_.inverseTransformOf(direction);
  start = frame_.inverseCoordinatesOf(start);

  return Ray(start,direction);

  // to remove "unused parameter" warnings - to be removed
  //Q_UNUSED(x)
  //Q_UNUSED(y)

  //return Ray();
}

void Camera::drawAllRays() const
{
  for (int i=0; i<xResolution(); ++i)
    for (int j=0; j<yResolution(); ++j)
      getPixelRay(i,j).draw();
}
