#include "TastManage.h"
#include "PrintTast.h"
#include "TestTast.h"
#include <iostream>
#include <windows.h>

class Test {
public:
	TastManage m_tastManage;
};

int main()
{
	Test t1;
	t1.m_tastManage.Start();
#pragma omp parallel for
	for (int i = 0; i < 50; i++) {
		int tmp = i % 4;
		switch (tmp)
		{
		case 0:
			t1.m_tastManage.AddTast(TastPtr(new PrintTast(PrintTast::enum_TAST_PRINT_TYPE1, "0")));
			break;
		case 1:
			t1.m_tastManage.AddTast(TastPtr(new PrintTast(PrintTast::enum_TAST_PRINT_TYPE2, "1")));
			break;
		case 2:
			t1.m_tastManage.AddTast(TastPtr(new TestTast(TestTast::enum_TAST_TEST_TYPE1, "2")));
			break;
		case 3:
			t1.m_tastManage.AddTast(TastPtr(new TestTast(TestTast::enum_TAST_TEST_TYPE2, "3")));
			break;
		default:
			break;
		}
	}
	// Sleep(1000);
	//t1.m_tastManage.Stop();

	cin.get();
	t1.m_tastManage.Stop();
	return 0;
}