﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <sdl/Window.h>
#include <hl/natives.h>
#include <sdl/Sdl.h>
extern String s$Failed_to_create_window;
bool sdl_Window_testGL(sdl__Window);
void sdl_Window_destroy(sdl__Window);
extern sdl__$Sdl g$_sdl_Sdl;
String sdl_Window_set_title(sdl__Window,String);
extern sdl__$Window g$_sdl_Window;
int hl_types_ArrayObj_push(hl__types__ArrayObj,vdynamic*);
bool sdl_Window_set_vsync(sdl__Window,bool);
#include <_std/EReg.h>
extern hl_type t$EReg;
extern String s$_0_9_0_9_;
extern String s$;
void EReg_new(EReg,String,String);
vdynamic* sdl_GL_getParameter(int);
extern hl_type t$String;
extern hl_type t$_dyn;
extern String s$ES;
int String_indexOf(String,String,vdynamic*);
bool EReg_match(EReg,String);
String EReg_matched(EReg,int);
double Std_parseFloat(String);
double Math_min(double,double);
extern String s$_version_;
String String___alloc__(vbyte*,int);
String String___add__(String,String);
extern String s$bfb0374;
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern String s$68b329d;
String hl_types_ArrayObj_join(hl__types__ArrayObj,String);
extern String s$Failed_to_compile_VS_;
String sdl_GL_getShaderInfoLog(vdynamic*);
extern String s$9371d7a;
extern String s$de77e85;
extern String s$3302c20;
extern String s$Failed_to_compile_FS_;
extern String s$Failed_to_link_;
String sdl_GL_getProgramInfoLog(vdynamic*);
vbyte* String_toUtf8(String);
extern hl_type t$_i32;
bool hl_types_ArrayObj_remove(hl__types__ArrayObj,vdynamic*);

void sdl_Window_new(sdl__Window r0,String r1,int r2,int r3,int* r4,int* r5,int* r6) {
	sdl_gl *r15;
	String r14;
	sdl_window *r11;
	hl__types__ArrayObj r19;
	sdl__$Sdl r17;
	bool r10;
	sdl__$Window r20;
	vclosure *r16, *r18;
	int r7, r8, r9, r12;
	if( r4 ) goto label$9a2f713_1_3;
	r7 = 805240832;
	goto label$9a2f713_1_4;
	label$9a2f713_1_3:
	r7 = *r4;
	label$9a2f713_1_4:
	if( r5 ) goto label$9a2f713_1_7;
	r8 = 805240832;
	goto label$9a2f713_1_8;
	label$9a2f713_1_7:
	r8 = *r5;
	label$9a2f713_1_8:
	if( r6 ) goto label$9a2f713_1_11;
	r9 = 36;
	goto label$9a2f713_1_12;
	label$9a2f713_1_11:
	r9 = *r6;
	label$9a2f713_1_12:
	r10 = true;
	if( !r10 ) goto label$9a2f713_1_41;
	r11 = sdl_win_create_ex(r7,r8,r2,r3,r9);
	r0->win = r11;
	r11 = r0->win;
	if( r11 ) goto label$9a2f713_1_21;
	r14 = (String)s$Failed_to_create_window;
	hl_throw((vdynamic*)r14);
	label$9a2f713_1_21:
	r11 = r0->win;
	r15 = sdl_win_get_glcontext(r11);
	r0->glctx = r15;
	r15 = r0->glctx;
	if( !r15 ) goto label$9a2f713_1_30;
	r10 = sdl_gl_init();
	if( !r10 ) goto label$9a2f713_1_30;
	r10 = sdl_Window_testGL(r0);
	if( r10 ) goto label$9a2f713_1_41;
	label$9a2f713_1_30:
	sdl_Window_destroy(r0);
	r17 = (sdl__$Sdl)g$_sdl_Sdl;
	r16 = r17->onGlContextRetry;
	if( r16 == NULL ) hl_null_access();
	r10 = r16->hasValue ? ((bool (*)(vdynamic*))r16->fun)((vdynamic*)r16->value) : ((bool (*)(void))r16->fun)();
	if( !r10 ) goto label$9a2f713_1_37;
	goto label$9a2f713_1_12;
	label$9a2f713_1_37:
	r17 = (sdl__$Sdl)g$_sdl_Sdl;
	r18 = r17->onGlContextError;
	if( r18 == NULL ) hl_null_access();
	r18->hasValue ? ((void (*)(vdynamic*))r18->fun)((vdynamic*)r18->value) : ((void (*)(void))r18->fun)();
	label$9a2f713_1_41:
	r14 = sdl_Window_set_title(r0,r1);
	r20 = (sdl__$Window)g$_sdl_Window;
	r19 = r20->windows;
	if( r19 == NULL ) hl_null_access();
	r12 = hl_types_ArrayObj_push(r19,((vdynamic*)r0));
	r10 = true;
	r10 = sdl_Window_set_vsync(r0,r10);
	return;
}

