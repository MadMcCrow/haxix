﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h3d/scene/Scene.h>
#include <h3d/scene/Interactive.h>
extern hl_type t$h3d_scene_Interactive;
extern hl_type t$_dyn;
#include <h3d/Engine.h>
#include <h3d/mat/MaterialSetup.h>
void h3d_scene_Object_new(h3d__scene__Object,h3d__scene__Object);
hxd__Window hxd_Window_getInstance(void);
extern hl_type t$fun_b4832bf;
#include <hl/natives.h>
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern hl_type t$h3d_Camera;
void h3d_Camera_new(h3d__Camera,double*,double*,double*,double*,double*,bool*);
extern h3d__$Engine g$_h3d_Engine;
extern hl_type t$h3d_scene_RenderContext;
void h3d_scene_RenderContext_new(h3d__scene__RenderContext);
extern h3d__mat__$MaterialSetup g$_h3d_mat_MaterialSetup;
h3d__scene__Renderer h3d_mat_MaterialSetup_createRenderer(h3d__mat__MaterialSetup);
h3d__scene__Renderer h3d_scene_Scene_set_renderer(h3d__scene__Scene,h3d__scene__Renderer);
h3d__scene__LightSystem h3d_mat_MaterialSetup_createLightSystem(h3d__mat__MaterialSetup);
#include <h3d/Vector4Impl.h>
extern hl_type t$vrt_c8e313e;
void h3d_scene_Interactive_handleEvent(h3d__scene__Interactive,hxd__Event);
extern hl_type t$h3d_scene_Object;
#include <h3d/VectorImpl.h>
#include <h3d/col/Ray.h>
int hxd_Window_get_width(hxd__Window);
int hxd_Window_get_height(hxd__Window);
h3d__VectorImpl h3d_Camera_unproject(h3d__Camera,double,double,double);
extern hl_type t$h3d_col_Ray;
void h3d_col_Ray_new(h3d__col__Ray);
void h3d_col_Ray_normalize(h3d__col__Ray);
h3d__MatrixImpl h3d_scene_Object_getInvPos(h3d__scene__Object);
vdynamic* hl_types_ArrayObj_pop(hl__types__ArrayObj);
int hl_types_ArrayObj_push(hl__types__ArrayObj,vdynamic*);
extern hl_type t$fun_9e0a57f;
extern hl_type t$fun_390b646;
void hl_types_ArrayObj_sort(hl__types__ArrayObj,vclosure*);
void hl_types_ArrayObj_unshift(hl__types__ArrayObj,vdynamic*);
int hl_types_ArrayObj_indexOf(hl__types__ArrayObj,vdynamic*,vdynamic*);
extern String s$assert;
bool hl_types_ArrayObj_remove(hl__types__ArrayObj,vdynamic*);
void hxd_SceneEvents_onRemove(hxd__SceneEvents,vvirtual*);
#include <h3d/mat/Texture.h>
#include <h3d/impl/Driver.h>
#include <h3d/impl/RenderFlag.h>
#include <h3d/pass/PassObject.h>
#include <h3d/scene/PassObjects.h>
#include <h3d/mat/Pass.h>
#include <h3d/pass/PassList.h>
void h3d_scene_Object_onAdd(h3d__scene__Object);
h3d__mat__Texture h3d_Engine_getCurrentTarget(h3d__Engine);
void h3d_Camera_update(h3d__Camera);
extern venum* g$4b90600;
void h3d_scene_RenderContext_start(h3d__scene__RenderContext);
void h3d_scene_Renderer_start(h3d__scene__Renderer);
void h3d_scene_Object_syncRec(h3d__scene__Object,h3d__scene__RenderContext);
void h3d_scene_Object_emitRec(h3d__scene__Object,h3d__scene__RenderContext);
extern hl_type t$h3d_scene_PassObjects;
void h3d_scene_PassObjects_new(h3d__scene__PassObjects);
void hl_types_ArrayObj___expand(hl__types__ArrayObj,int);
void h3d_scene_Renderer_process(h3d__scene__Renderer,hl__types__ArrayObj);
void h3d_scene_RenderContext_done(h3d__scene__RenderContext);

int h3d_scene_Scene_handleEvent__$1(vclosure* r0,vdynamic* r1,vdynamic* r2) {
	h3d__scene__Interactive r3, r4;
	int r5;
	r3 = (h3d__scene__Interactive)hl_dyn_castp(&r1,&t$_dyn,&t$h3d_scene_Interactive);
	r4 = (h3d__scene__Interactive)hl_dyn_castp(&r2,&t$_dyn,&t$h3d_scene_Interactive);
	r5 = r0->hasValue ? ((int (*)(vdynamic*,h3d__scene__Interactive,h3d__scene__Interactive))r0->fun)((vdynamic*)r0->value,r3,r4) : ((int (*)(h3d__scene__Interactive,h3d__scene__Interactive))r0->fun)(r3,r4);
	return r5;
}

