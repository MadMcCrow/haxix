﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxd__fs__ConvertTGA2PNG
#define INC_hxd__fs__ConvertTGA2PNG
typedef struct _hxd__fs__$ConvertTGA2PNG *hxd__fs__$ConvertTGA2PNG;
typedef struct _hxd__fs__ConvertTGA2PNG *hxd__fs__ConvertTGA2PNG;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hxd/fs/Convert.h>
#include <hl/types/ArrayObj.h>
#include <haxe/io/Bytes.h>


struct _hxd__fs__$ConvertTGA2PNG {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	int _hx__;
};
struct _hxd__fs__ConvertTGA2PNG {
	hl_type *$type;
	hl__types__ArrayObj sourceExts;
	String destExt;
	int version;
	vdynamic* params;
	String srcPath;
	String dstPath;
	String originalFilename;
	haxe__io__Bytes srcBytes;
};
#endif
