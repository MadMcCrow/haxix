﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxsl__ARead
#define INC_hxsl__ARead
typedef struct _hxsl__$ARead *hxsl__$ARead;
#include <hl/Enum.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/natives.h>
#include <hl/types/ArrayObj.h>
#include <hxsl/_Flatten/Alloc.h>
#include <hxsl/ARead.h>
#include <hxsl/TExprDef.h>
#include <hxsl/Type.h>


struct _hxsl__$ARead {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __ename__;
	hl_bytes_map* __emap__;
	hl__types__ArrayObj __constructs__;
	varray* __evalues__;
};
typedef struct {
	HL__ENUM_CONSTRUCT__
	hxsl___Flatten__Alloc p0;
} hxsl_ARead_AIndex;
typedef struct {
	HL__ENUM_CONSTRUCT__
	hxsl___Flatten__Alloc p0;
	int p1;
	vvirtual* p2;
} hxsl_ARead_AOffset;
#endif

