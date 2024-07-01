﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/pass/Shadows.h>
void h3d_mat_Texture_dispose(h3d__mat__Texture);
#include <h3d/MatrixImpl.h>
#include <hl/types/ArrayObj.h>
#include <hxsl/Output.h>
#include <hxsl/Component.h>
#include <h3d/mat/Texture.h>
extern hl_type t$hxsl_Output;
#include <hl/natives.h>
extern String s$output_worldDist;
extern hl_type t$_i32;
extern hl_type t$hxsl_Component;
extern venum* g$hxsl_Component_X;
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern h3d__mat__$Texture g$_h3d_mat_Texture;
extern String s$output_depth;
h3d__mat__Texture h3d_mat_Texture_fromColor(int,vdynamic*);
extern String s$defaultShadowMap;
#include <h3d/pass/PassObject.h>
#include <h3d/mat/Pass.h>
bool h3d_mat_Texture_isDepth(h3d__mat__Texture);
#include <h3d/impl/Driver.h>
#include <h3d/Engine.h>
#include <h3d/shader/ScreenShader.h>
#include <h3d/shader/Blur.h>
extern venum* g$h3d_pass_ShadowSamplingKind_None;
extern venum* g$h3d_pass_RenderMode_None;
extern venum* g$hxd_PixelFormat_R16F;
extern h3d__$Engine g$_h3d_Engine;
extern String s$shadow;
void h3d_pass_Default_new(h3d__pass__Default,String);
extern hl_type t$h3d_pass_Blur;
void h3d_pass_Blur_new(h3d__pass__Blur,double*,double*,double*,double*);
double h3d_pass_Blur_set_quality(h3d__pass__Blur,double);

int h3d_pass_Shadows_set_size(h3d__pass__Shadows r0,int r1) {
	h3d__mat__Texture r4;
	int r3;
	r3 = r0->size;
	if( r1 == r3 ) goto label$d8c91af_1_9;
	r4 = r0->staticTexture;
	if( !r4 ) goto label$d8c91af_1_9;
	r4 = r0->staticTexture;
	if( r4 == NULL ) hl_null_access();
	h3d_mat_Texture_dispose(r4);
	r4 = NULL;
	r0->staticTexture = r4;
	label$d8c91af_1_9:
	r0->size = r1;
	return r1;
}

h3d__MatrixImpl h3d_pass_Shadows_getShadowProj(h3d__pass__Shadows r0) {
	h3d__Camera r2;
	h3d__MatrixImpl r1;
	r2 = r0->lightCamera;
	if( r2 == NULL ) hl_null_access();
	r1 = r2->m;
	return r1;
}

bool h3d_pass_Shadows_isUsingWorldDist(h3d__pass__Shadows r0) {
	bool r1;
	r1 = false;
	return r1;
}

