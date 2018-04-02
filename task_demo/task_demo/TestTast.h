#pragma once
#include "Tast.h"

#include <string>
using namespace std;

class TestTast :
	public Tast
{
public:
	enum TestTastEnum {
		enum_TAST_TEST_TYPE1 = 1,
		enum_TAST_TEST_TYPE2 = 2
	};
public:
	TestTast(TestTastEnum enumType, string strBuf);
	virtual ~TestTast();
public:
	virtual void Process() override;
protected:
	void TastTestType1();
	void TastTestType2();
protected:
	string	m_strBuf;
};

