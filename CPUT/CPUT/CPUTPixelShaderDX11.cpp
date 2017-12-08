/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#include "CPUT_DX11.h"
#include "CPUTPixelShaderDX11.h"
#include "CPUTAssetLibraryDX11.h"

CPUTPixelShaderDX11 *CPUTPixelShaderDX11::CreatePixelShader(
    const cString     &name,
    const cString     &shaderMain,
    const cString     &shaderProfile,
    CPUT_SHADER_MACRO *pShaderMacros
)
{
    ID3DBlob           *pCompiledBlob = NULL;
    ID3D11PixelShader  *pNewPixelShader = NULL;

    CPUTAssetLibraryDX11 *pAssetLibrary = (CPUTAssetLibraryDX11*)CPUTAssetLibrary::GetAssetLibrary();
    CPUTResult result = pAssetLibrary->CompileShaderFromFile(name, shaderMain, shaderProfile, &pCompiledBlob, pShaderMacros);
    ASSERT( CPUTSUCCESS(result), _L("Error compiling pixel shader:\n\n") );
    UNREFERENCED_PARAMETER(result);

    // Create the pixel shader
    ID3D11Device      *pD3dDevice = CPUT_DX11::GetDevice();
    HRESULT hr = pD3dDevice->CreatePixelShader( pCompiledBlob->GetBufferPointer(), pCompiledBlob->GetBufferSize(), NULL, &pNewPixelShader );
    ASSERT( SUCCEEDED(hr), _L("Error creating pixel shader:\n\n") );
    UNREFERENCED_PARAMETER(hr);
    // cString DebugName = _L("CPUTAssetLibraryDX11::GetPixelShader ")+name;
    // CPUTSetDebugName(pNewPixelShader, DebugName);

    CPUTPixelShaderDX11 *pNewCPUTPixelShader = new CPUTPixelShaderDX11( pNewPixelShader, pCompiledBlob );

    // add shader to library
    pAssetLibrary->AddPixelShader( name, _L(""), shaderMain + shaderProfile, pNewCPUTPixelShader, pShaderMacros );

    // return the shader (and blob)
    return pNewCPUTPixelShader;
}

//--------------------------------------------------------------------------------------
CPUTPixelShaderDX11 *CPUTPixelShaderDX11::CreatePixelShaderFromMemory(
    const cString     &name,
    const cString     &shaderMain,
    const cString     &shaderProfile,
    const char        *pShaderSource,
    CPUT_SHADER_MACRO *pShaderMacros
)
{
    ID3DBlob           *pCompiledBlob = NULL;
    ID3D11PixelShader  *pNewPixelShader = NULL;

    CPUTAssetLibraryDX11 *pAssetLibrary = (CPUTAssetLibraryDX11*)CPUTAssetLibrary::GetAssetLibrary();
    CPUTResult result = pAssetLibrary->CompileShaderFromMemory(pShaderSource, shaderMain, shaderProfile, &pCompiledBlob, pShaderMacros);
    ASSERT( CPUTSUCCESS(result), _L("Error compiling pixel shader:\n\n") );
    UNREFERENCED_PARAMETER(result);

    // Create the pixel shader
    ID3D11Device      *pD3dDevice = CPUT_DX11::GetDevice();
    HRESULT hr = pD3dDevice->CreatePixelShader( pCompiledBlob->GetBufferPointer(), pCompiledBlob->GetBufferSize(), NULL, &pNewPixelShader );
    ASSERT( SUCCEEDED(hr), _L("Error creating pixel shader:\n\n") );
    UNREFERENCED_PARAMETER(hr);
    // cString DebugName = _L("CPUTAssetLibraryDX11::GetPixelShader ")+name;
    // CPUTSetDebugName(pNewPixelShader, DebugName);

    CPUTPixelShaderDX11 *pNewCPUTPixelShader = new CPUTPixelShaderDX11( pNewPixelShader, pCompiledBlob );

    // add shader to library
    pAssetLibrary->AddPixelShader( name, _L(""), shaderMain + shaderProfile, pNewCPUTPixelShader, pShaderMacros);
    // pNewCPUTPixelShader->Release(); // We've added it to the library, so release our reference

    // return the shader (and blob)
    return pNewCPUTPixelShader;
}