﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxsl___Linker__ShaderInfos
#define INC_hxsl___Linker__ShaderInfos
typedef struct _hxsl___Linker__$ShaderInfos *hxsl___Linker__$ShaderInfos;
typedef struct _hxsl___Linker__ShaderInfos *hxsl___Linker__ShaderInfos;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hxsl/TExprDef.h>
#include <hxsl/Type.h>
#include <hl/types/ArrayObj.h>
#include <haxe/ds/ObjectMap.h>
#include <haxe/ds/IntMap.h>


struct _hxsl___Linker__$ShaderInfos {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	int UID;
};
struct _hxsl___Linker__ShaderInfos {
	hl_type *$type;
	int uid;
	String name;
	int priority;
	vvirtual* body;
	hl__types__ArrayObj usedFunctions;
	haxe__ds__ObjectMap deps;
	haxe__ds__IntMap read;
	haxe__ds__IntMap write;
	haxe__ds__IntMap processed;
	vdynamic* vertex;
	bool onStack;
	bool hasDiscard;
	vdynamic* marked;
};
#endif

