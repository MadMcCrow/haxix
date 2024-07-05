﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxd/fmt/fbx/Geometry.h>
#include <hl/types/ArrayBytes_Float.h>
extern String s$Vertices;
vvirtual* hxd_fmt_fbx_FbxTools_get(vvirtual*,String,bool*);
hl__types__ArrayBytes_Float hxd_fmt_fbx_FbxTools_getFloats(vvirtual*);
#include <hl/types/ArrayBytes_Int.h>
extern String s$PolygonVertexIndex;
hl__types__ArrayBytes_Int hxd_fmt_fbx_FbxTools_getInts(vvirtual*);
extern String s$LayerElementMaterial;
extern String s$Materials;
#include <hl/natives.h>
hl__types__ArrayBytes_Int hl_types_ArrayBase_allocI32(vbyte*,int);
int hl_types_ArrayBytes_Int_push(hl__types__ArrayBytes_Int,int);
#include <h3d/MatrixImpl.h>
#include <hxd/fmt/fbx/FbxProp.h>
h3d__MatrixImpl hxd_fmt_fbx_Geometry_getGeomMatrix(hxd__fmt__fbx__Geometry);
extern String s$24aed1e;
int hl_types_ArrayBytes_Float_push(hl__types__ArrayBytes_Float,double);
extern String s$49f5dbb;
extern hl_type t$hl_types_ArrayObj;
String hxd_fmt_fbx_FbxTools_toString(venum*);
extern String s$AllSame;
int String___compare(String,vdynamic*);
hl__types__ArrayBytes_Float hxd_fmt_fbx_Geometry_getNormals(hxd__fmt__fbx__Geometry);
hl__types__ArrayObj hxd_fmt_fbx_Geometry_getUVs(hxd__fmt__fbx__Geometry);
extern String s$Different_UV_layer_;
String String___alloc__(vbyte*,int);
String String___add__(String,String);
extern String s$_should_be_;
extern String s$9371d7a;
extern hl_type t$vrt_55821a7;
extern hl_type t$hl_types_ArrayBytes_Float;
extern hl_type t$hl_types_ArrayBytes_Int;
vvirtual* hxd_fmt_fbx_Geometry_getColors(hxd__fmt__fbx__Geometry);
void hl_types_ArrayBytes_Int___expand(hl__types__ArrayBytes_Int,int);
extern hl_type t$vrt_47d8299;
extern String s$LayerElementNormal;
extern String s$Normals;
hl__types__ArrayBytes_Float hxd_fmt_fbx_Geometry_processVectors(hxd__fmt__fbx__Geometry,String,String,bool*);
String Std_string(vdynamic*);
extern String s$5058f1a;
extern String s$_MappingInformationType;
extern String s$ByVertice;
hl__types__ArrayBytes_Float hl_types_ArrayBase_allocF64(vbyte*,int);
extern String s$LayerElementColor;
extern String s$ColorIndex;
extern String s$Colors;
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern String s$LayerElementUV;
hl__types__ArrayObj hxd_fmt_fbx_FbxTools_getAll(vvirtual*,String);
extern hl_type t$vrt_0813dd2;
extern String s$UVIndex;
extern String s$UV;
int hl_types_ArrayObj_push(hl__types__ArrayObj,vdynamic*);
#include <h3d/VectorImpl.h>
extern String s$Model;
vvirtual* hxd_fmt_fbx_BaseLibrary_getParent(hxd__fmt__fbx__BaseLibrary,vvirtual*,String,vdynamic*);
extern String s$Properties70_P;
extern hl_type t$h3d_VectorImpl;
double hxd_fmt_fbx_FbxTools_toFloat(venum*);
void h3d_VectorImpl_new(h3d__VectorImpl,double*,double*,double*);
extern hl_type t$h3d_MatrixImpl;
void h3d_MatrixImpl_new(h3d__MatrixImpl);
void h3d_MatrixImpl_identity(h3d__MatrixImpl);
void h3d_MatrixImpl_initRotation(h3d__MatrixImpl,double,double,double);

void hxd_fmt_fbx_Geometry_new(hxd__fmt__fbx__Geometry r0,hxd__fmt__fbx__BaseLibrary r1,vvirtual* r2) {
	r0->lib = r1;
	r0->root = r2;
	return;
}

vvirtual* hxd_fmt_fbx_Geometry_getRoot(hxd__fmt__fbx__Geometry r0) {
	vvirtual *r1;
	r1 = r0->root;
	return r1;
}

hl__types__ArrayBytes_Float hxd_fmt_fbx_Geometry_getVertices(hxd__fmt__fbx__Geometry r0) {
	bool *r4;
	String r3;
	vvirtual *r2;
	hl__types__ArrayBytes_Float r1;
	r2 = r0->root;
	r3 = (String)s$Vertices;
	r4 = NULL;
	r2 = hxd_fmt_fbx_FbxTools_get(r2,r3,r4);
	r1 = hxd_fmt_fbx_FbxTools_getFloats(r2);
	return r1;
}

hl__types__ArrayBytes_Int hxd_fmt_fbx_Geometry_getPolygons(hxd__fmt__fbx__Geometry r0) {
	bool *r4;
	String r3;
	vvirtual *r2;
	hl__types__ArrayBytes_Int r1;
	r2 = r0->root;
	r3 = (String)s$PolygonVertexIndex;
	r4 = NULL;
	r2 = hxd_fmt_fbx_FbxTools_get(r2,r3,r4);
	r1 = hxd_fmt_fbx_FbxTools_getInts(r2);
	return r1;
}

hl__types__ArrayBytes_Int hxd_fmt_fbx_Geometry_getMaterials(hxd__fmt__fbx__Geometry r0) {
	bool *r4;
	String r2;
	vvirtual *r1, *r5;
	bool r3;
	hl__types__ArrayBytes_Int r6;
	r1 = r0->root;
	r2 = (String)s$LayerElementMaterial;
	r3 = true;
	r4 = &r3;
	r1 = hxd_fmt_fbx_FbxTools_get(r1,r2,r4);
	if( r1 ) goto label$8345228_5_8;
	r6 = NULL;
	return r6;
	label$8345228_5_8:
	r2 = (String)s$Materials;
	r4 = NULL;
	r5 = hxd_fmt_fbx_FbxTools_get(r1,r2,r4);
	r6 = hxd_fmt_fbx_FbxTools_getInts(r5);
	return r6;
}

