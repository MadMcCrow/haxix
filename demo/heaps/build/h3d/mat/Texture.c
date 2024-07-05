﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/mat/Texture.h>
extern h3d__mat__$Texture g$_h3d_mat_Texture;
#include <h3d/Engine.h>
bool h3d_mat_Texture_isDepth(h3d__mat__Texture);
extern h3d__$Engine g$_h3d_Engine;
void h3d_impl_MemoryManager_allocDepth(h3d__impl__MemoryManager,h3d__mat__Texture);
void h3d_impl_MemoryManager_allocTexture(h3d__impl__MemoryManager,h3d__mat__Texture);
extern String s$a0b3e07;
#include <hl/natives.h>
String String___alloc__(vbyte*,int);
String String___add__(String,String);
extern String s$84c4047;
extern String s$x;
extern String s$9371d7a;
void h3d_mat_Texture_dispose(h3d__mat__Texture);
#include <h3d/DepthBinding.h>
#include <hxd/Pixels.h>
#include <haxe/io/Bytes.h>
extern hl_type t$_i32;
void h3d_Engine_pushTarget(h3d__Engine,h3d__mat__Texture,int*,int*,venum*);
void h3d_Engine_clear(h3d__Engine,vdynamic*,vdynamic*,vdynamic*);
void h3d_Engine_popTarget(h3d__Engine);
hxd__Pixels hxd_Pixels_alloc(int,int,venum*);
extern String s$TODO;
void haxe_io_Bytes_set(haxe__io__Bytes,int,int);
void h3d_mat_Texture_uploadPixels(h3d__mat__Texture,hxd__Pixels,int*,int*);
void hxd_Pixels_dispose(hxd__Pixels);
extern String s$Invalid_upload_size_;
extern String s$_should_be_;
#include <h3d/impl/Driver.h>
void h3d_impl_MemoryManager_deleteDepth(h3d__impl__MemoryManager,h3d__mat__Texture);
void h3d_impl_MemoryManager_deleteTexture(h3d__impl__MemoryManager,h3d__mat__Texture);
#include <haxe/ds/IntMap.h>
#include <hl/types/ArrayObj.h>
extern hl_type t$_f64;
vdynamic* haxe_ds_IntMap_get(haxe__ds__IntMap,int);
extern hl_type t$h3d_mat_Texture;
void h3d_mat_Texture_new(h3d__mat__Texture,int,int,hl__types__ArrayObj,venum*);
extern hl_type t$ctx_25196c1;
extern hl_type t$fun_f5c4101;
void haxe_ds_IntMap_set(haxe__ds__IntMap,int,vdynamic*);
#include <haxe/ds/ObjectMap.h>
#include <h3d/mat/TextureFlags.h>
vdynamic* haxe_ds_ObjectMap_get(haxe__ds__ObjectMap,vdynamic*);
extern hl_type t$_dyn;
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern hl_type t$h3d_mat_TextureFlags;
extern venum* g$h3d_mat_TextureFlags_Cube;
void hl_types_ArrayObj___expand(hl__types__ArrayObj,int);
extern hl_type t$fun_715d8bf;
void haxe_ds_ObjectMap_set(haxe__ds__ObjectMap,vdynamic*,vdynamic*);
extern venum* g$h3d_mat_MipMap_Linear;
extern venum* g$h3d_mat_MipMap_Nearest;
extern venum* g$h3d_mat_MipMap_None;
extern venum* g$h3d_mat_Filter_Linear;

int h3d_mat_Texture_set_lastFrame(h3d__mat__Texture r0,int r1) {
	h3d__mat__$Texture r4;
	int r2, r3;
	r2 = r0->_lastFrame;
	r4 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r3 = r4->PREVENT_AUTO_DISPOSE;
	if( r2 == r3 ) goto label$3bd692e_1_5;
	r0->_lastFrame = r1;
	label$3bd692e_1_5:
	r2 = r0->_lastFrame;
	return r2;
}

int h3d_mat_Texture_get_mipLevels(h3d__mat__Texture r0) {
	int r1, r2, r3, r4, r5;
	r1 = r0->flags;
	r2 = 4;
	r1 = r1 & r2;
	r2 = 0;
	if( r1 != r2 ) goto label$3bd692e_2_7;
	r1 = 1;
	return r1;
	label$3bd692e_2_7:
	r1 = r0->customMipLevels;
	r2 = 0;
	if( r2 >= r1 ) goto label$3bd692e_2_12;
	r1 = r0->customMipLevels;
	return r1;
	label$3bd692e_2_12:
	r1 = 1;
	r2 = r0->width;
	r3 = r0->height;
	label$3bd692e_2_15:
	r4 = r2 >> r1;
	r5 = 1;
	if( r4 >= r5 ) goto label$3bd692e_2_22;
	r4 = r3 >> r1;
	r5 = 1;
	if( r4 < r5 ) goto label$3bd692e_2_24;
	label$3bd692e_2_22:
	++r1;
	goto label$3bd692e_2_15;
	label$3bd692e_2_24:
	return r1;
}

int h3d_mat_Texture_get_layerCount(h3d__mat__Texture r0) {
	int r1, r2;
	r1 = r0->flags;
	r2 = 2;
	r1 = r1 & r2;
	r2 = 0;
	if( r1 == r2 ) goto label$3bd692e_3_7;
	r1 = 6;
	return r1;
	label$3bd692e_3_7:
	r1 = 1;
	return r1;
}

