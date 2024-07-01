﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxsl/Serializer.h>
int haxe_io_BytesInput_readByte(haxe__io__BytesInput);
#include <haxe/io/Input.h>
int haxe_io_Input_readInt32(haxe__io__Input);
#include <hxsl/Type.h>
#include <hxsl/VecType.h>
#include <hl/types/ArrayDyn.h>
#include <hxsl/VarKind.h>
#include <hxsl/SizeDecl.h>
extern String s$assert;
extern venum* g$hxsl_Type_TVoid;
extern venum* g$hxsl_Type_TInt;
extern venum* g$hxsl_Type_TBool;
extern venum* g$hxsl_Type_TFloat;
extern venum* g$hxsl_Type_TString;
extern hxsl__$Serializer g$_hxsl_Serializer;
vdynamic* haxe_ds_IntMap_get(haxe__ds__IntMap,int);
extern hxsl__$VecType g$hxsl_VecType;
vdynamic* Type_createEnumIndex(hl__BaseType,int,hl__types__ArrayDyn);
extern hl_type t$hxsl_VecType;
extern hl_type t$_dyn;
extern hl_type t$hxsl_Type;
void haxe_ds_IntMap_set(haxe__ds__IntMap,int,vdynamic*);
extern venum* g$hxsl_Type_TMat3;
extern venum* g$hxsl_Type_TMat4;
extern venum* g$hxsl_Type_TMat3x4;
extern venum* g$hxsl_Type_TSampler2D;
extern venum* g$hxsl_Type_TSampler2DArray;
extern venum* g$hxsl_Type_TSamplerCube;
vvirtual* hxsl_Serializer_readVar(hxsl__Serializer);
extern hl_type t$fun_23d1dcc;
extern hl_type t$vrt_09f4a29;
#include <hl/natives.h>
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
int hl_types_ArrayObj_push(hl__types__ArrayObj,vdynamic*);
void hl_types_ArrayObj___expand(hl__types__ArrayObj,int);
extern hl_type t$hxsl_SizeDecl;
extern venum* g$hxsl_Type_TMat2;
#include <haxe/io/Bytes.h>
#include <haxe/io/Encoding.h>
haxe__io__Bytes haxe_io_Input_read(haxe__io__Input,int);
String haxe_io_Bytes_getString(haxe__io__Bytes,int,int,venum*);
#include <hxsl/Const.h>
extern venum* g$hxsl_Const_CNull;
extern hl_type t$hxsl_Const;
double haxe_io_Input_readDouble(haxe__io__Input);
#include <hxsl/TExprDef.h>
#include <hxsl/TGlobal.h>
#include <haxe/macro/Binop.h>
#include <haxe/macro/Unop.h>
#include <hxsl/Component.h>
extern hl_type t$hxsl_TExprDef;
extern hl_type t$fun_101847d;
extern hl_type t$vrt_6e3ace9;
extern hl_type t$haxe_macro_Binop;
int haxe_io_Input_readUInt16(haxe__io__Input);
extern hl_type t$hl_types_ArrayObj;
extern hl_type t$hxsl_Component;
extern venum* g$hxsl_TExprDef_TDiscard;
extern venum* g$hxsl_TExprDef_TContinue;
extern venum* g$hxsl_TExprDef_TBreak;
extern hl_type t$vrt_15384e6;
extern hl_type t$fun_48dadd5;
extern hl_type t$vrt_379f5a4;
#include <hxsl/VarQualifier.h>
#include <hxsl/Prec.h>
int hxsl_Tools_allocVarId(void);
extern hl_type t$_i32;
extern hl_type t$String;
extern hl_type t$hxsl_VarKind;
extern hl_type t$hxsl_VarQualifier;
extern venum* g$hxsl_VarQualifier_Private;
extern venum* g$hxsl_VarQualifier_Nullable;
extern venum* g$hxsl_VarQualifier_PerObject;
extern venum* g$hxsl_VarQualifier_Shared;
extern venum* g$hxsl_VarQualifier_Ignore;
#include <hxsl/FunctionKind.h>
extern hl_type t$vrt_ab557b2;
extern hl_type t$hxsl_FunctionKind;
extern hl_type t$haxe_io_BytesInput;
haxe__io__Bytes haxe_crypto_Base64_decode(String,bool*);
void haxe_io_BytesInput_new(haxe__io__BytesInput,haxe__io__Bytes,vdynamic*,vdynamic*);
extern String s$Invalid_HXSL_data;
extern hl_type t$haxe_ds_IntMap;
void haxe_ds_IntMap_new(haxe__ds__IntMap);
extern hl_type t$fun_b797f9a;
extern hl_type t$vrt_f479cb2;

void hxsl_Serializer_new(hxsl__Serializer r0) {
	return;
}

int hxsl_Serializer_readVarInt(hxsl__Serializer r0) {
	haxe__io__BytesInput r2;
	int r1, r3, r4;
	r2 = r0->input;
	if( r2 == NULL ) hl_null_access();
	r1 = haxe_io_BytesInput_readByte(r2);
	r4 = 128;
	if( r1 >= r4 ) goto label$0d3d4b3_2_6;
	return r1;
	label$0d3d4b3_2_6:
	r4 = 255;
	if( r1 != r4 ) goto label$0d3d4b3_2_12;
	r2 = r0->input;
	if( r2 == NULL ) hl_null_access();
	r3 = haxe_io_Input_readInt32(((haxe__io__Input)r2));
	return r3;
	label$0d3d4b3_2_12:
	r4 = 127;
	r3 = r1 & r4;
	r4 = 8;
	r3 = r3 << r4;
	r2 = r0->input;
	if( r2 == NULL ) hl_null_access();
	r4 = haxe_io_BytesInput_readByte(r2);
	r3 = r3 | r4;
	return r3;
}