hl__types__ArrayBytes_Int hxd_fmt_fbx_Geometry_getMaterialByTriangle(hxd__fmt__fbx__Geometry r0) {
	hl__types__ArrayBytes_Int r1, r4, r7;
	vbyte *r5;
	int r2, r3, r6, r8, r9, r10, r11, r12, r13;
	r1 = hxd_fmt_fbx_Geometry_getMaterials(r0);
	r2 = 0;
	r3 = 0;
	r6 = 0;
	r5 = hl_alloc_bytes(r6);
	r6 = 0;
	r6 = 0;
	r4 = hl_types_ArrayBase_allocI32(r5,r6);
	r6 = 0;
	r7 = hxd_fmt_fbx_Geometry_getPolygons(r0);
	label$8345228_6_10:
	if( r7 == NULL ) hl_null_access();
	r9 = r7->length;
	if( r6 >= r9 ) goto label$8345228_6_50;
	r9 = r7->length;
	if( ((unsigned)r6) < ((unsigned)r9) ) goto label$8345228_6_18;
	r8 = 0;
	goto label$8345228_6_22;
	label$8345228_6_18:
	r5 = r7->bytes;
	r9 = 2;
	r9 = r6 << r9;
	r8 = *(int*)(r5 + r9);
	label$8345228_6_22:
	++r6;
	++r3;
	r10 = 0;
	if( r8 < r10 ) goto label$8345228_6_27;
	goto label$8345228_6_10;
	label$8345228_6_27:
	if( r1 == NULL ) hl_null_access();
	r9 = r2;
	++r2;
	r10 = r1->length;
	if( ((unsigned)r9) < ((unsigned)r10) ) goto label$8345228_6_34;
	r9 = 0;
	goto label$8345228_6_38;
	label$8345228_6_34:
	r5 = r1->bytes;
	r10 = 2;
	r10 = r9 << r10;
	r9 = *(int*)(r5 + r10);
	label$8345228_6_38:
	r10 = 0;
	r12 = 2;
	r11 = r3 - r12;
	label$8345228_6_41:
	if( r10 >= r11 ) goto label$8345228_6_47;
	++r10;
	if( r4 == NULL ) hl_null_access();
	r13 = hl_types_ArrayBytes_Int_push(r4,r9);
	goto label$8345228_6_41;
	label$8345228_6_47:
	r10 = 0;
	r3 = r10;
	goto label$8345228_6_10;
	label$8345228_6_50:
	return r4;
}

