﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/scene/fwd/LightSystem.h>
#include <h3d/shader/AmbientLight.h>
extern h3d__shader__$AmbientLight g$_h3d_shader_AmbientLight;
bool hl_BaseType_check(hl__BaseType,vdynamic*);
#include <h3d/scene/fwd/Light.h>
void h3d_scene_fwd_LightSystem_cullLights(h3d__scene__fwd__LightSystem);
void h3d_scene_LightSystem_initLights(h3d__scene__LightSystem,h3d__scene__RenderContext);
int h3d_scene_fwd_LightSystem_sortLight(h3d__scene__fwd__LightSystem,h3d__scene__fwd__Light,h3d__scene__fwd__Light);
extern hl_type t$fun_d385426;
int wrapt$fun_395cfec(vclosure*,h3d__scene__Light,h3d__scene__Light);
extern hl_type t$fun_395cfec;
#include <hxsl/Globals.h>
extern String s$global_ambientLight;
void hxsl_Globals_set(hxsl__Globals,String,vdynamic*);
extern String s$global_perPixelLighting;
#include <h3d/col/Sphere.h>
#include <h3d/MatrixImpl.h>
#include <h3d/col/Frustum.h>
#include <h3d/Camera.h>
extern hl_type t$h3d_col_Sphere;
void h3d_col_Sphere_new(h3d__col__Sphere,double*,double*,double*,double*);
extern h3d__scene__fwd__$Light g$_h3d_scene_fwd_Light;
bool h3d_col_Frustum_hasSphere(h3d__col__Frustum,h3d__col__Sphere);
#include <h3d/scene/Object.h>
#include <hxsl/ShaderList.h>
hxsl__ShaderList h3d_scene_RenderContext_allocShaderList(h3d__scene__RenderContext,hxsl__Shader,hxsl__ShaderList);
void h3d_scene_LightSystem_new(h3d__scene__LightSystem);
extern hl_type t$h3d_VectorImpl;
void h3d_VectorImpl_new(h3d__VectorImpl,double*,double*,double*);
extern hl_type t$h3d_shader_AmbientLight;
void h3d_shader_AmbientLight_new(h3d__shader__AmbientLight);

bool h3d_scene_fwd_LightSystem_set_additiveLighting(h3d__scene__fwd__LightSystem r0,bool r1) {
	bool r5;
	h3d__shader__AmbientLight r4;
	h3d__shader__$AmbientLight r3;
	hxsl__Shader r2;
	r2 = r0->ambientShader;
	r3 = (h3d__shader__$AmbientLight)g$_h3d_shader_AmbientLight;
	r5 = hl_BaseType_check(((hl__BaseType)r3),((vdynamic*)r2));
	if( !r5 ) goto label$3b7f60a_1_6;
	r4 = (h3d__shader__AmbientLight)r2;
	goto label$3b7f60a_1_7;
	label$3b7f60a_1_6:
	r4 = NULL;
	label$3b7f60a_1_7:
	if( r4 == NULL ) hl_null_access();
	r5 = true;
	r4->constModified = r5;
	r4->additive__ = r1;
	return r1;
}

