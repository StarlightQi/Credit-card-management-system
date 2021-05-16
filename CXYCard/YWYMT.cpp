// YWYMT.cpp : ʵ���ļ�
//�˺Ź����ࣨҵ��Ա�����ڹ����˺ţ�֮ǰ��¼�ĺܶຯ�����ǵ��������

#include "stdafx.h"
#include "CXYCard.h"
#include "YWYMT.h"
#include "afxdialogex.h"
#include "YeList.h"
#include "Yewudg.h"
#include "Deng.h"
#include "fstream"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include  <io.h>
using namespace std;
// CYWYMT �Ի���
int q=10;//�����ж��Ƿ�������Ӱ���
IMPLEMENT_DYNAMIC(CYWYMT, CDialogEx)

CYWYMT::CYWYMT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CYWYMT::IDD, pParent)
	, m_FU(_T(""))
{
CDialogEx::SetBackgroundColor(RGB(155,170,190));
}

CYWYMT::~CYWYMT()
{
}
int oo=1;
void CYWYMT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_lstcPersonListy);
	DDX_Text(pDX, IDC_ED_FU, m_FU);
}


BEGIN_MESSAGE_MAP(CYWYMT, CDialogEx)
	ON_BN_CLICKED(IDC_BN_YMT, &CYWYMT::OnBnClickedBnYmt)
	ON_BN_CLICKED(IDD_BN_YMS, &CYWYMT::OnBnClickedBnYms)
	ON_BN_CLICKED(IDC_BN_YMX, &CYWYMT::OnBnClickedBnYmx)
	ON_BN_CLICKED(IDC_BN_YMB, &CYWYMT::OnBnClickedBnYmb)
	ON_BN_CLICKED(IDC_BN_YMH, &CYWYMT::OnBnClickedBnYmh)
	ON_WM_DESTROY()
	//ON_BN_CLICKED(IDOK, &CYWYMT::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BN_YF, &CYWYMT::OnBnClickedBnYf)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CYWYMT ��Ϣ�������
