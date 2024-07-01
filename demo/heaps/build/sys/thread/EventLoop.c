﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <sys/thread/EventLoop.h>
#include <hl/natives.h>
extern hl_type t$sys_thread__EventLoop_RegularEvent;
void sys_thread__EventLoop_RegularEvent_new(sys__thread___EventLoop__RegularEvent,vclosure*,double,double);
void sys_thread_Lock_release(sys__thread__Lock);
#include <sys/thread/NextEventTime.h>
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern hl_type t$_f64;
bool sys_thread_Lock_wait(sys__thread__Lock,vdynamic*);
void hl_types_ArrayObj___expand(hl__types__ArrayObj,int);
extern hl_type t$fun_7b48b4f;
double haxe_MainLoop_tick(void);
bool haxe_MainLoop_hasEvents(void);
extern hl_type t$sys_thread_NextEventTime;
extern venum* g$sys_thread_NextEventTime_Now;
extern venum* g$sys_thread_NextEventTime_Never;
double Math_max(double,double);
extern hl_type t$sys_thread_Lock;
void sys_thread_Lock_new(sys__thread__Lock);
extern hl_type t$hl_types_ArrayObj;
void hl_types_ArrayObj_new(hl__types__ArrayObj);
hl_mutex* sys_thread__Mutex_Mutex_Impl___new(void);
extern sys__thread__$EventLoop g$_sys_thread_EventLoop;

sys__thread___EventLoop__RegularEvent sys_thread_EventLoop_repeat(sys__thread__EventLoop r0,vclosure* r1,int r2) {
	bool r12;
	sys__thread___EventLoop__RegularEvent r7, r9, r10, r11, r13;
	sys__thread__Lock r14;
	hl_mutex *r4;
	double r5, r6, r8;
	r4 = r0->mutex;
	hl_mutex_acquire(r4);
	r5 = 0.001000000000000000021;
	r6 = (double)r2;
	r5 = r5 * r6;
	r7 = (sys__thread___EventLoop__RegularEvent)hl_alloc_obj(&t$sys_thread__EventLoop_RegularEvent);
	r6 = hl_sys_time();
	r6 = r6 + r5;
	sys_thread__EventLoop_RegularEvent_new(r7,r1,r6,r5);
	r9 = r0->regularEvents;
	if( r9 ) goto label$93e7ec3_1_13;
	r0->regularEvents = r7;
	goto label$93e7ec3_1_43;
	label$93e7ec3_1_13:
	r10 = r9;
	r11 = NULL;
	label$93e7ec3_1_15:
	r12 = true;
	if( !r12 ) goto label$93e7ec3_1_43;
	if( r10 ) goto label$93e7ec3_1_24;
	if( r11 == NULL ) hl_null_access();
	r11->next = r7;
	if( r7 == NULL ) hl_null_access();
	r7->previous = r11;
	goto label$93e7ec3_1_43;
	label$93e7ec3_1_24:
	if( r7 == NULL ) hl_null_access();
	r6 = r7->nextRunTime;
	if( r10 == NULL ) hl_null_access();
	r8 = r10->nextRunTime;
	if( !(r6 < r8) ) goto label$93e7ec3_1_39;
	r7->next = r10;
	r10->previous = r7;
	if( r11 ) goto label$93e7ec3_1_34;
	r0->regularEvents = r7;
	goto label$93e7ec3_1_38;
	label$93e7ec3_1_34:
	r7->previous = r11;
	if( r11 == NULL ) hl_null_access();
	r11->next = r7;
	r10->previous = r7;
	label$93e7ec3_1_38:
	goto label$93e7ec3_1_43;
	label$93e7ec3_1_39:
	r11 = r10;
	r13 = r10->next;
	r10 = r13;
	goto label$93e7ec3_1_15;
	label$93e7ec3_1_43:
	r14 = r0->waitLock;
	if( r14 == NULL ) hl_null_access();
	sys_thread_Lock_release(r14);
	r4 = r0->mutex;
	hl_mutex_release(r4);
	return r7;
}

