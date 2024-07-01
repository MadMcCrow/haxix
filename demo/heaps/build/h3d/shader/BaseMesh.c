﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/shader/BaseMesh.h>
#include <hxsl/Globals.h>
void hxsl_Shader_updateConstantsFinal(hxsl__Shader,hxsl__Globals);
extern hl_type t$_f64;
extern hl_type t$h3d_VectorImpl;
void h3d_VectorImpl_new(h3d__VectorImpl,double*,double*,double*);
extern hl_type t$h3d_Vector4Impl;
void h3d_Vector4Impl_new(h3d__Vector4Impl,double*,double*,double*,double*);
void hxsl_Shader_new(hxsl__Shader);

h3d__Vector4Impl h3d_shader_BaseMesh_get_color(h3d__shader__BaseMesh r0) {
	h3d__Vector4Impl r1;
	r1 = r0->color__;
	return r1;
}

double h3d_shader_BaseMesh_get_specularPower(h3d__shader__BaseMesh r0) {
	double r1;
	r1 = r0->specularPower__;
	return r1;
}

double h3d_shader_BaseMesh_get_specularAmount(h3d__shader__BaseMesh r0) {
	double r1;
	r1 = r0->specularAmount__;
	return r1;
}

h3d__VectorImpl h3d_shader_BaseMesh_get_specularColor(h3d__shader__BaseMesh r0) {
	h3d__VectorImpl r1;
	r1 = r0->specularColor__;
	return r1;
}

h3d__Vector4Impl h3d_shader_BaseMesh_set_color(h3d__shader__BaseMesh r0,h3d__Vector4Impl r1) {
	r0->color__ = r1;
	return r1;
}

double h3d_shader_BaseMesh_set_specularPower(h3d__shader__BaseMesh r0,double r1) {
	r0->specularPower__ = r1;
	return r1;
}

double h3d_shader_BaseMesh_set_specularAmount(h3d__shader__BaseMesh r0,double r1) {
	r0->specularAmount__ = r1;
	return r1;
}

h3d__VectorImpl h3d_shader_BaseMesh_set_specularColor(h3d__shader__BaseMesh r0,h3d__VectorImpl r1) {
	r0->specularColor__ = r1;
	return r1;
}

void h3d_shader_BaseMesh_updateConstants(h3d__shader__BaseMesh r0,hxsl__Globals r1) {
	int r2;
	r2 = 0;
	r0->constBits = r2;
	hxsl_Shader_updateConstantsFinal(((hxsl__Shader)r0),r1);
	return;
}

vdynamic* h3d_shader_BaseMesh_getParamValue(h3d__shader__BaseMesh r0,int r1) {
	h3d__VectorImpl r5;
	h3d__Vector4Impl r2;
	double r4;
	vdynamic *r3;
	switch(r1) {
		default:
			goto label$f900718_10_12;
		case 0:
			r2 = r0->color__;
			return ((vdynamic*)r2);
		case 1:
			r4 = r0->specularPower__;
			r3 = hl_alloc_dynamic(&t$_f64);
			r3->v.d = r4;
			return r3;
		case 2:
			r4 = r0->specularAmount__;
			r3 = hl_alloc_dynamic(&t$_f64);
			r3->v.d = r4;
			return r3;
		case 3:
			r5 = r0->specularColor__;
			return ((vdynamic*)r5);
	}
	label$f900718_10_12:
	r3 = NULL;
	return r3;
}

double h3d_shader_BaseMesh_getParamFloatValue(h3d__shader__BaseMesh r0,int r1) {
	double r2;
	switch(r1) {
		default:
		case 0:
			goto label$f900718_11_6;
		case 1:
			r2 = r0->specularPower__;
			return r2;
		case 2:
			r2 = r0->specularAmount__;
			return r2;
	}
	label$f900718_11_6:
	r2 = 0.;
	return r2;
}

void h3d_shader_BaseMesh_new(h3d__shader__BaseMesh r0) {
	h3d__VectorImpl r1;
	h3d__Vector4Impl r10;
	double r2, r4, r6, r9, r11, r12, r13, r15;
	double *r3, *r5, *r7, *r14;
	r1 = (h3d__VectorImpl)hl_alloc_obj(&t$h3d_VectorImpl);
	r2 = 0.;
	r3 = &r2;
	r4 = 0.;
	r5 = &r4;
	r6 = 0.;
	r7 = &r6;
	h3d_VectorImpl_new(r1,r3,r5,r7);
	r0->specularColor__ = r1;
	r9 = 0.;
	r0->specularAmount__ = r9;
	r9 = 0.;
	r0->specularPower__ = r9;
	r10 = (h3d__Vector4Impl)hl_alloc_obj(&t$h3d_Vector4Impl);
	r9 = 0.;
	r3 = &r9;
	r11 = 0.;
	r5 = &r11;
	r12 = 0.;
	r7 = &r12;
	r13 = 1.;
	r14 = &r13;
	h3d_Vector4Impl_new(r10,r3,r5,r7,r14);
	r0->color__ = r10;
	hxsl_Shader_new(((hxsl__Shader)r0));
	r10 = r0->color__;
	if( r10 == NULL ) hl_null_access();
	r15 = 1.;
	r10->x = r15;
	r15 = 1.;
	r10->y = r15;
	r15 = 1.;
	r10->z = r15;
	r15 = 1.;
	r10->w = r15;
	r1 = r0->specularColor__;
	if( r1 == NULL ) hl_null_access();
	r15 = 1.;
	r1->x = r15;
	r15 = 1.;
	r1->y = r15;
	r15 = 1.;
	r1->z = r15;
	r15 = 50.;
	r0->specularPower__ = r15;
	r15 = 1.;
	r0->specularAmount__ = r15;
	return;
}