void h3d_scene_Scene_new(h3d__scene__Scene r0,vdynamic* r1,vdynamic* r2) {
	bool *r17;
	hl__types__ArrayObj r7;
	hl_type *r9;
	bool r3;
	h3d__scene__Renderer r23;
	h3d__Camera r11;
	h3d__Engine r18;
	hxd__Window r6;
	h3d__mat__$MaterialSetup r25;
	h3d__$Engine r19;
	h3d__mat__MaterialSetup r24;
	double r20, r21;
	h3d__scene__RenderContext r22;
	double *r12, *r13, *r14, *r15, *r16;
	h3d__scene__LightSystem r26;
	int r10;
	varray *r8;
	h3d__scene__Object r5;
	if( r1 ) goto label$891d561_2_3;
	r3 = true;
	r1 = hl_alloc_dynbool(r3);
	label$891d561_2_3:
	if( r2 ) goto label$891d561_2_6;
	r3 = true;
	r2 = hl_alloc_dynbool(r3);
	label$891d561_2_6:
	r5 = NULL;
	h3d_scene_Object_new(((h3d__scene__Object)r0),r5);
	r6 = hxd_Window_getInstance();
	r0->window = r6;
	r9 = &t$fun_b4832bf;
	r10 = 0;
	r8 = hl_alloc_array(r9,r10);
	r7 = hl_types_ArrayObj_alloc(r8);
	r0->eventListeners = r7;
	r9 = &t$h3d_scene_Interactive;
	r10 = 0;
	r8 = hl_alloc_array(r9,r10);
	r7 = hl_types_ArrayObj_alloc(r8);
	r0->hitInteractives = r7;
	r9 = &t$h3d_scene_Interactive;
	r10 = 0;
	r8 = hl_alloc_array(r9,r10);
	r7 = hl_types_ArrayObj_alloc(r8);
	r0->interactives = r7;
	r11 = (h3d__Camera)hl_alloc_obj(&t$h3d_Camera);
	r12 = NULL;
	r13 = NULL;
	r14 = NULL;
	r15 = NULL;
	r16 = NULL;
	r17 = NULL;
	h3d_Camera_new(r11,r12,r13,r14,r15,r16,r17);
	r0->camera = r11;
	r19 = (h3d__$Engine)g$_h3d_Engine;
	r18 = r19->CURRENT;
	if( !r18 ) goto label$891d561_2_46;
	r11 = r0->camera;
	if( r11 == NULL ) hl_null_access();
	if( r18 == NULL ) hl_null_access();
	r10 = r18->width;
	r20 = (double)r10;
	r10 = r18->height;
	r21 = (double)r10;
	r20 = r20 / r21;
	r11->screenRatio = r20;
	label$891d561_2_46:
	r22 = (h3d__scene__RenderContext)hl_alloc_obj(&t$h3d_scene_RenderContext);
	h3d_scene_RenderContext_new(r22);
	r0->ctx = r22;
	r3 = r1 ? r1->v.b : 0;
	if( !r3 ) goto label$891d561_2_56;
	r25 = (h3d__mat__$MaterialSetup)g$_h3d_mat_MaterialSetup;
	r24 = r25->current;
	if( r24 == NULL ) hl_null_access();
	r23 = h3d_mat_MaterialSetup_createRenderer(r24);
	r23 = h3d_scene_Scene_set_renderer(r0,r23);
	label$891d561_2_56:
	r3 = r2 ? r2->v.b : 0;
	if( !r3 ) goto label$891d561_2_63;
	r25 = (h3d__mat__$MaterialSetup)g$_h3d_mat_MaterialSetup;
	r24 = r25->current;
	if( r24 == NULL ) hl_null_access();
	r26 = h3d_mat_MaterialSetup_createLightSystem(r24);
	r0->lightSystem = r26;
	label$891d561_2_63:
	return;
}

void h3d_scene_Scene_setEvents(h3d__scene__Scene r0,hxd__SceneEvents r1) {
	r0->events = r1;
	return;
}

void h3d_scene_Scene_dispatchListeners(h3d__scene__Scene r0,hxd__Event r1) {
	hl__types__ArrayObj r4;
	bool r9;
	vclosure *r6;
	vdynamic *r7;
	varray *r8;
	int r2, r5;
	r2 = 0;
	r4 = r0->eventListeners;
	label$891d561_4_2:
	if( r4 == NULL ) hl_null_access();
	r5 = r4->length;
	if( r2 >= r5 ) goto label$891d561_4_21;
	r5 = r4->length;
	if( ((unsigned)r2) < ((unsigned)r5) ) goto label$891d561_4_10;
	r6 = NULL;
	goto label$891d561_4_13;
	label$891d561_4_10:
	r8 = r4->array;
	r7 = ((vdynamic**)(r8 + 1))[r2];
	r6 = (vclosure*)r7;
	label$891d561_4_13:
	++r2;
	if( r6 == NULL ) hl_null_access();
	r6->hasValue ? ((void (*)(vdynamic*,hxd__Event))r6->fun)((vdynamic*)r6->value,r1) : ((void (*)(hxd__Event))r6->fun)(r1);
	if( r1 == NULL ) hl_null_access();
	r9 = r1->propagate;
	if( r9 ) goto label$891d561_4_20;
	goto label$891d561_4_21;
	label$891d561_4_20:
	goto label$891d561_4_2;
	label$891d561_4_21:
	return;
}

h3d__scene__Renderer h3d_scene_Scene_set_renderer(h3d__scene__Scene r0,h3d__scene__Renderer r1) {
	h3d__scene__RenderContext r2;
	r0->renderer = r1;
	if( !r1 ) goto label$891d561_5_5;
	if( r1 == NULL ) hl_null_access();
	r2 = r0->ctx;
	r1->ctx = r2;
	label$891d561_5_5:
	return r1;
}

int h3d_scene_Scene_sortHitPointByCameraDistance(h3d__scene__Scene r0,h3d__scene__Interactive r1,h3d__scene__Interactive r2) {
	h3d__Vector4Impl r4;
	double r3, r5;
	int r6;
	if( r1 == NULL ) hl_null_access();
	r4 = r1->hitPoint;
	if( r4 == NULL ) hl_null_access();
	r3 = r4->w;
	if( r2 == NULL ) hl_null_access();
	r4 = r2->hitPoint;
	if( r4 == NULL ) hl_null_access();
	r5 = r4->w;
	if( !(r5 < r3) ) goto label$891d561_6_11;
	r6 = -1;
	return r6;
	label$891d561_6_11:
	r6 = 1;
	return r6;
}

