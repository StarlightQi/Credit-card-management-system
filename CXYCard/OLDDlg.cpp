// OLDDlg.cpp : ʵ���ļ�
//ͳ��ͼ�࣬ҵ��Ա���������Ա���ڹ��ô��࣬��ʵ��ͳ�ƹ���

#include "stdafx.h"
#include "CXYCard.h"
#include "OLDDlg.h"
#include "afxdialogex.h"
#include "GCustomerList.h"

// COLDDlg �Ի���

IMPLEMENT_DYNAMIC(COLDDlg, CDialogEx)

COLDDlg::COLDDlg(int arr[],CWnd* pParent /*=NULL*/)
	: CDialogEx(COLDDlg::IDD, pParent)
{
	m_iArray[0]=arr[0];
	m_iArray[1]=arr[1];
	m_iArray[2]=arr[2];
 CDialogEx::SetBackgroundColor(RGB(155,170,190));
}

COLDDlg::~COLDDlg()
{
}

void COLDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COLDDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &COLDDlg::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// COLDDlg ��Ϣ�������


void COLDDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void COLDDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CGCustomerList::PaintChart(this->m_hWnd,m_iArray,IDC_STA_COUNT);
		// TODO: �ڴ˴������Ϣ����������
		// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
