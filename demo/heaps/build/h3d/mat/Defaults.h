﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__mat__Defaults
#define INC_h3d__mat__Defaults
typedef struct _h3d__mat__$Defaults *h3d__mat__$Defaults;
typedef struct _h3d__mat__Defaults *h3d__mat__Defaults;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hxsl/Shader.h>


struct _h3d__mat__$Defaults {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	double defaultKillAlphaThreshold;
	int loadingTextureColor;
	hxsl__Shader shadowShader;
	vclosure* get_shadowShader;
	vclosure* set_shadowShader;
};
struct _h3d__mat__Defaults {
	hl_type *$type;
};
#endif

