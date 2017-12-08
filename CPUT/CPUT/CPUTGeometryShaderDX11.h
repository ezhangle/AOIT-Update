/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CPUTGEOMETRYSHADERDX11_H
#define _CPUTGEOMETRYSHADERDX11_H

#include "CPUT.h"
#include "CPUTShaderDX11.h"

class CPUTGeometryShaderDX11 : public CPUTShaderDX11
{
protected:
    ID3D11GeometryShader *mpGeometryShader;

    // Destructor is not public.  Must release instead of delete.
    ~CPUTGeometryShaderDX11(){ SAFE_RELEASE(mpGeometryShader); }

public:
    static CPUTGeometryShaderDX11 *CreateGeometryShader(
        const cString     &name,
        const cString     &shaderMain,
        const cString     &shaderProfile,
        CPUT_SHADER_MACRO *pShaderMacros=NULL
    );
    static CPUTGeometryShaderDX11 *CreateGeometryShaderFromMemory(
        const cString     &name,
        const cString     &shaderMain,
        const cString     &shaderProfile,
        const char        *pShaderSource,
        CPUT_SHADER_MACRO *pShaderMacros=NULL
    );

    CPUTGeometryShaderDX11() : mpGeometryShader(NULL), CPUTShaderDX11(NULL) {}
    CPUTGeometryShaderDX11(ID3D11GeometryShader *pD3D11GeometryShader, ID3DBlob *pBlob) : mpGeometryShader(pD3D11GeometryShader), CPUTShaderDX11(pBlob) {}
    ID3DBlob *GetBlob() { return mpBlob; }
    ID3D11GeometryShader *GetNativeGeometryShader() { return mpGeometryShader; }
};

#endif //_CPUTGEOMETRYSHADER_H