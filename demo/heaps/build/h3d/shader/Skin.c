﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/shader/Skin.h>
void h3d_shader_SkinBase_new(h3d__shader__SkinBase);
#include <hxsl/Globals.h>
extern String s$MaxBones;
extern String s$_is_out_of_range_;
String String___add__(String,String);
#include <hl/natives.h>
String String___alloc__(vbyte*,int);
extern String s$cedf8da;
void hxsl_Shader_updateConstantsFinal(hxsl__Shader,hxsl__Globals);
extern hl_type t$_i32;

void h3d_shader_Skin_new(h3d__shader__Skin r0) {
	h3d_shader_SkinBase_new(((h3d__shader__SkinBase)r0));
	return;
}

void h3d_shader_Skin_updateConstants(h3d__shader__Skin r0,hxsl__Globals r1) {
	String r6, r7;
	bool r10;
	int *r8;
	vbyte *r9;
	int r2, r4, r5;
	r2 = 0;
	r0->constBits = r2;
	r2 = r0->MaxBones__;
	r5 = 8;
	r4 = ((unsigned)r2) >> r5;
	r5 = 0;
	if( r4 == r5 ) goto label$e2074a7_2_23;
	r6 = (String)s$MaxBones;
	r7 = (String)s$_is_out_of_range_;
	r6 = String___add__(r6,r7);
	r4 = r2;
	r8 = &r4;
	r9 = hl_itos(r4,r8);
	r7 = String___alloc__(r9,r4);
	r6 = String___add__(r6,r7);
	r7 = (String)s$cedf8da;
	r6 = String___add__(r6,r7);
	r4 = 255;
	r8 = &r4;
	r9 = hl_itos(r4,r8);
	r7 = String___alloc__(r9,r4);
	r6 = String___add__(r6,r7);
	hl_throw((vdynamic*)r6);
	label$e2074a7_2_23:
	r4 = r0->constBits;
	r4 = r4 | r2;
	r0->constBits = r4;
	r10 = r0->fourBonesByVertex__;
	if( !r10 ) goto label$e2074a7_2_32;
	r2 = r0->constBits;
	r4 = 256;
	r2 = r2 | r4;
	r0->constBits = r2;
	label$e2074a7_2_32:
	hxsl_Shader_updateConstantsFinal(((hxsl__Shader)r0),r1);
	return;
}

vdynamic* h3d_shader_Skin_getParamValue(h3d__shader__Skin r0,int r1) {
	hl__types__ArrayObj r5;
	bool r4;
	vdynamic *r3;
	int r2;
	switch(r1) {
		default:
			goto label$e2074a7_3_10;
		case 0:
			r2 = r0->MaxBones__;
			r3 = hl_alloc_dynamic(&t$_i32);
			r3->v.i = r2;
			return r3;
		case 1:
			r4 = r0->fourBonesByVertex__;
			r3 = hl_alloc_dynbool(r4);
			return r3;
		case 2:
			r5 = r0->bonesMatrixes__;
			return ((vdynamic*)r5);
	}
	label$e2074a7_3_10:
	r3 = NULL;
	return r3;
}

double h3d_shader_Skin_getParamFloatValue(h3d__shader__Skin r0,int r1) {
	double r2;
	r2 = 0.;
	return r2;
}

