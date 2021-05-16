#pragma once
#include "afxwin.h"
#include "YeList.h"
#include "YWYMT.h"
#include "YeWugl.h"
#include "GCustomert.h"

#include "PictureEx.h"// CDeng 对话框

class CDeng : public CDialogEx
{
	DECLARE_DYNAMIC(CDeng)

public:
	CDeng(CWnd* pParent = NULL); 
	CString DLN,PS;
	// 标准构造函数
	virtual ~CDeng();
// 对话框数据
	enum { IDD = IDD_DONG };
	CBrush m_bru;
 
protected:
	int k;//用于判断登录的次数
	void d(CYeList&a);//用于读取查找到后的数组数据
	void bh();//查找函数
	int pyi;//文件异常判断；
	CString FU;//转换类型的
	CString cw;
	CString US;
	CYeList qh;
	CString SC;//判断数据的正确性；
	virtual void DoDataExchange(CDataExchange* pDX);
	CYWYMT wen;//定义对象后边调用函数
	// DDX/DDV 支持
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
