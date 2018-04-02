#pragma once
class SystemInfo
{
public:
	static SystemInfo & Instance();
	int GetCpuCount();
private:
	SystemInfo();
	~SystemInfo();
private:
	int iCups;
};

