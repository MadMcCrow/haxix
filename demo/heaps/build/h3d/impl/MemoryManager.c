﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/impl/MemoryManager.h>
#include <h3d/mat/Texture.h>
extern hl_type t$h3d_mat_Texture;
extern hl_type t$_dyn;
extern hl_type t$hl_types_ArrayObj;
void hl_types_ArrayObj_new(hl__types__ArrayObj);
void h3d_impl_MemoryManager_initIndexes(h3d__impl__MemoryManager);
#include <hl/types/ArrayBytes_hl_UI16.h>
extern hl_type t$hl_types_ArrayBytes_hl_UI16;
void hl_types_ArrayBytes_hl_UI16_new(hl__types__ArrayBytes_hl_UI16);
void hl_types_ArrayBytes_hl_UI16___expand(hl__types__ArrayBytes_hl_UI16,int);
int hl_types_ArrayBytes_hl_UI16_push(hl__types__ArrayBytes_hl_UI16,unsigned short);
h3d__Indexes h3d_Indexes_alloc(hl__types__ArrayBytes_hl_UI16,int*,int*);
#include <haxe/io/Bytes.h>
haxe__io__Bytes haxe_io_Bytes_alloc(int);
void haxe_io_Bytes_setInt32(haxe__io__Bytes,int,int);
void h3d_Indexes_dispose(h3d__Indexes);
extern hl_type t$h3d_Indexes;
void h3d_Indexes_new(h3d__Indexes,int,bool*);
void h3d_Indexes_uploadBytes(h3d__Indexes,haxe__io__Bytes,int,int);
#include <h3d/Buffer.h>
#include <hxd/BufferFormat.h>
extern String s$Memory_full_;
#include <hl/natives.h>
String String___alloc__(vbyte*,int);
String String___add__(String,String);
extern String s$_KB_;
extern String s$_buffers_;
int hl_types_ArrayObj_push(hl__types__ArrayObj,vdynamic*);
bool hl_types_ArrayObj_remove(hl__types__ArrayObj,vdynamic*);
#include <hxd/PixelFormat.h>
int hxd_Pixels_calcDataSize(int,int,venum*);
int h3d_mat_Texture_get_mipLevels(h3d__mat__Texture);
#include <hxd/Timer.h>
int h3d_impl_MemoryManager_sortByLRU(h3d__impl__MemoryManager,h3d__mat__Texture,h3d__mat__Texture);
extern hl_type t$fun_6a85200;
extern hl_type t$fun_5f1efa7;
void hl_types_ArrayObj_sort(hl__types__ArrayObj,vclosure*);
bool h3d_mat_Texture_isDepth(h3d__mat__Texture);
extern hxd__$Timer g$_hxd_Timer;
extern h3d__mat__$Texture g$_h3d_mat_Texture;
void h3d_mat_Texture_dispose(h3d__mat__Texture);
extern String s$Maximum_texture_memory_reached;
void h3d_impl_MemoryManager_dispose(h3d__impl__MemoryManager);
hl__types__ArrayObj hl_types_ArrayObj_copy(hl__types__ArrayObj);
void h3d_Buffer_dispose(h3d__Buffer);
extern hl_type t$h3d_Buffer;
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern hl_type t$fun_4bffad7;

int h3d_impl_MemoryManager_cleanTextures__$1(vclosure* r0,vdynamic* r1,vdynamic* r2) {
	int r5;
	h3d__mat__Texture r3, r4;
	r3 = (h3d__mat__Texture)hl_dyn_castp(&r1,&t$_dyn,&t$h3d_mat_Texture);
	r4 = (h3d__mat__Texture)hl_dyn_castp(&r2,&t$_dyn,&t$h3d_mat_Texture);
	r5 = r0->hasValue ? ((int (*)(vdynamic*,h3d__mat__Texture,h3d__mat__Texture))r0->fun)((vdynamic*)r0->value,r3,r4) : ((int (*)(h3d__mat__Texture,h3d__mat__Texture))r0->fun)(r3,r4);
	return r5;
}

void h3d_impl_MemoryManager_init(h3d__impl__MemoryManager r0) {
	hl__types__ArrayObj r1;
	r1 = (hl__types__ArrayObj)hl_alloc_obj(&t$hl_types_ArrayObj);
	hl_types_ArrayObj_new(r1);
	r0->indexes = r1;
	r1 = (hl__types__ArrayObj)hl_alloc_obj(&t$hl_types_ArrayObj);
	hl_types_ArrayObj_new(r1);
	r0->textures = r1;
	r1 = (hl__types__ArrayObj)hl_alloc_obj(&t$hl_types_ArrayObj);
	hl_types_ArrayObj_new(r1);
	r0->buffers = r1;
	r1 = (hl__types__ArrayObj)hl_alloc_obj(&t$hl_types_ArrayObj);
	hl_types_ArrayObj_new(r1);
	r0->depths = r1;
	h3d_impl_MemoryManager_initIndexes(r0);
	return;
}

