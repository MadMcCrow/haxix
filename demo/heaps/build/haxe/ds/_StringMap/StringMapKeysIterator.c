﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <haxe/ds/_StringMap/StringMapKeysIterator.h>
#include <hl/natives.h>
extern hl_type t$String;

void haxe_ds__StringMap_StringMapKeysIterator_new(haxe__ds___StringMap__StringMapKeysIterator r0,hl_bytes_map* r1) {
	int r3;
	varray *r2;
	r2 = hl_hbkeys(r1);
	r0->arr = r2;
	r3 = 0;
	r0->pos = r3;
	r2 = r0->arr;
	r3 = r2->size;
	r0->length = r3;
	return;
}

bool haxe_ds__StringMap_StringMapKeysIterator_hasNext(haxe__ds___StringMap__StringMapKeysIterator r0) {
	bool r1;
	int r2, r3;
	r2 = r0->pos;
	r3 = r0->length;
	if( r2 < r3 ) goto label$9e6a120_2_5;
	r1 = false;
	goto label$9e6a120_2_6;
	label$9e6a120_2_5:
	r1 = true;
	label$9e6a120_2_6:
	return r1;
}

String haxe_ds__StringMap_StringMapKeysIterator_next(haxe__ds___StringMap__StringMapKeysIterator r0) {
	String r5;
	vbyte *r4;
	int r2, r3;
	varray *r1;
	r1 = r0->arr;
	r2 = r0->pos;
	r3 = r2;
	++r2;
	r0->pos = r2;
	r4 = ((vbyte**)(r1 + 1))[r3];
	r5 = (String)hl_alloc_obj(&t$String);
	r5->bytes = r4;
	r3 = 0;
	r3 = hl_ucs2length(r4,r3);
	r5->length = r3;
	return r5;
}

