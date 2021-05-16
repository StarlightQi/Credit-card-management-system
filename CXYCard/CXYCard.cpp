
// CXYCard.cpp : 定义应用程序的类行为。
//运行函数

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
#include "TextSpeaker.h" //调用语音阅读类
gds::CTextSpeaker m_TextSpeak;//定义语音阅读成员对象

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;

// CCXYCardApp

BEGIN_MESSAGE_MAP(CCXYCardApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()



// CCXYCardApp 构造

CCXYCardApp::CCXYCardApp()
{
	
	
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CCXYCardApp 对象

CCXYCardApp theApp;


// CCXYCardApp 初始化

BOOL CCXYCardApp::InitInstance()
{	
	CCXYCardDlg box;	//调用消息提示函数的类对象
	 HANDLE  hMutex = ::CreateMutex(NULL, FALSE, L"只能运行一个");//只能运行一个程序，标识
	if (GetLastError() == ERROR_ALREADY_EXISTS){

		box.box(L"已经有一个项目在远行了",L"提示");
		return FALSE;
	}

	//判断是否第一次运行，如果是创建必要的文件
	//_access判断文件是否存在,不存在返回-1；
if( (_access( "C:\\XYKGL", 0 )) == -1 )
{        //创建文件夹
		system("md C:\\XYKGL C:\\XYKGL\\yewu C:\\XYKGL\\Root C:\\XYKGL\\other");  
		box.box(L"信用卡管理系统安装成功，\n为了安全起见请修改默认密码",L"成功");
	    ofstream out("C:\\XYKGL\\Root\\jiyi.op");
        out.close();
}
if( (_access( "C:\\XYKGL\\Root\\业务员.ywy", 0 )) == -1 ){
if( (_access( "C:\\XYKGL\\Root\\CS.batr", 0 )) == -1 )//判断文件是否存在判断是否有使用过的痕迹；
{
	//判断目录是否完整
if( (_access( "C:\\XYKGL\\yewu", 0 )) == -1 )
	system("md C:\\XYKGL\\yewu");
if( (_access( "C:\\XYKGL\\Root", 0 )) == -1 )
	system("md C:\\XYKGL\\Root");
if( (_access( "C:\\XYKGL\\other", 0 )) == -1 )
	system("md C:\\XYKGL\\other");
if( (_access( "C:\\XYKGL\\head", 0 )) == -1 )
	system("md C:\\XYKGL\\head");
	     m_TextSpeak.Speak(L"为了安全起见请修改默认密码");//语音提示修改密码
          CYWYMT op;
		  op.DoModal();
		}else
	   {//业务员.xyk文件早不到了，之前又有使用过的痕迹系统就会判断这个
		   m_TextSpeak.Speak(L"系统检测到你有恶意行为，如有意见请连接管理员");
		    box.box(L"系统检测到你有恶意行为，如有意见请连接管理员",L"警告");
	   }	

}
else
{  
	//判断目录是否完整
if( (_access( "C:\\XYKGL\\yewu", 0 )) == -1 )
	system("md C:\\XYKGL\\yewu");
if( (_access( "C:\\XYKGL\\Root", 0 )) == -1 )
	system("md C:\\XYKGL\\Root");
if( (_access( "C:\\XYKGL\\other", 0 )) == -1 )
	system("md C:\\XYKGL\\other");
if( (_access( "C:\\XYKGL\\head", 0 )) == -1 )
	system("md C:\\XYKGL\\head");

//正常启动跳到登录界面

/*	if(op.m_lstYe.GetSize()>=0){
		
	
	}*/
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	//判断文件的长度不能


	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();



	CScreenWnd* imageWnd = new CScreenWnd;  //建立一个新窗口对象
	imageWnd->CreatScreenWnd ();			//创建窗口
	imageWnd->CenterWindow ();				//在屏幕中央
	imageWnd->ShowWindow (SW_SHOW);			//显示窗口
	imageWnd->UpdateWindow ();				//更新窗口，激活OnPait函数
	if (imageWnd != NULL)
	{
		imageWnd->SendMessage (WM_CLOSE); //关闭窗口
	}


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	CDeng dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
}
}
	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。



	

		return FALSE;
}


//int CCXYCardApp::ExitInstance()
//{
//	// TODO: 在此添加专用代码和/或调用基
//
//	return CWinApp::ExitInstance();
//}