void h3d_impl_MemoryManager_initIndexes(h3d__impl__MemoryManager r0) {
	hl__types__ArrayBytes_hl_UI16 r3, r6, r10, r14;
	unsigned short r7;
	int *r12, *r13;
	h3d__Indexes r11;
	vbyte *r9;
	int r1, r4, r5, r8, r15, r16, r17, r18;
	r1 = 0;
	r3 = (hl__types__ArrayBytes_hl_UI16)hl_alloc_obj(&t$hl_types_ArrayBytes_hl_UI16);
	hl_types_ArrayBytes_hl_UI16_new(r3);
	r5 = 0;
	if( r5 >= r1 ) goto label$88467e8_3_19;
	r5 = r3->length;
	if( r5 >= r1 ) goto label$88467e8_3_19;
	r5 = 1;
	r4 = r1 - r5;
	r5 = 0;
	r7 = (int)r5;
	r5 = (int)r7;
	r8 = r3->length;
	if( ((unsigned)r4) < ((unsigned)r8) ) goto label$88467e8_3_15;
	hl_types_ArrayBytes_hl_UI16___expand(r3,r4);
	label$88467e8_3_15:
	r9 = r3->bytes;
	r8 = 1;
	r8 = r4 << r8;
	*(unsigned short*)(r9 + r8) = (unsigned short)r5;
	label$88467e8_3_19:
	r6 = r3;
	r4 = 0;
	label$88467e8_3_21:
	r8 = 65532;
	if( r4 >= r8 ) goto label$88467e8_3_30;
	r5 = r4;
	++r4;
	if( r6 == NULL ) hl_null_access();
	r7 = (int)r5;
	r8 = hl_types_ArrayBytes_hl_UI16_push(r6,r7);
	goto label$88467e8_3_21;
	label$88467e8_3_30:
	r12 = NULL;
	r13 = NULL;
	r11 = h3d_Indexes_alloc(r6,r12,r13);
	r0->triIndexes16 = r11;
	r4 = 0;
	r10 = (hl__types__ArrayBytes_hl_UI16)hl_alloc_obj(&t$hl_types_ArrayBytes_hl_UI16);
	hl_types_ArrayBytes_hl_UI16_new(r10);
	r8 = 0;
	if( r8 >= r4 ) goto label$88467e8_3_53;
	r8 = r10->length;
	if( r8 >= r4 ) goto label$88467e8_3_53;
	r8 = 1;
	r5 = r4 - r8;
	r8 = 0;
	r7 = (int)r8;
	r8 = (int)r7;
	r15 = r10->length;
	if( ((unsigned)r5) < ((unsigned)r15) ) goto label$88467e8_3_49;
	hl_types_ArrayBytes_hl_UI16___expand(r10,r5);
	label$88467e8_3_49:
	r9 = r10->bytes;
	r15 = 1;
	r15 = r5 << r15;
	*(unsigned short*)(r9 + r15) = (unsigned short)r8;
	label$88467e8_3_53:
	r14 = r10;
	r5 = 0;
	r8 = 0;
	label$88467e8_3_56:
	r16 = 10922;
	if( r8 >= r16 ) goto label$88467e8_3_87;
	r15 = r8;
	++r8;
	r17 = 2;
	r16 = r15 << r17;
	if( r14 == NULL ) hl_null_access();
	r7 = (int)r16;
	r17 = hl_types_ArrayBytes_hl_UI16_push(r14,r7);
	r18 = 1;
	r17 = r16 + r18;
	r7 = (int)r17;
	r17 = hl_types_ArrayBytes_hl_UI16_push(r14,r7);
	r18 = 2;
	r17 = r16 + r18;
	r7 = (int)r17;
	r17 = hl_types_ArrayBytes_hl_UI16_push(r14,r7);
	r18 = 2;
	r17 = r16 + r18;
	r7 = (int)r17;
	r17 = hl_types_ArrayBytes_hl_UI16_push(r14,r7);
	r18 = 1;
	r17 = r16 + r18;
	r7 = (int)r17;
	r17 = hl_types_ArrayBytes_hl_UI16_push(r14,r7);
	r18 = 3;
	r17 = r16 + r18;
	r7 = (int)r17;
	r17 = hl_types_ArrayBytes_hl_UI16_push(r14,r7);
	goto label$88467e8_3_56;
	label$88467e8_3_87:
	if( r14 == NULL ) hl_null_access();
	r8 = 65532;
	r7 = (int)r8;
	r8 = hl_types_ArrayBytes_hl_UI16_push(r14,r7);
	r12 = NULL;
	r13 = NULL;
	r11 = h3d_Indexes_alloc(r14,r12,r13);
	r0->quadIndexes16 = r11;
	return;
}

void h3d_impl_MemoryManager_garbage(h3d__impl__MemoryManager r0) {
	return;
}

h3d__Indexes h3d_impl_MemoryManager_getTriIndexes(h3d__impl__MemoryManager r0,int r1) {
	bool *r12;
	bool r11;
	haxe__io__Bytes r7;
	h3d__Indexes r5;
	int r3, r4, r6, r8, r9, r10;
	r4 = 65532;
	if( r4 < r1 ) goto label$88467e8_5_4;
	r5 = r0->triIndexes16;
	return r5;
	label$88467e8_5_4:
	r5 = r0->triIndexes32;
	if( !r5 ) goto label$88467e8_5_10;
	r5 = r0->triIndexes32;
	if( r5 == NULL ) hl_null_access();
	r3 = r5->count;
	if( r3 >= r1 ) goto label$88467e8_5_45;
	label$88467e8_5_10:
	r3 = 131072;
	label$88467e8_5_11:
	if( r3 >= r1 ) goto label$88467e8_5_17;
	r6 = 1;
	r4 = r3 << r6;
	r3 = r4;
	goto label$88467e8_5_11;
	label$88467e8_5_17:
	r6 = 2;
	r4 = r3 << r6;
	r7 = haxe_io_Bytes_alloc(r4);
	r4 = 0;
	r6 = r3;
	label$88467e8_5_22:
	if( r4 >= r6 ) goto label$88467e8_5_31;
	r8 = r4;
	++r4;
	if( r7 == NULL ) hl_null_access();
	r10 = 2;
	r9 = r8 << r10;
	haxe_io_Bytes_setInt32(r7,r9,r8);
	goto label$88467e8_5_22;
	label$88467e8_5_31:
	r5 = r0->triIndexes32;
	if( !r5 ) goto label$88467e8_5_36;
	r5 = r0->triIndexes32;
	if( r5 == NULL ) hl_null_access();
	h3d_Indexes_dispose(r5);
	label$88467e8_5_36:
	r5 = (h3d__Indexes)hl_alloc_obj(&t$h3d_Indexes);
	r11 = true;
	r12 = &r11;
	h3d_Indexes_new(r5,r3,r12);
	r0->triIndexes32 = r5;
	r5 = r0->triIndexes32;
	if( r5 == NULL ) hl_null_access();
	r4 = 0;
	h3d_Indexes_uploadBytes(r5,r7,r4,r3);
	label$88467e8_5_45:
	r5 = r0->triIndexes32;
	return r5;
}

