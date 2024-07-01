﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h2d/Layers.h>
void h2d_Object_new(h2d__Object,h2d__Object);
#include <hl/natives.h>
hl__types__ArrayBytes_Int hl_types_ArrayBase_allocI32(vbyte*,int);
void h2d_Layers_add(h2d__Layers,h2d__Object,int*,int*);
void h2d_Layers_removeChild(h2d__Layers,h2d__Object);
void hl_types_ArrayBytes_Int___expand(hl__types__ArrayBytes_Int,int);
void h2d_Object_addChildAt(h2d__Object,h2d__Object,int);
#include <hl/types/ArrayBase.h>
hl__types__ArrayBase hl_types_ArrayObj_splice(hl__types__ArrayObj,int,int);
extern hl_type t$hl_types_ArrayObj;
extern hl_type t$hl_types_ArrayBase;
void h2d_Object_setParentContainer(h2d__Object,h2d__Object);
void h2d_Object_contentChanged(h2d__Object,h2d__Object);

void h2d_Layers_new(h2d__Layers r0,h2d__Object r1) {
	hl__types__ArrayBytes_Int r3;
	int r5;
	vbyte *r4;
	h2d_Object_new(((h2d__Object)r0),r1);
	r5 = 0;
	r4 = hl_alloc_bytes(r5);
	r5 = 0;
	r5 = 0;
	r3 = hl_types_ArrayBase_allocI32(r4,r5);
	r0->layersIndexes = r3;
	r5 = 0;
	r0->layerCount = r5;
	return;
}

void h2d_Layers_addChild(h2d__Layers r0,h2d__Object r1) {
	int *r4, *r5;
	int r3;
	r3 = -1;
	r4 = &r3;
	r5 = NULL;
	h2d_Layers_add(r0,r1,r4,r5);
	return;
}

