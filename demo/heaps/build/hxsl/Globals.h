﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxsl__Globals
#define INC_hxsl__Globals
typedef struct _hxsl__$Globals *hxsl__$Globals;
typedef struct _hxsl__Globals *hxsl__Globals;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayObj.h>
#include <haxe/ds/StringMap.h>
#include <haxe/ds/IntMap.h>


struct _hxsl__$Globals {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	hl__types__ArrayObj ALL;
	haxe__ds__StringMap MAP;
	vclosure* allocID;
};
struct _hxsl__Globals {
	hl_type *$type;
	haxe__ds__IntMap map;
	hl__types__ArrayObj channels;
	int maxChannels;
};
#endif

