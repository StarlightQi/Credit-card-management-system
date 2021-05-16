// YeWugl.cpp : 实现文件
//业务员窗口类，用于分开管理员与业务员权限的窗口，代码差不多来自管理员窗口类

#include "stdafx.h"
#include "CXYCard.h"
#include "YeWugl.h"
#include "afxdialogex.h"
#include "TJYH.h"
#include "GCustomerList.h"
#include "GCustomert.h"
#include "Deng.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include  <io.h>
#include "OLDDlg.h"
using namespace std;
#define WM_SHOWTASK1 WM_USER+101
#define IDR_BAIDU 12
#define IDR_OPEN 13
#define IDR_SHUO 14
// CYeWugl 对话框

IMPLEMENT_DYNAMIC(CYeWugl, CDialogEx)

CYeWugl::CYeWugl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CYeWugl::IDD, pParent)
	, m_fund(_T(""))
	, m_checkbox1(FALSE)
{
if((_access( "C:\\XYKGL\\Root\\ret1.re", 0 )) == 0){
    ifstream infile; 
	string gg="C:\\XYKGL\\Root\\ret1.re";
    infile.open(gg.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
   ex1= atoi( s.c_str() );
   if(ex1==123)
   {
	   m_checkbox1=true;
   }
   else
   {
	   m_checkbox1=false;
   }

   infile.close();


	}
}
CYeWugl::CYeWugl(CString strDN):m_strDN(strDN)
{
}
CYeWugl::~CYeWugl()
{

}
int rr=1;

void CYeWugl::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lstcPersonList1);
	DDX_Text(pDX, IDC_Fu, m_fund);
	CGCustomert DL;




	//  DDX_Check(pDX, IDC_CHECK1, m_exit1);

	DDX_Check(pDX, IDC_CHECK1, m_checkbox1);
}


BEGIN_MESSAGE_MAP(CYeWugl, CDialogEx)
	ON_MESSAGE(WM_SHOWTASK1,OnShowTask)
	ON_WM_DESTROY()
	ON_EN_CHANGE(IDC_Fu, &CYeWugl::OnChangeFu)
	ON_WM_PAINT()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CYeWugl::OnItemchangedList1)
	ON_BN_CLICKED(IDC_BN_YFUND, &CYeWugl::OnBnClickedBnYfund)
	ON_COMMAND(ID_YTC, &CYeWugl::OnYtc)
	ON_COMMAND(ID_YADD, &CYeWugl::OnYadd)
	ON_COMMAND(ID_YEXET, &CYeWugl::OnYexet)
	ON_COMMAND(ID_YSHOWN, &CYeWugl::OnYshown)
	ON_COMMAND(ID_YQS, &CYeWugl::OnYqs)
	ON_COMMAND(ID_YAble, &CYeWugl::OnYable)
	ON_COMMAND(ID_Yjis, &CYeWugl::OnYjis)
	ON_COMMAND(ID_luping, &CYeWugl::Onluping)
	ON_COMMAND(ID_jispb, &CYeWugl::Onjispb)
	ON_COMMAND(ID_Ybiadu, &CYeWugl::OnYbiadu)
	ON_COMMAND(ID_Yshuo, &CYeWugl::OnYshuo)
	ON_COMMAND(ID_BU_NEW2, &CYeWugl::OnBuNew2)
	ON_COMMAND(ID_BU_RE2, &CYeWugl::OnBuRe2)
	ON_COMMAND(ID_BU_TONG2, &CYeWugl::OnBuTong2)
	ON_COMMAND(ID_BU_ABOUT2, &CYeWugl::OnBuAbout2)	
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_32922, &CYeWugl::On32922)
	ON_COMMAND(ID_RE4, &CYeWugl::OnRe4)
	ON_COMMAND(ID_32925, &CYeWugl::On32925)
	ON_COMMAND(ID_32924, &CYeWugl::On32924)
	ON_WM_SYSCOMMAND()
	ON_WM_TIMER()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST1, &CYeWugl::OnNMCustomdrawList1)
END_MESSAGE_MAP()


// CYeWugl 消息处理程序


