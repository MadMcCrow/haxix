﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxd/fs/BytesFileSystem.h>
#include <haxe/io/Bytes.h>
extern String s$Not_implemented;
#include <hxd/fs/BytesFileEntry.h>
extern String s$Resource_not_found_;
String String___add__(String,String);
extern String s$3590cb8;
extern hl_type t$hxd_fs_BytesFileEntry;
void hxd_fs_BytesFileEntry_new(hxd__fs__BytesFileEntry,String,haxe__io__Bytes);

void hxd_fs_BytesFileSystem_new(hxd__fs__BytesFileSystem r0) {
	return;
}

haxe__io__Bytes hxd_fs_BytesFileSystem_getBytes(hxd__fs__BytesFileSystem r0,String r1) {
	String r2;
	r2 = (String)s$Not_implemented;
	hl_throw((vdynamic*)r2);
}

hxd__fs__BytesFileEntry hxd_fs_BytesFileSystem_get(hxd__fs__BytesFileSystem r0,String r1) {
	String r3, r5;
	haxe__io__Bytes r2;
	hxd__fs__BytesFileEntry r6;
	r2 = ((haxe__io__Bytes (*)(hxd__fs__BytesFileSystem,String))r0->$type->vobj_proto[0])(r0,r1);
	if( r2 ) goto label$87114e1_3_7;
	r3 = (String)s$Resource_not_found_;
	r3 = String___add__(r3,r1);
	r5 = (String)s$3590cb8;
	r3 = String___add__(r3,r5);
	hl_throw((vdynamic*)r3);
	label$87114e1_3_7:
	r6 = (hxd__fs__BytesFileEntry)hl_alloc_obj(&t$hxd_fs_BytesFileEntry);
	hxd_fs_BytesFileEntry_new(r6,r1,r2);
	return r6;
}