h3d__Indexes h3d_impl_MemoryManager_getQuadIndexes(h3d__impl__MemoryManager r0,int r1) {
	bool *r16;
	bool r15;
	haxe__io__Bytes r8;
	h3d__Indexes r6;
	int r2, r3, r5, r7, r9, r10, r11, r12, r13, r14;
	r3 = 3;
	r2 = r1 + r3;
	r3 = 2;
	r2 = r2 >> r3;
	r3 = 6;
	r2 = r2 * r3;
	r5 = 65532;
	if( r5 < r2 ) goto label$88467e8_6_10;
	r6 = r0->quadIndexes16;
	return r6;
	label$88467e8_6_10:
	r6 = r0->quadIndexes32;
	if( !r6 ) goto label$88467e8_6_16;
	r6 = r0->quadIndexes32;
	if( r6 == NULL ) hl_null_access();
	r3 = r6->count;
	if( r3 >= r1 ) goto label$88467e8_6_92;
	label$88467e8_6_16:
	r3 = 131072;
	label$88467e8_6_17:
	if( r3 >= r2 ) goto label$88467e8_6_23;
	r7 = 1;
	r5 = r3 << r7;
	r3 = r5;
	goto label$88467e8_6_17;
	label$88467e8_6_23:
	r7 = 2;
	r5 = r3 << r7;
	r8 = haxe_io_Bytes_alloc(r5);
	r5 = 0;
	r7 = 0;
	r10 = 6;
	r9 = r10 == 0 ? 0 : r3 / r10;
	label$88467e8_6_30:
	if( r7 >= r9 ) goto label$88467e8_6_78;
	r10 = r7;
	++r7;
	r12 = 2;
	r11 = r10 << r12;
	if( r8 == NULL ) hl_null_access();
	r12 = r5;
	++r5;
	r13 = 2;
	r12 = r12 << r13;
	haxe_io_Bytes_setInt32(r8,r12,r11);
	r12 = r5;
	++r5;
	r13 = 2;
	r12 = r12 << r13;
	r14 = 1;
	r13 = r11 + r14;
	haxe_io_Bytes_setInt32(r8,r12,r13);
	r12 = r5;
	++r5;
	r13 = 2;
	r12 = r12 << r13;
	r14 = 2;
	r13 = r11 + r14;
	haxe_io_Bytes_setInt32(r8,r12,r13);
	r12 = r5;
	++r5;
	r13 = 2;
	r12 = r12 << r13;
	r14 = 2;
	r13 = r11 + r14;
	haxe_io_Bytes_setInt32(r8,r12,r13);
	r12 = r5;
	++r5;
	r13 = 2;
	r12 = r12 << r13;
	r14 = 1;
	r13 = r11 + r14;
	haxe_io_Bytes_setInt32(r8,r12,r13);
	r12 = r5;
	++r5;
	r13 = 2;
	r12 = r12 << r13;
	r14 = 3;
	r13 = r11 + r14;
	haxe_io_Bytes_setInt32(r8,r12,r13);
	goto label$88467e8_6_30;
	label$88467e8_6_78:
	r6 = r0->quadIndexes32;
	if( !r6 ) goto label$88467e8_6_83;
	r6 = r0->quadIndexes32;
	if( r6 == NULL ) hl_null_access();
	h3d_Indexes_dispose(r6);
	label$88467e8_6_83:
	r6 = (h3d__Indexes)hl_alloc_obj(&t$h3d_Indexes);
	r15 = true;
	r16 = &r15;
	h3d_Indexes_new(r6,r3,r16);
	r0->quadIndexes32 = r6;
	r6 = r0->quadIndexes32;
	if( r6 == NULL ) hl_null_access();
	r7 = 0;
	h3d_Indexes_uploadBytes(r6,r8,r7,r3);
	label$88467e8_6_92:
	r6 = r0->quadIndexes32;
	return r6;
}