void h3d_scene_fwd_LightSystem_initLights(h3d__scene__fwd__LightSystem r0,h3d__scene__RenderContext r1) {
	bool r11;
	h3d__scene__Light r5, r8, r9, r12, r13, r16, r18, r19;
	vclosure *r6, *r7;
	int r2, r4, r10, r14, r15, r17;
	r2 = 0;
	r0->lightCount = r2;
	r0->ctx = r1;
	h3d_scene_fwd_LightSystem_cullLights(r0);
	h3d_scene_LightSystem_initLights(((h3d__scene__LightSystem)r0),r1);
	r2 = r0->lightCount;
	r4 = r0->maxLightsPerObject;
	if( r4 < r2 ) goto label$3b7f60a_2_105;
	if( r1 == NULL ) hl_null_access();
	r5 = r1->lights;
	r6 = hl_alloc_closure_ptr(&t$fun_d385426,h3d_scene_fwd_LightSystem_sortLight,r0);
	if( r6 ) goto label$3b7f60a_2_14;
	r7 = NULL;
	goto label$3b7f60a_2_15;
	label$3b7f60a_2_14:
	r7 = hl_alloc_closure_ptr(&t$fun_395cfec,wrapt$fun_395cfec,r6);
	label$3b7f60a_2_15:
	if( r5 ) goto label$3b7f60a_2_19;
	r9 = NULL;
	r8 = r9;
	goto label$3b7f60a_2_103;
	label$3b7f60a_2_19:
	r2 = 1;
	r4 = 0;
	r10 = 0;
	label$3b7f60a_2_22:
	r11 = true;
	if( !r11 ) goto label$3b7f60a_2_102;
	r9 = r5;
	r12 = NULL;
	r5 = r12;
	r13 = NULL;
	r12 = r13;
	r15 = 0;
	r14 = r15;
	label$3b7f60a_2_32:
	if( !r9 ) goto label$3b7f60a_2_92;
	++r14;
	r13 = r9;
	r15 = 0;
	r4 = r15;
	r15 = 0;
	r17 = r2;
	label$3b7f60a_2_40:
	if( r15 >= r17 ) goto label$3b7f60a_2_50;
	++r15;
	++r4;
	if( r13 == NULL ) hl_null_access();
	r16 = r13->next;
	r13 = r16;
	if( r16 ) goto label$3b7f60a_2_49;
	goto label$3b7f60a_2_50;
	label$3b7f60a_2_49:
	goto label$3b7f60a_2_40;
	label$3b7f60a_2_50:
	r10 = r2;
	label$3b7f60a_2_51:
	r17 = 0;
	if( r17 < r4 ) goto label$3b7f60a_2_57;
	r17 = 0;
	if( r17 >= r10 ) goto label$3b7f60a_2_90;
	if( !r13 ) goto label$3b7f60a_2_90;
	label$3b7f60a_2_57:
	r17 = 0;
	if( r4 != r17 ) goto label$3b7f60a_2_65;
	r16 = r13;
	if( r13 == NULL ) hl_null_access();
	r18 = r13->next;
	r13 = r18;
	--r10;
	goto label$3b7f60a_2_83;
	label$3b7f60a_2_65:
	r17 = 0;
	if( r10 == r17 ) goto label$3b7f60a_2_72;
	if( !r13 ) goto label$3b7f60a_2_72;
	if( r7 == NULL ) hl_null_access();
	r15 = r7->hasValue ? ((int (*)(vdynamic*,h3d__scene__Light,h3d__scene__Light))r7->fun)((vdynamic*)r7->value,r9,r13) : ((int (*)(h3d__scene__Light,h3d__scene__Light))r7->fun)(r9,r13);
	r17 = 0;
	if( r17 < r15 ) goto label$3b7f60a_2_78;
	label$3b7f60a_2_72:
	r16 = r9;
	if( r9 == NULL ) hl_null_access();
	r18 = r9->next;
	r9 = r18;
	--r4;
	goto label$3b7f60a_2_83;
	label$3b7f60a_2_78:
	r16 = r13;
	if( r13 == NULL ) hl_null_access();
	r18 = r13->next;
	r13 = r18;
	--r10;
	label$3b7f60a_2_83:
	if( !r12 ) goto label$3b7f60a_2_87;
	if( r12 == NULL ) hl_null_access();
	r12->next = r16;
	goto label$3b7f60a_2_88;
	label$3b7f60a_2_87:
	r5 = r16;
	label$3b7f60a_2_88:
	r12 = r16;
	goto label$3b7f60a_2_51;
	label$3b7f60a_2_90:
	r9 = r13;
	goto label$3b7f60a_2_32;
	label$3b7f60a_2_92:
	if( r12 == NULL ) hl_null_access();
	r19 = NULL;
	r12->next = r19;
	r17 = 1;
	if( r17 < r14 ) goto label$3b7f60a_2_98;
	goto label$3b7f60a_2_102;
	label$3b7f60a_2_98:
	r17 = 2;
	r15 = r2 * r17;
	r2 = r15;
	goto label$3b7f60a_2_22;
	label$3b7f60a_2_102:
	r8 = r5;
	label$3b7f60a_2_103:
	if( r1 == NULL ) hl_null_access();
	r1->lights = r8;
	label$3b7f60a_2_105:
	return;
}

