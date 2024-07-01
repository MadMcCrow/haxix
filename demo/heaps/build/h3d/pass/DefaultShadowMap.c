﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/pass/DefaultShadowMap.h>
void h3d_pass_DirShadowMap_new(h3d__pass__DirShadowMap,h3d__scene__Light);
int h3d_pass_DirShadowMap_set_size(h3d__pass__DirShadowMap,int);
extern hl_type t$h3d_VectorImpl;
void h3d_VectorImpl_new(h3d__VectorImpl,double*,double*,double*);
extern venum* g$h3d_pass_RenderMode_Dynamic;
venum* h3d_pass_DirShadowMap_set_mode(h3d__pass__DirShadowMap,venum*);
extern String s$shadow_map;
int hxsl_Globals_allocID(String);
extern String s$shadow_proj;
extern String s$shadow_color;
extern String s$shadow_power;
extern String s$shadow_bias;
#include <hxsl/Channel.h>
#include <h3d/mat/Texture.h>
#include <h3d/MatrixImpl.h>
void h3d_pass_DirShadowMap_draw(h3d__pass__DirShadowMap,h3d__pass__PassList,vclosure*);
extern hl_type t$vrt_7cde10b;
extern hl_type t$h3d_mat_Texture;
extern h3d__mat__$Texture g$_h3d_mat_Texture;
extern venum* g$hxsl_Channel_PackedFloat;
extern venum* g$hxsl_Channel_R;
extern hl_type t$hxsl_Channel;
void h3d_scene_RenderContext_setGlobalID(h3d__scene__RenderContext,int,vdynamic*);
h3d__MatrixImpl h3d_pass_Shadows_getShadowProj(h3d__pass__Shadows);
extern hl_type t$_f64;

void h3d_pass_DefaultShadowMap_new(h3d__pass__DefaultShadowMap r0,int* r1,venum* r2) {
	String r15;
	h3d__VectorImpl r7;
	venum *r14;
	h3d__scene__Light r5;
	double r8, r10, r12;
	double *r9, *r11, *r13;
	int r3, r6;
	if( r1 ) goto label$f2230f2_1_3;
	r3 = 1024;
	goto label$f2230f2_1_4;
	label$f2230f2_1_3:
	r3 = *r1;
	label$f2230f2_1_4:
	if( !r2 ) goto label$f2230f2_1_6;
	r0->format = r2;
	label$f2230f2_1_6:
	r5 = NULL;
	h3d_pass_DirShadowMap_new(((h3d__pass__DirShadowMap)r0),r5);
	r6 = h3d_pass_DirShadowMap_set_size(((h3d__pass__DirShadowMap)r0),r3);
	r7 = (h3d__VectorImpl)hl_alloc_obj(&t$h3d_VectorImpl);
	r8 = 0.;
	r9 = &r8;
	r10 = 0.;
	r11 = &r10;
	r12 = 0.;
	r13 = &r12;
	h3d_VectorImpl_new(r7,r9,r11,r13);
	r0->color = r7;
	r14 = (venum*)g$h3d_pass_RenderMode_Dynamic;
	r14 = h3d_pass_DirShadowMap_set_mode(((h3d__pass__DirShadowMap)r0),r14);
	r15 = (String)s$shadow_map;
	r6 = hxsl_Globals_allocID(r15);
	r0->shadowMapId = r6;
	r15 = (String)s$shadow_proj;
	r6 = hxsl_Globals_allocID(r15);
	r0->shadowProjId = r6;
	r15 = (String)s$shadow_color;
	r6 = hxsl_Globals_allocID(r15);
	r0->shadowColorId = r6;
	r15 = (String)s$shadow_power;
	r6 = hxsl_Globals_allocID(r15);
	r0->shadowPowerId = r6;
	r15 = (String)s$shadow_bias;
	r6 = hxsl_Globals_allocID(r15);
	r0->shadowBiasId = r6;
	return;
}

void h3d_pass_DefaultShadowMap_draw(h3d__pass__DefaultShadowMap r0,h3d__pass__PassList r1,vclosure* r2) {
	h3d__VectorImpl r14;
	vvirtual *r6;
	venum *r9, *r10, *r11;
	h3d__mat__$Texture r12;
	double r15;
	vdynamic *r16;
	h3d__MatrixImpl r13;
	h3d__scene__RenderContext r4;
	h3d__shader__DirShadow r8;
	h3d__mat__Texture r7;
	int r5;
	h3d_pass_DirShadowMap_draw(((h3d__pass__DirShadowMap)r0),r1,r2);
	r4 = r0->ctx;
	if( r4 == NULL ) hl_null_access();
	r5 = r0->shadowMapId;
	r6 = hl_alloc_virtual(&t$vrt_7cde10b);
	r8 = r0->dshader;
	if( r8 == NULL ) hl_null_access();
	r7 = r8->shadowMap__;
	if( hl_vfields(r6)[1] ) *(h3d__mat__Texture*)(hl_vfields(r6)[1]) = (h3d__mat__Texture)r7; else hl_dyn_setp(r6->value,-18823348/*texture*/,&t$h3d_mat_Texture,r7);
	r10 = r0->format;
	r12 = (h3d__mat__$Texture)g$_h3d_mat_Texture;
	r11 = r12->nativeFormat;
	if( r10 != r11 ) goto label$f2230f2_2_15;
	r9 = (venum*)g$hxsl_Channel_PackedFloat;
	goto label$f2230f2_2_16;
	label$f2230f2_2_15:
	r9 = (venum*)g$hxsl_Channel_R;
	label$f2230f2_2_16:
	if( hl_vfields(r6)[0] ) *(venum**)(hl_vfields(r6)[0]) = (venum*)r9; else hl_dyn_setp(r6->value,-321781698/*channel*/,&t$hxsl_Channel,r9);
	h3d_scene_RenderContext_setGlobalID(r4,r5,((vdynamic*)r6));
	r4 = r0->ctx;
	if( r4 == NULL ) hl_null_access();
	r5 = r0->shadowProjId;
	r13 = h3d_pass_Shadows_getShadowProj(((h3d__pass__Shadows)r0));
	h3d_scene_RenderContext_setGlobalID(r4,r5,((vdynamic*)r13));
	r4 = r0->ctx;
	if( r4 == NULL ) hl_null_access();
	r5 = r0->shadowColorId;
	r14 = r0->color;
	h3d_scene_RenderContext_setGlobalID(r4,r5,((vdynamic*)r14));
	r4 = r0->ctx;
	if( r4 == NULL ) hl_null_access();
	r5 = r0->shadowPowerId;
	r15 = r0->power;
	r16 = hl_alloc_dynamic(&t$_f64);
	r16->v.d = r15;
	h3d_scene_RenderContext_setGlobalID(r4,r5,r16);
	r4 = r0->ctx;
	if( r4 == NULL ) hl_null_access();
	r5 = r0->shadowBiasId;
	r15 = r0->bias;
	r16 = hl_alloc_dynamic(&t$_f64);
	r16->v.d = r15;
	h3d_scene_RenderContext_setGlobalID(r4,r5,r16);
	return;
}

