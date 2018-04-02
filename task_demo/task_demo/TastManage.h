#pragma once

#include "Tast.h"
#include <list>
#include <thread>
#include <memory>
#include <mutex>
#include <condition_variable>

using namespace std;

class TastManage
{
public:
	TastManage();
	virtual ~TastManage();
public:
	void Start();
	void AddTast(TastPtr tast);
	void Stop();
	void SetThreadNum();
	int  GetTastCount();
protected:
	list<shared_ptr<thread>>	m_threadList;
	condition_variable			m_condVar;
	mutex						m_tastMutex;
	list<TastPtr>				m_tastList;
	int							m_threadNum;
	bool						m_bStop;
};