void h3d_mat_Texture_alloc(h3d__mat__Texture r0) {
	vvirtual *r6;
	bool r2;
	h3d__Engine r4;
	h3d__$Engine r5;
	h3d__impl__MemoryManager r3;
	r2 = h3d_mat_Texture_isDepth(r0);
	if( !r2 ) goto label$3bd692e_4_9;
	r5 = (h3d__$Engine)g$_h3d_Engine;
	r4 = r5->CURRENT;
	if( r4 == NULL ) hl_null_access();
	r3 = r4->mem;
	if( r3 == NULL ) hl_null_access();
	h3d_impl_MemoryManager_allocDepth(r3,r0);
	goto label$3bd692e_4_14;
	label$3bd692e_4_9:
	r6 = r0->_hx_t;
	if( r6 ) goto label$3bd692e_4_14;
	r3 = r0->mem;
	if( r3 == NULL ) hl_null_access();
	h3d_impl_MemoryManager_allocTexture(r3,r0);
	label$3bd692e_4_14:
	return;
}

bool h3d_mat_Texture_isSRGB(h3d__mat__Texture r0) {
	venum *r2;
	bool r3;
	int r1;
	r2 = r0->format;
	if( r2 == NULL ) hl_null_access();
	r1 = HL__ENUM_INDEX__(r2);
	switch(r1) {
		default:
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
			r3 = false;
			return r3;
		case 14:
		case 15:
			r3 = true;
			return r3;
	}
}

vbyte* h3d_mat_Texture___string(h3d__mat__Texture r0) {
	String r2;
	vbyte *r1;
	r2 = ((String (*)(h3d__mat__Texture))r0->$type->vobj_proto[1])(r0);
	if( r2 == NULL ) hl_null_access();
	r1 = r2->bytes;
	return r1;
}

String h3d_mat_Texture_toString(h3d__mat__Texture r0) {
	String r1, r2, r6;
	int *r4;
	vbyte *r5;
	int r3;
	r1 = r0->name;
	r2 = r0->name;
	if( r2 ) goto label$3bd692e_7_10;
	r2 = (String)s$a0b3e07;
	r3 = r0->id;
	r4 = &r3;
	r5 = hl_itos(r3,r4);
	r6 = String___alloc__(r5,r3);
	r2 = String___add__(r2,r6);
	r1 = r2;
	label$3bd692e_7_10:
	r6 = (String)s$84c4047;
	r2 = String___add__(r1,r6);
	r3 = r0->width;
	r4 = &r3;
	r5 = hl_itos(r3,r4);
	r6 = String___alloc__(r5,r3);
	r2 = String___add__(r2,r6);
	r6 = (String)s$x;
	r2 = String___add__(r2,r6);
	r3 = r0->height;
	r4 = &r3;
	r5 = hl_itos(r3,r4);
	r6 = String___alloc__(r5,r3);
	r2 = String___add__(r2,r6);
	r6 = (String)s$9371d7a;
	r2 = String___add__(r2,r6);
	return r2;
}

void h3d_mat_Texture_setName(h3d__mat__Texture r0,String r1) {
	r0->name = r1;
	return;
}

venum* h3d_mat_Texture_set_mipMap(h3d__mat__Texture r0,venum* r1) {
	int r2, r3;
	r2 = r0->bits;
	r3 = -4;
	r2 = r2 & r3;
	if( r1 == NULL ) hl_null_access();
	r3 = HL__ENUM_INDEX__(r1);
	r2 = r2 | r3;
	r0->bits = r2;
	r0->mipMap = r1;
	return r1;
}

venum* h3d_mat_Texture_set_filter(h3d__mat__Texture r0,venum* r1) {
	int r2, r3, r4;
	r2 = r0->bits;
	r3 = -25;
	r2 = r2 & r3;
	if( r1 == NULL ) hl_null_access();
	r3 = HL__ENUM_INDEX__(r1);
	r4 = 3;
	r3 = r3 << r4;
	r2 = r2 | r3;
	r0->bits = r2;
	r0->filter = r1;
	return r1;
}

venum* h3d_mat_Texture_set_wrap(h3d__mat__Texture r0,venum* r1) {
	int r2, r3, r4;
	r2 = r0->bits;
	r3 = -193;
	r2 = r2 & r3;
	if( r1 == NULL ) hl_null_access();
	r3 = HL__ENUM_INDEX__(r1);
	r4 = 6;
	r3 = r3 << r4;
	r2 = r2 | r3;
	r0->bits = r2;
	r0->wrap = r1;
	return r1;
}

