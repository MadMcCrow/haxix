﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/pass/_Copy/ArrayCopyShader.h>
#include <hxsl/Globals.h>
void hxsl_Shader_updateConstantsFinal(hxsl__Shader,hxsl__Globals);
extern hl_type t$_f64;
extern hl_type t$_i32;
void h3d_shader_ScreenShader_new(h3d__shader__ScreenShader);

h3d__mat__TextureArray h3d_pass__Copy_ArrayCopyShader_get_texture(h3d__pass___Copy__ArrayCopyShader r0) {
	h3d__mat__TextureArray r1;
	r1 = r0->texture__;
	return r1;
}

int h3d_pass__Copy_ArrayCopyShader_get_layer(h3d__pass___Copy__ArrayCopyShader r0) {
	int r1;
	r1 = r0->layer__;
	return r1;
}

h3d__mat__TextureArray h3d_pass__Copy_ArrayCopyShader_set_texture(h3d__pass___Copy__ArrayCopyShader r0,h3d__mat__TextureArray r1) {
	r0->texture__ = r1;
	return r1;
}

int h3d_pass__Copy_ArrayCopyShader_set_layer(h3d__pass___Copy__ArrayCopyShader r0,int r1) {
	r0->layer__ = r1;
	return r1;
}

void h3d_pass__Copy_ArrayCopyShader_updateConstants(h3d__pass___Copy__ArrayCopyShader r0,hxsl__Globals r1) {
	int r2;
	r2 = 0;
	r0->constBits = r2;
	hxsl_Shader_updateConstantsFinal(((hxsl__Shader)r0),r1);
	return;
}

vdynamic* h3d_pass__Copy_ArrayCopyShader_getParamValue(h3d__pass___Copy__ArrayCopyShader r0,int r1) {
	h3d__mat__TextureArray r5;
	double r3;
	vdynamic *r4;
	int r2;
	switch(r1) {
		default:
			goto label$0027469_6_10;
		case 0:
			r3 = r0->flipY__;
			r4 = hl_alloc_dynamic(&t$_f64);
			r4->v.d = r3;
			return r4;
		case 1:
			r5 = r0->texture__;
			return ((vdynamic*)r5);
		case 2:
			r2 = r0->layer__;
			r4 = hl_alloc_dynamic(&t$_i32);
			r4->v.i = r2;
			return r4;
	}
	label$0027469_6_10:
	r4 = NULL;
	return r4;
}

double h3d_pass__Copy_ArrayCopyShader_getParamFloatValue(h3d__pass___Copy__ArrayCopyShader r0,int r1) {
	double r3;
	int r2;
	r2 = 0;
	if( r1 != r2 ) goto label$0027469_7_4;
	r3 = r0->flipY__;
	return r3;
	label$0027469_7_4:
	r3 = 0.;
	return r3;
}

void h3d_pass__Copy_ArrayCopyShader_new(h3d__pass___Copy__ArrayCopyShader r0) {
	int r1;
	r1 = 0;
	r0->layer__ = r1;
	h3d_shader_ScreenShader_new(((h3d__shader__ScreenShader)r0));
	return;
}

