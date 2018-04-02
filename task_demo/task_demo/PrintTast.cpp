#include "PrintTast.h"
#include <iostream>

PrintTast::PrintTast(PrintTastType type, string printString)
{
	m_iType = type;
	m_strBuf = printString;
}

PrintTast::~PrintTast()
{
}

void PrintTast::Process()
{
	switch (m_iType)
	{
	case PrintTast::enum_TAST_PRINT_TYPE1:
		TastPrintType1();
		break;
	case PrintTast::enum_TAST_PRINT_TYPE2:
		TastPrintType2();
		break;
	default:
		break;
	}
}

void PrintTast::TastPrintType1()
{
	std::cout << "TastPrintType1" << m_strBuf << std::endl;
	m_bIsFinsh = true;
}

void PrintTast::TastPrintType2()
{
	std::cout << "TastPrintType2" << m_strBuf << std::endl;
	m_bIsFinsh = true;
}
