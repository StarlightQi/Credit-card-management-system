// OLDDlg.cpp : 实现文件
//统计图类，业务员窗口与管理员窗口公用此类，来实现统计功能

#include "stdafx.h"
#include "CXYCard.h"
#include "OLDDlg.h"
#include "afxdialogex.h"
#include "GCustomerList.h"

// COLDDlg 对话框

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


// COLDDlg 消息处理程序


void COLDDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void COLDDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CGCustomerList::PaintChart(this->m_hWnd,m_iArray,IDC_STA_COUNT);
		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CDialogEx::OnPaint()
}
