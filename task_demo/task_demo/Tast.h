#pragma once
#include <memory>
class Tast
{
public:
	Tast();
	virtual ~Tast();
public:
	virtual void Process() = 0;
public:
	bool	m_bIsFinsh;
	int		m_iType;
};

typedef std::shared_ptr<Tast> TastPtr;