void sys_thread_EventLoop_cancel(sys__thread__EventLoop r0,sys__thread___EventLoop__RegularEvent r1) {
	bool r5;
	sys__thread___EventLoop__RegularEvent r4, r6, r7;
	hl_mutex *r3;
	r3 = r0->mutex;
	hl_mutex_acquire(r3);
	if( r1 == NULL ) hl_null_access();
	r5 = true;
	r1->cancelled = r5;
	r4 = r0->regularEvents;
	if( r4 != r1 ) goto label$93e7ec3_2_9;
	r4 = r1->next;
	r0->regularEvents = r4;
	label$93e7ec3_2_9:
	r4 = r1->next;
	if( !r4 ) goto label$93e7ec3_2_14;
	if( r4 == NULL ) hl_null_access();
	r7 = r1->previous;
	r4->previous = r7;
	label$93e7ec3_2_14:
	r4 = r1->previous;
	if( !r4 ) goto label$93e7ec3_2_19;
	if( r4 == NULL ) hl_null_access();
	r7 = r1->next;
	r4->next = r7;
	label$93e7ec3_2_19:
	r6 = NULL;
	r1->previous = r6;
	r1->next = r6;
	r3 = r0->mutex;
	hl_mutex_release(r3);
	return;
}

venum* sys_thread_EventLoop_progress(sys__thread__EventLoop r0) {
	hl__types__ArrayObj r3, r16, r24, r25;
	venum *r32;
	hl_type *r5;
	bool r9, r30;
	sys__thread___EventLoop__RegularEvent r13, r14;
	sys__thread__Lock r10;
	hl_mutex *r8;
	vclosure *r23, *r26;
	double r1, r7, r11, r15, r31;
	vdynamic *r12, *r22;
	int r6, r17, r18, r19, r20, r21, r27, r28, r29;
	varray *r4;
	r1 = hl_sys_time();
	r5 = &t$sys_thread__EventLoop_RegularEvent;
	r6 = 0;
	r4 = hl_alloc_array(r5,r6);
	r3 = hl_types_ArrayObj_alloc(r4);
	r6 = 0;
	r7 = -1.;
	r8 = r0->mutex;
	hl_mutex_acquire(r8);
	label$93e7ec3_3_9:
	r10 = r0->waitLock;
	if( r10 == NULL ) hl_null_access();
	r11 = 0.;
	r12 = hl_alloc_dynamic(&t$_f64);
	r12->v.d = r11;
	r9 = sys_thread_Lock_wait(r10,r12);
	if( !r9 ) goto label$93e7ec3_3_17;
	goto label$93e7ec3_3_9;
	label$93e7ec3_3_17:
	r13 = r0->regularEvents;
	label$93e7ec3_3_18:
	if( !r13 ) goto label$93e7ec3_3_47;
	if( r13 == NULL ) hl_null_access();
	r11 = r13->nextRunTime;
	if( !(r1 >= r11) ) goto label$93e7ec3_3_38;
	if( r3 == NULL ) hl_null_access();
	r17 = r6;
	++r6;
	r18 = r3->length;
	if( ((unsigned)r17) < ((unsigned)r18) ) goto label$93e7ec3_3_29;
	hl_types_ArrayObj___expand(r3,r17);
	label$93e7ec3_3_29:
	r4 = r3->array;
	((sys__thread___EventLoop__RegularEvent*)(r4 + 1))[r17] = r13;
	r11 = r13->nextRunTime;
	r15 = r13->interval;
	r11 = r11 + r15;
	r13->nextRunTime = r11;
	r11 = -2.;
	r7 = r11;
	goto label$93e7ec3_3_44;
	label$93e7ec3_3_38:
	r15 = -1.;
	if( r7 == r15 ) goto label$93e7ec3_3_42;
	r11 = r13->nextRunTime;
	if( !(r11 < r7) ) goto label$93e7ec3_3_44;
	label$93e7ec3_3_42:
	r11 = r13->nextRunTime;
	r7 = r11;
	label$93e7ec3_3_44:
	r14 = r13->next;
	r13 = r14;
	goto label$93e7ec3_3_18;
	label$93e7ec3_3_47:
	r8 = r0->mutex;
	hl_mutex_release(r8);
	r17 = 0;
	r18 = r6;
	label$93e7ec3_3_51:
	if( r17 >= r18 ) goto label$93e7ec3_3_84;
	r19 = r17;
	++r17;
	if( r3 == NULL ) hl_null_access();
	r21 = r3->length;
	if( ((unsigned)r19) < ((unsigned)r21) ) goto label$93e7ec3_3_60;
	r14 = NULL;
	goto label$93e7ec3_3_63;
	label$93e7ec3_3_60:
	r4 = r3->array;
	r22 = ((vdynamic**)(r4 + 1))[r19];
	r14 = (sys__thread___EventLoop__RegularEvent)r22;
	label$93e7ec3_3_63:
	if( r14 == NULL ) hl_null_access();
	r9 = r14->cancelled;
	if( r9 ) goto label$93e7ec3_3_77;
	r21 = r3->length;
	if( ((unsigned)r19) < ((unsigned)r21) ) goto label$93e7ec3_3_70;
	r14 = NULL;
	goto label$93e7ec3_3_73;
	label$93e7ec3_3_70:
	r4 = r3->array;
	r22 = ((vdynamic**)(r4 + 1))[r19];
	r14 = (sys__thread___EventLoop__RegularEvent)r22;
	label$93e7ec3_3_73:
	if( r14 == NULL ) hl_null_access();
	r23 = r14->run;
	if( r23 == NULL ) hl_null_access();
	r23->hasValue ? ((void (*)(vdynamic*))r23->fun)((vdynamic*)r23->value) : ((void (*)(void))r23->fun)();
	label$93e7ec3_3_77:
	r14 = NULL;
	r21 = r3->length;
	if( ((unsigned)r19) < ((unsigned)r21) ) goto label$93e7ec3_3_81;
	hl_types_ArrayObj___expand(r3,r19);
	label$93e7ec3_3_81:
	r4 = r3->array;
	((sys__thread___EventLoop__RegularEvent*)(r4 + 1))[r19] = r14;
	goto label$93e7ec3_3_51;
	label$93e7ec3_3_84:
	r19 = 0;
	r6 = r19;
	r5 = &t$fun_7b48b4f;
	r19 = 0;
	r4 = hl_alloc_array(r5,r19);
	r16 = hl_types_ArrayObj_alloc(r4);
	r8 = r0->mutex;
	hl_mutex_acquire(r8);
	r19 = 0;
	r24 = r0->oneTimeEvents;
	label$93e7ec3_3_94:
	if( r24 == NULL ) hl_null_access();
	r21 = r24->length;
	if( r19 >= r21 ) goto label$93e7ec3_3_126;
	r21 = r24->length;
	if( ((unsigned)r19) < ((unsigned)r21) ) goto label$93e7ec3_3_102;
	r23 = NULL;
	goto label$93e7ec3_3_105;
	label$93e7ec3_3_102:
	r4 = r24->array;
	r22 = ((vdynamic**)(r4 + 1))[r19];
	r23 = (vclosure*)r22;
	label$93e7ec3_3_105:
	r20 = r19;
	++r19;
	if( r23 ) goto label$93e7ec3_3_109;
	goto label$93e7ec3_3_126;
	label$93e7ec3_3_109:
	if( r16 == NULL ) hl_null_access();
	r27 = r6;
	++r6;
	r28 = r16->length;
	if( ((unsigned)r27) < ((unsigned)r28) ) goto label$93e7ec3_3_115;
	hl_types_ArrayObj___expand(r16,r27);
	label$93e7ec3_3_115:
	r4 = r16->array;
	((vclosure**)(r4 + 1))[r27] = r23;
	r25 = r0->oneTimeEvents;
	if( r25 == NULL ) hl_null_access();
	r26 = NULL;
	r28 = r25->length;
	if( ((unsigned)r20) < ((unsigned)r28) ) goto label$93e7ec3_3_123;
	hl_types_ArrayObj___expand(r25,r20);
	label$93e7ec3_3_123:
	r4 = r25->array;
	((vclosure**)(r4 + 1))[r20] = r26;
	goto label$93e7ec3_3_94;
	label$93e7ec3_3_126:
	r20 = 0;
	r0->oneTimeEventsIdx = r20;
	r20 = r0->promisedEventsCount;
	r21 = 0;
	if( r20 > r21 ) goto label$93e7ec3_3_133;
	r9 = false;
	goto label$93e7ec3_3_134;
	label$93e7ec3_3_133:
	r9 = true;
	label$93e7ec3_3_134:
	r8 = r0->mutex;
	hl_mutex_release(r8);
	r20 = 0;
	r21 = r6;
	label$93e7ec3_3_138:
	if( r20 >= r21 ) goto label$93e7ec3_3_159;
	r27 = r20;
	++r20;
	if( r16 == NULL ) hl_null_access();
	r29 = r16->length;
	if( ((unsigned)r27) < ((unsigned)r29) ) goto label$93e7ec3_3_147;
	r23 = NULL;
	goto label$93e7ec3_3_150;
	label$93e7ec3_3_147:
	r4 = r16->array;
	r22 = ((vdynamic**)(r4 + 1))[r27];
	r23 = (vclosure*)r22;
	label$93e7ec3_3_150:
	if( r23 == NULL ) hl_null_access();
	r23->hasValue ? ((void (*)(vdynamic*))r23->fun)((vdynamic*)r23->value) : ((void (*)(void))r23->fun)();
	r23 = NULL;
	r29 = r16->length;
	if( ((unsigned)r27) < ((unsigned)r29) ) goto label$93e7ec3_3_156;
	hl_types_ArrayObj___expand(r16,r27);
	label$93e7ec3_3_156:
	r4 = r16->array;
	((vclosure**)(r4 + 1))[r27] = r23;
	goto label$93e7ec3_3_138;
	label$93e7ec3_3_159:
	r30 = r0->isMainThread;
	if( !r30 ) goto label$93e7ec3_3_167;
	r11 = haxe_MainLoop_tick();
	r30 = haxe_MainLoop_hasEvents();
	if( !r30 ) goto label$93e7ec3_3_167;
	++r6;
	if( !(r11 < r7) ) goto label$93e7ec3_3_167;
	r7 = r11;
	label$93e7ec3_3_167:
	r28 = 0;
	if( r28 >= r6 ) goto label$93e7ec3_3_171;
	r11 = -2.;
	r7 = r11;
	label$93e7ec3_3_171:
	r31 = -2.;
	if( r31 == r7 ) goto label$93e7ec3_3_181;
	r31 = -1.;
	if( r31 == r7 ) goto label$93e7ec3_3_183;
	if( !r9 ) goto label$93e7ec3_3_179;
	r12 = hl_alloc_dynamic(&t$_f64);
	r12->v.d = r7;
	r32 = hl_alloc_enum(&t$sys_thread_NextEventTime,2);
	((sys_thread_NextEventTime_AnyTime*)r32)->p0 = r12;
	return r32;
	label$93e7ec3_3_179:
	r32 = hl_alloc_enum(&t$sys_thread_NextEventTime,3);
	((sys_thread_NextEventTime_At*)r32)->p0 = r7;
	return r32;
	label$93e7ec3_3_181:
	r32 = (venum*)g$sys_thread_NextEventTime_Now;
	return r32;
	label$93e7ec3_3_183:
	if( !r9 ) goto label$93e7ec3_3_187;
	r12 = NULL;
	r32 = hl_alloc_enum(&t$sys_thread_NextEventTime,2);
	((sys_thread_NextEventTime_AnyTime*)r32)->p0 = r12;
	return r32;
	label$93e7ec3_3_187:
	r32 = (venum*)g$sys_thread_NextEventTime_Never;
	return r32;
}

