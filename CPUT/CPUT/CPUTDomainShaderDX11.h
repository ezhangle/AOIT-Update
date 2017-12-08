/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CPUTDOMAINSHADERDX11_H
#define _CPUTDOMAINSHADERDX11_H

#include "CPUT.h"
#include "CPUTShaderDX11.h"

class CPUTDomainShaderDX11 : public CPUTShaderDX11
{
protected:
    ID3D11DomainShader *mpDomainShader;

    // Destructor is not public.  Must release instead of delete.
    ~CPUTDomainShaderDX11(){ SAFE_RELEASE(mpDomainShader) }

public:
    static CPUTDomainShaderDX11 *CreateDomainShader(
        const cString    &name,
        const cString    &shaderMain,
        const cString    &shaderProfile,
        CPUT_SHADER_MACRO *pShaderMacros=NULL
    );
    static CPUTDomainShaderDX11 *CreateDomainShaderFromMemory(
        const cString    &name,
        const cString    &shaderMain,
        const cString    &shaderProfile,
        const char       *pShaderSource,
        CPUT_SHADER_MACRO *pShaderMacros=NULL
    );

    CPUTDomainShaderDX11() : mpDomainShader(NULL), CPUTShaderDX11(NULL) {}
    CPUTDomainShaderDX11(ID3D11DomainShader *pD3D11DomainShader, ID3DBlob *pBlob) : mpDomainShader(pD3D11DomainShader), CPUTShaderDX11(pBlob) {}
    ID3DBlob *GetBlob() { return mpBlob; }
    ID3D11DomainShader *GetNativeDomainShader() { return mpDomainShader; }
};

#endif //_CPUTDOMAINSHADER_H