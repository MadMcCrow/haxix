﻿// Generated by HLC 5.0.0 (HL v4)
#define HLC_BOOT
#include <hlc.h>
#include <haxe/exceptions/NotImplementedException.h>
extern String s$Not_implemented;
void haxe_exceptions_PosException_new(haxe__exceptions__PosException,String,haxe__Exception,vvirtual*);

void haxe_exceptions_NotImplementedException_new(haxe__exceptions__NotImplementedException r0,String r1,haxe__Exception r2,vvirtual* r3) {
	String r4;
	int r6;
	if( r1 ) goto label$b77c151_1_3;
	r4 = (String)s$Not_implemented;
	r1 = r4;
	label$b77c151_1_3:
	haxe_exceptions_PosException_new(((haxe__exceptions__PosException)r0),r1,r2,r3);
	r6 = r0->__skipStack;
	++r6;
	r0->__skipStack = r6;
	return;
}