void h2d_Layers_add(h2d__Layers r0,h2d__Object r1,int* r2,int* r3) {
	hl__types__ArrayObj r13;
	bool r8, r9;
	h2d__Object r7;
	hl__types__ArrayBytes_Int r12;
	vbyte *r15;
	int r4, r5, r10, r11, r14, r16, r17;
	if( r2 ) goto label$7dc1728_3_3;
	r4 = -1;
	goto label$7dc1728_3_4;
	label$7dc1728_3_3:
	r4 = *r2;
	label$7dc1728_3_4:
	if( r3 ) goto label$7dc1728_3_7;
	r5 = -1;
	goto label$7dc1728_3_8;
	label$7dc1728_3_7:
	r5 = *r3;
	label$7dc1728_3_8:
	if( r1 == NULL ) hl_null_access();
	r7 = r1->parent;
	if( r7 != ((h2d__Object)r0) ) goto label$7dc1728_3_16;
	r8 = r1->allocated;
	r9 = false;
	r1->allocated = r9;
	h2d_Layers_removeChild(r0,r1);
	r1->allocated = r8;
	label$7dc1728_3_16:
	r11 = -1;
	if( r4 != r11 ) goto label$7dc1728_3_27;
	r10 = r0->layerCount;
	r11 = 0;
	if( r10 != r11 ) goto label$7dc1728_3_23;
	r10 = 0;
	goto label$7dc1728_3_26;
	label$7dc1728_3_23:
	r10 = r0->layerCount;
	r11 = 1;
	r10 = r10 - r11;
	label$7dc1728_3_26:
	r4 = r10;
	label$7dc1728_3_27:
	r11 = r0->layerCount;
	if( r4 < r11 ) goto label$7dc1728_3_47;
	r12 = r0->layersIndexes;
	if( r12 == NULL ) hl_null_access();
	r10 = r0->layerCount;
	r11 = r10;
	++r10;
	r0->layerCount = r10;
	r13 = r0->children;
	if( r13 == NULL ) hl_null_access();
	r10 = r13->length;
	r14 = r12->length;
	if( ((unsigned)r11) < ((unsigned)r14) ) goto label$7dc1728_3_42;
	hl_types_ArrayBytes_Int___expand(r12,r11);
	label$7dc1728_3_42:
	r15 = r12->bytes;
	r14 = 2;
	r14 = r11 << r14;
	*(int*)(r15 + r14) = r10;
	goto label$7dc1728_3_27;
	label$7dc1728_3_47:
	r11 = -1;
	if( r5 == r11 ) goto label$7dc1728_3_117;
	r11 = 0;
	if( r4 != r11 ) goto label$7dc1728_3_72;
	r12 = r0->layersIndexes;
	if( r12 == NULL ) hl_null_access();
	r11 = r12->length;
	if( ((unsigned)r4) < ((unsigned)r11) ) goto label$7dc1728_3_57;
	r10 = 0;
	goto label$7dc1728_3_61;
	label$7dc1728_3_57:
	r15 = r12->bytes;
	r11 = 2;
	r11 = r4 << r11;
	r10 = *(int*)(r15 + r11);
	label$7dc1728_3_61:
	if( r10 >= r5 ) goto label$7dc1728_3_64;
	r11 = r10;
	goto label$7dc1728_3_65;
	label$7dc1728_3_64:
	r11 = r5;
	label$7dc1728_3_65:
	r14 = 0;
	if( r14 >= r11 ) goto label$7dc1728_3_69;
	r14 = r11;
	goto label$7dc1728_3_70;
	label$7dc1728_3_69:
	r14 = 0;
	label$7dc1728_3_70:
	h2d_Object_addChildAt(((h2d__Object)r0),r1,r14);
	goto label$7dc1728_3_116;
	label$7dc1728_3_72:
	r11 = 0;
	if( r5 >= r11 ) goto label$7dc1728_3_88;
	r12 = r0->layersIndexes;
	if( r12 == NULL ) hl_null_access();
	r11 = 1;
	r10 = r4 - r11;
	r11 = r12->length;
	if( ((unsigned)r10) < ((unsigned)r11) ) goto label$7dc1728_3_82;
	r10 = 0;
	goto label$7dc1728_3_86;
	label$7dc1728_3_82:
	r15 = r12->bytes;
	r11 = 2;
	r11 = r10 << r11;
	r10 = *(int*)(r15 + r11);
	label$7dc1728_3_86:
	h2d_Object_addChildAt(((h2d__Object)r0),r1,r10);
	goto label$7dc1728_3_116;
	label$7dc1728_3_88:
	r12 = r0->layersIndexes;
	if( r12 == NULL ) hl_null_access();
	r11 = 1;
	r10 = r4 - r11;
	r11 = r12->length;
	if( ((unsigned)r10) < ((unsigned)r11) ) goto label$7dc1728_3_96;
	r10 = 0;
	goto label$7dc1728_3_100;
	label$7dc1728_3_96:
	r15 = r12->bytes;
	r11 = 2;
	r11 = r10 << r11;
	r10 = *(int*)(r15 + r11);
	label$7dc1728_3_100:
	r10 = r10 + r5;
	r12 = r0->layersIndexes;
	if( r12 == NULL ) hl_null_access();
	r14 = r12->length;
	if( ((unsigned)r4) < ((unsigned)r14) ) goto label$7dc1728_3_107;
	r11 = 0;
	goto label$7dc1728_3_111;
	label$7dc1728_3_107:
	r15 = r12->bytes;
	r14 = 2;
	r14 = r4 << r14;
	r11 = *(int*)(r15 + r14);
	label$7dc1728_3_111:
	if( r11 >= r10 ) goto label$7dc1728_3_114;
	r14 = r11;
	goto label$7dc1728_3_115;
	label$7dc1728_3_114:
	r14 = r10;
	label$7dc1728_3_115:
	h2d_Object_addChildAt(((h2d__Object)r0),r1,r14);
	label$7dc1728_3_116:
	goto label$7dc1728_3_128;
	label$7dc1728_3_117:
	r12 = r0->layersIndexes;
	if( r12 == NULL ) hl_null_access();
	r11 = r12->length;
	if( ((unsigned)r4) < ((unsigned)r11) ) goto label$7dc1728_3_123;
	r10 = 0;
	goto label$7dc1728_3_127;
	label$7dc1728_3_123:
	r15 = r12->bytes;
	r11 = 2;
	r11 = r4 << r11;
	r10 = *(int*)(r15 + r11);
	label$7dc1728_3_127:
	h2d_Object_addChildAt(((h2d__Object)r0),r1,r10);
	label$7dc1728_3_128:
	r10 = r4;
	r11 = r0->layerCount;
	label$7dc1728_3_130:
	if( r10 >= r11 ) goto label$7dc1728_3_146;
	r14 = r10;
	++r10;
	r12 = r0->layersIndexes;
	if( r12 == NULL ) hl_null_access();
	r16 = r12->length;
	if( ((unsigned)r14) < ((unsigned)r16) ) goto label$7dc1728_3_139;
	hl_types_ArrayBytes_Int___expand(r12,r14);
	label$7dc1728_3_139:
	r15 = r12->bytes;
	r16 = 2;
	r16 = r14 << r16;
	r17 = *(int*)(r15 + r16);
	++r17;
	*(int*)(r15 + r16) = r17;
	goto label$7dc1728_3_130;
	label$7dc1728_3_146:
	return;
}