void h3d_mat_Texture_resize(h3d__mat__Texture r0,int r1,int r2) {
	int r4, r5, r6, r7;
	h3d_mat_Texture_dispose(r0);
	r4 = 1;
	r5 = 1;
	label$3bd692e_12_3:
	if( r4 >= r1 ) goto label$3bd692e_12_9;
	r7 = 1;
	r6 = r4 << r7;
	r4 = r6;
	goto label$3bd692e_12_3;
	label$3bd692e_12_9:
	if( r5 >= r2 ) goto label$3bd692e_12_15;
	r7 = 1;
	r6 = r5 << r7;
	r5 = r6;
	goto label$3bd692e_12_9;
	label$3bd692e_12_15:
	if( r4 != r1 ) goto label$3bd692e_12_17;
	if( r5 == r2 ) goto label$3bd692e_12_22;
	label$3bd692e_12_17:
	r6 = r0->flags;
	r7 = 16;
	r6 = r6 | r7;
	r0->flags = r6;
	goto label$3bd692e_12_26;
	label$3bd692e_12_22:
	r6 = r0->flags;
	r7 = -17;
	r6 = r6 & r7;
	r0->flags = r6;
	label$3bd692e_12_26:
	r0->width = r1;
	r0->height = r2;
	r6 = r0->flags;
	r7 = 32;
	r6 = r6 & r7;
	r7 = 0;
	if( r6 != r7 ) goto label$3bd692e_12_34;
	h3d_mat_Texture_alloc(r0);
	label$3bd692e_12_34:
	return;
}

void h3d_mat_Texture_clear(h3d__mat__Texture r0,int r1,double* r2,vdynamic* r3) {
	String r29;
	hxd__Pixels r23;
	venum *r19, *r24;
	haxe__io__Bytes r32;
	h3d__mat__$Texture r25;
	h3d__Engine r8;
	h3d__$Engine r9;
	double r4, r10, r11, r12;
	int *r17, *r18;
	vdynamic *r15, *r21, *r22;
	int r5, r7, r13, r14, r16, r20, r26, r27, r28, r30, r31, r33;
	if( r2 ) goto label$3bd692e_13_3;
	r4 = 1.;
	goto label$3bd692e_13_4;
	label$3bd692e_13_3:
	r4 = *r2;
	label$3bd692e_13_4:
	if( r3 ) goto label$3bd692e_13_7;
	r5 = -1;
	r3 = hl_alloc_dynamic(&t$_i32);
	r3->v.i = r5;
	label$3bd692e_13_7:
	h3d_mat_Texture_alloc(r0);
	r5 = r0->width;
	r7 = 0;
	if( r5 == r7 ) goto label$3bd692e_13_14;
	r5 = r0->height;
	r7 = 0;
	if( r5 != r7 ) goto label$3bd692e_13_15;
	label$3bd692e_13_14:
	return;
	label$3bd692e_13_15:
	r5 = r0->width;
	r7 = 1;
	if( r5 != r7 ) goto label$3bd692e_13_21;
	r5 = r0->height;
	r7 = 1;
	if( r5 == r7 ) goto label$3bd692e_13_76;
	label$3bd692e_13_21:
	r9 = (h3d__$Engine)g$_h3d_Engine;
	r8 = r9->CURRENT;
	r10 = 0.;
	r11 = 1.;
	if( !(r4 < r10) ) goto label$3bd692e_13_28;
	r12 = r10;
	goto label$3bd692e_13_32;
	label$3bd692e_13_28:
	if( !(r11 < r4) ) goto label$3bd692e_13_31;
	r12 = r11;
	goto label$3bd692e_13_32;
	label$3bd692e_13_31:
	r12 = r4;
	label$3bd692e_13_32:
	r10 = 255.;
	r10 = r12 * r10;
	r5 = (int)r10;
	r14 = 24;
	r13 = r5 << r14;
	r7 = r1 | r13;
	r1 = r7;
	r7 = r3 ? r3->v.i : 0;
	r13 = 0;
	if( r7 >= r13 ) goto label$3bd692e_13_61;
	r7 = 0;
	r13 = ((int (*)(h3d__mat__Texture))r0->$type->vobj_proto[0])(r0);
	label$3bd692e_13_44:
	if( r7 >= r13 ) goto label$3bd692e_13_60;
	r14 = r7;
	++r7;
	if( r8 == NULL ) hl_null_access();
	r16 = r14;
	r17 = &r16;
	r18 = NULL;
	r19 = NULL;
	h3d_Engine_pushTarget(r8,r0,r17,r18,r19);
	r15 = hl_alloc_dynamic(&t$_i32);
	r15->v.i = r1;
	r21 = NULL;
	r22 = NULL;
	h3d_Engine_clear(r8,r15,r21,r22);
	h3d_Engine_popTarget(r8);
	goto label$3bd692e_13_44;
	label$3bd692e_13_60:
	goto label$3bd692e_13_75;
	label$3bd692e_13_61:
	if( r8 == NULL ) hl_null_access();
	if( r3 ) goto label$3bd692e_13_65;
	r17 = NULL;
	goto label$3bd692e_13_67;
	label$3bd692e_13_65:
	r7 = r3 ? r3->v.i : 0;
	r17 = &r7;
	label$3bd692e_13_67:
	r18 = NULL;
	r19 = NULL;
	h3d_Engine_pushTarget(r8,r0,r17,r18,r19);
	r15 = hl_alloc_dynamic(&t$_i32);
	r15->v.i = r1;
	r21 = NULL;
	r22 = NULL;
	h3d_Engine_clear(r8,r15,r21,r22);
	h3d_Engine_popTarget(r8);
	label$3bd692e_13_75:
	goto label$3bd692e_13_170;
	label$3bd692e_13_76:
	r5 = r0->width;
	r13 = r0->height;
	r25 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r24 = r25->nativeFormat;
	r23 = hxd_Pixels_alloc(r5,r13,r24);
	r5 = 0;
	r14 = 255;
	r13 = r1 & r14;
	r20 = 8;
	r14 = r1 >> r20;
	r20 = 255;
	r14 = r14 & r20;
	r26 = 16;
	r20 = r1 >> r26;
	r26 = 255;
	r20 = r20 & r26;
	r11 = 255.;
	r10 = r4 * r11;
	r26 = (int)r10;
	r28 = 0;
	if( r26 >= r28 ) goto label$3bd692e_13_100;
	r27 = 0;
	r26 = r27;
	goto label$3bd692e_13_104;
	label$3bd692e_13_100:
	r28 = 255;
	if( r28 >= r26 ) goto label$3bd692e_13_104;
	r27 = 255;
	r26 = r27;
	label$3bd692e_13_104:
	r25 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r24 = r25->nativeFormat;
	if( r24 == NULL ) hl_null_access();
	r27 = HL__ENUM_INDEX__(r24);
	switch(r27) {
		default:
		case 0:
			r29 = (String)s$TODO;
			hl_throw((vdynamic*)r29);
		case 1:
			r27 = r20;
			r20 = r13;
			r13 = r27;
			goto label$3bd692e_13_115;
		case 2:
			break;
	}
	label$3bd692e_13_115:
	r27 = 0;
	r28 = r0->width;
	r30 = r0->height;
	r28 = r28 * r30;
	label$3bd692e_13_119:
	if( r27 >= r28 ) goto label$3bd692e_13_144;
	++r27;
	if( r23 == NULL ) hl_null_access();
	r32 = r23->bytes;
	if( r32 == NULL ) hl_null_access();
	r31 = r5;
	++r5;
	haxe_io_Bytes_set(r32,r31,r20);
	r32 = r23->bytes;
	if( r32 == NULL ) hl_null_access();
	r31 = r5;
	++r5;
	haxe_io_Bytes_set(r32,r31,r14);
	r32 = r23->bytes;
	if( r32 == NULL ) hl_null_access();
	r31 = r5;
	++r5;
	haxe_io_Bytes_set(r32,r31,r13);
	r32 = r23->bytes;
	if( r32 == NULL ) hl_null_access();
	r31 = r5;
	++r5;
	haxe_io_Bytes_set(r32,r31,r26);
	goto label$3bd692e_13_119;
	label$3bd692e_13_144:
	r27 = r3 ? r3->v.i : 0;
	r28 = 0;
	if( r27 >= r28 ) goto label$3bd692e_13_160;
	r27 = 0;
	r28 = ((int (*)(h3d__mat__Texture))r0->$type->vobj_proto[0])(r0);
	label$3bd692e_13_149:
	if( r27 >= r28 ) goto label$3bd692e_13_159;
	r30 = r27;
	++r27;
	r31 = 0;
	r17 = &r31;
	r33 = r30;
	r18 = &r33;
	h3d_mat_Texture_uploadPixels(r0,r23,r17,r18);
	goto label$3bd692e_13_149;
	label$3bd692e_13_159:
	goto label$3bd692e_13_168;
	label$3bd692e_13_160:
	r27 = 0;
	r17 = &r27;
	if( r3 ) goto label$3bd692e_13_165;
	r18 = NULL;
	goto label$3bd692e_13_167;
	label$3bd692e_13_165:
	r28 = r3 ? r3->v.i : 0;
	r18 = &r28;
	label$3bd692e_13_167:
	h3d_mat_Texture_uploadPixels(r0,r23,r17,r18);
	label$3bd692e_13_168:
	if( r23 == NULL ) hl_null_access();
	hxd_Pixels_dispose(r23);
	label$3bd692e_13_170:
	return;
}

