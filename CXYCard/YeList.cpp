#include "stdafx.h"
#include "YeList.h"
//ҵ��Ա��̬�����࣬��������������¼�˺ŵ�

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