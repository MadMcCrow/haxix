﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/shader/MinMaxShader.h>
void h3d_shader_ScreenShader_new(h3d__shader__ScreenShader);
#include <hxsl/Globals.h>
void hxsl_Shader_updateConstantsFinal(hxsl__Shader,hxsl__Globals);
extern hl_type t$_f64;

void h3d_shader_MinMaxShader_new(h3d__shader__MinMaxShader r0) {
	h3d_shader_ScreenShader_new(((h3d__shader__ScreenShader)r0));
	return;
}

h3d__mat__Texture h3d_shader_MinMaxShader_get_texA(h3d__shader__MinMaxShader r0) {
	h3d__mat__Texture r1;
	r1 = r0->texA__;
	return r1;
}

h3d__mat__Texture h3d_shader_MinMaxShader_get_texB(h3d__shader__MinMaxShader r0) {
	h3d__mat__Texture r1;
	r1 = r0->texB__;
	return r1;
}

bool h3d_shader_MinMaxShader_get_isMax(h3d__shader__MinMaxShader r0) {
	bool r1;
	r1 = r0->isMax__;
	return r1;
}

h3d__mat__Texture h3d_shader_MinMaxShader_set_texA(h3d__shader__MinMaxShader r0,h3d__mat__Texture r1) {
	r0->texA__ = r1;
	return r1;
}

h3d__mat__Texture h3d_shader_MinMaxShader_set_texB(h3d__shader__MinMaxShader r0,h3d__mat__Texture r1) {
	r0->texB__ = r1;
	return r1;
}

bool h3d_shader_MinMaxShader_set_isMax(h3d__shader__MinMaxShader r0,bool r1) {
	bool r2;
	r2 = true;
	r0->constModified = r2;
	r0->isMax__ = r1;
	return r1;
}

void h3d_shader_MinMaxShader_updateConstants(h3d__shader__MinMaxShader r0,hxsl__Globals r1) {
	bool r4;
	int r2, r5;
	r2 = 0;
	r0->constBits = r2;
	r4 = r0->isMax__;
	if( !r4 ) goto label$88fd2fb_8_8;
	r2 = r0->constBits;
	r5 = 1;
	r2 = r2 | r5;
	r0->constBits = r2;
	label$88fd2fb_8_8:
	hxsl_Shader_updateConstantsFinal(((hxsl__Shader)r0),r1);
	return;
}

vdynamic* h3d_shader_MinMaxShader_getParamValue(h3d__shader__MinMaxShader r0,int r1) {
	bool r5;
	double r2;
	vdynamic *r3;
	h3d__mat__Texture r4;
	switch(r1) {
		default:
			goto label$88fd2fb_9_12;
		case 0:
			r2 = r0->flipY__;
			r3 = hl_alloc_dynamic(&t$_f64);
			r3->v.d = r2;
			return r3;
		case 1:
			r4 = r0->texA__;
			return ((vdynamic*)r4);
		case 2:
			r4 = r0->texB__;
			return ((vdynamic*)r4);
		case 3:
			r5 = r0->isMax__;
			r3 = hl_alloc_dynbool(r5);
			return r3;
	}
	label$88fd2fb_9_12:
	r3 = NULL;
	return r3;
}

double h3d_shader_MinMaxShader_getParamFloatValue(h3d__shader__MinMaxShader r0,int r1) {
	double r3;
	int r2;
	r2 = 0;
	if( r1 != r2 ) goto label$88fd2fb_10_4;
	r3 = r0->flipY__;
	return r3;
	label$88fd2fb_10_4:
	r3 = 0.;
	return r3;
}
