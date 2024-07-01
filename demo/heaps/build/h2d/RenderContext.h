﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h2d__RenderContext
#define INC_h2d__RenderContext
typedef struct _h2d__$RenderContext *h2d__$RenderContext;
typedef struct _h2d__RenderContext *h2d__RenderContext;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <h3d/impl/RenderContext.h>
#include <h3d/Engine.h>
#include <h3d/impl/TextureCache.h>
#include <h2d/Scene.h>
#include <h2d/Drawable.h>
#include <h2d/Object.h>
#include <h2d/col/Bounds.h>
#include <h3d/mat/Texture.h>
#include <h3d/shader/Base2d.h>
#include <h3d/pass/ShaderManager.h>
#include <hxsl/RuntimeShader.h>
#include <h3d/shader/Buffers.h>
#include <h3d/Buffer.h>
#include <h3d/mat/Pass.h>
#include <hxsl/ShaderList.h>
#include <hl/types/ArrayObj.h>
#include <h2d/BlendMode.h>


struct _h2d__$RenderContext {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _h2d__RenderContext {
	hl_type *$type;
	h3d__Engine engine;
	double time;
	double elapsedTime;
	int frame;
	h3d__impl__TextureCache textures;
	double globalAlpha;
	int bufPos;
	h2d__Scene scene;
	bool defaultSmooth;
	bool killAlpha;
	bool front2back;
	vclosure* onBeginDraw;
	vclosure* onEnterFilter;
	vclosure* onLeaveFilter;
	h2d__col__Bounds tmpBounds;
	h3d__mat__Texture texture;
	h3d__shader__Base2d baseShader;
	h3d__pass__ShaderManager manager;
	hxsl__RuntimeShader compiledShader;
	h3d__shader__Buffers buffers;
	h3d__Buffer fixedBuffer;
	h3d__mat__Pass pass;
	hxsl__ShaderList currentShaders;
	hxsl__ShaderList baseShaderList;
	h2d__Drawable currentObj;
	int stride;
	hl__types__ArrayObj targetsStack;
	int targetsStackIndex;
	hl__types__ArrayObj cameraStack;
	int cameraStackIndex;
	h3d__mat__Texture curTarget;
	hl__types__ArrayObj renderZoneStack;
	int renderZoneIndex;
	hl__types__ArrayObj filterStack;
	int filterStackIndex;
	vvirtual* inFilter;
	venum* inFilterBlend;
	double viewA;
	double viewB;
	double viewC;
	double viewD;
	double viewX;
	double viewY;
	bool hasRenderZone;
	double renderX;
	double renderY;
	double renderW;
	double renderH;
	venum* currentBlend;
	double baseFlipY;
	double targetFlipY;
};
#endif