bool sdl_Window_testGL(sdl__Window r0) {
	String r4, r5, r8, r9;
	hl__types__ArrayObj r18;
	hl_type *r20;
	bool r7, r12;
	EReg r3;
	double r13, r14, r15;
	int *r21;
	vdynamic *r1, *r10, *r17, *r23, *r24;
	vbyte *r22;
	varray *r19;
	int r6, r11, r16;
	hl_trap_ctx trap$0;
	hl_trap(trap$0,r1,label$9a2f713_2_157);
	r3 = (EReg)hl_alloc_obj(&t$EReg);
	r4 = (String)s$_0_9_0_9_;
	r5 = (String)s$;
	EReg_new(r3,r4,r5);
	r6 = 35724;
	r1 = sdl_GL_getParameter(r6);
	r4 = (String)hl_dyn_castp(&r1,&t$_dyn,&t$String);
	r6 = 7938;
	r1 = sdl_GL_getParameter(r6);
	r5 = (String)hl_dyn_castp(&r1,&t$_dyn,&t$String);
	if( !r5 ) goto label$9a2f713_2_20;
	if( r5 == NULL ) hl_null_access();
	r9 = (String)s$ES;
	r10 = NULL;
	r6 = String_indexOf(r5,r9,r10);
	r11 = 0;
	if( r6 < r11 ) goto label$9a2f713_2_20;
	r7 = true;
	goto label$9a2f713_2_21;
	label$9a2f713_2_20:
	r7 = false;
	label$9a2f713_2_21:
	r6 = 120;
	if( !r7 ) goto label$9a2f713_2_37;
	r12 = EReg_match(r3,r4);
	if( !r12 ) goto label$9a2f713_2_36;
	r13 = 100.;
	r11 = 0;
	r8 = EReg_matched(r3,r11);
	r14 = Std_parseFloat(r8);
	r15 = 100.;
	r14 = r14 * r15;
	r11 = hl_math_round(r14);
	r14 = (double)r11;
	r13 = Math_min(r13,r14);
	r11 = (int)r13;
	r6 = r11;
	label$9a2f713_2_36:
	goto label$9a2f713_2_51;
	label$9a2f713_2_37:
	r11 = 130;
	r6 = r11;
	r12 = EReg_match(r3,r4);
	if( !r12 ) goto label$9a2f713_2_51;
	r11 = 150;
	r16 = 0;
	r8 = EReg_matched(r3,r16);
	r13 = Std_parseFloat(r8);
	r14 = 100.;
	r13 = r13 * r14;
	r16 = hl_math_round(r13);
	r6 = r16;
	if( r16 >= r11 ) goto label$9a2f713_2_51;
	r6 = r11;
	label$9a2f713_2_51:
	r11 = 35633;
	r10 = sdl_gl_create_shader(r11);
	r20 = &t$String;
	r11 = 2;
	r19 = hl_alloc_array(r20,r11);
	r8 = (String)s$_version_;
	r11 = r6;
	r21 = &r11;
	r22 = hl_itos(r11,r21);
	r9 = String___alloc__(r22,r11);
	r8 = String___add__(r8,r9);
	r11 = 0;
	((String*)(r19 + 1))[r11] = r8;
	r8 = (String)s$bfb0374;
	r11 = 1;
	((String*)(r19 + 1))[r11] = r8;
	r18 = hl_types_ArrayObj_alloc(r19);
	if( r18 == NULL ) hl_null_access();
	r8 = (String)s$68b329d;
	r8 = hl_types_ArrayObj_join(r18,r8);
	sdl_gl_shader_source(r10,r8);
	sdl_gl_compile_shader(r10);
	r11 = 35713;
	r1 = sdl_gl_get_shader_parameter(r10,r11);
	r13 = (double)hl_dyn_castd(&r1,&t$_dyn);
	r14 = 1.;
	if( r13 == r14 ) goto label$9a2f713_2_84;
	r8 = (String)s$Failed_to_compile_VS_;
	r9 = sdl_GL_getShaderInfoLog(r10);
	r8 = String___add__(r8,r9);
	r9 = (String)s$9371d7a;
	r8 = String___add__(r8,r9);
	hl_throw((vdynamic*)r8);
	label$9a2f713_2_84:
	r11 = 35632;
	r17 = sdl_gl_create_shader(r11);
	if( !r7 ) goto label$9a2f713_2_107;
	r20 = &t$String;
	r11 = 2;
	r19 = hl_alloc_array(r20,r11);
	r8 = (String)s$_version_;
	r11 = r6;
	r21 = &r11;
	r22 = hl_itos(r11,r21);
	r9 = String___alloc__(r22,r11);
	r8 = String___add__(r8,r9);
	r11 = 0;
	((String*)(r19 + 1))[r11] = r8;
	r8 = (String)s$de77e85;
	r11 = 1;
	((String*)(r19 + 1))[r11] = r8;
	r18 = hl_types_ArrayObj_alloc(r19);
	if( r18 == NULL ) hl_null_access();
	r8 = (String)s$68b329d;
	r8 = hl_types_ArrayObj_join(r18,r8);
	sdl_gl_shader_source(r17,r8);
	goto label$9a2f713_2_126;
	label$9a2f713_2_107:
	r20 = &t$String;
	r11 = 2;
	r19 = hl_alloc_array(r20,r11);
	r8 = (String)s$_version_;
	r11 = r6;
	r21 = &r11;
	r22 = hl_itos(r11,r21);
	r9 = String___alloc__(r22,r11);
	r8 = String___add__(r8,r9);
	r11 = 0;
	((String*)(r19 + 1))[r11] = r8;
	r8 = (String)s$3302c20;
	r11 = 1;
	((String*)(r19 + 1))[r11] = r8;
	r18 = hl_types_ArrayObj_alloc(r19);
	if( r18 == NULL ) hl_null_access();
	r8 = (String)s$68b329d;
	r8 = hl_types_ArrayObj_join(r18,r8);
	sdl_gl_shader_source(r17,r8);
	label$9a2f713_2_126:
	sdl_gl_compile_shader(r17);
	r11 = 35713;
	r1 = sdl_gl_get_shader_parameter(r17,r11);
	r13 = (double)hl_dyn_castd(&r1,&t$_dyn);
	r14 = 1.;
	if( r13 == r14 ) goto label$9a2f713_2_138;
	r8 = (String)s$Failed_to_compile_FS_;
	r9 = sdl_GL_getShaderInfoLog(r17);
	r8 = String___add__(r8,r9);
	r9 = (String)s$9371d7a;
	r8 = String___add__(r8,r9);
	hl_throw((vdynamic*)r8);
	label$9a2f713_2_138:
	r23 = sdl_gl_create_program();
	sdl_gl_attach_shader(r23,r10);
	sdl_gl_attach_shader(r23,r17);
	sdl_gl_link_program(r23);
	r11 = 35714;
	r1 = sdl_gl_get_program_parameter(r23,r11);
	r13 = (double)hl_dyn_castd(&r1,&t$_dyn);
	r14 = 1.;
	if( r13 == r14 ) goto label$9a2f713_2_153;
	r8 = (String)s$Failed_to_link_;
	r9 = sdl_GL_getProgramInfoLog(r23);
	r8 = String___add__(r8,r9);
	r9 = (String)s$9371d7a;
	r8 = String___add__(r8,r9);
	hl_throw((vdynamic*)r8);
	label$9a2f713_2_153:
	sdl_gl_delete_shader(r10);
	sdl_gl_delete_shader(r17);
	hl_endtrap(trap$0);
	goto label$9a2f713_2_160;
	label$9a2f713_2_157:
	r24 = NULL;
	r7 = false;
	return r7;
	label$9a2f713_2_160:
	r7 = true;
	return r7;
}

