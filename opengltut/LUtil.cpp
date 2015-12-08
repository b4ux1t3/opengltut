/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 001

#include "LUtil.h"

//The current color rendering mode
int gColorMode = COLOR_MODE_CYAN;

//The projection scale
GLfloat gProjectionScale = 1.f;

bool initGL()
{
	//Initialize Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);

	//Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

	//Check for error
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		return false;
	}

	return true;
}

void update()
{

}

void render()
{
	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//Render quad
	glBegin(GL_QUADS);
	glVertex2f(-0.1f, -0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(-0.1f, 0.1f);

	glVertex2f(0.2f, 0.2f);
	glVertex2f(0.2f, -0.2f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 0.1f);

	glEnd();

	//Update screen
	glutSwapBuffers();
}
