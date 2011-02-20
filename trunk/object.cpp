#include "object.h"
#include <qmessagebox.h>

void Object::initFromDOMElement(const QDomElement& e)
{
  QDomNode n = e.firstChild();
  while (!n.isNull())
    {      
      QDomElement e = n.toElement();
      if (!e.isNull())
	{
	  if (e.tagName() == "Material")
	    material_.initFromDOMElement(e);
	  else
	    if (e.tagName() == "Frame")
	      {
		frame_.initFromDOMElement(e);

		// Patch : Make sure the orientation is normalized.
		// Absolutely needed to correctly rotate rays.
		qglviewer::Quaternion o = frame_.orientation();
		o.normalize();
		frame_.setOrientation(o);
	      }
	}
      else
	QMessageBox::warning(NULL, "Object XML error", "Error while parsing Object XML document");
      n = n.nextSibling();
    }
}
