TEMPLATE = app
TARGET   = rt
CONFIG  += qt opengl release thread
QT *= opengl
QT *= opengl xml
LIBS *= -lqglviewer-qt4

HEADERS  = viewer.h node.h sphere.h material.h object.h scene.h ray.h camera.h light.h rayTracer.h hit.h color.h
SOURCES  = viewer.cpp node.cpp sphere.cpp material.cpp object.cpp scene.cpp ray.cpp camera.cpp light.cpp rayTracer.cpp main.cpp

