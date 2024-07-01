﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <haxe/io/FPHelper.h>
extern haxe__io__$FPHelper g$_haxe_io_FPHelper;
#include <haxe/_Int64/Int64_Impl_.h>
extern haxe___Int64__$Int64_Impl_ g$_haxe__Int64_Int64_Impl_;

int haxe_io_FPHelper_floatToI32(float r0) {
	haxe__io__$FPHelper r2;
	int r3;
	vbyte *r1;
	r2 = (haxe__io__$FPHelper)g$_haxe_io_FPHelper;
	r1 = r2->helper;
	r3 = 0;
	*(float*)(r1 + r3) = r0;
	r2 = (haxe__io__$FPHelper)g$_haxe_io_FPHelper;
	r1 = r2->helper;
	r3 = 0;
	r3 = *(int*)(r1 + r3);
	return r3;
}

double haxe_io_FPHelper_i64ToDouble(int r0,int r1) {
	haxe__io__$FPHelper r3;
	double r5;
	int r4;
	vbyte *r2;
	r3 = (haxe__io__$FPHelper)g$_haxe_io_FPHelper;
	r2 = r3->helper;
	r4 = 0;
	*(int*)(r2 + r4) = r0;
	r3 = (haxe__io__$FPHelper)g$_haxe_io_FPHelper;
	r2 = r3->helper;
	r4 = 4;
	*(int*)(r2 + r4) = r1;
	r3 = (haxe__io__$FPHelper)g$_haxe_io_FPHelper;
	r2 = r3->helper;
	r4 = 0;
	r5 = *(double*)(r2 + r4);
	return r5;
}

int64 haxe_io_FPHelper_doubleToI64(double r0) {
	int64 r6, r7, r8, r9, r10;
	haxe__io__$FPHelper r2;
	haxe___Int64__$Int64_Impl_ r11;
	int r4, r5;
	vbyte *r1, *r3;
	r2 = (haxe__io__$FPHelper)g$_haxe_io_FPHelper;
	r1 = r2->helper;
	r4 = 0;
	*(double*)(r1 + r4) = r0;
	r2 = (haxe__io__$FPHelper)g$_haxe_io_FPHelper;
	r1 = r2->helper;
	r4 = 4;
	r4 = *(int*)(r1 + r4);
	r2 = (haxe__io__$FPHelper)g$_haxe_io_FPHelper;
	r3 = r2->helper;
	r6 = (int)r4;
	r5 = 0;
	r5 = *(int*)(r3 + r5);
	r7 = (int)r5;
	r5 = 32;
	r9 = (int)r5;
	r8 = r6 << r9;
	r11 = (haxe___Int64__$Int64_Impl_)g$_haxe__Int64_Int64_Impl_;
	r10 = r11->MASK;
	r9 = r7 & r10;
	r8 = r8 | r9;
	return r8;
}

