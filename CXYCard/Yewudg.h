#pragma once
#include "afxwin.h"
#include "Yewu.h"


// CYewudg �Ի���

class CYewudg : public CDialogEx
{
	DECLARE_DYNAMIC(CYewudg)

public:
	CYewudg(CYewu y,CWnd* pParent = NULL); 
	virtual ~CYewudg();

// �Ի�������
	enum { IDD = IDD_YEWU };

protected:
	
	CYewu m_yE;//ҵ��Ա�����
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CYewu& Getys(){return m_yE;}
	CString m_strYBian;
//	int m_YbMale;
	CString m_strYName;
//	CString str_YPhoneNo;
	CString m_strYQQNo;
//	CComboBox m_YbMale;
	int m_YbMale;
	afx_msg void OnBnClickedOk();
	CString m_strYPhoneNo;
	CString m_strYBz;
//	afx_msg void OnClose();
//	afx_msg void OnBnClickedCancel();
};
