﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC__std__Std
#define INC__std__Std
typedef struct _$Std *$Std;
typedef struct _Std *Std;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/natives.h>


struct _$Std {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	hl_random* rnd;
	int toStringDepth;
	vclosure* isOfType;
	vclosure* string;
	vclosure* parseInt;
	vclosure* parseFloat;
	vclosure* __add__;
};
struct _Std {
	hl_type *$type;
};
#endif
