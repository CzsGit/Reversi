// GoBang.h : main header file for the GOBANG application
//

#if !defined(AFX_GOBANG_H__7CE0E132_58C3_4634_8257_E5E062BD7CEE__INCLUDED_)
#define AFX_GOBANG_H__7CE0E132_58C3_4634_8257_E5E062BD7CEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGoBangApp:
// See GoBang.cpp for the implementation of this class
//

class CGoBangApp : public CWinApp
{
public:
	CGoBangApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoBangApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGoBangApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOBANG_H__7CE0E132_58C3_4634_8257_E5E062BD7CEE__INCLUDED_)
