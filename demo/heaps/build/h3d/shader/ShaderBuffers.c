﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/shader/ShaderBuffers.h>
#include <hxsl/RuntimeShaderData.h>
#include <h3d/mat/Texture.h>
#include <h3d/Buffer.h>
#include <hl/natives.h>
hl__types__ArrayBytes_hl_F32 hl_types_ArrayBase_allocF32(vbyte*,int);
extern hl_type t$_dyn;
void hl_types_ArrayBytes_hl_F32___expand(hl__types__ArrayBytes_hl_F32,int);
extern hl_type t$h3d_mat_Texture;
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
void hl_types_ArrayObj___expand(hl__types__ArrayObj,int);
extern hl_type t$h3d_Buffer;

void h3d_shader_ShaderBuffers_new(h3d__shader__ShaderBuffers r0,hxsl__RuntimeShaderData r1) {
	hl__types__ArrayObj r12, r16;
	hl_type *r14;
	hl__types__ArrayBytes_hl_F32 r5, r8;
	float r10;
	h3d__Buffer r19;
	vdynamic *r9;
	h3d__mat__Texture r17;
	varray *r13;
	vbyte *r6;
	int r2, r3, r7, r11, r15, r18;
	if( r1 == NULL ) hl_null_access();
	r2 = r1->globalsSize;
	r3 = 2;
	r2 = r2 << r3;
	r3 = 0;
	r6 = hl_alloc_bytes(r3);
	r3 = 0;
	r3 = 0;
	r5 = hl_types_ArrayBase_allocF32(r6,r3);
	r7 = 0;
	if( r7 >= r2 ) goto label$9c0bd3a_1_23;
	if( r5 == NULL ) hl_null_access();
	r7 = 1;
	r3 = r2 - r7;
	r9 = NULL;
	r10 = (float)hl_dyn_castf(&r9,&t$_dyn);
	r7 = r5->length;
	if( ((unsigned)r3) < ((unsigned)r7) ) goto label$9c0bd3a_1_19;
	hl_types_ArrayBytes_hl_F32___expand(r5,r3);
	label$9c0bd3a_1_19:
	r6 = r5->bytes;
	r7 = 2;
	r7 = r3 << r7;
	*(float*)(r6 + r7) = r10;
	label$9c0bd3a_1_23:
	r0->globals = r5;
	r3 = r1->paramsSize;
	r7 = 2;
	r3 = r3 << r7;
	r7 = 0;
	r6 = hl_alloc_bytes(r7);
	r7 = 0;
	r7 = 0;
	r8 = hl_types_ArrayBase_allocF32(r6,r7);
	r11 = 0;
	if( r11 >= r3 ) goto label$9c0bd3a_1_46;
	if( r8 == NULL ) hl_null_access();
	r11 = 1;
	r7 = r3 - r11;
	r9 = NULL;
	r10 = (float)hl_dyn_castf(&r9,&t$_dyn);
	r11 = r8->length;
	if( ((unsigned)r7) < ((unsigned)r11) ) goto label$9c0bd3a_1_42;
	hl_types_ArrayBytes_hl_F32___expand(r8,r7);
	label$9c0bd3a_1_42:
	r6 = r8->bytes;
	r11 = 2;
	r11 = r7 << r11;
	*(float*)(r6 + r11) = r10;
	label$9c0bd3a_1_46:
	r0->params = r8;
	r7 = r1->texturesCount;
	r14 = &t$h3d_mat_Texture;
	r11 = 0;
	r13 = hl_alloc_array(r14,r11);
	r12 = hl_types_ArrayObj_alloc(r13);
	r15 = 0;
	if( r15 >= r7 ) goto label$9c0bd3a_1_64;
	if( r12 == NULL ) hl_null_access();
	r15 = 1;
	r11 = r7 - r15;
	r9 = NULL;
	r17 = (h3d__mat__Texture)hl_dyn_castp(&r9,&t$_dyn,&t$h3d_mat_Texture);
	r15 = r12->length;
	if( ((unsigned)r11) < ((unsigned)r15) ) goto label$9c0bd3a_1_62;
	hl_types_ArrayObj___expand(r12,r11);
	label$9c0bd3a_1_62:
	r13 = r12->array;
	((h3d__mat__Texture*)(r13 + 1))[r11] = r17;
	label$9c0bd3a_1_64:
	r0->tex = r12;
	r11 = r1->bufferCount;
	r15 = 0;
	if( r15 >= r11 ) goto label$9c0bd3a_1_86;
	r11 = r1->bufferCount;
	r14 = &t$h3d_Buffer;
	r15 = 0;
	r13 = hl_alloc_array(r14,r15);
	r16 = hl_types_ArrayObj_alloc(r13);
	r18 = 0;
	if( r18 >= r11 ) goto label$9c0bd3a_1_85;
	if( r16 == NULL ) hl_null_access();
	r18 = 1;
	r15 = r11 - r18;
	r9 = NULL;
	r19 = (h3d__Buffer)hl_dyn_castp(&r9,&t$_dyn,&t$h3d_Buffer);
	r18 = r16->length;
	if( ((unsigned)r15) < ((unsigned)r18) ) goto label$9c0bd3a_1_83;
	hl_types_ArrayObj___expand(r16,r15);
	label$9c0bd3a_1_83:
	r13 = r16->array;
	((h3d__Buffer*)(r13 + 1))[r15] = r19;
	label$9c0bd3a_1_85:
	goto label$9c0bd3a_1_87;
	label$9c0bd3a_1_86:
	r16 = NULL;
	label$9c0bd3a_1_87:
	r0->buffers = r16;
	return;
}

