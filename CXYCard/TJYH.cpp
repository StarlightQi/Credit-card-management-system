// TJYH.cpp : 实现文件
//添加客户的窗口类，业务员窗口与管理员窗口公用此类，来实现添加修改客户的功能

#include "stdafx.h"
#include "CXYCard.h"
#include "TJYH.h"
#include "afxdialogex.h"
#include "GCustomerList.h"
/*#include <regex>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// TJYH 对话框
*/
IMPLEMENT_DYNAMIC(TJYH, CDialogEx)

TJYH::TJYH(CGCustomert psn,CWnd* pParent /*=NULL*/)
	: CDialogEx(TJYH::IDD, pParent)
	, m_bMale(psn.IsMale())
	, m_strZhang(psn.GetZhang())
	, m_strBz(psn.GetBz())
	, m_strBian(psn.GetBian())
	, m_strEd(psn.GetEd())
	, m_strName(psn.GetName())
	, m_strNLing(psn.GetNLing())
	, m_strPhoneNo(psn.GetPhoneNo())
	, m_strQQNo(psn.GetQQNo())
	, m_strGong(psn.GetGong())
	, m_strHead(psn.GetImageHead())
	
{
	m_CG=psn;
 CDialogEx::SetBackgroundColor(RGB(204, 232, 207));
}

TJYH::~TJYH()
{
}

void TJYH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COM_XING, m_bMale);
	DDX_CBIndex(pDX, IDC_COM_ZHANG, m_strZhang);
	DDX_Text(pDX, IDC_ED_BZ, m_strBz);
	DDX_Text(pDX, IDC_EDI_BIAN, m_strBian);
	DDX_Text(pDX, IDC_EDI_ED, m_strEd);
	DDX_Text(pDX, IDC_EDI_NAME, m_strName);
	//  DDX_Text(pDX, IDC_EDI_NLING, m_strNlian);
	DDX_Text(pDX, IDC_EDI_PHONEON, m_strPhoneNo);
	//  DDX_Text(pDX, IDC_EDI_QQNO, m_strQQno);
	DDX_Text(pDX, IDC_EDI_QQNO, m_strQQNo);
	//  DDX_Text(pDX, IDC_EDI_NLING, m_strNLing);
	DDX_Text(pDX, IDC_EDI_GONG, m_strGong);
	//  DDX_Text(pDX, IDC_EDI_NLING, m_strNLing);
	DDX_Text(pDX, IDC_EDI_NLING, m_strNLing);
}


BEGIN_MESSAGE_MAP(TJYH, CDialogEx)
	ON_BN_CLICKED(IDOK, &TJYH::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BN_TIAN, &TJYH::OnBnClickedBnTian)
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_EDI_PHONEON, &TJYH::OnEnChangeEdiPhoneon)
END_MESSAGE_MAP()


// TJYH 消息处理程序


void TJYH::OnBnClickedOk()
{
	UpdateData(TRUE);
	
	m_CG=CGCustomert(m_strBian,m_strName,m_bMale,m_strPhoneNo,m_strQQNo,m_strZhang,m_strEd,m_strBz,m_strNLing,m_strGong);
	m_CG.SetImageHead(m_strHead);
	// TODO: 在此添加控件通知处理程序代码
	int n= _ttoi(m_strNLing);
 //   wregex re(L"/^1([38][0-9]|4[579]|5[0-3,5-9]|6[6]|7[0135678]|9[89])\d{8}$/" );
    if(m_strBian.GetLength()!=0){
    if(m_strName.GetLength()!=0&&m_strName.GetLength()<=10){ 
	if(m_strPhoneNo.GetLength()==11){
	if(m_strQQNo.GetLength()!=0&&m_strQQNo.GetLength()>3){
	if(n<200&&n>=18&&m_strNLing.GetLength()!=0){
	if(MessageBox(_T("是否提交"),_T("提交"),MB_OKCANCEL)==IDOK)
	CDialogEx::OnOK();
	}else{AfxMessageBox(L"年龄在18岁到200岁之间且不能为空");}
	}else{AfxMessageBox(L"QQ号不能为空且大于3位");}
	}else{AfxMessageBox(L"手机号码必须为11位");}
    }else{AfxMessageBox(L"名字不能超过10位且不能为空");}
	}else{AfxMessageBox(L"编号不可以为空");}

}

void TJYH::OnBnClickedBnTian()
{
CFileDialog ccFileDlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_ALLOWMULTISELECT,_T("Image files(*.png;*.jpg|*.png;*.jpg|All files(*.*)|*.*||"),NULL);
	if(ccFileDlg.DoModal()==IDOK)
	{
		CString strPathName=ccFileDlg.GetPathName();
		m_strHead=ccFileDlg.GetFileName();
		CString strFolderPath=_T("C:\\XYKGL\\head\\");
		if(!PathIsDirectory(strFolderPath))
		{
		CString strMsg;
		strMsg.Format(_T("指定路径“%s”不存在，是否创建？"),strFolderPath);
		if(AfxMessageBox(strMsg,MB_YESNO)==IDYES)
		{
			if(!CreateDirectory(strFolderPath,NULL))
			{
				strMsg.Format(_T("创建路径“%S”失败！是否继续？"),strFolderPath);
				if(AfxMessageBox(strMsg,MB_YESNO)==IDYES)
					return;
			}
		}
		
		}
		m_strHead=_T("C:\\XYKGL\\head\\")+m_strHead;
		CopyFile(strPathName,m_strHead,TRUE);
		CGCustomerList::ShowImage(this->m_hWnd,m_strHead,IDC_STA_TUP);
	
	}
}


void TJYH::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	if(PathFileExists(m_CG.GetImageHead())){
		CGCustomerList::ShowImage(this->m_hWnd,m_strHead,IDC_STA_TUP);
	
	}
		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CDialogEx::OnPaint()
}


void TJYH::OnEnChangeEdiPhoneon()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	UpdateData(TRUE);
	if(m_strPhoneNo.GetLength()>=11){
		MessageBox(L"手机号码只能11位哦");}
	// TODO:  在此添加控件通知处理程序代码
}