void h3d_scene_Scene_dispatchEvent(h3d__scene__Scene r0,hxd__Event r1,vvirtual* r2) {
	h3d__scene__Interactive r3;
	r3 = (h3d__scene__Interactive)hl_dyn_castp(&r2,&t$vrt_c8e313e,&t$h3d_scene_Interactive);
	if( r3 == NULL ) hl_null_access();
	h3d_scene_Interactive_handleEvent(r3,r1);
	return;
}

bool h3d_scene_Scene_isInteractiveVisible(h3d__scene__Scene r0,vvirtual* r1) {
	bool r6;
	int r4, r5;
	h3d__scene__Object r2, r3;
	r2 = (h3d__scene__Object)hl_dyn_castp(&r1,&t$vrt_c8e313e,&t$h3d_scene_Object);
	label$891d561_8_1:
	if( r2 == ((h3d__scene__Object)r0) ) goto label$891d561_8_15;
	if( !r2 ) goto label$891d561_8_10;
	if( r2 == NULL ) hl_null_access();
	r4 = r2->flags;
	r5 = 2;
	r4 = r4 & r5;
	r5 = 0;
	if( r4 != r5 ) goto label$891d561_8_12;
	label$891d561_8_10:
	r6 = false;
	return r6;
	label$891d561_8_12:
	r3 = r2->parent;
	r2 = r3;
	goto label$891d561_8_1;
	label$891d561_8_15:
	r6 = true;
	return r6;
}

