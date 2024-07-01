﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxsl__Serializer
#define INC_hxsl__Serializer
typedef struct _hxsl__$Serializer *hxsl__$Serializer;
typedef struct _hxsl__Serializer *hxsl__Serializer;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <haxe/ds/IntMap.h>
#include <hl/types/ArrayObj.h>
#include <haxe/io/BytesInput.h>


struct _hxsl__$Serializer {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	haxe__ds__IntMap TVECS;
	hl__types__ArrayObj BOPS;
	hl__types__ArrayObj UNOPS;
	hl__types__ArrayObj TGLOBALS;
	haxe__ds__IntMap TSWIZ;
	hl__types__ArrayObj REGS;
	hl__types__ArrayObj VKINDS;
	hl__types__ArrayObj PRECS;
	hl__types__ArrayObj FKIND;
	int SIGN;
};
struct _hxsl__Serializer {
	hl_type *$type;
	haxe__io__BytesInput input;
	haxe__ds__IntMap varMap;
	hl__types__ArrayObj types;
};
#endif

