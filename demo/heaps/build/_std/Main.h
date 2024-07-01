﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC__std__Main
#define INC__std__Main
typedef struct _$Main *$Main;
typedef struct _Main *Main;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hxd/App.h>
#include <h3d/Engine.h>
#include <h3d/scene/Scene.h>
#include <h2d/Scene.h>
#include <hxd/SceneEvents.h>


struct _$Main {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	vclosure* main;
};
struct _Main {
	hl_type *$type;
	h3d__Engine engine;
	h3d__scene__Scene s3d;
	h2d__Scene s2d;
	hxd__SceneEvents sevents;
	bool isDisposed;
	vvirtual* f$5;
};
#endif

