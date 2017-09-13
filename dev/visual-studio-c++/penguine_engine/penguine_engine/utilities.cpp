#include "utilities.h"

Utilities::Utilities() {}

void Utilities::doSleep(int ms)
{
	#ifdef __linux__
		usleep(ms * 1000);
	#elif _WIN32
		Sleep(ms);
	#endif
}