void hxd_fmt_fbx_Geometry_merge(hxd__fmt__fbx__Geometry r0,hxd__fmt__fbx__Geometry r1,hl__types__ArrayBytes_Int r2) {
	bool *r23;
	String r10, r26;
	vvirtual *r22, *r34, *r35, *r39;
	hl__types__ArrayObj r21, r32;
	venum *r24;
	bool r38;
	hl__types__ArrayBytes_Int r18, r19, r20, r30;
	hl__types__ArrayBytes_Float r3, r7, r15, r31;
	double r5, r8, r17;
	int *r33;
	vdynamic *r11;
	h3d__MatrixImpl r9;
	varray *r25;
	vbyte *r16;
	int r6, r12, r13, r14, r27, r28, r29, r36, r37;
	r3 = hxd_fmt_fbx_Geometry_getVertices(r0);
	if( r3 == NULL ) hl_null_access();
	r6 = r3->length;
	r5 = (double)r6;
	r8 = 3.;
	r5 = r5 / r8;
	r6 = (int)r5;
	if( r1 == NULL ) hl_null_access();
	r9 = hxd_fmt_fbx_Geometry_getGeomMatrix(r1);
	if( r9 ) goto label$8345228_7_12;
	r9 = hxd_fmt_fbx_Geometry_getGeomMatrix(r0);
	if( !r9 ) goto label$8345228_7_14;
	label$8345228_7_12:
	r10 = (String)s$24aed1e;
	hl_throw((vdynamic*)r10);
	label$8345228_7_14:
	r12 = 0;
	r7 = hxd_fmt_fbx_Geometry_getVertices(r1);
	label$8345228_7_16:
	if( r7 == NULL ) hl_null_access();
	r14 = r7->length;
	if( r12 >= r14 ) goto label$8345228_7_32;
	r14 = r7->length;
	if( ((unsigned)r12) < ((unsigned)r14) ) goto label$8345228_7_24;
	r8 = 0.;
	goto label$8345228_7_28;
	label$8345228_7_24:
	r16 = r7->bytes;
	r14 = 3;
	r14 = r12 << r14;
	r8 = *(double*)(r16 + r14);
	label$8345228_7_28:
	++r12;
	if( r3 == NULL ) hl_null_access();
	r13 = hl_types_ArrayBytes_Float_push(r3,r8);
	goto label$8345228_7_16;
	label$8345228_7_32:
	r18 = hxd_fmt_fbx_Geometry_getPolygons(r0);
	r19 = hxd_fmt_fbx_Geometry_getMaterials(r0);
	if( r19 == NULL ) hl_null_access();
	r12 = r19->length;
	r13 = 1;
	if( r12 != r13 ) goto label$8345228_7_93;
	r22 = r0->root;
	r10 = (String)s$49f5dbb;
	r23 = NULL;
	r22 = hxd_fmt_fbx_FbxTools_get(r22,r10,r23);
	if( r22 == NULL ) hl_null_access();
	r21 = hl_vfields(r22)[2] ? (*(hl__types__ArrayObj*)(hl_vfields(r22)[2])) : (hl__types__ArrayObj)hl_dyn_getp(r22->value,-393222421/*props*/,&t$hl_types_ArrayObj);
	if( r21 == NULL ) hl_null_access();
	r12 = 0;
	r13 = r21->length;
	if( ((unsigned)r12) < ((unsigned)r13) ) goto label$8345228_7_50;
	r24 = NULL;
	goto label$8345228_7_53;
	label$8345228_7_50:
	r25 = r21->array;
	r11 = ((vdynamic**)(r25 + 1))[r12];
	r24 = (venum*)r11;
	label$8345228_7_53:
	r10 = hxd_fmt_fbx_FbxTools_toString(r24);
	r26 = (String)s$AllSame;
	if( r10 != r26 && (!r10 || !r26 || String___compare(r10,(vdynamic*)r26) != 0) ) goto label$8345228_7_93;
	r12 = 0;
	r13 = 0;
	label$8345228_7_58:
	if( r18 == NULL ) hl_null_access();
	r27 = r18->length;
	if( r13 >= r27 ) goto label$8345228_7_75;
	r27 = r18->length;
	if( ((unsigned)r13) < ((unsigned)r27) ) goto label$8345228_7_66;
	r14 = 0;
	goto label$8345228_7_70;
	label$8345228_7_66:
	r16 = r18->bytes;
	r27 = 2;
	r27 = r13 << r27;
	r14 = *(int*)(r16 + r27);
	label$8345228_7_70:
	++r13;
	r28 = 0;
	if( r14 >= r28 ) goto label$8345228_7_74;
	++r12;
	label$8345228_7_74:
	goto label$8345228_7_58;
	label$8345228_7_75:
	if( r19 == NULL ) hl_null_access();
	r13 = 0;
	r14 = r19->length;
	if( ((unsigned)r13) < ((unsigned)r14) ) goto label$8345228_7_81;
	r13 = 0;
	goto label$8345228_7_85;
	label$8345228_7_81:
	r16 = r19->bytes;
	r14 = 2;
	r14 = r13 << r14;
	r13 = *(int*)(r16 + r14);
	label$8345228_7_85:
	r14 = 1;
	r27 = r12;
	label$8345228_7_87:
	if( r14 >= r27 ) goto label$8345228_7_93;
	++r14;
	if( r19 == NULL ) hl_null_access();
	r29 = hl_types_ArrayBytes_Int_push(r19,r13);
	goto label$8345228_7_87;
	label$8345228_7_93:
	r12 = 0;
	r13 = 0;
	if( r1 == NULL ) hl_null_access();
	r20 = hxd_fmt_fbx_Geometry_getPolygons(r1);
	label$8345228_7_97:
	if( r20 == NULL ) hl_null_access();
	r27 = r20->length;
	if( r13 >= r27 ) goto label$8345228_7_119;
	r27 = r20->length;
	if( ((unsigned)r13) < ((unsigned)r27) ) goto label$8345228_7_105;
	r14 = 0;
	goto label$8345228_7_109;
	label$8345228_7_105:
	r16 = r20->bytes;
	r27 = 2;
	r27 = r13 << r27;
	r14 = *(int*)(r16 + r27);
	label$8345228_7_109:
	++r13;
	r29 = 0;
	if( r14 >= r29 ) goto label$8345228_7_115;
	++r12;
	r28 = r14 - r6;
	goto label$8345228_7_116;
	label$8345228_7_115:
	r28 = r14 + r6;
	label$8345228_7_116:
	if( r18 == NULL ) hl_null_access();
	r28 = hl_types_ArrayBytes_Int_push(r18,r28);
	goto label$8345228_7_97;
	label$8345228_7_119:
	r7 = hxd_fmt_fbx_Geometry_getNormals(r0);
	r13 = 0;
	if( r1 == NULL ) hl_null_access();
	r15 = hxd_fmt_fbx_Geometry_getNormals(r1);
	label$8345228_7_123:
	if( r15 == NULL ) hl_null_access();
	r27 = r15->length;
	if( r13 >= r27 ) goto label$8345228_7_139;
	r27 = r15->length;
	if( ((unsigned)r13) < ((unsigned)r27) ) goto label$8345228_7_131;
	r8 = 0.;
	goto label$8345228_7_135;
	label$8345228_7_131:
	r16 = r15->bytes;
	r27 = 3;
	r27 = r13 << r27;
	r8 = *(double*)(r16 + r27);
	label$8345228_7_135:
	++r13;
	if( r7 == NULL ) hl_null_access();
	r14 = hl_types_ArrayBytes_Float_push(r7,r8);
	goto label$8345228_7_123;
	label$8345228_7_139:
	r21 = hxd_fmt_fbx_Geometry_getUVs(r0);
	if( r1 == NULL ) hl_null_access();
	r32 = hxd_fmt_fbx_Geometry_getUVs(r1);
	if( r21 == NULL ) hl_null_access();
	r13 = r21->length;
	if( r32 == NULL ) hl_null_access();
	r14 = r32->length;
	if( r13 == r14 ) goto label$8345228_7_163;
	r10 = (String)s$Different_UV_layer_;
	r13 = r32->length;
	r33 = &r13;
	r16 = hl_itos(r13,r33);
	r26 = String___alloc__(r16,r13);
	r10 = String___add__(r10,r26);
	r26 = (String)s$_should_be_;
	r10 = String___add__(r10,r26);
	r13 = r21->length;
	r33 = &r13;
	r16 = hl_itos(r13,r33);
	r26 = String___alloc__(r16,r13);
	r10 = String___add__(r10,r26);
	r26 = (String)s$9371d7a;
	r10 = String___add__(r10,r26);
	hl_throw((vdynamic*)r10);
	label$8345228_7_163:
	r13 = 0;
	r14 = r21->length;
	label$8345228_7_165:
	if( r13 >= r14 ) goto label$8345228_7_235;
	r27 = r13;
	++r13;
	if( r21 == NULL ) hl_null_access();
	r29 = r21->length;
	if( ((unsigned)r27) < ((unsigned)r29) ) goto label$8345228_7_174;
	r34 = NULL;
	goto label$8345228_7_177;
	label$8345228_7_174:
	r25 = r21->array;
	r11 = ((vdynamic**)(r25 + 1))[r27];
	r34 = hl_to_virtual(&t$vrt_55821a7,(vdynamic*)r11);
	label$8345228_7_177:
	if( r32 == NULL ) hl_null_access();
	r29 = r32->length;
	if( ((unsigned)r27) < ((unsigned)r29) ) goto label$8345228_7_182;
	r35 = NULL;
	goto label$8345228_7_185;
	label$8345228_7_182:
	r25 = r32->array;
	r11 = ((vdynamic**)(r25 + 1))[r27];
	r35 = hl_to_virtual(&t$vrt_55821a7,(vdynamic*)r11);
	label$8345228_7_185:
	if( r34 == NULL ) hl_null_access();
	r15 = hl_vfields(r34)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r34)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r34->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	if( r15 == NULL ) hl_null_access();
	r28 = r15->length;
	r29 = 1;
	r28 = r28 >> r29;
	r29 = 0;
	if( r35 == NULL ) hl_null_access();
	r15 = hl_vfields(r35)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r35)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r35->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	label$8345228_7_194:
	if( r15 == NULL ) hl_null_access();
	r37 = r15->length;
	if( r29 >= r37 ) goto label$8345228_7_212;
	r37 = r15->length;
	if( ((unsigned)r29) < ((unsigned)r37) ) goto label$8345228_7_202;
	r8 = 0.;
	goto label$8345228_7_206;
	label$8345228_7_202:
	r16 = r15->bytes;
	r37 = 3;
	r37 = r29 << r37;
	r8 = *(double*)(r16 + r37);
	label$8345228_7_206:
	++r29;
	if( r34 == NULL ) hl_null_access();
	r31 = hl_vfields(r34)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r34)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r34->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	if( r31 == NULL ) hl_null_access();
	r36 = hl_types_ArrayBytes_Float_push(r31,r8);
	goto label$8345228_7_194;
	label$8345228_7_212:
	r29 = 0;
	if( r35 == NULL ) hl_null_access();
	r20 = hl_vfields(r35)[0] ? (*(hl__types__ArrayBytes_Int*)(hl_vfields(r35)[0])) : (hl__types__ArrayBytes_Int)hl_dyn_getp(r35->value,-32204280/*index*/,&t$hl_types_ArrayBytes_Int);
	label$8345228_7_215:
	if( r20 == NULL ) hl_null_access();
	r37 = r20->length;
	if( r29 >= r37 ) goto label$8345228_7_234;
	r37 = r20->length;
	if( ((unsigned)r29) < ((unsigned)r37) ) goto label$8345228_7_223;
	r36 = 0;
	goto label$8345228_7_227;
	label$8345228_7_223:
	r16 = r20->bytes;
	r37 = 2;
	r37 = r29 << r37;
	r36 = *(int*)(r16 + r37);
	label$8345228_7_227:
	++r29;
	if( r34 == NULL ) hl_null_access();
	r30 = hl_vfields(r34)[0] ? (*(hl__types__ArrayBytes_Int*)(hl_vfields(r34)[0])) : (hl__types__ArrayBytes_Int)hl_dyn_getp(r34->value,-32204280/*index*/,&t$hl_types_ArrayBytes_Int);
	if( r30 == NULL ) hl_null_access();
	r37 = r36 + r28;
	r37 = hl_types_ArrayBytes_Int_push(r30,r37);
	goto label$8345228_7_215;
	label$8345228_7_234:
	goto label$8345228_7_165;
	label$8345228_7_235:
	r34 = hxd_fmt_fbx_Geometry_getColors(r0);
	if( r1 == NULL ) hl_null_access();
	r35 = hxd_fmt_fbx_Geometry_getColors(r1);
	if( !r34 ) goto label$8345228_7_330;
	if( !r35 ) goto label$8345228_7_290;
	if( r34 == NULL ) hl_null_access();
	r15 = hl_vfields(r34)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r34)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r34->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	if( r15 == NULL ) hl_null_access();
	r13 = r15->length;
	r14 = 2;
	r13 = r13 >> r14;
	r14 = 0;
	if( r35 == NULL ) hl_null_access();
	r15 = hl_vfields(r35)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r35)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r35->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	label$8345228_7_249:
	if( r15 == NULL ) hl_null_access();
	r28 = r15->length;
	if( r14 >= r28 ) goto label$8345228_7_267;
	r28 = r15->length;
	if( ((unsigned)r14) < ((unsigned)r28) ) goto label$8345228_7_257;
	r8 = 0.;
	goto label$8345228_7_261;
	label$8345228_7_257:
	r16 = r15->bytes;
	r28 = 3;
	r28 = r14 << r28;
	r8 = *(double*)(r16 + r28);
	label$8345228_7_261:
	++r14;
	if( r34 == NULL ) hl_null_access();
	r31 = hl_vfields(r34)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r34)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r34->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	if( r31 == NULL ) hl_null_access();
	r27 = hl_types_ArrayBytes_Float_push(r31,r8);
	goto label$8345228_7_249;
	label$8345228_7_267:
	r14 = 0;
	if( r35 == NULL ) hl_null_access();
	r20 = hl_vfields(r35)[0] ? (*(hl__types__ArrayBytes_Int*)(hl_vfields(r35)[0])) : (hl__types__ArrayBytes_Int)hl_dyn_getp(r35->value,-32204280/*index*/,&t$hl_types_ArrayBytes_Int);
	label$8345228_7_270:
	if( r20 == NULL ) hl_null_access();
	r28 = r20->length;
	if( r14 >= r28 ) goto label$8345228_7_289;
	r28 = r20->length;
	if( ((unsigned)r14) < ((unsigned)r28) ) goto label$8345228_7_278;
	r27 = 0;
	goto label$8345228_7_282;
	label$8345228_7_278:
	r16 = r20->bytes;
	r28 = 2;
	r28 = r14 << r28;
	r27 = *(int*)(r16 + r28);
	label$8345228_7_282:
	++r14;
	if( r34 == NULL ) hl_null_access();
	r30 = hl_vfields(r34)[0] ? (*(hl__types__ArrayBytes_Int*)(hl_vfields(r34)[0])) : (hl__types__ArrayBytes_Int)hl_dyn_getp(r34->value,-32204280/*index*/,&t$hl_types_ArrayBytes_Int);
	if( r30 == NULL ) hl_null_access();
	r28 = r27 + r13;
	r28 = hl_types_ArrayBytes_Int_push(r30,r28);
	goto label$8345228_7_270;
	label$8345228_7_289:
	goto label$8345228_7_329;
	label$8345228_7_290:
	if( r34 == NULL ) hl_null_access();
	r15 = hl_vfields(r34)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r34)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r34->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	if( r15 == NULL ) hl_null_access();
	r13 = r15->length;
	r14 = 2;
	r13 = r13 >> r14;
	r15 = hxd_fmt_fbx_Geometry_getNormals(r1);
	if( r15 == NULL ) hl_null_access();
	r14 = r15->length;
	r8 = (double)r14;
	r17 = 3.;
	r8 = r8 / r17;
	r14 = (int)r8;
	r15 = hl_vfields(r34)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r34)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r34->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	if( r15 == NULL ) hl_null_access();
	r17 = 1.;
	r27 = hl_types_ArrayBytes_Float_push(r15,r17);
	r15 = hl_vfields(r34)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r34)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r34->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	if( r15 == NULL ) hl_null_access();
	r17 = 1.;
	r27 = hl_types_ArrayBytes_Float_push(r15,r17);
	r15 = hl_vfields(r34)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r34)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r34->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	if( r15 == NULL ) hl_null_access();
	r17 = 1.;
	r27 = hl_types_ArrayBytes_Float_push(r15,r17);
	r15 = hl_vfields(r34)[1] ? (*(hl__types__ArrayBytes_Float*)(hl_vfields(r34)[1])) : (hl__types__ArrayBytes_Float)hl_dyn_getp(r34->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float);
	if( r15 == NULL ) hl_null_access();
	r17 = 1.;
	r27 = hl_types_ArrayBytes_Float_push(r15,r17);
	r27 = 0;
	r28 = r14;
	label$8345228_7_321:
	if( r27 >= r28 ) goto label$8345228_7_329;
	++r27;
	if( r34 == NULL ) hl_null_access();
	r20 = hl_vfields(r34)[0] ? (*(hl__types__ArrayBytes_Int*)(hl_vfields(r34)[0])) : (hl__types__ArrayBytes_Int)hl_dyn_getp(r34->value,-32204280/*index*/,&t$hl_types_ArrayBytes_Int);
	if( r20 == NULL ) hl_null_access();
	r36 = hl_types_ArrayBytes_Int_push(r20,r13);
	goto label$8345228_7_321;
	label$8345228_7_329:
	goto label$8345228_7_335;
	label$8345228_7_330:
	r39 = NULL;
	if( r35 != r39 && (!r35 || !r39 || !r35->value || !r39->value || r35->value != r39->value) ) goto label$8345228_7_334;
	r38 = false;
	goto label$8345228_7_335;
	label$8345228_7_334:
	r38 = true;
	label$8345228_7_335:
	if( r1 == NULL ) hl_null_access();
	r20 = hxd_fmt_fbx_Geometry_getMaterials(r1);
	if( r20 ) goto label$8345228_7_357;
	if( r2 == NULL ) hl_null_access();
	r13 = 0;
	r14 = r2->length;
	if( ((unsigned)r13) < ((unsigned)r14) ) goto label$8345228_7_344;
	r13 = 0;
	goto label$8345228_7_348;
	label$8345228_7_344:
	r16 = r2->bytes;
	r14 = 2;
	r14 = r13 << r14;
	r13 = *(int*)(r16 + r14);
	label$8345228_7_348:
	r14 = 0;
	r27 = r12;
	label$8345228_7_350:
	if( r14 >= r27 ) goto label$8345228_7_356;
	++r14;
	if( r19 == NULL ) hl_null_access();
	r29 = hl_types_ArrayBytes_Int_push(r19,r13);
	goto label$8345228_7_350;
	label$8345228_7_356:
	goto label$8345228_7_416;
	label$8345228_7_357:
	r14 = 1;
	if( r14 >= r12 ) goto label$8345228_7_390;
	if( r20 == NULL ) hl_null_access();
	r13 = r20->length;
	r14 = 1;
	if( r13 != r14 ) goto label$8345228_7_390;
	r13 = 0;
	r14 = r20->length;
	if( ((unsigned)r13) < ((unsigned)r14) ) goto label$8345228_7_368;
	r13 = 0;
	goto label$8345228_7_372;
	label$8345228_7_368:
	r16 = r20->bytes;
	r14 = 2;
	r14 = r13 << r14;
	r13 = *(int*)(r16 + r14);
	label$8345228_7_372:
	r14 = 0;
	r27 = r12;
	label$8345228_7_374:
	if( r14 >= r27 ) goto label$8345228_7_389;
	++r14;
	if( r19 == NULL ) hl_null_access();
	if( r2 == NULL ) hl_null_access();
	r36 = r2->length;
	if( ((unsigned)r13) < ((unsigned)r36) ) goto label$8345228_7_383;
	r29 = 0;
	goto label$8345228_7_387;
	label$8345228_7_383:
	r16 = r2->bytes;
	r36 = 2;
	r36 = r13 << r36;
	r29 = *(int*)(r16 + r36);
	label$8345228_7_387:
	r29 = hl_types_ArrayBytes_Int_push(r19,r29);
	goto label$8345228_7_374;
	label$8345228_7_389:
	goto label$8345228_7_416;
	label$8345228_7_390:
	r13 = 0;
	label$8345228_7_391:
	if( r20 == NULL ) hl_null_access();
	r27 = r20->length;
	if( r13 >= r27 ) goto label$8345228_7_416;
	r27 = r20->length;
	if( ((unsigned)r13) < ((unsigned)r27) ) goto label$8345228_7_399;
	r14 = 0;
	goto label$8345228_7_403;
	label$8345228_7_399:
	r16 = r20->bytes;
	r27 = 2;
	r27 = r13 << r27;
	r14 = *(int*)(r16 + r27);
	label$8345228_7_403:
	++r13;
	if( r19 == NULL ) hl_null_access();
	if( r2 == NULL ) hl_null_access();
	r28 = r2->length;
	if( ((unsigned)r14) < ((unsigned)r28) ) goto label$8345228_7_410;
	r27 = 0;
	goto label$8345228_7_414;
	label$8345228_7_410:
	r16 = r2->bytes;
	r28 = 2;
	r28 = r14 << r28;
	r27 = *(int*)(r16 + r28);
	label$8345228_7_414:
	r27 = hl_types_ArrayBytes_Int_push(r19,r27);
	goto label$8345228_7_391;
	label$8345228_7_416:
	return;
}

