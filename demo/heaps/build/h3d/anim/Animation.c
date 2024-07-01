﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/anim/Animation.h>
extern hl_type t$h3d_anim_AnimatedObject;
#include <hl/natives.h>
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern String s$assert;
extern String s$3ba90dd;
extern hl_type t$hl_types_ArrayObj;
extern hl_type t$_dyn;

void h3d_anim_Animation_new(h3d__anim__Animation r0,String r1,int r2,double r3) {
	hl__types__ArrayObj r6;
	hl_type *r8;
	bool r9;
	double r5;
	varray *r7;
	int r4;
	r0->name = r1;
	r0->frameCount = r2;
	r0->sampling = r3;
	r8 = &t$h3d_anim_AnimatedObject;
	r4 = 0;
	r7 = hl_alloc_array(r8,r4);
	r6 = hl_types_ArrayObj_alloc(r7);
	r0->objects = r6;
	r4 = -1;
	r0->lastEvent = r4;
	r5 = 0.;
	r0->frame = r5;
	r5 = 1.;
	r0->speed = r5;
	r9 = true;
	r0->loop = r9;
	r9 = false;
	r0->pause = r9;
	return;
}

vdynamic* h3d_anim_Animation_getPropValue(h3d__anim__Animation r0,String r1,String r2) {
	vdynamic *r3;
	r3 = NULL;
	return r3;
}

void h3d_anim_Animation_sync(h3d__anim__Animation r0,bool* r1) {
	String r3;
	bool r2;
	if( r1 ) goto label$b4be4e7_3_3;
	r2 = false;
	goto label$b4be4e7_3_4;
	label$b4be4e7_3_3:
	r2 = *r1;
	label$b4be4e7_3_4:
	r3 = (String)s$assert;
	hl_throw((vdynamic*)r3);
}

bool h3d_anim_Animation_isPlaying(h3d__anim__Animation r0) {
	bool r1;
	double r2, r3;
	r1 = r0->pause;
	if( r1 ) goto label$b4be4e7_4_15;
	r2 = r0->speed;
	r3 = 0.;
	if( !(r2 < r3) ) goto label$b4be4e7_4_8;
	r2 = r0->speed;
	r2 = -r2;
	goto label$b4be4e7_4_9;
	label$b4be4e7_4_8:
	r2 = r0->speed;
	label$b4be4e7_4_9:
	r3 = 9.999999999999999547e-07;
	if( r2 > r3 ) goto label$b4be4e7_4_13;
	r1 = false;
	goto label$b4be4e7_4_14;
	label$b4be4e7_4_13:
	r1 = true;
	label$b4be4e7_4_14:
	return r1;
	label$b4be4e7_4_15:
	r1 = false;
	return r1;
}

int h3d_anim_Animation_endFrame(h3d__anim__Animation r0) {
	int r1;
	r1 = r0->frameCount;
	return r1;
}

