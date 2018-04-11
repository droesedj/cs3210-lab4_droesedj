/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file circle.cpp
 */

#include "shape.h"

circle::circle(double x, double y, double z, double r){
	//p1 = new matrix(4,1);
	radius = (unsigned int)r;
	(*p1)[0][0] = x;
	(*p1)[1][0] = y;
	(*p1)[2][0] = z;
	(*p1)[3][0] = 1.0;
}

circle::circle(double x, double y, double z, double r, unsigned int col){
	//p1 = new matrix(4,1);
	radius = (unsigned int)r;
	(*p1)[0][0] = x;
	(*p1)[1][0] = y;
	(*p1)[2][0] = z;
	(*p1)[3][0] = 1.0;

	color = col;
}

circle::~circle(){
}

circle& circle::operator=(const circle& from){
	radius = from.radius;
	return *this;
}

void circle::draw(GraphicsContext* gc){
	gc->setColor(color);
	gc->drawCircle((int)(*p1)[0][0], (int)(*p1)[1][0], radius);
}

std::ostream& circle::out(std::ostream& output){
	output << "CIRCLE\t" << color << "\t"
			<< (*p1)[0][0] << ' '
			<< (*p1)[1][0] << ' '
			<< (*p1)[2][0] << ' '
			<< (*p1)[3][0] << '\t'
			<< radius << '\n';
	return output;
}

void circle::in(std::istream& input){
	std::string garbage;

	input>>garbage>>color>>
	(*p1)[0][0]>>(*p1)[1][0]>>(*p1)[2][0]>>(*p1)[3][0]
	>>radius;
}
