﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hl__types__BytesIterator_Int
#define INC_hl__types__BytesIterator_Int
typedef struct _hl__types__$BytesIterator_Int *hl__types__$BytesIterator_Int;
typedef struct _hl__types__BytesIterator_Int *hl__types__BytesIterator_Int;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <haxe/iterators/ArrayIterator.h>
#include <hl/types/ArrayDyn.h>
#include <hl/types/ArrayBytes_Int.h>


struct _hl__types__$BytesIterator_Int {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
};
struct _hl__types__BytesIterator_Int {
	hl_type *$type;
	hl__types__ArrayDyn array;
	int current;
	hl__types__ArrayBytes_Int a;
};
#endif

