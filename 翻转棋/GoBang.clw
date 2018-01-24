; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGoBangDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GoBang.h"

ClassCount=5
Class1=CGoBangApp
Class2=CGoBangDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_GOBANG_DIALOG
Resource4=IDD_ABOUTBOX
Class4=CPlayerName
Resource5=IDD_PLAYERNAME
Class5=Rule
Resource6=IDR_MENU1

[CLS:CGoBangApp]
Type=0
HeaderFile=GoBang.h
ImplementationFile=GoBang.cpp
Filter=N

[CLS:CGoBangDlg]
Type=0
HeaderFile=GoBangDlg.h
ImplementationFile=GoBangDlg.cpp
Filter=D
LastObject=ID_Rule
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=GoBangDlg.h
ImplementationFile=GoBangDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_GOBANG_DIALOG]
Type=1
Class=CGoBangDlg
ControlCount=0

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_PLAYER_NAME
Command2=ID_Rule
CommandCount=2

[CLS:CPlayerName]
Type=0
HeaderFile=PlayerName.h
ImplementationFile=PlayerName.cpp
BaseClass=CDialog
Filter=D
LastObject=CPlayerName
VirtualFilter=dWC

[DLG:IDD_PLAYERNAME]
Type=1
Class=CPlayerName
ControlCount=6
Control1=IDC_EDIT_A,edit,1350631552
Control2=IDC_EDIT_B,edit,1350631552
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=Rule
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_STATIC0,static,1342308352
Control3=IDC_STATIC1,static,1342308352
Control4=IDC_STATIC2,static,1342308352
Control5=IDC_STATIC3,static,1342308352
Control6=IDC_STATIC4,static,1342308352
Control7=IDC_STATIC5,static,1342308352

[CLS:Rule]
Type=0
HeaderFile=Rule.h
ImplementationFile=Rule.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_PLAYER_NAME
VirtualFilter=dWC

