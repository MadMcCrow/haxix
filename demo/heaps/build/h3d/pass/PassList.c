﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/pass/PassList.h>

void h3d_pass_PassList_new(h3d__pass__PassList r0,h3d__pass__PassObject r1) {
	h3d__pass__PassObject r2;
	r0->current = r1;
	r2 = NULL;
	r0->lastDisc = r2;
	r0->discarded = r2;
	return;
}

