﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <format/png/Tools.h>
#include <format/png/Chunk.h>
#include <format/png/Color.h>
extern hl_type t$_i32;
haxe__io__Bytes haxe_io_Bytes_alloc(int);
void haxe_io_Bytes_set(haxe__io__Bytes,int,int);
int haxe_io_Bytes_get(haxe__io__Bytes,int);
extern hl_type t$haxe_ds_List;
void haxe_ds_List_new(haxe__ds__List);
extern hl_type t$vrt_1b4afe7;
extern hl_type t$format_png_Color;
extern hl_type t$_bool;
extern hl_type t$format_png_Chunk;
void haxe_ds_List_add(haxe__ds__List,vdynamic*);
haxe__io__Bytes format_tools_Deflate_run(haxe__io__Bytes,vdynamic*);
extern venum* g$format_png_Chunk_CEnd;

haxe__ds__List format_png_Tools_buildGrey(int r0,int r1,haxe__io__Bytes r2,vdynamic* r3) {
	vvirtual *r17;
	venum *r16, *r18;
	bool r19;
	haxe__io__Bytes r5, r11;
	haxe__ds__List r15;
	int r4, r6, r8, r9, r10, r12, r13, r14;
	if( r3 ) goto label$4214514_1_3;
	r4 = 9;
	r3 = hl_alloc_dynamic(&t$_i32);
	r3->v.i = r4;
	label$4214514_1_3:
	r4 = r0 * r1;
	r4 = r4 + r1;
	r5 = haxe_io_Bytes_alloc(r4);
	r4 = 0;
	r6 = 0;
	r8 = 0;
	r9 = r1;
	label$4214514_1_10:
	if( r8 >= r9 ) goto label$4214514_1_33;
	++r8;
	if( r5 == NULL ) hl_null_access();
	r10 = r4;
	++r4;
	r12 = 0;
	haxe_io_Bytes_set(r5,r10,r12);
	r10 = 0;
	r12 = r0;
	label$4214514_1_20:
	if( r10 >= r12 ) goto label$4214514_1_32;
	++r10;
	if( r5 == NULL ) hl_null_access();
	r13 = r4;
	++r4;
	if( r2 == NULL ) hl_null_access();
	r14 = r6;
	++r6;
	r14 = haxe_io_Bytes_get(r2,r14);
	haxe_io_Bytes_set(r5,r13,r14);
	goto label$4214514_1_20;
	label$4214514_1_32:
	goto label$4214514_1_10;
	label$4214514_1_33:
	r15 = (haxe__ds__List)hl_alloc_obj(&t$haxe_ds_List);
	haxe_ds_List_new(r15);
	r17 = hl_alloc_virtual(&t$vrt_1b4afe7);
	if( hl_vfields(r17)[4] ) *(int*)(hl_vfields(r17)[4]) = (int)r0; else hl_dyn_seti(r17->value,-362629759/*width*/,&t$_i32,r0);
	if( hl_vfields(r17)[2] ) *(int*)(hl_vfields(r17)[2]) = (int)r1; else hl_dyn_seti(r17->value,38537191/*height*/,&t$_i32,r1);
	r8 = 8;
	if( hl_vfields(r17)[0] ) *(int*)(hl_vfields(r17)[0]) = (int)r8; else hl_dyn_seti(r17->value,-423126202/*colbits*/,&t$_i32,r8);
	r19 = false;
	r18 = hl_alloc_enum(&t$format_png_Color,0);
	((format_png_Color_ColGrey*)r18)->p0 = r19;
	if( hl_vfields(r17)[1] ) *(venum**)(hl_vfields(r17)[1]) = (venum*)r18; else hl_dyn_setp(r17->value,173830765/*color*/,&t$format_png_Color,r18);
	r19 = false;
	if( hl_vfields(r17)[3] ) *(bool*)(hl_vfields(r17)[3]) = (bool)r19; else hl_dyn_seti(r17->value,-109524212/*interlaced*/,&t$_bool,r19);
	r16 = hl_alloc_enum(&t$format_png_Chunk,1);
	((format_png_Chunk_CHeader*)r16)->p0 = r17;
	haxe_ds_List_add(r15,((vdynamic*)r16));
	r11 = format_tools_Deflate_run(r5,r3);
	r16 = hl_alloc_enum(&t$format_png_Chunk,2);
	((format_png_Chunk_CData*)r16)->p0 = r11;
	haxe_ds_List_add(r15,((vdynamic*)r16));
	r16 = (venum*)g$format_png_Chunk_CEnd;
	haxe_ds_List_add(r15,((vdynamic*)r16));
	return r15;
}

