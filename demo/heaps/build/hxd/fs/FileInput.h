﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxd__fs__FileInput
#define INC_hxd__fs__FileInput
typedef struct _hxd__fs__$FileInput *hxd__fs__$FileInput;
typedef struct _hxd__fs__FileInput *hxd__fs__FileInput;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <haxe/io/Bytes.h>
#include <haxe/io/Input.h>
#include <hxd/fs/FileEntry.h>


struct _hxd__fs__$FileInput {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	haxe__io__Bytes PREFETCH_CACHE;
};
struct _hxd__fs__FileInput {
	hl_type *$type;
	bool bigEndian;
	hxd__fs__FileEntry entry;
	haxe__io__Bytes cache;
	int cachePos;
	int cacheLen;
	int nextReadPos;
};
#endif
