#pragma once


#include "afxtempl.h"
#include "Yewu.h"

typedef CArray<CYewu,CYewu>CYewus;

class CYeList:public CYewus
{
public:
	
	CYeList(void);
	~CYeList(void);
	void Ser(CArchive&yar);
};