void sys_thread_EventLoop_loop(sys__thread__EventLoop r0) {
	hl__types__ArrayObj r1, r6, r9, r18, r26, r27;
	hl_type *r3;
	bool r7, r32, r35;
	sys__thread___EventLoop__RegularEvent r15, r16;
	sys__thread__Lock r12;
	hl_mutex *r11;
	vclosure *r25, *r28;
	double r8, r10, r13, r17, r33, r34;
	vdynamic *r14, *r24;
	int r4, r19, r20, r21, r22, r23, r29, r30, r31;
	varray *r2;
	r3 = &t$sys_thread__EventLoop_RegularEvent;
	r4 = 0;
	r2 = hl_alloc_array(r3,r4);
	r1 = hl_types_ArrayObj_alloc(r2);
	r3 = &t$fun_7b48b4f;
	r4 = 0;
	r2 = hl_alloc_array(r3,r4);
	r6 = hl_types_ArrayObj_alloc(r2);
	label$93e7ec3_4_8:
	r7 = true;
	if( !r7 ) goto label$93e7ec3_4_198;
	r8 = hl_sys_time();
	r9 = r1;
	r4 = 0;
	r10 = -1.;
	r11 = r0->mutex;
	hl_mutex_acquire(r11);
	label$93e7ec3_4_17:
	r12 = r0->waitLock;
	if( r12 == NULL ) hl_null_access();
	r13 = 0.;
	r14 = hl_alloc_dynamic(&t$_f64);
	r14->v.d = r13;
	r7 = sys_thread_Lock_wait(r12,r14);
	if( !r7 ) goto label$93e7ec3_4_25;
	goto label$93e7ec3_4_17;
	label$93e7ec3_4_25:
	r15 = r0->regularEvents;
	label$93e7ec3_4_26:
	if( !r15 ) goto label$93e7ec3_4_55;
	if( r15 == NULL ) hl_null_access();
	r13 = r15->nextRunTime;
	if( !(r8 >= r13) ) goto label$93e7ec3_4_46;
	if( r9 == NULL ) hl_null_access();
	r19 = r4;
	++r4;
	r20 = r9->length;
	if( ((unsigned)r19) < ((unsigned)r20) ) goto label$93e7ec3_4_37;
	hl_types_ArrayObj___expand(r9,r19);
	label$93e7ec3_4_37:
	r2 = r9->array;
	((sys__thread___EventLoop__RegularEvent*)(r2 + 1))[r19] = r15;
	r13 = r15->nextRunTime;
	r17 = r15->interval;
	r13 = r13 + r17;
	r15->nextRunTime = r13;
	r13 = -2.;
	r10 = r13;
	goto label$93e7ec3_4_52;
	label$93e7ec3_4_46:
	r17 = -1.;
	if( r10 == r17 ) goto label$93e7ec3_4_50;
	r13 = r15->nextRunTime;
	if( !(r13 < r10) ) goto label$93e7ec3_4_52;
	label$93e7ec3_4_50:
	r13 = r15->nextRunTime;
	r10 = r13;
	label$93e7ec3_4_52:
	r16 = r15->next;
	r15 = r16;
	goto label$93e7ec3_4_26;
	label$93e7ec3_4_55:
	r11 = r0->mutex;
	hl_mutex_release(r11);
	r19 = 0;
	r20 = r4;
	label$93e7ec3_4_59:
	if( r19 >= r20 ) goto label$93e7ec3_4_92;
	r21 = r19;
	++r19;
	if( r9 == NULL ) hl_null_access();
	r23 = r9->length;
	if( ((unsigned)r21) < ((unsigned)r23) ) goto label$93e7ec3_4_68;
	r16 = NULL;
	goto label$93e7ec3_4_71;
	label$93e7ec3_4_68:
	r2 = r9->array;
	r24 = ((vdynamic**)(r2 + 1))[r21];
	r16 = (sys__thread___EventLoop__RegularEvent)r24;
	label$93e7ec3_4_71:
	if( r16 == NULL ) hl_null_access();
	r7 = r16->cancelled;
	if( r7 ) goto label$93e7ec3_4_85;
	r23 = r9->length;
	if( ((unsigned)r21) < ((unsigned)r23) ) goto label$93e7ec3_4_78;
	r16 = NULL;
	goto label$93e7ec3_4_81;
	label$93e7ec3_4_78:
	r2 = r9->array;
	r24 = ((vdynamic**)(r2 + 1))[r21];
	r16 = (sys__thread___EventLoop__RegularEvent)r24;
	label$93e7ec3_4_81:
	if( r16 == NULL ) hl_null_access();
	r25 = r16->run;
	if( r25 == NULL ) hl_null_access();
	r25->hasValue ? ((void (*)(vdynamic*))r25->fun)((vdynamic*)r25->value) : ((void (*)(void))r25->fun)();
	label$93e7ec3_4_85:
	r16 = NULL;
	r23 = r9->length;
	if( ((unsigned)r21) < ((unsigned)r23) ) goto label$93e7ec3_4_89;
	hl_types_ArrayObj___expand(r9,r21);
	label$93e7ec3_4_89:
	r2 = r9->array;
	((sys__thread___EventLoop__RegularEvent*)(r2 + 1))[r21] = r16;
	goto label$93e7ec3_4_59;
	label$93e7ec3_4_92:
	r21 = 0;
	r4 = r21;
	r18 = r6;
	r11 = r0->mutex;
	hl_mutex_acquire(r11);
	r21 = 0;
	r26 = r0->oneTimeEvents;
	label$93e7ec3_4_99:
	if( r26 == NULL ) hl_null_access();
	r23 = r26->length;
	if( r21 >= r23 ) goto label$93e7ec3_4_131;
	r23 = r26->length;
	if( ((unsigned)r21) < ((unsigned)r23) ) goto label$93e7ec3_4_107;
	r25 = NULL;
	goto label$93e7ec3_4_110;
	label$93e7ec3_4_107:
	r2 = r26->array;
	r24 = ((vdynamic**)(r2 + 1))[r21];
	r25 = (vclosure*)r24;
	label$93e7ec3_4_110:
	r22 = r21;
	++r21;
	if( r25 ) goto label$93e7ec3_4_114;
	goto label$93e7ec3_4_131;
	label$93e7ec3_4_114:
	if( r18 == NULL ) hl_null_access();
	r29 = r4;
	++r4;
	r30 = r18->length;
	if( ((unsigned)r29) < ((unsigned)r30) ) goto label$93e7ec3_4_120;
	hl_types_ArrayObj___expand(r18,r29);
	label$93e7ec3_4_120:
	r2 = r18->array;
	((vclosure**)(r2 + 1))[r29] = r25;
	r27 = r0->oneTimeEvents;
	if( r27 == NULL ) hl_null_access();
	r28 = NULL;
	r30 = r27->length;
	if( ((unsigned)r22) < ((unsigned)r30) ) goto label$93e7ec3_4_128;
	hl_types_ArrayObj___expand(r27,r22);
	label$93e7ec3_4_128:
	r2 = r27->array;
	((vclosure**)(r2 + 1))[r22] = r28;
	goto label$93e7ec3_4_99;
	label$93e7ec3_4_131:
	r22 = 0;
	r0->oneTimeEventsIdx = r22;
	r22 = r0->promisedEventsCount;
	r23 = 0;
	if( r22 > r23 ) goto label$93e7ec3_4_138;
	r7 = false;
	goto label$93e7ec3_4_139;
	label$93e7ec3_4_138:
	r7 = true;
	label$93e7ec3_4_139:
	r11 = r0->mutex;
	hl_mutex_release(r11);
	r22 = 0;
	r23 = r4;
	label$93e7ec3_4_143:
	if( r22 >= r23 ) goto label$93e7ec3_4_164;
	r29 = r22;
	++r22;
	if( r18 == NULL ) hl_null_access();
	r31 = r18->length;
	if( ((unsigned)r29) < ((unsigned)r31) ) goto label$93e7ec3_4_152;
	r25 = NULL;
	goto label$93e7ec3_4_155;
	label$93e7ec3_4_152:
	r2 = r18->array;
	r24 = ((vdynamic**)(r2 + 1))[r29];
	r25 = (vclosure*)r24;
	label$93e7ec3_4_155:
	if( r25 == NULL ) hl_null_access();
	r25->hasValue ? ((void (*)(vdynamic*))r25->fun)((vdynamic*)r25->value) : ((void (*)(void))r25->fun)();
	r25 = NULL;
	r31 = r18->length;
	if( ((unsigned)r29) < ((unsigned)r31) ) goto label$93e7ec3_4_161;
	hl_types_ArrayObj___expand(r18,r29);
	label$93e7ec3_4_161:
	r2 = r18->array;
	((vclosure**)(r2 + 1))[r29] = r25;
	goto label$93e7ec3_4_143;
	label$93e7ec3_4_164:
	r32 = r0->isMainThread;
	if( !r32 ) goto label$93e7ec3_4_172;
	r13 = haxe_MainLoop_tick();
	r32 = haxe_MainLoop_hasEvents();
	if( !r32 ) goto label$93e7ec3_4_172;
	++r4;
	if( !(r13 < r10) ) goto label$93e7ec3_4_172;
	r10 = r13;
	label$93e7ec3_4_172:
	r30 = 0;
	if( r30 >= r4 ) goto label$93e7ec3_4_176;
	r13 = -2.;
	r10 = r13;
	label$93e7ec3_4_176:
	r33 = -2.;
	if( r33 == r10 ) goto label$93e7ec3_4_189;
	r33 = -1.;
	if( r33 == r10 ) goto label$93e7ec3_4_190;
	r34 = hl_sys_time();
	r33 = r10 - r34;
	r12 = r0->waitLock;
	if( r12 == NULL ) hl_null_access();
	r34 = 0.;
	r34 = Math_max(r34,r33);
	r14 = hl_alloc_dynamic(&t$_f64);
	r14->v.d = r34;
	r35 = sys_thread_Lock_wait(r12,r14);
	goto label$93e7ec3_4_197;
	label$93e7ec3_4_189:
	goto label$93e7ec3_4_197;
	label$93e7ec3_4_190:
	if( !r7 ) goto label$93e7ec3_4_196;
	r12 = r0->waitLock;
	if( r12 == NULL ) hl_null_access();
	r14 = NULL;
	r35 = sys_thread_Lock_wait(r12,r14);
	goto label$93e7ec3_4_197;
	label$93e7ec3_4_196:
	goto label$93e7ec3_4_198;
	label$93e7ec3_4_197:
	goto label$93e7ec3_4_8;
	label$93e7ec3_4_198:
	return;
}

void sys_thread_EventLoop_new(sys__thread__EventLoop r0) {
	hl__types__ArrayObj r4;
	bool r6;
	sys__thread__$EventLoop r7;
	sys__thread__Lock r2;
	hl_mutex *r5;
	int r1;
	r1 = 0;
	r0->promisedEventsCount = r1;
	r2 = (sys__thread__Lock)hl_alloc_obj(&t$sys_thread_Lock);
	sys_thread_Lock_new(r2);
	r0->waitLock = r2;
	r1 = 0;
	r0->oneTimeEventsIdx = r1;
	r4 = (hl__types__ArrayObj)hl_alloc_obj(&t$hl_types_ArrayObj);
	hl_types_ArrayObj_new(r4);
	r0->oneTimeEvents = r4;
	r5 = sys_thread__Mutex_Mutex_Impl___new();
	r0->mutex = r5;
	r7 = (sys__thread__$EventLoop)g$_sys_thread_EventLoop;
	r6 = r7->CREATED;
	r6 = !r6;
	r0->isMainThread = r6;
	r6 = true;
	r7 = (sys__thread__$EventLoop)g$_sys_thread_EventLoop;
	r7->CREATED = r6;
	return;
}

