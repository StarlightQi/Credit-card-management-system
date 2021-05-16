
// CXYCardDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "GCustomerList.h"
#include "afxcolorbutton.h"


// CCXYCardDlg �Ի���
class CCXYCardDlg : public CDialogEx
{
// ����
public:
	  POINT mypoint; 
	COLORREF m_colRow1;
	COLORREF m_colRow2;
	CCXYCardDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void box(CString wen,CString title);
// �Ի�������
	enum { IDD = IDD_CXYCARD_DIALOG };
	int youg,zhong,old;//�������ָ�ֵ
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	void CountOld();//ͳ�����䣻
	CString IntToString (int n);
	int m_iArray[3];
	NOTIFYICONDATA m_nid;
// ʵ��
protected:
	CImageList m_img;
	int ex;
	CToolBar m_ToolBar;
	BOOL CreateToolBar();
	HICON m_hIcon;
	CGCustomerList m_lstPerson;
	void RefreshPersonListCtrl(CGCustomerList& psnList,int iCurSel=-1);
	BOOL DoSaveFile(CString strFileName);
	BOOL DoLoadFile(CString strFileName);
	CString m_s;
	CGCustomerList m_lstFindG;
    int GetCurSel(void);

	// ���ɵ���Ϣӳ�亯��
	void InitPersonListCtrl(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT OnShowTask(WPARAM wParam,LPARAM lParam);
//	afx_msg void OnBnClickedBnTianjia();
	CListCtrl m_lstcPersonList;
//	afx_msg void OnBnClickedBnshanchu();
//	afx_msg void OnBnClickedBnxiugai();
//	afx_msg void OnBnClickedBnbeifen();
//	afx_msg void OnBnClickedBnhuifu();
	afx_msg void OnDestroy();
//	afx_msg void OnBnClickedBnAddye();
	afx_msg void OnBnClickedBnBr();
	CString m_strFind;
	afx_msg void OnChangeEdiFund();
	afx_msg void OnItemchangedLiLiebiao(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBnFand();
	afx_msg void OnSave();
	afx_msg void OnOpen();
	afx_msg void OnClose();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnExer();
	afx_msg void OnYe();
	afx_msg void OnShutdown();
	afx_msg void On32788();
	afx_msg void OnXz();
	afx_msg void OnQs();
	afx_msg void OnJsq();
	afx_msg void Ontxt();
	afx_msg void Onbaidu();
	afx_msg void OnLp();
//	afx_msg void OnBnClickedBnTu();
	afx_msg void OnShuo();
	BOOL m_exit;

//	COLORREF m_color;

	afx_msg void OnBuAdd1();
	afx_msg void OnBuDel1();
	afx_msg void OnBuOpen1();
	afx_msg void OnBuBei();
	afx_msg void OnBuRe1();
	afx_msg void OnBuTong1();
	afx_msg void OnBuAbout1();
	afx_msg void OnBuYewu();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnAdd3();
	afx_msg void OnRe3();
	afx_msg void OnTong3();
	afx_msg void OnDel3();
	afx_msg void On32917();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnNMCustomdrawLiliebiao(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawLiliebiao(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void On32927();
};