void h3d_impl_MemoryManager_allocBuffer(h3d__impl__MemoryManager r0,h3d__Buffer r1) {
	String r14, r17;
	hl__types__ArrayObj r18;
	bool r11;
	hxd__BufferFormat r6;
	vclosure *r12;
	double r8, r9, r13;
	int *r15;
	h3d__impl__Driver r10;
	vdynamic *r3;
	vbyte *r16;
	int r4, r5, r7;
	if( r1 == NULL ) hl_null_access();
	r3 = r1->vbuf;
	if( !r3 ) goto label$88467e8_7_4;
	return;
	label$88467e8_7_4:
	r4 = r1->vertices;
	r6 = r1->format;
	if( r6 == NULL ) hl_null_access();
	r5 = r6->strideBytes;
	r4 = r4 * r5;
	r7 = 0;
	if( r4 != r7 ) goto label$88467e8_7_12;
	return;
	label$88467e8_7_12:
	r8 = r0->usedMemory;
	r5 = r4;
	r9 = (double)r4;
	r8 = r8 + r9;
	r9 = 4294967296.;
	if( r9 < r8 ) goto label$88467e8_7_25;
	if( r1 == NULL ) hl_null_access();
	r10 = r0->driver;
	if( r10 == NULL ) hl_null_access();
	r3 = ((vdynamic* (*)(h3d__impl__Driver,h3d__Buffer))r10->$type->vobj_proto[28])(r10,r1);
	r1->vbuf = r3;
	if( r3 ) goto label$88467e8_7_57;
	label$88467e8_7_25:
	r10 = r0->driver;
	if( r10 == NULL ) hl_null_access();
	r11 = ((bool (*)(h3d__impl__Driver))r10->$type->vobj_proto[3])(r10);
	if( !r11 ) goto label$88467e8_7_30;
	return;
	label$88467e8_7_30:
	r8 = r0->usedMemory;
	r12 = r0->garbage;
	if( r12 == NULL ) hl_null_access();
	r12->hasValue ? ((void (*)(vdynamic*))r12->fun)((vdynamic*)r12->value) : ((void (*)(void))r12->fun)();
	r9 = r0->usedMemory;
	if( r9 != r8 ) goto label$88467e8_7_56;
	r14 = (String)s$Memory_full_;
	r13 = 1024.;
	r9 = r8 / r13;
	r9 = hl_math_fceil(r9);
	r15 = &r5;
	r16 = hl_ftos(r9,r15);
	r17 = String___alloc__(r16,r5);
	r14 = String___add__(r14,r17);
	r17 = (String)s$_KB_;
	r14 = String___add__(r14,r17);
	r18 = r0->buffers;
	if( r18 == NULL ) hl_null_access();
	r5 = r18->length;
	r15 = &r5;
	r16 = hl_itos(r5,r15);
	r17 = String___alloc__(r16,r5);
	r14 = String___add__(r14,r17);
	r17 = (String)s$_buffers_;
	r14 = String___add__(r14,r17);
	hl_throw((vdynamic*)r14);
	label$88467e8_7_56:
	goto label$88467e8_7_12;
	label$88467e8_7_57:
	r8 = r0->usedMemory;
	r9 = (double)r4;
	r8 = r8 + r9;
	r0->usedMemory = r8;
	r18 = r0->buffers;
	if( r18 == NULL ) hl_null_access();
	r5 = hl_types_ArrayObj_push(r18,((vdynamic*)r1));
	return;
}

void h3d_impl_MemoryManager_freeBuffer(h3d__impl__MemoryManager r0,h3d__Buffer r1) {
	hl__types__ArrayObj r6;
	bool r5;
	hxd__BufferFormat r10;
	double r7, r11;
	h3d__impl__Driver r4;
	vdynamic *r3;
	int r8, r9;
	if( r1 == NULL ) hl_null_access();
	r3 = r1->vbuf;
	if( r3 ) goto label$88467e8_8_4;
	return;
	label$88467e8_8_4:
	r4 = r0->driver;
	if( r4 == NULL ) hl_null_access();
	((void (*)(h3d__impl__Driver,h3d__Buffer))r4->$type->vobj_proto[31])(r4,r1);
	r3 = NULL;
	r1->vbuf = r3;
	r6 = r0->buffers;
	if( r6 == NULL ) hl_null_access();
	r5 = hl_types_ArrayObj_remove(r6,((vdynamic*)r1));
	if( !r5 ) goto label$88467e8_8_22;
	r7 = r0->usedMemory;
	r8 = r1->vertices;
	r10 = r1->format;
	if( r10 == NULL ) hl_null_access();
	r9 = r10->strideBytes;
	r8 = r8 * r9;
	r11 = (double)r8;
	r7 = r7 - r11;
	r0->usedMemory = r7;
	label$88467e8_8_22:
	return;
}

void h3d_impl_MemoryManager_deleteIndexes(h3d__impl__MemoryManager r0,h3d__Indexes r1) {
	vvirtual *r6;
	hl__types__ArrayObj r3;
	bool r2;
	double r7, r10;
	h3d__impl__Driver r5;
	int r8, r9;
	r3 = r0->indexes;
	if( r3 == NULL ) hl_null_access();
	r2 = hl_types_ArrayObj_remove(r3,((vdynamic*)r1));
	r5 = r0->driver;
	if( r5 == NULL ) hl_null_access();
	if( r1 == NULL ) hl_null_access();
	r6 = r1->ibuf;
	((void (*)(h3d__impl__Driver,vvirtual*))r5->$type->vobj_proto[30])(r5,r6);
	r6 = NULL;
	r1->ibuf = r6;
	r7 = r0->usedMemory;
	r8 = r1->count;
	r2 = r1->is32;
	if( !r2 ) goto label$88467e8_9_16;
	r9 = 4;
	goto label$88467e8_9_17;
	label$88467e8_9_16:
	r9 = 2;
	label$88467e8_9_17:
	r8 = r8 * r9;
	r10 = (double)r8;
	r7 = r7 - r10;
	r0->usedMemory = r7;
	return;
}