venum* hxsl_Serializer_readType(hxsl__Serializer r0) {
	String r4;
	vvirtual *r22;
	hl__types__ArrayObj r16, r21;
	haxe__io__BytesInput r3;
	hl_type *r19;
	venum *r6, *r10, *r15, *r23;
	hxsl__$VecType r12;
	haxe__ds__IntMap r7;
	vclosure *r18;
	hl__types__ArrayDyn r14;
	hxsl__$Serializer r8;
	vdynamic *r5;
	varray *r17;
	int r2, r9, r11, r13, r20;
	r3 = r0->input;
	if( r3 == NULL ) hl_null_access();
	r2 = haxe_io_BytesInput_readByte(r3);
	switch(r2) {
		default:
			r4 = (String)s$assert;
			hl_throw((vdynamic*)r4);
		case 0:
			r6 = (venum*)g$hxsl_Type_TVoid;
			return r6;
		case 1:
			r6 = (venum*)g$hxsl_Type_TInt;
			return r6;
		case 2:
			r6 = (venum*)g$hxsl_Type_TBool;
			return r6;
		case 3:
			r6 = (venum*)g$hxsl_Type_TFloat;
			return r6;
		case 4:
			r6 = (venum*)g$hxsl_Type_TString;
			return r6;
		case 5:
			r3 = r0->input;
			if( r3 == NULL ) hl_null_access();
			r2 = haxe_io_BytesInput_readByte(r3);
			r8 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r7 = r8->TVECS;
			if( r7 == NULL ) hl_null_access();
			r5 = haxe_ds_IntMap_get(r7,r2);
			r6 = (venum*)r5;
			if( r6 ) goto label$0d3d4b3_3_39;
			r11 = 7;
			r9 = r2 & r11;
			r12 = (hxsl__$VecType)g$hxsl_VecType;
			r13 = 3;
			r11 = r2 >> r13;
			r14 = NULL;
			r5 = Type_createEnumIndex(((hl__BaseType)r12),r11,r14);
			r15 = (venum*)hl_dyn_castp(&r5,&t$_dyn,&t$hxsl_VecType);
			r10 = hl_alloc_enum(&t$hxsl_Type,5);
			((hxsl_Type_TVec*)r10)->p0 = r9;
			((hxsl_Type_TVec*)r10)->p1 = r15;
			r6 = r10;
			r8 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r7 = r8->TVECS;
			if( r7 == NULL ) hl_null_access();
			haxe_ds_IntMap_set(r7,r2,((vdynamic*)r10));
			label$0d3d4b3_3_39:
			return r6;
		case 6:
			r6 = (venum*)g$hxsl_Type_TMat3;
			return r6;
		case 7:
			r6 = (venum*)g$hxsl_Type_TMat4;
			return r6;
		case 8:
			r6 = (venum*)g$hxsl_Type_TMat3x4;
			return r6;
		case 9:
			r3 = r0->input;
			if( r3 == NULL ) hl_null_access();
			r2 = haxe_io_Input_readInt32(((haxe__io__Input)r3));
			r6 = hl_alloc_enum(&t$hxsl_Type,9);
			((hxsl_Type_TBytes*)r6)->p0 = r2;
			return r6;
		case 10:
			r6 = (venum*)g$hxsl_Type_TSampler2D;
			return r6;
		case 11:
			r6 = (venum*)g$hxsl_Type_TSampler2DArray;
			return r6;
		case 12:
			r6 = (venum*)g$hxsl_Type_TSamplerCube;
			return r6;
		case 13:
			r2 = hxsl_Serializer_readVarInt(r0);
			r16 = r0->types;
			if( r16 == NULL ) hl_null_access();
			r11 = r16->length;
			if( ((unsigned)r2) < ((unsigned)r11) ) goto label$0d3d4b3_3_64;
			r6 = NULL;
			goto label$0d3d4b3_3_67;
			label$0d3d4b3_3_64:
			r17 = r16->array;
			r5 = ((vdynamic**)(r17 + 1))[r2];
			r6 = (venum*)r5;
			label$0d3d4b3_3_67:
			if( !r6 ) goto label$0d3d4b3_3_69;
			return r6;
			label$0d3d4b3_3_69:
			r18 = hl_alloc_closure_ptr(&t$fun_23d1dcc,hxsl_Serializer_readVar,r0);
			r19 = &t$vrt_09f4a29;
			r9 = 0;
			r17 = hl_alloc_array(r19,r9);
			r16 = hl_types_ArrayObj_alloc(r17);
			r9 = 0;
			r11 = hxsl_Serializer_readVarInt(r0);
			label$0d3d4b3_3_76:
			if( r9 >= r11 ) goto label$0d3d4b3_3_84;
			++r9;
			if( r16 == NULL ) hl_null_access();
			if( r18 == NULL ) hl_null_access();
			r22 = r18->hasValue ? ((vvirtual* (*)(vdynamic*))r18->fun)((vdynamic*)r18->value) : ((vvirtual* (*)(void))r18->fun)();
			r20 = hl_types_ArrayObj_push(r16,((vdynamic*)r22));
			goto label$0d3d4b3_3_76;
			label$0d3d4b3_3_84:
			r10 = hl_alloc_enum(&t$hxsl_Type,13);
			((hxsl_Type_TStruct*)r10)->p0 = r16;
			r21 = r0->types;
			if( r21 == NULL ) hl_null_access();
			r11 = r21->length;
			if( ((unsigned)r2) < ((unsigned)r11) ) goto label$0d3d4b3_3_90;
			hl_types_ArrayObj___expand(r21,r2);
			label$0d3d4b3_3_90:
			r17 = r21->array;
			((venum**)(r17 + 1))[r2] = r10;
			return r10;
		case 14:
			r16 = NULL;
			r6 = hl_alloc_enum(&t$hxsl_Type,14);
			((hxsl_Type_TFun*)r6)->p0 = r16;
			return r6;
		case 15:
			r6 = hxsl_Serializer_readType(r0);
			r22 = hxsl_Serializer_readVar(r0);
			if( r22 ) goto label$0d3d4b3_3_102;
			r2 = hxsl_Serializer_readVarInt(r0);
			r23 = hl_alloc_enum(&t$hxsl_SizeDecl,0);
			((hxsl_SizeDecl_SConst*)r23)->p0 = r2;
			goto label$0d3d4b3_3_103;
			label$0d3d4b3_3_102:
			r23 = hl_alloc_enum(&t$hxsl_SizeDecl,1);
			((hxsl_SizeDecl_SVar*)r23)->p0 = r22;
			label$0d3d4b3_3_103:
			r10 = hl_alloc_enum(&t$hxsl_Type,15);
			((hxsl_Type_TArray*)r10)->p0 = r6;
			((hxsl_Type_TArray*)r10)->p1 = r23;
			return r10;
		case 16:
			r6 = hxsl_Serializer_readType(r0);
			r22 = hxsl_Serializer_readVar(r0);
			if( r22 ) goto label$0d3d4b3_3_111;
			r2 = hxsl_Serializer_readVarInt(r0);
			r23 = hl_alloc_enum(&t$hxsl_SizeDecl,0);
			((hxsl_SizeDecl_SConst*)r23)->p0 = r2;
			goto label$0d3d4b3_3_112;
			label$0d3d4b3_3_111:
			r23 = hl_alloc_enum(&t$hxsl_SizeDecl,1);
			((hxsl_SizeDecl_SVar*)r23)->p0 = r22;
			label$0d3d4b3_3_112:
			r10 = hl_alloc_enum(&t$hxsl_Type,16);
			((hxsl_Type_TBuffer*)r10)->p0 = r6;
			((hxsl_Type_TBuffer*)r10)->p1 = r23;
			return r10;
		case 17:
			r3 = r0->input;
			if( r3 == NULL ) hl_null_access();
			r2 = haxe_io_BytesInput_readByte(r3);
			r6 = hl_alloc_enum(&t$hxsl_Type,17);
			((hxsl_Type_TChannel*)r6)->p0 = r2;
			return r6;
		case 18:
			r6 = (venum*)g$hxsl_Type_TMat2;
			return r6;
	}
}

