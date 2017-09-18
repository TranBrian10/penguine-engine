#pragma once

#ifdef LINUX
	#include <unistd.h>
#endif
#ifdef WINDOWS
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