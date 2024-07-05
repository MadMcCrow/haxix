﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxd/_BufferFormat/InputFormat_Impl_.h>
extern String s$DFloat;
extern String s$DVec2;
extern String s$DVec3;
extern String s$DVec4;
extern String s$DBytes4;
#include <hxsl/VecType.h>
extern String s$Unsupported_buffer_type_;
String Std_string(vdynamic*);
String String___add__(String,String);

String hxd__BufferFormat_InputFormat_Impl__toString(int r0) {
	String r1;
	switch(r0) {
		default:
		case 0:
		case 5:
		case 6:
		case 7:
		case 8:
			goto label$615d824_1_12;
		case 1:
			r1 = (String)s$DFloat;
			return r1;
		case 2:
			r1 = (String)s$DVec2;
			return r1;
		case 3:
			r1 = (String)s$DVec3;
			return r1;
		case 4:
			r1 = (String)s$DVec4;
			return r1;
		case 9:
			r1 = (String)s$DBytes4;
			return r1;
	}
	label$615d824_1_12:
	r1 = NULL;
	return r1;
}

int hxd__BufferFormat_InputFormat_Impl__fromHXSL(venum* r0) {
	String r2, r3;
	venum *r4;
	int r1, r5;
	if( r0 == NULL ) hl_null_access();
	r1 = HL__ENUM_INDEX__(r0);
	switch(r1) {
		default:
		case 0:
		case 1:
		case 2:
		case 4:
		case 6:
		case 7:
		case 8:
			r2 = (String)s$Unsupported_buffer_type_;
			r3 = Std_string(((vdynamic*)r0));
			r2 = String___add__(r2,r3);
			hl_throw((vdynamic*)r2);
		case 3:
			r1 = 1;
			return r1;
		case 5:
			r4 = ((hxsl_Type_TVec*)r0)->p1;
			r1 = ((hxsl_Type_TVec*)r0)->p0;
			switch(r1) {
				default:
				case 0:
				case 1:
					r2 = (String)s$Unsupported_buffer_type_;
					r3 = Std_string(((vdynamic*)r0));
					r2 = String___add__(r2,r3);
					hl_throw((vdynamic*)r2);
				case 2:
					if( r4 == NULL ) hl_null_access();
					r1 = HL__ENUM_INDEX__(r4);
					r5 = 1;
					if( r1 != r5 ) goto label$615d824_2_22;
					r1 = 2;
					return r1;
					label$615d824_2_22:
					r2 = (String)s$Unsupported_buffer_type_;
					r3 = Std_string(((vdynamic*)r0));
					r2 = String___add__(r2,r3);
					hl_throw((vdynamic*)r2);
				case 3:
					if( r4 == NULL ) hl_null_access();
					r1 = HL__ENUM_INDEX__(r4);
					r5 = 1;
					if( r1 != r5 ) goto label$615d824_2_32;
					r1 = 3;
					return r1;
					label$615d824_2_32:
					r2 = (String)s$Unsupported_buffer_type_;
					r3 = Std_string(((vdynamic*)r0));
					r2 = String___add__(r2,r3);
					hl_throw((vdynamic*)r2);
				case 4:
					if( r4 == NULL ) hl_null_access();
					r1 = HL__ENUM_INDEX__(r4);
					r5 = 1;
					if( r1 != r5 ) goto label$615d824_2_42;
					r1 = 4;
					return r1;
					label$615d824_2_42:
					r2 = (String)s$Unsupported_buffer_type_;
					r3 = Std_string(((vdynamic*)r0));
					r2 = String___add__(r2,r3);
					hl_throw((vdynamic*)r2);
			}
		case 9:
			r1 = ((hxsl_Type_TBytes*)r0)->p0;
			r5 = 4;
			if( r1 != r5 ) goto label$615d824_2_51;
			r1 = 9;
			return r1;
			label$615d824_2_51:
			r2 = (String)s$Unsupported_buffer_type_;
			r3 = Std_string(((vdynamic*)r0));
			r2 = String___add__(r2,r3);
			hl_throw((vdynamic*)r2);
	}
}
