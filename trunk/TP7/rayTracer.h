#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include <qimage.h>
#include "color.h"
#include "ray.h"

class Scene;

class RayTracer
{
public :
  RayTracer() : scene_(NULL), antialiasing_(4) {};

  const Scene* const scene() const { return scene_; }
  const QImage& image() const { return image_; }

  void setScene(const Scene* const scene) { scene_ = scene; }
  void setAntialiasingSamplesNumber(int n) { antialiasing_ = n; }

  void renderImage() const;
  void saveImage(const QString& name, bool overwrite=false) const;

  Color rayColor(const Ray& ray) const;

private:
  const Scene* scene_;
  mutable QImage image_;

  int antialiasing_;
};

#endif // RAY_TRACER_H
