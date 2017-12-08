/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __CPUTCALLBACKHANDLER_H__
#define __CPUTCALLBACKHANDLER_H__

#include "CPUT.h"
#include "CPUTControl.h"
//forward declarations
class CPUTControl;
class CPUTGUIElement;

typedef unsigned int UINT;
typedef UINT CPUTControlID;

#define UNREFERENCED_PARAMETER(P) (P)

class CPUTCallbackHandler
{
public:
    virtual void HandleCallbackEvent( CPUTEventID Event, CPUTControlID ControlID, CPUTControl *pControl ) {UNREFERENCED_PARAMETER(Event);UNREFERENCED_PARAMETER(ControlID);UNREFERENCED_PARAMETER(pControl);}
    virtual void HandleGUIElementEvent( CPUTEventID Event, CPUTControlID ControlID, CPUTGUIElement *pElement) {UNREFERENCED_PARAMETER(Event);UNREFERENCED_PARAMETER(ControlID);UNREFERENCED_PARAMETER(pElement);}
};


#endif // #ifndef __CPUTCALLBACKHANDLER_H__