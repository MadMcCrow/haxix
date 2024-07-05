﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__impl__GlDriver
#define INC_h3d__impl__GlDriver
typedef struct _h3d__impl__$GlDriver *h3d__impl__$GlDriver;
typedef struct _h3d__impl__GlDriver *h3d__impl__GlDriver;
#include <h3d/impl/GlDriver.h>
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <h3d/Vector4Impl.h>
#include <hl/types/ArrayObj.h>
#include <hl/types/ArrayBytes_Int.h>
#include <h3d/impl/Driver.h>
#include <h3d/impl/_GlDriver/CompiledProgram.h>
#include <h3d/Buffer.h>
#include <h3d/mat/Stencil.h>
#include <haxe/ds/IntMap.h>
#include <h3d/mat/Texture.h>


typedef struct {
	HL__ENUM_CONSTRUCT__
	bool p0;
	vclosure* p1;
} Enumt$ctx_a1ee9dc;
struct _h3d__impl__$GlDriver {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	h3d__Vector4Impl BLACK;
	bool outOfMemoryCheck;
	hl__types__ArrayObj TFILTERS;
	hl__types__ArrayBytes_Int TWRAP;
	hl__types__ArrayBytes_Int FACES;
	hl__types__ArrayBytes_Int BLEND;
	hl__types__ArrayBytes_Int COMPARE;
	hl__types__ArrayBytes_Int STENCIL_OP;
	hl__types__ArrayBytes_Int OP;
	hl__types__ArrayBytes_Int CUBE_FACES;
	vbyte* CBUFFERS;
};
struct _h3d__impl__GlDriver {
	hl_type *$type;
	vdynamic* commonVA;
	vdynamic* commonFB;
	hl__types__ArrayObj curAttribs;
	int maxIdxCurAttribs;
	h3d__impl___GlDriver__CompiledProgram curShader;
	h3d__Buffer curBuffer;
	vvirtual* curIndexBuffer;
	int curMatBits;
	int curStOpBits;
	int curStMaskBits;
	bool curStEnabled;
	h3d__mat__Stencil defStencil;
	haxe__ds__IntMap programs;
	int frame;
	int lastActiveIndex;
	int curColorMask;
	hl__types__ArrayBytes_Int currentDivisor;
	int bufferWidth;
	int bufferHeight;
	h3d__mat__Texture curTarget;
	hl__types__ArrayObj curTargets;
	int numTargets;
	int curTargetLayer;
	int curTargetMip;
	bool debug;
	hl__types__ArrayObj boundTextures;
	vdynamic* glES;
	vdynamic* shaderVersion;
	bool firstShader;
	bool rightHanded;
	bool hasMultiIndirect;
	int maxCompressedTexturesSupport;
	int drawMode;
	bool isIntelGpu;
	h3d__mat__Texture defaultDepth;
	hl__types__ArrayObj streamKeep;
	vbyte* streamBytes;
	int streamLen;
	int streamPos;
};
#endif