String hxsl_Serializer_readString(hxsl__Serializer r0) {
	String r2;
	haxe__io__BytesInput r4;
	venum *r6;
	haxe__io__Bytes r3;
	int r1, r5;
	r1 = hxsl_Serializer_readVarInt(r0);
	r4 = r0->input;
	if( r4 == NULL ) hl_null_access();
	r3 = haxe_io_Input_read(((haxe__io__Input)r4),r1);
	if( r3 == NULL ) hl_null_access();
	r5 = 0;
	r6 = NULL;
	r2 = haxe_io_Bytes_getString(r3,r5,r1,r6);
	return r2;
}

venum* hxsl_Serializer_readConst(hxsl__Serializer r0) {
	String r3;
	haxe__io__BytesInput r2;
	venum *r4;
	bool r5;
	double r7;
	int r1, r6;
	r2 = r0->input;
	if( r2 == NULL ) hl_null_access();
	r1 = haxe_io_BytesInput_readByte(r2);
	switch(r1) {
		default:
			r3 = (String)s$assert;
			hl_throw((vdynamic*)r3);
		case 0:
			r4 = (venum*)g$hxsl_Const_CNull;
			return r4;
		case 1:
			r2 = r0->input;
			if( r2 == NULL ) hl_null_access();
			r1 = haxe_io_BytesInput_readByte(r2);
			r6 = 0;
			if( r1 != r6 ) goto label$0d3d4b3_5_15;
			r5 = false;
			goto label$0d3d4b3_5_16;
			label$0d3d4b3_5_15:
			r5 = true;
			label$0d3d4b3_5_16:
			r4 = hl_alloc_enum(&t$hxsl_Const,1);
			((hxsl_Const_CBool*)r4)->p0 = r5;
			return r4;
		case 2:
			r2 = r0->input;
			if( r2 == NULL ) hl_null_access();
			r1 = haxe_io_Input_readInt32(((haxe__io__Input)r2));
			r4 = hl_alloc_enum(&t$hxsl_Const,2);
			((hxsl_Const_CInt*)r4)->p0 = r1;
			return r4;
		case 3:
			r2 = r0->input;
			if( r2 == NULL ) hl_null_access();
			r7 = haxe_io_Input_readDouble(((haxe__io__Input)r2));
			r4 = hl_alloc_enum(&t$hxsl_Const,3);
			((hxsl_Const_CFloat*)r4)->p0 = r7;
			return r4;
		case 4:
			r3 = hxsl_Serializer_readString(r0);
			r4 = hl_alloc_enum(&t$hxsl_Const,4);
			((hxsl_Const_CString*)r4)->p0 = r3;
			return r4;
	}
}

