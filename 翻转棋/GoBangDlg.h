// GoBangDlg.h : header file
//

#if !defined(AFX_GOBANGDLG_H__78DCD1AF_FE52_4991_A140_3B36DA72AC02__INCLUDED_)
#define AFX_GOBANGDLG_H__78DCD1AF_FE52_4991_A140_3B36DA72AC02__INCLUDED_
#define row 8
#define col 8
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGoBangDlg dialog

class CGoBangDlg : public CDialog
{
// Construction
public:
	bool GoOn(int curPerson);
	bool CanDown(int xpos,int ypos,int curPerson);
	bool NowPositionIsRight(int x,int y);
	int DrawAgain(int hasChess[row][col]);
	int TURN(int xPos,int yPos,int curPerson,int hasChess[row][col]);
	CGoBangDlg(CWnd* pParent = NULL);	// standard constructor
	CString name_a;
	CString name_b;
	HCURSOR hcur1;
	HCURSOR hcur2;
	CBrush br1;
	CBrush br2;
	int person;
	int ystep;
	int xstep;
	 int hasChess[row][col];
	


// Dialog Data
	//{{AFX_DATA(CGoBangDlg)
	enum { IDD = IDD_GOBANG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoBangDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGoBangDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlayerName();
	afx_msg void OnUpdatePlayerName(CCmdUI* pCmdUI);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRule();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOBANGDLG_H__78DCD1AF_FE52_4991_A140_3B36DA72AC02__INCLUDED_)
