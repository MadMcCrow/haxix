﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/shader/Texture.h>
#include <hxsl/Globals.h>
void hxsl_Shader_updateConstantsFinal(hxsl__Shader,hxsl__Globals);
extern hl_type t$_f64;
#include <h3d/mat/Defaults.h>
void hxsl_Shader_new(hxsl__Shader);
extern h3d__mat__$Defaults g$_h3d_mat_Defaults;

bool h3d_shader_Texture_get_additive(h3d__shader__Texture r0) {
	bool r1;
	r1 = r0->additive__;
	return r1;
}

bool h3d_shader_Texture_get_killAlpha(h3d__shader__Texture r0) {
	bool r1;
	r1 = r0->killAlpha__;
	return r1;
}

bool h3d_shader_Texture_get_specularAlpha(h3d__shader__Texture r0) {
	bool r1;
	r1 = r0->specularAlpha__;
	return r1;
}

double h3d_shader_Texture_get_killAlphaThreshold(h3d__shader__Texture r0) {
	double r1;
	r1 = r0->killAlphaThreshold__;
	return r1;
}

h3d__mat__Texture h3d_shader_Texture_get_texture(h3d__shader__Texture r0) {
	h3d__mat__Texture r1;
	r1 = r0->texture__;
	return r1;
}

double h3d_shader_Texture_set_killAlphaThreshold(h3d__shader__Texture r0,double r1) {
	r0->killAlphaThreshold__ = r1;
	return r1;
}

h3d__mat__Texture h3d_shader_Texture_set_texture(h3d__shader__Texture r0,h3d__mat__Texture r1) {
	r0->texture__ = r1;
	return r1;
}

bool h3d_shader_Texture_set_additive(h3d__shader__Texture r0,bool r1) {
	bool r2;
	r2 = true;
	r0->constModified = r2;
	r0->additive__ = r1;
	return r1;
}

bool h3d_shader_Texture_set_killAlpha(h3d__shader__Texture r0,bool r1) {
	bool r2;
	r2 = true;
	r0->constModified = r2;
	r0->killAlpha__ = r1;
	return r1;
}

bool h3d_shader_Texture_set_specularAlpha(h3d__shader__Texture r0,bool r1) {
	bool r2;
	r2 = true;
	r0->constModified = r2;
	r0->specularAlpha__ = r1;
	return r1;
}

void h3d_shader_Texture_updateConstants(h3d__shader__Texture r0,hxsl__Globals r1) {
	bool r4;
	int r2, r5;
	r2 = 0;
	r0->constBits = r2;
	r4 = r0->additive__;
	if( !r4 ) goto label$8d17021_11_8;
	r2 = r0->constBits;
	r5 = 1;
	r2 = r2 | r5;
	r0->constBits = r2;
	label$8d17021_11_8:
	r4 = r0->killAlpha__;
	if( !r4 ) goto label$8d17021_11_14;
	r2 = r0->constBits;
	r5 = 2;
	r2 = r2 | r5;
	r0->constBits = r2;
	label$8d17021_11_14:
	r4 = r0->specularAlpha__;
	if( !r4 ) goto label$8d17021_11_20;
	r2 = r0->constBits;
	r5 = 4;
	r2 = r2 | r5;
	r0->constBits = r2;
	label$8d17021_11_20:
	hxsl_Shader_updateConstantsFinal(((hxsl__Shader)r0),r1);
	return;
}

vdynamic* h3d_shader_Texture_getParamValue(h3d__shader__Texture r0,int r1) {
	bool r2;
	double r4;
	vdynamic *r3;
	h3d__mat__Texture r5;
	switch(r1) {
		default:
			goto label$8d17021_12_16;
		case 0:
			r2 = r0->additive__;
			r3 = hl_alloc_dynbool(r2);
			return r3;
		case 1:
			r2 = r0->killAlpha__;
			r3 = hl_alloc_dynbool(r2);
			return r3;
		case 2:
			r2 = r0->specularAlpha__;
			r3 = hl_alloc_dynbool(r2);
			return r3;
		case 3:
			r4 = r0->killAlphaThreshold__;
			r3 = hl_alloc_dynamic(&t$_f64);
			r3->v.d = r4;
			return r3;
		case 4:
			r5 = r0->texture__;
			return ((vdynamic*)r5);
	}
	label$8d17021_12_16:
	r3 = NULL;
	return r3;
}

double h3d_shader_Texture_getParamFloatValue(h3d__shader__Texture r0,int r1) {
	double r3;
	int r2;
	r2 = 3;
	if( r1 != r2 ) goto label$8d17021_13_4;
	r3 = r0->killAlphaThreshold__;
	return r3;
	label$8d17021_13_4:
	r3 = 0.;
	return r3;
}

void h3d_shader_Texture_new(h3d__shader__Texture r0,h3d__mat__Texture r1) {
	h3d__mat__$Defaults r4;
	double r2;
	r2 = 0.;
	r0->killAlphaThreshold__ = r2;
	hxsl_Shader_new(((hxsl__Shader)r0));
	r0->texture__ = r1;
	r4 = (h3d__mat__$Defaults)g$_h3d_mat_Defaults;
	r2 = r4->defaultKillAlphaThreshold;
	r0->killAlphaThreshold__ = r2;
	return;
}

