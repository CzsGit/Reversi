// Rule.cpp : implementation file
//

#include "stdafx.h"
#include "GoBang.h"
#include "Rule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Rule dialog


Rule::Rule(CWnd* pParent /*=NULL*/)
	: CDialog(Rule::IDD, pParent)
{
	//{{AFX_DATA_INIT(Rule)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Rule::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Rule)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Rule, CDialog)
	//{{AFX_MSG_MAP(Rule)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Rule message handlers

BOOL Rule::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	font.CreatePointFont(300, "华文行楷"); 
	GetDlgItem(IDC_STATIC0)->SetFont(&font);
	font1.CreatePointFont(150, "华文行楷"); 
	GetDlgItem(IDC_STATIC1)->SetFont(&font1);
//	font.CreatePointFont(150, "华文行楷"); 
	GetDlgItem(IDC_STATIC2)->SetFont(&font1);
//	font.CreatePointFont(150, "华文行楷"); 
	GetDlgItem(IDC_STATIC3)->SetFont(&font1);
//	font.CreatePointFont(150, "华文行楷"); 
	GetDlgItem(IDC_STATIC4)->SetFont(&font1);
//	font.CreatePointFont(150, "华文行楷"); 
	GetDlgItem(IDC_STATIC5)->SetFont(&font1);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Rule::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rc;
	GetClientRect(rc);
	dc.FillSolidRect(rc,RGB(218,156,72));
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH Rule::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if (nCtlColor==CTLCOLOR_STATIC)

              {
                    pDC->SetTextColor(RGB(0,255,255));  //字体颜色
					pDC->SetBkColor(RGB(218,156,72));   //字体背景色  
					
                }
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
