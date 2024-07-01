﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <sys/io/FileInput.h>
#include <hl/natives.h>
#include <haxe/io/Eof.h>
extern hl_type t$haxe_io_Eof;
void haxe_io_Eof_new(haxe__io__Eof);
#include <haxe/io/Bytes.h>
#include <haxe/io/Error.h>
#include <haxe/io/BytesDataImpl.h>
extern venum* g$haxe_io_Error_OutsideBounds;
extern hl_type t$haxe_io_BytesDataImpl;
void haxe_io_BytesDataImpl_new(haxe__io__BytesDataImpl,vbyte*,int);
void haxe_io_Input_close(haxe__io__Input);

void sys_io_FileInput_new(sys__io__FileInput r0,hl_fdesc* r1) {
	r0->__f = r1;
	return;
}

int sys_io_FileInput_readByte(sys__io__FileInput r0) {
	hl_fdesc *r2;
	haxe__io__Eof r5;
	int r1, r4;
	r2 = r0->__f;
	r1 = hl_file_read_char(r2);
	r4 = 0;
	if( r1 >= r4 ) goto label$bf17b5a_2_7;
	r5 = (haxe__io__Eof)hl_alloc_obj(&t$haxe_io_Eof);
	haxe_io_Eof_new(r5);
	hl_throw((vdynamic*)r5);
	label$bf17b5a_2_7:
	return r1;
}

int sys_io_FileInput_readBytes(sys__io__FileInput r0,haxe__io__Bytes r1,int r2,int r3) {
	venum *r7;
	haxe__io__BytesDataImpl r9;
	hl_fdesc *r8;
	haxe__io__Eof r12;
	vbyte *r10;
	int r5, r6, r11;
	r6 = 0;
	if( r2 < r6 ) goto label$bf17b5a_3_8;
	r6 = 0;
	if( r3 < r6 ) goto label$bf17b5a_3_8;
	r5 = r2 + r3;
	if( r1 == NULL ) hl_null_access();
	r6 = r1->length;
	if( r6 >= r5 ) goto label$bf17b5a_3_10;
	label$bf17b5a_3_8:
	r7 = (venum*)g$haxe_io_Error_OutsideBounds;
	hl_throw((vdynamic*)r7);
	label$bf17b5a_3_10:
	r8 = r0->__f;
	r9 = (haxe__io__BytesDataImpl)hl_alloc_obj(&t$haxe_io_BytesDataImpl);
	r10 = r1->b;
	r5 = r1->length;
	haxe_io_BytesDataImpl_new(r9,r10,r5);
	if( r9 ) goto label$bf17b5a_3_18;
	r10 = NULL;
	goto label$bf17b5a_3_19;
	label$bf17b5a_3_18:
	r10 = r9->bytes;
	label$bf17b5a_3_19:
	r5 = hl_file_read(r8,r10,r2,r3);
	r11 = 0;
	if( r11 < r5 ) goto label$bf17b5a_3_25;
	r12 = (haxe__io__Eof)hl_alloc_obj(&t$haxe_io_Eof);
	haxe_io_Eof_new(r12);
	hl_throw((vdynamic*)r12);
	label$bf17b5a_3_25:
	return r5;
}

void sys_io_FileInput_close(sys__io__FileInput r0) {
	hl_fdesc *r2;
	haxe_io_Input_close(((haxe__io__Input)r0));
	r2 = r0->__f;
	hl_file_close(r2);
	r2 = NULL;
	r0->__f = r2;
	return;
}

