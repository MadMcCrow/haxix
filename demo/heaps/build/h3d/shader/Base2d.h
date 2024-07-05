﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h3d__shader__Base2d
#define INC_h3d__shader__Base2d
typedef struct _h3d__shader__$Base2d *h3d__shader__$Base2d;
typedef struct _h3d__shader__Base2d *h3d__shader__Base2d;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hxsl/SharedShader.h>
#include <hxsl/Shader.h>
#include <hxsl/ShaderInstance.h>
#include <h3d/mat/Texture.h>
#include <h3d/Vector4Impl.h>
#include <h3d/VectorImpl.h>


struct _h3d__shader__$Base2d {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	String SRC;
	hxsl__SharedShader _SHADER;
};
struct _h3d__shader__Base2d {
	hl_type *$type;
	int priority;
	hxsl__SharedShader shader;
	hxsl__ShaderInstance instance;
	int constBits;
	bool constModified;
	double zValue__;
	h3d__mat__Texture texture__;
	bool isRelative__;
	h3d__Vector4Impl color__;
	h3d__VectorImpl absoluteMatrixA__;
	h3d__VectorImpl absoluteMatrixB__;
	h3d__VectorImpl filterMatrixA__;
	h3d__VectorImpl filterMatrixB__;
	bool hasUVPos__;
	h3d__Vector4Impl uvPos__;
	bool killAlpha__;
	bool pixelAlign__;
	h3d__VectorImpl halfPixelInverse__;
	h3d__VectorImpl viewportA__;
	h3d__VectorImpl viewportB__;
};
#endif
