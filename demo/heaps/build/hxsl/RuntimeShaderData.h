﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxsl__RuntimeShaderData
#define INC_hxsl__RuntimeShaderData
typedef struct _hxsl__$RuntimeShaderData *hxsl__$RuntimeShaderData;
typedef struct _hxsl__RuntimeShaderData *hxsl__RuntimeShaderData;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayObj.h>
#include <hxsl/AllocParam.h>
#include <hxsl/AllocGlobal.h>
#include <hl/types/ArrayBytes_Float.h>


struct _hxsl__$RuntimeShaderData {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _hxsl__RuntimeShaderData {
	hl_type *$type;
	bool vertex;
	vvirtual* data;
	String code;
	hxsl__AllocParam params;
	int paramsSize;
	hxsl__AllocGlobal globals;
	int globalsSize;
	hxsl__AllocParam textures;
	int texturesCount;
	hxsl__AllocParam buffers;
	int bufferCount;
	hl__types__ArrayBytes_Float consts;
};
#endif