vvirtual* hxd_fmt_fbx_Geometry_getIndexes(hxd__fmt__fbx__Geometry r0) {
	vvirtual *r16;
	hl__types__ArrayBytes_Int r4, r5, r8;
	vbyte *r6;
	int r1, r3, r7, r9, r10, r11, r12, r13, r14, r15;
	r1 = 0;
	r3 = 0;
	r4 = hxd_fmt_fbx_Geometry_getPolygons(r0);
	r7 = 0;
	r6 = hl_alloc_bytes(r7);
	r7 = 0;
	r7 = 0;
	r5 = hl_types_ArrayBase_allocI32(r6,r7);
	r7 = 0;
	r6 = hl_alloc_bytes(r7);
	r7 = 0;
	r7 = 0;
	r8 = hl_types_ArrayBase_allocI32(r6,r7);
	r7 = 0;
	label$8345228_8_14:
	if( r4 == NULL ) hl_null_access();
	r10 = r4->length;
	if( r7 >= r10 ) goto label$8345228_8_93;
	r10 = r4->length;
	if( ((unsigned)r7) < ((unsigned)r10) ) goto label$8345228_8_22;
	r9 = 0;
	goto label$8345228_8_26;
	label$8345228_8_22:
	r6 = r4->bytes;
	r10 = 2;
	r10 = r7 << r10;
	r9 = *(int*)(r6 + r10);
	label$8345228_8_26:
	++r7;
	++r1;
	r11 = 0;
	if( r9 >= r11 ) goto label$8345228_8_91;
	r11 = -r9;
	r12 = 1;
	r11 = r11 - r12;
	r12 = r4->length;
	if( ((unsigned)r3) < ((unsigned)r12) ) goto label$8345228_8_36;
	hl_types_ArrayBytes_Int___expand(r4,r3);
	label$8345228_8_36:
	r6 = r4->bytes;
	r12 = 2;
	r12 = r3 << r12;
	*(int*)(r6 + r12) = r11;
	r10 = r3 - r1;
	r11 = 1;
	r10 = r10 + r11;
	r11 = 0;
	r12 = r1;
	label$8345228_8_45:
	if( r11 >= r12 ) goto label$8345228_8_62;
	r13 = r11;
	++r11;
	if( r5 == NULL ) hl_null_access();
	if( r4 == NULL ) hl_null_access();
	r14 = r13 + r10;
	r15 = r4->length;
	if( ((unsigned)r14) < ((unsigned)r15) ) goto label$8345228_8_56;
	r14 = 0;
	goto label$8345228_8_60;
	label$8345228_8_56:
	r6 = r4->bytes;
	r15 = 2;
	r15 = r14 << r15;
	r14 = *(int*)(r6 + r15);
	label$8345228_8_60:
	r14 = hl_types_ArrayBytes_Int_push(r5,r14);
	goto label$8345228_8_45;
	label$8345228_8_62:
	r11 = 0;
	r13 = 2;
	r12 = r1 - r13;
	label$8345228_8_65:
	if( r11 >= r12 ) goto label$8345228_8_81;
	r13 = r11;
	++r11;
	if( r8 == NULL ) hl_null_access();
	r14 = r10 + r13;
	r14 = hl_types_ArrayBytes_Int_push(r8,r14);
	r14 = r10 + r1;
	r15 = 1;
	r14 = r14 - r15;
	r14 = hl_types_ArrayBytes_Int_push(r8,r14);
	r14 = r10 + r13;
	r15 = 1;
	r14 = r14 + r15;
	r14 = hl_types_ArrayBytes_Int_push(r8,r14);
	goto label$8345228_8_65;
	label$8345228_8_81:
	if( r4 == NULL ) hl_null_access();
	r13 = r4->length;
	if( ((unsigned)r3) < ((unsigned)r13) ) goto label$8345228_8_85;
	hl_types_ArrayBytes_Int___expand(r4,r3);
	label$8345228_8_85:
	r6 = r4->bytes;
	r13 = 2;
	r13 = r3 << r13;
	*(int*)(r6 + r13) = r9;
	r11 = 0;
	r1 = r11;
	label$8345228_8_91:
	++r3;
	goto label$8345228_8_14;
	label$8345228_8_93:
	r16 = hl_alloc_virtual(&t$vrt_47d8299);
	if( hl_vfields(r16)[1] ) *(hl__types__ArrayBytes_Int*)(hl_vfields(r16)[1]) = (hl__types__ArrayBytes_Int)r5; else hl_dyn_setp(r16->value,240071313/*vidx*/,&t$hl_types_ArrayBytes_Int,r5);
	if( hl_vfields(r16)[0] ) *(hl__types__ArrayBytes_Int*)(hl_vfields(r16)[0]) = (hl__types__ArrayBytes_Int)r8; else hl_dyn_setp(r16->value,5243965/*idx*/,&t$hl_types_ArrayBytes_Int,r8);
	return r16;
}

