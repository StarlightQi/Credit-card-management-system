#pragma once
#include "afxcmn.h"
#include "GCustomerList.h"
#include "Deng.h"
#include "afxcolorbutton.h"


// CYeWugl �Ի���

class CYeWugl : public CDialogEx
{
	DECLARE_DYNAMIC(CYeWugl)

public:
	int ui;
	int youg,zhong,old;
	CString DLN;//��¼��
	CYeWugl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CYeWugl();
	CYeWugl(CString strDN);
	CString m_dl;
	CString m_strDN;
// �Ի�������
	enum { IDD = IDD_YEWUGL };
		void CountOld();//ͳ�����䣻
	CString IntToString (int n);
	int m_iArray[3];//ͳ��ͼ��ֵ
	CString GetDN(){return m_strDN;}
	void Set(CString strDN){m_strDN=strDN;}
protected:
	int ex1;
    BOOL CreateToolBar1();//����������
	CToolBar m_ToolBar1;
	CImageList m_img1;
	CGCustomerList m_lstFindY;//���ڲ��ҵ�
	virtual void DoDataExchange(CDataExchange* pDX);
	void IP(void);
	void RPC(CGCustomerList&psnList,int iC=-1);//ˢ��
	int GCS(void);
	CGCustomerList m_LP;//��̬�������
	CString m_sF;
	BOOL DS(CString sn);//����
	BOOL HF(CString hf);//����
	// DDX/DDV ֧��

	NOTIFYICONDATA m_nid1;
	DECLARE_MESSAGE_MAP()
public:
    afx_msg LRESULT OnShowTask(WPARAM wParam,LPARAM lParam);
//	afx_msg void OnBnClickedBnYtian();
	CListCtrl m_lstcPersonList1;
//	afx_msg void OnBnClickedBnYxiu();
	afx_msg void OnDestroy();
	CString m_fund;
	afx_msg void OnChangeFu();
	afx_msg void OnPaint();
	afx_msg void OnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBnYfund();
	afx_msg void OnYtc();
	afx_msg void OnYadd();
	afx_msg void OnYexet();
	afx_msg void OnYshown();
	afx_msg void OnYqs();
	afx_msg void OnYable();
	afx_msg void OnYjis();
	afx_msg void Onluping();
	afx_msg void Onjispb();
	afx_msg void OnYbiadu();
//	afx_msg void OnBnClickedBnTong();
	afx_msg void OnYshuo();
	virtual BOOL OnInitDialog();
//	BOOL m_exit1;
	afx_msg void OnBuNew2();
	afx_msg void OnBuRe2();
	afx_msg void OnBuTong2();
	afx_msg void OnBuAbout2();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void On32922();
	afx_msg void OnRe4();
	afx_msg void On32925();
	afx_msg void On32924();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	BOOL m_checkbox1;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNMCustomdrawList1(NMHDR *pNMHDR, LRESULT *pResult);
};
