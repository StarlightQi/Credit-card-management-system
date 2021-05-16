#include "stdafx.h"
#include "GCustomert.h"
//¹Ë¿ÍÀà

CGCustomert::CGCustomert(void)
{
	m_bMale=FALSE;
	m_iZhang=TRUE;
	m_strHead=_T("");
	m_strEd=_T("0");
	m_strQQNo=_T("00000");
	m_strPhoneNo=_T("00000000000");
	m_strNLing=_T("18");
}
CGCustomert::CGCustomert(CString strBian,CString strName,BOOL bMale,CString strPhoneNo,CString strQQNo,BOOL iZhang,CString strEd,CString strBz,CString strNLing,CString strGong)
	:m_strBian(strBian),m_strName(strName),m_bMale(bMale),m_strPhoneNo(strPhoneNo),m_strQQNo(strQQNo),m_iZhang(iZhang),m_strBz(strBz),m_strNLing(strNLing),m_strEd(strEd),m_strGong(strGong)
{
}

CGCustomert::~CGCustomert(void)
{
}

void CGCustomert::Serialize(CArchive&ar)
{
	if(ar.IsStoring()){
		ar<<m_strBian;
		ar<<m_strName;
		ar<<m_bMale;
		ar<<m_strPhoneNo;
		ar<<m_strQQNo;
		ar<<m_iZhang;
		ar<<m_strBz;
		ar<<m_strNLing;
		ar<<m_strEd;
		ar<<m_strGong;
		ar<<m_strHead;
	}else
	{
		ar>>m_strBian;
		ar>>m_strName;
		ar>>m_bMale;
		ar>>m_strPhoneNo;
		ar>>m_strQQNo;
		ar>>m_iZhang;
		ar>>m_strBz;
		ar>>m_strNLing;
		ar>>m_strEd;
		ar>>m_strGong;
		ar>>m_strHead;
	}

}