hl__types__ArrayBytes_Float hxd_fmt_fbx_Geometry_getNormals(hxd__fmt__fbx__Geometry r0) {
	bool *r4;
	String r2, r3;
	hl__types__ArrayBytes_Float r1;
	r2 = (String)s$LayerElementNormal;
	r3 = (String)s$Normals;
	r4 = NULL;
	r1 = hxd_fmt_fbx_Geometry_processVectors(r0,r2,r3,r4);
	return r1;
}

hl__types__ArrayBytes_Float hxd_fmt_fbx_Geometry_processVectors(hxd__fmt__fbx__Geometry r0,String r1,String r2,bool* r3) {
	String r6, r7;
	hl__types__ArrayObj r12;
	vvirtual *r5, *r9;
	venum *r15;
	bool r4, r8;
	hl__types__ArrayBytes_Int r19;
	hl__types__ArrayBytes_Float r10, r17;
	double r23;
	vdynamic *r11;
	vbyte *r18;
	varray *r16;
	int r13, r14, r20, r21, r22;
	if( r3 ) goto label$8345228_10_3;
	r4 = false;
	goto label$8345228_10_4;
	label$8345228_10_3:
	r4 = *r3;
	label$8345228_10_4:
	r5 = r0->root;
	r6 = Std_string(((vdynamic*)r1));
	r7 = (String)s$5058f1a;
	r6 = String___add__(r6,r7);
	r7 = Std_string(((vdynamic*)r2));
	r6 = String___add__(r6,r7);
	r8 = r4;
	r3 = &r8;
	r5 = hxd_fmt_fbx_FbxTools_get(r5,r6,r3);
	if( r5 ) goto label$8345228_10_16;
	r10 = NULL;
	return r10;
	label$8345228_10_16:
	r10 = hxd_fmt_fbx_FbxTools_getFloats(r5);
	r9 = r0->root;
	r6 = Std_string(((vdynamic*)r1));
	r7 = (String)s$_MappingInformationType;
	r6 = String___add__(r6,r7);
	r3 = NULL;
	r9 = hxd_fmt_fbx_FbxTools_get(r9,r6,r3);
	if( r9 == NULL ) hl_null_access();
	r12 = hl_vfields(r9)[2] ? (*(hl__types__ArrayObj*)(hl_vfields(r9)[2])) : (hl__types__ArrayObj)hl_dyn_getp(r9->value,-393222421/*props*/,&t$hl_types_ArrayObj);
	if( r12 == NULL ) hl_null_access();
	r13 = 0;
	r14 = r12->length;
	if( ((unsigned)r13) < ((unsigned)r14) ) goto label$8345228_10_31;
	r15 = NULL;
	goto label$8345228_10_34;
	label$8345228_10_31:
	r16 = r12->array;
	r11 = ((vdynamic**)(r16 + 1))[r13];
	r15 = (venum*)r11;
	label$8345228_10_34:
	r6 = hxd_fmt_fbx_FbxTools_toString(r15);
	r7 = (String)s$ByVertice;
	if( r6 != r7 && (!r6 || !r7 || String___compare(r6,(vdynamic*)r7) != 0) ) goto label$8345228_10_105;
	r13 = 0;
	r18 = hl_alloc_bytes(r13);
	r13 = 0;
	r13 = 0;
	r17 = hl_types_ArrayBase_allocF64(r18,r13);
	r13 = 0;
	r19 = hxd_fmt_fbx_Geometry_getPolygons(r0);
	label$8345228_10_44:
	if( r19 == NULL ) hl_null_access();
	r20 = r19->length;
	if( r13 >= r20 ) goto label$8345228_10_104;
	r20 = r19->length;
	if( ((unsigned)r13) < ((unsigned)r20) ) goto label$8345228_10_52;
	r14 = 0;
	goto label$8345228_10_56;
	label$8345228_10_52:
	r18 = r19->bytes;
	r20 = 2;
	r20 = r13 << r20;
	r14 = *(int*)(r18 + r20);
	label$8345228_10_56:
	++r13;
	r20 = r14;
	r22 = 0;
	if( r14 >= r22 ) goto label$8345228_10_64;
	r21 = -r14;
	r22 = 1;
	r21 = r21 - r22;
	r20 = r21;
	label$8345228_10_64:
	if( r17 == NULL ) hl_null_access();
	if( r10 == NULL ) hl_null_access();
	r22 = 3;
	r21 = r20 * r22;
	r22 = r10->length;
	if( ((unsigned)r21) < ((unsigned)r22) ) goto label$8345228_10_72;
	r23 = 0.;
	goto label$8345228_10_76;
	label$8345228_10_72:
	r18 = r10->bytes;
	r22 = 3;
	r22 = r21 << r22;
	r23 = *(double*)(r18 + r22);
	label$8345228_10_76:
	r21 = hl_types_ArrayBytes_Float_push(r17,r23);
	r22 = 3;
	r21 = r20 * r22;
	r22 = 1;
	r21 = r21 + r22;
	r22 = r10->length;
	if( ((unsigned)r21) < ((unsigned)r22) ) goto label$8345228_10_85;
	r23 = 0.;
	goto label$8345228_10_89;
	label$8345228_10_85:
	r18 = r10->bytes;
	r22 = 3;
	r22 = r21 << r22;
	r23 = *(double*)(r18 + r22);
	label$8345228_10_89:
	r21 = hl_types_ArrayBytes_Float_push(r17,r23);
	r22 = 3;
	r21 = r20 * r22;
	r22 = 2;
	r21 = r21 + r22;
	r22 = r10->length;
	if( ((unsigned)r21) < ((unsigned)r22) ) goto label$8345228_10_98;
	r23 = 0.;
	goto label$8345228_10_102;
	label$8345228_10_98:
	r18 = r10->bytes;
	r22 = 3;
	r22 = r21 << r22;
	r23 = *(double*)(r18 + r22);
	label$8345228_10_102:
	r21 = hl_types_ArrayBytes_Float_push(r17,r23);
	goto label$8345228_10_44;
	label$8345228_10_104:
	r10 = r17;
	label$8345228_10_105:
	return r10;
}