hl__types__ArrayObj h3d_pass_Shadows_getOutputs(h3d__pass__Shadows r0) {
	String r7;
	hl__types__ArrayObj r2;
	venum *r6, *r10, *r11, *r12;
	hl_type *r4;
	bool r1;
	h3d__mat__$Texture r13;
	vdynamic *r8;
	int r5;
	varray *r3, *r9;
	r1 = h3d_pass_Shadows_isUsingWorldDist(r0);
	if( !r1 ) goto label$d8c91af_4_30;
	r4 = &t$hxsl_Output;
	r5 = 1;
	r3 = hl_alloc_array(r4,r5);
	r7 = (String)s$output_worldDist;
	r5 = 1;
	r8 = hl_alloc_dynamic(&t$_i32);
	r8->v.i = r5;
	r6 = hl_alloc_enum(&t$hxsl_Output,1);
	((hxsl_Output_Value*)r6)->p0 = r7;
	((hxsl_Output_Value*)r6)->p1 = r8;
	r4 = &t$hxsl_Component;
	r5 = 4;
	r9 = hl_alloc_array(r4,r5);
	r10 = (venum*)g$hxsl_Component_X;
	r5 = 0;
	((venum**)(r9 + 1))[r5] = r10;
	r10 = (venum*)g$hxsl_Component_X;
	r5 = 1;
	((venum**)(r9 + 1))[r5] = r10;
	r10 = (venum*)g$hxsl_Component_X;
	r5 = 2;
	((venum**)(r9 + 1))[r5] = r10;
	r10 = (venum*)g$hxsl_Component_X;
	r5 = 3;
	((venum**)(r9 + 1))[r5] = r10;
	r2 = hl_types_ArrayObj_alloc(r9);
	{ venum *tmp;
	tmp = hl_alloc_enum(&t$hxsl_Output,7);
	((hxsl_Output_Swiz*)tmp)->p0 = r6;
	((hxsl_Output_Swiz*)tmp)->p1 = r2;
	r6 = tmp; };
	r5 = 0;
	((venum**)(r3 + 1))[r5] = r6;
	r2 = hl_types_ArrayObj_alloc(r3);
	return r2;
	label$d8c91af_4_30:
	r11 = r0->format;
	r13 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r12 = r13->nativeFormat;
	if( r11 != r12 ) goto label$d8c91af_4_45;
	r4 = &t$hxsl_Output;
	r5 = 1;
	r3 = hl_alloc_array(r4,r5);
	r7 = (String)s$output_depth;
	r8 = NULL;
	r6 = hl_alloc_enum(&t$hxsl_Output,1);
	((hxsl_Output_Value*)r6)->p0 = r7;
	((hxsl_Output_Value*)r6)->p1 = r8;
	{ venum *tmp;
	tmp = hl_alloc_enum(&t$hxsl_Output,3);
	((hxsl_Output_PackFloat*)tmp)->p0 = r6;
	r6 = tmp; };
	r5 = 0;
	((venum**)(r3 + 1))[r5] = r6;
	r2 = hl_types_ArrayObj_alloc(r3);
	return r2;
	label$d8c91af_4_45:
	r4 = &t$hxsl_Output;
	r5 = 1;
	r3 = hl_alloc_array(r4,r5);
	r7 = (String)s$output_depth;
	r5 = 1;
	r8 = hl_alloc_dynamic(&t$_i32);
	r8->v.i = r5;
	r6 = hl_alloc_enum(&t$hxsl_Output,1);
	((hxsl_Output_Value*)r6)->p0 = r7;
	((hxsl_Output_Value*)r6)->p1 = r8;
	r4 = &t$hxsl_Component;
	r5 = 4;
	r9 = hl_alloc_array(r4,r5);
	r10 = (venum*)g$hxsl_Component_X;
	r5 = 0;
	((venum**)(r9 + 1))[r5] = r10;
	r10 = (venum*)g$hxsl_Component_X;
	r5 = 1;
	((venum**)(r9 + 1))[r5] = r10;
	r10 = (venum*)g$hxsl_Component_X;
	r5 = 2;
	((venum**)(r9 + 1))[r5] = r10;
	r10 = (venum*)g$hxsl_Component_X;
	r5 = 3;
	((venum**)(r9 + 1))[r5] = r10;
	r2 = hl_types_ArrayObj_alloc(r9);
	{ venum *tmp;
	tmp = hl_alloc_enum(&t$hxsl_Output,7);
	((hxsl_Output_Swiz*)tmp)->p0 = r6;
	((hxsl_Output_Swiz*)tmp)->p1 = r2;
	r6 = tmp; };
	r5 = 0;
	((venum**)(r3 + 1))[r5] = r6;
	r2 = hl_types_ArrayObj_alloc(r3);
	return r2;
}

h3d__mat__Texture h3d_pass_Shadows_createDefaultShadowMap(h3d__pass__Shadows r0) {
	String r4;
	vdynamic *r3;
	int r2;
	h3d__mat__Texture r1;
	r2 = 16777215;
	r3 = NULL;
	r1 = h3d_mat_Texture_fromColor(r2,r3);
	if( r1 == NULL ) hl_null_access();
	r4 = (String)s$defaultShadowMap;
	r1->name = r4;
	return r1;
}

void h3d_pass_Shadows_syncShader(h3d__pass__Shadows r0,h3d__mat__Texture r1) {
	return;
}

