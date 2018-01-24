// GoBangDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GoBang.h"
#include "GoBangDlg.h"
#include "PlayerName.h"
#include "Rule.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define row 8
#define col 8
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoBangDlg dialog

CGoBangDlg::CGoBangDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGoBangDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGoBangDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGoBangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGoBangDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGoBangDlg, CDialog)
	//{{AFX_MSG_MAP(CGoBangDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_PLAYER_NAME, OnPlayerName)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_NAME, OnUpdatePlayerName)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_Rule, OnRule)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoBangDlg message handlers

BOOL CGoBangDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CRect rcClient;
	CRect rcWindow;
	GetWindowRect(rcWindow);
	GetClientRect(rcClient);
	int nBorderW=rcWindow.Width()-rcClient.Height()-210;
	int nBorderH=rcWindow.Height()-rcClient.Height()-100;
	MoveWindow(80,80,750+nBorderW,750+nBorderH);
	hcur1=AfxGetApp()->LoadCursor(IDC_POINTER);
	hcur2=AfxGetApp()->LoadCursor(IDC_POINTER1);
	br1.CreateSolidBrush(RGB(0,0,0));
	br2.CreateSolidBrush(RGB(255,255,255));
	person=0;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			hasChess[i][j]=0;
	hasChess[row/2-1][col/2-1]=1;
	hasChess[row/2-1][col/2]=2;
	hasChess[row/2][col/2-1]=2;
	hasChess[row/2][col/2]=1;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGoBangDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGoBangDlg::OnPaint() 
{	
	CPaintDC dc(this);
	if (IsIconic())
	{
		 // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	CRect rc;
	GetClientRect(rc);
	dc.FillSolidRect(rc,RGB(218,156,72));
	xstep=rc.Width()/row;
	ystep=rc.Height()/col;
	CPen penSolid(PS_SOLID,1,RGB(192,192,192));
	CPen* pOldPen=dc.SelectObject(&penSolid);
	CBrush* pOldBrush=dc.SelectObject(&br1);
	dc.SetBkMode(TRANSPARENT);
	for(int i=0;i<=rc.Width();i+=xstep)
	{
		dc.MoveTo(i,0);
		dc.LineTo(i,rc.Height());
	}
	for(int j=0;j<=rc.Height();j+=ystep)
	{
		dc.MoveTo(0,j);
		dc.LineTo(rc.Width(),j);
	}
	for(i=0;i<=row;i++)
		for(j=0;j<=col;j++)
		{
			if(hasChess[i][j]!=0)
			{
				CRect rcChess(i*xstep,j*ystep,(i+1)*xstep,(j+1)*ystep);
				if(hasChess[i][j]==1)
				{
					dc.SelectObject(&br1);
					dc.Ellipse(rcChess);
				//	dc.TextOut(rcChess.left+xstep/3*1,rcChess.top,"A");
				}
				else if(hasChess[i][j]==2)
				{
					dc.SelectObject(&br2);
					dc.Ellipse(rcChess);
				//	dc.TextOut(rcChess.left+xstep/3*1,rcChess.top,"B");
				}
			}
		}
		dc.SelectObject(pOldPen);
		dc.SelectObject(pOldBrush);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGoBangDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};//x和y用来确定寻找的方向 
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int CGoBangDlg::TURN(int xPos, int yPos, int curPerson,int hasChess[row][col])
{

	
	for(int i = 0; i < 8; ++i)//控制方向的变化
	{
		int nX = xPos + dx[i]; //在这个方向继续向前寻找
		int nY = yPos + dy[i];
		
		while(NowPositionIsRight(nX, nY)) 
		{
			if(hasChess[nX][nY] == 0)				
				break;
			else if(hasChess[nX][nY] == curPerson)  //如果说是相同的棋子则去更两个相同棋子之间的所有棋子
			{	
				
				while(nX != xPos || nY != yPos)
				{
					nX = nX - dx[i];				//逆向去更新到放棋的点结束，并跳出 
					nY = nY - dy[i];
					
					hasChess[nX][nY] = curPerson; //将对手的棋子换成自己的棋子
				}
				
				break;
			}										
			
			nX = nX + dx[i];						
			nY = nY + dy[i]; 
		}
	}

return 1;
}

void CGoBangDlg::OnPlayerName() 
{
	// TODO: Add your command handler code here
	CPlayerName dlg;
	int result=dlg.DoModal();
	if(result==IDOK)
	{
		name_a=dlg.nameA;
		name_b=dlg.nameB;
		CString title;
		GetWindowText(title);
		SetWindowText(title+"   "+name_a+"VS"+name_b);
		person=1;
	}
}

void CGoBangDlg::OnUpdatePlayerName(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(person==0)
//		pCmdUI->Enable;
	{}
	else
		pCmdUI->Enable(FALSE);
}

BOOL CGoBangDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(person==0)
		return CDialog::OnSetCursor(pWnd, nHitTest, message);
	if(nHitTest==HTCLIENT)
	{
		if(person==1)
			SetCursor(hcur1);
		else if(person==2)
			SetCursor(hcur2);
	}
	return TRUE;
	
}
int x=0;
int y=0;
void CGoBangDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(person==0)
		return;
	int Player_a=0;
	int Player_b=0;
		
	int xpos=point.x/xstep;
	int ypos=point.y/ystep;
	int curPerson;
	if(hasChess[xpos][ypos]!=0)  //下子的坐标如果已经有棋子
	{
		if(DrawAgain(hasChess))  //判断棋盘是否还有空位置
		{
			return;
		}
		else					//没有空余的位置可以下棋则游戏结束。
		{
			for(int i=0;i<row;i++)//统计每个玩家的分数
			{
				for(int j=0;j<col;j++)
					{
									
						if(hasChess[i][j]==1)
							Player_a++;
						else if(hasChess[i][j]==2)
							Player_b++;
					}
			}
			if(Player_a>Player_b)
				MessageBox(name_a+"获胜...再来一局吧！","胜负已定",MB_OK|MB_ICONINFORMATION);
			else if(Player_a<Player_b)
				MessageBox(name_b+"获胜...再来一局吧！","胜负已定",MB_OK|MB_ICONINFORMATION);
			else
				MessageBox("和棋...再来一局吧！","胜负已定",MB_OK|MB_ICONINFORMATION);
			if(person==1)
				person=2;
			else
				person=1;
			for(i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
					{
						hasChess[i][j]=0;
					}
			}
			hasChess[row/2-1][col/2-1]=1;
			hasChess[row/2-1][col/2]=2;
			hasChess[row/2][col/2-1]=2;
			hasChess[row/2][col/2]=1;
			Player_a=0;
			Player_b=0;
			Invalidate();
								
		}
	}

	



			if(DrawAgain(hasChess))
			
				{
				CClientDC dc(this);
				CRect rcChess(xpos*xstep,ypos*ystep,(xpos+1)*xstep,(ypos+1)*ystep);//绘制棋子
				CBrush* pOldBrush=dc.SelectObject(&br1);
				dc.SetBkMode(TRANSPARENT);
				
				if((GoOn(1)||GoOn(2)))//判断是否有玩家可以落子
				{	
					
					if(person==1)
					{
						if(GoOn(1))//判断玩家1是否可以继续落子如果不能则玩家2继续，并给出提示
						{
							if(CanDown(xpos,ypos,1))
							{
								hasChess[xpos][ypos]=1;
								pOldBrush=dc.SelectObject(&br1);
								dc.Ellipse(rcChess);
					
								person=2;
								curPerson=1;
							}
						}
						else 
						{
							MessageBox(name_a+"无法下子，"+name_b+"继续","提示");
							person=2;
							curPerson=1;
						}
					}
					else if(person==2)
					{
						if(GoOn(2))
						{
							if(CanDown(xpos,ypos,2))
							{
								hasChess[xpos][ypos]=2;
								pOldBrush=dc.SelectObject(&br2);
								dc.Ellipse(rcChess);
					
								person=1;
								curPerson=2;
							}
						}
						else 
						{
							MessageBox(name_b+"无法下子，"+name_a+"继续","提示");
							person=1;
							curPerson=2;
						}
					}
					else					//若双方都不可以落子怎游戏结束，并按照当前的棋子数算分
					{
						for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
					{
									
						if(hasChess[i][j]==1)
							Player_a++;
						else if(hasChess[i][j]==2)
							Player_b++;
					}
			}
			if(Player_a>Player_b)
				MessageBox(name_a+"获胜...再来一局吧！","胜负已定",MB_OK|MB_ICONINFORMATION);
			else if(Player_a<Player_b)
				MessageBox(name_b+"获胜...再来一局吧！","胜负已定",MB_OK|MB_ICONINFORMATION);
			else
				MessageBox("和棋...再来一局吧！","胜负已定",MB_OK|MB_ICONINFORMATION);
			if(person==1)
				person=2;
			else
				person=1;
			for(i=0;i<row;i++)//绘制新棋盘，重新开始游戏
			{
				for(int j=0;j<col;j++)
					{
						hasChess[i][j]=0;
					}
			}
			hasChess[row/2-1][col/2-1]=1;
			hasChess[row/2-1][col/2]=2;
			hasChess[row/2][col/2-1]=2;
			hasChess[row/2][col/2]=1;
			Player_a=0;
			Player_b=0;
			Invalidate();	
			
				}
				dc.SelectObject(pOldBrush);
				TURN(xpos,ypos,curPerson,hasChess);
				Invalidate();
	
		}
		


		
	

			}
	

