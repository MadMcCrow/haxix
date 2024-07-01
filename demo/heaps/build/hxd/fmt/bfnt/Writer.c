﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxd/fmt/bfnt/Writer.h>
#include <h2d/Font.h>
#include <haxe/io/Encoding.h>
#include <haxe/io/Bytes.h>
#include <h2d/FontChar.h>
#include <haxe/ds/IntMap.h>
#include <h2d/Tile.h>
#include <h2d/Kerning.h>
extern String s$BFNT;
void haxe_io_Output_writeString(haxe__io__Output,String,venum*);
extern String s$;
haxe__io__Bytes haxe_io_Bytes_ofString(String,venum*);
extern String s$Invalid_string_Size_over_0xFFFF;
void haxe_io_Output_writeUInt16(haxe__io__Output,int);
void haxe_io_Output_write(haxe__io__Output,haxe__io__Bytes);
void haxe_io_Output_writeInt16(haxe__io__Output,int);
vvirtual* haxe_ds_IntMap_keys(haxe__ds__IntMap);
extern hl_type t$fun_bf7849e;
extern hl_type t$fun_4dc72d5;
vdynamic* haxe_ds_IntMap_get(haxe__ds__IntMap,int);
void haxe_io_Output_writeInt32(haxe__io__Output,int);

void hxd_fmt_bfnt_Writer_new(hxd__fmt__bfnt__Writer r0,haxe__io__Output r1) {
	r0->out = r1;
	return;
}

