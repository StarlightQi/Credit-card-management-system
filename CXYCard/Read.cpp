// Read.cpp : ʵ���ļ�
//�����ı��Ķ�������

#include "stdafx.h"
#include "CXYCard.h"
#include "Read.h"
#include "afxdialogex.h"
#include "TextSpeaker.h"
gds::CTextSpeaker m_read1;

// CRead �Ի���

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


// CRead ��Ϣ�������


void CRead::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if(m_read.GetLength()!=0){
	m_read1.Speak(m_read);
	}else
	{
     m_read1.Speak(L"��û�ӭʹ�����ÿ�����ϵͳ,����������");
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
