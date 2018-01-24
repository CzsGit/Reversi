#if !defined(AFX_RULE_H__4149CD82_AEC1_4288_869D_706EBB8FF735__INCLUDED_)
#define AFX_RULE_H__4149CD82_AEC1_4288_869D_706EBB8FF735__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Rule.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Rule dialog

class Rule : public CDialog
{
// Construction
public:
	Rule(CWnd* pParent = NULL);   // standard constructor
	CFont font;
	CFont font1;
// Dialog Data
	//{{AFX_DATA(Rule)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Rule)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Rule)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULE_H__4149CD82_AEC1_4288_869D_706EBB8FF735__INCLUDED_)