void h2d_Layers_addChildAt(h2d__Layers r0,h2d__Object r1,int r2) {
	int *r5, *r7;
	int r4, r6;
	r4 = -1;
	r5 = &r4;
	r6 = r2;
	r7 = &r6;
	h2d_Layers_add(r0,r1,r5,r7);
	return;
}

void h2d_Layers_removeChild(h2d__Layers r0,h2d__Object r1) {
	hl__types__ArrayObj r5;
	bool r14;
	h2d__Object r9, r12;
	hl__types__ArrayBytes_Int r16;
	hl__types__ArrayBase r13;
	vdynamic *r10;
	vbyte *r17;
	varray *r11;
	int r2, r4, r6, r7, r8, r15, r18;
	r2 = 0;
	r5 = r0->children;
	if( r5 == NULL ) hl_null_access();
	r4 = r5->length;
	label$7dc1728_5_4:
	if( r2 >= r4 ) goto label$7dc1728_5_72;
	r6 = r2;
	++r2;
	r5 = r0->children;
	if( r5 == NULL ) hl_null_access();
	r8 = r5->length;
	if( ((unsigned)r6) < ((unsigned)r8) ) goto label$7dc1728_5_14;
	r9 = NULL;
	goto label$7dc1728_5_17;
	label$7dc1728_5_14:
	r11 = r5->array;
	r10 = ((vdynamic**)(r11 + 1))[r6];
	r9 = (h2d__Object)r10;
	label$7dc1728_5_17:
	if( r9 != r1 ) goto label$7dc1728_5_71;
	r5 = r0->children;
	if( r5 == NULL ) hl_null_access();
	r8 = 1;
	r13 = hl_types_ArrayObj_splice(r5,r6,r8);
	r5 = (hl__types__ArrayObj)hl_dyn_castp(&r13,&t$hl_types_ArrayBase,&t$hl_types_ArrayObj);
	if( r1 == NULL ) hl_null_access();
	r14 = r1->allocated;
	if( !r14 ) goto label$7dc1728_5_27;
	((void (*)(h2d__Object))r1->$type->vobj_proto[5])(r1);
	label$7dc1728_5_27:
	r12 = NULL;
	r1->parent = r12;
	r14 = true;
	r1->posChanged = r14;
	r9 = r1->parentContainer;
	if( !r9 ) goto label$7dc1728_5_35;
	r12 = NULL;
	h2d_Object_setParentContainer(r1,r12);
	label$7dc1728_5_35:
	r7 = r0->layerCount;
	r8 = 1;
	r7 = r7 - r8;
	label$7dc1728_5_38:
	r15 = 0;
	if( r7 < r15 ) goto label$7dc1728_5_65;
	r16 = r0->layersIndexes;
	if( r16 == NULL ) hl_null_access();
	r15 = r16->length;
	if( ((unsigned)r7) < ((unsigned)r15) ) goto label$7dc1728_5_47;
	r8 = 0;
	goto label$7dc1728_5_51;
	label$7dc1728_5_47:
	r17 = r16->bytes;
	r15 = 2;
	r15 = r7 << r15;
	r8 = *(int*)(r17 + r15);
	label$7dc1728_5_51:
	if( r6 >= r8 ) goto label$7dc1728_5_65;
	r16 = r0->layersIndexes;
	if( r16 == NULL ) hl_null_access();
	r15 = r16->length;
	if( ((unsigned)r7) < ((unsigned)r15) ) goto label$7dc1728_5_57;
	hl_types_ArrayBytes_Int___expand(r16,r7);
	label$7dc1728_5_57:
	r17 = r16->bytes;
	r15 = 2;
	r15 = r7 << r15;
	r18 = *(int*)(r17 + r15);
	--r18;
	*(int*)(r17 + r15) = r18;
	--r7;
	goto label$7dc1728_5_38;
	label$7dc1728_5_65:
	r9 = r0->parentContainer;
	if( !r9 ) goto label$7dc1728_5_70;
	r9 = r0->parentContainer;
	if( r9 == NULL ) hl_null_access();
	h2d_Object_contentChanged(r9,((h2d__Object)r0));
	label$7dc1728_5_70:
	goto label$7dc1728_5_72;
	label$7dc1728_5_71:
	goto label$7dc1728_5_4;
	label$7dc1728_5_72:
	return;
}

