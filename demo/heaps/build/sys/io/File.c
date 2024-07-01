﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <sys/io/File.h>
#include <_std/SysError.h>
vbyte* Sys_getPath(String);
#include <hl/natives.h>
extern hl_type t$SysError;
extern String s$Can_t_read_;
String String___add__(String,String);
void SysError_new(SysError,String);
extern hl_type t$haxe_io_Bytes;
void haxe_io_Bytes_new(haxe__io__Bytes,vbyte*,int);
sys__io__FileOutput sys_io_File_write(String,bool*);
#include <haxe/io/Output.h>
void haxe_io_Output_write(haxe__io__Output,haxe__io__Bytes);
void sys_io_FileOutput_close(sys__io__FileOutput);
extern String s$Can_t_open_;
extern hl_type t$sys_io_FileInput;
void sys_io_FileInput_new(sys__io__FileInput,hl_fdesc*);
extern String s$_for_writing;
extern hl_type t$sys_io_FileOutput;
void sys_io_FileOutput_new(sys__io__FileOutput,hl_fdesc*);
#include <haxe/io/Input.h>
void haxe_io_Output_writeInput(haxe__io__Output,haxe__io__Input,vdynamic*);
void sys_io_FileInput_close(sys__io__FileInput);

haxe__io__Bytes sys_io_File_getBytes(String r0) {
	String r4;
	SysError r6;
	haxe__io__Bytes r7;
	int *r5;
	vbyte *r3;
	int r1;
	r1 = 0;
	r3 = Sys_getPath(r0);
	r5 = &r1;
	r3 = hl_file_contents(r3,r5);
	if( r3 ) goto label$3b6e088_1_10;
	r6 = (SysError)hl_alloc_obj(&t$SysError);
	r4 = (String)s$Can_t_read_;
	r4 = String___add__(r4,r0);
	SysError_new(r6,r4);
	hl_throw((vdynamic*)r6);
	label$3b6e088_1_10:
	r7 = (haxe__io__Bytes)hl_alloc_obj(&t$haxe_io_Bytes);
	haxe_io_Bytes_new(r7,r3,r1);
	return r7;
}

void sys_io_File_saveBytes(String r0,haxe__io__Bytes r1) {
	bool *r3;
	sys__io__FileOutput r2;
	r3 = NULL;
	r2 = sys_io_File_write(r0,r3);
	if( r2 == NULL ) hl_null_access();
	haxe_io_Output_write(((haxe__io__Output)r2),r1);
	sys_io_FileOutput_close(r2);
	return;
}

sys__io__FileInput sys_io_File_read(String r0,bool* r1) {
	String r5;
	SysError r8;
	bool r2;
	hl_fdesc *r3;
	sys__io__FileInput r9;
	int r6;
	vbyte *r4;
	if( r1 ) goto label$3b6e088_3_3;
	r2 = true;
	goto label$3b6e088_3_4;
	label$3b6e088_3_3:
	r2 = *r1;
	label$3b6e088_3_4:
	r4 = Sys_getPath(r0);
	r6 = 0;
	r3 = hl_file_open(r4,r6,r2);
	if( r3 ) goto label$3b6e088_3_13;
	r8 = (SysError)hl_alloc_obj(&t$SysError);
	r5 = (String)s$Can_t_open_;
	r5 = String___add__(r5,r0);
	SysError_new(r8,r5);
	hl_throw((vdynamic*)r8);
	label$3b6e088_3_13:
	r9 = (sys__io__FileInput)hl_alloc_obj(&t$sys_io_FileInput);
	sys_io_FileInput_new(r9,r3);
	return r9;
}

sys__io__FileOutput sys_io_File_write(String r0,bool* r1) {
	String r5, r9;
	sys__io__FileOutput r10;
	SysError r8;
	bool r2;
	hl_fdesc *r3;
	int r6;
	vbyte *r4;
	if( r1 ) goto label$3b6e088_4_3;
	r2 = true;
	goto label$3b6e088_4_4;
	label$3b6e088_4_3:
	r2 = *r1;
	label$3b6e088_4_4:
	r4 = Sys_getPath(r0);
	r6 = 1;
	r3 = hl_file_open(r4,r6,r2);
	if( r3 ) goto label$3b6e088_4_15;
	r8 = (SysError)hl_alloc_obj(&t$SysError);
	r5 = (String)s$Can_t_open_;
	r5 = String___add__(r5,r0);
	r9 = (String)s$_for_writing;
	r5 = String___add__(r5,r9);
	SysError_new(r8,r5);
	hl_throw((vdynamic*)r8);
	label$3b6e088_4_15:
	r10 = (sys__io__FileOutput)hl_alloc_obj(&t$sys_io_FileOutput);
	sys_io_FileOutput_new(r10,r3);
	return r10;
}

void sys_io_File_copy(String r0,String r1) {
	bool *r4;
	sys__io__FileOutput r6;
	bool r3, r7;
	vdynamic *r8;
	sys__io__FileInput r2;
	r3 = true;
	r4 = &r3;
	r2 = sys_io_File_read(r0,r4);
	r7 = true;
	r4 = &r7;
	r6 = sys_io_File_write(r1,r4);
	if( r6 == NULL ) hl_null_access();
	r8 = NULL;
	haxe_io_Output_writeInput(((haxe__io__Output)r6),((haxe__io__Input)r2),r8);
	if( r2 == NULL ) hl_null_access();
	sys_io_FileInput_close(r2);
	sys_io_FileOutput_close(r6);
	return;
}