void h3d_impl_MemoryManager_allocIndexes(h3d__impl__MemoryManager r0,h3d__Indexes r1) {
	hl__types__ArrayObj r6;
	vvirtual *r2;
	bool r5;
	double r7, r9;
	h3d__impl__Driver r3;
	int r4, r8;
	if( r1 == NULL ) hl_null_access();
	r3 = r0->driver;
	if( r3 == NULL ) hl_null_access();
	r4 = r1->count;
	r5 = r1->is32;
	r2 = ((vvirtual* (*)(h3d__impl__Driver,int,bool))r3->$type->vobj_proto[27])(r3,r4,r5);
	r1->ibuf = r2;
	r6 = r0->indexes;
	if( r6 == NULL ) hl_null_access();
	r4 = hl_types_ArrayObj_push(r6,((vdynamic*)r1));
	r7 = r0->usedMemory;
	r4 = r1->count;
	r5 = r1->is32;
	if( !r5 ) goto label$88467e8_10_16;
	r8 = 4;
	goto label$88467e8_10_17;
	label$88467e8_10_16:
	r8 = 2;
	label$88467e8_10_17:
	r4 = r4 * r8;
	r9 = (double)r4;
	r7 = r7 + r9;
	r0->usedMemory = r7;
	return;
}

int h3d_impl_MemoryManager_memSize(h3d__impl__MemoryManager r0,h3d__mat__Texture r1) {
	venum *r4;
	int r2, r3, r5, r6, r7, r8, r9, r10;
	if( r1 == NULL ) hl_null_access();
	r2 = r1->flags;
	r3 = 4096;
	r2 = r2 & r3;
	r3 = 0;
	if( r2 == r3 ) goto label$88467e8_11_13;
	r2 = r1->flags;
	r3 = 512;
	r2 = r2 & r3;
	r3 = 0;
	if( r2 == r3 ) goto label$88467e8_11_13;
	r2 = 4;
	return r2;
	label$88467e8_11_13:
	r2 = r1->width;
	r3 = r1->height;
	r4 = r1->format;
	r2 = hxd_Pixels_calcDataSize(r2,r3,r4);
	r3 = h3d_mat_Texture_get_mipLevels(r1);
	r5 = 0;
	if( r5 >= r3 ) goto label$88467e8_11_44;
	r3 = 1;
	r5 = h3d_mat_Texture_get_mipLevels(r1);
	label$88467e8_11_22:
	if( r3 >= r5 ) goto label$88467e8_11_44;
	r6 = r3;
	++r3;
	if( r1 == NULL ) hl_null_access();
	r7 = r1->width;
	r7 = r7 >> r6;
	r9 = 0;
	if( r7 != r9 ) goto label$88467e8_11_33;
	r8 = 1;
	r7 = r8;
	label$88467e8_11_33:
	r8 = r1->height;
	r8 = r8 >> r6;
	r10 = 0;
	if( r8 != r10 ) goto label$88467e8_11_39;
	r9 = 1;
	r8 = r9;
	label$88467e8_11_39:
	r4 = r1->format;
	r10 = hxd_Pixels_calcDataSize(r7,r8,r4);
	r9 = r2 + r10;
	r2 = r9;
	goto label$88467e8_11_22;
	label$88467e8_11_44:
	if( r1 == NULL ) hl_null_access();
	r5 = ((int (*)(h3d__mat__Texture))r1->$type->vobj_proto[0])(r1);
	r3 = r2 * r5;
	return r3;
}

