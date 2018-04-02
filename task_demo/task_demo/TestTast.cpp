#include "TestTast.h"

#include <iostream>

TestTast::TestTast(TestTastEnum enumType, string strBuf)
{
	m_iType = enumType;
	m_strBuf = strBuf;
}

TestTast::~TestTast()
{
}

void TestTast::Process()
{
	switch (m_iType)
	{
	case enum_TAST_TEST_TYPE1:
		TastTestType1();
		break;
	case enum_TAST_TEST_TYPE2:
		TastTestType2();
		break;
	default:
		break;
	}
}

void TestTast::TastTestType1()
{
	cout << "TastTestType1" << m_strBuf << endl;
}

void TestTast::TastTestType2()
{
	cout << "TastTestType2" << m_strBuf << endl;
}