vvirtual* hxsl_Serializer_readExpr(hxsl__Serializer r0) {
	String r9;
	hl__types__ArrayObj r13, r21, r27;
	vvirtual *r7, *r12, *r23, *r31, *r32, *r36;
	haxe__io__BytesInput r4;
	hl_type *r18;
	venum *r10, *r11, *r15, *r22, *r24, *r30, *r35;
	bool r33;
	haxe__ds__IntMap r25;
	hxsl__Serializer r1;
	vclosure *r17, *r34;
	hxsl__$Serializer r14;
	vdynamic *r8;
	varray *r16;
	int r3, r5, r6, r19, r20, r26, r28, r29;
	r1 = r0;
	r4 = r0->input;
	if( r4 == NULL ) hl_null_access();
	r3 = haxe_io_BytesInput_readByte(r4);
	r5 = r3;
	--r3;
	r6 = 0;
	if( r5 != r6 ) goto label$0d3d4b3_6_10;
	r7 = NULL;
	return r7;
	label$0d3d4b3_6_10:
	switch(r3) {
		default:
			r9 = (String)s$assert;
			hl_throw((vdynamic*)r9);
		case 0:
			r11 = hxsl_Serializer_readConst(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,0);
			((hxsl_TExprDef_TConst*)r10)->p0 = r11;
			goto label$0d3d4b3_6_282;
		case 1:
			r12 = hxsl_Serializer_readVar(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,1);
			((hxsl_TExprDef_TVar*)r10)->p0 = r12;
			goto label$0d3d4b3_6_282;
		case 2:
			r14 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r13 = r14->TGLOBALS;
			if( r13 == NULL ) hl_null_access();
			r4 = r0->input;
			if( r4 == NULL ) hl_null_access();
			r5 = haxe_io_BytesInput_readByte(r4);
			r6 = r13->length;
			if( ((unsigned)r5) < ((unsigned)r6) ) goto label$0d3d4b3_6_29;
			r15 = NULL;
			goto label$0d3d4b3_6_32;
			label$0d3d4b3_6_29:
			r16 = r13->array;
			r8 = ((vdynamic**)(r16 + 1))[r5];
			r15 = (venum*)r8;
			label$0d3d4b3_6_32:
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,2);
			((hxsl_TExprDef_TGlobal*)r10)->p0 = r15;
			goto label$0d3d4b3_6_282;
		case 3:
			r7 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,3);
			((hxsl_TExprDef_TParenthesis*)r10)->p0 = r7;
			goto label$0d3d4b3_6_282;
		case 4:
			r17 = hl_alloc_closure_ptr(&t$fun_101847d,hxsl_Serializer_readExpr,r0);
			r18 = &t$vrt_6e3ace9;
			r5 = 0;
			r16 = hl_alloc_array(r18,r5);
			r13 = hl_types_ArrayObj_alloc(r16);
			r5 = 0;
			r6 = hxsl_Serializer_readVarInt(r0);
			label$0d3d4b3_6_44:
			if( r5 >= r6 ) goto label$0d3d4b3_6_52;
			++r5;
			if( r13 == NULL ) hl_null_access();
			if( r17 == NULL ) hl_null_access();
			r7 = r17->hasValue ? ((vvirtual* (*)(vdynamic*))r17->fun)((vdynamic*)r17->value) : ((vvirtual* (*)(void))r17->fun)();
			r20 = hl_types_ArrayObj_push(r13,((vdynamic*)r7));
			goto label$0d3d4b3_6_44;
			label$0d3d4b3_6_52:
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,4);
			((hxsl_TExprDef_TBlock*)r10)->p0 = r13;
			goto label$0d3d4b3_6_282;
		case 5:
			r4 = r0->input;
			if( r4 == NULL ) hl_null_access();
			r5 = haxe_io_BytesInput_readByte(r4);
			r19 = 128;
			if( r5 < r19 ) goto label$0d3d4b3_6_73;
			r14 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r13 = r14->BOPS;
			if( r13 == NULL ) hl_null_access();
			r19 = 127;
			r6 = r5 & r19;
			r19 = r13->length;
			if( ((unsigned)r6) < ((unsigned)r19) ) goto label$0d3d4b3_6_68;
			r22 = NULL;
			goto label$0d3d4b3_6_71;
			label$0d3d4b3_6_68:
			r16 = r13->array;
			r8 = ((vdynamic**)(r16 + 1))[r6];
			r22 = (venum*)r8;
			label$0d3d4b3_6_71:
			{ venum *tmp;
			tmp = hl_alloc_enum(&t$haxe_macro_Binop,20);
			((haxe_macro_Binop_OpAssignOp*)tmp)->p0 = r22;
			r22 = tmp; };
			goto label$0d3d4b3_6_83;
			label$0d3d4b3_6_73:
			r14 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r13 = r14->BOPS;
			if( r13 == NULL ) hl_null_access();
			r19 = r13->length;
			if( ((unsigned)r5) < ((unsigned)r19) ) goto label$0d3d4b3_6_80;
			r22 = NULL;
			goto label$0d3d4b3_6_83;
			label$0d3d4b3_6_80:
			r16 = r13->array;
			r8 = ((vdynamic**)(r16 + 1))[r5];
			r22 = (venum*)r8;
			label$0d3d4b3_6_83:
			r7 = hxsl_Serializer_readExpr(r0);
			r23 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,5);
			((hxsl_TExprDef_TBinop*)r10)->p0 = r22;
			((hxsl_TExprDef_TBinop*)r10)->p1 = r7;
			((hxsl_TExprDef_TBinop*)r10)->p2 = r23;
			goto label$0d3d4b3_6_282;
		case 6:
			r14 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r13 = r14->UNOPS;
			if( r13 == NULL ) hl_null_access();
			r4 = r0->input;
			if( r4 == NULL ) hl_null_access();
			r5 = haxe_io_BytesInput_readByte(r4);
			r6 = r13->length;
			if( ((unsigned)r5) < ((unsigned)r6) ) goto label$0d3d4b3_6_97;
			r24 = NULL;
			goto label$0d3d4b3_6_100;
			label$0d3d4b3_6_97:
			r16 = r13->array;
			r8 = ((vdynamic**)(r16 + 1))[r5];
			r24 = (venum*)r8;
			label$0d3d4b3_6_100:
			r7 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,6);
			((hxsl_TExprDef_TUnop*)r10)->p0 = r24;
			((hxsl_TExprDef_TUnop*)r10)->p1 = r7;
			goto label$0d3d4b3_6_282;
		case 7:
			r12 = hxsl_Serializer_readVar(r0);
			r7 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,7);
			((hxsl_TExprDef_TVarDecl*)r10)->p0 = r12;
			((hxsl_TExprDef_TVarDecl*)r10)->p1 = r7;
			goto label$0d3d4b3_6_282;
		case 8:
			r7 = hxsl_Serializer_readExpr(r0);
			r17 = hl_alloc_closure_ptr(&t$fun_101847d,hxsl_Serializer_readExpr,r0);
			r18 = &t$vrt_6e3ace9;
			r5 = 0;
			r16 = hl_alloc_array(r18,r5);
			r13 = hl_types_ArrayObj_alloc(r16);
			r5 = 0;
			r6 = hxsl_Serializer_readVarInt(r0);
			label$0d3d4b3_6_115:
			if( r5 >= r6 ) goto label$0d3d4b3_6_123;
			++r5;
			if( r13 == NULL ) hl_null_access();
			if( r17 == NULL ) hl_null_access();
			r23 = r17->hasValue ? ((vvirtual* (*)(vdynamic*))r17->fun)((vdynamic*)r17->value) : ((vvirtual* (*)(void))r17->fun)();
			r20 = hl_types_ArrayObj_push(r13,((vdynamic*)r23));
			goto label$0d3d4b3_6_115;
			label$0d3d4b3_6_123:
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,8);
			((hxsl_TExprDef_TCall*)r10)->p0 = r7;
			((hxsl_TExprDef_TCall*)r10)->p1 = r13;
			goto label$0d3d4b3_6_282;
		case 9:
			r7 = hxsl_Serializer_readExpr(r0);
			r4 = r0->input;
			if( r4 == NULL ) hl_null_access();
			r5 = haxe_io_Input_readUInt16(((haxe__io__Input)r4));
			r14 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r25 = r14->TSWIZ;
			if( r25 == NULL ) hl_null_access();
			r8 = haxe_ds_IntMap_get(r25,r5);
			r13 = (hl__types__ArrayObj)hl_dyn_castp(&r8,&t$_dyn,&t$hl_types_ArrayObj);
			if( r13 ) goto label$0d3d4b3_6_173;
			r18 = &t$hxsl_Component;
			r6 = 0;
			r16 = hl_alloc_array(r18,r6);
			r21 = hl_types_ArrayObj_alloc(r16);
			r6 = 0;
			r20 = 3;
			r19 = r5 & r20;
			r20 = 1;
			r19 = r19 + r20;
			label$0d3d4b3_6_144:
			if( r6 >= r19 ) goto label$0d3d4b3_6_168;
			r20 = r6;
			++r6;
			if( r21 == NULL ) hl_null_access();
			r14 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r27 = r14->REGS;
			if( r27 == NULL ) hl_null_access();
			r29 = 2;
			r28 = r20 * r29;
			r29 = 2;
			r28 = r28 + r29;
			r26 = r5 >> r28;
			r28 = 3;
			r26 = r26 & r28;
			r28 = r27->length;
			if( ((unsigned)r26) < ((unsigned)r28) ) goto label$0d3d4b3_6_163;
			r30 = NULL;
			goto label$0d3d4b3_6_166;
			label$0d3d4b3_6_163:
			r16 = r27->array;
			r8 = ((vdynamic**)(r16 + 1))[r26];
			r30 = (venum*)r8;
			label$0d3d4b3_6_166:
			r26 = hl_types_ArrayObj_push(r21,((vdynamic*)r30));
			goto label$0d3d4b3_6_144;
			label$0d3d4b3_6_168:
			r13 = r21;
			r14 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r25 = r14->TSWIZ;
			if( r25 == NULL ) hl_null_access();
			haxe_ds_IntMap_set(r25,r5,((vdynamic*)r21));
			label$0d3d4b3_6_173:
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,9);
			((hxsl_TExprDef_TSwiz*)r10)->p0 = r7;
			((hxsl_TExprDef_TSwiz*)r10)->p1 = r13;
			goto label$0d3d4b3_6_282;
		case 10:
			r7 = hxsl_Serializer_readExpr(r0);
			r23 = hxsl_Serializer_readExpr(r0);
			r31 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,10);
			((hxsl_TExprDef_TIf*)r10)->p0 = r7;
			((hxsl_TExprDef_TIf*)r10)->p1 = r23;
			((hxsl_TExprDef_TIf*)r10)->p2 = r31;
			goto label$0d3d4b3_6_282;
		case 11:
			r10 = (venum*)g$hxsl_TExprDef_TDiscard;
			goto label$0d3d4b3_6_282;
		case 12:
			r7 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,12);
			((hxsl_TExprDef_TReturn*)r10)->p0 = r7;
			goto label$0d3d4b3_6_282;
		case 13:
			r12 = hxsl_Serializer_readVar(r0);
			r7 = hxsl_Serializer_readExpr(r0);
			r23 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,13);
			((hxsl_TExprDef_TFor*)r10)->p0 = r12;
			((hxsl_TExprDef_TFor*)r10)->p1 = r7;
			((hxsl_TExprDef_TFor*)r10)->p2 = r23;
			goto label$0d3d4b3_6_282;
		case 14:
			r10 = (venum*)g$hxsl_TExprDef_TContinue;
			goto label$0d3d4b3_6_282;
		case 15:
			r10 = (venum*)g$hxsl_TExprDef_TBreak;
			goto label$0d3d4b3_6_282;
		case 16:
			r7 = hxsl_Serializer_readExpr(r0);
			r23 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,16);
			((hxsl_TExprDef_TArray*)r10)->p0 = r7;
			((hxsl_TExprDef_TArray*)r10)->p1 = r23;
			goto label$0d3d4b3_6_282;
		case 17:
			r17 = hl_alloc_closure_ptr(&t$fun_101847d,hxsl_Serializer_readExpr,r0);
			r18 = &t$vrt_6e3ace9;
			r5 = 0;
			r16 = hl_alloc_array(r18,r5);
			r13 = hl_types_ArrayObj_alloc(r16);
			r5 = 0;
			r6 = hxsl_Serializer_readVarInt(r0);
			label$0d3d4b3_6_205:
			if( r5 >= r6 ) goto label$0d3d4b3_6_213;
			++r5;
			if( r13 == NULL ) hl_null_access();
			if( r17 == NULL ) hl_null_access();
			r7 = r17->hasValue ? ((vvirtual* (*)(vdynamic*))r17->fun)((vdynamic*)r17->value) : ((vvirtual* (*)(void))r17->fun)();
			r20 = hl_types_ArrayObj_push(r13,((vdynamic*)r7));
			goto label$0d3d4b3_6_205;
			label$0d3d4b3_6_213:
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,17);
			((hxsl_TExprDef_TArrayDecl*)r10)->p0 = r13;
			goto label$0d3d4b3_6_282;
		case 18:
			r7 = hxsl_Serializer_readExpr(r0);
			r18 = &t$vrt_15384e6;
			r5 = 0;
			r16 = hl_alloc_array(r18,r5);
			r13 = hl_types_ArrayObj_alloc(r16);
			r5 = 0;
			r6 = hxsl_Serializer_readVarInt(r0);
			label$0d3d4b3_6_222:
			if( r5 >= r6 ) goto label$0d3d4b3_6_249;
			++r5;
			if( r1 == NULL ) hl_null_access();
			r17 = hl_alloc_closure_ptr(&t$fun_101847d,hxsl_Serializer_readExpr,r1);
			r18 = &t$vrt_6e3ace9;
			r20 = 0;
			r16 = hl_alloc_array(r18,r20);
			r21 = hl_types_ArrayObj_alloc(r16);
			r20 = 0;
			r26 = hxsl_Serializer_readVarInt(r1);
			label$0d3d4b3_6_233:
			if( r20 >= r26 ) goto label$0d3d4b3_6_241;
			++r20;
			if( r21 == NULL ) hl_null_access();
			if( r17 == NULL ) hl_null_access();
			r23 = r17->hasValue ? ((vvirtual* (*)(vdynamic*))r17->fun)((vdynamic*)r17->value) : ((vvirtual* (*)(void))r17->fun)();
			r29 = hl_types_ArrayObj_push(r21,((vdynamic*)r23));
			goto label$0d3d4b3_6_233;
			label$0d3d4b3_6_241:
			if( r13 == NULL ) hl_null_access();
			r32 = hl_alloc_virtual(&t$vrt_15384e6);
			if( hl_vfields(r32)[1] ) *(hl__types__ArrayObj*)(hl_vfields(r32)[1]) = (hl__types__ArrayObj)r21; else hl_dyn_setp(r32->value,263652588/*values*/,&t$hl_types_ArrayObj,r21);
			if( r1 == NULL ) hl_null_access();
			r23 = hxsl_Serializer_readExpr(r1);
			if( hl_vfields(r32)[0] ) *(vvirtual**)(hl_vfields(r32)[0]) = (vvirtual*)r23; else hl_dyn_setp(r32->value,52297279/*expr*/,&t$vrt_6e3ace9,r23);
			r20 = hl_types_ArrayObj_push(r13,((vdynamic*)r32));
			goto label$0d3d4b3_6_222;
			label$0d3d4b3_6_249:
			r31 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,18);
			((hxsl_TExprDef_TSwitch*)r10)->p0 = r7;
			((hxsl_TExprDef_TSwitch*)r10)->p1 = r13;
			((hxsl_TExprDef_TSwitch*)r10)->p2 = r31;
			goto label$0d3d4b3_6_282;
		case 19:
			r7 = hxsl_Serializer_readExpr(r0);
			r23 = hxsl_Serializer_readExpr(r0);
			r4 = r0->input;
			if( r4 == NULL ) hl_null_access();
			r5 = haxe_io_BytesInput_readByte(r4);
			r6 = 0;
			if( r5 != r6 ) goto label$0d3d4b3_6_261;
			r33 = false;
			goto label$0d3d4b3_6_262;
			label$0d3d4b3_6_261:
			r33 = true;
			label$0d3d4b3_6_262:
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,19);
			((hxsl_TExprDef_TWhile*)r10)->p0 = r7;
			((hxsl_TExprDef_TWhile*)r10)->p1 = r23;
			((hxsl_TExprDef_TWhile*)r10)->p2 = r33;
			goto label$0d3d4b3_6_282;
		case 20:
			r9 = hxsl_Serializer_readString(r0);
			r34 = hl_alloc_closure_ptr(&t$fun_48dadd5,hxsl_Serializer_readConst,r0);
			r18 = &t$hxsl_Const;
			r5 = 0;
			r16 = hl_alloc_array(r18,r5);
			r13 = hl_types_ArrayObj_alloc(r16);
			r5 = 0;
			r6 = hxsl_Serializer_readVarInt(r0);
			label$0d3d4b3_6_272:
			if( r5 >= r6 ) goto label$0d3d4b3_6_280;
			++r5;
			if( r13 == NULL ) hl_null_access();
			if( r34 == NULL ) hl_null_access();
			r11 = r34->hasValue ? ((venum* (*)(vdynamic*))r34->fun)((vdynamic*)r34->value) : ((venum* (*)(void))r34->fun)();
			r20 = hl_types_ArrayObj_push(r13,((vdynamic*)r11));
			goto label$0d3d4b3_6_272;
			label$0d3d4b3_6_280:
			r7 = hxsl_Serializer_readExpr(r0);
			r10 = hl_alloc_enum(&t$hxsl_TExprDef,20);
			((hxsl_TExprDef_TMeta*)r10)->p0 = r9;
			((hxsl_TExprDef_TMeta*)r10)->p1 = r13;
			((hxsl_TExprDef_TMeta*)r10)->p2 = r7;
	}
	label$0d3d4b3_6_282:
	r7 = hl_alloc_virtual(&t$vrt_6e3ace9);
	if( hl_vfields(r7)[0] ) *(venum**)(hl_vfields(r7)[0]) = (venum*)r10; else hl_dyn_setp(r7->value,101/*e*/,&t$hxsl_TExprDef,r10);
	r35 = hxsl_Serializer_readType(r0);
	if( hl_vfields(r7)[2] ) *(venum**)(hl_vfields(r7)[2]) = (venum*)r35; else hl_dyn_setp(r7->value,116/*t*/,&t$hxsl_Type,r35);
	r36 = NULL;
	if( hl_vfields(r7)[1] ) *(vvirtual**)(hl_vfields(r7)[1]) = (vvirtual*)r36; else hl_dyn_setp(r7->value,112/*p*/,&t$vrt_379f5a4,r36);
	return r7;
}

