﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__prim__MeshPrimitive
#define INC_h3d__prim__MeshPrimitive
typedef struct _h3d__prim__$MeshPrimitive *h3d__prim__$MeshPrimitive;
typedef struct _h3d__prim__MeshPrimitive *h3d__prim__MeshPrimitive;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <h3d/prim/Primitive.h>
#include <h3d/Buffer.h>
#include <h3d/Indexes.h>
#include <hl/types/ArrayObj.h>
#include <hxd/MultiFormat.h>


struct _h3d__prim__$MeshPrimitive {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _h3d__prim__MeshPrimitive {
	hl_type *$type;
	h3d__Buffer buffer;
	h3d__Indexes indexes;
	int refCount;
	hl__types__ArrayObj buffers;
	hxd__MultiFormat formats;
};
#endif

