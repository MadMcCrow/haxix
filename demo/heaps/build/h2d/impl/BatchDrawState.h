﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h2d__impl__BatchDrawState
#define INC_h2d__impl__BatchDrawState
typedef struct _h2d__impl__$BatchDrawState *h2d__impl__$BatchDrawState;
typedef struct _h2d__impl__BatchDrawState *h2d__impl__BatchDrawState;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <h2d/impl/_BatchDrawState/StateEntry.h>


struct _h2d__impl__$BatchDrawState {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _h2d__impl__BatchDrawState {
	hl_type *$type;
	int totalCount;
	h2d__impl___BatchDrawState__StateEntry head;
	h2d__impl___BatchDrawState__StateEntry tail;
};
#endif
