﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxd__fmt__hmd__Skin
#define INC_hxd__fmt__hmd__Skin
typedef struct _hxd__fmt__hmd__$Skin *hxd__fmt__hmd__$Skin;
typedef struct _hxd__fmt__hmd__Skin *hxd__fmt__hmd__Skin;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayObj.h>


struct _hxd__fmt__hmd__$Skin {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _hxd__fmt__hmd__Skin {
	hl_type *$type;
	String name;
	hl__types__ArrayObj props;
	hl__types__ArrayObj joints;
	hl__types__ArrayObj split;
};
#endif

