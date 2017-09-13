#pragma once

#ifdef __linux__
	#include <unistd.h>
#endif
#ifdef _WIN32
	#include <windows.h>
#endif

#ifndef UTILITIES_H_
#define UTILITIES_H_

class Utilities
{
public:
	static void doSleep(int ms);
private:
	Utilities();
};

#endif