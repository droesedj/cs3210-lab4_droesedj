/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file line.cpp
 */

#include "shape.h"

line::line(double x0, double y0, double z0, double x1, double y1, double z1){
	p2 = new matrix(1,4);
	(*p1)[0][0] = x0;
	(*p1)[0][1] = y0;
	(*p1)[0][2] = z0;
	(*p1)[0][3] = 1.0;
	(*p2)[0][0] = x1;
	(*p2)[0][1] = y1;
	(*p2)[0][2] = z1;
	(*p2)[0][3] = 1.0;
}

line::~line(){
	delete p2;
}

void line::draw(GraphicsContext* gc){
	gc->drawLine((int)(*p1)[0][0],(int)(*p1)[0][1],(int)(*p2)[0][0],(int)(*p2)[0][1]);
}

void line::erase(){
	//TODO
}

std::ostream& line::out(std::ostream& output){
	//TODO
	return output;
}

void line::in(std::istream& input){
	//TODO
}
