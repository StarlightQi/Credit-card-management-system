#pragma once
#include "afxwin.h"
#include "YeList.h"
#include "YWYMT.h"
#include "YeWugl.h"
#include "GCustomert.h"

#include "PictureEx.h"// CDeng �Ի���

class CDeng : public CDialogEx
{
	DECLARE_DYNAMIC(CDeng)

public:
	CDeng(CWnd* pParent = NULL); 
	CString DLN,PS;
	// ��׼���캯��
	virtual ~CDeng();
// �Ի�������
	enum { IDD = IDD_DONG };
	CBrush m_bru;
 
protected:
	int k;//�����жϵ�¼�Ĵ���
	void d(CYeList&a);//���ڶ�ȡ���ҵ������������
	void bh();//���Һ���
	int pyi;//�ļ��쳣�жϣ�
	CString FU;//ת�����͵�
	CString cw;
	CString US;
	CYeList qh;
	CString SC;//�ж����ݵ���ȷ�ԣ�
	virtual void DoDataExchange(CDataExchange* pDX);
	CYWYMT wen;//��������ߵ��ú���
	// DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	CEdit m_strDName;
	CString m_strDName;
	CString m_strDPoss;
	afx_msg void OnEnKillfocusEdName();
	afx_msg void OnEnChangeEdPoss();
	afx_msg void OnEnChangeEdName();
	afx_msg void OnBnClickedCheck1();
	virtual BOOL OnInitDialog();
	BOOL m_checkBox1;
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnKillfocusEdPoss();
	afx_msg void OnEnUpdateEdName();

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton1();
	CButton m_BtnTest;
	afx_msg void OnBnClickedButton2();
	CButton m_bt3;
};
