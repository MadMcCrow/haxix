﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxd__fmt__hmd__AnimationEvent
#define INC_hxd__fmt__hmd__AnimationEvent
typedef struct _hxd__fmt__hmd__$AnimationEvent *hxd__fmt__hmd__$AnimationEvent;
typedef struct _hxd__fmt__hmd__AnimationEvent *hxd__fmt__hmd__AnimationEvent;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>


struct _hxd__fmt__hmd__$AnimationEvent {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _hxd__fmt__hmd__AnimationEvent {
	hl_type *$type;
	int frame;
	String data;
};
#endif

