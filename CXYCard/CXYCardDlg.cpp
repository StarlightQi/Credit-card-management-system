
// CXYCardDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CXYCard.h"
#include "CXYCardDlg.h"
#include "afxdialogex.h"
#include "TJYH.h"
#include "YWYMT.h"
#include "Deng.h"
#include "OLDDlg.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include  <io.h>
#include <shellapi.h>
#include <afxinet.h>
#include "Read.h"
#include "TextSpeaker.h"
gds::CTextSpeaker m_read2;//定义语音阅读对象成员
//#include <windows.h>
using namespace std;
#include <Wininet.h>
#pragma comment (lib, "Wininet.lib")
using namespace std;
#define WM_SHOWTASK WM_USER+101
#define IDR_UPDATE 12//设置相应菜单的宏（最小托盘化菜单）
#define IDR_OPEN 13
#define IDR_SHUO 14
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnYbiadu();
//	afx_msg void OnPaint();
	afx_msg void OnBnClickedBnUp();
	afx_msg void OnBnClickedMfclink1();
//	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

ON_COMMAND(ID_Ybiadu, &CAboutDlg::OnYbiadu)

//	ON_WM_PAINT()
ON_BN_CLICKED(IDC_BN_UP, &CAboutDlg::OnBnClickedBnUp)
ON_BN_CLICKED(IDC_MFCLINK1, &CAboutDlg::OnBnClickedMfclink1)
//ON_WM_ACTIVATE()
END_MESSAGE_MAP()


// CCXYCardDlg 对话框



CCXYCardDlg::CCXYCardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCXYCardDlg::IDD, pParent)
	, m_strFind(_T(""))
	, m_exit(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//读取文件判断复选框的真假值
	//直接退出程序，用于记录复选框的状态
	if((_access( "C:\\XYKGL\\Root\\ret.re", 0 )) == 0){
    ifstream infile; 
	string gg="C:\\XYKGL\\Root\\ret.re";
    infile.open(gg.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
   ex= atoi( s.c_str() );//转换类型int
   if(ex==123)
   {
	   m_exit=true;
   }
   else
   {
	   m_exit=false;
   }

   infile.close();


	}

}

void CCXYCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LI_liebiao, m_lstcPersonList);
	DDX_Text(pDX, IDC_EDI_fund, m_strFind);
	DDX_Check(pDX, IDC_CHECK1, m_exit);
	//  DDX_Text(pDX, IDC_MFCCOLORBUTTON1, m_color);

}

BEGIN_MESSAGE_MAP(CCXYCardDlg, CDialogEx)
	ON_MESSAGE(WM_SHOWTASK,OnShowTask)//绑定函数（最小托盘化）
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()

	ON_BN_CLICKED(IDC_BN_BR, &CCXYCardDlg::OnBnClickedBnBr)
	ON_EN_CHANGE(IDC_EDI_fund, &CCXYCardDlg::OnChangeEdiFund)
	ON_BN_CLICKED(IDC_BN_Fand, &CCXYCardDlg::OnBnClickedBnFand)
	ON_COMMAND(ID_SAVE, &CCXYCardDlg::OnSave)
	ON_COMMAND(ID_OPEN, &CCXYCardDlg::OnOpen)
	ON_COMMAND(ID_CLOSE, &CCXYCardDlg::OnClose)
	ON_COMMAND(ID_ADD, &CCXYCardDlg::OnAdd)
	ON_COMMAND(ID_DEL, &CCXYCardDlg::OnDel)
	ON_COMMAND(ID_EXER, &CCXYCardDlg::OnExer)
	ON_COMMAND(ID_YE, &CCXYCardDlg::OnYe)
	ON_COMMAND(ID_SHUTDOWN, &CCXYCardDlg::OnShutdown)
	ON_COMMAND(ID_32788, &CCXYCardDlg::On32788)
	ON_COMMAND(ID_XZ, &CCXYCardDlg::OnXz)
	ON_COMMAND(ID_QS, &CCXYCardDlg::OnQs)
	ON_COMMAND(ID_JSQ, &CCXYCardDlg::OnJsq)
	ON_COMMAND(ID_txt, &CCXYCardDlg::Ontxt)
	ON_COMMAND(ID_baidu, &CCXYCardDlg::Onbaidu)
	ON_COMMAND(ID_LP, &CCXYCardDlg::OnLp)
	ON_COMMAND(ID_SHUO, &CCXYCardDlg::OnShuo)
	ON_COMMAND(ID_BU_ADD1, &CCXYCardDlg::OnBuAdd1)
	ON_COMMAND(ID_BU_DEL1, &CCXYCardDlg::OnBuDel1)
	ON_COMMAND(ID_BU_OPEN1, &CCXYCardDlg::OnBuOpen1)
	ON_COMMAND(ID_BU_BEI, &CCXYCardDlg::OnBuBei)
	ON_COMMAND(ID_BU_RE1, &CCXYCardDlg::OnBuRe1)
	ON_COMMAND(ID_BU_TONG1, &CCXYCardDlg::OnBuTong1)
	ON_COMMAND(ID_BU_ABOUT1, &CCXYCardDlg::OnBuAbout1)
	ON_COMMAND(ID_BU_YEWU, &CCXYCardDlg::OnBuYewu)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ADD3, &CCXYCardDlg::OnAdd3)
	ON_COMMAND(ID_RE3, &CCXYCardDlg::OnRe3)
	ON_COMMAND(ID_TONG3, &CCXYCardDlg::OnTong3)
	ON_COMMAND(ID_DEL3, &CCXYCardDlg::OnDel3)
	ON_COMMAND(ID_32917, &CCXYCardDlg::On32917)
	ON_WM_TIMER()

	ON_WM_ERASEBKGND()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LI_liebiao, &CCXYCardDlg::OnNMCustomdrawLiliebiao)
	ON_COMMAND(ID_32927, &CCXYCardDlg::On32927)