void h3d_mat_Texture_checkSize(h3d__mat__Texture r0,int r1,int r2,int r3) {
	String r9, r12;
	int *r10;
	vbyte *r11;
	int r4, r5, r7, r8;
	r4 = r0->width;
	r4 = r4 >> r3;
	r7 = 0;
	if( r4 != r7 ) goto label$3bd692e_14_6;
	r5 = 1;
	r4 = r5;
	label$3bd692e_14_6:
	r5 = r0->height;
	r5 = r5 >> r3;
	r8 = 0;
	if( r5 != r8 ) goto label$3bd692e_14_12;
	r7 = 1;
	r5 = r7;
	label$3bd692e_14_12:
	if( r1 != r4 ) goto label$3bd692e_14_14;
	if( r2 == r5 ) goto label$3bd692e_14_42;
	label$3bd692e_14_14:
	r9 = (String)s$Invalid_upload_size_;
	r7 = r1;
	r10 = &r7;
	r11 = hl_itos(r7,r10);
	r12 = String___alloc__(r11,r7);
	r9 = String___add__(r9,r12);
	r12 = (String)s$x;
	r9 = String___add__(r9,r12);
	r7 = r2;
	r10 = &r7;
	r11 = hl_itos(r7,r10);
	r12 = String___alloc__(r11,r7);
	r9 = String___add__(r9,r12);
	r12 = (String)s$_should_be_;
	r9 = String___add__(r9,r12);
	r7 = r4;
	r10 = &r7;
	r11 = hl_itos(r7,r10);
	r12 = String___alloc__(r11,r7);
	r9 = String___add__(r9,r12);
	r12 = (String)s$x;
	r9 = String___add__(r9,r12);
	r7 = r5;
	r10 = &r7;
	r11 = hl_itos(r7,r10);
	r12 = String___alloc__(r11,r7);
	r9 = String___add__(r9,r12);
	hl_throw((vdynamic*)r9);
	label$3bd692e_14_42:
	return;
}

