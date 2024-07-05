﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/shader/GenTexture.h>
extern hl_type t$h3d_Vector4Impl;
void h3d_Vector4Impl_new(h3d__Vector4Impl,double*,double*,double*,double*);
void h3d_shader_ScreenShader_new(h3d__shader__ScreenShader);
#include <hxsl/Globals.h>
extern String s$mode;
extern String s$_is_out_of_range_;
String String___add__(String,String);
#include <hl/natives.h>
String String___alloc__(vbyte*,int);
extern String s$cedf8da;
void hxsl_Shader_updateConstantsFinal(hxsl__Shader,hxsl__Globals);
extern hl_type t$_f64;
extern hl_type t$_i32;

void h3d_shader_GenTexture_new(h3d__shader__GenTexture r0) {
	h3d__Vector4Impl r1;
	double r2, r4, r6, r8;
	double *r3, *r5, *r7, *r9;
	int r11;
	r1 = (h3d__Vector4Impl)hl_alloc_obj(&t$h3d_Vector4Impl);
	r2 = 0.;
	r3 = &r2;
	r4 = 0.;
	r5 = &r4;
	r6 = 0.;
	r7 = &r6;
	r8 = 1.;
	r9 = &r8;
	h3d_Vector4Impl_new(r1,r3,r5,r7,r9);
	r0->color__ = r1;
	r11 = 0;
	r0->mode__ = r11;
	h3d_shader_ScreenShader_new(((h3d__shader__ScreenShader)r0));
	return;
}

int h3d_shader_GenTexture_get_mode(h3d__shader__GenTexture r0) {
	int r1;
	r1 = r0->mode__;
	return r1;
}

h3d__Vector4Impl h3d_shader_GenTexture_get_color(h3d__shader__GenTexture r0) {
	h3d__Vector4Impl r1;
	r1 = r0->color__;
	return r1;
}

h3d__Vector4Impl h3d_shader_GenTexture_set_color(h3d__shader__GenTexture r0,h3d__Vector4Impl r1) {
	r0->color__ = r1;
	return r1;
}

int h3d_shader_GenTexture_set_mode(h3d__shader__GenTexture r0,int r1) {
	bool r2;
	r2 = true;
	r0->constModified = r2;
	r0->mode__ = r1;
	return r1;
}

void h3d_shader_GenTexture_updateConstants(h3d__shader__GenTexture r0,hxsl__Globals r1) {
	String r6, r7;
	int *r8;
	vbyte *r9;
	int r2, r4, r5;
	r2 = 0;
	r0->constBits = r2;
	r2 = r0->mode__;
	r5 = 8;
	r4 = ((unsigned)r2) >> r5;
	r5 = 0;
	if( r4 == r5 ) goto label$1c0b98d_6_23;
	r6 = (String)s$mode;
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
	label$1c0b98d_6_23:
	r4 = r0->constBits;
	r4 = r4 | r2;
	r0->constBits = r4;
	hxsl_Shader_updateConstantsFinal(((hxsl__Shader)r0),r1);
	return;
}

vdynamic* h3d_shader_GenTexture_getParamValue(h3d__shader__GenTexture r0,int r1) {
	h3d__Vector4Impl r5;
	double r3;
	vdynamic *r4;
	int r2;
	switch(r1) {
		default:
			goto label$1c0b98d_7_10;
		case 0:
			r3 = r0->flipY__;
			r4 = hl_alloc_dynamic(&t$_f64);
			r4->v.d = r3;
			return r4;
		case 1:
			r2 = r0->mode__;
			r4 = hl_alloc_dynamic(&t$_i32);
			r4->v.i = r2;
			return r4;
		case 2:
			r5 = r0->color__;
			return ((vdynamic*)r5);
	}
	label$1c0b98d_7_10:
	r4 = NULL;
	return r4;
}

double h3d_shader_GenTexture_getParamFloatValue(h3d__shader__GenTexture r0,int r1) {
	double r3;
	int r2;
	r2 = 0;
	if( r1 != r2 ) goto label$1c0b98d_8_4;
	r3 = r0->flipY__;
	return r3;
	label$1c0b98d_8_4:
	r3 = 0.;
	return r3;
}
