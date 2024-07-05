﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h2d/TileLayerContent.h>
#include <hxd/impl/Allocator.h>
#include <_std/Math.h>
extern hl_type t$hl_types_ArrayBytes_hl_F32;
void hl_types_ArrayBytes_hl_F32_new(hl__types__ArrayBytes_hl_F32);
void hl_types_ArrayBytes_hl_F32___expand(hl__types__ArrayBytes_hl_F32,int);
hxd__impl__Allocator hxd_impl_Allocator_get(void);
void hxd_impl_Allocator_disposeBuffer(hxd__impl__Allocator,h3d__Buffer);
void h3d_Buffer_dispose(h3d__Buffer);
extern $Math g$_Math;
void h2d_impl_BatchDrawState_clear(h2d__impl__BatchDrawState);
#include <h2d/Tile.h>
#include <h3d/mat/Texture.h>
#include <h2d/impl/_BatchDrawState/StateEntry.h>
int hl_types_ArrayBytes_hl_F32_push(hl__types__ArrayBytes_hl_F32,float);
void h2d_impl_BatchDrawState_setTexture(h2d__impl__BatchDrawState,h3d__mat__Texture);
#include <h3d/Engine.h>
#include <hxd/BufferFormat.h>
#include <hl/types/ArrayObj.h>
hxd__BufferFormat hxd_BufferFormat_get_XY_UV_RGBA(void);
h3d__Buffer hxd_impl_Allocator_ofFloats(hxd__impl__Allocator,hl__types__ArrayBytes_hl_F32,hxd__BufferFormat,int*);
h3d__Buffer h3d_Buffer_ofFloats(hl__types__ArrayBytes_hl_F32,hxd__BufferFormat,hl__types__ArrayObj);
void h3d_prim_Primitive_dispose(h3d__prim__Primitive);
void h3d_prim_Primitive_new(h3d__prim__Primitive);
extern hl_type t$h2d_impl_BatchDrawState;
void h2d_impl_BatchDrawState_new(h2d__impl__BatchDrawState);

void h2d_TileLayerContent_clear(h2d__TileLayerContent r0) {
	h2d__impl__BatchDrawState r12;
	hl__types__ArrayBytes_hl_F32 r3;
	hxd__impl__Allocator r10;
	$Math r11;
	float r7;
	h3d__Buffer r9;
	double r6;
	vbyte *r8;
	int r1, r4, r5;
	r1 = 0;
	r3 = (hl__types__ArrayBytes_hl_F32)hl_alloc_obj(&t$hl_types_ArrayBytes_hl_F32);
	hl_types_ArrayBytes_hl_F32_new(r3);
	r5 = 0;
	if( r5 >= r1 ) goto label$bbfd967_1_18;
	r5 = r3->length;
	if( r5 >= r1 ) goto label$bbfd967_1_18;
	r5 = 1;
	r4 = r1 - r5;
	r6 = 0.;
	r7 = (float)r6;
	r5 = r3->length;
	if( ((unsigned)r4) < ((unsigned)r5) ) goto label$bbfd967_1_14;
	hl_types_ArrayBytes_hl_F32___expand(r3,r4);
	label$bbfd967_1_14:
	r8 = r3->bytes;
	r5 = 2;
	r5 = r4 << r5;
	*(float*)(r8 + r5) = r7;
	label$bbfd967_1_18:
	r0->tmp = r3;
	r9 = r0->buffer;
	if( !r9 ) goto label$bbfd967_1_36;
	r9 = r0->buffer;
	if( r9 == NULL ) hl_null_access();
	r4 = r9->vertices;
	r5 = 8;
	r4 = r4 * r5;
	r5 = r0->useAllocatorLimit;
	if( r4 >= r5 ) goto label$bbfd967_1_33;
	r10 = hxd_impl_Allocator_get();
	if( r10 == NULL ) hl_null_access();
	r9 = r0->buffer;
	hxd_impl_Allocator_disposeBuffer(r10,r9);
	goto label$bbfd967_1_36;
	label$bbfd967_1_33:
	r9 = r0->buffer;
	if( r9 == NULL ) hl_null_access();
	h3d_Buffer_dispose(r9);
	label$bbfd967_1_36:
	r9 = NULL;
	r0->buffer = r9;
	r11 = ($Math)g$_Math;
	r6 = r11->POSITIVE_INFINITY;
	r0->xMin = r6;
	r11 = ($Math)g$_Math;
	r6 = r11->POSITIVE_INFINITY;
	r0->yMin = r6;
	r11 = ($Math)g$_Math;
	r6 = r11->NEGATIVE_INFINITY;
	r0->xMax = r6;
	r11 = ($Math)g$_Math;
	r6 = r11->NEGATIVE_INFINITY;
	r0->yMax = r6;
	r12 = r0->state;
	if( r12 == NULL ) hl_null_access();
	h2d_impl_BatchDrawState_clear(r12);
	return;
}

