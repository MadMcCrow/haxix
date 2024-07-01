﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/prim/Instanced.h>
void h3d_prim_Primitive_new(h3d__prim__Primitive);
extern hl_type t$h3d_col_Bounds;
void h3d_col_Bounds_new(h3d__col__Bounds);
void h3d_prim_Primitive_incref(h3d__prim__Primitive);
void h3d_prim_Primitive_decref(h3d__prim__Primitive);
#include <h3d/Engine.h>
#include <hl/types/ArrayObj.h>
#include <h3d/impl/Driver.h>
#include <hxd/MultiFormat.h>
#include <h3d/impl/MemoryManager.h>
void h3d_Engine_doFlushTarget(h3d__Engine);
int h3d_prim_Primitive_triCount(h3d__prim__Primitive);
h3d__Indexes h3d_impl_MemoryManager_getTriIndexes(h3d__impl__MemoryManager,int);
void h3d_Engine_renderInstanced(h3d__Engine,h3d__Indexes,h3d__impl__InstanceBuffer);

void h3d_prim_Instanced_new(h3d__prim__Instanced r0) {
	h3d__col__Bounds r2;
	double r3, r4;
	h3d_prim_Primitive_new(((h3d__prim__Primitive)r0));
	r2 = (h3d__col__Bounds)hl_alloc_obj(&t$h3d_col_Bounds);
	h3d_col_Bounds_new(r2);
	r0->bounds = r2;
	r2 = r0->bounds;
	r3 = 0.;
	if( r2 == NULL ) hl_null_access();
	r4 = r2->xMin;
	if( !(r3 < r4) ) goto label$49a30dd_1_11;
	r3 = 0.;
	r2->xMin = r3;
	label$49a30dd_1_11:
	r3 = 0.;
	r4 = r2->xMax;
	if( !(r4 < r3) ) goto label$49a30dd_1_16;
	r3 = 0.;
	r2->xMax = r3;
	label$49a30dd_1_16:
	r3 = 0.;
	r4 = r2->yMin;
	if( !(r3 < r4) ) goto label$49a30dd_1_21;
	r3 = 0.;
	r2->yMin = r3;
	label$49a30dd_1_21:
	r3 = 0.;
	r4 = r2->yMax;
	if( !(r4 < r3) ) goto label$49a30dd_1_26;
	r3 = 0.;
	r2->yMax = r3;
	label$49a30dd_1_26:
	r3 = 0.;
	r4 = r2->zMin;
	if( !(r3 < r4) ) goto label$49a30dd_1_31;
	r3 = 0.;
	r2->zMin = r3;
	label$49a30dd_1_31:
	r3 = 0.;
	r4 = r2->zMax;
	if( !(r4 < r3) ) goto label$49a30dd_1_36;
	r3 = 0.;
	r2->zMax = r3;
	label$49a30dd_1_36:
	r2 = (h3d__col__Bounds)hl_alloc_obj(&t$h3d_col_Bounds);
	h3d_col_Bounds_new(r2);
	r0->tmpBounds = r2;
	return;
}

void h3d_prim_Instanced_dispose(h3d__prim__Instanced r0) {
	return;
}

void h3d_prim_Instanced_incref(h3d__prim__Instanced r0) {
	h3d__prim__MeshPrimitive r4;
	int r2, r3;
	r2 = r0->refCount;
	r3 = 0;
	if( r2 != r3 ) goto label$49a30dd_3_8;
	r4 = r0->primitive;
	if( !r4 ) goto label$49a30dd_3_8;
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	h3d_prim_Primitive_incref(((h3d__prim__Primitive)r4));
	label$49a30dd_3_8:
	h3d_prim_Primitive_incref(((h3d__prim__Primitive)r0));
	return;
}

void h3d_prim_Instanced_decref(h3d__prim__Instanced r0) {
	h3d__prim__MeshPrimitive r4;
	int r2, r3;
	h3d_prim_Primitive_decref(((h3d__prim__Primitive)r0));
	r2 = r0->refCount;
	r3 = 0;
	if( r2 != r3 ) goto label$49a30dd_4_9;
	r4 = r0->primitive;
	if( !r4 ) goto label$49a30dd_4_9;
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	h3d_prim_Primitive_decref(((h3d__prim__Primitive)r4));
	label$49a30dd_4_9:
	return;
}

h3d__col__Bounds h3d_prim_Instanced_getBounds(h3d__prim__Instanced r0) {
	h3d__col__Bounds r1;
	r1 = r0->bounds;
	return r1;
}

void h3d_prim_Instanced_render(h3d__prim__Instanced r0,h3d__Engine r1) {
	hl__types__ArrayObj r8;
	hxd__MultiFormat r10;
	bool r7;
	h3d__impl__InstanceBuffer r15;
	h3d__prim__MeshPrimitive r4;
	h3d__impl__MemoryManager r12;
	h3d__Buffer r6;
	h3d__impl__Driver r9;
	vdynamic *r5;
	int r13, r14;
	h3d__Indexes r3, r11;
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	r3 = r4->indexes;
	if( !r3 ) goto label$49a30dd_6_10;
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	r6 = r4->buffer;
	if( r6 == NULL ) hl_null_access();
	r5 = r6->vbuf;
	if( r5 ) goto label$49a30dd_6_13;
	label$49a30dd_6_10:
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	((void (*)(h3d__prim__MeshPrimitive,h3d__Engine))r4->$type->vobj_proto[4])(r4,r1);
	label$49a30dd_6_13:
	if( r1 == NULL ) hl_null_access();
	r7 = r1->needFlushTarget;
	if( !r7 ) goto label$49a30dd_6_17;
	h3d_Engine_doFlushTarget(r1);
	label$49a30dd_6_17:
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	r8 = r4->buffers;
	if( r8 ) goto label$49a30dd_6_28;
	r9 = r1->driver;
	if( r9 == NULL ) hl_null_access();
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	r6 = r4->buffer;
	((void (*)(h3d__impl__Driver,h3d__Buffer))r9->$type->vobj_proto[12])(r9,r6);
	goto label$49a30dd_6_37;
	label$49a30dd_6_28:
	r9 = r1->driver;
	if( r9 == NULL ) hl_null_access();
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	r10 = r4->formats;
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	r8 = r4->buffers;
	((void (*)(h3d__impl__Driver,hxd__MultiFormat,hl__types__ArrayObj))r9->$type->vobj_proto[13])(r9,r10,r8);
	label$49a30dd_6_37:
	r4 = r0->primitive;
	if( r4 == NULL ) hl_null_access();
	r3 = r4->indexes;
	if( r3 ) goto label$49a30dd_6_48;
	r12 = r1->mem;
	if( r12 == NULL ) hl_null_access();
	r13 = h3d_prim_Primitive_triCount(((h3d__prim__Primitive)r0));
	r14 = 3;
	r13 = r13 * r14;
	r11 = h3d_impl_MemoryManager_getTriIndexes(r12,r13);
	r3 = r11;
	label$49a30dd_6_48:
	r15 = r0->commands;
	h3d_Engine_renderInstanced(r1,r3,r15);
	return;
}