void h3d_scene_fwd_LightSystem_initGlobals(h3d__scene__fwd__LightSystem r0,hxsl__Globals r1) {
	h3d__VectorImpl r4;
	String r3;
	bool r5;
	vdynamic *r6;
	if( r1 == NULL ) hl_null_access();
	r3 = (String)s$global_ambientLight;
	r4 = r0->ambientLight;
	hxsl_Globals_set(r1,r3,((vdynamic*)r4));
	r3 = (String)s$global_perPixelLighting;
	r5 = r0->perPixelLighting;
	r6 = hl_alloc_dynbool(r5);
	hxsl_Globals_set(r1,r3,r6);
	return;
}

void h3d_scene_fwd_LightSystem_cullLights(h3d__scene__fwd__LightSystem r0) {
	bool r13;
	h3d__col__Frustum r17;
	h3d__scene__fwd__Light r12;
	h3d__Camera r18;
	h3d__scene__fwd__$Light r11;
	h3d__col__Sphere r5;
	h3d__scene__Light r1, r4, r10, r19;
	double r14, r16;
	h3d__MatrixImpl r15;
	double *r6, *r7, *r8, *r9;
	h3d__scene__RenderContext r2;
	int r20;
	r2 = r0->ctx;
	if( r2 == NULL ) hl_null_access();
	r1 = r2->lights;
	r4 = NULL;
	r5 = (h3d__col__Sphere)hl_alloc_obj(&t$h3d_col_Sphere);
	r6 = NULL;
	r7 = NULL;
	r8 = NULL;
	r9 = NULL;
	h3d_col_Sphere_new(r5,r6,r7,r8,r9);
	label$3b7f60a_4_10:
	if( !r1 ) goto label$3b7f60a_4_76;
	r11 = (h3d__scene__fwd__$Light)g$_h3d_scene_fwd_Light;
	r13 = hl_BaseType_check(((hl__BaseType)r11),((vdynamic*)r1));
	if( !r13 ) goto label$3b7f60a_4_17;
	r12 = (h3d__scene__fwd__Light)r1;
	goto label$3b7f60a_4_18;
	label$3b7f60a_4_17:
	r12 = NULL;
	label$3b7f60a_4_18:
	if( !r12 ) goto label$3b7f60a_4_35;
	if( r5 == NULL ) hl_null_access();
	if( r12 == NULL ) hl_null_access();
	r15 = r12->absPos;
	if( r15 == NULL ) hl_null_access();
	r14 = r15->_41;
	r5->x = r14;
	r15 = r12->absPos;
	if( r15 == NULL ) hl_null_access();
	r14 = r15->_42;
	r5->y = r14;
	r15 = r12->absPos;
	if( r15 == NULL ) hl_null_access();
	r14 = r15->_43;
	r5->z = r14;
	r14 = r12->cullingDistance;
	r5->r = r14;
	label$3b7f60a_4_35:
	if( !r12 ) goto label$3b7f60a_4_52;
	if( r12 == NULL ) hl_null_access();
	r14 = r12->cullingDistance;
	r16 = 0.;
	if( !(r16 < r14) ) goto label$3b7f60a_4_66;
	r2 = r0->ctx;
	if( r2 == NULL ) hl_null_access();
	r13 = r2->computingStatic;
	if( r13 ) goto label$3b7f60a_4_66;
	r2 = r0->ctx;
	if( r2 == NULL ) hl_null_access();
	r18 = r2->camera;
	if( r18 == NULL ) hl_null_access();
	r17 = r18->frustum;
	if( r17 == NULL ) hl_null_access();
	r13 = h3d_col_Frustum_hasSphere(r17,r5);
	if( r13 ) goto label$3b7f60a_4_66;
	label$3b7f60a_4_52:
	if( r4 ) goto label$3b7f60a_4_59;
	r2 = r0->ctx;
	if( r2 == NULL ) hl_null_access();
	if( r1 == NULL ) hl_null_access();
	r10 = r1->next;
	r2->lights = r10;
	goto label$3b7f60a_4_63;
	label$3b7f60a_4_59:
	if( r4 == NULL ) hl_null_access();
	if( r1 == NULL ) hl_null_access();
	r19 = r1->next;
	r4->next = r19;
	label$3b7f60a_4_63:
	r10 = r1->next;
	r1 = r10;
	goto label$3b7f60a_4_10;
	label$3b7f60a_4_66:
	r20 = r0->lightCount;
	++r20;
	r0->lightCount = r20;
	r14 = 0.;
	r12->objectDistance = r14;
	r4 = r1;
	if( r1 == NULL ) hl_null_access();
	r10 = r1->next;
	r1 = r10;
	goto label$3b7f60a_4_10;
	label$3b7f60a_4_76:
	return;
}

