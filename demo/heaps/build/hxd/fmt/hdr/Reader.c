﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxd/fmt/hdr/Reader.h>
#include <haxe/io/BytesInput.h>
#include <haxe/ds/StringMap.h>
#include <hl/types/ArrayObj.h>
#include <hl/types/ArrayBytes_Float.h>
extern hl_type t$haxe_io_BytesInput;
void haxe_io_BytesInput_new(haxe__io__BytesInput,haxe__io__Bytes,vdynamic*,vdynamic*);
extern hl_type t$haxe_ds_StringMap;
void haxe_ds_StringMap_new(haxe__ds__StringMap);
#include <haxe/io/Input.h>
String haxe_io_Input_readLine(haxe__io__Input);
extern String s$;
int String___compare(String,vdynamic*);
vdynamic* String_charCodeAt(String,int);
extern hl_type t$_i32;
extern String s$43ec3e5;
hl__types__ArrayObj String_split(String,String);
vdynamic* hl_types_ArrayObj_shift(hl__types__ArrayObj);
String hl_types_ArrayObj_join(hl__types__ArrayObj,String);
void haxe_ds_StringMap_set(haxe__ds__StringMap,String,vdynamic*);
extern String s$7215ee9;
vdynamic* Std_parseInt(String);
extern String s$GAMMA;
vdynamic* haxe_ds_StringMap_get(haxe__ds__StringMap,String);
extern String s$1;
haxe__io__Bytes haxe_io_Bytes_alloc(int);
extern String s$EXPOSURE;
double Std_parseFloat(String);
#include <hl/natives.h>
hl__types__ArrayBytes_Float hl_types_ArrayBase_allocF64(vbyte*,int);
int hl_types_ArrayBytes_Float_push(hl__types__ArrayBytes_Float,double);
extern String s$FORMAT;
extern String s$Unsupported_HDR_format_;
String String___add__(String,String);
extern String s$32_bit_rle_rgbe;
int haxe_io_Bytes_getInt32(haxe__io__Bytes,int);
void haxe_io_Bytes_blit(haxe__io__Bytes,int,haxe__io__Bytes,int,int);
int haxe_io_Bytes_get(haxe__io__Bytes,int);
void haxe_io_Bytes_fill(haxe__io__Bytes,int,int,int);
extern hl_type t$vrt_9772814;
extern hl_type t$haxe_io_Bytes;
extern hl_type t$_bool;

