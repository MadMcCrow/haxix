﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_hxd__fs__ConvertWAV2MP3
#define INC_hxd__fs__ConvertWAV2MP3
typedef struct _hxd__fs__$ConvertWAV2MP3 *hxd__fs__$ConvertWAV2MP3;
typedef struct _hxd__fs__ConvertWAV2MP3 *hxd__fs__ConvertWAV2MP3;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hxd/fs/Convert.h>
#include <hl/types/ArrayObj.h>
#include <haxe/io/Bytes.h>


struct _hxd__fs__$ConvertWAV2MP3 {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	int _hx__;
};
struct _hxd__fs__ConvertWAV2MP3 {
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