vvirtual* hxd_fmt_fbx_Geometry_getColors(hxd__fmt__fbx__Geometry r0) {
	bool *r4;
	String r2;
	vvirtual *r1, *r5, *r6, *r8;
	bool r3, r7;
	hl__types__ArrayBytes_Int r10;
	hl__types__ArrayBytes_Float r9;
	r1 = r0->root;
	r2 = (String)s$LayerElementColor;
	r3 = true;
	r4 = &r3;
	r1 = hxd_fmt_fbx_FbxTools_get(r1,r2,r4);
	if( r1 ) goto label$8345228_11_8;
	r6 = NULL;
	return r6;
	label$8345228_11_8:
	r2 = (String)s$ColorIndex;
	r7 = true;
	r4 = &r7;
	r5 = hxd_fmt_fbx_FbxTools_get(r1,r2,r4);
	if( r5 ) goto label$8345228_11_15;
	r6 = NULL;
	return r6;
	label$8345228_11_15:
	r6 = hl_alloc_virtual(&t$vrt_55821a7);
	r2 = (String)s$Colors;
	r4 = NULL;
	r8 = hxd_fmt_fbx_FbxTools_get(r1,r2,r4);
	r9 = hxd_fmt_fbx_FbxTools_getFloats(r8);
	if( hl_vfields(r6)[1] ) *(hl__types__ArrayBytes_Float*)(hl_vfields(r6)[1]) = (hl__types__ArrayBytes_Float)r9; else hl_dyn_setp(r6->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float,r9);
	r10 = hxd_fmt_fbx_FbxTools_getInts(r5);
	if( hl_vfields(r6)[0] ) *(hl__types__ArrayBytes_Int*)(hl_vfields(r6)[0]) = (hl__types__ArrayBytes_Int)r10; else hl_dyn_setp(r6->value,-32204280/*index*/,&t$hl_types_ArrayBytes_Int,r10);
	return r6;
}

