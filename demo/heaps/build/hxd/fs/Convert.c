﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxd/fs/Convert.h>
extern hl_type t$fun_a6a5f55;
extern String s$c0cb5f0;
extern String s$Not_implemented;
vdynamic* Reflect_field(vdynamic*,String);
extern String s$Missing_required_parameter_;
String String___add__(String,String);
extern String s$_for_converting_;
extern String s$_to_;
void hxd_File_saveBytes(String,haxe__io__Bytes);
int Sys_command(String,hl__types__ArrayObj);
extern String s$Command_;
extern String s$;
extern String s$7215ee9;
String hl_types_ArrayObj_join(hl__types__ArrayObj,String);
extern String s$_failed_with_exit_code_;
#include <hl/natives.h>
String String___alloc__(vbyte*,int);
extern hxd__fs__$Convert g$_hxd_fs_Convert;
vdynamic* haxe_ds_StringMap_get(haxe__ds__StringMap,String);
extern hl_type t$hl_types_ArrayObj;
extern hl_type t$_dyn;
extern hl_type t$hxd_fs_Convert;
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
void haxe_ds_StringMap_set(haxe__ds__StringMap,String,vdynamic*);
void hl_types_ArrayObj_unshift(hl__types__ArrayObj,vdynamic*);

void hxd_fs_Convert_new(hxd__fs__Convert r0,vvirtual* r1,String r2) {
	String r5;
	hl__types__ArrayObj r3;
	vclosure *r4;
	int r6;
	if( r1 ) goto label$1fe3372_1_3;
	r3 = NULL;
	goto label$1fe3372_1_8;
	label$1fe3372_1_3:
	if( r1 == NULL ) hl_null_access();
	r4 = hl_vfields(r1)[0] ? (*(vclosure**)(hl_vfields(r1)[0])) : (vclosure*)hl_dyn_getp(r1->value,-512825013/*split*/,&t$fun_a6a5f55);
	if( r4 == NULL ) hl_null_access();
	r5 = (String)s$c0cb5f0;
	r3 = r4->hasValue ? ((hl__types__ArrayObj (*)(vdynamic*,String))r4->fun)((vdynamic*)r4->value,r5) : ((hl__types__ArrayObj (*)(String))r4->fun)(r5);
	label$1fe3372_1_8:
	r0->sourceExts = r3;
	r0->destExt = r2;
	r6 = 0;
	r0->version = r6;
	return;
}

void hxd_fs_Convert_convert(hxd__fs__Convert r0) {
	String r1;
	r1 = (String)s$Not_implemented;
	hl_throw((vdynamic*)r1);
}

bool hxd_fs_Convert_hasParam(hxd__fs__Convert r0,String r1) {
	bool r3;
	vdynamic *r2, *r4;
	r2 = r0->params;
	r2 = Reflect_field(r2,r1);
	if( !r2 ) goto label$1fe3372_3_10;
	r3 = false;
	r4 = hl_alloc_dynbool(r3);
	{ int i = hl_dyn_compare((vdynamic*)r2,(vdynamic*)r4); if( i != 0 ) goto label$1fe3372_3_8; };
	r3 = false;
	goto label$1fe3372_3_9;
	label$1fe3372_3_8:
	r3 = true;
	label$1fe3372_3_9:
	return r3;
	label$1fe3372_3_10:
	r3 = false;
	return r3;
}

vdynamic* hxd_fs_Convert_getParam(hxd__fs__Convert r0,String r1) {
	String r3, r4;
	vdynamic *r2;
	r2 = r0->params;
	r2 = Reflect_field(r2,r1);
	if( r2 ) goto label$1fe3372_4_14;
	r3 = (String)s$Missing_required_parameter_;
	r3 = String___add__(r3,r1);
	r4 = (String)s$_for_converting_;
	r3 = String___add__(r3,r4);
	r4 = r0->srcPath;
	r3 = String___add__(r3,r4);
	r4 = (String)s$_to_;
	r3 = String___add__(r3,r4);
	r4 = r0->dstPath;
	r3 = String___add__(r3,r4);
	hl_throw((vdynamic*)r3);
	label$1fe3372_4_14:
	return r2;
}

void hxd_fs_Convert_save(hxd__fs__Convert r0,haxe__io__Bytes r1) {
	String r3;
	r3 = r0->dstPath;
	hxd_File_saveBytes(r3,r1);
	return;
}

void hxd_fs_Convert_command(hxd__fs__Convert r0,String r1,hl__types__ArrayObj r2) {
	String r4, r8, r9;
	int *r10;
	vbyte *r11;
	int r3, r6, r7;
	r3 = Sys_command(r1,r2);
	r7 = 0;
	if( r3 == r7 ) goto label$1fe3372_6_24;
	r4 = (String)s$Command_;
	r4 = String___add__(r4,r1);
	if( r2 == NULL ) hl_null_access();
	r6 = r2->length;
	r7 = 0;
	if( r6 != r7 ) goto label$1fe3372_6_11;
	r8 = (String)s$;
	goto label$1fe3372_6_15;
	label$1fe3372_6_11:
	r8 = (String)s$7215ee9;
	r9 = (String)s$7215ee9;
	r9 = hl_types_ArrayObj_join(r2,r9);
	r8 = String___add__(r8,r9);
	label$1fe3372_6_15:
	r4 = String___add__(r4,r8);
	r8 = (String)s$_failed_with_exit_code_;
	r4 = String___add__(r4,r8);
	r6 = r3;
	r10 = &r6;
	r11 = hl_itos(r6,r10);
	r8 = String___alloc__(r11,r6);
	r4 = String___add__(r4,r8);
	hl_throw((vdynamic*)r4);
	label$1fe3372_6_24:
	return;
}

int hxd_fs_Convert_register(hxd__fs__Convert r0) {
	String r4;
	hl__types__ArrayObj r5, r7;
	haxe__ds__StringMap r2;
	hl_type *r9;
	hxd__fs__$Convert r3;
	vdynamic *r1;
	int r10;
	varray *r8;
	r3 = (hxd__fs__$Convert)g$_hxd_fs_Convert;
	r2 = r3->converts;
	if( r2 == NULL ) hl_null_access();
	if( r0 == NULL ) hl_null_access();
	r4 = r0->destExt;
	r1 = haxe_ds_StringMap_get(r2,r4);
	r5 = (hl__types__ArrayObj)hl_dyn_castp(&r1,&t$_dyn,&t$hl_types_ArrayObj);
	if( r5 ) goto label$1fe3372_7_18;
	r9 = &t$hxd_fs_Convert;
	r10 = 0;
	r8 = hl_alloc_array(r9,r10);
	r7 = hl_types_ArrayObj_alloc(r8);
	r5 = r7;
	r3 = (hxd__fs__$Convert)g$_hxd_fs_Convert;
	r2 = r3->converts;
	if( r2 == NULL ) hl_null_access();
	r4 = r0->destExt;
	haxe_ds_StringMap_set(r2,r4,((vdynamic*)r7));
	label$1fe3372_7_18:
	if( r5 == NULL ) hl_null_access();
	hl_types_ArrayObj_unshift(r5,((vdynamic*)r0));
	r10 = 0;
	return r10;
}