int h3d_scene_fwd_LightSystem_sortLight(h3d__scene__fwd__LightSystem r0,h3d__scene__fwd__Light r1,h3d__scene__fwd__Light r2) {
	double r6, r7;
	int r3, r4, r5;
	if( r1 == NULL ) hl_null_access();
	r3 = r1->priority;
	if( r2 == NULL ) hl_null_access();
	r4 = r2->priority;
	r3 = r3 - r4;
	r5 = 0;
	if( r3 == r5 ) goto label$3b7f60a_5_9;
	r4 = -r3;
	return r4;
	label$3b7f60a_5_9:
	r6 = r1->objectDistance;
	r7 = r2->objectDistance;
	if( !(r6 < r7) ) goto label$3b7f60a_5_14;
	r4 = -1;
	return r4;
	label$3b7f60a_5_14:
	r4 = 1;
	return r4;
}

hxsl__ShaderList h3d_scene_fwd_LightSystem_computeLight(h3d__scene__fwd__LightSystem r0,h3d__scene__Object r1,hxsl__ShaderList r2) {
	h3d__VectorImpl r15;
	bool r11;
	h3d__scene__fwd__Light r10;
	hxsl__Shader r34;
	h3d__Camera r16;
	h3d__scene__fwd__$Light r9;
	hxsl__ShaderList r33;
	h3d__scene__Light r6, r8, r22, r23, r25, r26, r29, r31, r32;
	vclosure *r20, *r21;
	double r12, r14, r17, r18, r19;
	h3d__MatrixImpl r13;
	h3d__scene__RenderContext r7;
	int r4, r5, r24, r27, r28, r30;
	h3d__scene__fwd__LightSystem r3;
	r3 = r0;
	r4 = r0->lightCount;
	r5 = r0->maxLightsPerObject;
	if( r5 >= r4 ) goto label$3b7f60a_6_193;
	r7 = r0->ctx;
	if( r7 == NULL ) hl_null_access();
	r6 = r7->lights;
	label$3b7f60a_6_7:
	if( !r6 ) goto label$3b7f60a_6_94;
	r9 = (h3d__scene__fwd__$Light)g$_h3d_scene_fwd_Light;
	r11 = hl_BaseType_check(((hl__BaseType)r9),((vdynamic*)r6));
	if( !r11 ) goto label$3b7f60a_6_14;
	r10 = (h3d__scene__fwd__Light)r6;
	goto label$3b7f60a_6_15;
	label$3b7f60a_6_14:
	r10 = NULL;
	label$3b7f60a_6_15:
	if( r1 == NULL ) hl_null_access();
	r4 = r1->flags;
	r5 = 16;
	r4 = r4 & r5;
	r5 = 0;
	if( r4 == r5 ) goto label$3b7f60a_6_62;
	if( r10 == NULL ) hl_null_access();
	r13 = r10->absPos;
	if( r13 == NULL ) hl_null_access();
	r12 = r13->_41;
	r7 = r0->ctx;
	if( r7 == NULL ) hl_null_access();
	r16 = r7->camera;
	if( r16 == NULL ) hl_null_access();
	r15 = r16->target;
	if( r15 == NULL ) hl_null_access();
	r14 = r15->x;
	r12 = r12 - r14;
	r13 = r10->absPos;
	if( r13 == NULL ) hl_null_access();
	r14 = r13->_42;
	r7 = r0->ctx;
	if( r7 == NULL ) hl_null_access();
	r16 = r7->camera;
	if( r16 == NULL ) hl_null_access();
	r15 = r16->target;
	if( r15 == NULL ) hl_null_access();
	r17 = r15->y;
	r14 = r14 - r17;
	r13 = r10->absPos;
	if( r13 == NULL ) hl_null_access();
	r17 = r13->_43;
	r7 = r0->ctx;
	if( r7 == NULL ) hl_null_access();
	r16 = r7->camera;
	if( r16 == NULL ) hl_null_access();
	r15 = r16->target;
	if( r15 == NULL ) hl_null_access();
	r18 = r15->z;
	r17 = r17 - r18;
	r18 = r12 * r12;
	r19 = r14 * r14;
	r18 = r18 + r19;
	r19 = r17 * r17;
	r18 = r18 + r19;
	r10->objectDistance = r18;
	goto label$3b7f60a_6_90;
	label$3b7f60a_6_62:
	if( r10 == NULL ) hl_null_access();
	r13 = r10->absPos;
	if( r13 == NULL ) hl_null_access();
	r12 = r13->_41;
	r13 = r1->absPos;
	if( r13 == NULL ) hl_null_access();
	r14 = r13->_41;
	r12 = r12 - r14;
	r13 = r10->absPos;
	if( r13 == NULL ) hl_null_access();
	r14 = r13->_42;
	r13 = r1->absPos;
	if( r13 == NULL ) hl_null_access();
	r17 = r13->_42;
	r14 = r14 - r17;
	r13 = r10->absPos;
	if( r13 == NULL ) hl_null_access();
	r17 = r13->_43;
	r13 = r1->absPos;
	if( r13 == NULL ) hl_null_access();
	r18 = r13->_43;
	r17 = r17 - r18;
	r18 = r12 * r12;
	r19 = r14 * r14;
	r18 = r18 + r19;
	r19 = r17 * r17;
	r18 = r18 + r19;
	r10->objectDistance = r18;
	label$3b7f60a_6_90:
	if( r6 == NULL ) hl_null_access();
	r8 = r6->next;
	r6 = r8;
	goto label$3b7f60a_6_7;
	label$3b7f60a_6_94:
	r7 = r0->ctx;
	if( r7 == NULL ) hl_null_access();
	r8 = r7->lights;
	r20 = hl_alloc_closure_ptr(&t$fun_d385426,h3d_scene_fwd_LightSystem_sortLight,r0);
	if( r20 ) goto label$3b7f60a_6_101;
	r21 = NULL;
	goto label$3b7f60a_6_102;
	label$3b7f60a_6_101:
	r21 = hl_alloc_closure_ptr(&t$fun_395cfec,wrapt$fun_395cfec,r20);
	label$3b7f60a_6_102:
	if( r8 ) goto label$3b7f60a_6_106;
	r23 = NULL;
	r22 = r23;
	goto label$3b7f60a_6_190;
	label$3b7f60a_6_106:
	r4 = 1;
	r5 = 0;
	r24 = 0;
	label$3b7f60a_6_109:
	r11 = true;
	if( !r11 ) goto label$3b7f60a_6_189;
	r23 = r8;
	r25 = NULL;
	r8 = r25;
	r26 = NULL;
	r25 = r26;
	r28 = 0;
	r27 = r28;
	label$3b7f60a_6_119:
	if( !r23 ) goto label$3b7f60a_6_179;
	++r27;
	r26 = r23;
	r28 = 0;
	r5 = r28;
	r28 = 0;
	r30 = r4;
	label$3b7f60a_6_127:
	if( r28 >= r30 ) goto label$3b7f60a_6_137;
	++r28;
	++r5;
	if( r26 == NULL ) hl_null_access();
	r29 = r26->next;
	r26 = r29;
	if( r29 ) goto label$3b7f60a_6_136;
	goto label$3b7f60a_6_137;
	label$3b7f60a_6_136:
	goto label$3b7f60a_6_127;
	label$3b7f60a_6_137:
	r24 = r4;
	label$3b7f60a_6_138:
	r30 = 0;
	if( r30 < r5 ) goto label$3b7f60a_6_144;
	r30 = 0;
	if( r30 >= r24 ) goto label$3b7f60a_6_177;
	if( !r26 ) goto label$3b7f60a_6_177;
	label$3b7f60a_6_144:
	r30 = 0;
	if( r5 != r30 ) goto label$3b7f60a_6_152;
	r29 = r26;
	if( r26 == NULL ) hl_null_access();
	r31 = r26->next;
	r26 = r31;
	--r24;
	goto label$3b7f60a_6_170;
	label$3b7f60a_6_152:
	r30 = 0;
	if( r24 == r30 ) goto label$3b7f60a_6_159;
	if( !r26 ) goto label$3b7f60a_6_159;
	if( r21 == NULL ) hl_null_access();
	r28 = r21->hasValue ? ((int (*)(vdynamic*,h3d__scene__Light,h3d__scene__Light))r21->fun)((vdynamic*)r21->value,r23,r26) : ((int (*)(h3d__scene__Light,h3d__scene__Light))r21->fun)(r23,r26);
	r30 = 0;
	if( r30 < r28 ) goto label$3b7f60a_6_165;
	label$3b7f60a_6_159:
	r29 = r23;
	if( r23 == NULL ) hl_null_access();
	r31 = r23->next;
	r23 = r31;
	--r5;
	goto label$3b7f60a_6_170;
	label$3b7f60a_6_165:
	r29 = r26;
	if( r26 == NULL ) hl_null_access();
	r31 = r26->next;
	r26 = r31;
	--r24;
	label$3b7f60a_6_170:
	if( !r25 ) goto label$3b7f60a_6_174;
	if( r25 == NULL ) hl_null_access();
	r25->next = r29;
	goto label$3b7f60a_6_175;
	label$3b7f60a_6_174:
	r8 = r29;
	label$3b7f60a_6_175:
	r25 = r29;
	goto label$3b7f60a_6_138;
	label$3b7f60a_6_177:
	r23 = r26;
	goto label$3b7f60a_6_119;
	label$3b7f60a_6_179:
	if( r25 == NULL ) hl_null_access();
	r32 = NULL;
	r25->next = r32;
	r30 = 1;
	if( r30 < r27 ) goto label$3b7f60a_6_185;
	goto label$3b7f60a_6_189;
	label$3b7f60a_6_185:
	r30 = 2;
	r28 = r4 * r30;
	r4 = r28;
	goto label$3b7f60a_6_109;
	label$3b7f60a_6_189:
	r22 = r8;
	label$3b7f60a_6_190:
	r7 = r0->ctx;
	if( r7 == NULL ) hl_null_access();
	r7->lights = r22;
	label$3b7f60a_6_193:
	if( r3 == NULL ) hl_null_access();
	r7 = r3->ctx;
	if( r7 == NULL ) hl_null_access();
	r34 = r0->ambientShader;
	r33 = h3d_scene_RenderContext_allocShaderList(r7,r34,r2);
	r2 = r33;
	r7 = r0->ctx;
	if( r7 == NULL ) hl_null_access();
	r6 = r7->lights;
	r4 = 0;
	label$3b7f60a_6_203:
	if( !r6 ) goto label$3b7f60a_6_220;
	r5 = r4;
	++r4;
	r24 = r0->maxLightsPerObject;
	if( r5 != r24 ) goto label$3b7f60a_6_210;
	goto label$3b7f60a_6_220;
	label$3b7f60a_6_210:
	if( r3 == NULL ) hl_null_access();
	r7 = r3->ctx;
	if( r7 == NULL ) hl_null_access();
	if( r6 == NULL ) hl_null_access();
	r34 = r6->shader;
	r33 = h3d_scene_RenderContext_allocShaderList(r7,r34,r2);
	r2 = r33;
	r8 = r6->next;
	r6 = r8;
	goto label$3b7f60a_6_203;
	label$3b7f60a_6_220:
	return r2;
}

void h3d_scene_fwd_LightSystem_new(h3d__scene__fwd__LightSystem r0) {
	h3d__VectorImpl r4;
	bool r1;
	h3d__shader__AmbientLight r11;
	double r5, r7, r9;
	double *r6, *r8, *r10;
	int r2;
	r1 = true;
	r0->perPixelLighting = r1;
	r2 = 6;
	r0->maxLightsPerObject = r2;
	h3d_scene_LightSystem_new(((h3d__scene__LightSystem)r0));
	r4 = (h3d__VectorImpl)hl_alloc_obj(&t$h3d_VectorImpl);
	r5 = 0.5;
	r6 = &r5;
	r7 = 0.5;
	r8 = &r7;
	r9 = 0.5;
	r10 = &r9;
	h3d_VectorImpl_new(r4,r6,r8,r10);
	r0->ambientLight = r4;
	r11 = (h3d__shader__AmbientLight)hl_alloc_obj(&t$h3d_shader_AmbientLight);
	h3d_shader_AmbientLight_new(r11);
	r0->ambientShader = ((hxsl__Shader)r11);
	r1 = true;
	r1 = h3d_scene_fwd_LightSystem_set_additiveLighting(r0,r1);
	return;
}

