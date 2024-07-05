﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/shader/ColorMatrix.h>
#include <hxsl/Globals.h>
void hxsl_Shader_updateConstantsFinal(hxsl__Shader,hxsl__Globals);
#include <hl/types/ArrayBytes_Float.h>
extern hl_type t$h3d_MatrixImpl;
void h3d_MatrixImpl_new(h3d__MatrixImpl);
void hxsl_Shader_new(hxsl__Shader);
void h3d_MatrixImpl_loadValues(h3d__MatrixImpl,hl__types__ArrayBytes_Float);
void h3d_MatrixImpl_identity(h3d__MatrixImpl);

h3d__MatrixImpl h3d_shader_ColorMatrix_get_matrix(h3d__shader__ColorMatrix r0) {
	h3d__MatrixImpl r1;
	r1 = r0->matrix__;
	return r1;
}

bool h3d_shader_ColorMatrix_get_enabled(h3d__shader__ColorMatrix r0) {
	bool r1;
	r1 = r0->enabled__;
	return r1;
}

h3d__MatrixImpl h3d_shader_ColorMatrix_set_matrix(h3d__shader__ColorMatrix r0,h3d__MatrixImpl r1) {
	r0->matrix__ = r1;
	return r1;
}

bool h3d_shader_ColorMatrix_set_enabled(h3d__shader__ColorMatrix r0,bool r1) {
	bool r2;
	r2 = true;
	r0->constModified = r2;
	r0->enabled__ = r1;
	return r1;
}

void h3d_shader_ColorMatrix_updateConstants(h3d__shader__ColorMatrix r0,hxsl__Globals r1) {
	bool r4;
	int r2, r5;
	r2 = 0;
	r0->constBits = r2;
	r4 = r0->enabled__;
	if( !r4 ) goto label$6c082bf_5_8;
	r2 = r0->constBits;
	r5 = 1;
	r2 = r2 | r5;
	r0->constBits = r2;
	label$6c082bf_5_8:
	hxsl_Shader_updateConstantsFinal(((hxsl__Shader)r0),r1);
	return;
}

vdynamic* h3d_shader_ColorMatrix_getParamValue(h3d__shader__ColorMatrix r0,int r1) {
	bool r4;
	vdynamic *r3;
	h3d__MatrixImpl r2;
	switch(r1) {
		default:
			goto label$6c082bf_6_7;
		case 0:
			r2 = r0->matrix__;
			return ((vdynamic*)r2);
		case 1:
			r4 = r0->enabled__;
			r3 = hl_alloc_dynbool(r4);
			return r3;
	}
	label$6c082bf_6_7:
	r3 = NULL;
	return r3;
}

double h3d_shader_ColorMatrix_getParamFloatValue(h3d__shader__ColorMatrix r0,int r1) {
	double r2;
	r2 = 0.;
	return r2;
}

void h3d_shader_ColorMatrix_new(h3d__shader__ColorMatrix r0,hl__types__ArrayBytes_Float r1) {
	bool r2;
	h3d__MatrixImpl r3;
	r2 = true;
	r0->enabled__ = r2;
	r3 = (h3d__MatrixImpl)hl_alloc_obj(&t$h3d_MatrixImpl);
	h3d_MatrixImpl_new(r3);
	r0->matrix__ = r3;
	hxsl_Shader_new(((hxsl__Shader)r0));
	if( !r1 ) goto label$6c082bf_8_11;
	r3 = r0->matrix__;
	if( r3 == NULL ) hl_null_access();
	h3d_MatrixImpl_loadValues(r3,r1);
	goto label$6c082bf_8_14;
	label$6c082bf_8_11:
	r3 = r0->matrix__;
	if( r3 == NULL ) hl_null_access();
	h3d_MatrixImpl_identity(r3);
	label$6c082bf_8_14:
	return;
}
