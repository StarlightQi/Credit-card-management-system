// Yewudg.cpp : ʵ���ļ�
//����޺��˺ŵĴ�����

#include "stdafx.h"
#include "CXYCard.h"
#include "Yewudg.h"
#include "afxdialogex.h"
#include "Yewu.h"
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
// CYewudg �Ի���

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


// CYewudg ��Ϣ�������


void CYewudg::OnBnClickedOk()
{
	UpdateData(TRUE);
	 /*if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == -1 ){
		if(m_strYBian!="root"){
		 }
	else{
		if(m_strYBian.GetLength()>=4){
		 if(m_strYQQNo.GetLength()>5){
	m_yE=CYewu(m_strYBian,m_strYName,m_YbMale,m_strYPhoneNo,m_strYQQNo,m_strYBz);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	}else{AfxMessageBox(L"���벻����Ϊ���Ҳ���С��5���ַ�");}
	}else {AfxMessageBox(L"��Ų�����Ϊ�ջ�������4���ַ�");}}
	}else{*/
		 if(m_strYBian.GetLength()>=4){
		 if(m_strYQQNo.GetLength()>5){
	m_yE=CYewu(m_strYBian,m_strYName,m_YbMale,m_strYPhoneNo,m_strYQQNo,m_strYBz);
	CDialogEx::OnOK();

		 }else{AfxMessageBox(L"���벻����Ϊ���Ҳ��ܴ���5���ַ�");}
		 }else {AfxMessageBox(L"��Ų�����Ϊ�ջ�������4���ַ�");}

}

//�����жϵ�һ���������Ϣ
//void CYewudg::OnClose()
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	 /*if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == 0 ){ 
//	CDialogEx::OnClose();
//	 }else
//	 {
//		 AfxMessageBox(L"��ܰС��ʾ������ط���");
//	 }*/
//}


//void CYewudg::OnBnClickedCancel()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	 /*if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == 0 ){ 
//	CDialogEx::OnCancel();
//	 }
//	 else
//	 {
//		 AfxMessageBox(L"��ܰС��ʾ������ط���");
//	 }*/
//}
