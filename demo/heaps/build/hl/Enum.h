﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hl__Enum
#define INC_hl__Enum
typedef struct _hl__$Enum *hl__$Enum;
typedef struct _hl__Enum *hl__Enum;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/natives.h>
#include <hl/types/ArrayObj.h>


struct _hl__$Enum {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _hl__Enum {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __ename__;
	hl_bytes_map* __emap__;
	hl__types__ArrayObj __constructs__;
	varray* __evalues__;
};
#endif

