#pragma once


// COLDDlg �Ի���

class COLDDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COLDDlg)

public:
	COLDDlg(int arr[],CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COLDDlg();

// �Ի�������
	enum { IDD = IDD_COUNT };
	int m_iArray[3];
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
};
