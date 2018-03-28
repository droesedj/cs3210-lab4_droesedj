/**LAB WEEK 4: SHAPES
 * CS3210
 * @author Dennis Droese
 * @file main.cpp
 * @date March 28, 2018
 */

/*
 * A simple test for drawing shapes n' stuff
 */


#include "x11context.h"
#include "shape.h"
#include <unistd.h>
#include <iostream>

int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);


	// draw some lines
	gc->setColor(GraphicsContext::GREEN);

	(new circle(200.0,175.0,5.0,50.0))->draw(gc);




	sleep(8);

	//delete bigOlCircle;

	//delete gc;

	return 0;
}
