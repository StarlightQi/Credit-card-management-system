#pragma once


// CRead �Ի���

class CRead : public CDialogEx
{
	DECLARE_DYNAMIC(CRead)

public:
	CRead(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRead();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_read;
	afx_msg void OnBnClickedButton1();
};