haxe__ds__List format_png_Tools_build32ARGB(int r0,int r1,haxe__io__Bytes r2,vdynamic* r3) {
	vvirtual *r18;
	venum *r17, *r19;
	bool r20;
	haxe__io__Bytes r5, r11;
	haxe__ds__List r16;
	int r4, r6, r8, r9, r10, r12, r13, r14, r15;
	if( r3 ) goto label$4214514_2_3;
	r4 = 9;
	r3 = hl_alloc_dynamic(&t$_i32);
	r3->v.i = r4;
	label$4214514_2_3:
	r4 = r0 * r1;
	r6 = 4;
	r4 = r4 * r6;
	r4 = r4 + r1;
	r5 = haxe_io_Bytes_alloc(r4);
	r4 = 0;
	r6 = 0;
	r8 = 0;
	r9 = r1;
	label$4214514_2_12:
	if( r8 >= r9 ) goto label$4214514_2_54;
	++r8;
	if( r5 == NULL ) hl_null_access();
	r10 = r4;
	++r4;
	r12 = 0;
	haxe_io_Bytes_set(r5,r10,r12);
	r10 = 0;
	r12 = r0;
	label$4214514_2_22:
	if( r10 >= r12 ) goto label$4214514_2_53;
	++r10;
	if( r5 == NULL ) hl_null_access();
	r13 = r4;
	++r4;
	if( r2 == NULL ) hl_null_access();
	r15 = 1;
	r14 = r6 + r15;
	r14 = haxe_io_Bytes_get(r2,r14);
	haxe_io_Bytes_set(r5,r13,r14);
	r13 = r4;
	++r4;
	r15 = 2;
	r14 = r6 + r15;
	r14 = haxe_io_Bytes_get(r2,r14);
	haxe_io_Bytes_set(r5,r13,r14);
	r13 = r4;
	++r4;
	r15 = 3;
	r14 = r6 + r15;
	r14 = haxe_io_Bytes_get(r2,r14);
	haxe_io_Bytes_set(r5,r13,r14);
	r13 = r4;
	++r4;
	r14 = haxe_io_Bytes_get(r2,r6);
	haxe_io_Bytes_set(r5,r13,r14);
	r14 = 4;
	r13 = r6 + r14;
	r6 = r13;
	goto label$4214514_2_22;
	label$4214514_2_53:
	goto label$4214514_2_12;
	label$4214514_2_54:
	r16 = (haxe__ds__List)hl_alloc_obj(&t$haxe_ds_List);
	haxe_ds_List_new(r16);
	r18 = hl_alloc_virtual(&t$vrt_1b4afe7);
	if( hl_vfields(r18)[4] ) *(int*)(hl_vfields(r18)[4]) = (int)r0; else hl_dyn_seti(r18->value,-362629759/*width*/,&t$_i32,r0);
	if( hl_vfields(r18)[2] ) *(int*)(hl_vfields(r18)[2]) = (int)r1; else hl_dyn_seti(r18->value,38537191/*height*/,&t$_i32,r1);
	r8 = 8;
	if( hl_vfields(r18)[0] ) *(int*)(hl_vfields(r18)[0]) = (int)r8; else hl_dyn_seti(r18->value,-423126202/*colbits*/,&t$_i32,r8);
	r20 = true;
	r19 = hl_alloc_enum(&t$format_png_Color,1);
	((format_png_Color_ColTrue*)r19)->p0 = r20;
	if( hl_vfields(r18)[1] ) *(venum**)(hl_vfields(r18)[1]) = (venum*)r19; else hl_dyn_setp(r18->value,173830765/*color*/,&t$format_png_Color,r19);
	r20 = false;
	if( hl_vfields(r18)[3] ) *(bool*)(hl_vfields(r18)[3]) = (bool)r20; else hl_dyn_seti(r18->value,-109524212/*interlaced*/,&t$_bool,r20);
	r17 = hl_alloc_enum(&t$format_png_Chunk,1);
	((format_png_Chunk_CHeader*)r17)->p0 = r18;
	haxe_ds_List_add(r16,((vdynamic*)r17));
	r11 = format_tools_Deflate_run(r5,r3);
	r17 = hl_alloc_enum(&t$format_png_Chunk,2);
	((format_png_Chunk_CData*)r17)->p0 = r11;
	haxe_ds_List_add(r16,((vdynamic*)r17));
	r17 = (venum*)g$format_png_Chunk_CEnd;
	haxe_ds_List_add(r16,((vdynamic*)r17));
	return r16;
}

