/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file circle.cpp
 */

#include "shape.h"

circle::circle(double x, double y, double z, double r){
	radius = (unsigned int)r;
	*p1[0][0] = x;
	*p1[0][1] = y;
//	*p1[0][2] = z;
//	*(p1[0][3]) = 1.0;
}

circle::~circle(){
	//TODO
}

circle& circle::operator=(const circle& from){
	radius = from.radius;
	return *this;
}

void circle::draw(GraphicsContext* gc){
	gc->drawCircle((int)*p1[0][0], (int)*p1[0][1], radius);
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
