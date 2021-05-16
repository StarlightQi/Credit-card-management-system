// YWYMT.cpp : 实现文件
//账号管理类（业务员）用于管理账号，之前登录的很多函数都是调用这里的

#include "stdafx.h"
#include "CXYCard.h"
#include "YWYMT.h"
#include "afxdialogex.h"
#include "YeList.h"
#include "Yewudg.h"
#include "Deng.h"
#include "fstream"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include  <io.h>
using namespace std;
// CYWYMT 对话框
int q=10;//用来判断是否点击了添加按键
IMPLEMENT_DYNAMIC(CYWYMT, CDialogEx)

CYWYMT::CYWYMT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CYWYMT::IDD, pParent)
	, m_FU(_T(""))
{
CDialogEx::SetBackgroundColor(RGB(155,170,190));
}

CYWYMT::~CYWYMT()
{
}
int oo=1;
void CYWYMT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_lstcPersonListy);
	DDX_Text(pDX, IDC_ED_FU, m_FU);
}


BEGIN_MESSAGE_MAP(CYWYMT, CDialogEx)
	ON_BN_CLICKED(IDC_BN_YMT, &CYWYMT::OnBnClickedBnYmt)
	ON_BN_CLICKED(IDD_BN_YMS, &CYWYMT::OnBnClickedBnYms)
	ON_BN_CLICKED(IDC_BN_YMX, &CYWYMT::OnBnClickedBnYmx)
	ON_BN_CLICKED(IDC_BN_YMB, &CYWYMT::OnBnClickedBnYmb)
	ON_BN_CLICKED(IDC_BN_YMH, &CYWYMT::OnBnClickedBnYmh)
	ON_WM_DESTROY()
	//ON_BN_CLICKED(IDOK, &CYWYMT::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BN_YF, &CYWYMT::OnBnClickedBnYf)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CYWYMT 消息处理程序
