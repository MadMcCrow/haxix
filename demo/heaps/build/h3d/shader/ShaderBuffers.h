﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__shader__ShaderBuffers
#define INC_h3d__shader__ShaderBuffers
typedef struct _h3d__shader__$ShaderBuffers *h3d__shader__$ShaderBuffers;
typedef struct _h3d__shader__ShaderBuffers *h3d__shader__ShaderBuffers;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayBytes_hl_F32.h>
#include <hl/types/ArrayObj.h>


struct _h3d__shader__$ShaderBuffers {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _h3d__shader__ShaderBuffers {
	hl_type *$type;
	hl__types__ArrayBytes_hl_F32 globals;
	hl__types__ArrayBytes_hl_F32 params;
	hl__types__ArrayObj tex;
	hl__types__ArrayObj buffers;
};
#endif

