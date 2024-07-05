﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <_std/EReg.h>
#include <hl/types/ArrayObj.h>
#include <hl/natives.h>
extern String s$g;
hl__types__ArrayObj String_split(String,String);
extern String s$;
String hl_types_ArrayObj_join(hl__types__ArrayObj,String);
extern hl_type t$_i32;
String String_substr(String,int,vdynamic*);
extern hl_type t$vrt_23648b9;
#include <_std/StringBuf.h>
#include <_std/String.h>
#include <haxe/ValueException.h>
extern hl_type t$StringBuf;
void StringBuf_new(StringBuf);
extern String s$c3e97dd;
void StringBuf_addSub(StringBuf,String,int,vdynamic*);
void StringBuf_add(StringBuf,vdynamic*);
extern $String g$_String;
bool hl_BaseType_check(hl__BaseType,vdynamic*);
extern haxe__$ValueException g$_haxe_ValueException;
bool Std_isOfType(vdynamic*,vdynamic*);
String String___add__(String,String);
String StringBuf_toString(StringBuf);

void EReg_new(EReg r0,String r1,String r2) {
	ereg *r10;
	String r4, r5;
	hl__types__ArrayObj r3;
	bool r7;
	vbyte *r11, *r12;
	int r8, r9;
	if( r2 == NULL ) hl_null_access();
	r5 = (String)s$g;
	r3 = String_split(r2,r5);
	if( r3 == NULL ) hl_null_access();
	r8 = r3->length;
	r9 = 1;
	if( r8 > r9 ) goto label$6d09180_1_9;
	r7 = false;
	goto label$6d09180_1_10;
	label$6d09180_1_9:
	r7 = true;
	label$6d09180_1_10:
	r0->global = r7;
	r7 = r0->global;
	if( !r7 ) goto label$6d09180_1_16;
	r4 = (String)s$;
	r4 = hl_types_ArrayObj_join(r3,r4);
	r2 = r4;
	label$6d09180_1_16:
	if( r1 == NULL ) hl_null_access();
	r11 = r1->bytes;
	if( r2 == NULL ) hl_null_access();
	r12 = r2->bytes;
	r10 = hl_regexp_new_options(r11,r12);
	r0->r = r10;
	return;
}

bool EReg_match(EReg r0,String r1) {
	String r5;
	ereg *r3;
	bool r2;
	int r6, r7;
	vbyte *r4;
	r3 = r0->r;
	if( r1 == NULL ) hl_null_access();
	r4 = r1->bytes;
	r6 = 0;
	r7 = r1->length;
	r2 = hl_regexp_match(r3,r4,r6,r7);
	if( !r2 ) goto label$6d09180_2_9;
	r0->last = r1;
	goto label$6d09180_2_11;
	label$6d09180_2_9:
	r5 = NULL;
	r0->last = r5;
	label$6d09180_2_11:
	return r2;
}

String EReg_matched(EReg r0,int r1) {
	String r7;
	ereg *r4;
	vdynamic *r8;
	int *r5;
	int r2, r3, r6;
	r2 = 0;
	r4 = r0->r;
	r5 = &r2;
	r3 = hl_regexp_matched_pos(r4,r1,r5);
	r6 = 0;
	if( r3 >= r6 ) goto label$6d09180_3_8;
	r7 = NULL;
	return r7;
	label$6d09180_3_8:
	r7 = r0->last;
	if( r7 == NULL ) hl_null_access();
	r8 = hl_alloc_dynamic(&t$_i32);
	r8->v.i = r2;
	r7 = String_substr(r7,r3,r8);
	return r7;
}

vvirtual* EReg_matchedPos(EReg r0) {
	ereg *r3;
	vvirtual *r6;
	int *r4;
	int r1, r2, r5;
	r1 = 0;
	r3 = r0->r;
	r2 = 0;
	r4 = &r1;
	r2 = hl_regexp_matched_pos(r3,r2,r4);
	r5 = 0;
	if( r2 >= r5 ) goto label$6d09180_4_9;
	r6 = NULL;
	return r6;
	label$6d09180_4_9:
	r6 = hl_alloc_virtual(&t$vrt_23648b9);
	if( hl_vfields(r6)[1] ) *(int*)(hl_vfields(r6)[1]) = (int)r2; else hl_dyn_seti(r6->value,5594516/*pos*/,&t$_i32,r2);
	if( hl_vfields(r6)[0] ) *(int*)(hl_vfields(r6)[0]) = (int)r1; else hl_dyn_seti(r6->value,5393365/*len*/,&t$_i32,r1);
	return r6;
}

