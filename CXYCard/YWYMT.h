#pragma once
#include "afxcmn.h"
#include "YeList.h"


// CYWYMT �Ի���

class CYWYMT : public CDialogEx
{
	DECLARE_DYNAMIC(CYWYMT)

public:
	CYWYMT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CYWYMT();
	BOOL DL(CString hf);
	int GetS(void);
	CYeList m_lstYe;
	BOOL DS(CString strsf);
	CString m_strD;
	int pan();
	CYeList m_lstFindw;
// �Ի�������
	enum { IDD = IDD_YWYMT };

protected:
	void Ystye(void);
	void YS(CYeList&ye,int S=-1);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_lstcPersonListy;
	afx_msg void OnBnClickedBnYmt();
	afx_msg void OnBnClickedBnYms();
	afx_msg void OnBnClickedBnYmx();
	afx_msg void OnBnClickedBnYmb();
	afx_msg void OnBnClickedBnYmh();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBnYf();
	CString m_FU;
//	virtual BOOL OnInitDialog();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
};
