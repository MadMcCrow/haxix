﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__pass__Copy
#define INC_h3d__pass__Copy
typedef struct _h3d__pass__$Copy *h3d__pass__$Copy;
typedef struct _h3d__pass__Copy *h3d__pass__Copy;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <h3d/mat/Texture.h>
#include <h2d/BlendMode.h>
#include <h3d/mat/Pass.h>
#include <h3d/pass/ScreenFx.h>
#include <h3d/shader/ScreenShader.h>
#include <h3d/prim/Primitive.h>
#include <h3d/pass/ShaderManager.h>
#include <h3d/Engine.h>
#include <h3d/shader/Buffers.h>


struct _h3d__pass__$Copy {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	vclosure* run;
};
struct _h3d__pass__Copy {
	hl_type *$type;
	h3d__shader__ScreenShader shader;
	h3d__mat__Pass pass;
	h3d__prim__Primitive primitive;
	h3d__pass__ShaderManager manager;
	h3d__Engine _engine;
	h3d__shader__Buffers buffers;
};
#endif