//void CYeWugl::OnBnClickedBnYtian()
//{
//
//    CGCustomert psnDef;
//	TJYH dlgEdit(psnDef,this);
//   int iRet=dlgEdit.DoModal();
//   if(iRet==IDOK){  
//	   m_LP.Add(dlgEdit.GetGCustomert());
//	   RPC(m_LP,m_LP.GetSize()-1);
//   }
//
//	// TODO: 在此添加控件通知处理程序代码
//}
void CYeWugl::IP(void){
	m_lstcPersonList1.SetExtendedStyle(m_lstcPersonList1.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_lstcPersonList1.InsertColumn(0,_T("编号"),LVCFMT_CENTER,100);
	m_lstcPersonList1.InsertColumn(1,_T("姓名"),LVCFMT_CENTER,80);
	m_lstcPersonList1.InsertColumn(2,_T("性别"),LVCFMT_CENTER,70);
	m_lstcPersonList1.InsertColumn(3,_T("手机号"),LVCFMT_CENTER,120);
	m_lstcPersonList1.InsertColumn(4,_T("QQ号"),LVCFMT_CENTER,120);
	m_lstcPersonList1.InsertColumn(5,_T("状态"),LVCFMT_CENTER,120);
	m_lstcPersonList1.InsertColumn(6,_T("额度"),LVCFMT_CENTER,60);
	m_lstcPersonList1.InsertColumn(7,_T("公司"),LVCFMT_CENTER,240);
	m_lstcPersonList1.InsertColumn(8,_T("年龄"),LVCFMT_CENTER,80);
	m_lstcPersonList1.InsertColumn(9,_T("备注"),LVCFMT_CENTER,360);


}
int CYeWugl::GCS(void)
{
	POSITION pos =m_lstcPersonList1.GetFirstSelectedItemPosition();
	return m_lstcPersonList1.GetNextSelectedItem(pos);


}
void CYeWugl::RPC(CGCustomerList& psnList,int iC)
{
int iLastSel=GCS();
m_lstcPersonList1.DeleteAllItems();
for(int i=0;i<psnList.GetSize();i++){
	m_lstcPersonList1.InsertItem(i,psnList[i].GetBian());
	m_lstcPersonList1.SetItemText(i,1,psnList[i].GetName());
	m_lstcPersonList1.SetItemText(i,2,psnList[i].IsMale()?_T("女"):_T("男"));
	m_lstcPersonList1.SetItemText(i,3,psnList[i].GetPhoneNo());
	m_lstcPersonList1.SetItemText(i,4,psnList[i].GetQQNo());
	m_lstcPersonList1.SetItemText(i,5,psnList[i].GetZhang()?_T("未按时还款"):_T("已按时还款"));
	m_lstcPersonList1.SetItemText(i,6,psnList[i].GetEd());
	m_lstcPersonList1.SetItemText(i,7,psnList[i].GetGong());
	m_lstcPersonList1.SetItemText(i,8,psnList[i].GetNLing());
	m_lstcPersonList1.SetItemText(i,9,psnList[i].GetBz());
}
	if(iC<0){
		if(iLastSel<0)
			iC=psnList.GetSize()>0?0:-1;
		else
			iC=min(psnList.GetSize()-1,iLastSel);
	}
	else{
		iC=min(psnList.GetSize()-1,iC);
	}
	if(iC>=0){
		m_lstcPersonList1.SetFocus();
		m_lstcPersonList1.SetItemState(iC,LVIS_SELECTED,LVIS_SELECTED);
	}
	if(m_LP.GetCount()!=0&&PathFileExists(m_LP[iC].GetImageHead())){
	CGCustomerList::ShowImage(this->m_hWnd,m_LP[GCS()].GetImageHead(),IDC_STA_YHEAD);
	}
   CountOld();
}

//void CYeWugl::OnBnClickedBnYxiu()
//{
//	int iC=GCS();
//	if(iC<0)return;
//	TJYH dlgEdit(m_LP[iC],this);
//	int iRet=dlgEdit.DoModal();
//	if(iRet==IDOK){
//		m_LP[iC]=dlgEdit.GetGCustomert();
//		RPC(m_LP,iC);
//	}
//	// TODO: 在此添加控件通知处理程序代码
//}

BOOL CYeWugl::DS(CString sn)
{
	CFile fi(sn,CFile::modeWrite|CFile::modeCreate);
	CArchive ar(&fi,CArchive::store);
	m_LP.Serialize(ar);
	return TRUE;
}
BOOL CYeWugl::HF(CString hf)
{
	CFile fi(hf,CFile::modeRead);
	CArchive ar(&fi,CArchive::load);
	m_LP.Serialize(ar);
	return TRUE;
}
void CYeWugl::OnDestroy()
{
	CDialogEx::OnDestroy();
	DS(m_sF);
	// TODO: 在此处添加消息处理程序代码
}



void CYeWugl::OnChangeFu()
{
}


void CYeWugl::OnPaint()
{
	CPaintDC   dc1(this);   
          CRect   rect;   
          GetClientRect(&rect);   
          CDC   dcMem;   
          dcMem.CreateCompatibleDC(&dc1);   
          CBitmap   bmpBackground;   
          bmpBackground.LoadBitmap(IDB_BITMAP5);   
                  //IDB_BITMAP是你自己的图对应的ID   
          BITMAP   bitmap;   
          bmpBackground.GetBitmap(&bitmap);   
          CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
          dc1.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);   
	     CPaintDC dc(this); // device context for painting
		if(m_LP.GetCount()!=0&&PathFileExists(m_LP[GCS()].GetImageHead())){
		CGCustomerList::ShowImage(this->m_hWnd,m_LP[GCS()].GetImageHead(),IDC_STA_YHEAD);
	}
	
		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CDialogEx::OnPaint()
}


