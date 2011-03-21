#include "rayTracer.h"
#include "scene.h"
#include "camera.h"
#include "hit.h"
#include "ray.h"

#include <qfileinfo.h>
#include <qfiledialog.h>
#include <qmessagebox.h>

void RayTracer::renderImage() const
{
  // A FAIRE
}

Color RayTracer::rayColor(const Ray& ray) const
{
  // A FAIRE

  // Pour ne pas avoir de warnings "unused parameter" - A supprimer
  Q_UNUSED(ray)

  return Color();
}

void RayTracer::saveImage(const QString& name, bool overwrite) const
{
  QString fileName = name;
  QFileInfo info(fileName);

  // Append jpg extension if needed
#if QT_VERSION < 0x040000
  if (info.extension(false) != "jpg")
#else
  if (info.suffix() != "jpg")
#endif
    {
      fileName += ".jpg";
      info.setFile(fileName);
    }

  // Prevent overwriting an existing file
  if (info.exists() && !overwrite)
    if (QMessageBox::warning(NULL, "Overwrite file ?",
			     "File "+info.fileName()+" already exists.\nOverwrite ?",
			     QMessageBox::Yes,
			     QMessageBox::Cancel) == QMessageBox::Cancel)
      return;

  if (!image().save(fileName, "JPEG", 95))
    QMessageBox::information(NULL, "Error", "Error while saving "+fileName);
  else
    QMessageBox::information(NULL, "Saving done", "Image successfully saved in "+fileName);
}
