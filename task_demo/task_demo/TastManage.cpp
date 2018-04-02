#include "TastManage.h"
#include "SystemInfo.h"
#include <functional>
#include <algorithm>


TastManage::TastManage()
{
	m_bStop = false;
	// m_threadNum = SystemInfo::Instance().GetCpuCount();
	m_threadNum = SystemInfo::Instance().GetCpuCount() * 2;
}

TastManage::~TastManage()
{
	Stop();
}

int  TastManage::GetTastCount()
{
	int retCount = 0;
	retCount = m_tastList.size();
	return retCount;
}

void TastManage::AddTast(TastPtr tast)
{
	{
		unique_lock<mutex> lock(m_tastMutex);
		m_tastList.push_back(tast);
	}
	m_condVar.notify_one();
}

void TastManage::Start()
{
	function<void()> tempFun = [&]()
	{
		while (!m_bStop)
		{
			unique_lock<mutex> lock(m_tastMutex);
			while(m_tastList.size() == 0) {
				m_condVar.wait(lock);
				if (m_bStop) break;
			}
			if(m_bStop) continue;
			TastPtr tastPtr = m_tastList.front();
			m_tastList.pop_front();
			lock.unlock();

			tastPtr->Process();
		}
		return;
	};

	for (int i = 0; i < m_threadNum; ++i)
	{
		m_threadList.push_back(shared_ptr<thread>(new thread(tempFun)));
	}
}

void TastManage::Stop()
{
	m_bStop = true;
	m_condVar.notify_all();
	for_each(m_threadList.begin(), m_threadList.end(), [](shared_ptr<thread> thr) {
		try {
			thr->join();
		}
		catch(...){

		}
	});
}
