// Yewudg.cpp : 实现文件
//添加修好账号的窗口类

#include "stdafx.h"
#include "CXYCard.h"
#include "Yewudg.h"
#include "afxdialogex.h"
#include "Yewu.h"
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
// CYewudg 对话框

IMPLEMENT_DYNAMIC(CYewudg, CDialogEx)

	CYewudg::CYewudg(CYewu y,CWnd* pParent /*=NULL*/)
	: CDialogEx(CYewudg::IDD, pParent)
	, m_strYBian(y.GetYBian())
	, m_strYName(y.GetYName())
	, m_strYQQNo(y.GetYQQNo())
	, m_YbMale(y.IsYMale())
	, m_strYPhoneNo(y.GetYPhoneNo())
	, m_strYBz(y.GetYBz())
{
m_yE=y;
 CDialogEx::SetBackgroundColor(RGB(204, 232, 207));
}


CYewudg::~CYewudg()
{
}

void CYewudg::DoDataExchange(CDataExchange* pDX)
{
	
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ED_YBIAN, m_strYBian);
	DDX_Text(pDX, IDC_ED_YNAME, m_strYName);
	//  DDX_Text(pDX, IDC_ED_YPHONE, str_YPhoneNo);
	DDX_Text(pDX, IDC_ED_YQQ, m_strYQQNo);
	//  DDX_Control(pDX, IDC_CM_BM, m_YbMale);
	DDX_CBIndex(pDX, IDC_CM_BM, m_YbMale);
	DDX_Text(pDX, IDC_ED_YPHONE, m_strYPhoneNo);
	DDX_Text(pDX, IDC_ED_YBZ, m_strYBz);
	if(m_strYBian=="root")
	GetDlgItem(IDC_ED_YBIAN)->EnableWindow(FALSE);
}


BEGIN_MESSAGE_MAP(CYewudg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CYewudg::OnBnClickedOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CYewudg 消息处理程序


void CYewudg::OnBnClickedOk()
{
	UpdateData(TRUE);
	 /*if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == -1 ){
		if(m_strYBian!="root"){
		 }
	else{
		if(m_strYBian.GetLength()>=4){
		 if(m_strYQQNo.GetLength()>5){
	m_yE=CYewu(m_strYBian,m_strYName,m_YbMale,m_strYPhoneNo,m_strYQQNo,m_strYBz);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	}else{AfxMessageBox(L"密码不可以为空且不能小于5个字符");}
	}else {AfxMessageBox(L"编号不可以为空或者少于4个字符");}}
	}else{*/
		 if(m_strYBian.GetLength()>=4){
		 if(m_strYQQNo.GetLength()>5){
	m_yE=CYewu(m_strYBian,m_strYName,m_YbMale,m_strYPhoneNo,m_strYQQNo,m_strYBz);
	CDialogEx::OnOK();

		 }else{AfxMessageBox(L"密码不可以为空且不能大于5个字符");}
		 }else {AfxMessageBox(L"编号不可以为空或者少于4个字符");}

}

//用于判断第一次输入的信息
//void CYewudg::OnClose()
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	 /*if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == 0 ){ 
//	CDialogEx::OnClose();
//	 }else
//	 {
//		 AfxMessageBox(L"温馨小提示：你点错地方了");
//	 }*/
//}


//void CYewudg::OnBnClickedCancel()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	 /*if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == 0 ){ 
//	CDialogEx::OnCancel();
//	 }
//	 else
//	 {
//		 AfxMessageBox(L"温馨小提示：你点错地方了");
//	 }*/
//}
