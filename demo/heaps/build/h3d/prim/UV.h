﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__prim__UV
#define INC_h3d__prim__UV
typedef struct _h3d__prim__$UV *h3d__prim__$UV;
typedef struct _h3d__prim__UV *h3d__prim__UV;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>


struct _h3d__prim__$UV {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _h3d__prim__UV {
	hl_type *$type;
	double u;
	double v;
};
#endif