void CYWYMT::Ystye(void)
{
    m_lstcPersonListy.SetExtendedStyle(m_lstcPersonListy.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_lstcPersonListy.InsertColumn(0,_T("���"),LVCFMT_CENTER,100);
	m_lstcPersonListy.InsertColumn(1,_T("����"),LVCFMT_CENTER,100);
	m_lstcPersonListy.InsertColumn(2,_T("�Ա�"),LVCFMT_CENTER,50);
	m_lstcPersonListy.InsertColumn(3,_T("�ֻ���"),LVCFMT_CENTER,120);
	m_lstcPersonListy.InsertColumn(4,_T("����"),LVCFMT_CENTER,120);
	m_lstcPersonListy.InsertColumn(5,_T("��ע"),LVCFMT_CENTER,250);


}
int CYWYMT::GetS(void)
{
	POSITION ye=m_lstcPersonListy.GetFirstSelectedItemPosition();
	return m_lstcPersonListy.GetNextSelectedItem(ye);

}
void CYWYMT::YS(CYeList&ye,int S)
{

int iLastSel=GetS();
m_lstcPersonListy.DeleteAllItems();
for(int i=0;i<ye.GetSize();i++){

	m_lstcPersonListy.InsertItem(i,ye[i].GetYBian());
	m_lstcPersonListy.SetItemText(i,1,ye[i].GetYName());
	m_lstcPersonListy.SetItemText(i,2,ye[i].IsYMale()?_T("Ů"):_T("��"));
	m_lstcPersonListy.SetItemText(i,3,ye[i].GetYPhoneNo());
	m_lstcPersonListy.SetItemText(i,4,ye[i].GetYQQNo());
	m_lstcPersonListy.SetItemText(i,5,ye[i].GetYBz());

}
	if(S<0){
		if(iLastSel<0)
			S=ye.GetSize()>0?0:-1;
		else
			S=min(ye.GetSize()-1,iLastSel);
	
	}
	else{
		S=min(ye.GetSize()-1,S);
	
	}
	if(S>=0){
		m_lstcPersonListy.SetFocus();
		m_lstcPersonListy.SetItemState(S,LVIS_SELECTED,LVIS_SELECTED);
	}


}



void CYWYMT::OnBnClickedBnYmt()
{
 /*if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == -1 ){
	  ofstream out("C:\\XYKGL\\Root\\D.del");//�����ж��Ƿ���
	   MessageBox(L"���޸ĳ�ʼ����\n�˳�����root���е�¼����",L"���ÿ�ϵͳ��ʾ");
		CDialogEx::OnOK();
   }*/
	CYewu yeAdd;
	CYewudg dlgEdit(yeAdd,this);
   int re=dlgEdit.DoModal();
   if(re==IDOK){  
	  /* if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == -1 ){
	   m_lstYe.Add(dlgEdit.Getys());
	   YS(m_lstYe,m_lstYe.GetSize()-1);
	   MessageBox(_T("root��Ա�Ѿ��ɹ�¼�������µ�¼"),_T("��ʾ"),MB_ICONASTERISK);
	   }
   else{*/

		for (int i = 0; i < m_lstYe.GetSize(); i++)
		{
			if(dlgEdit.Getys().GetYBian()==m_lstYe[i].GetYBian())  //�ж��Ƿ�����û���
			{
				MessageBox(L"�ף���Ų���һ��",L"���ÿ���ʾ");
				return;
			}
		}
  if(dlgEdit.Getys().GetYBian()=="root"){MessageBox(_T("root���������"),_T("����"));}
   else{
       m_lstYe.Add(dlgEdit.Getys());
	   YS(m_lstYe,m_lstYe.GetSize()-1);
		}
	   }
  

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



void CYWYMT::OnBnClickedBnYms()
{

	int iS=GetS();
	if(iS<0)return;
	CString strHint;
	strHint.Format(_T("��ȷ��ɾ�����Ϊ%s��ҵ��Ա��?"),m_lstYe[iS].GetYBian());
	if(m_lstYe[iS].GetYBian()=="root"){
		MessageBox(_T("root����ɾ��"),_T("����"));
	}else{
	if(MessageBox(strHint,_T("ȷ��ɾ��"),MB_YESNO|MB_ICONQUESTION)==IDYES)m_lstYe.RemoveAt(iS);
	YS(m_lstYe,iS);

	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CYWYMT::OnBnClickedBnYmx()
{
	int iCurSel=GetS();
	if(iCurSel<0)return;
	CYewudg dlgEdit(m_lstYe[iCurSel],this);
	int iRet=dlgEdit.DoModal();
	if(iRet==IDOK){
		if(dlgEdit.Getys().GetYBian()=="root"&&iCurSel!=0)//�������������жϵ�һ��ֻ����һ��root�޸�ʱ��һ���ɸĶ������Ķ�����
		{MessageBox(L"����������Ա�����Ը�Ϊroot��Ա",L"����",MB_ICONHAND);}
		else
		{

		m_lstYe[iCurSel]=dlgEdit.Getys();
		YS(m_lstYe,iCurSel);
		}
	}

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

BOOL CYWYMT::DS(CString strsf)
{
	CFile fileGCL(strsf,CFile::modeWrite|CFile::modeCreate);
	CArchive yar(&fileGCL,CArchive::store);
	m_lstYe.Ser(yar);
	return TRUE;

}

void CYWYMT::OnBnClickedBnYmb()
{

	CFileDialog dlgFile(FALSE,_T(".ywy"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|OFN_HIDEREADONLY,_T("ͨѶ¼(*.ywy)|*.ywy||"),NULL);
	if(dlgFile.DoModal()!=IDOK){
		m_lstcPersonListy.SetFocus();
		return;
	}
	DS(dlgFile.GetPathName());
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
BOOL CYWYMT::DL(CString strhf)
{
	CFile hf(strhf,CFile::modeRead);
	CArchive yar(&hf,CArchive::load);
	m_lstYe.Ser(yar);
	return TRUE;

}

void CYWYMT::OnBnClickedBnYmh()
{
	CFileDialog dlgFile(TRUE,_T(".ywy"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|OFN_HIDEREADONLY,_T("ͨѶ¼(*.ywy)|*.ywy||"),NULL);
	if(dlgFile.DoModal()!=IDOK){
		m_lstcPersonListy.SetFocus();
		return;
	}
	if(DL(dlgFile.GetPathName()))
		YS(m_lstYe,0);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CYWYMT::OnDestroy()
{
	CDialogEx::OnDestroy();
	DS(m_strD);
	// TODO: �ڴ˴������Ϣ����������
}


/*void CYWYMT::OnBnClickedOk()
{
if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == -1 ){
		AfxMessageBox(L"��Ҫ�ļ�û������ֱ���˳�");
     CDialogEx::OnOK();
}else
{   
	if(MessageBox(_T("�Ƿ��˳����ص���¼����"),_T("�˳�"),MB_OKCANCEL)==IDOK){
    CDialogEx::OnOK();
	CDeng deng;
	deng.DoModal();
	}
}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}
*/

void CYWYMT::OnBnClickedBnYf()
{
	UpdateData(TRUE);
	m_lstFindw.RemoveAll();
	for(int i=0;i<m_lstYe.GetSize();i++){
		CString tempMale=m_lstYe[i].IsYMale()?_T("��"):_T("Ů");
	if(m_lstYe[i].GetYName().Find(m_FU)!=-1||tempMale.Find(m_FU)!=-1||m_lstYe[i].GetYBian().Find(m_FU)!=-1)m_lstFindw.Add(m_lstYe[i]);	
	}
	if(m_lstFindw.GetSize()>0)
		YS(m_lstFindw);
	else
	MessageBox(L"�Ҳ�����Ӧ�Ľ��",L"��ʾ");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


//BOOL CYWYMT::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//	if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == -1 ){
//		AfxMessageBox(L"�����������ǵ�һ��ʹ�ã�����Ҫ����������ó�Ա");
//
//	}
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//
//}

BOOL CYWYMT::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Ystye();
	WCHAR YPath[_MAX_PATH];
	GetCurrentDirectory(MAX_PATH,YPath);
	m_strD.Format(_T("C:\\XYKGL\\Root\\ҵ��Ա.ywy"),YPath);
	if(PathFileExists(m_strD)){
		DL(m_strD);
		YS(m_lstYe);
	}
	//��һ�ε�½���Ĭ��ֵ
	if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == -1&&m_lstYe.GetSize()==0){
	if((_access( "C:\\XYKGL\\Root\\D.del", 0 )) == -1){
		CYewu k;
		k=CYewu(L"root",L"����Ա",FALSE,L"1231231",L"123456",L"���");
	   m_lstYe.Add(k);
	   YS(m_lstYe,m_lstYe.GetSize()-1);
	}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control

	// �쳣: OCX ����ҳӦ���� FALSE
}



void CYWYMT::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == -1&&m_lstYe.GetSize()==0){
	if((_access( "C:\\XYKGL\\Root\\D.del", 0 )) == -1){
		CYewu k;
		k=CYewu(L"root",L"����Ա",FALSE,L"1231231",L"123456",L"���");
	   m_lstYe.Add(k);
	}
	}
	*/
	CDialogEx::OnClose();
}
