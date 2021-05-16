#pragma once
class CGCustomert
{
public:
	CGCustomert(void);
	CGCustomert(CString strBian,CString strName,BOOL bMale,CString strPhoneNo,CString strQQNo,BOOL iZhang,CString strEd,CString strBz,CString strNLing,CString strGong);
	~CGCustomert(void);
public:
	CString m_strBian;
	CString GetName(){return m_strName;}
	BOOL IsMale(){return m_bMale;}
	CString GetPhoneNo(){return m_strPhoneNo;}
	CString GetQQNo(){return m_strQQNo;}
	CString GetBian(){return m_strBian;}
	CString GetEd(){return m_strEd;}
	CString GetBz(){return m_strBz;}
	CString GetNLing(){return m_strNLing;}
	BOOL GetZhang(){return m_iZhang;}
	CString GetGong(){return m_strGong;}
	CString GetImageHead(){return m_strHead;}


	void SetName(CString strName){m_strName=strName;}
	//Bian编号
	void SetBian(CString strBian){m_strBian=strBian;}
	void SetMale(BOOL bMale){m_bMale=bMale;}
	void SetPhoneNo(CString strPhoneNO){m_strPhoneNo=strPhoneNO;}
	void SetQQNo(CString strQQNo){m_strQQNo=strQQNo;}
	//Ed额度
	void SetEd(CString strEd){m_strEd=strEd;}
	//Zhang状态
	void SetZhang(BOOL iZhang){m_iZhang=iZhang;}
	//Bz备注
	void SetBz(CString strBz){m_strBz=strBz;}
	void SetNLing(CString strNLing){m_strNLing=strNLing;}
	void SetGong(CString strGong){m_strGong=strGong;}

	void SetImageHead(CString strHead){m_strHead=strHead;}
	void Serialize(CArchive&ar);
protected:
	
	CString m_strName;//名字
	BOOL m_bMale;//性别
	CString m_strPhoneNo;//电话
	CString m_strQQNo;//QQ
	CString m_strEd;//额度
	BOOL m_iZhang;//状态
	CString m_strBz;//备注
	CString m_strNLing;//年龄
	CString m_strGong;//公司
	CString m_strHead;//头像

};