void h3d_shader_ShaderBuffers_grow(h3d__shader__ShaderBuffers r0,hxsl__RuntimeShaderData r1) {
	hl__types__ArrayObj r13;
	hl_type *r15;
	hl__types__ArrayBytes_hl_F32 r8;
	float r12;
	h3d__Buffer r17;
	vdynamic *r11;
	h3d__mat__Texture r16;
	varray *r14;
	vbyte *r10;
	int r2, r3, r5, r6, r7, r9;
	if( r1 == NULL ) hl_null_access();
	r2 = r1->globalsSize;
	r3 = 2;
	r2 = r2 << r3;
	r3 = r1->paramsSize;
	r5 = 2;
	r3 = r3 << r5;
	r5 = r1->texturesCount;
	r6 = r1->bufferCount;
	r8 = r0->globals;
	if( r8 == NULL ) hl_null_access();
	r7 = r8->length;
	if( r7 >= r2 ) goto label$9c0bd3a_2_33;
	r7 = 0;
	r10 = hl_alloc_bytes(r7);
	r7 = 0;
	r7 = 0;
	r8 = hl_types_ArrayBase_allocF32(r10,r7);
	r9 = 0;
	if( r9 >= r2 ) goto label$9c0bd3a_2_32;
	if( r8 == NULL ) hl_null_access();
	r9 = 1;
	r7 = r2 - r9;
	r11 = NULL;
	r12 = (float)hl_dyn_castf(&r11,&t$_dyn);
	r9 = r8->length;
	if( ((unsigned)r7) < ((unsigned)r9) ) goto label$9c0bd3a_2_28;
	hl_types_ArrayBytes_hl_F32___expand(r8,r7);
	label$9c0bd3a_2_28:
	r10 = r8->bytes;
	r9 = 2;
	r9 = r7 << r9;
	*(float*)(r10 + r9) = r12;
	label$9c0bd3a_2_32:
	r0->globals = r8;
	label$9c0bd3a_2_33:
	r8 = r0->params;
	if( r8 == NULL ) hl_null_access();
	r7 = r8->length;
	if( r7 >= r3 ) goto label$9c0bd3a_2_57;
	r7 = 0;
	r10 = hl_alloc_bytes(r7);
	r7 = 0;
	r7 = 0;
	r8 = hl_types_ArrayBase_allocF32(r10,r7);
	r9 = 0;
	if( r9 >= r3 ) goto label$9c0bd3a_2_56;
	if( r8 == NULL ) hl_null_access();
	r9 = 1;
	r7 = r3 - r9;
	r11 = NULL;
	r12 = (float)hl_dyn_castf(&r11,&t$_dyn);
	r9 = r8->length;
	if( ((unsigned)r7) < ((unsigned)r9) ) goto label$9c0bd3a_2_52;
	hl_types_ArrayBytes_hl_F32___expand(r8,r7);
	label$9c0bd3a_2_52:
	r10 = r8->bytes;
	r9 = 2;
	r9 = r7 << r9;
	*(float*)(r10 + r9) = r12;
	label$9c0bd3a_2_56:
	r0->params = r8;
	label$9c0bd3a_2_57:
	r13 = r0->tex;
	if( r13 == NULL ) hl_null_access();
	r7 = r13->length;
	if( r7 >= r5 ) goto label$9c0bd3a_2_78;
	r15 = &t$h3d_mat_Texture;
	r7 = 0;
	r14 = hl_alloc_array(r15,r7);
	r13 = hl_types_ArrayObj_alloc(r14);
	r9 = 0;
	if( r9 >= r5 ) goto label$9c0bd3a_2_77;
	if( r13 == NULL ) hl_null_access();
	r9 = 1;
	r7 = r5 - r9;
	r11 = NULL;
	r16 = (h3d__mat__Texture)hl_dyn_castp(&r11,&t$_dyn,&t$h3d_mat_Texture);
	r9 = r13->length;
	if( ((unsigned)r7) < ((unsigned)r9) ) goto label$9c0bd3a_2_75;
	hl_types_ArrayObj___expand(r13,r7);
	label$9c0bd3a_2_75:
	r14 = r13->array;
	((h3d__mat__Texture*)(r14 + 1))[r7] = r16;
	label$9c0bd3a_2_77:
	r0->tex = r13;
	label$9c0bd3a_2_78:
	r9 = 0;
	if( r9 >= r6 ) goto label$9c0bd3a_2_103;
	r13 = r0->buffers;
	if( !r13 ) goto label$9c0bd3a_2_86;
	r13 = r0->buffers;
	if( r13 == NULL ) hl_null_access();
	r7 = r13->length;
	if( r7 >= r6 ) goto label$9c0bd3a_2_103;
	label$9c0bd3a_2_86:
	r15 = &t$h3d_Buffer;
	r7 = 0;
	r14 = hl_alloc_array(r15,r7);
	r13 = hl_types_ArrayObj_alloc(r14);
	r9 = 0;
	if( r9 >= r6 ) goto label$9c0bd3a_2_102;
	if( r13 == NULL ) hl_null_access();
	r9 = 1;
	r7 = r6 - r9;
	r11 = NULL;
	r17 = (h3d__Buffer)hl_dyn_castp(&r11,&t$_dyn,&t$h3d_Buffer);
	r9 = r13->length;
	if( ((unsigned)r7) < ((unsigned)r9) ) goto label$9c0bd3a_2_100;
	hl_types_ArrayObj___expand(r13,r7);
	label$9c0bd3a_2_100:
	r14 = r13->array;
	((h3d__Buffer*)(r14 + 1))[r7] = r17;
	label$9c0bd3a_2_102:
	r0->buffers = r13;
	label$9c0bd3a_2_103:
	return;
}

