﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__scene__RenderContext
#define INC_h3d__scene__RenderContext
typedef struct _h3d__scene__$RenderContext *h3d__scene__$RenderContext;
typedef struct _h3d__scene__RenderContext *h3d__scene__RenderContext;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <h3d/impl/RenderContext.h>
#include <h3d/Engine.h>
#include <h3d/impl/TextureCache.h>
#include <h3d/Camera.h>
#include <h3d/scene/Scene.h>
#include <h3d/pass/PassObject.h>
#include <hl/types/ArrayObj.h>
#include <h3d/scene/LightSystem.h>
#include <hxsl/ShaderList.h>
#include <h3d/shader/Buffers.h>
#include <h3d/col/Collider.h>
#include <h3d/scene/Light.h>
#include <h3d/pass/ShaderManager.h>


struct _h3d__scene__$RenderContext {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _h3d__scene__RenderContext {
	hl_type *$type;
	h3d__Engine engine;
	double time;
	double elapsedTime;
	int frame;
	h3d__impl__TextureCache textures;
	h3d__Camera camera;
	h3d__scene__Scene scene;
	h3d__pass__PassObject drawPass;
	bool computingStatic;
	hl__types__ArrayObj sharedGlobals;
	h3d__scene__LightSystem lightSystem;
	hxsl__ShaderList extraShaders;
	bool visibleFlag;
	bool wasContextLost;
	h3d__shader__Buffers shaderBuffers;
	h3d__col__Collider cullingCollider;
	h3d__pass__PassObject allocPool;
	h3d__pass__PassObject allocFirst;
	hl__types__ArrayObj cachedShaderList;
	hl__types__ArrayObj cachedPassObjects;
	int cachedPos;
	hl__types__ArrayObj passes;
	h3d__scene__Light lights;
	h3d__pass__ShaderManager currentManager;
};
#endif
