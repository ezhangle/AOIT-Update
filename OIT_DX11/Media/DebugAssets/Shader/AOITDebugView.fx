/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AOIT CODE////////////////////////////////////////////////////////////////////////////////////////////////////



//AOIT CODE////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct AOITCtrlSurface
{
	bool  clear;
	bool  opaque;
	float depth;
};

struct AOITDebugViewConsts
{
    int a;
    int b;
    int c;
    int d;
};

cbuffer cbAOITDebugViewConsts : register(b4)
{
   AOITDebugViewConsts  g_AOITDebugViewConsts;
};

// ********************************************************************************************************


struct PS_INPUT
{
    float4 Pos     : SV_POSITION;
    float2 Uv      : TEXCOORD0;
};

// ********************************************************************************************************
Texture2D    TEXTURE0 : register( t0 );
SamplerState SAMPLER0 : register( s0 );

Texture2D<uint> gAOITSPClearMaskSRV : register( t29 );


void AOITLoadControlSurface(in uint data, inout AOITCtrlSurface surface)
{
	surface.clear	= data & 0x1 ? true : false;
	surface.opaque  = data & 0x2 ? true : false;
	surface.depth   = asfloat((data & 0xFFFFFFFCUL) | 0x3UL);
}

void AOITLoadControlSurfaceSRV(in uint2 pixelAddr, inout AOITCtrlSurface surface)
{
	uint data = gAOITSPClearMaskSRV[pixelAddr];
	AOITLoadControlSurface(data, surface);
}
// ********************************************************************************************************
float4 PSMain( PS_INPUT input ) : SV_Target
{
	AOITCtrlSurface ctrlSurface;

    uint2 dim;
	gAOITSPClearMaskSRV.GetDimensions(dim[0], dim[1]);    
    const int2 pixelAddr = (int2)(input.Uv * (float2)dim);
    AOITLoadControlSurfaceSRV(pixelAddr, ctrlSurface);

    return float4( !ctrlSurface.clear, 0.0, 0.0, 0.5 );
}