double h3d_anim_Animation_update(h3d__anim__Animation r0,double r1) {
	String r4;
	hl__types__ArrayObj r7;
	bool r3;
	vclosure *r8, *r25;
	double r6, r10, r11, r12, r20, r21, r22, r23;
	vdynamic *r5;
	varray *r19;
	int r9, r13, r14, r15, r16, r17, r18, r24;
	r3 = r0->isInstance;
	if( r3 ) goto label$b4be4e7_6_4;
	r4 = (String)s$3ba90dd;
	hl_throw((vdynamic*)r4);
	label$b4be4e7_6_4:
	r3 = h3d_anim_Animation_isPlaying(r0);
	if( r3 ) goto label$b4be4e7_6_8;
	r6 = 0.;
	return r6;
	label$b4be4e7_6_8:
	r7 = r0->events;
	if( !r7 ) goto label$b4be4e7_6_99;
	r8 = r0->onEvent;
	if( !r8 ) goto label$b4be4e7_6_99;
	r6 = r0->frame;
	r9 = (int)r6;
	r10 = r0->frame;
	r12 = r0->speed;
	r11 = r1 * r12;
	r12 = r0->sampling;
	r11 = r11 * r12;
	r10 = r10 + r11;
	r13 = (int)r10;
	r15 = r0->frameCount;
	if( r13 < r15 ) goto label$b4be4e7_6_27;
	r14 = r0->frameCount;
	r15 = 1;
	r14 = r14 - r15;
	r13 = r14;
	label$b4be4e7_6_27:
	r14 = r9;
	r16 = 1;
	r15 = r13 + r16;
	label$b4be4e7_6_30:
	if( r14 >= r15 ) goto label$b4be4e7_6_99;
	r16 = r14;
	++r14;
	r18 = r0->lastEvent;
	if( r16 != r18 ) goto label$b4be4e7_6_37;
	goto label$b4be4e7_6_30;
	label$b4be4e7_6_37:
	r0->lastEvent = r16;
	r7 = r0->events;
	if( r7 == NULL ) hl_null_access();
	r18 = r7->length;
	if( ((unsigned)r16) < ((unsigned)r18) ) goto label$b4be4e7_6_44;
	r7 = NULL;
	goto label$b4be4e7_6_47;
	label$b4be4e7_6_44:
	r19 = r7->array;
	r5 = ((vdynamic**)(r19 + 1))[r16];
	r7 = (hl__types__ArrayObj)hl_dyn_castp(&r5,&t$_dyn,&t$hl_types_ArrayObj);
	label$b4be4e7_6_47:
	if( !r7 ) goto label$b4be4e7_6_98;
	r11 = r0->frame;
	r12 = r1;
	r21 = (double)r16;
	r22 = r0->frame;
	r21 = r21 - r22;
	r22 = r0->speed;
	r23 = r0->sampling;
	r22 = r22 * r23;
	r21 = r21 / r22;
	r20 = r1 - r21;
	r1 = r20;
	r20 = (double)r16;
	r0->frame = r20;
	r17 = 0;
	r7 = r0->events;
	if( r7 == NULL ) hl_null_access();
	r24 = r7->length;
	if( ((unsigned)r16) < ((unsigned)r24) ) goto label$b4be4e7_6_68;
	r7 = NULL;
	goto label$b4be4e7_6_71;
	label$b4be4e7_6_68:
	r19 = r7->array;
	r5 = ((vdynamic**)(r19 + 1))[r16];
	r7 = (hl__types__ArrayObj)hl_dyn_castp(&r5,&t$_dyn,&t$hl_types_ArrayObj);
	label$b4be4e7_6_71:
	if( r7 == NULL ) hl_null_access();
	r24 = r7->length;
	if( r17 >= r24 ) goto label$b4be4e7_6_87;
	r24 = r7->length;
	if( ((unsigned)r17) < ((unsigned)r24) ) goto label$b4be4e7_6_79;
	r4 = NULL;
	goto label$b4be4e7_6_82;
	label$b4be4e7_6_79:
	r19 = r7->array;
	r5 = ((vdynamic**)(r19 + 1))[r17];
	r4 = (String)r5;
	label$b4be4e7_6_82:
	++r17;
	r8 = r0->onEvent;
	if( r8 == NULL ) hl_null_access();
	r8->hasValue ? ((void (*)(vdynamic*,String))r8->fun)((vdynamic*)r8->value,r4) : ((void (*)(String))r8->fun)(r4);
	goto label$b4be4e7_6_71;
	label$b4be4e7_6_87:
	r20 = r0->frame;
	r21 = (double)r16;
	if( r20 != r21 ) goto label$b4be4e7_6_97;
	r18 = r0->frameCount;
	r24 = 1;
	r18 = r18 - r24;
	if( r16 != r18 ) goto label$b4be4e7_6_97;
	r0->frame = r11;
	r1 = r12;
	goto label$b4be4e7_6_99;
	label$b4be4e7_6_97:
	return r1;
	label$b4be4e7_6_98:
	goto label$b4be4e7_6_30;
	label$b4be4e7_6_99:
	r25 = r0->onAnimEnd;
	if( !r25 ) goto label$b4be4e7_6_137;
	r9 = ((int (*)(h3d__anim__Animation))r0->$type->vobj_proto[2])(r0);
	r6 = r0->speed;
	r10 = 0.;
	if( r6 != r10 ) goto label$b4be4e7_6_107;
	r6 = 0.;
	goto label$b4be4e7_6_114;
	label$b4be4e7_6_107:
	r6 = (double)r9;
	r10 = r0->frame;
	r6 = r6 - r10;
	r10 = r0->speed;
	r11 = r0->sampling;
	r10 = r10 * r11;
	r6 = r6 / r10;
	label$b4be4e7_6_114:
	if( !(r1 >= r6) ) goto label$b4be4e7_6_137;
	r11 = 0.;
	if( !(r11 < r6) ) goto label$b4be4e7_6_137;
	r10 = (double)r9;
	r0->frame = r10;
	r10 = r1 - r6;
	r1 = r10;
	r25 = r0->onAnimEnd;
	if( r25 == NULL ) hl_null_access();
	r25->hasValue ? ((void (*)(vdynamic*))r25->fun)((vdynamic*)r25->value) : ((void (*)(void))r25->fun)();
	r10 = r0->frame;
	r11 = (double)r9;
	if( r10 != r11 ) goto label$b4be4e7_6_136;
	r3 = h3d_anim_Animation_isPlaying(r0);
	if( !r3 ) goto label$b4be4e7_6_136;
	r3 = r0->loop;
	if( !r3 ) goto label$b4be4e7_6_134;
	r10 = 0.;
	r0->frame = r10;
	goto label$b4be4e7_6_136;
	label$b4be4e7_6_134:
	r10 = 0.;
	r1 = r10;
	label$b4be4e7_6_136:
	return r1;
	label$b4be4e7_6_137:
	r6 = r0->frame;
	r11 = r0->speed;
	r10 = r1 * r11;
	r11 = r0->sampling;
	r10 = r10 * r11;
	r6 = r6 + r10;
	r0->frame = r6;
	r6 = r0->frame;
	r9 = r0->frameCount;
	r10 = (double)r9;
	if( !(r6 >= r10) ) goto label$b4be4e7_6_159;
	r3 = r0->loop;
	if( !r3 ) goto label$b4be4e7_6_156;
	r6 = r0->frame;
	r9 = r0->frameCount;
	r10 = (double)r9;
	r6 = fmod(r6,r10);
	r0->frame = r6;
	goto label$b4be4e7_6_159;
	label$b4be4e7_6_156:
	r9 = r0->frameCount;
	r6 = (double)r9;
	r0->frame = r6;
	label$b4be4e7_6_159:
	r6 = 0.;
	return r6;
}

