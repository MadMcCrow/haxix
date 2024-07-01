﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/scene/Renderer.h>
void h3d_scene_Renderer_depthSort(h3d__scene__Renderer,bool,h3d__pass__PassList);
#include <h3d/MatrixImpl.h>
#include <h3d/Camera.h>
#include <h3d/pass/PassObject.h>
#include <h3d/scene/Object.h>
#include <h3d/mat/Pass.h>
#include <h3d/Engine.h>
void h3d_Engine_popTarget(h3d__Engine);
#include <h3d/scene/PassObjects.h>
vdynamic* haxe_ds_StringMap_get(haxe__ds__StringMap,String);
extern String s$Not_implemented;
#include <h3d/impl/TextureCache.h>
void h3d_pass_Base_setContext(h3d__pass__Base,h3d__scene__RenderContext);
void haxe_ds_StringMap_set(haxe__ds__StringMap,String,vdynamic*);
void h3d_impl_TextureCache_begin(h3d__impl__TextureCache);
extern hl_type t$h3d_pass_PassList;
void h3d_pass_PassList_new(h3d__pass__PassList,h3d__pass__PassObject);
extern hl_type t$h3d_pass_Base;
#include <hl/natives.h>
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern hl_type t$haxe_ds_StringMap;
void haxe_ds_StringMap_new(haxe__ds__StringMap);
vdynamic* hxd_impl_AnyProps_getDefaultProps(hxd__impl__AnyProps,String);
vdynamic* hxd_impl_AnyProps_set_props(hxd__impl__AnyProps,vdynamic*);
extern hl_type t$ctx_8b4b31c;
extern hl_type t$fun_cf8f614;

void h3d_scene_Renderer_new__$1(venum* r0,h3d__pass__PassList r1) {
	bool r4;
	h3d__scene__Renderer r3;
	r3 = ((Enumt$ctx_8b4b31c*)r0)->p1;
	if( r3 == NULL ) hl_null_access();
	r4 = ((Enumt$ctx_8b4b31c*)r0)->p0;
	h3d_scene_Renderer_depthSort(r3,r4,r1);
	return;
}

void h3d_scene_Renderer_new__$2(venum* r0,h3d__pass__PassList r1) {
	bool r4;
	h3d__scene__Renderer r3;
	r3 = ((Enumt$ctx_8b4b31c*)r0)->p1;
	if( r3 == NULL ) hl_null_access();
	r4 = ((Enumt$ctx_8b4b31c*)r0)->p0;
	h3d_scene_Renderer_depthSort(r3,r4,r1);
	return;
}

