﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxd__fmt__hbson__Writer
#define INC_hxd__fmt__hbson__Writer
typedef struct _hxd__fmt__hbson__$Writer *hxd__fmt__hbson__$Writer;
typedef struct _hxd__fmt__hbson__Writer *hxd__fmt__hbson__Writer;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <haxe/io/Output.h>
#include <haxe/ds/StringMap.h>


struct _hxd__fmt__hbson__$Writer {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _hxd__fmt__hbson__Writer {
	hl_type *$type;
	haxe__io__Output out;
	int stringCount;
	haxe__ds__StringMap stringMap;
};
#endif