vvirtual* hxd_fmt_hdr_Reader_decode(haxe__io__Bytes r0,bool r1) {
	String r11, r12, r13, r30;
	vvirtual *r44;
	hl__types__ArrayObj r15;
	haxe__ds__StringMap r9;
	haxe__io__BytesInput r2;
	bool r10;
	haxe__io__Bytes r3, r31;
	float r43;
	hl__types__ArrayBytes_Float r23, r26, r27, r28;
	double r19, r20, r21, r22;
	vdynamic *r4, *r5, *r17;
	vbyte *r24, *r42;
	varray *r18;
	int r7, r8, r14, r16, r25, r29, r32, r33, r34, r35, r36, r37, r38, r39, r40, r41;
	r2 = (haxe__io__BytesInput)hl_alloc_obj(&t$haxe_io_BytesInput);
	r4 = NULL;
	r5 = NULL;
	haxe_io_BytesInput_new(r2,r0,r4,r5);
	r7 = 0;
	r8 = 0;
	r9 = (haxe__ds__StringMap)hl_alloc_obj(&t$haxe_ds_StringMap);
	haxe_ds_StringMap_new(r9);
	label$0b2aba1_1_8:
	r10 = true;
	if( !r10 ) goto label$0b2aba1_1_36;
	if( r2 == NULL ) hl_null_access();
	r11 = haxe_io_Input_readLine(((haxe__io__Input)r2));
	r13 = (String)s$;
	if( r11 != r13 && (!r11 || !r13 || String___compare(r11,(vdynamic*)r13) != 0) ) goto label$0b2aba1_1_16;
	goto label$0b2aba1_1_36;
	label$0b2aba1_1_16:
	if( r11 == NULL ) hl_null_access();
	r14 = 0;
	r4 = String_charCodeAt(r11,r14);
	r14 = 35;
	r5 = hl_alloc_dynamic(&t$_i32);
	r5->v.i = r14;
	if( r4 != r5 && (!r4 || !r5 || (r4->v.i != r5->v.i)) ) goto label$0b2aba1_1_23;
	goto label$0b2aba1_1_8;
	label$0b2aba1_1_23:
	r13 = (String)s$43ec3e5;
	r15 = String_split(r11,r13);
	if( r15 == NULL ) hl_null_access();
	r14 = r15->length;
	r16 = 1;
	if( r16 >= r14 ) goto label$0b2aba1_1_35;
	if( r9 == NULL ) hl_null_access();
	r17 = hl_types_ArrayObj_shift(r15);
	r12 = (String)r17;
	r13 = (String)s$43ec3e5;
	r13 = hl_types_ArrayObj_join(r15,r13);
	haxe_ds_StringMap_set(r9,r12,((vdynamic*)r13));
	label$0b2aba1_1_35:
	goto label$0b2aba1_1_8;
	label$0b2aba1_1_36:
	if( r2 == NULL ) hl_null_access();
	r11 = haxe_io_Input_readLine(((haxe__io__Input)r2));
	if( r11 == NULL ) hl_null_access();
	r12 = (String)s$7215ee9;
	r15 = String_split(r11,r12);
	if( r15 == NULL ) hl_null_access();
	r14 = 1;
	r16 = r15->length;
	if( ((unsigned)r14) < ((unsigned)r16) ) goto label$0b2aba1_1_47;
	r11 = NULL;
	goto label$0b2aba1_1_50;
	label$0b2aba1_1_47:
	r18 = r15->array;
	r17 = ((vdynamic**)(r18 + 1))[r14];
	r11 = (String)r17;
	label$0b2aba1_1_50:
	r4 = Std_parseInt(r11);
	r14 = r4 ? r4->v.i : 0;
	r8 = r14;
	r14 = 3;
	r16 = r15->length;
	if( ((unsigned)r14) < ((unsigned)r16) ) goto label$0b2aba1_1_58;
	r11 = NULL;
	goto label$0b2aba1_1_61;
	label$0b2aba1_1_58:
	r18 = r15->array;
	r17 = ((vdynamic**)(r18 + 1))[r14];
	r11 = (String)r17;
	label$0b2aba1_1_61:
	r4 = Std_parseInt(r11);
	r14 = r4 ? r4->v.i : 0;
	r7 = r14;
	if( r9 == NULL ) hl_null_access();
	r11 = (String)s$GAMMA;
	r17 = haxe_ds_StringMap_get(r9,r11);
	r11 = (String)r17;
	r12 = (String)s$1;
	if( r11 == r12 || (r11 && r12 && String___compare(r11,(vdynamic*)r12) == 0) ) goto label$0b2aba1_1_72;
	r10 = false;
	goto label$0b2aba1_1_73;
	label$0b2aba1_1_72:
	r10 = true;
	label$0b2aba1_1_73:
	r14 = r14 * r8;
	r16 = 4;
	r14 = r14 * r16;
	r16 = 4;
	r14 = r14 * r16;
	r3 = haxe_io_Bytes_alloc(r14);
	r19 = 1.;
	r11 = (String)s$EXPOSURE;
	r17 = haxe_ds_StringMap_get(r9,r11);
	r11 = (String)r17;
	if( !r11 ) goto label$0b2aba1_1_90;
	r20 = Std_parseFloat(r11);
	r22 = 9.999999999999999799e-13;
	if( r20 < r22 ) goto label$0b2aba1_1_89;
	r22 = 1000000000000.;
	if( !(r20 < r22) ) goto label$0b2aba1_1_90;
	label$0b2aba1_1_89:
	r19 = r20;
	label$0b2aba1_1_90:
	if( !r1 ) goto label$0b2aba1_1_93;
	r20 = 1.;
	goto label$0b2aba1_1_94;
	label$0b2aba1_1_93:
	r20 = 0.4545454545454545303;
	label$0b2aba1_1_94:
	r14 = 0;
	r24 = hl_alloc_bytes(r14);
	r14 = 0;
	r14 = 0;
	r23 = hl_types_ArrayBase_allocF64(r24,r14);
	r14 = 0;
	label$0b2aba1_1_100:
	r25 = 256;
	if( r14 >= r25 ) goto label$0b2aba1_1_110;
	r16 = r14;
	++r14;
	if( r23 == NULL ) hl_null_access();
	r21 = (double)r16;
	r21 = hl_math_pow(r21,r20);
	r25 = hl_types_ArrayBytes_Float_push(r23,r21);
	goto label$0b2aba1_1_100;
	label$0b2aba1_1_110:
	r26 = r23;
	r14 = 0;
	r24 = hl_alloc_bytes(r14);
	r14 = 0;
	r14 = 0;
	r27 = hl_types_ArrayBase_allocF64(r24,r14);
	r14 = 0;
	label$0b2aba1_1_117:
	r25 = 256;
	if( r14 >= r25 ) goto label$0b2aba1_1_134;
	r16 = r14;
	++r14;
	if( r27 == NULL ) hl_null_access();
	r21 = 2.;
	r29 = 128;
	r25 = r16 - r29;
	r22 = (double)r25;
	r21 = hl_math_pow(r21,r22);
	r22 = 256.;
	r22 = r22 * r19;
	r21 = r21 / r22;
	r21 = hl_math_pow(r21,r20);
	r25 = hl_types_ArrayBytes_Float_push(r27,r21);
	goto label$0b2aba1_1_117;
	label$0b2aba1_1_134:
	r28 = r27;
	if( r9 == NULL ) hl_null_access();
	r12 = (String)s$FORMAT;
	r17 = haxe_ds_StringMap_get(r9,r12);
	r12 = (String)r17;
	if( r12 ) goto label$0b2aba1_1_143;
	r30 = (String)s$Unsupported_HDR_format_;
	r30 = String___add__(r30,r12);
	hl_throw((vdynamic*)r30);
	label$0b2aba1_1_143:
	r30 = (String)s$32_bit_rle_rgbe;
	if( r12 != r30 && (!r12 || !r30 || String___compare(r12,(vdynamic*)r30) != 0) ) goto label$0b2aba1_1_295;
	if( r2 == NULL ) hl_null_access();
	r14 = r2->pos;
	r25 = 4;
	r16 = r7 * r25;
	r31 = haxe_io_Bytes_alloc(r16);
	r29 = 8;
	r25 = r7 >> r29;
	r32 = 255;
	r29 = r7 & r32;
	r32 = 8;
	r29 = r29 << r32;
	r25 = r25 | r29;
	if( r3 == NULL ) hl_null_access();
	r24 = r3->b;
	r29 = 0;
	r32 = r8;
	label$0b2aba1_1_161:
	if( r29 >= r32 ) goto label$0b2aba1_1_294;
	r33 = r29;
	++r29;
	if( r0 == NULL ) hl_null_access();
	r34 = haxe_io_Bytes_getInt32(r0,r14);
	r36 = 65535;
	r35 = r34 & r36;
	r36 = 514;
	if( r35 != r36 ) goto label$0b2aba1_1_174;
	r36 = 16;
	r35 = ((unsigned)r34) >> r36;
	if( r35 == r25 ) goto label$0b2aba1_1_184;
	label$0b2aba1_1_174:
	if( r31 == NULL ) hl_null_access();
	r35 = 0;
	r38 = 4;
	r37 = r7 * r38;
	haxe_io_Bytes_blit(r31,r35,r0,r14,r37);
	r37 = 4;
	r36 = r7 * r37;
	r35 = r14 + r36;
	r14 = r35;
	goto label$0b2aba1_1_214;
	label$0b2aba1_1_184:
	r36 = 4;
	r35 = r14 + r36;
	r14 = r35;
	r35 = 0;
	r37 = 4;
	r36 = r7 * r37;
	label$0b2aba1_1_190:
	if( r35 >= r36 ) goto label$0b2aba1_1_214;
	if( r0 == NULL ) hl_null_access();
	r37 = r14;
	++r14;
	r37 = haxe_io_Bytes_get(r0,r37);
	r39 = 128;
	if( r39 >= r37 ) goto label$0b2aba1_1_207;
	r39 = 128;
	r38 = r37 - r39;
	r37 = r38;
	if( r31 == NULL ) hl_null_access();
	r40 = r14;
	++r14;
	r40 = haxe_io_Bytes_get(r0,r40);
	haxe_io_Bytes_fill(r31,r35,r37,r40);
	goto label$0b2aba1_1_211;
	label$0b2aba1_1_207:
	if( r31 == NULL ) hl_null_access();
	haxe_io_Bytes_blit(r31,r35,r0,r14,r37);
	r38 = r14 + r37;
	r14 = r38;
	label$0b2aba1_1_211:
	r38 = r35 + r37;
	r35 = r38;
	goto label$0b2aba1_1_190;
	label$0b2aba1_1_214:
	r35 = r33 * r7;
	r36 = 16;
	r35 = r35 * r36;
	r36 = 0;
	r37 = r7;
	label$0b2aba1_1_219:
	if( r36 >= r37 ) goto label$0b2aba1_1_293;
	r38 = r36;
	++r36;
	if( r28 == NULL ) hl_null_access();
	if( r31 == NULL ) hl_null_access();
	r41 = 3;
	r40 = r7 * r41;
	r39 = r38 + r40;
	r39 = haxe_io_Bytes_get(r31,r39);
	r40 = r28->length;
	if( ((unsigned)r39) < ((unsigned)r40) ) goto label$0b2aba1_1_233;
	r21 = 0.;
	goto label$0b2aba1_1_237;
	label$0b2aba1_1_233:
	r42 = r28->bytes;
	r40 = 3;
	r40 = r39 << r40;
	r21 = *(double*)(r42 + r40);
	label$0b2aba1_1_237:
	if( r26 == NULL ) hl_null_access();
	r39 = haxe_io_Bytes_get(r31,r38);
	r40 = r26->length;
	if( ((unsigned)r39) < ((unsigned)r40) ) goto label$0b2aba1_1_243;
	r22 = 0.;
	goto label$0b2aba1_1_247;
	label$0b2aba1_1_243:
	r42 = r26->bytes;
	r40 = 3;
	r40 = r39 << r40;
	r22 = *(double*)(r42 + r40);
	label$0b2aba1_1_247:
	r22 = r22 * r21;
	r43 = (float)r22;
	*(float*)(r24 + r35) = r43;
	r40 = 4;
	r39 = r35 + r40;
	r35 = r39;
	r39 = r38 + r7;
	r39 = haxe_io_Bytes_get(r31,r39);
	r40 = r26->length;
	if( ((unsigned)r39) < ((unsigned)r40) ) goto label$0b2aba1_1_259;
	r22 = 0.;
	goto label$0b2aba1_1_263;
	label$0b2aba1_1_259:
	r42 = r26->bytes;
	r40 = 3;
	r40 = r39 << r40;
	r22 = *(double*)(r42 + r40);
	label$0b2aba1_1_263:
	r22 = r22 * r21;
	r43 = (float)r22;
	*(float*)(r24 + r35) = r43;
	r40 = 4;
	r39 = r35 + r40;
	r35 = r39;
	r41 = 1;
	r40 = r7 << r41;
	r39 = r38 + r40;
	r39 = haxe_io_Bytes_get(r31,r39);
	r40 = r26->length;
	if( ((unsigned)r39) < ((unsigned)r40) ) goto label$0b2aba1_1_277;
	r22 = 0.;
	goto label$0b2aba1_1_281;
	label$0b2aba1_1_277:
	r42 = r26->bytes;
	r40 = 3;
	r40 = r39 << r40;
	r22 = *(double*)(r42 + r40);
	label$0b2aba1_1_281:
	r22 = r22 * r21;
	r43 = (float)r22;
	*(float*)(r24 + r35) = r43;
	r40 = 4;
	r39 = r35 + r40;
	r22 = 1.;
	r43 = (float)r22;
	*(float*)(r24 + r39) = r43;
	r40 = 4;
	r39 = r39 + r40;
	r35 = r39;
	goto label$0b2aba1_1_219;
	label$0b2aba1_1_293:
	goto label$0b2aba1_1_161;
	label$0b2aba1_1_294:
	goto label$0b2aba1_1_298;
	label$0b2aba1_1_295:
	r30 = (String)s$Unsupported_HDR_format_;
	r30 = String___add__(r30,r12);
	hl_throw((vdynamic*)r30);
	label$0b2aba1_1_298:
	r44 = hl_alloc_virtual(&t$vrt_9772814);
	if( hl_vfields(r44)[3] ) *(int*)(hl_vfields(r44)[3]) = (int)r7; else hl_dyn_seti(r44->value,-362629759/*width*/,&t$_i32,r7);
	if( hl_vfields(r44)[2] ) *(int*)(hl_vfields(r44)[2]) = (int)r8; else hl_dyn_seti(r44->value,38537191/*height*/,&t$_i32,r8);
	if( hl_vfields(r44)[0] ) *(haxe__io__Bytes*)(hl_vfields(r44)[0]) = (haxe__io__Bytes)r3; else hl_dyn_setp(r44->value,-40368287/*bytes*/,&t$haxe_io_Bytes,r3);
	if( hl_vfields(r44)[1] ) *(bool*)(hl_vfields(r44)[1]) = (bool)r10; else hl_dyn_seti(r44->value,-290028136/*gamma*/,&t$_bool,r10);
	return r44;
}

