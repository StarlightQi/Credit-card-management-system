#include "stdafx.h"
#include "Yewu.h"
#include  <io.h>
#include  <stdio.h>
#include  <stdlib.h>
//ҵ��Ա�࣬�˺ŵĸ��ֳ�Ա
CYewu::CYewu(void)
{
	 m_bYMale=FALSE;
	/*if( (_access( "C:\\XYKGL\\Root\\ҵ��Ա.ywy", 0 )) == -1 ){
		m_strYBian=_T("root");
		m_strYQQNo=_T("123456");
		m_strYName=_T("����Ա");
	}*/
}
CYewu::CYewu(CString strYBian,CString strYName,BOOL bYMale,CString strYPhoneNo,CString strYQQNo,CString strYBz)
	:m_strYBian(strYBian),m_strYName(strYName),m_bYMale(bYMale),m_strYPhoneNo(strYPhoneNo),m_strYQQNo(strYQQNo),m_strYBz(strYBz)
{

}

CYewu::~CYewu(void)
{
}

void CYewu::Ser(CArchive&yar)
{
	if(yar.IsStoring()){
		yar<<m_strYBian;
		yar<<m_strYName;
		yar<<m_bYMale;
		yar<<m_strYPhoneNo;
		yar<<m_strYQQNo;
		yar<<m_strYBz;

	
	}
	else
	{
		yar>>m_strYBian;
		yar>>m_strYName;
		yar>>m_bYMale;
		yar>>m_strYPhoneNo;
		yar>>m_strYQQNo;
		yar>>m_strYBz;


	}


}