bool h3d_impl_MemoryManager_cleanTextures(h3d__impl__MemoryManager r0,bool* r1) {
	vvirtual *r15, *r16;
	hl__types__ArrayObj r4;
	bool r2, r14;
	h3d__mat__$Texture r19;
	hxd__$Timer r17;
	vclosure *r5, *r6, *r13;
	vdynamic *r11;
	varray *r12;
	h3d__mat__Texture r10;
	int r7, r8, r9, r18;
	if( r1 ) goto label$88467e8_12_3;
	r2 = true;
	goto label$88467e8_12_4;
	label$88467e8_12_3:
	r2 = *r1;
	label$88467e8_12_4:
	r4 = r0->textures;
	if( r4 == NULL ) hl_null_access();
	r5 = hl_alloc_closure_ptr(&t$fun_6a85200,h3d_impl_MemoryManager_sortByLRU,r0);
	if( r5 ) goto label$88467e8_12_10;
	r6 = NULL;
	goto label$88467e8_12_11;
	label$88467e8_12_10:
	r6 = hl_alloc_closure_ptr(&t$fun_5f1efa7,h3d_impl_MemoryManager_cleanTextures__$1,r5);
	label$88467e8_12_11:
	hl_types_ArrayObj_sort(r4,r6);
	r7 = 0;
	r4 = r0->textures;
	label$88467e8_12_14:
	if( r4 == NULL ) hl_null_access();
	r9 = r4->length;
	if( r7 >= r9 ) goto label$88467e8_12_62;
	r9 = r4->length;
	if( ((unsigned)r7) < ((unsigned)r9) ) goto label$88467e8_12_22;
	r10 = NULL;
	goto label$88467e8_12_25;
	label$88467e8_12_22:
	r12 = r4->array;
	r11 = ((vdynamic**)(r12 + 1))[r7];
	r10 = (h3d__mat__Texture)r11;
	label$88467e8_12_25:
	++r7;
	if( r10 == NULL ) hl_null_access();
	r13 = r10->realloc;
	if( !r13 ) goto label$88467e8_12_46;
	r14 = h3d_mat_Texture_isDepth(r10);
	if( !r14 ) goto label$88467e8_12_38;
	r15 = r10->_hx_t;
	r16 = NULL;
	if( r15 == r16 || (r15 && r16 && r15->value && r16->value && r15->value == r16->value) ) goto label$88467e8_12_36;
	r14 = false;
	goto label$88467e8_12_37;
	label$88467e8_12_36:
	r14 = true;
	label$88467e8_12_37:
	goto label$88467e8_12_45;
	label$88467e8_12_38:
	r15 = r10->_hx_t;
	if( r15 ) goto label$88467e8_12_44;
	r13 = r10->realloc;
	if( r13 ) goto label$88467e8_12_44;
	r14 = true;
	goto label$88467e8_12_45;
	label$88467e8_12_44:
	r14 = false;
	label$88467e8_12_45:
	if( !r14 ) goto label$88467e8_12_47;
	label$88467e8_12_46:
	goto label$88467e8_12_14;
	label$88467e8_12_47:
	if( r2 ) goto label$88467e8_12_54;
	r8 = r10->_lastFrame;
	r17 = (hxd__$Timer)g$_hxd_Timer;
	r9 = r17->frameCount;
	r18 = 3600;
	r9 = r9 - r18;
	if( r8 >= r9 ) goto label$88467e8_12_61;
	label$88467e8_12_54:
	r8 = r10->_lastFrame;
	r19 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r9 = r19->PREVENT_AUTO_DISPOSE;
	if( r8 == r9 ) goto label$88467e8_12_61;
	h3d_mat_Texture_dispose(r10);
	r14 = true;
	return r14;
	label$88467e8_12_61:
	goto label$88467e8_12_14;
	label$88467e8_12_62:
	r14 = false;
	return r14;
}

int h3d_impl_MemoryManager_sortByLRU(h3d__impl__MemoryManager r0,h3d__mat__Texture r1,h3d__mat__Texture r2) {
	int r3, r4;
	if( r1 == NULL ) hl_null_access();
	r3 = r1->_lastFrame;
	if( r2 == NULL ) hl_null_access();
	r4 = r2->_lastFrame;
	r3 = r3 - r4;
	return r3;
}

void h3d_impl_MemoryManager_deleteTexture(h3d__impl__MemoryManager r0,h3d__mat__Texture r1) {
	hl__types__ArrayObj r4;
	bool r3;
	double r6, r8;
	h3d__impl__Driver r5;
	int r7;
	r4 = r0->textures;
	if( r4 == NULL ) hl_null_access();
	r3 = hl_types_ArrayObj_remove(r4,((vdynamic*)r1));
	if( r3 ) goto label$88467e8_14_5;
	return;
	label$88467e8_14_5:
	r5 = r0->driver;
	if( r5 == NULL ) hl_null_access();
	((void (*)(h3d__impl__Driver,h3d__mat__Texture))r5->$type->vobj_proto[29])(r5,r1);
	r6 = r0->texMemory;
	r7 = h3d_impl_MemoryManager_memSize(r0,r1);
	r8 = (double)r7;
	r6 = r6 - r8;
	r0->texMemory = r6;
	return;
}

void h3d_impl_MemoryManager_allocTexture(h3d__impl__MemoryManager r0,h3d__mat__Texture r1) {
	String r10;
	bool *r3;
	hl__types__ArrayObj r12;
	vvirtual *r6;
	bool r2, r4, r8, r9;
	double r13, r14;
	h3d__impl__Driver r7;
	int r11;
	label$88467e8_15_0:
	r2 = true;
	if( !r2 ) goto label$88467e8_15_34;
	r2 = false;
	r3 = &r2;
	r2 = h3d_impl_MemoryManager_cleanTextures(r0,r3);
	r4 = r2;
	if( r1 == NULL ) hl_null_access();
	r7 = r0->driver;
	if( r7 == NULL ) hl_null_access();
	r6 = ((vvirtual* (*)(h3d__impl__Driver,h3d__mat__Texture))r7->$type->vobj_proto[26])(r7,r1);
	r1->_hx_t = r6;
	r6 = r1->_hx_t;
	if( !r6 ) goto label$88467e8_15_15;
	goto label$88467e8_15_34;
	label$88467e8_15_15:
	r7 = r0->driver;
	if( r7 == NULL ) hl_null_access();
	r8 = ((bool (*)(h3d__impl__Driver))r7->$type->vobj_proto[3])(r7);
	if( !r8 ) goto label$88467e8_15_20;
	return;
	label$88467e8_15_20:
	r8 = false;
	r3 = &r8;
	r8 = h3d_impl_MemoryManager_cleanTextures(r0,r3);
	if( !r8 ) goto label$88467e8_15_26;
	goto label$88467e8_15_20;
	label$88467e8_15_26:
	if( r4 ) goto label$88467e8_15_33;
	r9 = true;
	r3 = &r9;
	r9 = h3d_impl_MemoryManager_cleanTextures(r0,r3);
	if( r9 ) goto label$88467e8_15_33;
	r10 = (String)s$Maximum_texture_memory_reached;
	hl_throw((vdynamic*)r10);
	label$88467e8_15_33:
	goto label$88467e8_15_0;
	label$88467e8_15_34:
	r12 = r0->textures;
	if( r12 == NULL ) hl_null_access();
	r11 = hl_types_ArrayObj_push(r12,((vdynamic*)r1));
	r13 = r0->texMemory;
	r11 = h3d_impl_MemoryManager_memSize(r0,r1);
	r14 = (double)r11;
	r13 = r13 + r14;
	r0->texMemory = r13;
	return;
}