void h3d_scene_Renderer_depthSort(h3d__scene__Renderer r0,bool r1,h3d__pass__PassList r2) {
	bool r17;
	h3d__Camera r4;
	h3d__mat__Pass r27;
	double r10, r14, r15, r16;
	h3d__pass__PassObject r7, r8, r9, r13, r21, r24, r26, r28;
	h3d__scene__RenderContext r5;
	h3d__MatrixImpl r3, r11;
	int r18, r19, r20, r22, r23, r25;
	h3d__scene__Object r12;
	r5 = r0->ctx;
	if( r5 == NULL ) hl_null_access();
	r4 = r5->camera;
	if( r4 == NULL ) hl_null_access();
	r3 = r4->m;
	if( r2 == NULL ) hl_null_access();
	r7 = r2->current;
	label$6ac2093_3_7:
	if( !r7 ) goto label$6ac2093_3_68;
	r8 = r7;
	if( r7 == NULL ) hl_null_access();
	r9 = r7->next;
	r7 = r9;
	if( r8 == NULL ) hl_null_access();
	r12 = r8->obj;
	if( r12 == NULL ) hl_null_access();
	r11 = r12->absPos;
	if( r11 == NULL ) hl_null_access();
	r10 = r11->_41;
	if( r3 == NULL ) hl_null_access();
	r14 = r3->_13;
	r10 = r10 * r14;
	r12 = r8->obj;
	if( r12 == NULL ) hl_null_access();
	r11 = r12->absPos;
	if( r11 == NULL ) hl_null_access();
	r14 = r11->_42;
	r15 = r3->_23;
	r14 = r14 * r15;
	r10 = r10 + r14;
	r12 = r8->obj;
	if( r12 == NULL ) hl_null_access();
	r11 = r12->absPos;
	if( r11 == NULL ) hl_null_access();
	r14 = r11->_43;
	r15 = r3->_33;
	r14 = r14 * r15;
	r10 = r10 + r14;
	r14 = r3->_43;
	r10 = r10 + r14;
	r12 = r8->obj;
	if( r12 == NULL ) hl_null_access();
	r11 = r12->absPos;
	if( r11 == NULL ) hl_null_access();
	r14 = r11->_41;
	r15 = r3->_14;
	r14 = r14 * r15;
	r12 = r8->obj;
	if( r12 == NULL ) hl_null_access();
	r11 = r12->absPos;
	if( r11 == NULL ) hl_null_access();
	r15 = r11->_42;
	r16 = r3->_24;
	r15 = r15 * r16;
	r14 = r14 + r15;
	r12 = r8->obj;
	if( r12 == NULL ) hl_null_access();
	r11 = r12->absPos;
	if( r11 == NULL ) hl_null_access();
	r15 = r11->_43;
	r16 = r3->_34;
	r15 = r15 * r16;
	r14 = r14 + r15;
	r15 = r3->_44;
	r14 = r14 + r15;
	r15 = r10 / r14;
	r8->depth = r15;
	goto label$6ac2093_3_7;
	label$6ac2093_3_68:
	if( !r1 ) goto label$6ac2093_3_182;
	if( r2 == NULL ) hl_null_access();
	r7 = r2->current;
	if( r7 ) goto label$6ac2093_3_75;
	r9 = NULL;
	r8 = r9;
	goto label$6ac2093_3_179;
	label$6ac2093_3_75:
	r18 = 1;
	r19 = 0;
	r20 = 0;
	label$6ac2093_3_78:
	r17 = true;
	if( !r17 ) goto label$6ac2093_3_178;
	r9 = r7;
	r13 = NULL;
	r7 = r13;
	r21 = NULL;
	r13 = r21;
	r23 = 0;
	r22 = r23;
	label$6ac2093_3_88:
	if( !r9 ) goto label$6ac2093_3_168;
	++r22;
	r21 = r9;
	r23 = 0;
	r19 = r23;
	r23 = 0;
	r25 = r18;
	label$6ac2093_3_96:
	if( r23 >= r25 ) goto label$6ac2093_3_106;
	++r23;
	++r19;
	if( r21 == NULL ) hl_null_access();
	r24 = r21->next;
	r21 = r24;
	if( r24 ) goto label$6ac2093_3_105;
	goto label$6ac2093_3_106;
	label$6ac2093_3_105:
	goto label$6ac2093_3_96;
	label$6ac2093_3_106:
	r20 = r18;
	label$6ac2093_3_107:
	r25 = 0;
	if( r25 < r19 ) goto label$6ac2093_3_113;
	r25 = 0;
	if( r25 >= r20 ) goto label$6ac2093_3_166;
	if( !r21 ) goto label$6ac2093_3_166;
	label$6ac2093_3_113:
	r25 = 0;
	if( r19 != r25 ) goto label$6ac2093_3_121;
	r24 = r21;
	if( r21 == NULL ) hl_null_access();
	r26 = r21->next;
	r21 = r26;
	--r20;
	goto label$6ac2093_3_159;
	label$6ac2093_3_121:
	r25 = 0;
	if( r20 == r25 ) goto label$6ac2093_3_149;
	if( !r21 ) goto label$6ac2093_3_149;
	if( r9 == NULL ) hl_null_access();
	r27 = r9->pass;
	if( r27 == NULL ) hl_null_access();
	r23 = r27->layer;
	if( r21 == NULL ) hl_null_access();
	r27 = r21->pass;
	if( r27 == NULL ) hl_null_access();
	r25 = r27->layer;
	if( r23 != r25 ) goto label$6ac2093_3_140;
	r10 = r9->depth;
	r14 = r21->depth;
	if( !(r14 < r10) ) goto label$6ac2093_3_138;
	r23 = 1;
	goto label$6ac2093_3_139;
	label$6ac2093_3_138:
	r23 = -1;
	label$6ac2093_3_139:
	goto label$6ac2093_3_147;
	label$6ac2093_3_140:
	r27 = r9->pass;
	if( r27 == NULL ) hl_null_access();
	r23 = r27->layer;
	r27 = r21->pass;
	if( r27 == NULL ) hl_null_access();
	r25 = r27->layer;
	r23 = r23 - r25;
	label$6ac2093_3_147:
	r25 = 0;
	if( r25 < r23 ) goto label$6ac2093_3_155;
	label$6ac2093_3_149:
	r24 = r9;
	if( r9 == NULL ) hl_null_access();
	r26 = r9->next;
	r9 = r26;
	--r19;
	goto label$6ac2093_3_159;
	label$6ac2093_3_155:
	r24 = r21;
	r26 = r21->next;
	r21 = r26;
	--r20;
	label$6ac2093_3_159:
	if( !r13 ) goto label$6ac2093_3_163;
	if( r13 == NULL ) hl_null_access();
	r13->next = r24;
	goto label$6ac2093_3_164;
	label$6ac2093_3_163:
	r7 = r24;
	label$6ac2093_3_164:
	r13 = r24;
	goto label$6ac2093_3_107;
	label$6ac2093_3_166:
	r9 = r21;
	goto label$6ac2093_3_88;
	label$6ac2093_3_168:
	if( r13 == NULL ) hl_null_access();
	r28 = NULL;
	r13->next = r28;
	r25 = 1;
	if( r25 < r22 ) goto label$6ac2093_3_174;
	goto label$6ac2093_3_178;
	label$6ac2093_3_174:
	r25 = 2;
	r23 = r18 * r25;
	r18 = r23;
	goto label$6ac2093_3_78;
	label$6ac2093_3_178:
	r8 = r7;
	label$6ac2093_3_179:
	if( r2 == NULL ) hl_null_access();
	r2->current = r8;
	goto label$6ac2093_3_294;
	label$6ac2093_3_182:
	if( r2 == NULL ) hl_null_access();
	r7 = r2->current;
	if( r7 ) goto label$6ac2093_3_188;
	r9 = NULL;
	r8 = r9;
	goto label$6ac2093_3_292;
	label$6ac2093_3_188:
	r18 = 1;
	r19 = 0;
	r20 = 0;
	label$6ac2093_3_191:
	r17 = true;
	if( !r17 ) goto label$6ac2093_3_291;
	r9 = r7;
	r13 = NULL;
	r7 = r13;
	r21 = NULL;
	r13 = r21;
	r23 = 0;
	r22 = r23;
	label$6ac2093_3_201:
	if( !r9 ) goto label$6ac2093_3_281;
	++r22;
	r21 = r9;
	r23 = 0;
	r19 = r23;
	r23 = 0;
	r25 = r18;
	label$6ac2093_3_209:
	if( r23 >= r25 ) goto label$6ac2093_3_219;
	++r23;
	++r19;
	if( r21 == NULL ) hl_null_access();
	r24 = r21->next;
	r21 = r24;
	if( r24 ) goto label$6ac2093_3_218;
	goto label$6ac2093_3_219;
	label$6ac2093_3_218:
	goto label$6ac2093_3_209;
	label$6ac2093_3_219:
	r20 = r18;
	label$6ac2093_3_220:
	r25 = 0;
	if( r25 < r19 ) goto label$6ac2093_3_226;
	r25 = 0;
	if( r25 >= r20 ) goto label$6ac2093_3_279;
	if( !r21 ) goto label$6ac2093_3_279;
	label$6ac2093_3_226:
	r25 = 0;
	if( r19 != r25 ) goto label$6ac2093_3_234;
	r24 = r21;
	if( r21 == NULL ) hl_null_access();
	r26 = r21->next;
	r21 = r26;
	--r20;
	goto label$6ac2093_3_272;
	label$6ac2093_3_234:
	r25 = 0;
	if( r20 == r25 ) goto label$6ac2093_3_262;
	if( !r21 ) goto label$6ac2093_3_262;
	if( r9 == NULL ) hl_null_access();
	r27 = r9->pass;
	if( r27 == NULL ) hl_null_access();
	r23 = r27->layer;
	if( r21 == NULL ) hl_null_access();
	r27 = r21->pass;
	if( r27 == NULL ) hl_null_access();
	r25 = r27->layer;
	if( r23 != r25 ) goto label$6ac2093_3_253;
	r10 = r9->depth;
	r14 = r21->depth;
	if( !(r14 < r10) ) goto label$6ac2093_3_251;
	r23 = -1;
	goto label$6ac2093_3_252;
	label$6ac2093_3_251:
	r23 = 1;
	label$6ac2093_3_252:
	goto label$6ac2093_3_260;
	label$6ac2093_3_253:
	r27 = r9->pass;
	if( r27 == NULL ) hl_null_access();
	r23 = r27->layer;
	r27 = r21->pass;
	if( r27 == NULL ) hl_null_access();
	r25 = r27->layer;
	r23 = r23 - r25;
	label$6ac2093_3_260:
	r25 = 0;
	if( r25 < r23 ) goto label$6ac2093_3_268;
	label$6ac2093_3_262:
	r24 = r9;
	if( r9 == NULL ) hl_null_access();
	r26 = r9->next;
	r9 = r26;
	--r19;
	goto label$6ac2093_3_272;
	label$6ac2093_3_268:
	r24 = r21;
	r26 = r21->next;
	r21 = r26;
	--r20;
	label$6ac2093_3_272:
	if( !r13 ) goto label$6ac2093_3_276;
	if( r13 == NULL ) hl_null_access();
	r13->next = r24;
	goto label$6ac2093_3_277;
	label$6ac2093_3_276:
	r7 = r24;
	label$6ac2093_3_277:
	r13 = r24;
	goto label$6ac2093_3_220;
	label$6ac2093_3_279:
	r9 = r21;
	goto label$6ac2093_3_201;
	label$6ac2093_3_281:
	if( r13 == NULL ) hl_null_access();
	r28 = NULL;
	r13->next = r28;
	r25 = 1;
	if( r25 < r22 ) goto label$6ac2093_3_287;
	goto label$6ac2093_3_291;
	label$6ac2093_3_287:
	r25 = 2;
	r23 = r18 * r25;
	r18 = r23;
	goto label$6ac2093_3_191;
	label$6ac2093_3_291:
	r8 = r7;
	label$6ac2093_3_292:
	if( r2 == NULL ) hl_null_access();
	r2->current = r8;
	label$6ac2093_3_294:
	return;
}