vvirtual* hxsl_Serializer_readVar(hxsl__Serializer r0) {
	String r10;
	vdynobj *r9;
	haxe__io__BytesInput r15;
	hl__types__ArrayObj r13;
	vvirtual *r5, *r8, *r17;
	hl_type *r19;
	venum *r11, *r12, *r22, *r26;
	haxe__ds__IntMap r7;
	double r27, r28;
	hxsl__$Serializer r14;
	vdynamic *r6, *r23;
	varray *r16;
	int r1, r3, r4, r18, r20, r21, r24, r25;
	r1 = hxsl_Serializer_readVarInt(r0);
	r4 = 0;
	if( r1 != r4 ) goto label$0d3d4b3_7_5;
	r5 = NULL;
	return r5;
	label$0d3d4b3_7_5:
	r7 = r0->varMap;
	if( r7 == NULL ) hl_null_access();
	r6 = haxe_ds_IntMap_get(r7,r1);
	r5 = hl_to_virtual(&t$vrt_09f4a29,(vdynamic*)r6);
	if( !r5 ) goto label$0d3d4b3_7_11;
	return r5;
	label$0d3d4b3_7_11:
	r9 = hl_alloc_dynobj();
	r3 = hxsl_Tools_allocVarId();
	hl_dyn_seti((vdynamic*)r9,23515/*id*/,&t$_i32,r3);
	r10 = hxsl_Serializer_readString(r0);
	hl_dyn_setp((vdynamic*)r9,150958933/*name*/,&t$String,r10);
	r11 = NULL;
	hl_dyn_setp((vdynamic*)r9,218690500/*type*/,&t$hxsl_Type,r11);
	r12 = NULL;
	hl_dyn_setp((vdynamic*)r9,118088286/*kind*/,&t$hxsl_VarKind,r12);
	r8 = hl_to_virtual(&t$vrt_09f4a29,(vdynamic*)r9);
	r5 = r8;
	r7 = r0->varMap;
	if( r7 == NULL ) hl_null_access();
	haxe_ds_IntMap_set(r7,r1,((vdynamic*)r8));
	r11 = hxsl_Serializer_readType(r0);
	if( hl_vfields(r8)[5] ) *(venum**)(hl_vfields(r8)[5]) = (venum*)r11; else hl_dyn_setp(r8->value,218690500/*type*/,&t$hxsl_Type,r11);
	r14 = (hxsl__$Serializer)g$_hxsl_Serializer;
	r13 = r14->VKINDS;
	if( r13 == NULL ) hl_null_access();
	r15 = r0->input;
	if( r15 == NULL ) hl_null_access();
	r3 = haxe_io_BytesInput_readByte(r15);
	r4 = r13->length;
	if( ((unsigned)r3) < ((unsigned)r4) ) goto label$0d3d4b3_7_37;
	r12 = NULL;
	goto label$0d3d4b3_7_40;
	label$0d3d4b3_7_37:
	r16 = r13->array;
	r6 = ((vdynamic**)(r16 + 1))[r3];
	r12 = (venum*)r6;
	label$0d3d4b3_7_40:
	if( hl_vfields(r8)[1] ) *(venum**)(hl_vfields(r8)[1]) = (venum*)r12; else hl_dyn_setp(r8->value,118088286/*kind*/,&t$hxsl_VarKind,r12);
	r17 = hxsl_Serializer_readVar(r0);
	if( hl_vfields(r8)[3] ) *(vvirtual**)(hl_vfields(r8)[3]) = (vvirtual*)r17; else hl_dyn_setp(r8->value,-310508246/*parent*/,&t$vrt_09f4a29,r17);
	r15 = r0->input;
	if( r15 == NULL ) hl_null_access();
	r3 = haxe_io_BytesInput_readByte(r15);
	r18 = 0;
	if( r18 >= r3 ) goto label$0d3d4b3_7_128;
	r19 = &t$hxsl_VarQualifier;
	r4 = 0;
	r16 = hl_alloc_array(r19,r4);
	r13 = hl_types_ArrayObj_alloc(r16);
	if( hl_vfields(r8)[4] ) *(hl__types__ArrayObj*)(hl_vfields(r8)[4]) = (hl__types__ArrayObj)r13; else hl_dyn_setp(r8->value,476822680/*qualifiers*/,&t$hl_types_ArrayObj,r13);
	r4 = 0;
	r18 = r3;
	label$0d3d4b3_7_55:
	if( r4 >= r18 ) goto label$0d3d4b3_7_128;
	++r4;
	r15 = r0->input;
	if( r15 == NULL ) hl_null_access();
	r20 = haxe_io_BytesInput_readByte(r15);
	switch(r20) {
		default:
			r10 = (String)s$assert;
			hl_throw((vdynamic*)r10);
		case 0:
			r15 = r0->input;
			if( r15 == NULL ) hl_null_access();
			r21 = haxe_io_Input_readInt32(((haxe__io__Input)r15));
			r25 = 0;
			if( r21 != r25 ) goto label$0d3d4b3_7_71;
			r23 = NULL;
			goto label$0d3d4b3_7_72;
			label$0d3d4b3_7_71:
			r23 = hl_alloc_dynamic(&t$_i32);
			r23->v.i = r21;
			label$0d3d4b3_7_72:
			r22 = hl_alloc_enum(&t$hxsl_VarQualifier,0);
			((hxsl_VarQualifier_Const*)r22)->p0 = r23;
			goto label$0d3d4b3_7_123;
		case 1:
			r22 = (venum*)g$hxsl_VarQualifier_Private;
			goto label$0d3d4b3_7_123;
		case 2:
			r22 = (venum*)g$hxsl_VarQualifier_Nullable;
			goto label$0d3d4b3_7_123;
		case 3:
			r22 = (venum*)g$hxsl_VarQualifier_PerObject;
			goto label$0d3d4b3_7_123;
		case 4:
			r10 = hxsl_Serializer_readString(r0);
			r22 = hl_alloc_enum(&t$hxsl_VarQualifier,4);
			((hxsl_VarQualifier_Name*)r22)->p0 = r10;
			goto label$0d3d4b3_7_123;
		case 5:
			r22 = (venum*)g$hxsl_VarQualifier_Shared;
			goto label$0d3d4b3_7_123;
		case 6:
			r14 = (hxsl__$Serializer)g$_hxsl_Serializer;
			r13 = r14->PRECS;
			if( r13 == NULL ) hl_null_access();
			r15 = r0->input;
			if( r15 == NULL ) hl_null_access();
			r21 = haxe_io_BytesInput_readByte(r15);
			r24 = r13->length;
			if( ((unsigned)r21) < ((unsigned)r24) ) goto label$0d3d4b3_7_95;
			r26 = NULL;
			goto label$0d3d4b3_7_98;
			label$0d3d4b3_7_95:
			r16 = r13->array;
			r6 = ((vdynamic**)(r16 + 1))[r21];
			r26 = (venum*)r6;
			label$0d3d4b3_7_98:
			r22 = hl_alloc_enum(&t$hxsl_VarQualifier,6);
			((hxsl_VarQualifier_Precision*)r22)->p0 = r26;
			goto label$0d3d4b3_7_123;
		case 7:
			r15 = r0->input;
			if( r15 == NULL ) hl_null_access();
			r27 = haxe_io_Input_readDouble(((haxe__io__Input)r15));
			r15 = r0->input;
			if( r15 == NULL ) hl_null_access();
			r28 = haxe_io_Input_readDouble(((haxe__io__Input)r15));
			r22 = hl_alloc_enum(&t$hxsl_VarQualifier,7);
			((hxsl_VarQualifier_Range*)r22)->p0 = r27;
			((hxsl_VarQualifier_Range*)r22)->p1 = r28;
			goto label$0d3d4b3_7_123;
		case 8:
			r22 = (venum*)g$hxsl_VarQualifier_Ignore;
			goto label$0d3d4b3_7_123;
		case 9:
			r15 = r0->input;
			if( r15 == NULL ) hl_null_access();
			r21 = haxe_io_Input_readInt32(((haxe__io__Input)r15));
			r22 = hl_alloc_enum(&t$hxsl_VarQualifier,9);
			((hxsl_VarQualifier_PerInstance*)r22)->p0 = r21;
			goto label$0d3d4b3_7_123;
		case 10:
			r10 = hxsl_Serializer_readString(r0);
			r22 = hl_alloc_enum(&t$hxsl_VarQualifier,10);
			((hxsl_VarQualifier_Doc*)r22)->p0 = r10;
			goto label$0d3d4b3_7_123;
		case 11:
			r10 = hxsl_Serializer_readString(r0);
			r22 = hl_alloc_enum(&t$hxsl_VarQualifier,11);
			((hxsl_VarQualifier_Borrow*)r22)->p0 = r10;
			goto label$0d3d4b3_7_123;
		case 12:
			r10 = hxsl_Serializer_readString(r0);
			r22 = hl_alloc_enum(&t$hxsl_VarQualifier,12);
			((hxsl_VarQualifier_Sampler*)r22)->p0 = r10;
	}
	label$0d3d4b3_7_123:
	if( r5 == NULL ) hl_null_access();
	r13 = hl_vfields(r5)[4] ? (*(hl__types__ArrayObj*)(hl_vfields(r5)[4])) : (hl__types__ArrayObj)hl_dyn_getp(r5->value,476822680/*qualifiers*/,&t$hl_types_ArrayObj);
	if( r13 == NULL ) hl_null_access();
	r21 = hl_types_ArrayObj_push(r13,((vdynamic*)r22));
	goto label$0d3d4b3_7_55;
	label$0d3d4b3_7_128:
	return r5;
}