int h2d_TileLayerContent_triCount(h2d__TileLayerContent r0) {
	hl__types__ArrayBytes_hl_F32 r3;
	h3d__Buffer r1;
	int r2, r4;
	r1 = r0->buffer;
	if( r1 ) goto label$bbfd967_2_8;
	r3 = r0->tmp;
	if( r3 == NULL ) hl_null_access();
	r2 = r3->length;
	r4 = 4;
	r2 = r2 >> r4;
	return r2;
	label$bbfd967_2_8:
	r1 = r0->buffer;
	if( r1 == NULL ) hl_null_access();
	r2 = r1->vertices;
	r4 = 1;
	r2 = r2 >> r4;
	return r2;
}

void h2d_TileLayerContent_add(h2d__TileLayerContent r0,double r1,double r2,double r3,double r4,double r5,double r6,h2d__Tile r7) {
	h2d__impl__BatchDrawState r18;
	hl__types__ArrayBytes_hl_F32 r13;
	float r14;
	double r8, r9, r11, r15, r16, r17;
	h2d__impl___BatchDrawState__StateEntry r20;
	h3d__mat__Texture r19;
	int r12, r21;
	if( r7 == NULL ) hl_null_access();
	r9 = r7->dx;
	r8 = r1 + r9;
	r11 = r7->dy;
	r9 = r2 + r11;
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r8;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r9;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r11 = r7->u;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r11 = r7->v;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r3;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r4;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r5;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r6;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r15 = r7->width;
	r11 = r8 + r15;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r9;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r11 = r7->u2;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r11 = r7->v;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r3;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r4;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r5;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r6;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r8;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r15 = r7->height;
	r11 = r9 + r15;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r11 = r7->u;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r11 = r7->v2;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r3;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r4;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r5;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r6;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r15 = r7->width;
	r11 = r8 + r15;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r15 = r7->height;
	r11 = r9 + r15;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r11 = r7->u2;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r11 = r7->v2;
	r14 = (float)r11;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r3;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r4;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r5;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r13 = r0->tmp;
	if( r13 == NULL ) hl_null_access();
	r14 = (float)r6;
	r12 = hl_types_ArrayBytes_hl_F32_push(r13,r14);
	r15 = r7->dx;
	r11 = r1 + r15;
	r16 = r7->dy;
	r15 = r2 + r16;
	r17 = r0->xMin;
	if( !(r11 < r17) ) goto label$bbfd967_3_156;
	r0->xMin = r11;
	label$bbfd967_3_156:
	r17 = r0->yMin;
	if( !(r15 < r17) ) goto label$bbfd967_3_159;
	r0->yMin = r15;
	label$bbfd967_3_159:
	r17 = r7->width;
	r16 = r11 + r17;
	r11 = r16;
	r17 = r7->height;
	r16 = r15 + r17;
	r15 = r16;
	r17 = r0->xMax;
	if( !(r17 < r11) ) goto label$bbfd967_3_168;
	r0->xMax = r11;
	label$bbfd967_3_168:
	r17 = r0->yMax;
	if( !(r17 < r15) ) goto label$bbfd967_3_171;
	r0->yMax = r15;
	label$bbfd967_3_171:
	if( !r7 ) goto label$bbfd967_3_176;
	r18 = r0->state;
	if( r18 == NULL ) hl_null_access();
	r19 = r7->innerTex;
	h2d_impl_BatchDrawState_setTexture(r18,r19);
	label$bbfd967_3_176:
	r18 = r0->state;
	if( r18 == NULL ) hl_null_access();
	r20 = r18->tail;
	if( r20 == NULL ) hl_null_access();
	r12 = r20->count;
	r21 = 4;
	r12 = r12 + r21;
	r20->count = r12;
	r12 = r18->totalCount;
	r21 = 4;
	r12 = r12 + r21;
	r18->totalCount = r12;
	return;
}