String sdl_Window_set_title(sdl__Window r0,String r1) {
	sdl_window *r3;
	vbyte *r4;
	r3 = r0->win;
	if( r1 == NULL ) hl_null_access();
	r4 = String_toUtf8(r1);
	sdl_win_set_title(r3,r4);
	r0->title = r1;
	return r1;
}

int sdl_Window_set_displayMode(sdl__Window r0,int r1) {
	sdl_window *r3;
	vvirtual *r7;
	bool r2;
	vdynamic *r6;
	int r4, r5, r8;
	hl_trap_ctx trap$0;
	r3 = r0->win;
	r2 = sdl_win_set_fullscreen(r3,r1);
	if( !r2 ) goto label$9a2f713_4_19;
	r0->displayMode = r1;
	r5 = 1;
	if( r1 != r5 ) goto label$9a2f713_4_19;
	hl_trap(trap$0,r6,label$9a2f713_4_19);
	r3 = r0->win;
	r7 = r0->displaySetting;
	if( r7 == NULL ) hl_null_access();
	r4 = hl_vfields(r7)[2] ? (*(int*)(hl_vfields(r7)[2])) : (int)hl_dyn_geti(r7->value,-362629759/*width*/,&t$_i32);
	r7 = r0->displaySetting;
	if( r7 == NULL ) hl_null_access();
	r5 = hl_vfields(r7)[1] ? (*(int*)(hl_vfields(r7)[1])) : (int)hl_dyn_geti(r7->value,38537191/*height*/,&t$_i32);
	r7 = r0->displaySetting;
	if( r7 == NULL ) hl_null_access();
	r8 = hl_vfields(r7)[0] ? (*(int*)(hl_vfields(r7)[0])) : (int)hl_dyn_geti(r7->value,239855255/*framerate*/,&t$_i32);
	r2 = sdl_win_set_display_mode(r3,r4,r5,r8);
	hl_endtrap(trap$0);
	label$9a2f713_4_19:
	r4 = r0->displayMode;
	return r4;
}

