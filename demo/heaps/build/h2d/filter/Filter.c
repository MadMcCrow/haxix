﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <h2d/filter/Filter.h>
#include <h2d/RenderContext.h>
#include <h2d/Object.h>
#include <h2d/col/Bounds.h>
#include <h2d/col/PointImpl.h>
h2d__col__Bounds h2d_Object_getBounds(h2d__Object,h2d__Object,h2d__col__Bounds);
#include <h2d/Tile.h>
extern h2d__filter__$Filter g$_h2d_filter_Filter;

bool h2d_filter_Filter_get_enable(h2d__filter__Filter r0) {
	bool r1;
	r1 = r0->enable;
	return r1;
}

void h2d_filter_Filter_sync(h2d__filter__Filter r0,h2d__RenderContext r1,h2d__Object r2) {
	return;
}

void h2d_filter_Filter_bind(h2d__filter__Filter r0,h2d__Object r1) {
	return;
}

void h2d_filter_Filter_unbind(h2d__filter__Filter r0,h2d__Object r1) {
	return;
}

void h2d_filter_Filter_getBounds(h2d__filter__Filter r0,h2d__Object r1,h2d__col__Bounds r2,h2d__col__PointImpl r3) {
	h2d__col__Bounds r4;
	double r5, r6;
	if( r1 == NULL ) hl_null_access();
	r4 = h2d_Object_getBounds(r1,r1,r2);
	if( r2 == NULL ) hl_null_access();
	r5 = r2->xMin;
	if( r3 == NULL ) hl_null_access();
	r6 = r3->x;
	r5 = r5 * r6;
	r6 = r0->boundsExtend;
	r5 = r5 - r6;
	r2->xMin = r5;
	r5 = r2->xMax;
	r6 = r3->x;
	r5 = r5 * r6;
	r6 = r0->boundsExtend;
	r5 = r5 + r6;
	r2->xMax = r5;
	r5 = r2->yMin;
	r6 = r3->y;
	r5 = r5 * r6;
	r6 = r0->boundsExtend;
	r5 = r5 - r6;
	r2->yMin = r5;
	r5 = r2->yMax;
	r6 = r3->y;
	r5 = r5 * r6;
	r6 = r0->boundsExtend;
	r5 = r5 + r6;
	r2->yMax = r5;
	return;
}

h2d__Tile h2d_filter_Filter_draw(h2d__filter__Filter r0,h2d__RenderContext r1,h2d__Tile r2) {
	return r2;
}

void h2d_filter_Filter_new(h2d__filter__Filter r0) {
	h2d__filter__$Filter r2;
	bool r1;
	double r3;
	r2 = (h2d__filter__$Filter)g$_h2d_filter_Filter;
	r1 = r2->defaultUseScreenResolution;
	r0->useScreenResolution = r1;
	r3 = 1.;
	r0->resolutionScale = r3;
	r1 = true;
	r0->enable = r1;
	r3 = 0.;
	r0->boundsExtend = r3;
	r1 = true;
	r0->autoBounds = r1;
	return;
}

