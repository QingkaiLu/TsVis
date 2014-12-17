
// TenVis.h : main header file for the TenVis application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include "Polyhedron\Polyhedron.h"

// CTenVisApp:
// See TenVis.cpp for the implementation of this class
//

class CTenVisApp : public CWinApp
{
public:
	CTenVisApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTenVisApp theApp;
