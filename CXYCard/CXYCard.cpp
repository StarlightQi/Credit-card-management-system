
// CXYCard.cpp : ����Ӧ�ó��������Ϊ��
//���к���

#include "stdafx.h"
#include "CXYCard.h"
#include "CXYCardDlg.h"
#include "Deng.h"
#include"YWYMT.h"
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
#include "fstream"
#include "AS.h"
#include "TextSpeaker.h" //���������Ķ���
gds::CTextSpeaker m_TextSpeak;//���������Ķ���Ա����

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;

// CCXYCardApp

BEGIN_MESSAGE_MAP(CCXYCardApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()



// CCXYCardApp ����

CCXYCardApp::CCXYCardApp()
{
	
	
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCXYCardApp ����

CCXYCardApp theApp;


// CCXYCardApp ��ʼ��

BOOL CCXYCardApp::InitInstance()
{	
	CCXYCardDlg box;	//������Ϣ��ʾ�����������
	 HANDLE  hMutex = ::CreateMutex(NULL, FALSE, L"ֻ������һ��");//ֻ������һ�����򣬱�ʶ
	if (GetLastError() == ERROR_ALREADY_EXISTS){

		box.box(L"�Ѿ���һ����Ŀ��Զ����",L"��ʾ");
		return FALSE;
	}

	//�ж��Ƿ��һ�����У�����Ǵ�����Ҫ���ļ�
	//_access�ж��ļ��Ƿ����,�����ڷ���-1��
if( (_access( "C:\\XYKGL", 0 )) == -1 )
{        //�����ļ���
		system("md C:\\XYKGL C:\\XYKGL\\yewu C:\\XYKGL\\Root C:\\XYKGL\\other");  
		box.box(L"���ÿ�����ϵͳ��װ�ɹ���\nΪ�˰�ȫ������޸�Ĭ������",L"�ɹ�");
	    ofstream out("C:\\XYKGL\\Root\\jiyi.op");
        out.close();
}
if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == -1 ){
if( (_access( "C:\\XYKGL\\Root\\CS.batr", 0 )) == -1 )//�ж��ļ��Ƿ�����ж��Ƿ���ʹ�ù��ĺۼ���
{
	//�ж�Ŀ¼�Ƿ�����
if( (_access( "C:\\XYKGL\\yewu", 0 )) == -1 )
	system("md C:\\XYKGL\\yewu");
if( (_access( "C:\\XYKGL\\Root", 0 )) == -1 )
	system("md C:\\XYKGL\\Root");
if( (_access( "C:\\XYKGL\\other", 0 )) == -1 )
	system("md C:\\XYKGL\\other");
if( (_access( "C:\\XYKGL\\head", 0 )) == -1 )
	system("md C:\\XYKGL\\head");
	     m_TextSpeak.Speak(L"Ϊ�˰�ȫ������޸�Ĭ������");//������ʾ�޸�����
          CYWYMT op;
		  op.DoModal();
		}else
	   {//ҵ��Ա.xyk�ļ��粻���ˣ�֮ǰ����ʹ�ù��ĺۼ�ϵͳ�ͻ��ж����
		   m_TextSpeak.Speak(L"ϵͳ��⵽���ж�����Ϊ��������������ӹ���Ա");
		    box.box(L"ϵͳ��⵽���ж�����Ϊ��������������ӹ���Ա",L"����");
	   }	

}
else
{  
	//�ж�Ŀ¼�Ƿ�����
if( (_access( "C:\\XYKGL\\yewu", 0 )) == -1 )
	system("md C:\\XYKGL\\yewu");
if( (_access( "C:\\XYKGL\\Root", 0 )) == -1 )
	system("md C:\\XYKGL\\Root");
if( (_access( "C:\\XYKGL\\other", 0 )) == -1 )
	system("md C:\\XYKGL\\other");
if( (_access( "C:\\XYKGL\\head", 0 )) == -1 )
	system("md C:\\XYKGL\\head");

//��������������¼����

/*	if(op.m_lstYe.GetSize()>=0){
		
	
	}*/
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	//�ж��ļ��ĳ��Ȳ���


	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();



	CScreenWnd* imageWnd = new CScreenWnd;  //����һ���´��ڶ���
	imageWnd->CreatScreenWnd ();			//��������
	imageWnd->CenterWindow ();				//����Ļ����
	imageWnd->ShowWindow (SW_SHOW);			//��ʾ����
	imageWnd->UpdateWindow ();				//���´��ڣ�����OnPait����
	if (imageWnd != NULL)
	{
		imageWnd->SendMessage (WM_CLOSE); //�رմ���
	}


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	CDeng dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
}
}
	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�



	

		return FALSE;
}


//int CCXYCardApp::ExitInstance()
//{
//	// TODO: �ڴ����ר�ô����/����û�
//
//	return CWinApp::ExitInstance();
//}