END_MESSAGE_MAP()


// CCXYCardDlg 消息处理程序

BOOL CCXYCardDlg::OnInitDialog()
{
	//设置界面透明度为0
	::SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,::GetWindowLongPtr(GetSafeHwnd(),GWL_EXSTYLE)|WS_EX_LAYERED);
    this->SetLayeredWindowAttributes(0,0,LWA_ALPHA);

	CDialogEx::OnInitDialog();
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	InitPersonListCtrl();
	CreateToolBar();
	// TODO: 在此添加额外的初始化代码
	WCHAR szCurPath[_MAX_PATH];
	GetCurrentDirectory(MAX_PATH,szCurPath);
	m_s.Format(_T("C:\\XYKGL\\Root\\root.xyk"),szCurPath);
	if(PathFileExists(m_s)){
	DoLoadFile(m_s);
	RefreshPersonListCtrl(m_lstPerson);
	}
	 m_nid.cbSize  = (DWORD)sizeof(NOTIFYICONDATA);//设置大小
    m_nid.hWnd    = this->m_hWnd;
    m_nid.uID     = IDR_MAINFRAME;
    m_nid.uFlags  = NIF_ICON | NIF_MESSAGE | NIF_TIP ;//设置默认参数
    m_nid.uCallbackMessage = WM_SHOWTASK;          // 自定义的消息名称需在头部声明
    m_nid.hIcon   = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));  //获取图标资源       
	wcscpy_s(m_nid.szTip, _T("信用卡管理系统"));  // 信息提示条
    Shell_NotifyIcon(NIM_ADD, &m_nid);                // 在托盘区添加图标
		SetTimer(1,25,NULL);//在规定的时间内调用重复调用这个函数
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
//对托盘操作后的响应函数
 LRESULT CCXYCardDlg::OnShowTask(WPARAM wparam,LPARAM lParam){
	if(wparam != IDR_MAINFRAME)
           return 1;
           switch(lParam)
           {
           case WM_RBUTTONUP:                                        // 右键起来时弹出菜单
			   {          
                         LPPOINT lpoint = new tagPOINT;
                         ::GetCursorPos(lpoint);                    // 得到鼠标位置
                         CMenu menu;
                         menu.CreatePopupMenu();                    // 声明一个弹出式菜单
						 menu.AppendMenu(MF_STRING, IDR_OPEN,L"打开主界面");
						 menu.AppendMenu(MFT_STRING, IDR_UPDATE,L"检查更新");
						 menu.AppendMenu(MF_STRING, WM_DESTROY,L"退出");
                          SetForegroundWindow();                
						  int xx=TrackPopupMenu(menu,TPM_RETURNCMD,lpoint->x,lpoint->y,NULL,this->m_hWnd,NULL);
						   if(xx==WM_DESTROY){ 
							   CDialogEx::OnOK();//退出程序
						   }
						   if(xx==IDR_UPDATE){
							   //调用函数更新
						    CAboutDlg UP;
							UP.OnBnClickedBnUp();
						   }//打开网页代码
						   if(xx==IDR_OPEN) {
							   this->ShowWindow(SW_SHOWNORMAL);		// 打开主窗口				  
							  SetWindowPos(&wndNoTopMost,0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
						   }
						  HMENU hmenu = menu.Detach();//弹出菜单
						  menu.DestroyMenu();
							delete lpoint;
                  }
                  break;
		   case WM_LBUTTONDOWN:                                 // 但击左键的处理

                  {
                         this->ShowWindow(SW_SHOWNORMAL);         // 显示主窗口
                  }
                  break;
           }
           return 0;
}


void CCXYCardDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	UpdateData(true);
	//更新复选框写入记录；
	ofstream out2("C:\\XYKGL\\Root\\ret.re");
	if(m_exit){
	out2<<"123";
	}else
	{
		out2<<"321";
	}
	out2.close();
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}else if((nID & 0xFFF0)==SC_CLOSE&&!m_exit){//按关闭后最小化
		
		ShowWindow(SW_HIDE);//隐藏窗口
		Shell_NotifyIcon(NIM_ADD,&m_nid);//添加到系统托盘图标
	
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void CCXYCardDlg::OnPaint()
{
	
	CPaintDC   dc(this);   
	//重写背景函数，改为位图背景
          CRect   rect;   
          GetClientRect(&rect);   
          CDC   dcMem;   
          dcMem.CreateCompatibleDC(&dc);   
          CBitmap   bmpBackground;   
          bmpBackground.LoadBitmap(IDB_BITMAP5);   
                  //IDB_BITMAP是你自己的图对应的ID   
          BITMAP   bitmap;   
          bmpBackground.GetBitmap(&bitmap);   
          CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
          dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  

		  //载入时显示控件的图片（头像）
	if(m_lstPerson.GetCount()!=0&&PathFileExists(m_lstPerson[GetCurSel()].GetImageHead())){
		CGCustomerList::ShowImage(this->m_hWnd,m_lstPerson[GetCurSel()].GetImageHead(),IDC_STA_HEAD);
	}
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}


}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCXYCardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//void CCXYCardDlg::OnBnClickedBnTianjia()
//{
//	CGCustomert psnDef;
//	TJYH dlgEdit(psnDef,this);
//   int iRet=dlgEdit.DoModal();
//   if(iRet==IDOK){
//	   m_lstPerson.Add(dlgEdit.GetGCustomert());
//	   RefreshPersonListCtrl(m_lstPerson,m_lstPerson.GetSize()-1);
//   
//   }
//	// TODO: 在此添加控件通知处理程序代码
//}
void CCXYCardDlg::InitPersonListCtrl(void){
	m_lstcPersonList.SetExtendedStyle(m_lstcPersonList.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_lstcPersonList.InsertColumn(0,_T("编号"),LVCFMT_CENTER,100);
	m_lstcPersonList.InsertColumn(1,_T("姓名"),LVCFMT_CENTER,100);
	m_lstcPersonList.InsertColumn(2,_T("性别"),LVCFMT_CENTER,50);
	m_lstcPersonList.InsertColumn(3,_T("手机号"),LVCFMT_CENTER,120);
	m_lstcPersonList.InsertColumn(4,_T("QQ号"),LVCFMT_CENTER,120);
	m_lstcPersonList.InsertColumn(5,_T("状态"),LVCFMT_CENTER,120);
	m_lstcPersonList.InsertColumn(6,_T("额度"),LVCFMT_CENTER,80);
	m_lstcPersonList.InsertColumn(7,_T("公司"),LVCFMT_CENTER,230);
	m_lstcPersonList.InsertColumn(8,_T("年龄"),LVCFMT_CENTER,80);
	m_lstcPersonList.InsertColumn(9,_T("备注"),LVCFMT_CENTER,350);



}
int CCXYCardDlg::GetCurSel(void)
{
	POSITION pos=m_lstcPersonList.GetFirstSelectedItemPosition();
	return m_lstcPersonList.GetNextSelectedItem(pos);

}
void CCXYCardDlg::RefreshPersonListCtrl(CGCustomerList& psnList,int iCurSel)
{
		
int iLastSel=GetCurSel();
m_lstcPersonList.DeleteAllItems();
for(int i=0;i<psnList.GetSize();i++){
	m_lstcPersonList.InsertItem(i,psnList[i].GetBian());
	m_lstcPersonList.SetItemText(i,1,psnList[i].GetName());
	m_lstcPersonList.SetItemText(i,2,psnList[i].IsMale()?_T("女"):_T("男"));
	m_lstcPersonList.SetItemText(i,3,psnList[i].GetPhoneNo());
	m_lstcPersonList.SetItemText(i,4,psnList[i].GetQQNo());
	m_lstcPersonList.SetItemText(i,5,psnList[i].GetZhang()?_T("未按时还款"):_T("已按时还款"));
	m_lstcPersonList.SetItemText(i,6,psnList[i].GetEd());
	m_lstcPersonList.SetItemText(i,7,psnList[i].GetGong());
	m_lstcPersonList.SetItemText(i,8,psnList[i].GetNLing());
	m_lstcPersonList.SetItemText(i,9,psnList[i].GetBz());

}
	if(iCurSel<0){
		if(iLastSel<0)
			iCurSel=psnList.GetSize()>0?0:-1;
		else
			iCurSel=min(psnList.GetSize()-1,iLastSel);
	
	}
	else{
		iCurSel=min(psnList.GetSize()-1,iCurSel);
	
	}
	if(iCurSel>=0){
		m_lstcPersonList.SetFocus();
		m_lstcPersonList.SetItemState(iCurSel,LVIS_SELECTED,LVIS_SELECTED);
	}
	if(m_lstPerson.GetCount()!=0&&PathFileExists(m_lstPerson[iCurSel].GetImageHead()))
	{
	CGCustomerList::ShowImage(this->m_hWnd,m_lstPerson[GetCurSel()].GetImageHead(),IDC_STA_HEAD);
	}

	CountOld();
}

//void CCXYCardDlg::OnBnClickedBnshanchu()
//{
//	int iCurSel=GetCurSel();
//	if(iCurSel<0)return;
//	CString strHint;
//	strHint.Format(_T("你确认删除名为%s的客户吗?"),m_lstPerson[iCurSel].GetName());
//	if(MessageBox(strHint,_T("确认删除"),MB_YESNO|MB_ICONQUESTION)==IDYES)
//	m_lstPerson.RemoveAt(iCurSel);
//	RefreshPersonListCtrl(m_lstPerson,iCurSel);
//
//	// TODO: 在此添加控件通知处理程序代码
//}


//void CCXYCardDlg::OnBnClickedBnxiugai()
//{
//	int iCurSel=GetCurSel();
//	if(iCurSel<0)return;
//	TJYH dlgEdit(m_lstPerson[iCurSel],this);
//	int iRet=dlgEdit.DoModal();
//	if(iRet==IDOK){
//		m_lstPerson[iCurSel]=dlgEdit.GetGCustomert();
//		RefreshPersonListCtrl(m_lstPerson,iCurSel);
//	}
//
//	// TODO: 在此添加控件通知处理程序代码
//}
BOOL CCXYCardDlg::DoSaveFile(CString strFileName)
{
	CFile fileGCL(strFileName,CFile::modeWrite|CFile::modeCreate);
	CArchive ar(&fileGCL,CArchive::store);
	m_lstPerson.Serialize(ar);
	return TRUE;

}

//void CCXYCardDlg::OnBnClickedBnbeifen()
//{
//	CFileDialog dlgFile(FALSE,_T(".xyk"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|OFN_HIDEREADONLY,_T("信用卡(*.xyk)|*.xyk||"),NULL);
//	if(dlgFile.DoModal()!=IDOK){
//		
//		m_lstcPersonList.SetFocus();
//		return;
//	}
//	DoSaveFile(dlgFile.GetPathName());
//	// TODO: 在此添加控件通知处理程序代码
//}
BOOL CCXYCardDlg::DoLoadFile(CString strFileName)
{
	CFile fileGCL(strFileName,CFile::modeRead);
	CArchive ar(&fileGCL,CArchive::load);
	m_lstPerson.Serialize(ar);
	return TRUE;

}


//void CCXYCardDlg::OnBnClickedBnhuifu()
//{
//	MessageBox(L"查看文件时请先备份好自己的\n查看文件请到C\\XYKGL\\yewu查看",L"查看");
//	CFileDialog dlgFile(TRUE,_T(".xyk"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|OFN_HIDEREADONLY,_T("信用卡(*.xyk)|*.xyk||"),NULL);
//	if(dlgFile.DoModal()!=IDOK){
//		
//		m_lstcPersonList.SetFocus();
//		return;
//	}
//	if(DoLoadFile(dlgFile.GetPathName()))
//		RefreshPersonListCtrl(m_lstPerson,0);
//
//	// TODO: 在此添加控件通知处理程序代码
//}


void CCXYCardDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	DoSaveFile(m_s);

	// TODO: 在此处添加消息处理程序代码
}


