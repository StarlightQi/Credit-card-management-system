#include "stdafx.h"
#include "YeList.h"
//业务员动态数组类，就是用来操作登录账号的

CYeList::CYeList(void)
{
}


CYeList::~CYeList(void)
{
}

void CYeList::Ser(CArchive &yar)
{
int iSize=GetSize();
if(yar.IsStoring()){
	yar<<iSize;
}
else
{
	yar>>iSize;
	SetSize(iSize);
}
for(int i=0;i<iSize;i++){

	(*this)[i].Ser(yar);
}
}