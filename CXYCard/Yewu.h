#pragma once
class CYewu
{
public:
	CYewu(void);
	CYewu(CString strYBian,CString strYName,BOOL bYMale,CString strYPhoneNo,CString strYQQNo,CString strYBz);
	~CYewu(void);
public:
	CString GetYName(){return m_strYName;}
	BOOL IsYMale(){return m_bYMale;}
	CString GetYPhoneNo(){return m_strYPhoneNo;}
	CString GetYQQNo(){return m_strYQQNo;}
	CString GetYBian(){return m_strYBian;}
	CString GetYBz(){return m_strYBz;}

	void SetYName(CString strName){m_strYName=strName;}
	//Bian编号
	void SetYBian(CString strYBian){m_strYBian=strYBian;}
	void SetYMale(BOOL bYMale){m_bYMale=bYMale;}
	void SetYPhoneNo(CString strYPhoneNO){m_strYPhoneNo=strYPhoneNO;}
	void SetYQQNo(CString strYQQNo){m_strYQQNo=strYQQNo;}
	void SetYBz(CString strYBz){m_strYBz=strYBz;}

	void Ser(CArchive&yar);
	

protected:
	CString m_strYBian;//编号
	CString m_strYName;//名字
	BOOL m_bYMale;//性别
	CString m_strYPhoneNo;//手机号
	CString m_strYQQNo;//密码成员
	CString m_strYBz;//备注

};



