﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <_std/Reflect.h>
#include <hl/natives.h>
#include <hl/types/ArrayBase.h>
extern String s$Invalid_function_;
String Std_string(vdynamic*);
String String___add__(String,String);
extern hl_type t$_dyn;
vdynamic* hl_types_ArrayDyn_getDyn(hl__types__ArrayDyn,int);
extern hl_type t$String;
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
int hl_types_ArrayObj_push(hl__types__ArrayObj,vdynamic*);

vdynamic* Reflect_field(vdynamic* r0,String r1) {
	vdynamic *r2;
	vbyte *r4;
	int r3;
	if( r1 ) goto label$0858e10_1_3;
	r2 = NULL;
	return r2;
	label$0858e10_1_3:
	if( r1 == NULL ) hl_null_access();
	r4 = r1->bytes;
	r3 = hl_hash(r4);
	r2 = hl_obj_get_field(r0,r3);
	return r2;
}

void Reflect_setField(vdynamic* r0,String r1,vdynamic* r2) {
	vbyte *r4;
	int r3;
	if( r1 == NULL ) hl_null_access();
	r4 = r1->bytes;
	r3 = hl_hash(r4);
	hl_obj_set_field(r0,r3,r2);
	return;
}

vdynamic* Reflect_callMethod(vdynamic* r0,vdynamic* r1,hl__types__ArrayDyn r2) {
	String r9, r10;
	hl_type *r4, *r7;
	hl__types__ArrayBase r11;
	hl__types__ArrayDyn r3;
	vdynamic *r5, *r14;
	varray *r15;
	int r6, r8, r12, r13, r16, r17, r18, r19;
	r3 = r2;
	r4 = r1 ? ((vdynamic*)r1)->t : &hlt_void;
	r6 = r4->kind;
	r8 = 10;
	if( r6 == r8 ) goto label$0858e10_3_9;
	r9 = (String)s$Invalid_function_;
	r10 = Std_string(r1);
	r9 = String___add__(r9,r10);
	hl_throw((vdynamic*)r9);
	label$0858e10_3_9:
	if( r2 == NULL ) hl_null_access();
	r11 = r2->array;
	if( r11 == NULL ) hl_null_access();
	r6 = r11->length;
	r8 = hl_type_args_count(r4);
	if( r6 >= r8 ) goto label$0858e10_3_17;
	r12 = r8;
	goto label$0858e10_3_18;
	label$0858e10_3_17:
	r12 = r6;
	label$0858e10_3_18:
	r5 = hl_get_closure_value(r1);
	if( !r5 ) goto label$0858e10_3_23;
	r14 = hl_no_closure(r1);
	r1 = r14;
	++r12;
	label$0858e10_3_23:
	r7 = &t$_dyn;
	r15 = hl_alloc_array(r7,r12);
	if( r5 ) goto label$0858e10_3_37;
	r13 = 0;
	r16 = r6;
	label$0858e10_3_28:
	if( r13 >= r16 ) goto label$0858e10_3_36;
	r17 = r13;
	++r13;
	if( r3 == NULL ) hl_null_access();
	r14 = hl_types_ArrayDyn_getDyn(r3,r17);
	((vdynamic**)(r15 + 1))[r17] = r14;
	goto label$0858e10_3_28;
	label$0858e10_3_36:
	goto label$0858e10_3_51;
	label$0858e10_3_37:
	r13 = 0;
	((vdynamic**)(r15 + 1))[r13] = r5;
	r13 = 0;
	r16 = r6;
	label$0858e10_3_41:
	if( r13 >= r16 ) goto label$0858e10_3_51;
	r17 = r13;
	++r13;
	if( r3 == NULL ) hl_null_access();
	r14 = hl_types_ArrayDyn_getDyn(r3,r17);
	r19 = 1;
	r18 = r17 + r19;
	((vdynamic**)(r15 + 1))[r18] = r14;
	goto label$0858e10_3_41;
	label$0858e10_3_51:
	r14 = hl_call_method(r1,r15);
	return r14;
}

hl__types__ArrayObj Reflect_fields(vdynamic* r0) {
	String r9;
	hl__types__ArrayObj r3;
	hl_type *r4;
	vbyte *r8;
	int r5, r6, r7;
	varray *r1, *r2;
	r1 = hl_obj_fields(r0);
	if( r1 ) goto label$0858e10_4_7;
	r4 = &t$String;
	r5 = 0;
	r2 = hl_alloc_array(r4,r5);
	r3 = hl_types_ArrayObj_alloc(r2);
	return r3;
	label$0858e10_4_7:
	r4 = &t$String;
	r5 = 0;
	r2 = hl_alloc_array(r4,r5);
	r3 = hl_types_ArrayObj_alloc(r2);
	r5 = 0;
	label$0858e10_4_12:
	r7 = r1->size;
	if( r5 >= r7 ) goto label$0858e10_4_25;
	r8 = ((vbyte**)(r1 + 1))[r5];
	++r5;
	r9 = (String)hl_alloc_obj(&t$String);
	r9->bytes = r8;
	r6 = 0;
	r6 = hl_ucs2length(r8,r6);
	r9->length = r6;
	if( r3 == NULL ) hl_null_access();
	r6 = hl_types_ArrayObj_push(r3,((vdynamic*)r9));
	goto label$0858e10_4_12;
	label$0858e10_4_25:
	return r3;
}

bool Reflect_deleteField(vdynamic* r0,String r1) {
	bool r2;
	vbyte *r4;
	int r3;
	if( r1 == NULL ) hl_null_access();
	r4 = r1->bytes;
	r3 = hl_hash(r4);
	r2 = hl_obj_delete_field(r0,r3);
	return r2;
}