void h3d_mat_Texture_checkMipMapGen(h3d__mat__Texture r0,int r1,int r2) {
	h3d__impl__MemoryManager r8;
	h3d__impl__Driver r7;
	int r4, r5, r6;
	r5 = 0;
	if( r1 != r5 ) goto label$3bd692e_15_21;
	r4 = r0->flags;
	r5 = 4;
	r4 = r4 & r5;
	r5 = 0;
	if( r4 == r5 ) goto label$3bd692e_15_21;
	r4 = r0->flags;
	r5 = 8;
	r4 = r4 & r5;
	r5 = 0;
	if( r4 != r5 ) goto label$3bd692e_15_21;
	r5 = ((int (*)(h3d__mat__Texture))r0->$type->vobj_proto[0])(r0);
	r6 = 1;
	r5 = r5 - r6;
	if( r2 != r5 ) goto label$3bd692e_15_21;
	r8 = r0->mem;
	if( r8 == NULL ) hl_null_access();
	r7 = r8->driver;
	if( r7 == NULL ) hl_null_access();
	((void (*)(h3d__impl__Driver,h3d__mat__Texture))r7->$type->vobj_proto[5])(r7,r0);
	label$3bd692e_15_21:
	return;
}

void h3d_mat_Texture_uploadPixels(h3d__mat__Texture r0,hxd__Pixels r1,int* r2,int* r3) {
	h3d__impl__MemoryManager r10;
	h3d__impl__Driver r9;
	int r4, r5, r7, r8;
	if( r2 ) goto label$3bd692e_16_3;
	r4 = 0;
	goto label$3bd692e_16_4;
	label$3bd692e_16_3:
	r4 = *r2;
	label$3bd692e_16_4:
	if( r3 ) goto label$3bd692e_16_7;
	r5 = 0;
	goto label$3bd692e_16_8;
	label$3bd692e_16_7:
	r5 = *r3;
	label$3bd692e_16_8:
	h3d_mat_Texture_alloc(r0);
	if( r1 == NULL ) hl_null_access();
	r7 = r1->width;
	r8 = r1->height;
	h3d_mat_Texture_checkSize(r0,r7,r8,r4);
	r10 = r0->mem;
	if( r10 == NULL ) hl_null_access();
	r9 = r10->driver;
	if( r9 == NULL ) hl_null_access();
	((void (*)(h3d__impl__Driver,h3d__mat__Texture,hxd__Pixels,int,int))r9->$type->vobj_proto[35])(r9,r0,r1,r4,r5);
	r7 = r0->flags;
	r8 = 256;
	r7 = r7 | r8;
	r0->flags = r7;
	h3d_mat_Texture_checkMipMapGen(r0,r4,r5);
	return;
}

void h3d_mat_Texture_dispose(h3d__mat__Texture r0) {
	vvirtual *r2;
	bool r3;
	h3d__Engine r5;
	h3d__$Engine r6;
	h3d__impl__MemoryManager r4;
	r2 = r0->_hx_t;
	if( !r2 ) goto label$3bd692e_17_14;
	r3 = h3d_mat_Texture_isDepth(r0);
	if( !r3 ) goto label$3bd692e_17_11;
	r6 = (h3d__$Engine)g$_h3d_Engine;
	r5 = r6->CURRENT;
	if( r5 == NULL ) hl_null_access();
	r4 = r5->mem;
	if( r4 == NULL ) hl_null_access();
	h3d_impl_MemoryManager_deleteDepth(r4,r0);
	goto label$3bd692e_17_14;
	label$3bd692e_17_11:
	r4 = r0->mem;
	if( r4 == NULL ) hl_null_access();
	h3d_impl_MemoryManager_deleteTexture(r4,r0);
	label$3bd692e_17_14:
	return;
}

void h3d_mat_Texture_fromColor__$1(venum* r0) {
	double r6;
	double *r5;
	vdynamic *r4, *r7;
	int r3;
	h3d__mat__Texture r2;
	r2 = ((Enumt$ctx_25196c1*)r0)->p2;
	if( r2 == NULL ) hl_null_access();
	r3 = ((Enumt$ctx_25196c1*)r0)->p0;
	r4 = ((Enumt$ctx_25196c1*)r0)->p1;
	if( r4 ) goto label$3bd692e_18_7;
	r5 = NULL;
	goto label$3bd692e_18_9;
	label$3bd692e_18_7:
	r6 = r4 ? r4->v.d : 0;
	r5 = &r6;
	label$3bd692e_18_9:
	r7 = NULL;
	h3d_mat_Texture_clear(r2,r3,r5,r7);
	return;
}

