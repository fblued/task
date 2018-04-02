#if 0
// c++ 11
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include <string>
#include <sstream>

using namespace std;

bool bstop = 0;
list<string> strList;
mutex		mut;
condition_variable cond;

void Produce()
{
	while (!bstop){
		unique_lock<mutex> lock(mut);
		while (strList.size() == 0) {
			cond.wait(lock);
			if (bstop) break;
		}
		string str = strList.front();
		strList.pop_front();
		lock.unlock();

		std::cout << str << std::endl;
	}

	return;
}

void Consume()
{
	while (!bstop){
		stringstream mystr;
		mystr << time(NULL);

		unique_lock<mutex> lock(mut);
		strList.push_back(mystr.str());
		lock.unlock();
		cond.notify_all();
	}

	return;
}

int main()
{
	thread t1(Produce), t2(Produce), t3(Consume);
	
	cin.get();

	bstop = true;
	t1.join();
	t2.join();
	t3.join();
	
	cin.get();
	return 0;
}
#endif