void h3d_scene_Renderer_resetTarget(h3d__scene__Renderer r0) {
	bool r2;
	h3d__Engine r3;
	h3d__scene__RenderContext r4;
	r2 = r0->hasSetTarget;
	if( !r2 ) goto label$6ac2093_4_9;
	r4 = r0->ctx;
	if( r4 == NULL ) hl_null_access();
	r3 = r4->engine;
	if( r3 == NULL ) hl_null_access();
	h3d_Engine_popTarget(r3);
	r2 = false;
	r0->hasSetTarget = r2;
	label$6ac2093_4_9:
	return;
}

bool h3d_scene_Renderer_has(h3d__scene__Renderer r0,String r1) {
	h3d__scene__PassObjects r5, r6;
	haxe__ds__StringMap r4;
	bool r2;
	vdynamic *r3;
	r4 = r0->passObjects;
	if( r4 == NULL ) hl_null_access();
	r3 = haxe_ds_StringMap_get(r4,r1);
	r5 = (h3d__scene__PassObjects)r3;
	r6 = NULL;
	if( r5 != r6 ) goto label$6ac2093_5_8;
	r2 = false;
	goto label$6ac2093_5_9;
	label$6ac2093_5_8:
	r2 = true;
	label$6ac2093_5_9:
	return r2;
}

