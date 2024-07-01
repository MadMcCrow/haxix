﻿// Generated by HLC 5.0.0 (HL v4)
#ifndef INC_h2d__Tile
#define INC_h2d__Tile
typedef struct _h2d__$Tile *h2d__$Tile;
typedef struct _h2d__Tile *h2d__Tile;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <h3d/mat/Texture.h>


struct _h2d__$Tile {
	hl_type *$type;
	hl_type* __type__;
	vdynamic* __meta__;
	varray* __implementedBy__;
	String __name__;
	vdynamic* __constructor__;
	vclosure* fromColor;
	vclosure* fromTexture;
};
struct _h2d__Tile {
	hl_type *$type;
	h3d__mat__Texture innerTex;
	double u;
	double v;
	double u2;
	double v2;
	double dx;
	double dy;
	double x;
	double y;
	double width;
	double height;
};
#endif

