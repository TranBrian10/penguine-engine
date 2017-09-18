#include "rotate.h"
#include "utilities.h"

/**
* Static
*/
GLfloat Rotate::S_ANGLE = 0;

/**
* Constructor
*/
Rotate::Rotate(int *ac, char *av[]) {
	glutInit(ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(SCREEN_POSITION_X, SCREEN_POSITION_Y);
	glutCreateWindow(SCREEN_TITLE);
	this->init();
	glutDisplayFunc(&managerDisplay);
	glutReshapeFunc(&managerResize);
	glutMouseFunc(&managerMouse);
	glutKeyboardFunc(&managerKeyboard);
	glutIdleFunc(&managerIdle);
	glutMainLoop();
}

/**
* Deleting
*/
Rotate::~Rotate() {}

/**
* Init
*/
void Rotate::init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

/**
* Display 3 squares on the screen, one rotating from left to right,
* another from right to left and the last reducing all their dimensions
* to 0 before recovering its original values.
*/
void Rotate::managerDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// White square
	glPushMatrix();
	glTranslated(25, 0, 0);
	glRotatef(S_ANGLE, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();

	// Burgundy square
	glPushMatrix();
	glRotatef(S_ANGLE, 0.0, 0.0, -1.0);
	glColor3f(0.7, 0.2, 0.3);
	glRectf(-10.0, -10.0, 10.0, 10.0);
	glPopMatrix();

	// Green square
	glPushMatrix();
	glRotatef(S_ANGLE, 0.0, 0.0, 0.0);
	glColor3f(0.7, 1.0, 0.3);
	glRectf(-5.0, -5.0, 5.0, 5.0);
	glPopMatrix();

	glutSwapBuffers();
}

/**
* What's happening when the animation is activated.
*/
void Rotate::managerIdle(void)
{
	Utilities::doSleep(1.0);
	S_ANGLE -= 1;
	glutPostRedisplay();
}

/**
* Allow the resizing of the window, perspective is not respected.
*/
void Rotate::managerResize(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/**
* Manage the mouse, if the left button is clicked, we revive the animation.
* If the right button is clicked, we stop the animation.
*/
void Rotate::managerMouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(&managerIdle);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
	(void)(x);
	(void)(y);
}

/**
* Manage the keyboard, 27 = ESC key.
*/
void Rotate::managerKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
	{
		//exit(0);
        return;
	}
	break;
	}
	(void)(x);
	(void)(y);
}
