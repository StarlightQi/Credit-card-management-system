#pragma once
#include "afxwin.h"
#include "GCustomert.h"

// TJYH �Ի���

class TJYH : public CDialogEx
{
	DECLARE_DYNAMIC(TJYH)

public:
	TJYH(CGCustomert psn,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TJYH();

// �Ի�������
	enum { IDD = IDD_TIAN };

protected:
	CString m_strHead;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGCustomert m_CG;
	DECLARE_MESSAGE_MAP()
public:
	CGCustomert& GetGCustomert(){return m_CG;}
	int m_bMale;
	int m_strZhang;
	CString m_strBz;
	CString m_strBian;
	CString m_strEd;
	CString m_strName;
//	CString m_strNlian;
	CString m_strPhoneNo;
//	CString m_strQQno;
	CString m_strQQNo;
	afx_msg void OnBnClickedOk();
//	CString m_strNLing;
	CString m_strGong;
//	int m_strNLing;
	CString m_strNLing;
	afx_msg void OnBnClickedBnTian();
	afx_msg void OnPaint();
	afx_msg void OnEnChangeEdiPhoneon();
};
