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

	circle* theBigOlCircle = new circle(200.0, 175.0, 0.5, 50.0);

	point* whatsThePoint = new point(100.0, 300.0, 0.0);

	line* theBestLineEver = new line(20.0, 75.0, 0.0, 300.0, 288.0, 0.0);

	triangle* theTriHard = new triangle(400.0, 400.0, 0.0,
										450.0, 577.0, 0.0,
										432.0, 588.0, 0.0);

	// draw some cool stuff
	gc->setColor(GraphicsContext::GREEN);
	theBigOlCircle->draw(gc);

	gc->setColor(GraphicsContext::RED);
	theBestLineEver->draw(gc);

	gc->setColor(GraphicsContext::BLUE);
	theTriHard->draw(gc);

	gc->setColor(GraphicsContext::YELLOW);
	whatsThePoint->draw(gc);

	sleep(2);

	delete theBigOlCircle;
	delete theBestLineEver;
	delete theTriHard;
	delete whatsThePoint;

	delete gc;

	return 0;
}
