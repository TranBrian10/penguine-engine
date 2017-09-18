#pragma once

#ifndef ROTATE_H_
#define ROTATE_H_

#include "GLUT/glut.h"

#include <string>

#define SCREEN_TITLE			"Square rotation"
#define SCREEN_WIDTH			600
#define SCREEN_HEIGHT			600
#define SCREEN_POSITION_X		100
#define SCREEN_POSITION_Y		100

class Rotate
{
public:
	static GLfloat S_ANGLE;

	Rotate(int *ac, char *av[]);
	virtual ~Rotate();

	void init(void);
	static void managerDisplay(void);
	static void managerIdle(void);
	static void managerResize(int, int);
	static void managerMouse(int, int, int, int);
	static void managerKeyboard(unsigned char, int, int);
};

#endif
