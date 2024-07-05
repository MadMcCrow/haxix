﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/shader/SpecularTexture.h>
#include <hxsl/Globals.h>
void hxsl_Shader_updateConstantsFinal(hxsl__Shader,hxsl__Globals);
void hxsl_Shader_new(hxsl__Shader);

h3d__mat__Texture h3d_shader_SpecularTexture_get_texture(h3d__shader__SpecularTexture r0) {
	h3d__mat__Texture r1;
	r1 = r0->texture__;
	return r1;
}

h3d__mat__Texture h3d_shader_SpecularTexture_set_texture(h3d__shader__SpecularTexture r0,h3d__mat__Texture r1) {
	r0->texture__ = r1;
	return r1;
}

void h3d_shader_SpecularTexture_updateConstants(h3d__shader__SpecularTexture r0,hxsl__Globals r1) {
	int r2;
	r2 = 0;
	r0->constBits = r2;
	hxsl_Shader_updateConstantsFinal(((hxsl__Shader)r0),r1);
	return;
}

vdynamic* h3d_shader_SpecularTexture_getParamValue(h3d__shader__SpecularTexture r0,int r1) {
	vdynamic *r4;
	h3d__mat__Texture r3;
	int r2;
	r2 = 0;
	if( r1 != r2 ) goto label$1c90034_4_4;
	r3 = r0->texture__;
	return ((vdynamic*)r3);
	label$1c90034_4_4:
	r4 = NULL;
	return r4;
}

double h3d_shader_SpecularTexture_getParamFloatValue(h3d__shader__SpecularTexture r0,int r1) {
	double r2;
	r2 = 0.;
	return r2;
}

void h3d_shader_SpecularTexture_new(h3d__shader__SpecularTexture r0,h3d__mat__Texture r1) {
	hxsl_Shader_new(((hxsl__Shader)r0));
	r0->texture__ = r1;
	return;
}
