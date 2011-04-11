TEMPLATE = app
TARGET   = rt
CONFIG  += qt opengl glut warn_on release thread debug openmp

HEADERS  = viewer.h   sphere.h   material.h   object.h   scene.h   ray.h camera.h   light.h   rayTracer.h   hit.h color.h triangle.h node.h cylinder.h dynamics.h spring.h
SOURCES  = viewer.cpp sphere.cpp material.cpp object.cpp scene.cpp ray.cpp camera.cpp light.cpp rayTracer.cpp main.cpp triangle.cpp node.cpp cylinder.cpp dynamics.cpp spring.cpp

# Qt 2.3 users must edit config.pri
#include( config.pri )
LIBS *= -lqglviewer -lglut

QT += qt3support 