void h3d_impl_MemoryManager_allocDepth(h3d__impl__MemoryManager r0,h3d__mat__Texture r1) {
	String r10;
	bool *r3;
	hl__types__ArrayObj r12;
	vvirtual *r6;
	bool r2, r4, r8, r9;
	double r13, r15;
	h3d__impl__Driver r7;
	int r11, r14;
	label$88467e8_16_0:
	r2 = true;
	if( !r2 ) goto label$88467e8_16_34;
	r2 = false;
	r3 = &r2;
	r2 = h3d_impl_MemoryManager_cleanTextures(r0,r3);
	r4 = r2;
	if( r1 == NULL ) hl_null_access();
	r7 = r0->driver;
	if( r7 == NULL ) hl_null_access();
	r6 = ((vvirtual* (*)(h3d__impl__Driver,h3d__mat__Texture))r7->$type->vobj_proto[20])(r7,r1);
	r1->_hx_t = r6;
	r6 = r1->_hx_t;
	if( !r6 ) goto label$88467e8_16_15;
	goto label$88467e8_16_34;
	label$88467e8_16_15:
	r7 = r0->driver;
	if( r7 == NULL ) hl_null_access();
	r8 = ((bool (*)(h3d__impl__Driver))r7->$type->vobj_proto[3])(r7);
	if( !r8 ) goto label$88467e8_16_20;
	return;
	label$88467e8_16_20:
	r8 = false;
	r3 = &r8;
	r8 = h3d_impl_MemoryManager_cleanTextures(r0,r3);
	if( !r8 ) goto label$88467e8_16_26;
	goto label$88467e8_16_20;
	label$88467e8_16_26:
	if( r4 ) goto label$88467e8_16_33;
	r9 = true;
	r3 = &r9;
	r9 = h3d_impl_MemoryManager_cleanTextures(r0,r3);
	if( r9 ) goto label$88467e8_16_33;
	r10 = (String)s$Maximum_texture_memory_reached;
	hl_throw((vdynamic*)r10);
	label$88467e8_16_33:
	goto label$88467e8_16_0;
	label$88467e8_16_34:
	r12 = r0->depths;
	if( r12 == NULL ) hl_null_access();
	r11 = hl_types_ArrayObj_push(r12,((vdynamic*)r1));
	r13 = r0->texMemory;
	if( r1 == NULL ) hl_null_access();
	r11 = r1->width;
	r14 = r1->height;
	r11 = r11 * r14;
	r14 = 4;
	r11 = r11 * r14;
	r15 = (double)r11;
	r13 = r13 + r15;
	r0->texMemory = r13;
	return;
}

void h3d_impl_MemoryManager_deleteDepth(h3d__impl__MemoryManager r0,h3d__mat__Texture r1) {
	hl__types__ArrayObj r4;
	bool r3;
	double r6, r9;
	h3d__impl__Driver r5;
	int r7, r8;
	r4 = r0->depths;
	if( r4 == NULL ) hl_null_access();
	r3 = hl_types_ArrayObj_remove(r4,((vdynamic*)r1));
	if( r3 ) goto label$88467e8_17_5;
	return;
	label$88467e8_17_5:
	r5 = r0->driver;
	if( r5 == NULL ) hl_null_access();
	((void (*)(h3d__impl__Driver,h3d__mat__Texture))r5->$type->vobj_proto[21])(r5,r1);
	r6 = r0->texMemory;
	if( r1 == NULL ) hl_null_access();
	r7 = r1->width;
	r8 = r1->height;
	r7 = r7 * r8;
	r8 = 4;
	r7 = r7 * r8;
	r9 = (double)r7;
	r6 = r6 - r9;
	r0->texMemory = r6;
	return;
}

void h3d_impl_MemoryManager_onContextLost(h3d__impl__MemoryManager r0) {
	h3d_impl_MemoryManager_dispose(r0);
	h3d_impl_MemoryManager_initIndexes(r0);
	return;
}

