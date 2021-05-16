#pragma once
#include "afxtempl.h"
#include "GCustomert.h"
typedef CArray<CGCustomert,CGCustomert>CGCustomerts;



class CGCustomerList:public CGCustomerts
{
public:
	CGCustomerList(void);
	~CGCustomerList(void);
	void Serialize(CArchive&ar);
	static void ShowImage(HWND hDlg,CString pathName,int pictureId);
	static void PaintChart(HWND hDlg,int arr[],int ControlId);
};