h3d__scene__Interactive h3d_scene_Scene_handleEvent(h3d__scene__Scene r0,hxd__Event r1,vvirtual* r2) {
	h3d__VectorImpl r13, r17;
	h3d__col__Collider r50;
	h3d__scene__Interactive r7, r33;
	hl__types__ArrayObj r5, r31;
	bool r36;
	h3d__Camera r14;
	hxd__Window r10;
	h3d__Vector4Impl r51, r53;
	h3d__col__Ray r21, r22;
	vclosure *r54, *r55;
	double r9, r11, r12, r15, r16, r18, r19, r20, r23, r24, r25, r26, r27, r28, r38, r39, r40, r41, r42, r44, r45, r46, r47, r48, r49, r52;
	h3d__MatrixImpl r37, r43;
	vdynamic *r8;
	h3d__scene__Object r34, r35;
	varray *r32;
	int r4, r6, r29, r30;
	r5 = r0->interactives;
	if( r5 == NULL ) hl_null_access();
	r4 = r5->length;
	r6 = 0;
	if( r4 != r6 ) goto label$891d561_9_7;
	r7 = NULL;
	return r7;
	label$891d561_9_7:
	r5 = r0->hitInteractives;
	if( r5 == NULL ) hl_null_access();
	r4 = r5->length;
	r6 = 0;
	if( r4 != r6 ) goto label$891d561_9_500;
	if( r1 == NULL ) hl_null_access();
	r9 = r1->relX;
	r10 = r0->window;
	if( r10 == NULL ) hl_null_access();
	r4 = hxd_Window_get_width(r10);
	r11 = (double)r4;
	r9 = r9 / r11;
	r11 = 0.5;
	r9 = r9 - r11;
	r11 = 2.;
	r9 = r9 * r11;
	r11 = r1->relY;
	r10 = r0->window;
	if( r10 == NULL ) hl_null_access();
	r4 = hxd_Window_get_height(r10);
	r12 = (double)r4;
	r11 = r11 / r12;
	r12 = 0.5;
	r11 = r11 - r12;
	r11 = -r11;
	r12 = 2.;
	r11 = r11 * r12;
	r14 = r0->camera;
	if( r14 == NULL ) hl_null_access();
	r16 = 0.;
	r13 = h3d_Camera_unproject(r14,r9,r11,r16);
	r14 = r0->camera;
	if( r14 == NULL ) hl_null_access();
	r16 = 1.;
	r17 = h3d_Camera_unproject(r14,r9,r11,r16);
	if( r13 == NULL ) hl_null_access();
	r12 = r13->x;
	r15 = r13->y;
	r16 = r13->z;
	if( r17 == NULL ) hl_null_access();
	r18 = r17->x;
	r19 = r17->y;
	r20 = r17->z;
	r21 = (h3d__col__Ray)hl_alloc_obj(&t$h3d_col_Ray);
	h3d_col_Ray_new(r21);
	r21->px = r12;
	r21->py = r15;
	r21->pz = r16;
	r23 = r18 - r12;
	r21->lx = r23;
	r23 = r19 - r15;
	r21->ly = r23;
	r23 = r20 - r16;
	r21->lz = r23;
	h3d_col_Ray_normalize(r21);
	r22 = r21;
	r23 = r21->px;
	r24 = r21->py;
	r25 = r21->pz;
	r26 = r21->lx;
	r27 = r21->ly;
	r28 = r21->lz;
	r4 = 0x80000000;
	r6 = 0;
	r5 = r0->interactives;
	label$891d561_9_72:
	if( r5 == NULL ) hl_null_access();
	r30 = r5->length;
	if( r6 >= r30 ) goto label$891d561_9_246;
	r30 = r5->length;
	if( ((unsigned)r6) < ((unsigned)r30) ) goto label$891d561_9_80;
	r7 = NULL;
	goto label$891d561_9_83;
	label$891d561_9_80:
	r32 = r5->array;
	r8 = ((vdynamic**)(r32 + 1))[r6];
	r7 = (h3d__scene__Interactive)r8;
	label$891d561_9_83:
	++r6;
	if( r7 == NULL ) hl_null_access();
	r29 = r7->priority;
	if( r29 >= r4 ) goto label$891d561_9_88;
	goto label$891d561_9_72;
	label$891d561_9_88:
	r34 = ((h3d__scene__Object)r7);
	label$891d561_9_89:
	if( !r34 ) goto label$891d561_9_100;
	if( r34 == NULL ) hl_null_access();
	r29 = r34->flags;
	r30 = 2;
	r29 = r29 & r30;
	r30 = 0;
	if( r29 == r30 ) goto label$891d561_9_100;
	r35 = r34->parent;
	r34 = r35;
	goto label$891d561_9_89;
	label$891d561_9_100:
	if( !r34 ) goto label$891d561_9_102;
	goto label$891d561_9_72;
	label$891d561_9_102:
	if( r7 == NULL ) hl_null_access();
	r36 = r7->isAbsoluteShape;
	if( r36 ) goto label$891d561_9_175;
	r37 = h3d_scene_Object_getInvPos(((h3d__scene__Object)r7));
	if( r22 == NULL ) hl_null_access();
	r38 = r22->px;
	r39 = r22->py;
	r40 = r22->pz;
	if( r37 == NULL ) hl_null_access();
	r42 = r37->_11;
	r41 = r38 * r42;
	r44 = r37->_21;
	r42 = r39 * r44;
	r41 = r41 + r42;
	r44 = r37->_31;
	r42 = r40 * r44;
	r41 = r41 + r42;
	r42 = r37->_41;
	r41 = r41 + r42;
	r44 = r37->_12;
	r42 = r38 * r44;
	r45 = r37->_22;
	r44 = r39 * r45;
	r42 = r42 + r44;
	r45 = r37->_32;
	r44 = r40 * r45;
	r42 = r42 + r44;
	r44 = r37->_42;
	r42 = r42 + r44;
	r45 = r37->_13;
	r44 = r38 * r45;
	r46 = r37->_23;
	r45 = r39 * r46;
	r44 = r44 + r45;
	r46 = r37->_33;
	r45 = r40 * r46;
	r44 = r44 + r45;
	r45 = r37->_43;
	r44 = r44 + r45;
	r22->px = r41;
	r22->py = r42;
	r22->pz = r44;
	r41 = r22->lx;
	r42 = r22->ly;
	r44 = r22->lz;
	r46 = r37->_11;
	r45 = r41 * r46;
	r47 = r37->_21;
	r46 = r42 * r47;
	r45 = r45 + r46;
	r47 = r37->_31;
	r46 = r44 * r47;
	r45 = r45 + r46;
	r47 = r37->_12;
	r46 = r41 * r47;
	r48 = r37->_22;
	r47 = r42 * r48;
	r46 = r46 + r47;
	r48 = r37->_32;
	r47 = r44 * r48;
	r46 = r46 + r47;
	r48 = r37->_13;
	r47 = r41 * r48;
	r49 = r37->_23;
	r48 = r42 * r49;
	r47 = r47 + r48;
	r49 = r37->_33;
	r48 = r44 * r49;
	r47 = r47 + r48;
	r22->lx = r45;
	r22->ly = r46;
	r22->lz = r47;
	h3d_col_Ray_normalize(r22);
	label$891d561_9_175:
	if( r22 == NULL ) hl_null_access();
	r38 = r22->lx;
	r39 = r22->lx;
	if( r38 == r39 ) goto label$891d561_9_186;
	r22->px = r23;
	r22->py = r24;
	r22->pz = r25;
	r22->lx = r26;
	r22->ly = r27;
	r22->lz = r28;
	goto label$891d561_9_72;
	label$891d561_9_186:
	r50 = r7->shape;
	if( r50 == NULL ) hl_null_access();
	r36 = r7->bestMatch;
	r38 = ((double (*)(h3d__col__Collider,h3d__col__Ray,bool))r50->$type->vobj_proto[0])(r50,r22,r36);
	r40 = 0.;
	if( !(r38 < r40) ) goto label$891d561_9_199;
	r22->px = r23;
	r22->py = r24;
	r22->pz = r25;
	r22->lx = r26;
	r22->ly = r27;
	r22->lz = r28;
	goto label$891d561_9_72;
	label$891d561_9_199:
	r39 = r22->px;
	r41 = r22->lx;
	r40 = r38 * r41;
	r39 = r39 + r40;
	r40 = r22->py;
	r42 = r22->ly;
	r41 = r38 * r42;
	r40 = r40 + r41;
	r41 = r22->pz;
	r44 = r22->lz;
	r42 = r38 * r44;
	r41 = r41 + r42;
	r22->px = r23;
	r22->py = r24;
	r22->pz = r25;
	r22->lx = r26;
	r22->ly = r27;
	r22->lz = r28;
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r51->x = r39;
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r51->y = r40;
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r51->z = r41;
	r29 = r7->priority;
	if( r4 >= r29 ) goto label$891d561_9_242;
	label$891d561_9_228:
	r31 = r0->hitInteractives;
	if( r31 == NULL ) hl_null_access();
	r29 = r31->length;
	r30 = 0;
	if( r30 >= r29 ) goto label$891d561_9_239;
	r31 = r0->hitInteractives;
	if( r31 == NULL ) hl_null_access();
	r8 = hl_types_ArrayObj_pop(r31);
	r33 = (h3d__scene__Interactive)r8;
	goto label$891d561_9_228;
	label$891d561_9_239:
	if( r7 == NULL ) hl_null_access();
	r29 = r7->priority;
	r4 = r29;
	label$891d561_9_242:
	r31 = r0->hitInteractives;
	if( r31 == NULL ) hl_null_access();
	r29 = hl_types_ArrayObj_push(r31,((vdynamic*)r7));
	goto label$891d561_9_72;
	label$891d561_9_246:
	r5 = r0->hitInteractives;
	if( r5 == NULL ) hl_null_access();
	r6 = r5->length;
	r29 = 0;
	if( r6 != r29 ) goto label$891d561_9_253;
	r7 = NULL;
	return r7;
	label$891d561_9_253:
	r5 = r0->hitInteractives;
	if( r5 == NULL ) hl_null_access();
	r6 = r5->length;
	r29 = 1;
	if( r29 >= r6 ) goto label$891d561_9_496;
	r6 = 0;
	r5 = r0->hitInteractives;
	label$891d561_9_260:
	if( r5 == NULL ) hl_null_access();
	r30 = r5->length;
	if( r6 >= r30 ) goto label$891d561_9_488;
	r30 = r5->length;
	if( ((unsigned)r6) < ((unsigned)r30) ) goto label$891d561_9_268;
	r7 = NULL;
	goto label$891d561_9_271;
	label$891d561_9_268:
	r32 = r5->array;
	r8 = ((vdynamic**)(r32 + 1))[r6];
	r7 = (h3d__scene__Interactive)r8;
	label$891d561_9_271:
	++r6;
	if( r7 == NULL ) hl_null_access();
	r37 = r7->invPos;
	r38 = 0.;
	r50 = r7->preciseShape;
	if( !r50 ) goto label$891d561_9_382;
	if( r22 == NULL ) hl_null_access();
	r39 = r22->px;
	r40 = r22->py;
	r41 = r22->pz;
	if( r37 == NULL ) hl_null_access();
	r44 = r37->_11;
	r42 = r39 * r44;
	r45 = r37->_21;
	r44 = r40 * r45;
	r42 = r42 + r44;
	r45 = r37->_31;
	r44 = r41 * r45;
	r42 = r42 + r44;
	r44 = r37->_41;
	r42 = r42 + r44;
	r45 = r37->_12;
	r44 = r39 * r45;
	r46 = r37->_22;
	r45 = r40 * r46;
	r44 = r44 + r45;
	r46 = r37->_32;
	r45 = r41 * r46;
	r44 = r44 + r45;
	r45 = r37->_42;
	r44 = r44 + r45;
	r46 = r37->_13;
	r45 = r39 * r46;
	r47 = r37->_23;
	r46 = r40 * r47;
	r45 = r45 + r46;
	r47 = r37->_33;
	r46 = r41 * r47;
	r45 = r45 + r46;
	r46 = r37->_43;
	r45 = r45 + r46;
	r22->px = r42;
	r22->py = r44;
	r22->pz = r45;
	r42 = r22->lx;
	r44 = r22->ly;
	r45 = r22->lz;
	r47 = r37->_11;
	r46 = r42 * r47;
	r48 = r37->_21;
	r47 = r44 * r48;
	r46 = r46 + r47;
	r48 = r37->_31;
	r47 = r45 * r48;
	r46 = r46 + r47;
	r48 = r37->_12;
	r47 = r42 * r48;
	r49 = r37->_22;
	r48 = r44 * r49;
	r47 = r47 + r48;
	r49 = r37->_32;
	r48 = r45 * r49;
	r47 = r47 + r48;
	r49 = r37->_13;
	r48 = r42 * r49;
	r52 = r37->_23;
	r49 = r44 * r52;
	r48 = r48 + r49;
	r52 = r37->_33;
	r49 = r45 * r52;
	r48 = r48 + r49;
	r22->lx = r46;
	r22->ly = r47;
	r22->lz = r48;
	h3d_col_Ray_normalize(r22);
	r50 = r7->preciseShape;
	if( r50 == NULL ) hl_null_access();
	r36 = r7->bestMatch;
	r39 = ((double (*)(h3d__col__Collider,h3d__col__Ray,bool))r50->$type->vobj_proto[0])(r50,r22,r36);
	r41 = 0.;
	if( !(r41 < r39) ) goto label$891d561_9_374;
	r40 = r22->px;
	r42 = r22->lx;
	r41 = r39 * r42;
	r40 = r40 + r41;
	r41 = r22->py;
	r44 = r22->ly;
	r42 = r39 * r44;
	r41 = r41 + r42;
	r42 = r22->pz;
	r45 = r22->lz;
	r44 = r39 * r45;
	r42 = r42 + r44;
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r51->x = r40;
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r51->y = r41;
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r51->z = r42;
	goto label$891d561_9_376;
	label$891d561_9_374:
	r40 = 1.;
	r38 = r40;
	label$891d561_9_376:
	r22->px = r23;
	r22->py = r24;
	r22->pz = r25;
	r22->lx = r26;
	r22->ly = r27;
	r22->lz = r28;
	label$891d561_9_382:
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r39 = r51->x;
	r40 = r51->y;
	r41 = r51->z;
	r42 = r51->w;
	r44 = 1.;
	r42 = r44;
	r43 = r7->absPos;
	if( r43 == NULL ) hl_null_access();
	r45 = r43->_11;
	r44 = r39 * r45;
	r46 = r43->_21;
	r45 = r40 * r46;
	r44 = r44 + r45;
	r46 = r43->_31;
	r45 = r41 * r46;
	r44 = r44 + r45;
	r46 = r43->_41;
	r45 = r42 * r46;
	r44 = r44 + r45;
	r46 = r43->_12;
	r45 = r39 * r46;
	r47 = r43->_22;
	r46 = r40 * r47;
	r45 = r45 + r46;
	r47 = r43->_32;
	r46 = r41 * r47;
	r45 = r45 + r46;
	r47 = r43->_42;
	r46 = r42 * r47;
	r45 = r45 + r46;
	r47 = r43->_13;
	r46 = r39 * r47;
	r48 = r43->_23;
	r47 = r40 * r48;
	r46 = r46 + r47;
	r48 = r43->_33;
	r47 = r41 * r48;
	r46 = r46 + r47;
	r48 = r43->_43;
	r47 = r42 * r48;
	r46 = r46 + r47;
	r39 = r44;
	r40 = r45;
	r41 = r46;
	r14 = r0->camera;
	if( r14 == NULL ) hl_null_access();
	r43 = r14->m;
	if( r43 == NULL ) hl_null_access();
	r45 = r43->_11;
	r44 = r44 * r45;
	r46 = r43->_21;
	r45 = r40 * r46;
	r44 = r44 + r45;
	r46 = r43->_31;
	r45 = r41 * r46;
	r44 = r44 + r45;
	r46 = r43->_41;
	r45 = r42 * r46;
	r44 = r44 + r45;
	r46 = r43->_12;
	r45 = r39 * r46;
	r47 = r43->_22;
	r46 = r40 * r47;
	r45 = r45 + r46;
	r47 = r43->_32;
	r46 = r41 * r47;
	r45 = r45 + r46;
	r47 = r43->_42;
	r46 = r42 * r47;
	r45 = r45 + r46;
	r47 = r43->_13;
	r46 = r39 * r47;
	r48 = r43->_23;
	r47 = r40 * r48;
	r46 = r46 + r47;
	r48 = r43->_33;
	r47 = r41 * r48;
	r46 = r46 + r47;
	r48 = r43->_43;
	r47 = r42 * r48;
	r46 = r46 + r47;
	r47 = 1.;
	r49 = r43->_14;
	r48 = r39 * r49;
	r52 = r43->_24;
	r49 = r40 * r52;
	r48 = r48 + r49;
	r52 = r43->_34;
	r49 = r41 * r52;
	r48 = r48 + r49;
	r52 = r43->_44;
	r49 = r42 * r52;
	r48 = r48 + r49;
	r47 = r47 / r48;
	r48 = r44 * r47;
	r48 = r45 * r47;
	r48 = r46 * r47;
	r41 = r48;
	r48 = 1.;
	r53 = r7->hitPoint;
	if( r53 == NULL ) hl_null_access();
	r44 = r41 + r38;
	r53->w = r44;
	goto label$891d561_9_260;
	label$891d561_9_488:
	r5 = r0->hitInteractives;
	if( r5 == NULL ) hl_null_access();
	r54 = hl_alloc_closure_ptr(&t$fun_9e0a57f,h3d_scene_Scene_sortHitPointByCameraDistance,r0);
	if( r54 ) goto label$891d561_9_494;
	r55 = NULL;
	goto label$891d561_9_495;
	label$891d561_9_494:
	r55 = hl_alloc_closure_ptr(&t$fun_390b646,h3d_scene_Scene_handleEvent__$1,r54);
	label$891d561_9_495:
	hl_types_ArrayObj_sort(r5,r55);
	label$891d561_9_496:
	r5 = r0->hitInteractives;
	if( r5 == NULL ) hl_null_access();
	r7 = NULL;
	hl_types_ArrayObj_unshift(r5,((vdynamic*)r7));
	label$891d561_9_500:
	r5 = r0->hitInteractives;
	if( r5 == NULL ) hl_null_access();
	r4 = r5->length;
	r6 = 0;
	if( r6 >= r4 ) goto label$891d561_9_549;
	r5 = r0->hitInteractives;
	if( r5 == NULL ) hl_null_access();
	r8 = hl_types_ArrayObj_pop(r5);
	r7 = (h3d__scene__Interactive)r8;
	if( r7 ) goto label$891d561_9_513;
	r33 = NULL;
	return r33;
	label$891d561_9_513:
	if( r1 == NULL ) hl_null_access();
	if( r7 == NULL ) hl_null_access();
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r9 = r51->x;
	r1->relX = r9;
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r9 = r51->y;
	r1->relY = r9;
	r51 = r7->hitPoint;
	if( r51 == NULL ) hl_null_access();
	r9 = r51->z;
	r1->relZ = r9;
	h3d_scene_Interactive_handleEvent(r7,r1);
	r36 = r1->cancel;
	if( !r36 ) goto label$891d561_9_535;
	r36 = false;
	r1->cancel = r36;
	r36 = false;
	r1->propagate = r36;
	goto label$891d561_9_500;
	label$891d561_9_535:
	r36 = r1->propagate;
	if( r36 ) goto label$891d561_9_548;
	label$891d561_9_537:
	r5 = r0->hitInteractives;
	if( r5 == NULL ) hl_null_access();
	r4 = r5->length;
	r6 = 0;
	if( r6 >= r4 ) goto label$891d561_9_548;
	r5 = r0->hitInteractives;
	if( r5 == NULL ) hl_null_access();
	r8 = hl_types_ArrayObj_pop(r5);
	r33 = (h3d__scene__Interactive)r8;
	goto label$891d561_9_537;
	label$891d561_9_548:
	return r7;
	label$891d561_9_549:
	r7 = NULL;
	return r7;
}