void hxd_fmt_bfnt_Writer_write(hxd__fmt__bfnt__Writer r0,h2d__Font r1) {
	String r4, r7;
	vvirtual *r17;
	venum *r5;
	bool r16, r19;
	haxe__io__Bytes r8;
	haxe__ds__IntMap r18;
	h2d__Tile r21;
	h2d__FontChar r14, r15;
	haxe__io__Output r3;
	h2d__Kerning r29, r30;
	double r11, r12, r13, r22, r23, r24, r25, r26, r27, r28;
	vdynamic *r10;
	int r6, r9, r20;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r4 = (String)s$BFNT;
	r5 = NULL;
	haxe_io_Output_writeString(r3,r4,r5);
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = 0;
	((void (*)(haxe__io__Output,int))r3->$type->vobj_proto[0])(r3,r6);
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = 1;
	((void (*)(haxe__io__Output,int))r3->$type->vobj_proto[0])(r3,r6);
	if( r1 == NULL ) hl_null_access();
	r4 = r1->name;
	if( r4 ) goto label$ee0389f_2_18;
	r7 = (String)s$;
	r4 = r7;
	label$ee0389f_2_18:
	r5 = NULL;
	r8 = haxe_io_Bytes_ofString(r4,r5);
	if( r8 == NULL ) hl_null_access();
	r6 = r8->length;
	r9 = 65535;
	if( r9 >= r6 ) goto label$ee0389f_2_26;
	r7 = (String)s$Invalid_string_Size_over_0xFFFF;
	hl_throw((vdynamic*)r7);
	label$ee0389f_2_26:
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = r8->length;
	haxe_io_Output_writeUInt16(r3,r6);
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	haxe_io_Output_write(r3,r8);
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = r1->size;
	haxe_io_Output_writeInt16(r3,r6);
	r4 = r1->tilePath;
	if( r4 ) goto label$ee0389f_2_41;
	r7 = (String)s$;
	r4 = r7;
	label$ee0389f_2_41:
	r5 = NULL;
	r8 = haxe_io_Bytes_ofString(r4,r5);
	if( r8 == NULL ) hl_null_access();
	r6 = r8->length;
	r9 = 65535;
	if( r9 >= r6 ) goto label$ee0389f_2_49;
	r7 = (String)s$Invalid_string_Size_over_0xFFFF;
	hl_throw((vdynamic*)r7);
	label$ee0389f_2_49:
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = r8->length;
	haxe_io_Output_writeUInt16(r3,r6);
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	haxe_io_Output_write(r3,r8);
	r11 = r1->lineHeight;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = (int)r11;
	haxe_io_Output_writeInt16(r3,r6);
	r12 = r1->baseLine;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = (int)r12;
	haxe_io_Output_writeInt16(r3,r6);
	r14 = r1->defaultChar;
	r15 = r1->nullChar;
	if( r14 == r15 ) goto label$ee0389f_2_98;
	r16 = false;
	r18 = r1->glyphs;
	if( r18 == NULL ) hl_null_access();
	r17 = haxe_ds_IntMap_keys(r18);
	label$ee0389f_2_73:
	if( r17 == NULL ) hl_null_access();
	if( hl_vfields(r17)[0] ) r19 = ((bool (*)(vdynamic*))hl_vfields(r17)[0])(r17->value); else {
		vdynamic ret;
		hl_dyn_call_obj(r17->value,&t$fun_bf7849e,407283053/*hasNext*/,NULL,&ret);
		r19 = (bool)ret.v.i;
	}
	if( !r19 ) goto label$ee0389f_2_92;
	if( hl_vfields(r17)[1] ) r6 = ((int (*)(vdynamic*))hl_vfields(r17)[1])(r17->value); else {
		vdynamic ret;
		hl_dyn_call_obj(r17->value,&t$fun_4dc72d5,151160317/*next*/,NULL,&ret);
		r6 = (int)ret.v.i;
	}
	if( r1 == NULL ) hl_null_access();
	r18 = r1->glyphs;
	if( r18 == NULL ) hl_null_access();
	r10 = haxe_ds_IntMap_get(r18,r6);
	r14 = (h2d__FontChar)r10;
	r15 = r1->defaultChar;
	if( r14 != r15 ) goto label$ee0389f_2_91;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	haxe_io_Output_writeInt32(r3,r6);
	r19 = true;
	r16 = r19;
	goto label$ee0389f_2_92;
	label$ee0389f_2_91:
	goto label$ee0389f_2_73;
	label$ee0389f_2_92:
	if( r16 ) goto label$ee0389f_2_97;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = 0;
	haxe_io_Output_writeInt32(r3,r6);
	label$ee0389f_2_97:
	goto label$ee0389f_2_102;
	label$ee0389f_2_98:
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = 0;
	haxe_io_Output_writeInt32(r3,r6);
	label$ee0389f_2_102:
	if( r1 == NULL ) hl_null_access();
	r18 = r1->glyphs;
	if( r18 == NULL ) hl_null_access();
	r17 = haxe_ds_IntMap_keys(r18);
	label$ee0389f_2_106:
	if( r17 == NULL ) hl_null_access();
	if( hl_vfields(r17)[0] ) r16 = ((bool (*)(vdynamic*))hl_vfields(r17)[0])(r17->value); else {
		vdynamic ret;
		hl_dyn_call_obj(r17->value,&t$fun_bf7849e,407283053/*hasNext*/,NULL,&ret);
		r16 = (bool)ret.v.i;
	}
	if( !r16 ) goto label$ee0389f_2_184;
	if( hl_vfields(r17)[1] ) r6 = ((int (*)(vdynamic*))hl_vfields(r17)[1])(r17->value); else {
		vdynamic ret;
		hl_dyn_call_obj(r17->value,&t$fun_4dc72d5,151160317/*next*/,NULL,&ret);
		r6 = (int)ret.v.i;
	}
	r20 = 0;
	if( r6 != r20 ) goto label$ee0389f_2_114;
	goto label$ee0389f_2_106;
	label$ee0389f_2_114:
	if( r1 == NULL ) hl_null_access();
	r18 = r1->glyphs;
	if( r18 == NULL ) hl_null_access();
	r10 = haxe_ds_IntMap_get(r18,r6);
	r14 = (h2d__FontChar)r10;
	if( r14 == NULL ) hl_null_access();
	r21 = r14->_hx_t;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	haxe_io_Output_writeInt32(r3,r6);
	if( r21 == NULL ) hl_null_access();
	r13 = r21->x;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = (int)r13;
	haxe_io_Output_writeUInt16(r3,r9);
	r22 = r21->y;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = (int)r22;
	haxe_io_Output_writeUInt16(r3,r9);
	r23 = r21->width;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = (int)r23;
	haxe_io_Output_writeUInt16(r3,r9);
	r24 = r21->height;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = (int)r24;
	haxe_io_Output_writeUInt16(r3,r9);
	r25 = r21->dx;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = (int)r25;
	haxe_io_Output_writeInt16(r3,r9);
	r26 = r21->dy;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = (int)r26;
	haxe_io_Output_writeInt16(r3,r9);
	r27 = r14->width;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = (int)r27;
	haxe_io_Output_writeInt16(r3,r9);
	r29 = r14->kerning;
	label$ee0389f_2_161:
	if( !r29 ) goto label$ee0389f_2_179;
	if( r29 == NULL ) hl_null_access();
	r9 = r29->prevChar;
	r20 = 0;
	if( r9 == r20 ) goto label$ee0389f_2_176;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = r29->prevChar;
	haxe_io_Output_writeInt32(r3,r9);
	r28 = r29->offset;
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = (int)r28;
	haxe_io_Output_writeInt16(r3,r9);
	label$ee0389f_2_176:
	r30 = r29->next;
	r29 = r30;
	goto label$ee0389f_2_161;
	label$ee0389f_2_179:
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r9 = 0;
	haxe_io_Output_writeInt32(r3,r9);
	goto label$ee0389f_2_106;
	label$ee0389f_2_184:
	r3 = r0->out;
	if( r3 == NULL ) hl_null_access();
	r6 = 0;
	haxe_io_Output_writeInt32(r3,r6);
	return;
}

