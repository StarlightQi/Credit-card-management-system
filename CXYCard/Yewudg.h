#pragma once
#include "afxwin.h"
#include "Yewu.h"


// CYewudg 对话框

class CYewudg : public CDialogEx
{
	DECLARE_DYNAMIC(CYewudg)

public:
	CYewudg(CYewu y,CWnd* pParent = NULL); 
	virtual ~CYewudg();

// 对话框数据
	enum { IDD = IDD_YEWU };

protected:
	
	CYewu m_yE;//业务员类对象
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