bool h3d_pass_Shadows_filterPasses(h3d__pass__Shadows r0,h3d__pass__PassList r1) {
	vvirtual *r9, *r10;
	venum *r6;
	bool r3, r8, r19;
	h3d__mat__Pass r18;
	h3d__pass__PassObject r12, r13, r14, r15, r16, r17, r20;
	vclosure *r11;
	h3d__scene__RenderContext r4;
	h3d__mat__Texture r7;
	int r5;
	r4 = r0->ctx;
	if( r4 == NULL ) hl_null_access();
	r3 = r4->computingStatic;
	if( r3 ) goto label$d8c91af_7_114;
	r6 = r0->mode;
	if( r6 == NULL ) hl_null_access();
	r5 = HL__ENUM_INDEX__(r6);
	switch(r5) {
		default:
			goto label$d8c91af_7_113;
		case 0:
			r3 = false;
			return r3;
		case 1:
			r7 = r0->staticTexture;
			if( !r7 ) goto label$d8c91af_7_32;
			r7 = r0->staticTexture;
			if( r7 == NULL ) hl_null_access();
			r8 = h3d_mat_Texture_isDepth(r7);
			if( !r8 ) goto label$d8c91af_7_24;
			r9 = r7->_hx_t;
			r10 = NULL;
			if( r9 == r10 || (r9 && r10 && r9->value && r10->value && r9->value == r10->value) ) goto label$d8c91af_7_22;
			r8 = false;
			goto label$d8c91af_7_23;
			label$d8c91af_7_22:
			r8 = true;
			label$d8c91af_7_23:
			goto label$d8c91af_7_31;
			label$d8c91af_7_24:
			r9 = r7->_hx_t;
			if( r9 ) goto label$d8c91af_7_30;
			r11 = r7->realloc;
			if( r11 ) goto label$d8c91af_7_30;
			r8 = true;
			goto label$d8c91af_7_31;
			label$d8c91af_7_30:
			r8 = false;
			label$d8c91af_7_31:
			goto label$d8c91af_7_33;
			label$d8c91af_7_32:
			r8 = true;
			label$d8c91af_7_33:
			if( !r8 ) goto label$d8c91af_7_36;
			r7 = h3d_pass_Shadows_createDefaultShadowMap(r0);
			r0->staticTexture = r7;
			label$d8c91af_7_36:
			r7 = r0->staticTexture;
			((void (*)(h3d__pass__Shadows,h3d__mat__Texture))r0->$type->vobj_proto[4])(r0,r7);
			r8 = false;
			return r8;
		case 2:
			r3 = true;
			return r3;
		case 3:
			r7 = r0->staticTexture;
			if( !r7 ) goto label$d8c91af_7_63;
			r7 = r0->staticTexture;
			if( r7 == NULL ) hl_null_access();
			r8 = h3d_mat_Texture_isDepth(r7);
			if( !r8 ) goto label$d8c91af_7_55;
			r9 = r7->_hx_t;
			r10 = NULL;
			if( r9 == r10 || (r9 && r10 && r9->value && r10->value && r9->value == r10->value) ) goto label$d8c91af_7_53;
			r8 = false;
			goto label$d8c91af_7_54;
			label$d8c91af_7_53:
			r8 = true;
			label$d8c91af_7_54:
			goto label$d8c91af_7_62;
			label$d8c91af_7_55:
			r9 = r7->_hx_t;
			if( r9 ) goto label$d8c91af_7_61;
			r11 = r7->realloc;
			if( r11 ) goto label$d8c91af_7_61;
			r8 = true;
			goto label$d8c91af_7_62;
			label$d8c91af_7_61:
			r8 = false;
			label$d8c91af_7_62:
			goto label$d8c91af_7_64;
			label$d8c91af_7_63:
			r8 = true;
			label$d8c91af_7_64:
			if( !r8 ) goto label$d8c91af_7_67;
			r7 = h3d_pass_Shadows_createDefaultShadowMap(r0);
			r0->staticTexture = r7;
			label$d8c91af_7_67:
			r12 = NULL;
			r13 = NULL;
			if( r1 == NULL ) hl_null_access();
			r14 = r1->discarded;
			r15 = r1->lastDisc;
			r16 = r1->current;
			label$d8c91af_7_73:
			if( !r16 ) goto label$d8c91af_7_99;
			if( r16 == NULL ) hl_null_access();
			r18 = r16->pass;
			if( r18 == NULL ) hl_null_access();
			r8 = r18->isStatic;
			r19 = false;
			if( r8 != r19 ) goto label$d8c91af_7_89;
			if( r12 ) goto label$d8c91af_7_85;
			r13 = r16;
			r12 = r16;
			goto label$d8c91af_7_88;
			label$d8c91af_7_85:
			if( r13 == NULL ) hl_null_access();
			r13->next = r16;
			r13 = r16;
			label$d8c91af_7_88:
			goto label$d8c91af_7_96;
			label$d8c91af_7_89:
			if( r14 ) goto label$d8c91af_7_93;
			r15 = r16;
			r14 = r16;
			goto label$d8c91af_7_96;
			label$d8c91af_7_93:
			if( r15 == NULL ) hl_null_access();
			r15->next = r16;
			r15 = r16;
			label$d8c91af_7_96:
			r17 = r16->next;
			r16 = r17;
			goto label$d8c91af_7_73;
			label$d8c91af_7_99:
			if( !r13 ) goto label$d8c91af_7_103;
			if( r13 == NULL ) hl_null_access();
			r20 = NULL;
			r13->next = r20;
			label$d8c91af_7_103:
			if( !r15 ) goto label$d8c91af_7_107;
			if( r15 == NULL ) hl_null_access();
			r20 = NULL;
			r15->next = r20;
			label$d8c91af_7_107:
			if( r1 == NULL ) hl_null_access();
			r1->current = r12;
			r1->discarded = r14;
			r1->lastDisc = r15;
			r8 = true;
			return r8;
	}
	label$d8c91af_7_113:
	goto label$d8c91af_7_215;
	label$d8c91af_7_114:
	r6 = r0->mode;
	if( r6 == NULL ) hl_null_access();
	r5 = HL__ENUM_INDEX__(r6);
	switch(r5) {
		default:
			goto label$d8c91af_7_215;
		case 0:
			r3 = false;
			return r3;
		case 1:
			r12 = NULL;
			r13 = NULL;
			if( r1 == NULL ) hl_null_access();
			r14 = r1->discarded;
			r15 = r1->lastDisc;
			r16 = r1->current;
			label$d8c91af_7_127:
			if( !r16 ) goto label$d8c91af_7_153;
			if( r16 == NULL ) hl_null_access();
			r18 = r16->pass;
			if( r18 == NULL ) hl_null_access();
			r3 = r18->isStatic;
			r8 = true;
			if( r3 != r8 ) goto label$d8c91af_7_143;
			if( r12 ) goto label$d8c91af_7_139;
			r13 = r16;
			r12 = r16;
			goto label$d8c91af_7_142;
			label$d8c91af_7_139:
			if( r13 == NULL ) hl_null_access();
			r13->next = r16;
			r13 = r16;
			label$d8c91af_7_142:
			goto label$d8c91af_7_150;
			label$d8c91af_7_143:
			if( r14 ) goto label$d8c91af_7_147;
			r15 = r16;
			r14 = r16;
			goto label$d8c91af_7_150;
			label$d8c91af_7_147:
			if( r15 == NULL ) hl_null_access();
			r15->next = r16;
			r15 = r16;
			label$d8c91af_7_150:
			r17 = r16->next;
			r16 = r17;
			goto label$d8c91af_7_127;
			label$d8c91af_7_153:
			if( !r13 ) goto label$d8c91af_7_157;
			if( r13 == NULL ) hl_null_access();
			r20 = NULL;
			r13->next = r20;
			label$d8c91af_7_157:
			if( !r15 ) goto label$d8c91af_7_161;
			if( r15 == NULL ) hl_null_access();
			r20 = NULL;
			r15->next = r20;
			label$d8c91af_7_161:
			if( r1 == NULL ) hl_null_access();
			r1->current = r12;
			r1->discarded = r14;
			r1->lastDisc = r15;
			r3 = true;
			return r3;
		case 2:
			r3 = false;
			return r3;
		case 3:
			r12 = NULL;
			r13 = NULL;
			if( r1 == NULL ) hl_null_access();
			r14 = r1->discarded;
			r15 = r1->lastDisc;
			r16 = r1->current;
			label$d8c91af_7_175:
			if( !r16 ) goto label$d8c91af_7_201;
			if( r16 == NULL ) hl_null_access();
			r18 = r16->pass;
			if( r18 == NULL ) hl_null_access();
			r3 = r18->isStatic;
			r8 = true;
			if( r3 != r8 ) goto label$d8c91af_7_191;
			if( r12 ) goto label$d8c91af_7_187;
			r13 = r16;
			r12 = r16;
			goto label$d8c91af_7_190;
			label$d8c91af_7_187:
			if( r13 == NULL ) hl_null_access();
			r13->next = r16;
			r13 = r16;
			label$d8c91af_7_190:
			goto label$d8c91af_7_198;
			label$d8c91af_7_191:
			if( r14 ) goto label$d8c91af_7_195;
			r15 = r16;
			r14 = r16;
			goto label$d8c91af_7_198;
			label$d8c91af_7_195:
			if( r15 == NULL ) hl_null_access();
			r15->next = r16;
			r15 = r16;
			label$d8c91af_7_198:
			r17 = r16->next;
			r16 = r17;
			goto label$d8c91af_7_175;
			label$d8c91af_7_201:
			if( !r13 ) goto label$d8c91af_7_205;
			if( r13 == NULL ) hl_null_access();
			r20 = NULL;
			r13->next = r20;
			label$d8c91af_7_205:
			if( !r15 ) goto label$d8c91af_7_209;
			if( r15 == NULL ) hl_null_access();
			r20 = NULL;
			r15->next = r20;
			label$d8c91af_7_209:
			if( r1 == NULL ) hl_null_access();
			r1->current = r12;
			r1->discarded = r14;
			r1->lastDisc = r15;
			r3 = true;
			return r3;
	}
	label$d8c91af_7_215:
	r3 = false;
	return r3;
}

