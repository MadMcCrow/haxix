﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__shader__ColorAdd
#define INC_h3d__shader__ColorAdd
typedef struct _h3d__shader__$ColorAdd *h3d__shader__$ColorAdd;
typedef struct _h3d__shader__ColorAdd *h3d__shader__ColorAdd;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hxsl/SharedShader.h>
#include <hxsl/Shader.h>
#include <hxsl/ShaderInstance.h>
#include <h3d/VectorImpl.h>


struct _h3d__shader__$ColorAdd {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	String SRC;
	hxsl__SharedShader _SHADER;
};
struct _h3d__shader__ColorAdd {
	hl_type *$type;
	int priority;
	hxsl__SharedShader shader;
	hxsl__ShaderInstance instance;
	int constBits;
	bool constModified;
	h3d__VectorImpl color__;
};
#endif