void h3d_scene_Renderer_setPassFlags(h3d__scene__Renderer r0,h3d__mat__Pass r1) {
	int r2, r3;
	if( r1 == NULL ) hl_null_access();
	r2 = r1->rendererFlags;
	r3 = 1;
	r2 = r2 | r3;
	r1->rendererFlags = r2;
	return;
}

h3d__pass__PassList h3d_scene_Renderer_get(h3d__scene__Renderer r0,String r1) {
	h3d__scene__PassObjects r4;
	haxe__ds__StringMap r3;
	bool r6;
	h3d__pass__PassList r5;
	vdynamic *r2;
	r3 = r0->passObjects;
	if( r3 == NULL ) hl_null_access();
	r2 = haxe_ds_StringMap_get(r3,r1);
	r4 = (h3d__scene__PassObjects)r2;
	if( r4 ) goto label$6ac2093_7_7;
	r5 = r0->emptyPasses;
	return r5;
	label$6ac2093_7_7:
	if( r4 == NULL ) hl_null_access();
	r6 = true;
	r4->rendered = r6;
	r5 = r4->passes;
	return r5;
}

void h3d_scene_Renderer_render(h3d__scene__Renderer r0) {
	String r1;
	r1 = (String)s$Not_implemented;
	hl_throw((vdynamic*)r1);
}

