#include "stdafx.h"
#include "GCustomerList.h"
//顾客动态数组类

CGCustomerList::CGCustomerList(void)
{
}


CGCustomerList::~CGCustomerList(void)
{
}
void CGCustomerList::Serialize(CArchive &ar)
{
int iSize=GetSize();
if(ar.IsStoring()){
	ar<<iSize;
}
else
{
	ar>>iSize;
	SetSize(iSize);
}
for(int i=0;i<iSize;i++){

	(*this)[i].Serialize(ar);
}


}
void CGCustomerList::ShowImage(HWND hDlg,CString pathName,int pictureId)
{
	CImage image;
	CRect rect;
	image.Load(pathName);
	HWND hWnd=GetDlgItem(hDlg,pictureId);
	GetClientRect(hWnd,&rect);
	HDC hdc=GetDC(hWnd);
	image.Draw(hdc,rect);

}

void CGCustomerList::PaintChart(HWND hDlg,int arr[],int ControlId)
{
CRect rect;
HWND hWnd=GetDlgItem(hDlg,ControlId);
GetClientRect(hWnd,&rect);
int dx=(rect.right-rect.left)/50;
int dy=(rect.bottom-rect.top)/90;
int L=rect.left,R=rect.right,T=rect.top,B=rect.bottom;
CPaintDC dc(CWnd::FromHandle(hWnd));

dc.MoveTo(L+dx*2,B-dy*3);
dc.LineTo(L+dx*49,B-dy*3);

dc.MoveTo(L+dx*49,B-dy*3);
dc.LineTo(L+dx*48,B-dy*2);
dc.MoveTo(L+dx*49,B-dy*3);
dc.LineTo(L+dx*48,B-dy*4);
//画y轴
dc.MoveTo(L+dx*2,B-dy*3);
dc.LineTo(L+dx*2,B-dy*77);

dc.MoveTo(L+dx*2,B-dy*77);
dc.LineTo(L+dx*2-dy,B-dy*77+dx);
dc.MoveTo(L+dx*2,B-dy*77);
dc.LineTo(L+dx*2+dy,B-dy*77+dx);

int x=L+dx*-8;
int y=B-dy*3;


CString strnum;

for(int i=1;i<=3;i++)
{
CRect rc;
rc.left=x+i*dx*15;
rc.right=rc.left+dx*7;
rc.bottom=y;
rc.top=rc.bottom-dy*arr[i-1];
dc.SetBkMode(TRANSPARENT);



strnum.Format(_T("%d人"),arr[i-1]);
dc.TextOutW((rc.left+rc.right)/2-3*dx+20,rc.bottom-dy*(arr[i-1]+8),strnum);

CBrush brush;
brush.CreateSolidBrush(RGB(100*i,200,0));
dc.FillRect(&rc,&brush);

}







}