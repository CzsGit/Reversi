#if !defined(AFX_PLAYERNAME_H__A088CA39_B659_45B7_B397_ACC585C60731__INCLUDED_)
#define AFX_PLAYERNAME_H__A088CA39_B659_45B7_B397_ACC585C60731__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PlayerName.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPlayerName dialog

class CPlayerName : public CDialog
{
// Construction
public:
	CPlayerName(CWnd* pParent = NULL);   // standard constructor
	CString nameA;
	CString nameB;
// Dialog Data
	//{{AFX_DATA(CPlayerName)
	enum { IDD = IDD_PLAYERNAME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayerName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlayerName)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYERNAME_H__A088CA39_B659_45B7_B397_ACC585C60731__INCLUDED_)
