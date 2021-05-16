#pragma once


// CRead 对话框

class CRead : public CDialogEx
{
	DECLARE_DYNAMIC(CRead)

public:
	CRead(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRead();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_read;
	afx_msg void OnBnClickedButton1();
};
