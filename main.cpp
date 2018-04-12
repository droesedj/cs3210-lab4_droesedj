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

	matrix* p0 = new matrix(4,1);
	(*p0)[0][0] = 50.0;
	(*p0)[1][0] = 200.0;
	(*p0)[2][0] = 99.0;
	(*p0)[3][0] = 1.0;

	matrix* p1 = new matrix(4,1);
	(*p1)[0][0] = 75.0;
	(*p1)[1][0] = 222.0;
	(*p1)[2][0] = 283.0;
	(*p1)[3][0] = 1.0;

	matrix* p2 = new matrix(4,1);
	(*p2)[0][0] = 100.0;
	(*p2)[1][0] = 300.0;
	(*p2)[2][0] = 88.0;
	(*p2)[3][0] = 1.0;

	matrix* p3 = new matrix(4,1);
	(*p3)[0][0] = 124.0;
	(*p3)[1][0] = 300.0;
	(*p3)[2][0] = 84.0;
	(*p3)[3][0] = 1.0;

	matrix* p4 = new matrix(4,1);
	(*p4)[0][0] = 50.0;
	(*p4)[1][0] = 365.0;
	(*p4)[2][0] = 45.0;
	(*p4)[3][0] = 1.0;

	std::vector<matrix*> myVect;

	myVect.push_back(p0);
	myVect.push_back(p1);
	myVect.push_back(p2);
	myVect.push_back(p3);
	myVect.push_back(p4);

	std::istringstream pointToReadIn("POINT	19987215		88	275	0	1\n"
									 "CIRCLE	88888		100	475	0	1	40\n"
									 "TRI	16777777		300	100	0	1		250	277	0	1		222	202	0	1\n"
									 "POLY	12345678		55 205 99 1		77 227 283 1	105 305 88 1	129 309 84 1	55 369 45 1		88 88 88 1 		123 321 1 1");

	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);

	circle* theBigOlCircle = new circle(200.0, 175.0, 0.5, 50.0,
										GraphicsContext::GREEN);

	point* whatsThePoint = new point(100.0, 300.0, 0.0,
									 GraphicsContext::WHITE);

	line* theBestLineEver = new line(20.0, 75.0, 0.0, 300.0, 288.0, 0.0,
									 GraphicsContext::BLUE);

	triangle* theTriHard = new triangle(400.0, 400.0, 0.0,
										450.0, 577.0, 0.0,
										432.0, 588.0, 0.0,
										GraphicsContext::YELLOW);

	poly* myPolygon = new poly(myVect, GraphicsContext::CYAN);


	image* theImage = new image();

	theImage->add(theBigOlCircle);
	theImage->add(whatsThePoint);
	theImage->add(theBestLineEver);
	theImage->add(theTriHard);

	theImage->add(myPolygon);

	theImage->in(pointToReadIn);

	theImage->draw(gc);

	theImage->out(std::cout);

	sleep(6);

	theImage->erase();
	delete theImage;

	delete gc;

	return 0;
}