void h3d_scene_Renderer_computeStatic(h3d__scene__Renderer r0) {
	String r1;
	r1 = (String)s$Not_implemented;
	hl_throw((vdynamic*)r1);
}

void h3d_scene_Renderer_start(h3d__scene__Renderer r0) {
	return;
}

void h3d_scene_Renderer_process(h3d__scene__Renderer r0,hl__types__ArrayObj r1) {
	h3d__impl__TextureCache r15;
	String r13;
	h3d__scene__PassObjects r11, r14;
	haxe__ds__StringMap r12;
	hl__types__ArrayObj r5;
	h3d__pass__Base r7;
	bool r2;
	h3d__scene__RenderContext r10;
	vdynamic *r8;
	varray *r9;
	int r3, r6;
	r2 = false;
	r0->hasSetTarget = r2;
	r3 = 0;
	r5 = r0->allPasses;
	label$6ac2093_11_4:
	if( r5 == NULL ) hl_null_access();
	r6 = r5->length;
	if( r3 >= r6 ) goto label$6ac2093_11_20;
	r6 = r5->length;
	if( ((unsigned)r3) < ((unsigned)r6) ) goto label$6ac2093_11_12;
	r7 = NULL;
	goto label$6ac2093_11_15;
	label$6ac2093_11_12:
	r9 = r5->array;
	r8 = ((vdynamic**)(r9 + 1))[r3];
	r7 = (h3d__pass__Base)r8;
	label$6ac2093_11_15:
	++r3;
	if( r7 == NULL ) hl_null_access();
	r10 = r0->ctx;
	h3d_pass_Base_setContext(r7,r10);
	goto label$6ac2093_11_4;
	label$6ac2093_11_20:
	r3 = 0;
	label$6ac2093_11_21:
	if( r1 == NULL ) hl_null_access();
	r6 = r1->length;
	if( r3 >= r6 ) goto label$6ac2093_11_39;
	r6 = r1->length;
	if( ((unsigned)r3) < ((unsigned)r6) ) goto label$6ac2093_11_29;
	r11 = NULL;
	goto label$6ac2093_11_32;
	label$6ac2093_11_29:
	r9 = r1->array;
	r8 = ((vdynamic**)(r9 + 1))[r3];
	r11 = (h3d__scene__PassObjects)r8;
	label$6ac2093_11_32:
	++r3;
	r12 = r0->passObjects;
	if( r12 == NULL ) hl_null_access();
	if( r11 == NULL ) hl_null_access();
	r13 = r11->name;
	haxe_ds_StringMap_set(r12,r13,((vdynamic*)r11));
	goto label$6ac2093_11_21;
	label$6ac2093_11_39:
	r10 = r0->ctx;
	if( r10 == NULL ) hl_null_access();
	r15 = r10->textures;
	if( r15 == NULL ) hl_null_access();
	h3d_impl_TextureCache_begin(r15);
	r10 = r0->ctx;
	if( r10 == NULL ) hl_null_access();
	r2 = r10->computingStatic;
	if( !r2 ) goto label$6ac2093_11_50;
	h3d_scene_Renderer_computeStatic(r0);
	goto label$6ac2093_11_51;
	label$6ac2093_11_50:
	((void (*)(h3d__scene__Renderer))r0->$type->vobj_proto[2])(r0);
	label$6ac2093_11_51:
	h3d_scene_Renderer_resetTarget(r0);
	r3 = 0;
	label$6ac2093_11_53:
	if( r1 == NULL ) hl_null_access();
	r6 = r1->length;
	if( r3 >= r6 ) goto label$6ac2093_11_72;
	r6 = r1->length;
	if( ((unsigned)r3) < ((unsigned)r6) ) goto label$6ac2093_11_61;
	r11 = NULL;
	goto label$6ac2093_11_64;
	label$6ac2093_11_61:
	r9 = r1->array;
	r8 = ((vdynamic**)(r9 + 1))[r3];
	r11 = (h3d__scene__PassObjects)r8;
	label$6ac2093_11_64:
	++r3;
	r12 = r0->passObjects;
	if( r12 == NULL ) hl_null_access();
	if( r11 == NULL ) hl_null_access();
	r13 = r11->name;
	r14 = NULL;
	haxe_ds_StringMap_set(r12,r13,((vdynamic*)r14));
	goto label$6ac2093_11_53;
	label$6ac2093_11_72:
	return;
}

