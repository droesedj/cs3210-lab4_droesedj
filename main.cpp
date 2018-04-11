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
#include "image.h"
#include <unistd.h>
#include <sstream>
#include <iostream>

int main(void)
{

	std::istringstream pointToReadIn("POINT	19987215		88	275	0	1\n"
									 "CIRCLE	88888		100	475	0	1	40\n"
									 "TRI	16777777		300	100	0	1		250	277	0	1		222	202	0	1");

	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);

	circle* theBigOlCircle = new circle(200.0, 175.0, 0.5, 50.0,
										GraphicsContext::GREEN);

	point* whatsThePoint = new point(100.0, 300.0, 0.0,
									 GraphicsContext::WHITE);

//	whatsThePoint->in(pointToReadIn);

	line* theBestLineEver = new line(20.0, 75.0, 0.0, 300.0, 288.0, 0.0,
									 GraphicsContext::BLUE);

	triangle* theTriHard = new triangle(400.0, 400.0, 0.0,
										450.0, 577.0, 0.0,
										432.0, 588.0, 0.0,
										GraphicsContext::YELLOW);

	image* theImage = new image();

	theImage->add(theBigOlCircle);
	theImage->add(whatsThePoint);
	theImage->add(theBestLineEver);
	theImage->add(theTriHard);

	theImage->in(pointToReadIn);

	theImage->draw(gc);

	theImage->out(std::cout);

	sleep(2);

	theImage->erase();
	delete theImage;

	delete gc;

	return 0;
}
