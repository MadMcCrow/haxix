﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxd/BufferInput.h>

void hxd_BufferInput_new(hxd__BufferInput r0,String r1,int r2,int* r3) {
	int r4;
	if( r3 ) goto label$071dd0d_1_3;
	r4 = 0;
	goto label$071dd0d_1_4;
	label$071dd0d_1_3:
	r4 = *r3;
	label$071dd0d_1_4:
	r0->name = r1;
	r0->type = r2;
	r0->precision = r4;
	return;
}