//void CCXYCardDlg::OnBnClickedBnAddye()
//{
//	CYWYMT YWY;
//	YWY.DoModal();
//	// TODO: 在此添加控件通知处理程序代码
//}

//无效控件
void CCXYCardDlg::OnBnClickedBnBr()
{
	
	if(MessageBox(_T("是否退出而回到登录界面"),_T("退出"),MB_OKCANCEL)==IDOK){
    CDialogEx::OnOK();
	CDeng deng;
	deng.DoModal();
	}
	// TODO: 在此添加控件通知处理程序代码
}

//无效控件
void CCXYCardDlg::OnChangeEdiFund()
{

	
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。


	// TODO:  在此添加控件通知处理程序代码
}

//选中后显示图片
void CCXYCardDlg::OnItemchangedLiLiebiao(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	if(pNMLV->uNewState==(LVIS_SELECTED|LVIS_FOCUSED))
	{
		if(PathFileExists(m_lstPerson[GetCurSel()].GetImageHead())){
			CGCustomerList::ShowImage(this->m_hWnd,m_lstPerson[GetCurSel()].GetImageHead(),IDC_STA_HEAD);
		}
	}
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

//查找
void CCXYCardDlg::OnBnClickedBnFand()
{
	UpdateData(TRUE);
	m_lstFindG.RemoveAll();
	for(int i=0;i<m_lstPerson.GetSize();i++){
		CString tempMale=m_lstPerson[i].IsMale()?_T("男"):_T("女");
		if(m_lstPerson[i].GetName().Find(m_strFind)!=-1||tempMale.Find(m_strFind)!=-1||m_lstPerson[i].GetQQNo().Find(m_strFind)!=-1||m_lstPerson[i].GetBian().Find(m_strFind)!=-1)m_lstFindG.Add(m_lstPerson[i]);	
	}
	if(m_lstFindG.GetSize()>0)
		RefreshPersonListCtrl(m_lstFindG);
	else
		MessageBox(L"找不到对应的结果",L"提示");
	// TODO: 在此添加控件通知处理程序代码
}


void CCXYCardDlg::OnSave()
{
	OnBuBei();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnOpen()
{
	OnBuOpen1();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnClose()
{
	CDialogEx::OnOK();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnAdd()
{
	OnBuAdd1();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnDel()
{
	OnBuDel1();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnExer()
{
	OnBuRe1();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnYe()
{
OnBuYewu();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnShutdown()
{
	system("shutdown -s -t 60 -c 信用卡管理系统将在60秒后关机 ");
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::On32788()
{
	CAboutDlg ab;
	ab.DoModal();
	// TODO: 在此添加命令处理程序代码
}

//一键卸载
void CCXYCardDlg::OnXz()
{
	if(AfxMessageBox(_T("卸载文件后请自行把exe文件删去")_T("卸载"),MB_OKCANCEL)==IDOK)
	string hh;
	ofstream hh("C:\\XYKGL\\一键卸载.bat");
	hh<<"rd C:\\XYKGL\\Root C:\\XYKGL\\other C:\\XYKGL\\yewu C:\\XYKGL\\head"<<endl;
	hh<<"del /f/p C:\\XYKGL\\Root\\*.*"<<endl;
	hh<<"del /f/p C:\\XYKGL\\other\\*.*"<<endl;
	hh<<"del /f/p C:\\XYKGL\\yewu\\*.*"<<endl;
	hh<<"del /f/p C:\\XYKGL\\head\\*.*"<<endl;
	hh<<"rd C:\\XYKGL\\Root C:\\XYKGL\\other C:\\XYKGL\\yewu C:\\XYKGL\\head"<<endl;
	hh.close();
	system("start C:\\XYKGL\\一键卸载.bat");
    ofstream bb("一键删除.bat");
	bb<<"rd  C:\\XYKGL\\Root"<<endl;
	bb<<"rd  C:\\XYKGL"<<endl;
	bb<<"del /f/p CXYCard.exe"<<endl;
	bb<<"del /f/p 一键删除.bat"<<endl;
	bb.close();

	CDialogEx::OnOK();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnQs()
{
	system("shutdown -a");
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnJsq()
{
	//system("calc");
	ShellExecute(0,NULL,_T("calc.exe"),NULL,NULL,SW_NORMAL);
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::Ontxt()
{
	//system("notepad");
	ShellExecute(0,NULL,_T("notepad.exe"),NULL,NULL,SW_NORMAL);
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::Onbaidu()
{
   ShellExecute(0,NULL,_T("http://106.13.122.53/cord/"),NULL,NULL,SW_NORMAL);
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnLp()
{
	//system("psr.exe");
	ShellExecute(0,NULL,_T("psr.exe"),NULL,NULL,SW_NORMAL);
	// TODO: 在此添加命令处理程序代码
}


void CAboutDlg::OnYbiadu()
{
	// TODO: 在此添加命令处理程序代码
}
//转换类型函数
CString CCXYCardDlg::IntToString(int n)
{
CString strTemp;
strTemp.Format(_T("%d"),n);
return strTemp;

}

void CCXYCardDlg::CountOld()
{
int iyong=0;
int izhong=0;
int iold=0;
for(int i=0;i<m_lstPerson.GetSize();i++){
int n= _ttoi(m_lstPerson[i].GetNLing());
	if(n<=30)
		iyong++;
	if(n>30&&n<=65)
		izhong++;
	if(n>65&&n<=200)
		iold++;

	}
youg=iyong;
zhong=izhong;
old=iold;
	((CStatic*)GetDlgItem(IDC_STA_YOUG))->SetWindowTextW(IntToString(iyong));
	((CStatic*)GetDlgItem(IDC_STA_ZHONG))->SetWindowTextW(IntToString(izhong));
	((CStatic*)GetDlgItem(IDC_STA_OLD))->SetWindowTextW(IntToString(iold));
	
}

//void CAboutDlg::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//
//		// TODO: 在此处添加消息处理程序代码
//		// 不为绘图消息调用 CDialogEx::OnPaint()
//}


//void CCXYCardDlg::OnBnClickedBnTu()
//{
//	if(youg<0||youg>99999999&&m_lstPerson.GetSize()==0){
//	int m_iArray[3]={0,0,0};
//	COLDDlg op(m_iArray);
//	op.DoModal();
//	}else
//	{
//  int m_iArray[3]={youg,zhong,old};
//  	COLDDlg op(m_iArray);
//	op.DoModal();
//	}
//
//	// TODO: 在此添加控件通知处理程序代码
//}

//CXYCard调用不了MessageBox这个函数所以在这里定义后边调用；
void CCXYCardDlg::box(CString wen,CString title)
{
  MessageBox(wen,title);
	

}
//更新函数
void CAboutDlg::OnBnClickedBnUp()
{
	//取网页更新状态
    DWORD   flags;//上网方式 
    BOOL   m_bOnline=TRUE;//是否在线 
    m_bOnline=InternetGetConnectedState(&flags,0);   
    if(m_bOnline)//在线判断是否联网
	{


	CInternetSession ms(NULL,0);
	CHttpFile *bv=NULL;
	CString strs,strl;
	bv=(CHttpFile*)ms.OpenURL(L"http://106.13.122.53/v.html");//打开网页读取网页内容
	while (bv->ReadString(strs))
	{
		strl=strs;
	}
	bv->Close();
USES_CONVERSION;
 
LPSTR pStr = (LPSTR)strl.GetBuffer();
 
LPTSTR ptStr = A2T(pStr);//转换类型
 
strl.ReleaseBuffer();
//CString kk;
//kk.Format( _T("%s"), ptStr );
int kk = _ttoi(ptStr);
if(kk>=12)//版本号判断
	if(MessageBox(L"系统检测到新的版本请进行更新",L"更新提示",MB_OKCANCEL)==IDOK){
	ShellExecute(0,NULL,_T("http://106.13.122.53/cord/"),NULL,NULL,SW_NORMAL);
	}
	}
}


void CCXYCardDlg::OnShuo()
{//语音阅读提示使用说明
	m_read2.Speak(L"你好欢迎使用信用卡管理系统，你现在是在管理员页面，你可以添加新的业务员账号，使业务员得以登录，查看时，要注意备份自己的，");
	// TODO: 在此添加命令处理程序代码
}

//无效控件
void CAboutDlg::OnBnClickedMfclink1()
{
	// TODO: 在此添加控件通知处理程序代码
}


//void CAboutDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
//{
//	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
//
//	// TODO: 在此处添加消息处理程序代码
//}


/*void CCXYCardDlg::OnBnClickedMfccolorbutton1()
{
	UpdateData(true);
	// COLORREF color = m_ColorPicker.GetColor()
	CDialogEx::SetBackgroundColor(m_color.GetColor());

	// TODO: 在此添加控件通知处理程序代码
}*/
//工具栏，加载图标等
BOOL CCXYCardDlg::CreateToolBar()
{
	if(!m_ToolBar.CreateEx(this,TBSTYLE_FLAT,WS_CHILD|WS_VISIBLE|CBRS_TOP|CBRS_GRIPPER|CBRS_TOOLTIPS|CBRS_FLYBY|CBRS_SIZE_DYNAMIC)||!m_ToolBar.LoadToolBar(IDR_TOOLBAR2))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	
	}
	m_img.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);
	m_img.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_img.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_img.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_img.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	m_img.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_img.Add(AfxGetApp()->LoadIcon(IDI_ICON7));
	m_img.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	m_img.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_img);
	m_ToolBar.GetToolBarCtrl().SetBitmapSize(CSize(32,32));
	m_ToolBar.GetToolBarCtrl().SetButtonSize(CSize(60,60));
	m_ToolBar.SetButtonText(0,_T("添加"));
	m_ToolBar.SetButtonText(1,_T("删除"));
	m_ToolBar.SetButtonText(2,_T("查看"));
	m_ToolBar.SetButtonText(4,_T("备份"));//图标下文字
	m_ToolBar.SetButtonText(5,_T("修改"));
	m_ToolBar.SetButtonText(6,_T("统计"));
	m_ToolBar.SetButtonText(8,_T("帮助"));
	m_ToolBar.SetButtonText(9,_T("业务员"));
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_FIRST,0);
	CBitmap bm;
	bm.Detach();
	return true;
}

//图标的响应函数
void CCXYCardDlg::OnBuAdd1()
{

	CGCustomert psnDef;
	int zong=m_lstPerson.GetSize()+1;
	CString zon;
	zon.Format(L"0000%d",zong);//实现编号的自加，默认值
	psnDef.m_strBian=zon;
	TJYH dlgEdit(psnDef,this);
   int iRet=dlgEdit.DoModal();
   if(iRet==IDOK){
for (int i = 0; i < m_lstPerson.GetSize(); i++)
		{
			if(dlgEdit.GetGCustomert().GetBian()==m_lstPerson[i].GetBian())  //判断是否存在用户名
			{
				MessageBox(L"亲，编号不能一样",L"信用卡提示");
				return;
			}
		}
	   m_lstPerson.Add(dlgEdit.GetGCustomert());
	   RefreshPersonListCtrl(m_lstPerson,m_lstPerson.GetSize()-1);
	// TODO: 在此添加命令处理程序代码
}
}

void CCXYCardDlg::OnBuDel1()
{
		int iCurSel=GetCurSel();
	if(iCurSel<0)return;
	CString strHint;
	strHint.Format(_T("你确认删除名为%s的客户吗?"),m_lstPerson[iCurSel].GetName());
	if(MessageBox(strHint,_T("确认删除"),MB_YESNO|MB_ICONQUESTION)==IDYES)
	m_lstPerson.RemoveAt(iCurSel);
	RefreshPersonListCtrl(m_lstPerson,iCurSel);
}


void CCXYCardDlg::OnBuOpen1()
{
	//MessageBox(L"查看文件时请先备份好自己的\n查看文件请到C\\XYKGL\\yewu查看",L"查看");
	CFileDialog dlgFile(TRUE,_T(".xyk"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|OFN_HIDEREADONLY,_T("信用卡(*.xyk)|*.xyk||"),NULL);
	dlgFile.m_ofn.lpstrInitialDir=_T("C:\\XYKGL\\yewu\\");//设置默认路径
	if(dlgFile.DoModal()!=IDOK){
		
		m_lstcPersonList.SetFocus();
		return;
	}
	if(DoLoadFile(dlgFile.GetPathName()))
		RefreshPersonListCtrl(m_lstPerson,0);
}


void CCXYCardDlg::OnBuBei()
{
	CFileDialog dlgFile(FALSE,_T(".xyk"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|OFN_HIDEREADONLY,_T("信用卡(*.xyk)|*.xyk||"),NULL);
	dlgFile.m_ofn.lpstrInitialDir=_T("C:\\XYKGL\\yewu\\");
	if(dlgFile.DoModal()!=IDOK){
		
		m_lstcPersonList.SetFocus();
		return;
	}
	DoSaveFile(dlgFile.GetPathName());
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnBuRe1()
{
	int iCurSel=GetCurSel();
	if(iCurSel<0)return;
	TJYH dlgEdit(m_lstPerson[iCurSel],this);
	int iRet=dlgEdit.DoModal();
	if(iRet==IDOK){
		m_lstPerson[iCurSel]=dlgEdit.GetGCustomert();
		RefreshPersonListCtrl(m_lstPerson,iCurSel);
	}
}

//统计功能进行判断防止第一次运行时出现超大默认值
void CCXYCardDlg::OnBuTong1()
{
	if(youg<0||youg>99999999&&m_lstPerson.GetSize()==0){
	int m_iArray[3]={0,0,0};
	COLDDlg op(m_iArray);
	op.DoModal();
	}else
	{
  int m_iArray[3]={youg,zhong,old};
  	COLDDlg op(m_iArray);
	op.DoModal();
	}
}


void CCXYCardDlg::OnBuAbout1()
{
	CAboutDlg ab;
	ab.DoModal();
	// TODO: 在此添加命令处理程序代码
}

//业务员
void CCXYCardDlg::OnBuYewu()
{
    CYWYMT YWY;
	YWY.DoModal();
}

//实现右键鼠标弹出菜单
void CCXYCardDlg::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu m_p;
	m_p.LoadMenuW(IDR_MENU3);
	CMenu*m_s=m_p.GetSubMenu(0);
	m_s->TrackPopupMenu(TPM_LEFTBUTTON|TPM_LEFTALIGN,point.x,point.y,this);
	m_p.DestroyMenu();
}


void CCXYCardDlg::OnAdd3()
{
	OnBuAdd1();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnRe3()
{
	OnBuRe1();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnTong3()
{
	OnBuTong1();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::OnDel3()
{
	OnBuDel1();
	// TODO: 在此添加命令处理程序代码
}


void CCXYCardDlg::On32917()
{
	OnBuAbout1();
	// TODO: 在此添加命令处理程序代码
}

int opy=0;//设置函数用于后边调用时自加
 //时间调用的函数，通过类向导添加
void CCXYCardDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	::SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,::GetWindowLongPtr(GetSafeHwnd(),GWL_EXSTYLE)|WS_EX_LAYERED);
    this->SetLayeredWindowAttributes(0,opy,LWA_ALPHA);
	opy+=5;
	if(opy==255) //255为不透明就停止执行函数
	{
		KillTimer(1);
	}
	
	CDialogEx::OnTimer(nIDEvent);
}
//重画表格背景的函数实现隔行换色
void CCXYCardDlg::OnNMCustomdrawLiliebiao(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVCUSTOMDRAW  lplvcd = (LPNMLVCUSTOMDRAW)pNMHDR; 
    *pResult  =  CDRF_DODEFAULT;
     
    switch (lplvcd->nmcd.dwDrawStage) 
    { 
    case CDDS_PREPAINT : 
        { 
            *pResult = CDRF_NOTIFYITEMDRAW; 
            return; 
        } 
    case CDDS_ITEMPREPAINT: 
        { 
            *pResult = CDRF_NOTIFYSUBITEMDRAW; 
            return; 
        } 
    case CDDS_ITEMPREPAINT | CDDS_SUBITEM:
        { 
 
            int    nItem = static_cast<int>( lplvcd->nmcd.dwItemSpec );
            COLORREF clrNewTextColor, clrNewBkColor;
            clrNewTextColor=RGB(0,0,0);
            if( nItem%2 ==0 )
            {
                clrNewBkColor = RGB( 199,237,204); //偶数行背景色为灰色
            }
            else
            {
                clrNewBkColor = RGB( 245 ,245 ,245 ); //奇数行背景色为白色
            }
            lplvcd->clrText = clrNewTextColor;
            lplvcd->clrTextBk = clrNewBkColor;
 
            *pResult = CDRF_DODEFAULT;  
            return; 
        } 
	}
}

//文本阅读的对话框
void CCXYCardDlg::On32927()
{
	CRead rd;
	rd.DoModal();

	// TODO: 在此添加命令处理程序代码
}
