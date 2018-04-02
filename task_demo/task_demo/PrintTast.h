#pragma once
#include "Tast.h"

#include <string>
using namespace std;

class PrintTast :
	public Tast
{
public:
	enum PrintTastType{
		enum_TAST_PRINT_TYPE1 = 1,
		enum_TAST_PRINT_TYPE2 = 2
	};
public:
	PrintTast(PrintTastType type, string printString);
	virtual ~PrintTast();
public:
	virtual void Process();
protected:
	void TastPrintType1();
	void TastPrintType2();

protected:
	std::string m_strBuf;
};

