﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_haxe__Unserializer
#define INC_haxe__Unserializer
typedef struct _haxe__$Unserializer *haxe__$Unserializer;
typedef struct _haxe__Unserializer *haxe__Unserializer;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayBytes_Int.h>
#include <hl/types/ArrayDyn.h>
#include <hl/types/ArrayObj.h>


struct _haxe__$Unserializer {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	vvirtual* DEFAULT_RESOLVER;
	String BASE64;
	hl__types__ArrayBytes_Int CODES;
	vclosure* initCodes;
	vclosure* run;
};
struct _haxe__Unserializer {
	hl_type *$type;
	String buf;
	int pos;
	int length;
	hl__types__ArrayDyn cache;
	hl__types__ArrayObj scache;
	vvirtual* resolver;
};
#endif