void h3d_scene_Scene_addEventTarget(h3d__scene__Scene r0,h3d__scene__Interactive r1) {
	String r7;
	hl__types__ArrayObj r4;
	vdynamic *r5;
	int r3, r6;
	r4 = r0->interactives;
	if( r4 == NULL ) hl_null_access();
	r5 = NULL;
	r3 = hl_types_ArrayObj_indexOf(r4,((vdynamic*)r1),r5);
	r6 = 0;
	if( r3 < r6 ) goto label$891d561_10_8;
	r7 = (String)s$assert;
	hl_throw((vdynamic*)r7);
	label$891d561_10_8:
	r4 = r0->interactives;
	if( r4 == NULL ) hl_null_access();
	r3 = hl_types_ArrayObj_push(r4,((vdynamic*)r1));
	return;
}

void h3d_scene_Scene_removeEventTarget(h3d__scene__Scene r0,h3d__scene__Interactive r1) {
	vvirtual *r6;
	hl__types__ArrayObj r4;
	bool r3;
	hxd__SceneEvents r5;
	r4 = r0->interactives;
	if( r4 == NULL ) hl_null_access();
	r3 = hl_types_ArrayObj_remove(r4,((vdynamic*)r1));
	if( !r3 ) goto label$891d561_11_19;
	r5 = r0->events;
	if( !r5 ) goto label$891d561_11_16;
	r5 = r0->events;
	if( r5 == NULL ) hl_null_access();
	if( r1 ) goto label$891d561_11_11;
	r6 = NULL;
	goto label$891d561_11_15;
	label$891d561_11_11:
	r6 = r1->f$46;
	if( r6 ) goto label$891d561_11_15;
	r6 = hl_to_virtual(&t$vrt_c8e313e,(vdynamic*)r1);
	r1->f$46 = r6;
	label$891d561_11_15:
	hxd_SceneEvents_onRemove(r5,r6);
	label$891d561_11_16:
	r4 = r0->hitInteractives;
	if( r4 == NULL ) hl_null_access();
	r3 = hl_types_ArrayObj_remove(r4,((vdynamic*)r1));
	label$891d561_11_19:
	return;
}

