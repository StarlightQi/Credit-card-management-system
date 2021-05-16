// Read.cpp : 实现文件
//语音文本阅读窗口类

#include "stdafx.h"
#include "CXYCard.h"
#include "Read.h"
#include "afxdialogex.h"
#include "TextSpeaker.h"
gds::CTextSpeaker m_read1;

// CRead 对话框

IMPLEMENT_DYNAMIC(CRead, CDialogEx)

CRead::CRead(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRead::IDD, pParent)
	, m_read(_T(""))
{

}

CRead::~CRead()
{
}

void CRead::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_read);
}


BEGIN_MESSAGE_MAP(CRead, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CRead::OnBnClickedButton1)
END_MESSAGE_MAP()


// CRead 消息处理程序


void CRead::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if(m_read.GetLength()!=0){
	m_read1.Speak(m_read);
	}else
	{
     m_read1.Speak(L"你好欢迎使用信用卡管理系统,请输入内容");
	}
	// TODO: 在此添加控件通知处理程序代码
}