hl__types__ArrayObj hxd_fmt_fbx_Geometry_getUVs(hxd__fmt__fbx__Geometry r0) {
	bool *r13;
	String r7;
	vvirtual *r6, *r11, *r15, *r21;
	hl__types__ArrayObj r1, r5;
	hl_type *r3;
	bool r12;
	hl__types__ArrayBytes_Int r16, r18;
	hl__types__ArrayBytes_Float r14;
	vdynamic *r10;
	vbyte *r17;
	int r4, r8, r9, r19, r20;
	varray *r2;
	r3 = &t$vrt_55821a7;
	r4 = 0;
	r2 = hl_alloc_array(r3,r4);
	r1 = hl_types_ArrayObj_alloc(r2);
	r4 = 0;
	r6 = r0->root;
	r7 = (String)s$LayerElementUV;
	r5 = hxd_fmt_fbx_FbxTools_getAll(r6,r7);
	label$8345228_12_8:
	if( r5 == NULL ) hl_null_access();
	r9 = r5->length;
	if( r4 >= r9 ) goto label$8345228_12_68;
	r9 = r5->length;
	if( ((unsigned)r4) < ((unsigned)r9) ) goto label$8345228_12_16;
	r6 = NULL;
	goto label$8345228_12_19;
	label$8345228_12_16:
	r2 = r5->array;
	r10 = ((vdynamic**)(r2 + 1))[r4];
	r6 = hl_to_virtual(&t$vrt_0813dd2,(vdynamic*)r10);
	label$8345228_12_19:
	++r4;
	r7 = (String)s$UVIndex;
	r12 = true;
	r13 = &r12;
	r11 = hxd_fmt_fbx_FbxTools_get(r6,r7,r13);
	r7 = (String)s$UV;
	r13 = NULL;
	r15 = hxd_fmt_fbx_FbxTools_get(r6,r7,r13);
	r14 = hxd_fmt_fbx_FbxTools_getFloats(r15);
	if( r11 ) goto label$8345228_12_61;
	r8 = 0;
	r17 = hl_alloc_bytes(r8);
	r8 = 0;
	r8 = 0;
	r16 = hl_types_ArrayBase_allocI32(r17,r8);
	r8 = 0;
	r18 = hxd_fmt_fbx_Geometry_getPolygons(r0);
	label$8345228_12_36:
	if( r18 == NULL ) hl_null_access();
	r19 = r18->length;
	if( r8 >= r19 ) goto label$8345228_12_60;
	r19 = r18->length;
	if( ((unsigned)r8) < ((unsigned)r19) ) goto label$8345228_12_44;
	r9 = 0;
	goto label$8345228_12_48;
	label$8345228_12_44:
	r17 = r18->bytes;
	r19 = 2;
	r19 = r8 << r19;
	r9 = *(int*)(r17 + r19);
	label$8345228_12_48:
	++r8;
	r20 = 0;
	if( r9 >= r20 ) goto label$8345228_12_57;
	if( r16 == NULL ) hl_null_access();
	r19 = -r9;
	r20 = 1;
	r19 = r19 - r20;
	r19 = hl_types_ArrayBytes_Int_push(r16,r19);
	goto label$8345228_12_59;
	label$8345228_12_57:
	if( r16 == NULL ) hl_null_access();
	r19 = hl_types_ArrayBytes_Int_push(r16,r9);
	label$8345228_12_59:
	goto label$8345228_12_36;
	label$8345228_12_60:
	goto label$8345228_12_62;
	label$8345228_12_61:
	r16 = hxd_fmt_fbx_FbxTools_getInts(r11);
	label$8345228_12_62:
	if( r1 == NULL ) hl_null_access();
	r21 = hl_alloc_virtual(&t$vrt_55821a7);
	if( hl_vfields(r21)[1] ) *(hl__types__ArrayBytes_Float*)(hl_vfields(r21)[1]) = (hl__types__ArrayBytes_Float)r14; else hl_dyn_setp(r21->value,263652588/*values*/,&t$hl_types_ArrayBytes_Float,r14);
	if( hl_vfields(r21)[0] ) *(hl__types__ArrayBytes_Int*)(hl_vfields(r21)[0]) = (hl__types__ArrayBytes_Int)r16; else hl_dyn_setp(r21->value,-32204280/*index*/,&t$hl_types_ArrayBytes_Int,r16);
	r8 = hl_types_ArrayObj_push(r1,((vdynamic*)r21));
	goto label$8345228_12_8;
	label$8345228_12_68:
	return r1;
}

