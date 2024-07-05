﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxd/fs/FileEntry.h>
extern String s$readBytes_not_implemented;
extern hxd__fs__$FileEntry g$_hxd_fs_FileEntry;
haxe__io__Bytes haxe_io_Bytes_alloc(int);
void hxd_fs_FileEntry_readFull(hxd__fs__FileEntry,haxe__io__Bytes,int,int);
#include <haxe/io/Eof.h>
extern hl_type t$haxe_io_Eof;
void haxe_io_Eof_new(haxe__io__Eof);
#include <hxd/fs/FileInput.h>
extern hl_type t$hxd_fs_FileInput;
void hxd_fs_FileInput_new(hxd__fs__FileInput,hxd__fs__FileEntry);
bool hxd_fs_FileEntry_get_isAvailable(hxd__fs__FileEntry);
extern String s$load_not_implemented;
extern String s$path_not_implemented;
extern String s$5058f1a;
int String_lastIndexOf(String,String,vdynamic*);
extern String s$;
String String_substr(String,int,vdynamic*);
String String_toLowerCase(String);

haxe__io__Bytes hxd_fs_FileEntry_getBytes(hxd__fs__FileEntry r0) {
	haxe__io__Bytes r1;
	r1 = NULL;
	return r1;
}

int hxd_fs_FileEntry_readBytes(hxd__fs__FileEntry r0,haxe__io__Bytes r1,int r2,int r3,int r4) {
	String r5;
	r5 = (String)s$readBytes_not_implemented;
	hl_throw((vdynamic*)r5);
}

haxe__io__Bytes hxd_fs_FileEntry_fetchBytes(hxd__fs__FileEntry r0,int r1,int r2) {
	hxd__fs__$FileEntry r4;
	haxe__io__Bytes r3, r6;
	int r7, r8;
	r4 = (hxd__fs__$FileEntry)g$_hxd_fs_FileEntry;
	r3 = r4->TMP_BYTES;
	if( !r3 ) goto label$558104c_3_6;
	if( r3 == NULL ) hl_null_access();
	r7 = r3->length;
	if( r7 >= r2 ) goto label$558104c_3_14;
	label$558104c_3_6:
	r8 = 65535;
	r7 = r2 + r8;
	r8 = -65536;
	r7 = r7 & r8;
	r6 = haxe_io_Bytes_alloc(r7);
	r3 = r6;
	r4 = (hxd__fs__$FileEntry)g$_hxd_fs_FileEntry;
	r4->TMP_BYTES = r6;
	label$558104c_3_14:
	hxd_fs_FileEntry_readFull(r0,r3,r1,r2);
	return r3;
}

void hxd_fs_FileEntry_readFull(hxd__fs__FileEntry r0,haxe__io__Bytes r1,int r2,int r3) {
	haxe__io__Eof r6;
	int r5;
	r5 = 0;
	r5 = ((int (*)(hxd__fs__FileEntry,haxe__io__Bytes,int,int,int))r0->$type->vobj_proto[1])(r0,r1,r5,r2,r3);
	if( r5 >= r3 ) goto label$558104c_4_6;
	r6 = (haxe__io__Eof)hl_alloc_obj(&t$haxe_io_Eof);
	haxe_io_Eof_new(r6);
	hl_throw((vdynamic*)r6);
	label$558104c_4_6:
	return;
}

hxd__fs__FileInput hxd_fs_FileEntry_open(hxd__fs__FileEntry r0) {
	hxd__fs__FileInput r1;
	r1 = (hxd__fs__FileInput)hl_alloc_obj(&t$hxd_fs_FileInput);
	hxd_fs_FileInput_new(r1,r0);
	return r1;
}

void hxd_fs_FileEntry_load(hxd__fs__FileEntry r0,vclosure* r1) {
	String r4;
	bool r3;
	r3 = hxd_fs_FileEntry_get_isAvailable(r0);
	if( r3 ) goto label$558104c_6_4;
	r4 = (String)s$load_not_implemented;
	hl_throw((vdynamic*)r4);
	label$558104c_6_4:
	if( !r1 ) goto label$558104c_6_7;
	if( r1 == NULL ) hl_null_access();
	r1->hasValue ? ((void (*)(vdynamic*))r1->fun)((vdynamic*)r1->value) : ((void (*)(void))r1->fun)();
	label$558104c_6_7:
	return;
}

void hxd_fs_FileEntry_watch(hxd__fs__FileEntry r0,vclosure* r1) {
	return;
}

bool hxd_fs_FileEntry_get_isAvailable(hxd__fs__FileEntry r0) {
	bool r1;
	r1 = true;
	return r1;
}

int hxd_fs_FileEntry_get_size(hxd__fs__FileEntry r0) {
	int r1;
	r1 = 0;
	return r1;
}

String hxd_fs_FileEntry_get_path(hxd__fs__FileEntry r0) {
	String r1;
	r1 = (String)s$path_not_implemented;
	hl_throw((vdynamic*)r1);
}

String hxd_fs_FileEntry_get_extension(hxd__fs__FileEntry r0) {
	String r2, r3;
	vdynamic *r4;
	int r1, r5, r6;
	r2 = r0->name;
	if( r2 == NULL ) hl_null_access();
	r3 = (String)s$5058f1a;
	r4 = NULL;
	r1 = String_lastIndexOf(r2,r3,r4);
	r6 = 0;
	if( r1 >= r6 ) goto label$558104c_11_9;
	r2 = (String)s$;
	return r2;
	label$558104c_11_9:
	r2 = r0->name;
	if( r2 == NULL ) hl_null_access();
	r6 = 1;
	r5 = r1 + r6;
	r4 = NULL;
	r2 = String_substr(r2,r5,r4);
	if( r2 == NULL ) hl_null_access();
	r2 = String_toLowerCase(r2);
	return r2;
}