void h3d_scene_Scene_setElapsedTime(h3d__scene__Scene r0,double r1) {
	h3d__scene__RenderContext r2;
	r2 = r0->ctx;
	if( r2 == NULL ) hl_null_access();
	r2->elapsedTime = r1;
	return;
}

void h3d_scene_Scene_onContextLost(h3d__scene__Scene r0) {
	bool r2;
	h3d__scene__RenderContext r1;
	r1 = r0->ctx;
	if( r1 == NULL ) hl_null_access();
	r2 = true;
	r1->wasContextLost = r2;
	return;
}

void h3d_scene_Scene_render(h3d__scene__Scene r0,h3d__Engine r1) {
	String r28;
	h3d__scene__PassObjects r26, r27;
	hl__types__ArrayObj r15, r19;
	hl_type *r17;
	venum *r12;
	bool r10;
	h3d__scene__Scene r32;
	h3d__scene__Renderer r14;
	h3d__pass__PassList r30;
	h3d__Camera r7;
	h3d__Engine r6;
	h3d__mat__Pass r29;
	h3d__pass__PassObject r23, r25;
	double r8, r9;
	vdynamic *r24;
	h3d__scene__RenderContext r13;
	h3d__impl__Driver r11;
	h3d__scene__LightSystem r31;
	varray *r16;
	h3d__mat__Texture r5;
	int r3, r4, r18, r20, r21, r22;
	r3 = r0->flags;
	r4 = 32;
	r3 = r3 & r4;
	r4 = 0;
	if( r3 != r4 ) goto label$891d561_14_6;
	h3d_scene_Object_onAdd(((h3d__scene__Object)r0));
	label$891d561_14_6:
	if( r1 == NULL ) hl_null_access();
	r5 = h3d_Engine_getCurrentTarget(r1);
	if( r5 ) goto label$891d561_14_18;
	r7 = r0->camera;
	if( r7 == NULL ) hl_null_access();
	r3 = r1->width;
	r8 = (double)r3;
	r3 = r1->height;
	r9 = (double)r3;
	r8 = r8 / r9;
	r7->screenRatio = r8;
	goto label$891d561_14_27;
	label$891d561_14_18:
	r7 = r0->camera;
	if( r7 == NULL ) hl_null_access();
	if( r5 == NULL ) hl_null_access();
	r3 = r5->width;
	r8 = (double)r3;
	r3 = r5->height;
	r9 = (double)r3;
	r8 = r8 / r9;
	r7->screenRatio = r8;
	label$891d561_14_27:
	r7 = r0->camera;
	if( r7 == NULL ) hl_null_access();
	h3d_Camera_update(r7);
	r7 = r0->camera;
	if( r7 == NULL ) hl_null_access();
	r10 = r7->rightHanded;
	if( !r10 ) goto label$891d561_14_39;
	r11 = r1->driver;
	if( r11 == NULL ) hl_null_access();
	r12 = (venum*)g$4b90600;
	r3 = 1;
	((void (*)(h3d__impl__Driver,venum*,int))r11->$type->vobj_proto[1])(r11,r12,r3);
	label$891d561_14_39:
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r7 = r0->camera;
	r13->camera = r7;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r13->engine = r1;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r13->scene = r0;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	h3d_scene_RenderContext_start(r13);
	r14 = r0->renderer;
	if( r14 == NULL ) hl_null_access();
	h3d_scene_Renderer_start(r14);
	r13 = r0->ctx;
	h3d_scene_Object_syncRec(((h3d__scene__Object)r0),r13);
	r13 = r0->ctx;
	h3d_scene_Object_emitRec(((h3d__scene__Object)r0),r13);
	r17 = &t$h3d_scene_PassObjects;
	r3 = 0;
	r16 = hl_alloc_array(r17,r3);
	r15 = hl_types_ArrayObj_alloc(r16);
	r3 = -1;
	r4 = 0;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r19 = r13->passes;
	if( r19 == NULL ) hl_null_access();
	r18 = r19->length;
	label$891d561_14_70:
	if( r4 >= r18 ) goto label$891d561_14_127;
	r20 = r4;
	++r4;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r19 = r13->passes;
	if( r19 == NULL ) hl_null_access();
	r22 = r19->length;
	if( ((unsigned)r20) < ((unsigned)r22) ) goto label$891d561_14_82;
	r23 = NULL;
	goto label$891d561_14_85;
	label$891d561_14_82:
	r16 = r19->array;
	r24 = ((vdynamic**)(r16 + 1))[r20];
	r23 = (h3d__pass__PassObject)r24;
	label$891d561_14_85:
	if( r23 ) goto label$891d561_14_87;
	goto label$891d561_14_70;
	label$891d561_14_87:
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r19 = r13->cachedPassObjects;
	if( r19 == NULL ) hl_null_access();
	++r3;
	r21 = r19->length;
	if( ((unsigned)r3) < ((unsigned)r21) ) goto label$891d561_14_96;
	r26 = NULL;
	goto label$891d561_14_99;
	label$891d561_14_96:
	r16 = r19->array;
	r24 = ((vdynamic**)(r16 + 1))[r3];
	r26 = (h3d__scene__PassObjects)r24;
	label$891d561_14_99:
	if( r26 ) goto label$891d561_14_112;
	r27 = (h3d__scene__PassObjects)hl_alloc_obj(&t$h3d_scene_PassObjects);
	h3d_scene_PassObjects_new(r27);
	r26 = r27;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r19 = r13->cachedPassObjects;
	if( r19 == NULL ) hl_null_access();
	r22 = r19->length;
	if( ((unsigned)r3) < ((unsigned)r22) ) goto label$891d561_14_110;
	hl_types_ArrayObj___expand(r19,r3);
	label$891d561_14_110:
	r16 = r19->array;
	((h3d__scene__PassObjects*)(r16 + 1))[r3] = r27;
	label$891d561_14_112:
	if( r26 == NULL ) hl_null_access();
	if( r23 == NULL ) hl_null_access();
	r29 = r23->pass;
	if( r29 == NULL ) hl_null_access();
	r28 = r29->name;
	r26->name = r28;
	r30 = r26->passes;
	if( r30 == NULL ) hl_null_access();
	r30->current = r23;
	r25 = NULL;
	r30->lastDisc = r25;
	r30->discarded = r25;
	if( r15 == NULL ) hl_null_access();
	r21 = hl_types_ArrayObj_push(r15,((vdynamic*)r26));
	goto label$891d561_14_70;
	label$891d561_14_127:
	r31 = r0->lightSystem;
	if( !r31 ) goto label$891d561_14_137;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r31 = r0->lightSystem;
	r13->lightSystem = r31;
	r31 = r0->lightSystem;
	if( r31 == NULL ) hl_null_access();
	r13 = r0->ctx;
	((void (*)(h3d__scene__LightSystem,h3d__scene__RenderContext))r31->$type->vobj_proto[1])(r31,r13);
	label$891d561_14_137:
	r14 = r0->renderer;
	if( r14 == NULL ) hl_null_access();
	h3d_scene_Renderer_process(r14,r15);
	r7 = r0->camera;
	if( r7 == NULL ) hl_null_access();
	r10 = r7->rightHanded;
	if( !r10 ) goto label$891d561_14_150;
	if( r1 == NULL ) hl_null_access();
	r11 = r1->driver;
	if( r11 == NULL ) hl_null_access();
	r12 = (venum*)g$4b90600;
	r4 = 0;
	((void (*)(h3d__impl__Driver,venum*,int))r11->$type->vobj_proto[1])(r11,r12,r4);
	label$891d561_14_150:
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	h3d_scene_RenderContext_done(r13);
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r10 = false;
	r13->wasContextLost = r10;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r32 = NULL;
	r13->scene = r32;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r7 = NULL;
	r13->camera = r7;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r6 = NULL;
	r13->engine = r6;
	r4 = 0;
	r18 = r3;
	label$891d561_14_171:
	if( r4 >= r18 ) goto label$891d561_14_197;
	r20 = r4;
	++r4;
	r13 = r0->ctx;
	if( r13 == NULL ) hl_null_access();
	r19 = r13->cachedPassObjects;
	if( r19 == NULL ) hl_null_access();
	r22 = r19->length;
	if( ((unsigned)r20) < ((unsigned)r22) ) goto label$891d561_14_183;
	r26 = NULL;
	goto label$891d561_14_186;
	label$891d561_14_183:
	r16 = r19->array;
	r24 = ((vdynamic**)(r16 + 1))[r20];
	r26 = (h3d__scene__PassObjects)r24;
	label$891d561_14_186:
	if( r26 == NULL ) hl_null_access();
	r28 = NULL;
	r26->name = r28;
	r30 = r26->passes;
	if( r30 == NULL ) hl_null_access();
	r23 = NULL;
	r30->current = r23;
	r23 = NULL;
	r30->lastDisc = r23;
	r30->discarded = r23;
	goto label$891d561_14_171;
	label$891d561_14_197:
	return;
}