haxe__ds__List format_png_Tools_build32BGRA(int r0,int r1,haxe__io__Bytes r2,vdynamic* r3) {
	vvirtual *r18;
	venum *r17, *r19;
	bool r20;
	haxe__io__Bytes r5, r11;
	haxe__ds__List r16;
	int r4, r6, r8, r9, r10, r12, r13, r14, r15;
	if( r3 ) goto label$4214514_3_3;
	r4 = 9;
	r3 = hl_alloc_dynamic(&t$_i32);
	r3->v.i = r4;
	label$4214514_3_3:
	r4 = r0 * r1;
	r6 = 4;
	r4 = r4 * r6;
	r4 = r4 + r1;
	r5 = haxe_io_Bytes_alloc(r4);
	r4 = 0;
	r6 = 0;
	r8 = 0;
	r9 = r1;
	label$4214514_3_12:
	if( r8 >= r9 ) goto label$4214514_3_54;
	++r8;
	if( r5 == NULL ) hl_null_access();
	r10 = r4;
	++r4;
	r12 = 0;
	haxe_io_Bytes_set(r5,r10,r12);
	r10 = 0;
	r12 = r0;
	label$4214514_3_22:
	if( r10 >= r12 ) goto label$4214514_3_53;
	++r10;
	if( r5 == NULL ) hl_null_access();
	r13 = r4;
	++r4;
	if( r2 == NULL ) hl_null_access();
	r15 = 2;
	r14 = r6 + r15;
	r14 = haxe_io_Bytes_get(r2,r14);
	haxe_io_Bytes_set(r5,r13,r14);
	r13 = r4;
	++r4;
	r15 = 1;
	r14 = r6 + r15;
	r14 = haxe_io_Bytes_get(r2,r14);
	haxe_io_Bytes_set(r5,r13,r14);
	r13 = r4;
	++r4;
	r14 = haxe_io_Bytes_get(r2,r6);
	haxe_io_Bytes_set(r5,r13,r14);
	r13 = r4;
	++r4;
	r15 = 3;
	r14 = r6 + r15;
	r14 = haxe_io_Bytes_get(r2,r14);
	haxe_io_Bytes_set(r5,r13,r14);
	r14 = 4;
	r13 = r6 + r14;
	r6 = r13;
	goto label$4214514_3_22;
	label$4214514_3_53:
	goto label$4214514_3_12;
	label$4214514_3_54:
	r16 = (haxe__ds__List)hl_alloc_obj(&t$haxe_ds_List);
	haxe_ds_List_new(r16);
	r18 = hl_alloc_virtual(&t$vrt_1b4afe7);
	if( hl_vfields(r18)[4] ) *(int*)(hl_vfields(r18)[4]) = (int)r0; else hl_dyn_seti(r18->value,-362629759/*width*/,&t$_i32,r0);
	if( hl_vfields(r18)[2] ) *(int*)(hl_vfields(r18)[2]) = (int)r1; else hl_dyn_seti(r18->value,38537191/*height*/,&t$_i32,r1);
	r8 = 8;
	if( hl_vfields(r18)[0] ) *(int*)(hl_vfields(r18)[0]) = (int)r8; else hl_dyn_seti(r18->value,-423126202/*colbits*/,&t$_i32,r8);
	r20 = true;
	r19 = hl_alloc_enum(&t$format_png_Color,1);
	((format_png_Color_ColTrue*)r19)->p0 = r20;
	if( hl_vfields(r18)[1] ) *(venum**)(hl_vfields(r18)[1]) = (venum*)r19; else hl_dyn_setp(r18->value,173830765/*color*/,&t$format_png_Color,r19);
	r20 = false;
	if( hl_vfields(r18)[3] ) *(bool*)(hl_vfields(r18)[3]) = (bool)r20; else hl_dyn_seti(r18->value,-109524212/*interlaced*/,&t$_bool,r20);
	r17 = hl_alloc_enum(&t$format_png_Chunk,1);
	((format_png_Chunk_CHeader*)r17)->p0 = r18;
	haxe_ds_List_add(r16,((vdynamic*)r17));
	r11 = format_tools_Deflate_run(r5,r3);
	r17 = hl_alloc_enum(&t$format_png_Chunk,2);
	((format_png_Chunk_CData*)r17)->p0 = r11;
	haxe_ds_List_add(r16,((vdynamic*)r17));
	r17 = (venum*)g$format_png_Chunk_CEnd;
	haxe_ds_List_add(r16,((vdynamic*)r17));
	return r16;
}

