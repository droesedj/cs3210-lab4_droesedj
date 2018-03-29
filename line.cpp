/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file line.cpp
 */

#include "shape.h"

line::line(double x0, double y0, double z0, double x1, double y1, double z1){
	p2 = new matrix(4,1);
	(*p1)[0][0] = x0;
	(*p1)[1][0] = y0;
	(*p1)[2][0] = z0;
	(*p1)[3][0] = 1.0;
	(*p2)[0][0] = x1;
	(*p2)[1][0] = y1;
	(*p2)[2][0] = z1;
	(*p2)[3][0] = 1.0;
}

line::~line(){
	delete p2;
}

void line::draw(GraphicsContext* gc){
	gc->drawLine((int)(*p1)[0][0],(int)(*p1)[1][0],(int)(*p2)[0][0],(int)(*p2)[1][0]);
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