void h2d_TileLayerContent_alloc(h2d__TileLayerContent r0,h3d__Engine r1) {
	hl__types__ArrayObj r10;
	hl__types__ArrayBytes_hl_F32 r3;
	hxd__impl__Allocator r7;
	hxd__BufferFormat r8;
	h3d__Buffer r6;
	int *r9;
	int r4, r5;
	r3 = r0->tmp;
	if( r3 ) goto label$bbfd967_4_3;
	h2d_TileLayerContent_clear(r0);
	label$bbfd967_4_3:
	r3 = r0->tmp;
	if( r3 == NULL ) hl_null_access();
	r4 = r3->length;
	r5 = 0;
	if( r5 >= r4 ) goto label$bbfd967_4_25;
	r3 = r0->tmp;
	if( r3 == NULL ) hl_null_access();
	r4 = r3->length;
	r5 = r0->useAllocatorLimit;
	if( r4 >= r5 ) goto label$bbfd967_4_20;
	r7 = hxd_impl_Allocator_get();
	if( r7 == NULL ) hl_null_access();
	r3 = r0->tmp;
	r8 = hxd_BufferFormat_get_XY_UV_RGBA();
	r9 = NULL;
	r6 = hxd_impl_Allocator_ofFloats(r7,r3,r8,r9);
	goto label$bbfd967_4_24;
	label$bbfd967_4_20:
	r3 = r0->tmp;
	r8 = hxd_BufferFormat_get_XY_UV_RGBA();
	r10 = NULL;
	r6 = h3d_Buffer_ofFloats(r3,r8,r10);
	label$bbfd967_4_24:
	r0->buffer = r6;
	label$bbfd967_4_25:
	return;
}

void h2d_TileLayerContent_dispose(h2d__TileLayerContent r0) {
	hxd__impl__Allocator r5;
	h3d__Buffer r2;
	int r3, r4;
	r2 = r0->buffer;
	if( !r2 ) goto label$bbfd967_5_19;
	r2 = r0->buffer;
	if( r2 == NULL ) hl_null_access();
	r3 = r2->vertices;
	r4 = 8;
	r3 = r3 * r4;
	r4 = r0->useAllocatorLimit;
	if( r3 >= r4 ) goto label$bbfd967_5_14;
	r5 = hxd_impl_Allocator_get();
	if( r5 == NULL ) hl_null_access();
	r2 = r0->buffer;
	hxd_impl_Allocator_disposeBuffer(r5,r2);
	goto label$bbfd967_5_17;
	label$bbfd967_5_14:
	r2 = r0->buffer;
	if( r2 == NULL ) hl_null_access();
	h3d_Buffer_dispose(r2);
	label$bbfd967_5_17:
	r2 = NULL;
	r0->buffer = r2;
	label$bbfd967_5_19:
	h3d_prim_Primitive_dispose(((h3d__prim__Primitive)r0));
	return;
}

void h2d_TileLayerContent_new(h2d__TileLayerContent r0) {
	h2d__impl__BatchDrawState r3;
	int r1;
	r1 = 1024;
	r0->useAllocatorLimit = r1;
	h3d_prim_Primitive_new(((h3d__prim__Primitive)r0));
	r3 = (h2d__impl__BatchDrawState)hl_alloc_obj(&t$h2d_impl_BatchDrawState);
	h2d_impl_BatchDrawState_new(r3);
	r0->state = r3;
	h2d_TileLayerContent_clear(r0);
	return;
}
