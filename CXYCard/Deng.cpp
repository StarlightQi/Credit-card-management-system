// Deng.cpp : 实现文件
//登录界面类

#include "stdafx.h"
#include "CXYCard.h"
#include "Deng.h"
#include "afxdialogex.h"
#include "CXYCardDlg.h"
#include "YeWugl.h"
#include "YWYMT.h"
#include "YeList.h"
#include "Yewu.h"
#include "Yewudg.h"
#include "YeWugl.h"
#include "fstream"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include  <io.h>
#include <afxinet.h>
//#include <windows.h>
using namespace std;
#include <Wininet.h>
#pragma comment (lib, "Wininet.lib")
using namespace std;
// CDeng 对话框

IMPLEMENT_DYNAMIC(CDeng, CDialogEx)



int hn=0;
CDeng::CDeng(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeng::IDD, pParent)
{

//判断文件是否为空
if( (_access( "C:\\XYKGL\\Root\\jiyi.op", 0 )) == -1 ){
	    ofstream out("C:\\XYKGL\\Root\\jiyi.op");
        out.close();
}
	fstream file;
char ch;
//判断文件里边的内容是否为空
file.open("C:\\XYKGL\\Root\\jiyi.op",ios::in);
while (!file.eof()){
ch=file.get();//
if(ch=='\n')
   hn+=1; //行数加1
}
	if((_access( "C:\\XYKGL\\Root\\jiyi.op", 0 ))==0 &&hn!=0){
	m_checkBox1=true;//记录复选框的转态
	ifstream infile; 
	//记录密码
	string gg="C:\\XYKGL\\Root\\jiyi.op";
    infile.open(gg.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
    string s,g;
    while(!getline(infile,s))
    {
        cout<<s<<endl;
    }
       while(getline(infile,g))
    {
        cout<<g<<endl;
    }
	
     DLN = s.c_str();
	 PS = g.c_str();
	 CString HD=PS;//设置默认值，打开后就会记住密码了
	 m_strDName=DLN;
	 m_strDPoss=HD;
	  infile.close();  

	}
	file.close();

    
}
CDeng::~CDeng()
{
}

void CDeng::DoDataExchange(CDataExchange* pDX)
{






	pyi=0;                                            //进行判断如不为指定数值就会关闭对话框；
	CDialogEx::DoDataExchange(pDX);                   //  DDX_Control(pDX, IDC_ED_NAME, m_strDName);                                                     
	DDX_Text(pDX, IDC_ED_NAME, m_strDName);
	DDX_Text(pDX, IDC_ED_POSS, m_strDPoss);
	//每次打开登录对话框都会载入记录账号的文件
	WCHAR YPath[_MAX_PATH];
	GetCurrentDirectory(MAX_PATH,YPath);
	wen.m_strD.Format(_T("C:\\XYKGL\\Root\\业务员.ywy"),YPath);
	if(PathFileExists(wen.m_strD)){
		wen.DL(wen.m_strD);//调用CYWYMT业务员类的载入函数
		d(wen.m_lstYe);//刷新列表
	}

	//判断文件的长度判断第一次是否为添加root成员就退出还是数据成员不完整
	//安全检查，后边完善了这里就不算太重要了
	ifstream is;
	is.open ("C:\\XYKGL\\Root\\业务员.ywy", ios_base::binary );
	is.seekg (0, ios_base::end);
	streampos fp = is.tellg(); 
	if (int(fp)>20){
		if(wen.m_lstYe[0].GetYBian()!="root"){
			pyi=1;
			MessageBox(L"系统读出您的内存数据出现异常，\n请对业务员文件进行删除处理\n请到C\\XYKGL\\Root\\业务员.ywy",L"信用卡系统提示");
			ofstream hh("C:\\XYKGL\\Root\\del.bat");//登录次数检验
			hh<<"echo off"<<endl;
			hh<<"start taskkill /f /im CXYCard.exe"<<endl;
			hh<<"echo 删除业务员.ywy失败是否打开目录"<<endl;

			hh<<"set /p a=请输入你的选择(y打开):"<<endl;
			hh<<"if /i '%a%'=='y' start C:\\XYKGL\\Root\\"<<endl;
			hh<<"del/f/q/s C:\\XYKGL\\*.*"<<endl;
			hh.close();
			system("start C:\\XYKGL\\Root\\del.bat");
		}
	}else
	{
		MessageBox(L"系统读出您的内存数据出现异常，\n请对业务员文件进行删除处理\n请到C\\XYKGL\\Root\\业务员.ywy",L"信用卡系统提示"); 
		ofstream hh("C:\\XYKGL\\Root\\del.bat");//登录次数检验
		hh<<"echo off"<<endl;
		hh<<"start taskkill /f /im CXYCard.exe"<<endl;
		hh<<"echo 删除业务员.ywy失败是否打开目录"<<endl;
		hh<<"set /p a=请输入你的选择(y打开):"<<endl;
		hh<<"if /i '%a%'=='y' start C:\\XYKGL\\Root\\"<<endl;
		hh<<"del/f/q/s C:\\XYKGL\\*.*"<<endl;
		hh.close();
		system("start C:\\XYKGL\\Root\\del.bat");

		pyi=1;
	}
	DDX_Check(pDX, IDC_CHECK1, m_checkBox1);

	DDX_Control(pDX, IDC_BUTTON1, m_BtnTest);
	DDX_Control(pDX, IDC_BUTTON2, m_bt3);
}
void::CDeng::d(CYeList&a)
{
	 
	if(qh.GetSize()!=0){
	if(m_strDName.GetLength()>2)
	FU=a[0].GetYQQNo();
	}
else
{
	FU="密码错误";
}
}

BEGIN_MESSAGE_MAP(CDeng, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDeng::OnBnClickedOk)
	ON_EN_KILLFOCUS(IDC_ED_NAME, &CDeng::OnEnKillfocusEdName)
	ON_EN_CHANGE(IDC_ED_POSS, &CDeng::OnEnChangeEdPoss)
	ON_EN_CHANGE(IDC_ED_NAME, &CDeng::OnEnChangeEdName)
	ON_BN_CLICKED(IDC_CHECK1, &CDeng::OnBnClickedCheck1)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_EN_KILLFOCUS(IDC_ED_POSS, &CDeng::OnEnKillfocusEdPoss)
	ON_EN_UPDATE(IDC_ED_NAME, &CDeng::OnEnUpdateEdName)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, &CDeng::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeng::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDeng 消息处理程序

int i=0;
int b=0;
void CDeng::OnBnClickedOk()
{
	   CString F=m_strDName;
	   std::string F2= CT2A(F.GetBuffer());
	   CString F3=m_strDPoss;
	   std::string F4= CT2A(F3.GetBuffer());
	   ofstream out2("C:\\XYKGL\\Root\\jiyi.op");

	if(pyi==1)
	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码
	//登录
	if(m_strDName.GetLength()>3){
	if(m_strDPoss.GetLength()>=6){
		//root管理员登录
	if(m_strDName=="root"&& m_strDPoss==FU){
     //记住登录成功后几张密码
   	if(m_checkBox1)
	{
	   out2<<F2<<endl;
	   out2<<F4;
	   out2.close();
	}else
	{
		out2<<"";
	}
	SetTimer(1,45,NULL);
}
else{
if(m_strDPoss==FU){
	//记住登录成功后几张密码
	   if(m_checkBox1)
	{
	   out2<<F2<<endl;
	   out2<<F4;
	   out2.close();
	}else
	{
		out2<<"";
	}

		//CDialogEx::OnOK();
		//获取输入用户
		CString F=m_strDName;
	   std::string F2= CT2A(F.GetBuffer());
	   ofstream out("C:\\XYKGL\\Root\\Yname.txt");
	   out<<F2;
	   out.close();
	   //弹窗
	   SetTimer(1,45,NULL);

		}else
{
	MessageBox(_T("密码错误您只有3次尝试机会"),_T("警告"));
	i++;
	if(i==3){
		AfxMessageBox(L"您的3次输入机会已经用完");
	ifstream infile; 
	  string gg="C:\\XYKGL\\Root\\CS.batr";
     infile.open(gg.data());   //将文件流对象与文件连接起来 
     assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
     string s;
     while(getline(infile,s))
     {
          cout<<s<<endl;
      }
      b= atoi( s.c_str() );
  
		if(b<4)
		AfxMessageBox(L"温馨提示：默认管理员账户root，密码123456");
		CDialogEx::OnOK();
	infile.close();
	}
		}
	}
	}else{AfxMessageBox(L"密码要大于等于6位字符");}
	}else{AfxMessageBox(L"编号要大于3位字符");}


if( (_access( "C:\\XYKGL\\Root\\CS.batr", 0 )) == -1 )//判断文件是否存在；
{  ofstream out("C:\\XYKGL\\Root\\CS.batr");//登录次数检验

   out.close();
}else
{
	 ifstream infile; 
	string gg="C:\\XYKGL\\Root\\CS.batr";
    infile.open(gg.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
	//每登录一次就自加一次；
   b= atoi( s.c_str() );
   b++;
   infile.close();
	
	ofstream out("C:\\XYKGL\\Root\\CS.batr");//登录次数检验
	   out<<b;
	   out.close();



}
}
//查找密码的重要函数，由于编号是唯一的所以后边用查找函数时只会有列被放入到动态数组中所以a[0]就可以获得对应账号的密码了
void CDeng::bh()
{
	qh.RemoveAll();
	for(int i=0;i<wen.m_lstYe.GetSize();i++){
	if(wen.m_lstYe[i].GetYBian().Find(m_strDName)!=-1){
	qh.Add(wen.m_lstYe[i]);
	}
	if(qh.GetSize()>0)
		d(qh);
	}

}
//失去焦点时触发，防止密码不受控制
void CDeng::OnEnKillfocusEdName()
{
	UpdateData(TRUE);
	bh();
	// TODO: 在此添加控件通知处理程序代码
}


void CDeng::OnEnChangeEdPoss()
{
	UpdateData(TRUE);
	bh();
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}


void CDeng::OnEnChangeEdName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	UpdateData(TRUE);
	bh();
	//m_DN=m_strDName;
	// TODO:  在此添加控件通知处理程序代码
}

//点击后刷新按键状态；
void CDeng::OnBnClickedCheck1()
{  
	UpdateData(TRUE);
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CDeng::OnInitDialog()
{
	 CDialogEx::SetBackgroundColor(RGB(0, 204, 221));
	CDialogEx::OnInitDialog();
	//载入对话框时触发这个寻找事件不如登录不了
	UpdateData(TRUE);
	bh();
	//去掉边框代码
	LONG IStyle = ::GetWindowLong(this->m_hWnd,GWL_STYLE);
    ::SetWindowLong(this->m_hWnd, GWL_STYLE, IStyle&~WS_CAPTION);
    ::SetWindowPos(this->m_hWnd,NULL,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE|SWP_NOZORDER
        |SWP_NOACTIVATE|SWP_FRAMECHANGED);

HICON m_IconBtn=AfxGetApp()->LoadIcon(IDI_ICON9);//导入Icon资源，利用m_hIconBtn来存储句柄。
  m_BtnTest.SetIcon(m_IconBtn); //为按钮添加图标

HICON m_IconBtn1=AfxGetApp()->LoadIcon(IDI_ICON10);//导入Icon资源，利用m_hIconBtn来存储句柄。
  m_bt3.SetIcon(m_IconBtn1);  //为按钮添加图标


	/*::SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,::GetWindowLongPtr(GetSafeHwnd(),GWL_EXSTYLE)|WS_EX_LAYERED);
    this->SetLayeredWindowAttributes(0,0,LWA_ALPHA);*/

	//获取网页更新状态检测更新
	DWORD   flags;//上网方式 
    BOOL   m_bOnline=TRUE;//是否在线 
    m_bOnline=InternetGetConnectedState(&flags,0);   
    if(m_bOnline)//在线判断是否联网
	{
	CInternetSession ms(NULL,0);
	CHttpFile *bv=NULL;
	CString strs,strl;
	bv=(CHttpFile*)ms.OpenURL(L"http://106.13.122.53/v.html");
	while (bv->ReadString(strs))
	{
		strl=strs;
	}
	bv->Close();
USES_CONVERSION;
 
LPSTR pStr = (LPSTR)strl.GetBuffer();
 
LPTSTR ptStr = A2T(pStr); //转换类型
 
strl.ReleaseBuffer();
//CString kk;
//kk.Format( _T("%s"), ptStr );
	CString gg;
    gg.Format( _T("系统检测到新的版本请进行更新版本号为%s"), ptStr );
int kk = _ttoi(ptStr);
if(kk>=16)

	if(MessageBox(gg,L"更新提示",MB_OKCANCEL)==IDOK){
	ShellExecute(0,NULL,_T("http://106.13.122.53/cord/"),NULL,NULL,SW_NORMAL);
	}
	}
	




	return TRUE;
}

//HBRUSH CDeng::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//
//
//
//	/*if(pWnd==this)
//	{
//		
//	}
//	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
//	*/
//	return hbr;
//}


void CDeng::OnPaint()
{
 
 CPaintDC   dc(this);   
 
}

//设置登录特效，登录后边框容器的宽度不断减少当到0时就停止进入相应的界面
int xwei=600,xkuan=600;//x轴的位置，x轴的宽度
void CDeng::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MoveWindow(xwei,300,xkuan,485);
	xwei+=30;
	xkuan-=30;
	if(xkuan<0)
	{
	KillTimer(1);
	if(m_strDName=="root"){
	CDialogEx::OnOK();
	CCXYCardDlg guan;
	guan.DoModal();
	}else
	{
		CDialogEx::OnOK();
		CYeWugl yed;
		CYeWugl m;
     	yed.DoModal();
	}
	}

	CDialogEx::OnTimer(nIDEvent);
}

 //失焦刷新控件转态值

void CDeng::OnEnKillfocusEdPoss()
{
		UpdateData(TRUE);
	    bh();
	// TODO: 在此添加控件通知处理程序代码
}

//数据更新刷新控件转态值
void CDeng::OnEnUpdateEdName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。

		UpdateData(TRUE);
	    bh();

	// TODO:  在此添加控件通知处理程序代码
}

//重写文字背景改为透明的
HBRUSH CDeng::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
 
 if(nCtlColor == CTLCOLOR_STATIC )
 {
  pDC->SetBkMode(TRANSPARENT);//设置背景透明
  //pDC->SetTextColor(RGB(255,255,0));//设置字体为黄色
  return (HBRUSH)::GetStockObject(NULL_BRUSH);
 }
 // TODO:  假设默认的不是所需画笔，则返回还有一个画笔
return NULL;
}

//关闭按钮
void CDeng::OnBnClickedButton1()
{
	
	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码
}

//最小化按钮
void CDeng::OnBnClickedButton2()
{
	PostMessage(WM_SYSCOMMAND,SC_MINIMIZE,0);

	// TODO: 在此添加控件通知处理程序代码
}
