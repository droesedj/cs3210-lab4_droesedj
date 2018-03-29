/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file circle.cpp
 */

#include "shape.h"

circle::circle(double x, double y, double z, double r){
	p1 = new matrix(4,1);
	radius = (unsigned int)r;
	(*p1)[0][0] = x;
	(*p1)[1][0] = y;
	(*p1)[2][0] = z;
	(*p1)[3][0] = 1.0;
}

circle::~circle(){
	//TODO
}

circle& circle::operator=(const circle& from){
	radius = from.radius;
	return *this;
}

void circle::draw(GraphicsContext* gc){
	double x = (*p1)[0][0];
	double y = (*p1)[1][0];
	gc->drawCircle((int)x, (int)y, radius);
}

void circle::erase(){
	//TODO
}

std::ostream& circle::out(std::ostream& output){
	//TODO
	return output;
}

void circle::in(std::istream& input){
	//TODO
}
