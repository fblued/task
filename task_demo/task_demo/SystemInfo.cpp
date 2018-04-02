#include "SystemInfo.h"

#if !defined (_WIN32) && !defined (_WIN64)  
#define LINUX  
#include <sysconf.h>  
#else  
#define WINDOWS  
#include <windows.h>  
#endif  


SystemInfo::SystemInfo() : iCups(0)
{
}

SystemInfo::~SystemInfo()
{
}

SystemInfo & SystemInfo::Instance()
{
	static SystemInfo info;
	return info;
}

int SystemInfo::GetCpuCount()
{
	if (iCups == 0) {
		iCups = 1;
#if defined (LINUX)  
		iCups = sysconf(_SC_NPROCESSORS_CONF);
#elif defined (WINDOWS)  
		SYSTEM_INFO si;
		GetSystemInfo(&si);
		iCups = si.dwNumberOfProcessors;
#endif
	}
	return iCups;
}
