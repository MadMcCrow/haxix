﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/shader/UVDelta.h>
#include <hxsl/Globals.h>
void hxsl_Shader_updateConstantsFinal(hxsl__Shader,hxsl__Globals);
extern hl_type t$h3d_VectorImpl;
void h3d_VectorImpl_new(h3d__VectorImpl,double*,double*,double*);
void hxsl_Shader_new(hxsl__Shader);

h3d__VectorImpl h3d_shader_UVDelta_get_uvDelta(h3d__shader__UVDelta r0) {
	h3d__VectorImpl r1;
	r1 = r0->uvDelta__;
	return r1;
}

h3d__VectorImpl h3d_shader_UVDelta_get_uvScale(h3d__shader__UVDelta r0) {
	h3d__VectorImpl r1;
	r1 = r0->uvScale__;
	return r1;
}

h3d__VectorImpl h3d_shader_UVDelta_set_uvDelta(h3d__shader__UVDelta r0,h3d__VectorImpl r1) {
	r0->uvDelta__ = r1;
	return r1;
}

h3d__VectorImpl h3d_shader_UVDelta_set_uvScale(h3d__shader__UVDelta r0,h3d__VectorImpl r1) {
	r0->uvScale__ = r1;
	return r1;
}

void h3d_shader_UVDelta_updateConstants(h3d__shader__UVDelta r0,hxsl__Globals r1) {
	int r2;
	r2 = 0;
	r0->constBits = r2;
	hxsl_Shader_updateConstantsFinal(((hxsl__Shader)r0),r1);
	return;
}

vdynamic* h3d_shader_UVDelta_getParamValue(h3d__shader__UVDelta r0,int r1) {
	h3d__VectorImpl r2;
	vdynamic *r3;
	switch(r1) {
		default:
			goto label$a53a0f7_6_6;
		case 0:
			r2 = r0->uvDelta__;
			return ((vdynamic*)r2);
		case 1:
			r2 = r0->uvScale__;
			return ((vdynamic*)r2);
	}
	label$a53a0f7_6_6:
	r3 = NULL;
	return r3;
}

double h3d_shader_UVDelta_getParamFloatValue(h3d__shader__UVDelta r0,int r1) {
	double r2;
	r2 = 0.;
	return r2;
}

void h3d_shader_UVDelta_new(h3d__shader__UVDelta r0,double* r1,double* r2,double* r3,double* r4) {
	h3d__VectorImpl r9;
	double r5, r6, r7, r8, r10, r11, r12, r14, r15, r16, r17;
	if( r1 ) goto label$a53a0f7_8_3;
	r5 = 0.;
	goto label$a53a0f7_8_4;
	label$a53a0f7_8_3:
	r5 = *r1;
	label$a53a0f7_8_4:
	if( r2 ) goto label$a53a0f7_8_7;
	r6 = 0.;
	goto label$a53a0f7_8_8;
	label$a53a0f7_8_7:
	r6 = *r2;
	label$a53a0f7_8_8:
	if( r3 ) goto label$a53a0f7_8_11;
	r7 = 1.;
	goto label$a53a0f7_8_12;
	label$a53a0f7_8_11:
	r7 = *r3;
	label$a53a0f7_8_12:
	if( r4 ) goto label$a53a0f7_8_15;
	r8 = 1.;
	goto label$a53a0f7_8_16;
	label$a53a0f7_8_15:
	r8 = *r4;
	label$a53a0f7_8_16:
	r9 = (h3d__VectorImpl)hl_alloc_obj(&t$h3d_VectorImpl);
	r10 = 0.;
	r1 = &r10;
	r11 = 0.;
	r2 = &r11;
	r12 = 0.;
	r3 = &r12;
	h3d_VectorImpl_new(r9,r1,r2,r3);
	r0->uvScale__ = r9;
	r9 = (h3d__VectorImpl)hl_alloc_obj(&t$h3d_VectorImpl);
	r14 = 0.;
	r1 = &r14;
	r15 = 0.;
	r2 = &r15;
	r16 = 0.;
	r3 = &r16;
	h3d_VectorImpl_new(r9,r1,r2,r3);
	r0->uvDelta__ = r9;
	hxsl_Shader_new(((hxsl__Shader)r0));
	r9 = r0->uvDelta__;
	if( r9 == NULL ) hl_null_access();
	r9->x = r5;
	r9->y = r6;
	r17 = 0.;
	r9->z = r17;
	r9 = r0->uvScale__;
	if( r9 == NULL ) hl_null_access();
	r9->x = r7;
	r9->y = r8;
	r17 = 0.;
	r9->z = r17;
	return;
}

