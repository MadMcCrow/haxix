﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__impl__InstanceBuffer
#define INC_h3d__impl__InstanceBuffer
typedef struct _h3d__impl__$InstanceBuffer *h3d__impl__$InstanceBuffer;
typedef struct _h3d__impl__InstanceBuffer *h3d__impl__InstanceBuffer;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>


struct _h3d__impl__$InstanceBuffer {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _h3d__impl__InstanceBuffer {
	hl_type *$type;
	vdynamic* data;
	int indexCount;
	int startIndex;
	int triCount;
	int commandCount;
};
#endif
