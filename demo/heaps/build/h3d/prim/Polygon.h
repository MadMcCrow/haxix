﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__prim__Polygon
#define INC_h3d__prim__Polygon
typedef struct _h3d__prim__$Polygon *h3d__prim__$Polygon;
typedef struct _h3d__prim__Polygon *h3d__prim__Polygon;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <h3d/prim/MeshPrimitive.h>
#include <h3d/prim/Primitive.h>
#include <h3d/Buffer.h>
#include <h3d/Indexes.h>
#include <hl/types/ArrayObj.h>
#include <hxd/MultiFormat.h>
#include <hl/types/ArrayBytes_hl_UI16.h>


struct _h3d__prim__$Polygon {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _h3d__prim__Polygon {
	hl_type *$type;
	h3d__Buffer buffer;
	h3d__Indexes indexes;
	int refCount;
	hl__types__ArrayObj buffers;
	hxd__MultiFormat formats;
	hl__types__ArrayObj points;
	hl__types__ArrayObj normals;
	hl__types__ArrayObj tangents;
	hl__types__ArrayObj uvs;
	hl__types__ArrayBytes_hl_UI16 idx;
	hl__types__ArrayObj colors;
};
#endif