void h3d_impl_MemoryManager_dispose(h3d__impl__MemoryManager r0) {
	hl__types__ArrayObj r4;
	hl_type *r10;
	double r11;
	h3d__Buffer r9;
	vdynamic *r7;
	varray *r8;
	h3d__mat__Texture r6;
	int r3, r5;
	h3d__Indexes r2;
	r2 = r0->triIndexes16;
	if( !r2 ) goto label$88467e8_19_5;
	r2 = r0->triIndexes16;
	if( r2 == NULL ) hl_null_access();
	h3d_Indexes_dispose(r2);
	label$88467e8_19_5:
	r2 = r0->quadIndexes16;
	if( !r2 ) goto label$88467e8_19_10;
	r2 = r0->quadIndexes16;
	if( r2 == NULL ) hl_null_access();
	h3d_Indexes_dispose(r2);
	label$88467e8_19_10:
	r2 = r0->triIndexes32;
	if( !r2 ) goto label$88467e8_19_15;
	r2 = r0->triIndexes32;
	if( r2 == NULL ) hl_null_access();
	h3d_Indexes_dispose(r2);
	label$88467e8_19_15:
	r2 = r0->quadIndexes32;
	if( !r2 ) goto label$88467e8_19_20;
	r2 = r0->quadIndexes32;
	if( r2 == NULL ) hl_null_access();
	h3d_Indexes_dispose(r2);
	label$88467e8_19_20:
	r2 = NULL;
	r0->triIndexes16 = r2;
	r2 = NULL;
	r0->quadIndexes16 = r2;
	r2 = NULL;
	r0->triIndexes32 = r2;
	r2 = NULL;
	r0->quadIndexes32 = r2;
	r3 = 0;
	r4 = r0->textures;
	if( r4 == NULL ) hl_null_access();
	r4 = hl_types_ArrayObj_copy(r4);
	label$88467e8_19_32:
	if( r4 == NULL ) hl_null_access();
	r5 = r4->length;
	if( r3 >= r5 ) goto label$88467e8_19_47;
	r5 = r4->length;
	if( ((unsigned)r3) < ((unsigned)r5) ) goto label$88467e8_19_40;
	r6 = NULL;
	goto label$88467e8_19_43;
	label$88467e8_19_40:
	r8 = r4->array;
	r7 = ((vdynamic**)(r8 + 1))[r3];
	r6 = (h3d__mat__Texture)r7;
	label$88467e8_19_43:
	++r3;
	if( r6 == NULL ) hl_null_access();
	h3d_mat_Texture_dispose(r6);
	goto label$88467e8_19_32;
	label$88467e8_19_47:
	r3 = 0;
	r4 = r0->depths;
	if( r4 == NULL ) hl_null_access();
	r4 = hl_types_ArrayObj_copy(r4);
	label$88467e8_19_51:
	if( r4 == NULL ) hl_null_access();
	r5 = r4->length;
	if( r3 >= r5 ) goto label$88467e8_19_66;
	r5 = r4->length;
	if( ((unsigned)r3) < ((unsigned)r5) ) goto label$88467e8_19_59;
	r6 = NULL;
	goto label$88467e8_19_62;
	label$88467e8_19_59:
	r8 = r4->array;
	r7 = ((vdynamic**)(r8 + 1))[r3];
	r6 = (h3d__mat__Texture)r7;
	label$88467e8_19_62:
	++r3;
	if( r6 == NULL ) hl_null_access();
	h3d_mat_Texture_dispose(r6);
	goto label$88467e8_19_51;
	label$88467e8_19_66:
	r3 = 0;
	r4 = r0->buffers;
	if( r4 == NULL ) hl_null_access();
	r4 = hl_types_ArrayObj_copy(r4);
	label$88467e8_19_70:
	if( r4 == NULL ) hl_null_access();
	r5 = r4->length;
	if( r3 >= r5 ) goto label$88467e8_19_85;
	r5 = r4->length;
	if( ((unsigned)r3) < ((unsigned)r5) ) goto label$88467e8_19_78;
	r9 = NULL;
	goto label$88467e8_19_81;
	label$88467e8_19_78:
	r8 = r4->array;
	r7 = ((vdynamic**)(r8 + 1))[r3];
	r9 = (h3d__Buffer)r7;
	label$88467e8_19_81:
	++r3;
	if( r9 == NULL ) hl_null_access();
	h3d_Buffer_dispose(r9);
	goto label$88467e8_19_70;
	label$88467e8_19_85:
	r3 = 0;
	r4 = r0->indexes;
	if( r4 == NULL ) hl_null_access();
	r4 = hl_types_ArrayObj_copy(r4);
	label$88467e8_19_89:
	if( r4 == NULL ) hl_null_access();
	r5 = r4->length;
	if( r3 >= r5 ) goto label$88467e8_19_104;
	r5 = r4->length;
	if( ((unsigned)r3) < ((unsigned)r5) ) goto label$88467e8_19_97;
	r2 = NULL;
	goto label$88467e8_19_100;
	label$88467e8_19_97:
	r8 = r4->array;
	r7 = ((vdynamic**)(r8 + 1))[r3];
	r2 = (h3d__Indexes)r7;
	label$88467e8_19_100:
	++r3;
	if( r2 == NULL ) hl_null_access();
	h3d_Indexes_dispose(r2);
	goto label$88467e8_19_89;
	label$88467e8_19_104:
	r10 = &t$h3d_Buffer;
	r3 = 0;
	r8 = hl_alloc_array(r10,r3);
	r4 = hl_types_ArrayObj_alloc(r8);
	r0->buffers = r4;
	r10 = &t$h3d_Indexes;
	r3 = 0;
	r8 = hl_alloc_array(r10,r3);
	r4 = hl_types_ArrayObj_alloc(r8);
	r0->indexes = r4;
	r10 = &t$h3d_mat_Texture;
	r3 = 0;
	r8 = hl_alloc_array(r10,r3);
	r4 = hl_types_ArrayObj_alloc(r8);
	r0->textures = r4;
	r11 = 0.;
	r0->usedMemory = r11;
	r11 = 0.;
	r0->texMemory = r11;
	return;
}

void h3d_impl_MemoryManager_new(h3d__impl__MemoryManager r0,h3d__impl__Driver r1) {
	double r3;
	vclosure *r2;
	r2 = r0->garbage;
	if( r2 ) goto label$88467e8_20_4;
	r2 = hl_alloc_closure_ptr(&t$fun_4bffad7,h3d_impl_MemoryManager_garbage,r0);
	r0->garbage = r2;
	label$88467e8_20_4:
	r3 = 0.;
	r0->texMemory = r3;
	r3 = 0.;
	r0->usedMemory = r3;
	r0->driver = r1;
	return;
}