void CYeWugl::OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	if(pNMLV->uNewState==(LVIS_SELECTED|LVIS_FOCUSED))
	{
		if(PathFileExists(m_LP[GCS()].GetImageHead())){
			CGCustomerList::ShowImage(this->m_hWnd,m_LP[GCS()].GetImageHead(),IDC_STA_YHEAD);
		}
	}
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CYeWugl::OnBnClickedBnYfund()
{
	UpdateData(TRUE);
	m_lstFindY.RemoveAll();
	for(int i=0;i<m_LP.GetSize();i++){
		CString tempMale=m_LP[i].IsMale()?_T("男"):_T("女");
		if(m_LP[i].GetName().Find(m_fund)!=-1||tempMale.Find(m_fund)!=-1||m_LP[i].GetQQNo().Find(m_fund)!=-1||m_LP[i].GetBian().Find(m_fund)!=-1)m_lstFindY.Add(m_LP[i]);	
	}
	if(m_lstFindY.GetSize()>0)
		RPC(m_lstFindY);
	else
	MessageBox(L"找不到对应的结果",L"提示");
	// TODO: 在此添加控件通知处理程序代码
}


void CYeWugl::OnYtc()
{
	CDialogEx::OnOK();
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::OnYadd()
{
	OnBuNew2();
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::OnYexet()
{
	OnBuRe2();
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::OnYshown()
{
	system("shutdown -s -t 60 -c 信用卡管理系统系统将在60秒后关机");
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::OnYqs()
{
	system("shutdown -a");
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::OnYable()
{
	MessageBox(L"信用卡管理系统");
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::OnYjis()
{
		
			ShellExecute(0,NULL,_T("calc"),NULL,NULL,SW_NORMAL);
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::Onluping()
{
		
			ShellExecute(0,NULL,_T("psr.exe"),NULL,NULL,SW_NORMAL);
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::Onjispb()
{

	ShellExecute(0,NULL,_T("notepad"),NULL,NULL,SW_NORMAL);
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::OnYbiadu()
{
	ShellExecute(0,NULL,_T("http://106.13.122.53/cord/"),NULL,NULL,SW_NORMAL);
	// TODO: 在此添加命令处理程序代码
}


CString CYeWugl::IntToString(int n)
{
CString strTemp;
strTemp.Format(_T("%d"),n);
return strTemp;

}

void CYeWugl::CountOld()
{
int iyong=0;
int izhong=0;
int iold=0;
for(int i=0;i<m_LP.GetSize();i++){
int n= _ttoi(m_LP[i].GetNLing());
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
	((CStatic*)GetDlgItem(IDC_STA_YYOUG))->SetWindowTextW(IntToString(iyong));
	((CStatic*)GetDlgItem(IDC_STA_YZHONG))->SetWindowTextW(IntToString(izhong));
	((CStatic*)GetDlgItem(IDC_STA_YOLD))->SetWindowTextW(IntToString(iold));
	
}

//void CYeWugl::OnBnClickedBnTong()
//{
//	if(youg<0||youg>99999999&&m_LP.GetSize()==0){
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


void CYeWugl::OnYshuo()
{
	MessageBox(L"欢迎使用",L"使用说明");
	// TODO: 在此添加命令处理程序代码
}

//对话框打开时载入信息
BOOL CYeWugl::OnInitDialog()
{
	
	::SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,::GetWindowLongPtr(GetSafeHwnd(),GWL_EXSTYLE)|WS_EX_LAYERED);
    this->SetLayeredWindowAttributes(0,0,LWA_ALPHA);
	SetTimer(1,20,NULL);
	CDialogEx::OnInitDialog();
	CreateToolBar1();
		if(rr==1){
	//读取文件数据
	ifstream infile; 
	string gg="C:\\XYKGL\\Root\\Yname.txt";
    infile.open(gg.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
	
     DLN = s.c_str();
    infile.close();  
	rr++;
	}
	WCHAR szCurPath[_MAX_PATH];
	GetCurrentDirectory(MAX_PATH,szCurPath);
	CString SaveName=_T("C:\\XYKGL\\yewu\\")+DLN+_T(".xyk");
	 IP();
	m_sF.Format(SaveName,szCurPath);//进行变量命名，不同的业务员有不同的文件
	

	
	//BUG添加新用户或进行修改后如果不关掉就不会保存
	if(PathFileExists(m_sF)){
		HF(m_sF);
		RPC(m_LP);
	}

    m_nid1.cbSize  = (DWORD)sizeof(NOTIFYICONDATA);
    m_nid1.hWnd    = this->m_hWnd;
    m_nid1.uID     = IDR_MAINFRAME;
    m_nid1.uFlags  = NIF_ICON | NIF_MESSAGE | NIF_TIP ;
    m_nid1.uCallbackMessage = WM_SHOWTASK1;          // 自定义的消息名称需在头部声明
    m_nid1.hIcon   = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));  //获取图标资源       
	wcscpy_s(m_nid1.szTip, _T("信用卡管理系统"));  // 信息提示条
    Shell_NotifyIcon(NIM_ADD, &m_nid1);                // 在托盘区添加图标
	

	

	return TRUE;  // return TRUE unless you set the focus to a control

	// 异常: OCX 属性页应返回 FALSE
}

LRESULT CYeWugl::OnShowTask(WPARAM wparam,LPARAM lParam){
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
						 menu.AppendMenu(MFT_STRING, IDR_BAIDU,L"百度");
						 menu.AppendMenu(MF_STRING, WM_DESTROY,L"退出");

                          SetForegroundWindow();
                   
						  int xx=TrackPopupMenu(menu,TPM_RETURNCMD,lpoint->x,lpoint->y,NULL,this->m_hWnd,NULL);
						   if(xx==WM_DESTROY){ 
							   CDialogEx::OnOK();
						   }
						   if(xx==IDR_BAIDU){
						   ShellExecute(0,NULL,_T("https://www.baidu.com/"),NULL,NULL,SW_NORMAL);
						   }//打开网页代码
						   if(xx==IDR_OPEN) {
							   this->ShowWindow(SW_SHOWNORMAL);

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


BOOL CYeWugl::CreateToolBar1()
{
	if(!m_ToolBar1.CreateEx(this,TBSTYLE_FLAT,WS_CHILD|WS_VISIBLE|CBRS_TOP|CBRS_GRIPPER|CBRS_TOOLTIPS|CBRS_FLYBY|CBRS_SIZE_DYNAMIC)||!m_ToolBar1.LoadToolBar(IDR_TOOLBAR3))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	
	}
	m_img1.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);
	m_img1.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_img1.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_img1.Add(AfxGetApp()->LoadIcon(IDI_ICON7));
	m_img1.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	m_ToolBar1.GetToolBarCtrl().SetImageList(&m_img1);
	m_ToolBar1.GetToolBarCtrl().SetBitmapSize(CSize(32,32));
	m_ToolBar1.GetToolBarCtrl().SetButtonSize(CSize(60,60));
	m_ToolBar1.SetButtonText(0,_T("添加"));
	m_ToolBar1.SetButtonText(1,_T("修改"));
	m_ToolBar1.SetButtonText(2,_T("统计"));
	m_ToolBar1.SetButtonText(3,_T("关于"));
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_FIRST,0);
	CBitmap bm;
	bm.Detach();
	return true;
}

void CYeWugl::OnBuNew2()
{
	  CGCustomert psnDef;
	int zong1=m_LP.GetSize()+1;
	CString zon1;
	zon1.Format(L"0000%d",zong1);//实现编号的自加，默认值
	psnDef.m_strBian=zon1;
	TJYH dlgEdit(psnDef,this);
   int iRet=dlgEdit.DoModal();
   if(iRet==IDOK){  
for (int i = 0; i <m_LP.GetSize(); i++)
		{
			if(dlgEdit.GetGCustomert().GetBian()==m_LP[i].GetBian())  //判断是否存在用户名
			{
				MessageBox(L"亲，编号不能一样",L"信用卡提示");
				return;
			}
		}

	   m_LP.Add(dlgEdit.GetGCustomert());
	   RPC(m_LP,m_LP.GetSize()-1);
   }

}


void CYeWugl::OnBuRe2()
{	
	int iC=GCS();
	if(iC<0)return;
	TJYH dlgEdit(m_LP[iC],this);
	int iRet=dlgEdit.DoModal();
	if(iRet==IDOK){
		m_LP[iC]=dlgEdit.GetGCustomert();
		RPC(m_LP,iC);
	}
}


void CYeWugl::OnBuTong2()
{
		
		if(youg<0||youg>99999999&&m_LP.GetSize()==0){
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


void CYeWugl::OnBuAbout2()
{
	MessageBox(L"欢迎使用");
}

/*
void CYeWugl::OnBnClickedMfccolorbutton1()
{
	UpdateData(true);
	// COLORREF color = m_ColorPicker.GetColor()
	CDialogEx::SetBackgroundColor(m_color1.GetColor());
}
*/

void CYeWugl::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
		CMenu m_p;
	m_p.LoadMenuW(IDR_MENU4);
	CMenu*m_s=m_p.GetSubMenu(0);
	m_s->TrackPopupMenu(TPM_LEFTBUTTON|TPM_LEFTALIGN,point.x,point.y,this);
	m_p.DestroyMenu();
	// TODO: 在此处添加消息处理程序代码
}

//添加
void CYeWugl::On32922()
{
	OnBuNew2();
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::OnRe4()
{
	OnBuRe2();
	// TODO: 在此添加命令处理程序代码
}

//统计
void CYeWugl::On32925()
{
	OnBuTong2();
	// TODO: 在此添加命令处理程序代码
}

//关于
void CYeWugl::On32924()
{
	MessageBox(L"欢迎使用信用卡管理系统",L"信用卡管理系统");
	// TODO: 在此添加命令处理程序代码
}


void CYeWugl::OnSysCommand(UINT nID, LPARAM lParam)
{
	UpdateData(true);
	//更新复选框写入记录；
		UpdateData(true);
	//更新复选框写入记录；
	ofstream out2("C:\\XYKGL\\Root\\ret1.re");
	if(m_checkbox1){
	out2<<"123";
	}else
	{
		out2<<"321";
	}
	out2.close();

	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{

	}else if((nID & 0xFFF0)==SC_CLOSE&&!m_checkbox1){//按关闭后最小化
		ShowWindow(SW_HIDE);//隐藏窗口
		Shell_NotifyIcon(NIM_ADD,&m_nid1);//添加到系统托盘图标
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

int opy1=0;
void CYeWugl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	::SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,::GetWindowLongPtr(GetSafeHwnd(),GWL_EXSTYLE)|WS_EX_LAYERED);
    this->SetLayeredWindowAttributes(0,opy1,LWA_ALPHA);
	opy1+=5;
	if(opy1==255)
	{
		KillTimer(1);
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CYeWugl::OnNMCustomdrawList1(NMHDR *pNMHDR, LRESULT *pResult)
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
