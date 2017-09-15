#include "utilities.h"

Utilities::Utilities() {}

void Utilities::doSleep(int ms)
{
	#ifdef LINUX
		usleep(ms * 1000);
	#endif
	#ifdef WINDOWS
		Sleep(ms);
	#endif
}