h3d__mat__Texture h3d_mat_Texture_fromColor(int r0,vdynamic* r1) {
	hl__types__ArrayObj r15;
	venum *r16, *r20;
	haxe__ds__IntMap r12;
	h3d__Engine r3;
	h3d__$Engine r4;
	vclosure *r19;
	double r2, r7;
	double *r17;
	vdynamic *r11, *r18;
	h3d__mat__Texture r13, r14;
	int r6, r8, r9, r10;
	if( r1 ) goto label$3bd692e_19_3;
	r2 = 1.;
	r1 = hl_alloc_dynamic(&t$_f64);
	r1->v.d = r2;
	label$3bd692e_19_3:
	r4 = (h3d__$Engine)g$_h3d_Engine;
	r3 = r4->CURRENT;
	r2 = r1 ? r1->v.d : 0;
	r7 = 255.;
	r2 = r2 * r7;
	r6 = (int)r2;
	r9 = 0;
	if( r6 >= r9 ) goto label$3bd692e_19_14;
	r8 = 0;
	r6 = r8;
	goto label$3bd692e_19_18;
	label$3bd692e_19_14:
	r9 = 255;
	if( r9 >= r6 ) goto label$3bd692e_19_18;
	r8 = 255;
	r6 = r8;
	label$3bd692e_19_18:
	r9 = 16777215;
	r8 = r0 & r9;
	r10 = 24;
	r9 = r6 << r10;
	r8 = r8 | r9;
	if( r3 == NULL ) hl_null_access();
	r12 = r3->textureColorCache;
	if( r12 == NULL ) hl_null_access();
	r11 = haxe_ds_IntMap_get(r12,r8);
	r13 = (h3d__mat__Texture)r11;
	if( !r13 ) goto label$3bd692e_19_30;
	return r13;
	label$3bd692e_19_30:
	r14 = (h3d__mat__Texture)hl_alloc_obj(&t$h3d_mat_Texture);
	r9 = 1;
	r10 = 1;
	r15 = NULL;
	r16 = NULL;
	h3d_mat_Texture_new(r14,r9,r10,r15,r16);
	if( r1 ) goto label$3bd692e_19_39;
	r17 = NULL;
	goto label$3bd692e_19_41;
	label$3bd692e_19_39:
	r2 = r1 ? r1->v.d : 0;
	r17 = &r2;
	label$3bd692e_19_41:
	r18 = NULL;
	h3d_mat_Texture_clear(r14,r0,r17,r18);
	r20 = hl_alloc_enum(&t$ctx_25196c1,0);
	((Enumt$ctx_25196c1*)r20)->p0 = (int)r0;
	((Enumt$ctx_25196c1*)r20)->p1 = (vdynamic*)r1;
	((Enumt$ctx_25196c1*)r20)->p2 = (h3d__mat__Texture)r14;
	r19 = hl_alloc_closure_ptr(&t$fun_f5c4101,h3d_mat_Texture_fromColor__$1,r20);
	r14->realloc = r19;
	r12 = r3->textureColorCache;
	if( r12 == NULL ) hl_null_access();
	haxe_ds_IntMap_set(r12,r8,((vdynamic*)r14));
	return r14;
}

void h3d_mat_Texture_defaultCubeTexture__$1(hl__types__ArrayObj r0) {
	double *r7;
	vdynamic *r5, *r8;
	varray *r6;
	h3d__mat__Texture r4;
	int r2, r3;
	if( r0 == NULL ) hl_null_access();
	r2 = 0;
	r3 = r0->length;
	if( ((unsigned)r2) < ((unsigned)r3) ) goto label$3bd692e_20_6;
	r4 = NULL;
	goto label$3bd692e_20_9;
	label$3bd692e_20_6:
	r6 = r0->array;
	r5 = ((vdynamic**)(r6 + 1))[r2];
	r4 = (h3d__mat__Texture)r5;
	label$3bd692e_20_9:
	if( r4 == NULL ) hl_null_access();
	r2 = 2105376;
	r7 = NULL;
	r8 = NULL;
	h3d_mat_Texture_clear(r4,r2,r7,r8);
	return;
}

