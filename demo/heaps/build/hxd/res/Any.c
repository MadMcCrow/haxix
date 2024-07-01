﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <hxd/res/Any.h>
void hxd_res_Resource_new(hxd__res__Resource,hxd__fs__FileEntry);
#include <h2d/Tile.h>
#include <hxd/res/Image.h>
hxd__res__Image hxd_res_Any_toImage(hxd__res__Any);
h2d__Tile hxd_res_Image_toTile(hxd__res__Image);
extern hxd__res__$Image g$_hxd_res_Image;
hxd__res__Resource hxd_res_Loader_loadCache(hxd__res__Loader,String,hl__Class);
#include <hxd/res/_Any/SingleFileSystem.h>
extern hl_type t$hxd_res__Any_SingleFileSystem;
void hxd_res__Any_SingleFileSystem_new(hxd__res___Any__SingleFileSystem,String,haxe__io__Bytes);
extern hl_type t$hxd_res_Loader;
extern hl_type t$vrt_fa4db88;
void hxd_res_Loader_new(hxd__res__Loader,vvirtual*);
hxd__res__Any hxd_res_Loader_load(hxd__res__Loader,String);

void hxd_res_Any_new(hxd__res__Any r0,hxd__res__Loader r1,hxd__fs__FileEntry r2) {
	hxd_res_Resource_new(((hxd__res__Resource)r0),r2);
	r0->loader = r1;
	return;
}

h2d__Tile hxd_res_Any_toTile(hxd__res__Any r0) {
	h2d__Tile r1;
	hxd__res__Image r2;
	r2 = hxd_res_Any_toImage(r0);
	if( r2 == NULL ) hl_null_access();
	r1 = hxd_res_Image_toTile(r2);
	return r1;
}

hxd__res__Image hxd_res_Any_toImage(hxd__res__Any r0) {
	hxd__fs__FileEntry r4;
	String r3;
	hxd__res__Resource r1;
	hxd__res__Loader r2;
	hxd__res__$Image r5;
	hxd__res__Image r6;
	r2 = r0->loader;
	if( r2 == NULL ) hl_null_access();
	r4 = r0->entry;
	if( r4 == NULL ) hl_null_access();
	r3 = ((String (*)(hxd__fs__FileEntry))r4->$type->vobj_proto[4])(r4);
	r5 = (hxd__res__$Image)g$_hxd_res_Image;
	r1 = hxd_res_Loader_loadCache(r2,r3,((hl__Class)r5));
	r6 = (hxd__res__Image)r1;
	return r6;
}

hxd__res__Any hxd_res_Any_fromBytes(String r0,haxe__io__Bytes r1) {
	vvirtual *r6;
	hxd__res___Any__SingleFileSystem r2;
	hxd__res__Loader r5;
	hxd__res__Any r4;
	r2 = (hxd__res___Any__SingleFileSystem)hl_alloc_obj(&t$hxd_res__Any_SingleFileSystem);
	hxd_res__Any_SingleFileSystem_new(r2,r0,r1);
	r5 = (hxd__res__Loader)hl_alloc_obj(&t$hxd_res_Loader);
	if( r2 ) goto label$e6337da_4_6;
	r6 = NULL;
	goto label$e6337da_4_10;
	label$e6337da_4_6:
	r6 = r2->f$0;
	if( r6 ) goto label$e6337da_4_10;
	r6 = hl_to_virtual(&t$vrt_fa4db88,(vdynamic*)r2);
	r2->f$0 = r6;
	label$e6337da_4_10:
	hxd_res_Loader_new(r5,r6);
	r4 = hxd_res_Loader_load(r5,r0);
	return r4;
}