//	DrawAgain(hasChess);
	

	CDialog::OnLButtonDown(nFlags, point);
}

int CGoBangDlg::DrawAgain(int hasChess[row][col])
{
	for(int x=0;x<row;x++)
	{
		for(int y=0;y<col;y++)
		{
			if(hasChess[x][y]==0)
				return TRUE;
		}
	}
	return FALSE;
	
}

bool CGoBangDlg::NowPositionIsRight(int x, int y)
{
	if(x >= 0 && x < row && y >= 0 && y < col)
		return true;
	
	return false;

}

bool CGoBangDlg::CanDown(int xPos, int yPos, int curPerson)
{
	
	int Can=1;
	int nX;
	int nY;
	
	for(int i = 0; i < 8; ++i)
	{
		 nX = xPos + dx[i]; 
		 nY = yPos + dy[i];
		int Long=0;
		while(NowPositionIsRight(nX, nY)) 
		{
			if(hasChess[nX][nY] == 0)				//如果落子的周围没有棋子则不可以落子			
				break;
			else if(hasChess[nX][nY] == curPerson)  
			{	
				if(Long<1)
				{
				
					break;                        // 如果落子的周围是自己的棋子且没有对方的棋子则不可以落子
				}
				else							  //如果落子周围有对方的棋子则可以落子
					
					return TRUE;
			}										
			Long++;								  // 距离落子处的距离
			nX = nX + dx[i];					 //	按照现在的方向继续查找
			nY = nY + dy[i]; 
		}
	}

		return FALSE;
}

bool CGoBangDlg::GoOn(int curPerson)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(hasChess[i][j]==0)
				if(CanDown(i,j,curPerson))
					return TRUE;
		}
	}
	return FALSE;

}

void CGoBangDlg::OnRule() 
{
	// TODO: Add your command handler code here
	Rule dlg;
	dlg.DoModal();
	
}