h3d__mat__Texture h3d_mat_Texture_defaultCubeTexture() {
	haxe__ds__ObjectMap r8;
	hl__types__ArrayObj r3, r13;
	venum *r15, *r16;
	hl_type *r5;
	h3d__mat__$Texture r9;
	h3d__Engine r0;
	h3d__$Engine r1;
	vclosure *r19;
	double *r17;
	vdynamic *r7, *r18;
	h3d__mat__Texture r10;
	int r6, r11, r12, r14;
	varray *r4;
	r1 = (h3d__$Engine)g$_h3d_Engine;
	r0 = r1->CURRENT;
	r5 = &t$h3d_mat_Texture;
	r6 = 1;
	r4 = hl_alloc_array(r5,r6);
	if( r0 == NULL ) hl_null_access();
	r8 = r0->resCache;
	if( r8 == NULL ) hl_null_access();
	r9 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r7 = haxe_ds_ObjectMap_get(r8,((vdynamic*)r9));
	r10 = (h3d__mat__Texture)hl_dyn_castp(&r7,&t$_dyn,&t$h3d_mat_Texture);
	r6 = 0;
	((h3d__mat__Texture*)(r4 + 1))[r6] = r10;
	r3 = hl_types_ArrayObj_alloc(r4);
	if( r3 == NULL ) hl_null_access();
	r6 = 0;
	r11 = r3->length;
	if( ((unsigned)r6) < ((unsigned)r11) ) goto label$3bd692e_21_20;
	r10 = NULL;
	goto label$3bd692e_21_23;
	label$3bd692e_21_20:
	r4 = r3->array;
	r7 = ((vdynamic**)(r4 + 1))[r6];
	r10 = (h3d__mat__Texture)r7;
	label$3bd692e_21_23:
	if( !r10 ) goto label$3bd692e_21_33;
	r6 = 0;
	r11 = r3->length;
	if( ((unsigned)r6) < ((unsigned)r11) ) goto label$3bd692e_21_29;
	r10 = NULL;
	goto label$3bd692e_21_32;
	label$3bd692e_21_29:
	r4 = r3->array;
	r7 = ((vdynamic**)(r4 + 1))[r6];
	r10 = (h3d__mat__Texture)r7;
	label$3bd692e_21_32:
	return r10;
	label$3bd692e_21_33:
	r6 = 0;
	r10 = (h3d__mat__Texture)hl_alloc_obj(&t$h3d_mat_Texture);
	r11 = 1;
	r12 = 1;
	r5 = &t$h3d_mat_TextureFlags;
	r14 = 1;
	r4 = hl_alloc_array(r5,r14);
	r15 = (venum*)g$h3d_mat_TextureFlags_Cube;
	r14 = 0;
	((venum**)(r4 + 1))[r14] = r15;
	r13 = hl_types_ArrayObj_alloc(r4);
	r16 = NULL;
	h3d_mat_Texture_new(r10,r11,r12,r13,r16);
	r11 = r3->length;
	if( ((unsigned)r6) < ((unsigned)r11) ) goto label$3bd692e_21_49;
	hl_types_ArrayObj___expand(r3,r6);
	label$3bd692e_21_49:
	r4 = r3->array;
	((h3d__mat__Texture*)(r4 + 1))[r6] = r10;
	r6 = 0;
	r11 = r3->length;
	if( ((unsigned)r6) < ((unsigned)r11) ) goto label$3bd692e_21_56;
	r10 = NULL;
	goto label$3bd692e_21_59;
	label$3bd692e_21_56:
	r4 = r3->array;
	r7 = ((vdynamic**)(r4 + 1))[r6];
	r10 = (h3d__mat__Texture)r7;
	label$3bd692e_21_59:
	if( r10 == NULL ) hl_null_access();
	r6 = 2105376;
	r17 = NULL;
	r18 = NULL;
	h3d_mat_Texture_clear(r10,r6,r17,r18);
	r6 = 0;
	r11 = r3->length;
	if( ((unsigned)r6) < ((unsigned)r11) ) goto label$3bd692e_21_69;
	r10 = NULL;
	goto label$3bd692e_21_72;
	label$3bd692e_21_69:
	r4 = r3->array;
	r7 = ((vdynamic**)(r4 + 1))[r6];
	r10 = (h3d__mat__Texture)r7;
	label$3bd692e_21_72:
	if( r10 == NULL ) hl_null_access();
	r19 = hl_alloc_closure_ptr(&t$fun_715d8bf,h3d_mat_Texture_defaultCubeTexture__$1,r3);
	r10->realloc = r19;
	r8 = r0->resCache;
	if( r8 == NULL ) hl_null_access();
	r9 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r6 = 0;
	r11 = r3->length;
	if( ((unsigned)r6) < ((unsigned)r11) ) goto label$3bd692e_21_83;
	r10 = NULL;
	goto label$3bd692e_21_86;
	label$3bd692e_21_83:
	r4 = r3->array;
	r7 = ((vdynamic**)(r4 + 1))[r6];
	r10 = (h3d__mat__Texture)r7;
	label$3bd692e_21_86:
	haxe_ds_ObjectMap_set(r8,((vdynamic*)r9),((vdynamic*)r10));
	r6 = 0;
	r11 = r3->length;
	if( ((unsigned)r6) < ((unsigned)r11) ) goto label$3bd692e_21_92;
	r10 = NULL;
	goto label$3bd692e_21_95;
	label$3bd692e_21_92:
	r4 = r3->array;
	r7 = ((vdynamic**)(r4 + 1))[r6];
	r10 = (h3d__mat__Texture)r7;
	label$3bd692e_21_95:
	return r10;
}

bool h3d_mat_Texture_hasStencil(h3d__mat__Texture r0) {
	venum *r2;
	bool r4;
	int r1, r3;
	r2 = r0->format;
	if( r2 == NULL ) hl_null_access();
	r1 = HL__ENUM_INDEX__(r2);
	r3 = 25;
	if( r1 != r3 ) goto label$3bd692e_22_7;
	r4 = true;
	return r4;
	label$3bd692e_22_7:
	r4 = false;
	return r4;
}

bool h3d_mat_Texture_isDepth(h3d__mat__Texture r0) {
	venum *r2;
	bool r3;
	int r1;
	r2 = r0->format;
	if( r2 == NULL ) hl_null_access();
	r1 = HL__ENUM_INDEX__(r2);
	switch(r1) {
		default:
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
			r3 = false;
			return r3;
		case 23:
		case 24:
		case 25:
			r3 = true;
			return r3;
	}
}

h3d__mat__Texture h3d_mat_Texture_getDefaultDepth() {
	h3d__Engine r2;
	h3d__$Engine r3;
	h3d__impl__Driver r1;
	h3d__mat__Texture r0;
	r3 = (h3d__$Engine)g$_h3d_Engine;
	r2 = r3->CURRENT;
	if( r2 == NULL ) hl_null_access();
	r1 = r2->driver;
	if( r1 == NULL ) hl_null_access();
	r0 = ((h3d__mat__Texture (*)(h3d__impl__Driver))r1->$type->vobj_proto[22])(r1);
	return r0;
}