vvirtual* hxsl_Serializer_readFun(hxsl__Serializer r0) {
	vvirtual *r9, *r13, *r14, *r16;
	haxe__io__BytesInput r4;
	hl__types__ArrayObj r1;
	hl_type *r11;
	venum *r6, *r15;
	vclosure *r10;
	vdynamic *r7;
	hxsl__$Serializer r2;
	varray *r8;
	int r3, r5, r12;
	r2 = (hxsl__$Serializer)g$_hxsl_Serializer;
	r1 = r2->FKIND;
	if( r1 == NULL ) hl_null_access();
	r4 = r0->input;
	if( r4 == NULL ) hl_null_access();
	r3 = haxe_io_BytesInput_readByte(r4);
	r5 = r1->length;
	if( ((unsigned)r3) < ((unsigned)r5) ) goto label$0d3d4b3_8_10;
	r6 = NULL;
	goto label$0d3d4b3_8_13;
	label$0d3d4b3_8_10:
	r8 = r1->array;
	r7 = ((vdynamic**)(r8 + 1))[r3];
	r6 = (venum*)r7;
	label$0d3d4b3_8_13:
	r9 = hxsl_Serializer_readVar(r0);
	r10 = hl_alloc_closure_ptr(&t$fun_23d1dcc,hxsl_Serializer_readVar,r0);
	r11 = &t$vrt_09f4a29;
	r3 = 0;
	r8 = hl_alloc_array(r11,r3);
	r1 = hl_types_ArrayObj_alloc(r8);
	r3 = 0;
	r5 = hxsl_Serializer_readVarInt(r0);
	label$0d3d4b3_8_21:
	if( r3 >= r5 ) goto label$0d3d4b3_8_29;
	++r3;
	if( r1 == NULL ) hl_null_access();
	if( r10 == NULL ) hl_null_access();
	r13 = r10->hasValue ? ((vvirtual* (*)(vdynamic*))r10->fun)((vdynamic*)r10->value) : ((vvirtual* (*)(void))r10->fun)();
	r12 = hl_types_ArrayObj_push(r1,((vdynamic*)r13));
	goto label$0d3d4b3_8_21;
	label$0d3d4b3_8_29:
	r14 = hl_alloc_virtual(&t$vrt_ab557b2);
	if( hl_vfields(r14)[2] ) *(venum**)(hl_vfields(r14)[2]) = (venum*)r6; else hl_dyn_setp(r14->value,118088286/*kind*/,&t$hxsl_FunctionKind,r6);
	if( hl_vfields(r14)[3] ) *(vvirtual**)(hl_vfields(r14)[3]) = (vvirtual*)r9; else hl_dyn_setp(r14->value,5691731/*ref*/,&t$vrt_09f4a29,r9);
	if( hl_vfields(r14)[0] ) *(hl__types__ArrayObj*)(hl_vfields(r14)[0]) = (hl__types__ArrayObj)r1; else hl_dyn_setp(r14->value,7638631/*args*/,&t$hl_types_ArrayObj,r1);
	r15 = hxsl_Serializer_readType(r0);
	if( hl_vfields(r14)[4] ) *(venum**)(hl_vfields(r14)[4]) = (venum*)r15; else hl_dyn_setp(r14->value,5691745/*ret*/,&t$hxsl_Type,r15);
	r16 = hxsl_Serializer_readExpr(r0);
	if( hl_vfields(r14)[1] ) *(vvirtual**)(hl_vfields(r14)[1]) = (vvirtual*)r16; else hl_dyn_setp(r14->value,52297279/*expr*/,&t$vrt_6e3ace9,r16);
	return r14;
}