bool EReg_matchSub(EReg r0,String r1,int r2,int* r3) {
	String r8;
	ereg *r6;
	bool r5;
	vbyte *r7;
	int r4, r9, r10;
	if( r3 ) goto label$6d09180_5_3;
	r4 = -1;
	goto label$6d09180_5_4;
	label$6d09180_5_3:
	r4 = *r3;
	label$6d09180_5_4:
	r6 = r0->r;
	if( r1 == NULL ) hl_null_access();
	r7 = r1->bytes;
	r10 = 0;
	if( r4 >= r10 ) goto label$6d09180_5_12;
	r9 = r1->length;
	r9 = r9 - r2;
	goto label$6d09180_5_13;
	label$6d09180_5_12:
	r9 = r4;
	label$6d09180_5_13:
	r5 = hl_regexp_match(r6,r7,r2,r9);
	if( !r5 ) goto label$6d09180_5_17;
	r0->last = r1;
	goto label$6d09180_5_19;
	label$6d09180_5_17:
	r8 = NULL;
	r0->last = r8;
	label$6d09180_5_19:
	return r5;
}

String EReg_replace(EReg r0,String r1,String r2) {
	$String r26;
	ereg *r12;
	String r7, r9, r27;
	hl__types__ArrayObj r8;
	bool r10, r11;
	haxe__ValueException r29;
	haxe__$ValueException r28;
	StringBuf r3;
	vdynamic *r20, *r21;
	int *r16;
	varray *r22;
	vbyte *r13;
	int r5, r6, r14, r15, r17, r18, r19, r23, r24, r25, r30;
	hl_trap_ctx trap$0;
	r3 = (StringBuf)hl_alloc_obj(&t$StringBuf);
	StringBuf_new(r3);
	r5 = 0;
	if( r1 == NULL ) hl_null_access();
	r6 = r1->length;
	if( r2 == NULL ) hl_null_access();
	r9 = (String)s$c3e97dd;
	r8 = String_split(r2,r9);
	r10 = true;
	label$6d09180_6_9:
	r12 = r0->r;
	if( r1 == NULL ) hl_null_access();
	r13 = r1->bytes;
	r11 = hl_regexp_match(r12,r13,r5,r6);
	if( !r11 ) goto label$6d09180_6_153;
	r14 = 0;
	r12 = r0->r;
	r15 = 0;
	r16 = &r14;
	r15 = hl_regexp_matched_pos(r12,r15,r16);
	r18 = 0;
	if( r14 != r18 ) goto label$6d09180_6_27;
	if( r10 ) goto label$6d09180_6_27;
	r18 = r1->length;
	if( r15 != r18 ) goto label$6d09180_6_26;
	goto label$6d09180_6_153;
	label$6d09180_6_26:
	++r15;
	label$6d09180_6_27:
	if( r3 == NULL ) hl_null_access();
	r18 = r15 - r5;
	r20 = hl_alloc_dynamic(&t$_i32);
	r20->v.i = r18;
	StringBuf_addSub(r3,r1,r5,r20);
	if( r8 == NULL ) hl_null_access();
	r17 = r8->length;
	r18 = 0;
	if( r18 >= r17 ) goto label$6d09180_6_44;
	r17 = 0;
	r18 = r8->length;
	if( ((unsigned)r17) < ((unsigned)r18) ) goto label$6d09180_6_40;
	r7 = NULL;
	goto label$6d09180_6_43;
	label$6d09180_6_40:
	r22 = r8->array;
	r21 = ((vdynamic**)(r22 + 1))[r17];
	r7 = (String)r21;
	label$6d09180_6_43:
	StringBuf_add(r3,((vdynamic*)r7));
	label$6d09180_6_44:
	r17 = 1;
	label$6d09180_6_45:
	if( r8 == NULL ) hl_null_access();
	r19 = r8->length;
	if( r17 >= r19 ) goto label$6d09180_6_141;
	r19 = r8->length;
	if( ((unsigned)r17) < ((unsigned)r19) ) goto label$6d09180_6_53;
	r7 = NULL;
	goto label$6d09180_6_56;
	label$6d09180_6_53:
	r22 = r8->array;
	r21 = ((vdynamic**)(r22 + 1))[r17];
	r7 = (String)r21;
	label$6d09180_6_56:
	if( r7 == NULL ) hl_null_access();
	r13 = r7->bytes;
	r18 = 0;
	r18 = *(unsigned short*)(r13 + r18);
	r23 = 49;
	if( r18 < r23 ) goto label$6d09180_6_115;
	r23 = 57;
	if( r23 < r18 ) goto label$6d09180_6_115;
	r19 = 0;
	hl_trap(trap$0,r21,label$6d09180_6_74);
	r12 = r0->r;
	r24 = (int)r18;
	r25 = 48;
	r24 = r24 - r25;
	r16 = &r19;
	r24 = hl_regexp_matched_pos(r12,r24,r16);
	hl_endtrap(trap$0);
	goto label$6d09180_6_95;
	label$6d09180_6_74:
	r26 = ($String)g$_String;
	r11 = hl_BaseType_check(((hl__BaseType)r26),r21);
	if( !r11 ) goto label$6d09180_6_80;
	r27 = (String)r21;
	r24 = -1;
	goto label$6d09180_6_95;
	label$6d09180_6_80:
	r28 = (haxe__$ValueException)g$_haxe_ValueException;
	r11 = hl_BaseType_check(((hl__BaseType)r28),r21);
	if( !r11 ) goto label$6d09180_6_94;
	r29 = (haxe__ValueException)r21;
	r21 = NULL;
	if( r29 == NULL ) hl_null_access();
	r21 = r29->value;
	r26 = ($String)g$_String;
	r11 = Std_isOfType(r21,((vdynamic*)r26));
	if( !r11 ) goto label$6d09180_6_92;
	r24 = -1;
	goto label$6d09180_6_93;
	label$6d09180_6_92:
	hl_rethrow((vdynamic*)r29);
	label$6d09180_6_93:
	goto label$6d09180_6_95;
	label$6d09180_6_94:
	hl_rethrow((vdynamic*)r21);
	label$6d09180_6_95:
	r25 = 0;
	if( r24 >= r25 ) goto label$6d09180_6_102;
	if( r3 == NULL ) hl_null_access();
	r27 = (String)s$c3e97dd;
	StringBuf_add(r3,((vdynamic*)r27));
	StringBuf_add(r3,((vdynamic*)r7));
	goto label$6d09180_6_114;
	label$6d09180_6_102:
	r25 = 0;
	if( r24 < r25 ) goto label$6d09180_6_107;
	if( r3 == NULL ) hl_null_access();
	r20 = hl_alloc_dynamic(&t$_i32);
	r20->v.i = r19;
	StringBuf_addSub(r3,r1,r24,r20);
	label$6d09180_6_107:
	if( r3 == NULL ) hl_null_access();
	r24 = 1;
	r25 = r7->length;
	r30 = 1;
	r25 = r25 - r30;
	r20 = hl_alloc_dynamic(&t$_i32);
	r20->v.i = r25;
	StringBuf_addSub(r3,r7,r24,r20);
	label$6d09180_6_114:
	goto label$6d09180_6_139;
	label$6d09180_6_115:
	r24 = 0;
	if( r18 != r24 ) goto label$6d09180_6_135;
	if( r3 == NULL ) hl_null_access();
	r9 = (String)s$c3e97dd;
	StringBuf_add(r3,((vdynamic*)r9));
	++r17;
	r24 = r8->length;
	if( ((unsigned)r17) < ((unsigned)r24) ) goto label$6d09180_6_125;
	r9 = NULL;
	goto label$6d09180_6_128;
	label$6d09180_6_125:
	r22 = r8->array;
	r21 = ((vdynamic**)(r22 + 1))[r17];
	r9 = (String)r21;
	label$6d09180_6_128:
	if( !r9 ) goto label$6d09180_6_134;
	if( r9 == NULL ) hl_null_access();
	r23 = r9->length;
	r24 = 0;
	if( r24 >= r23 ) goto label$6d09180_6_134;
	StringBuf_add(r3,((vdynamic*)r9));
	label$6d09180_6_134:
	goto label$6d09180_6_139;
	label$6d09180_6_135:
	if( r3 == NULL ) hl_null_access();
	r9 = (String)s$c3e97dd;
	r9 = String___add__(r9,r7);
	StringBuf_add(r3,((vdynamic*)r9));
	label$6d09180_6_139:
	++r17;
	goto label$6d09180_6_45;
	label$6d09180_6_141:
	r18 = r15 + r14;
	r18 = r18 - r5;
	r23 = r5 + r18;
	r5 = r23;
	r23 = r6 - r18;
	r6 = r23;
	r11 = false;
	r10 = r11;
	r11 = r0->global;
	if( r11 ) goto label$6d09180_6_152;
	goto label$6d09180_6_153;
	label$6d09180_6_152:
	goto label$6d09180_6_9;
	label$6d09180_6_153:
	if( r3 == NULL ) hl_null_access();
	r20 = hl_alloc_dynamic(&t$_i32);
	r20->v.i = r6;
	StringBuf_addSub(r3,r1,r5,r20);
	r7 = StringBuf_toString(r3);
	return r7;
}
