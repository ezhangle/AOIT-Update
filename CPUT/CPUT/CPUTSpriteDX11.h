/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CPUTSPRITE_H
#define _CPUTSPRITE_H

#include "CPUT.h"
#include "d3d11.h"
#include "CPUTSprite.h"

class CPUTMaterial;
class CPUTRenderParameters;
class CPUTTexture;

class CPUTSpriteDX11 : public CPUTSprite
{
protected:

    ID3D11Buffer      *mpVertexBuffer;
    ID3D11InputLayout *mpInputLayout;

public:
    CPUTSpriteDX11()  : CPUTSprite(),
        mpInputLayout(NULL),
        mpVertexBuffer(NULL)
    {
    }
    ~CPUTSpriteDX11();
    static CPUTSpriteDX11* CreateSprite(
        float          spriteX,
        float          spriteY,
        float          spriteWidth,
        float          spriteHeight,
        const cString &materialName 
    );
    void DrawSprite( CPUTRenderParameters &renderParams ) { DrawSprite( renderParams, *mpMaterial ); }
    void DrawSprite( CPUTRenderParameters &renderParams, CPUTMaterial &material );
};

#endif // _CPUTSPRITE_H