h3d__MatrixImpl hxd_fmt_fbx_Geometry_getGeomMatrix(hxd__fmt__fbx__Geometry r0) {
	String r8;
	h3d__VectorImpl r1, r3, r18;
	vvirtual *r6;
	hl__types__ArrayObj r5, r12;
	venum *r15;
	bool r26;
	double r19, r20, r22, r24, r27, r28, r30, r31, r32;
	hxd__fmt__fbx__BaseLibrary r7;
	h3d__MatrixImpl r29;
	double *r21, *r23, *r25;
	vdynamic *r9, *r13;
	vbyte *r16, *r17;
	varray *r14;
	int r4, r10, r11;
	r1 = NULL;
	r3 = NULL;
	r4 = 0;
	r7 = r0->lib;
	if( r7 == NULL ) hl_null_access();
	r6 = r0->root;
	r8 = (String)s$Model;
	r9 = NULL;
	r6 = hxd_fmt_fbx_BaseLibrary_getParent(r7,r6,r8,r9);
	r8 = (String)s$Properties70_P;
	r5 = hxd_fmt_fbx_FbxTools_getAll(r6,r8);
	label$8345228_13_11:
	if( r5 == NULL ) hl_null_access();
	r11 = r5->length;
	if( r4 >= r11 ) goto label$8345228_13_155;
	r11 = r5->length;
	if( ((unsigned)r4) < ((unsigned)r11) ) goto label$8345228_13_19;
	r6 = NULL;
	goto label$8345228_13_22;
	label$8345228_13_19:
	r14 = r5->array;
	r13 = ((vdynamic**)(r14 + 1))[r4];
	r6 = hl_to_virtual(&t$vrt_0813dd2,(vdynamic*)r13);
	label$8345228_13_22:
	++r4;
	if( r6 == NULL ) hl_null_access();
	r12 = hl_vfields(r6)[2] ? (*(hl__types__ArrayObj*)(hl_vfields(r6)[2])) : (hl__types__ArrayObj)hl_dyn_getp(r6->value,-393222421/*props*/,&t$hl_types_ArrayObj);
	if( r12 == NULL ) hl_null_access();
	r10 = 0;
	r11 = r12->length;
	if( ((unsigned)r10) < ((unsigned)r11) ) goto label$8345228_13_31;
	r15 = NULL;
	goto label$8345228_13_34;
	label$8345228_13_31:
	r14 = r12->array;
	r13 = ((vdynamic**)(r14 + 1))[r10];
	r15 = (venum*)r13;
	label$8345228_13_34:
	r8 = hxd_fmt_fbx_FbxTools_toString(r15);
	if( !r8 ) goto label$8345228_13_44;
	r10 = r8->length;
	r11 = 17;
	if( r10 != r11 ) goto label$8345228_13_44;
	r16 = r8->bytes;
	r17 = (vbyte*)USTR("GeometricRotation");
	r10 = hl_string_compare(r16,r17,r10);
	r11 = 0;
	if( r10 == r11 ) goto label$8345228_13_54;
	label$8345228_13_44:
	if( !r8 ) goto label$8345228_13_53;
	r10 = r8->length;
	r11 = 20;
	if( r10 != r11 ) goto label$8345228_13_53;
	r16 = r8->bytes;
	r17 = (vbyte*)USTR("GeometricTranslation");
	r10 = hl_string_compare(r16,r17,r10);
	r11 = 0;
	if( r10 == r11 ) goto label$8345228_13_106;
	label$8345228_13_53:
	goto label$8345228_13_154;
	label$8345228_13_54:
	r18 = (h3d__VectorImpl)hl_alloc_obj(&t$h3d_VectorImpl);
	r12 = hl_vfields(r6)[2] ? (*(hl__types__ArrayObj*)(hl_vfields(r6)[2])) : (hl__types__ArrayObj)hl_dyn_getp(r6->value,-393222421/*props*/,&t$hl_types_ArrayObj);
	if( r12 == NULL ) hl_null_access();
	r10 = 4;
	r11 = r12->length;
	if( ((unsigned)r10) < ((unsigned)r11) ) goto label$8345228_13_62;
	r15 = NULL;
	goto label$8345228_13_65;
	label$8345228_13_62:
	r14 = r12->array;
	r13 = ((vdynamic**)(r14 + 1))[r10];
	r15 = (venum*)r13;
	label$8345228_13_65:
	r19 = hxd_fmt_fbx_FbxTools_toFloat(r15);
	r20 = 3.141592653589793116;
	r19 = r19 * r20;
	r20 = 180.;
	r19 = r19 / r20;
	r21 = &r19;
	r12 = hl_vfields(r6)[2] ? (*(hl__types__ArrayObj*)(hl_vfields(r6)[2])) : (hl__types__ArrayObj)hl_dyn_getp(r6->value,-393222421/*props*/,&t$hl_types_ArrayObj);
	if( r12 == NULL ) hl_null_access();
	r10 = 5;
	r11 = r12->length;
	if( ((unsigned)r10) < ((unsigned)r11) ) goto label$8345228_13_78;
	r15 = NULL;
	goto label$8345228_13_81;
	label$8345228_13_78:
	r14 = r12->array;
	r13 = ((vdynamic**)(r14 + 1))[r10];
	r15 = (venum*)r13;
	label$8345228_13_81:
	r20 = hxd_fmt_fbx_FbxTools_toFloat(r15);
	r22 = 3.141592653589793116;
	r20 = r20 * r22;
	r22 = 180.;
	r20 = r20 / r22;
	r23 = &r20;
	r12 = hl_vfields(r6)[2] ? (*(hl__types__ArrayObj*)(hl_vfields(r6)[2])) : (hl__types__ArrayObj)hl_dyn_getp(r6->value,-393222421/*props*/,&t$hl_types_ArrayObj);
	if( r12 == NULL ) hl_null_access();
	r10 = 6;
	r11 = r12->length;
	if( ((unsigned)r10) < ((unsigned)r11) ) goto label$8345228_13_94;
	r15 = NULL;
	goto label$8345228_13_97;
	label$8345228_13_94:
	r14 = r12->array;
	r13 = ((vdynamic**)(r14 + 1))[r10];
	r15 = (venum*)r13;
	label$8345228_13_97:
	r22 = hxd_fmt_fbx_FbxTools_toFloat(r15);
	r24 = 3.141592653589793116;
	r22 = r22 * r24;
	r24 = 180.;
	r22 = r22 / r24;
	r25 = &r22;
	h3d_VectorImpl_new(r18,r21,r23,r25);
	r1 = r18;
	goto label$8345228_13_154;
	label$8345228_13_106:
	r18 = (h3d__VectorImpl)hl_alloc_obj(&t$h3d_VectorImpl);
	r12 = hl_vfields(r6)[2] ? (*(hl__types__ArrayObj*)(hl_vfields(r6)[2])) : (hl__types__ArrayObj)hl_dyn_getp(r6->value,-393222421/*props*/,&t$hl_types_ArrayObj);
	if( r12 == NULL ) hl_null_access();
	r10 = 4;
	r11 = r12->length;
	if( ((unsigned)r10) < ((unsigned)r11) ) goto label$8345228_13_114;
	r15 = NULL;
	goto label$8345228_13_117;
	label$8345228_13_114:
	r14 = r12->array;
	r13 = ((vdynamic**)(r14 + 1))[r10];
	r15 = (venum*)r13;
	label$8345228_13_117:
	r24 = hxd_fmt_fbx_FbxTools_toFloat(r15);
	r7 = r0->lib;
	if( r7 == NULL ) hl_null_access();
	r26 = r7->leftHand;
	if( !r26 ) goto label$8345228_13_124;
	r10 = -1;
	goto label$8345228_13_125;
	label$8345228_13_124:
	r10 = 1;
	label$8345228_13_125:
	r27 = (double)r10;
	r24 = r24 * r27;
	r21 = &r24;
	r12 = hl_vfields(r6)[2] ? (*(hl__types__ArrayObj*)(hl_vfields(r6)[2])) : (hl__types__ArrayObj)hl_dyn_getp(r6->value,-393222421/*props*/,&t$hl_types_ArrayObj);
	if( r12 == NULL ) hl_null_access();
	r10 = 5;
	r11 = r12->length;
	if( ((unsigned)r10) < ((unsigned)r11) ) goto label$8345228_13_135;
	r15 = NULL;
	goto label$8345228_13_138;
	label$8345228_13_135:
	r14 = r12->array;
	r13 = ((vdynamic**)(r14 + 1))[r10];
	r15 = (venum*)r13;
	label$8345228_13_138:
	r27 = hxd_fmt_fbx_FbxTools_toFloat(r15);
	r23 = &r27;
	r12 = hl_vfields(r6)[2] ? (*(hl__types__ArrayObj*)(hl_vfields(r6)[2])) : (hl__types__ArrayObj)hl_dyn_getp(r6->value,-393222421/*props*/,&t$hl_types_ArrayObj);
	if( r12 == NULL ) hl_null_access();
	r10 = 6;
	r11 = r12->length;
	if( ((unsigned)r10) < ((unsigned)r11) ) goto label$8345228_13_147;
	r15 = NULL;
	goto label$8345228_13_150;
	label$8345228_13_147:
	r14 = r12->array;
	r13 = ((vdynamic**)(r14 + 1))[r10];
	r15 = (venum*)r13;
	label$8345228_13_150:
	r28 = hxd_fmt_fbx_FbxTools_toFloat(r15);
	r25 = &r28;
	h3d_VectorImpl_new(r18,r21,r23,r25);
	r3 = r18;
	label$8345228_13_154:
	goto label$8345228_13_11;
	label$8345228_13_155:
	if( r1 ) goto label$8345228_13_159;
	if( r3 ) goto label$8345228_13_159;
	r29 = NULL;
	return r29;
	label$8345228_13_159:
	r29 = (h3d__MatrixImpl)hl_alloc_obj(&t$h3d_MatrixImpl);
	h3d_MatrixImpl_new(r29);
	if( r1 ) goto label$8345228_13_164;
	h3d_MatrixImpl_identity(r29);
	goto label$8345228_13_169;
	label$8345228_13_164:
	if( r1 == NULL ) hl_null_access();
	r30 = r1->x;
	r31 = r1->y;
	r32 = r1->z;
	h3d_MatrixImpl_initRotation(r29,r30,r31,r32);
	label$8345228_13_169:
	if( !r3 ) goto label$8345228_13_183;
	r30 = r29->_41;
	if( r3 == NULL ) hl_null_access();
	r31 = r3->x;
	r30 = r30 + r31;
	r29->_41 = r30;
	r30 = r29->_42;
	r31 = r3->y;
	r30 = r30 + r31;
	r29->_42 = r30;
	r30 = r29->_43;
	r31 = r3->z;
	r30 = r30 + r31;
	r29->_43 = r30;
	label$8345228_13_183:
	return r29;
}