void sdl_Window_resize(sdl__Window r0,int r1,int r2) {
	sdl_window *r4;
	r4 = r0->win;
	sdl_win_set_size(r4,r1,r2);
	return;
}

void sdl_Window_setPosition(sdl__Window r0,int r1,int r2) {
	sdl_window *r4;
	r4 = r0->win;
	sdl_win_set_position(r4,r1,r2);
	return;
}

int sdl_Window_get_width(sdl__Window r0) {
	sdl_window *r3;
	int *r4, *r5;
	int r1;
	r1 = 0;
	r3 = r0->win;
	r4 = &r1;
	r5 = NULL;
	sdl_win_get_size(r3,r4,r5);
	return r1;
}

int sdl_Window_get_height(sdl__Window r0) {
	sdl_window *r3;
	int *r4, *r5;
	int r1;
	r1 = 0;
	r3 = r0->win;
	r4 = NULL;
	r5 = &r1;
	sdl_win_get_size(r3,r4,r5);
	return r1;
}

int sdl_Window_get_x(sdl__Window r0) {
	sdl_window *r3;
	int *r4, *r5;
	int r1;
	r1 = 0;
	r3 = r0->win;
	r4 = &r1;
	r5 = NULL;
	sdl_win_get_position(r3,r4,r5);
	return r1;
}

int sdl_Window_get_y(sdl__Window r0) {
	sdl_window *r3;
	int *r4, *r5;
	int r1;
	r1 = 0;
	r3 = r0->win;
	r4 = NULL;
	r5 = &r1;
	sdl_win_get_position(r3,r4,r5);
	return r1;
}

int sdl_Window_get_currentMonitor(sdl__Window r0) {
	sdl_window *r2;
	int r1;
	r2 = r0->win;
	r1 = sdl_win_display_handle(r2);
	return r1;
}

bool sdl_Window_set_vsync(sdl__Window r0,bool r1) {
	sdl_set_vsync(r1);
	r0->vsync = r1;
	return r1;
}

void sdl_Window_present(sdl__Window r0) {
	sdl_window *r7;
	sdl__$Sdl r3;
	bool r2;
	double r4, r5, r6;
	r2 = r0->vsync;
	if( !r2 ) goto label$9a2f713_13_13;
	r3 = (sdl__$Sdl)g$_sdl_Sdl;
	r2 = r3->isWin32;
	if( !r2 ) goto label$9a2f713_13_13;
	r4 = hl_sys_time();
	r5 = r0->lastFrame;
	r4 = r4 - r5;
	r6 = 0.005000000000000000104;
	if( !(r4 < r6) ) goto label$9a2f713_13_13;
	r5 = 0.005000000000000000104;
	r5 = r5 - r4;
	hl_sys_sleep(r5);
	label$9a2f713_13_13:
	r7 = r0->win;
	sdl_win_swap_window(r7);
	r4 = hl_sys_time();
	r0->lastFrame = r4;
	return;
}

void sdl_Window_destroy(sdl__Window r0) {
	sdl_gl *r4;
	sdl_window *r3;
	hl__types__ArrayObj r7;
	bool r6;
	sdl__$Window r8;
	vdynamic *r1, *r5;
	hl_trap_ctx trap$0;
	hl_trap(trap$0,r1,label$9a2f713_14_6);
	r3 = r0->win;
	r4 = r0->glctx;
	sdl_win_destroy(r3,r4);
	hl_endtrap(trap$0);
	goto label$9a2f713_14_7;
	label$9a2f713_14_6:
	r5 = NULL;
	label$9a2f713_14_7:
	r3 = NULL;
	r0->win = r3;
	r4 = NULL;
	r0->glctx = r4;
	r8 = (sdl__$Window)g$_sdl_Window;
	r7 = r8->windows;
	if( r7 == NULL ) hl_null_access();
	r6 = hl_types_ArrayObj_remove(r7,((vdynamic*)r0));
	return;
}