void CYWYMT::Ystye(void)
{
    m_lstcPersonListy.SetExtendedStyle(m_lstcPersonListy.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_lstcPersonListy.InsertColumn(0,_T("编号"),LVCFMT_CENTER,100);
	m_lstcPersonListy.InsertColumn(1,_T("姓名"),LVCFMT_CENTER,100);
	m_lstcPersonListy.InsertColumn(2,_T("性别"),LVCFMT_CENTER,50);
	m_lstcPersonListy.InsertColumn(3,_T("手机号"),LVCFMT_CENTER,120);
	m_lstcPersonListy.InsertColumn(4,_T("密码"),LVCFMT_CENTER,120);
	m_lstcPersonListy.InsertColumn(5,_T("备注"),LVCFMT_CENTER,250);


}
int CYWYMT::GetS(void)
{
	POSITION ye=m_lstcPersonListy.GetFirstSelectedItemPosition();
	return m_lstcPersonListy.GetNextSelectedItem(ye);

}
void CYWYMT::YS(CYeList&ye,int S)
{

int iLastSel=GetS();
m_lstcPersonListy.DeleteAllItems();
for(int i=0;i<ye.GetSize();i++){

	m_lstcPersonListy.InsertItem(i,ye[i].GetYBian());
	m_lstcPersonListy.SetItemText(i,1,ye[i].GetYName());
	m_lstcPersonListy.SetItemText(i,2,ye[i].IsYMale()?_T("女"):_T("男"));
	m_lstcPersonListy.SetItemText(i,3,ye[i].GetYPhoneNo());
	m_lstcPersonListy.SetItemText(i,4,ye[i].GetYQQNo());
	m_lstcPersonListy.SetItemText(i,5,ye[i].GetYBz());

}
	if(S<0){
		if(iLastSel<0)
			S=ye.GetSize()>0?0:-1;
		else
			S=min(ye.GetSize()-1,iLastSel);
	
	}
	else{
		S=min(ye.GetSize()-1,S);
	
	}
	if(S>=0){
		m_lstcPersonListy.SetFocus();
		m_lstcPersonListy.SetItemState(S,LVIS_SELECTED,LVIS_SELECTED);
	}


}



void CYWYMT::OnBnClickedBnYmt()
{
 /*if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == -1 ){
	  ofstream out("C:\\XYKGL\\Root\\D.del");//用于判断是否点击
	   MessageBox(L"请修改初始密码\n退出后以root进行登录管理",L"信用卡系统提示");
		CDialogEx::OnOK();
   }*/
	CYewu yeAdd;
	CYewudg dlgEdit(yeAdd,this);
   int re=dlgEdit.DoModal();
   if(re==IDOK){  
	  /* if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == -1 ){
	   m_lstYe.Add(dlgEdit.Getys());
	   YS(m_lstYe,m_lstYe.GetSize()-1);
	   MessageBox(_T("root成员已经成功录入请重新登录"),_T("提示"),MB_ICONASTERISK);
	   }
   else{*/

		for (int i = 0; i < m_lstYe.GetSize(); i++)
		{
			if(dlgEdit.Getys().GetYBian()==m_lstYe[i].GetYBian())  //判断是否存在用户名
			{
				MessageBox(L"亲，编号不能一样",L"信用卡提示");
				return;
			}
		}
  if(dlgEdit.Getys().GetYBian()=="root"){MessageBox(_T("root不可在添加"),_T("警告"));}
   else{
       m_lstYe.Add(dlgEdit.Getys());
	   YS(m_lstYe,m_lstYe.GetSize()-1);
		}
	   }
  

	// TODO: 在此添加控件通知处理程序代码
}



void CYWYMT::OnBnClickedBnYms()
{

	int iS=GetS();
	if(iS<0)return;
	CString strHint;
	strHint.Format(_T("你确认删除编号为%s的业务员吗?"),m_lstYe[iS].GetYBian());
	if(m_lstYe[iS].GetYBian()=="root"){
		MessageBox(_T("root不可删除"),_T("警告"));
	}else{
	if(MessageBox(strHint,_T("确认删除"),MB_YESNO|MB_ICONQUESTION)==IDYES)m_lstYe.RemoveAt(iS);
	YS(m_lstYe,iS);

	}
	// TODO: 在此添加控件通知处理程序代码
}


void CYWYMT::OnBnClickedBnYmx()
{
	int iCurSel=GetS();
	if(iCurSel<0)return;
	CYewudg dlgEdit(m_lstYe[iCurSel],this);
	int iRet=dlgEdit.DoModal();
	if(iRet==IDOK){
		if(dlgEdit.Getys().GetYBian()=="root"&&iCurSel!=0)//两个条件进行判断第一个只能有一个root修改时第一个可改动其他的都不能
		{MessageBox(L"警告其他成员不可以该为root成员",L"警告",MB_ICONHAND);}
		else
		{

		m_lstYe[iCurSel]=dlgEdit.Getys();
		YS(m_lstYe,iCurSel);
		}
	}

	// TODO: 在此添加控件通知处理程序代码
}

BOOL CYWYMT::DS(CString strsf)
{
	CFile fileGCL(strsf,CFile::modeWrite|CFile::modeCreate);
	CArchive yar(&fileGCL,CArchive::store);
	m_lstYe.Ser(yar);
	return TRUE;

}

void CYWYMT::OnBnClickedBnYmb()
{

	CFileDialog dlgFile(FALSE,_T(".ywy"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|OFN_HIDEREADONLY,_T("通讯录(*.ywy)|*.ywy||"),NULL);
	if(dlgFile.DoModal()!=IDOK){
		m_lstcPersonListy.SetFocus();
		return;
	}
	DS(dlgFile.GetPathName());
	// TODO: 在此添加控件通知处理程序代码
}
BOOL CYWYMT::DL(CString strhf)
{
	CFile hf(strhf,CFile::modeRead);
	CArchive yar(&hf,CArchive::load);
	m_lstYe.Ser(yar);
	return TRUE;

}

void CYWYMT::OnBnClickedBnYmh()
{
	CFileDialog dlgFile(TRUE,_T(".ywy"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|OFN_HIDEREADONLY,_T("通讯录(*.ywy)|*.ywy||"),NULL);
	if(dlgFile.DoModal()!=IDOK){
		m_lstcPersonListy.SetFocus();
		return;
	}
	if(DL(dlgFile.GetPathName()))
		YS(m_lstYe,0);

	// TODO: 在此添加控件通知处理程序代码
}


void CYWYMT::OnDestroy()
{
	CDialogEx::OnDestroy();
	DS(m_strD);
	// TODO: 在此处添加消息处理程序代码
}


/*void CYWYMT::OnBnClickedOk()
{
if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == -1 ){
		AfxMessageBox(L"必要文件没创建将直接退出");
     CDialogEx::OnOK();
}else
{   
	if(MessageBox(_T("是否退出而回到登录界面"),_T("退出"),MB_OKCANCEL)==IDOK){
    CDialogEx::OnOK();
	CDeng deng;
	deng.DoModal();
	}
}
	// TODO: 在此添加控件通知处理程序代码
	
}
*/

void CYWYMT::OnBnClickedBnYf()
{
	UpdateData(TRUE);
	m_lstFindw.RemoveAll();
	for(int i=0;i<m_lstYe.GetSize();i++){
		CString tempMale=m_lstYe[i].IsYMale()?_T("男"):_T("女");
	if(m_lstYe[i].GetYName().Find(m_FU)!=-1||tempMale.Find(m_FU)!=-1||m_lstYe[i].GetYBian().Find(m_FU)!=-1)m_lstFindw.Add(m_lstYe[i]);	
	}
	if(m_lstFindw.GetSize()>0)
		YS(m_lstFindw);
	else
	MessageBox(L"找不到对应的结果",L"提示");
	// TODO: 在此添加控件通知处理程序代码
}


//BOOL CYWYMT::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//	if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == -1 ){
//		AfxMessageBox(L"您好由于您是第一次使用，所以要自行添加内置成员");
//
//	}
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//
//}

BOOL CYWYMT::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Ystye();
	WCHAR YPath[_MAX_PATH];
	GetCurrentDirectory(MAX_PATH,YPath);
	m_strD.Format(_T("C:\\XYKGL\\Root\\业务员.ywy"),YPath);
	if(PathFileExists(m_strD)){
		DL(m_strD);
		YS(m_lstYe);
	}
	//第一次登陆添加默认值
	if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == -1&&m_lstYe.GetSize()==0){
	if((_access( "C:\\XYKGL\\Root\\D.del", 0 )) == -1){
		CYewu k;
		k=CYewu(L"root",L"管理员",FALSE,L"1231231",L"123456",L"你好");
	   m_lstYe.Add(k);
	   YS(m_lstYe,m_lstYe.GetSize()-1);
	}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control

	// 异常: OCX 属性页应返回 FALSE
}



void CYWYMT::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == -1&&m_lstYe.GetSize()==0){
	if((_access( "C:\\XYKGL\\Root\\D.del", 0 )) == -1){
		CYewu k;
		k=CYewu(L"root",L"管理员",FALSE,L"1231231",L"123456",L"你好");
	   m_lstYe.Add(k);
	}
	}
	*/
	CDialogEx::OnClose();
}