void h3d_pass_Shadows_new(h3d__pass__Shadows r0,h3d__scene__Light r1) {
	String r13;
	h3d__shader__ScreenShader r20;
	venum *r4, *r5, *r8, *r22;
	bool r6;
	h3d__mat__$Texture r12;
	h3d__Engine r10;
	h3d__$Engine r11;
	h3d__shader__Blur r21;
	h3d__pass__Blur r14;
	double r2, r19;
	double *r15, *r16, *r17, *r18;
	h3d__impl__Driver r9;
	int r3;
	r2 = 1.;
	r0->pcfScale = r2;
	r3 = 1;
	r0->pcfQuality = r3;
	r2 = 0.01000000000000000021;
	r0->bias = r2;
	r2 = 30.;
	r0->power = r2;
	r4 = (venum*)g$h3d_pass_ShadowSamplingKind_None;
	r0->samplingKind = r4;
	r3 = 1024;
	r0->size = r3;
	r5 = (venum*)g$h3d_pass_RenderMode_None;
	r0->mode = r5;
	r6 = true;
	r0->enabled = r6;
	r8 = r0->format;
	if( r8 ) goto label$d8c91af_8_20;
	r8 = (venum*)g$hxd_PixelFormat_R16F;
	r0->format = r8;
	label$d8c91af_8_20:
	r11 = (h3d__$Engine)g$_h3d_Engine;
	r10 = r11->CURRENT;
	if( r10 == NULL ) hl_null_access();
	r9 = r10->driver;
	if( r9 == NULL ) hl_null_access();
	r8 = r0->format;
	r6 = ((bool (*)(h3d__impl__Driver,venum*))r9->$type->vobj_proto[2])(r9,r8);
	if( r6 ) goto label$d8c91af_8_31;
	r12 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r8 = r12->nativeFormat;
	r0->format = r8;
	label$d8c91af_8_31:
	r13 = (String)s$shadow;
	h3d_pass_Default_new(((h3d__pass__Default)r0),r13);
	r0->light = r1;
	r14 = (h3d__pass__Blur)hl_alloc_obj(&t$h3d_pass_Blur);
	r3 = 5;
	r2 = (double)r3;
	r15 = &r2;
	r16 = NULL;
	r17 = NULL;
	r18 = NULL;
	h3d_pass_Blur_new(r14,r15,r16,r17,r18);
	r0->blur = r14;
	r14 = r0->blur;
	if( r14 == NULL ) hl_null_access();
	r19 = 0.5;
	r19 = h3d_pass_Blur_set_quality(r14,r19);
	r14 = r0->blur;
	if( r14 == NULL ) hl_null_access();
	r20 = r14->shader;
	r21 = (h3d__shader__Blur)r20;
	if( r21 == NULL ) hl_null_access();
	r6 = true;
	r21->constModified = r6;
	r8 = r0->format;
	r12 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r22 = r12->nativeFormat;
	if( r8 == r22 ) goto label$d8c91af_8_60;
	r6 = false;
	goto label$d8c91af_8_61;
	label$d8c91af_8_60:
	r6 = true;
	label$d8c91af_8_61:
	r21->isDepth__ = r6;
	return;
}