void h3d_scene_Renderer_new(h3d__scene__Renderer r0) {
	String r11;
	haxe__ds__StringMap r9;
	hl__types__ArrayObj r5;
	venum *r13;
	hl_type *r7;
	bool r1, r14;
	h3d__pass__PassList r2;
	vclosure *r12;
	h3d__pass__PassObject r3;
	vdynamic *r10;
	int r8;
	varray *r6;
	r1 = false;
	r0->hasSetTarget = r1;
	r2 = (h3d__pass__PassList)hl_alloc_obj(&t$h3d_pass_PassList);
	r3 = NULL;
	h3d_pass_PassList_new(r2,r3);
	r0->emptyPasses = r2;
	r7 = &t$h3d_pass_Base;
	r8 = 0;
	r6 = hl_alloc_array(r7,r8);
	r5 = hl_types_ArrayObj_alloc(r6);
	r0->allPasses = r5;
	r9 = (haxe__ds__StringMap)hl_alloc_obj(&t$haxe_ds_StringMap);
	haxe_ds_StringMap_new(r9);
	r0->passObjects = r9;
	r11 = NULL;
	r10 = hxd_impl_AnyProps_getDefaultProps(((hxd__impl__AnyProps)r0),r11);
	r10 = hxd_impl_AnyProps_set_props(((hxd__impl__AnyProps)r0),r10);
	r1 = true;
	r13 = hl_alloc_enum(&t$ctx_8b4b31c,0);
	((Enumt$ctx_8b4b31c*)r13)->p0 = (bool)r1;
	((Enumt$ctx_8b4b31c*)r13)->p1 = (h3d__scene__Renderer)r0;
	r12 = hl_alloc_closure_ptr(&t$fun_cf8f614,h3d_scene_Renderer_new__$1,r13);
	r0->frontToBack = r12;
	r14 = false;
	r13 = hl_alloc_enum(&t$ctx_8b4b31c,0);
	((Enumt$ctx_8b4b31c*)r13)->p0 = (bool)r14;
	((Enumt$ctx_8b4b31c*)r13)->p1 = (h3d__scene__Renderer)r0;
	r12 = hl_alloc_closure_ptr(&t$fun_cf8f614,h3d_scene_Renderer_new__$2,r13);
	r0->backToFront = r12;
	return;
}