void h3d_mat_Texture_new(h3d__mat__Texture r0,int r1,int r2,hl__types__ArrayObj r3,venum* r4) {
	venum *r8, *r12, *r20, *r21, *r22;
	bool r16;
	h3d__Engine r17;
	h3d__mat__$Texture r9;
	h3d__impl__MemoryManager r19;
	h3d__$Engine r18;
	double r5;
	vdynamic *r13;
	varray *r14;
	int r6, r10, r11, r15;
	r5 = 0.;
	r0->lodBias = r5;
	r6 = 0;
	r0->startingMip = r6;
	if( r4 ) goto label$3bd692e_25_8;
	r9 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r8 = r9->nativeFormat;
	r4 = r8;
	label$3bd692e_25_8:
	r9 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r6 = r9->UID;
	++r6;
	r9->UID = r6;
	r0->id = r6;
	r0->format = r4;
	r6 = 0;
	r0->flags = r6;
	if( !r3 ) goto label$3bd692e_25_38;
	r6 = 0;
	label$3bd692e_25_18:
	if( r3 == NULL ) hl_null_access();
	r11 = r3->length;
	if( r6 >= r11 ) goto label$3bd692e_25_38;
	r11 = r3->length;
	if( ((unsigned)r6) < ((unsigned)r11) ) goto label$3bd692e_25_26;
	r12 = NULL;
	goto label$3bd692e_25_29;
	label$3bd692e_25_26:
	r14 = r3->array;
	r13 = ((vdynamic**)(r14 + 1))[r6];
	r12 = (venum*)r13;
	label$3bd692e_25_29:
	++r6;
	r10 = r0->flags;
	r11 = 1;
	if( r12 == NULL ) hl_null_access();
	r15 = HL__ENUM_INDEX__(r12);
	r11 = r11 << r15;
	r10 = r10 | r11;
	r0->flags = r10;
	goto label$3bd692e_25_18;
	label$3bd692e_25_38:
	r16 = h3d_mat_Texture_isDepth(r0);
	if( r16 ) goto label$3bd692e_25_45;
	r18 = (h3d__$Engine)g$_h3d_Engine;
	r17 = r18->CURRENT;
	if( r17 == NULL ) hl_null_access();
	r19 = r17->mem;
	r0->mem = r19;
	label$3bd692e_25_45:
	r6 = 1;
	r10 = 1;
	label$3bd692e_25_47:
	if( r6 >= r1 ) goto label$3bd692e_25_53;
	r15 = 1;
	r11 = r6 << r15;
	r6 = r11;
	goto label$3bd692e_25_47;
	label$3bd692e_25_53:
	if( r10 >= r2 ) goto label$3bd692e_25_59;
	r15 = 1;
	r11 = r10 << r15;
	r10 = r11;
	goto label$3bd692e_25_53;
	label$3bd692e_25_59:
	if( r6 != r1 ) goto label$3bd692e_25_61;
	if( r10 == r2 ) goto label$3bd692e_25_65;
	label$3bd692e_25_61:
	r11 = r0->flags;
	r15 = 16;
	r11 = r11 | r15;
	r0->flags = r11;
	label$3bd692e_25_65:
	r0->width = r1;
	r0->height = r2;
	r11 = r0->flags;
	r15 = 4;
	r11 = r11 & r15;
	r15 = 0;
	if( r11 == r15 ) goto label$3bd692e_25_80;
	r9 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r16 = r9->TRILINEAR_FILTERING_ENABLED;
	if( !r16 ) goto label$3bd692e_25_77;
	r20 = (venum*)g$h3d_mat_MipMap_Linear;
	goto label$3bd692e_25_78;
	label$3bd692e_25_77:
	r20 = (venum*)g$h3d_mat_MipMap_Nearest;
	label$3bd692e_25_78:
	r20 = h3d_mat_Texture_set_mipMap(r0,r20);
	goto label$3bd692e_25_82;
	label$3bd692e_25_80:
	r20 = (venum*)g$h3d_mat_MipMap_None;
	r20 = h3d_mat_Texture_set_mipMap(r0,r20);
	label$3bd692e_25_82:
	r21 = (venum*)g$h3d_mat_Filter_Linear;
	r21 = h3d_mat_Texture_set_filter(r0,r21);
	r9 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r22 = r9->DEFAULT_WRAP;
	r22 = h3d_mat_Texture_set_wrap(r0,r22);
	r11 = r0->bits;
	r15 = 32767;
	r11 = r11 & r15;
	r0->bits = r11;
	r11 = r0->flags;
	r15 = 32;
	r11 = r11 & r15;
	r15 = 0;
	if( r11 != r15 ) goto label$3bd692e_25_102;
	r16 = h3d_mat_Texture_isDepth(r0);
	if( !r16 ) goto label$3bd692e_25_101;
	r11 = r0->width;
	r15 = 0;
	if( r15 >= r11 ) goto label$3bd692e_25_102;
	label$3bd692e_25_101:
	h3d_mat_Texture_alloc(r0);
	label$3bd692e_25_102:
	return;
}
