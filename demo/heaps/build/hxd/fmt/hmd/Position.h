﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxd__fmt__hmd__Position
#define INC_hxd__fmt__hmd__Position
typedef struct _hxd__fmt__hmd__$Position *hxd__fmt__hmd__$Position;
typedef struct _hxd__fmt__hmd__Position *hxd__fmt__hmd__Position;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>


struct _hxd__fmt__hmd__$Position {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _hxd__fmt__hmd__Position {
	hl_type *$type;
	double x;
	double y;
	double z;
	double qx;
	double qy;
	double qz;
	double sx;
	double sy;
	double sz;
};
#endif
