#############################################################################
# Makefile for building: rt
# Generated by qmake (1.07a) (Qt 3.3.8b) on: Sun May  1 14:08:16 2011
# Project:  rt.pro
# Template: app
# Command: $(QMAKE) -o Makefile rt.pro
#############################################################################

####### Compiler, tools and options

CC       = gcc
CXX      = g++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -g -Wall -W -O0 -D_REENTRANT  -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT -DQT_NO_DEBUG
CXXFLAGS = -pipe -g -Wall -W -O0 -D_REENTRANT  -DQT_THREAD_SUPPORT -DQT_SHARED -DQT_TABLET_SUPPORT -DQT_NO_DEBUG
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/usr/share/qt3/mkspecs/default -I. -I/usr/include/qt3 -I/usr/X11R6/include -I/usr/X11R6/include
LINK     = g++
LFLAGS   = 
LIBS     = $(SUBLIBS) -L/usr/share/qt3/lib -L/usr/X11R6/lib -L/usr/X11R6/lib -lqglviewer -lglut -lqt-mt -lGLU -lGL -lXmu -lXext -lX11 -lm -lpthread
AR       = ar cqs
RANLIB   = 
MOC      = /usr/share/qt3/bin/moc
UIC      = /usr/share/qt3/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= $(COPY)
COPY_DIR = $(COPY) -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = ./

####### Files

HEADERS = viewer.h \
		sphere.h \
		material.h \
		object.h \
		scene.h \
		ray.h \
		camera.h \
		light.h \
		rayTracer.h \
		hit.h \
		color.h \
		triangle.h \
		node.h \
		cylinder.h \
		dynamics.h \
		spring.h \
		rope.h \
		plane.h \
		fog.h \
		fishflock.h \
		fish.h \
		planTexture.h \
		airbubble.h
SOURCES = viewer.cpp \
		sphere.cpp \
		material.cpp \
		object.cpp \
		scene.cpp \
		ray.cpp \
		camera.cpp \
		light.cpp \
		rayTracer.cpp \
		main.cpp \
		triangle.cpp \
		node.cpp \
		cylinder.cpp \
		dynamics.cpp \
		spring.cpp \
		rope.cpp \
		plane.cpp \
		fog.cpp \
		fishflock.cpp \
		fish.cpp \
		planTexture.cpp \
		airbubble.cpp
OBJECTS = viewer.o \
		sphere.o \
		material.o \
		object.o \
		scene.o \
		ray.o \
		camera.o \
		light.o \
		rayTracer.o \
		main.o \
		triangle.o \
		node.o \
		cylinder.o \
		dynamics.o \
		spring.o \
		rope.o \
		plane.o \
		fog.o \
		fishflock.o \
		fish.o \
		planTexture.o \
		airbubble.o
FORMS = 
UICDECLS = 
UICIMPLS = 
SRCMOC   = 
OBJMOC = 
DIST	   = rt.pro
QMAKE_TARGET = rt
DESTDIR  = 
TARGET   = rt

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(OBJCOMP) $(LIBS)

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: rt.pro  /usr/share/qt3/mkspecs/default/qmake.conf /usr/share/qt3/lib/libqt-mt.prl
	$(QMAKE) -o Makefile rt.pro
qmake: 
	@$(QMAKE) -o Makefile rt.pro

dist: 
	@mkdir -p .tmp/rt && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .tmp/rt/ && ( cd `dirname .tmp/rt` && $(TAR) rt.tar rt && $(GZIP) rt.tar ) && $(MOVE) `dirname .tmp/rt`/rt.tar.gz . && $(DEL_FILE) -r .tmp/rt

mocclean:

uiclean:

yaccclean:
lexclean:
clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) $(TARGET)


FORCE:

####### Compile

viewer.o: viewer.cpp viewer.h \
		scene.h \
		material.h \
		color.h \
		fog.h \
		rayTracer.h \
		ray.h \
		object.h \
		camera.h \
		node.h \
		hit.h \
		light.h

sphere.o: sphere.cpp sphere.h \
		material.h \
		object.h \
		hit.h \
		ray.h \
		color.h

material.o: material.cpp material.h \
		color.h

object.o: object.cpp object.h \
		material.h \
		hit.h \
		ray.h \
		color.h

scene.o: scene.cpp scene.h \
		sphere.h \
		cylinder.h \
		planTexture.h \
		fog.h \
		fishflock.h \
		object.h \
		camera.h \
		node.h \
		ray.h \
		hit.h \
		light.h \
		material.h \
		color.h \
		fish.h

ray.o: ray.cpp ray.h

camera.o: camera.cpp camera.h \
		scene.h \
		ray.h \
		object.h \
		node.h \
		hit.h \
		light.h \
		fog.h \
		material.h \
		color.h

light.o: light.cpp light.h \
		material.h \
		scene.h \
		color.h \
		hit.h \
		ray.h \
		object.h \
		camera.h \
		node.h \
		fog.h

rayTracer.o: rayTracer.cpp rayTracer.h \
		scene.h \
		camera.h \
		hit.h \
		ray.h \
		color.h \
		object.h \
		node.h \
		light.h \
		fog.h \
		material.h

main.o: main.cpp viewer.h \
		rayTracer.h \
		ray.h \
		color.h

triangle.o: triangle.cpp triangle.h \
		object.h \
		material.h \
		hit.h \
		ray.h \
		color.h

node.o: node.cpp sphere.h \
		cylinder.h \
		dynamics.h \
		planTexture.h \
		plane.h \
		rope.h \
		fishflock.h \
		airbubble.h \
		object.h \
		material.h \
		hit.h \
		ray.h \
		color.h \
		node.h \
		spring.h \
		light.h \
		fish.h

cylinder.o: cylinder.cpp cylinder.h \
		material.h \
		object.h \
		hit.h \
		ray.h \
		color.h

dynamics.o: dynamics.cpp dynamics.h \
		sphere.h \
		viewer.h \
		triangle.h \
		node.h \
		spring.h \
		object.h \
		material.h \
		hit.h \
		ray.h \
		color.h \
		rayTracer.h

spring.o: spring.cpp spring.h

rope.o: rope.cpp rope.h \
		sphere.h \
		viewer.h \
		triangle.h \
		node.h \
		spring.h \
		object.h \
		material.h \
		hit.h \
		ray.h \
		color.h \
		rayTracer.h

plane.o: plane.cpp plane.h \
		material.h \
		object.h \
		hit.h \
		ray.h \
		color.h

fog.o: fog.cpp fog.h \
		object.h \
		material.h \
		hit.h \
		ray.h \
		color.h

fishflock.o: fishflock.cpp fishflock.h \
		fish.h \
		sphere.h \
		object.h \
		light.h \
		material.h \
		hit.h \
		ray.h \
		color.h

fish.o: fish.cpp fish.h \
		light.h \
		object.h \
		material.h \
		hit.h \
		ray.h \
		color.h

planTexture.o: planTexture.cpp planTexture.h \
		material.h \
		object.h \
		hit.h \
		ray.h \
		color.h

airbubble.o: airbubble.cpp airbubble.h \
		sphere.h \
		viewer.h \
		triangle.h \
		object.h \
		material.h \
		node.h \
		hit.h \
		ray.h \
		color.h \
		rayTracer.h

####### Install

install:  

uninstall:  

