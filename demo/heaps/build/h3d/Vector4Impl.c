﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/Vector4Impl.h>

void h3d_Vector4Impl_new(h3d__Vector4Impl r0,double* r1,double* r2,double* r3,double* r4) {
	double r5, r6, r7, r8;
	if( r1 ) goto label$e6e8594_1_3;
	r5 = 0.;
	goto label$e6e8594_1_4;
	label$e6e8594_1_3:
	r5 = *r1;
	label$e6e8594_1_4:
	if( r2 ) goto label$e6e8594_1_7;
	r6 = 0.;
	goto label$e6e8594_1_8;
	label$e6e8594_1_7:
	r6 = *r2;
	label$e6e8594_1_8:
	if( r3 ) goto label$e6e8594_1_11;
	r7 = 0.;
	goto label$e6e8594_1_12;
	label$e6e8594_1_11:
	r7 = *r3;
	label$e6e8594_1_12:
	if( r4 ) goto label$e6e8594_1_15;
	r8 = 1.;
	goto label$e6e8594_1_16;
	label$e6e8594_1_15:
	r8 = *r4;
	label$e6e8594_1_16:
	r0->x = r5;
	r0->y = r6;
	r0->z = r7;
	r0->w = r8;
	return;
}

