// PlayerName.cpp : implementation file
//

#include "stdafx.h"
#include "GoBang.h"
#include "PlayerName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlayerName dialog


CPlayerName::CPlayerName(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayerName::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayerName)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPlayerName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayerName)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlayerName, CDialog)
	//{{AFX_MSG_MAP(CPlayerName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayerName message handlers

void CPlayerName::OnOK() 
{
	// TODO: Add extra validation here
	GetDlgItem(IDC_EDIT_A)->GetWindowText(nameA);
	GetDlgItem(IDC_EDIT_B)->GetWindowText(nameB);
	if(nameA.IsEmpty()||nameB.IsEmpty())
		return;
	CDialog::OnOK();
}
