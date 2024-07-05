﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/prim/Plane2D.h>
void h3d_prim_Primitive_new(h3d__prim__Primitive);
#include <h3d/Engine.h>
#include <hl/types/ArrayBytes_hl_F32.h>
#include <hxd/BufferFormat.h>
#include <hl/types/ArrayObj.h>
extern hl_type t$hl_types_ArrayBytes_hl_F32;
void hl_types_ArrayBytes_hl_F32_new(hl__types__ArrayBytes_hl_F32);
void hl_types_ArrayBytes_hl_F32___expand(hl__types__ArrayBytes_hl_F32,int);
int hl_types_ArrayBytes_hl_F32_push(hl__types__ArrayBytes_hl_F32,float);
hxd__BufferFormat hxd_BufferFormat_get_XY_UV(void);
h3d__Buffer h3d_Buffer_ofFloats(hl__types__ArrayBytes_hl_F32,hxd__BufferFormat,hl__types__ArrayObj);
#include <h3d/impl/MemoryManager.h>
h3d__Indexes h3d_impl_MemoryManager_getQuadIndexes(h3d__impl__MemoryManager,int);
void h3d_Engine_renderBuffer(h3d__Engine,h3d__Buffer,h3d__Indexes,int,int*,int*);
#include <haxe/ds/ObjectMap.h>
extern h3d__$Engine g$_h3d_Engine;
extern h3d__prim__$Plane2D g$_h3d_prim_Plane2D;
vdynamic* haxe_ds_ObjectMap_get(haxe__ds__ObjectMap,vdynamic*);
extern hl_type t$h3d_prim_Plane2D;
void haxe_ds_ObjectMap_set(haxe__ds__ObjectMap,vdynamic*,vdynamic*);

void h3d_prim_Plane2D_new(h3d__prim__Plane2D r0) {
	h3d_prim_Primitive_new(((h3d__prim__Primitive)r0));
	return;
}

int h3d_prim_Plane2D_triCount(h3d__prim__Plane2D r0) {
	int r1;
	r1 = 2;
	return r1;
}

void h3d_prim_Plane2D_alloc(h3d__prim__Plane2D r0,h3d__Engine r1) {
	hl__types__ArrayObj r12;
	hl__types__ArrayBytes_hl_F32 r4;
	hxd__BufferFormat r11;
	float r8;
	h3d__Buffer r10;
	double r7;
	vbyte *r9;
	int r2, r5, r6;
	r2 = 0;
	r4 = (hl__types__ArrayBytes_hl_F32)hl_alloc_obj(&t$hl_types_ArrayBytes_hl_F32);
	hl_types_ArrayBytes_hl_F32_new(r4);
	r6 = 0;
	if( r6 >= r2 ) goto label$18e592e_3_18;
	r6 = r4->length;
	if( r6 >= r2 ) goto label$18e592e_3_18;
	r6 = 1;
	r5 = r2 - r6;
	r7 = 0.;
	r8 = (float)r7;
	r6 = r4->length;
	if( ((unsigned)r5) < ((unsigned)r6) ) goto label$18e592e_3_14;
	hl_types_ArrayBytes_hl_F32___expand(r4,r5);
	label$18e592e_3_14:
	r9 = r4->bytes;
	r6 = 2;
	r6 = r5 << r6;
	*(float*)(r9 + r6) = r8;
	label$18e592e_3_18:
	r5 = -1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = -1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 0;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = -1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 0;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 0;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = -1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 1;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r5 = 0;
	r8 = (float)r5;
	r5 = hl_types_ArrayBytes_hl_F32_push(r4,r8);
	r11 = hxd_BufferFormat_get_XY_UV();
	r12 = NULL;
	r10 = h3d_Buffer_ofFloats(r4,r11,r12);
	r0->buffer = r10;
	return;
}

void h3d_prim_Plane2D_render(h3d__prim__Plane2D r0,h3d__Engine r1) {
	h3d__impl__MemoryManager r6;
	h3d__Buffer r3;
	int *r9, *r11;
	vdynamic *r4;
	int r7, r8, r10;
	h3d__Indexes r5;
	r3 = r0->buffer;
	if( !r3 ) goto label$18e592e_4_6;
	r3 = r0->buffer;
	if( r3 == NULL ) hl_null_access();
	r4 = r3->vbuf;
	if( r4 ) goto label$18e592e_4_7;
	label$18e592e_4_6:
	h3d_prim_Plane2D_alloc(r0,r1);
	label$18e592e_4_7:
	r3 = r0->buffer;
	if( r1 == NULL ) hl_null_access();
	r6 = r1->mem;
	if( r6 == NULL ) hl_null_access();
	if( r3 == NULL ) hl_null_access();
	r7 = r3->vertices;
	r5 = h3d_impl_MemoryManager_getQuadIndexes(r6,r7);
	r7 = 2;
	r8 = 0;
	r9 = &r8;
	r10 = -1;
	r11 = &r10;
	h3d_Engine_renderBuffer(r1,r3,r5,r7,r9,r11);
	return;
}

vdynamic* h3d_prim_Plane2D_get() {
	haxe__ds__ObjectMap r4;
	h3d__prim__$Plane2D r5;
	h3d__prim__Plane2D r6;
	h3d__Engine r0;
	h3d__$Engine r1;
	vdynamic *r3;
	r1 = (h3d__$Engine)g$_h3d_Engine;
	r0 = r1->CURRENT;
	if( r0 == NULL ) hl_null_access();
	r4 = r0->resCache;
	if( r4 == NULL ) hl_null_access();
	r5 = (h3d__prim__$Plane2D)g$_h3d_prim_Plane2D;
	r3 = haxe_ds_ObjectMap_get(r4,((vdynamic*)r5));
	if( r3 ) goto label$18e592e_5_15;
	r6 = (h3d__prim__Plane2D)hl_alloc_obj(&t$h3d_prim_Plane2D);
	h3d_prim_Plane2D_new(r6);
	r3 = ((vdynamic*)r6);
	r4 = r0->resCache;
	if( r4 == NULL ) hl_null_access();
	r5 = (h3d__prim__$Plane2D)g$_h3d_prim_Plane2D;
	haxe_ds_ObjectMap_set(r4,((vdynamic*)r5),((vdynamic*)r6));
	label$18e592e_5_15:
	return r3;
}