vvirtual* hxsl_Serializer_unserialize(hxsl__Serializer r0,String r1) {
	bool *r6;
	String r4;
	vvirtual *r21, *r24, *r25;
	hl__types__ArrayObj r15, r20, r23;
	haxe__io__BytesInput r2;
	hl_type *r17;
	bool r5;
	haxe__io__Bytes r3;
	haxe__ds__IntMap r14;
	vclosure *r18, *r22;
	hxsl__$Serializer r12;
	vdynamic *r7, *r8;
	varray *r16;
	int r10, r11, r13, r19;
	r2 = (haxe__io__BytesInput)hl_alloc_obj(&t$haxe_io_BytesInput);
	r5 = false;
	r6 = &r5;
	r3 = haxe_crypto_Base64_decode(r1,r6);
	r7 = NULL;
	r8 = NULL;
	haxe_io_BytesInput_new(r2,r3,r7,r8);
	r0->input = r2;
	r2 = r0->input;
	if( r2 == NULL ) hl_null_access();
	r10 = haxe_io_BytesInput_readByte(r2);
	r12 = (hxsl__$Serializer)g$_hxsl_Serializer;
	r11 = r12->SIGN;
	r13 = 255;
	r11 = r11 & r13;
	if( r10 != r11 ) goto label$0d3d4b3_9_36;
	r2 = r0->input;
	if( r2 == NULL ) hl_null_access();
	r10 = haxe_io_BytesInput_readByte(r2);
	r12 = (hxsl__$Serializer)g$_hxsl_Serializer;
	r11 = r12->SIGN;
	r13 = 8;
	r11 = r11 >> r13;
	r13 = 255;
	r11 = r11 & r13;
	if( r10 != r11 ) goto label$0d3d4b3_9_36;
	r2 = r0->input;
	if( r2 == NULL ) hl_null_access();
	r10 = haxe_io_BytesInput_readByte(r2);
	r12 = (hxsl__$Serializer)g$_hxsl_Serializer;
	r11 = r12->SIGN;
	r13 = 16;
	r11 = r11 >> r13;
	r13 = 255;
	r11 = r11 & r13;
	if( r10 == r11 ) goto label$0d3d4b3_9_38;
	label$0d3d4b3_9_36:
	r4 = (String)s$Invalid_HXSL_data;
	hl_throw((vdynamic*)r4);
	label$0d3d4b3_9_38:
	r14 = (haxe__ds__IntMap)hl_alloc_obj(&t$haxe_ds_IntMap);
	haxe_ds_IntMap_new(r14);
	r0->varMap = r14;
	r17 = &t$hxsl_Type;
	r10 = 0;
	r16 = hl_alloc_array(r17,r10);
	r15 = hl_types_ArrayObj_alloc(r16);
	r0->types = r15;
	r4 = hxsl_Serializer_readString(r0);
	r18 = hl_alloc_closure_ptr(&t$fun_23d1dcc,hxsl_Serializer_readVar,r0);
	r17 = &t$vrt_09f4a29;
	r10 = 0;
	r16 = hl_alloc_array(r17,r10);
	r15 = hl_types_ArrayObj_alloc(r16);
	r10 = 0;
	r11 = hxsl_Serializer_readVarInt(r0);
	label$0d3d4b3_9_54:
	if( r10 >= r11 ) goto label$0d3d4b3_9_62;
	++r10;
	if( r15 == NULL ) hl_null_access();
	if( r18 == NULL ) hl_null_access();
	r21 = r18->hasValue ? ((vvirtual* (*)(vdynamic*))r18->fun)((vdynamic*)r18->value) : ((vvirtual* (*)(void))r18->fun)();
	r19 = hl_types_ArrayObj_push(r15,((vdynamic*)r21));
	goto label$0d3d4b3_9_54;
	label$0d3d4b3_9_62:
	r20 = r15;
	r22 = hl_alloc_closure_ptr(&t$fun_b797f9a,hxsl_Serializer_readFun,r0);
	r17 = &t$vrt_ab557b2;
	r10 = 0;
	r16 = hl_alloc_array(r17,r10);
	r23 = hl_types_ArrayObj_alloc(r16);
	r10 = 0;
	r11 = hxsl_Serializer_readVarInt(r0);
	label$0d3d4b3_9_70:
	if( r10 >= r11 ) goto label$0d3d4b3_9_78;
	++r10;
	if( r23 == NULL ) hl_null_access();
	if( r22 == NULL ) hl_null_access();
	r24 = r22->hasValue ? ((vvirtual* (*)(vdynamic*))r22->fun)((vdynamic*)r22->value) : ((vvirtual* (*)(void))r22->fun)();
	r19 = hl_types_ArrayObj_push(r23,((vdynamic*)r24));
	goto label$0d3d4b3_9_70;
	label$0d3d4b3_9_78:
	r25 = hl_alloc_virtual(&t$vrt_f479cb2);
	if( hl_vfields(r25)[1] ) *(String*)(hl_vfields(r25)[1]) = (String)r4; else hl_dyn_setp(r25->value,150958933/*name*/,&t$String,r4);
	if( hl_vfields(r25)[2] ) *(hl__types__ArrayObj*)(hl_vfields(r25)[2]) = (hl__types__ArrayObj)r20; else hl_dyn_setp(r25->value,239676598/*vars*/,&t$hl_types_ArrayObj,r20);
	if( hl_vfields(r25)[0] ) *(hl__types__ArrayObj*)(hl_vfields(r25)[0]) = (hl__types__ArrayObj)r23; else hl_dyn_setp(r25->value,63237214/*funs*/,&t$hl_types_ArrayObj,r23);
	return r25;
}

