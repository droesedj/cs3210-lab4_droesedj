/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file point.cpp
 */

#include "shape.h"

point::point(double x, double y, double z){
	(*p1)[0][0] = x;
	(*p1)[1][0] = y;
	(*p1)[2][0] = z;
	(*p1)[3][0] = 1.0;
}

point::point(double x, double y, double z, unsigned int col){
	(*p1)[0][0] = x;
	(*p1)[1][0] = y;
	(*p1)[2][0] = z;
	(*p1)[3][0] = 1.0;
	color = col;
}

point::~point(){
	//TODO
}

void point::draw(GraphicsContext* gc){
	gc->setColor(color);
	gc->setPixel((int)(*p1)[0][0], (int)(*p1)[1][0]);
}

std::ostream& point::out(std::ostream& output){
	output << "POINT\t" << color << "\n\t"
			<< (*p1)[0][0] << '\t'
			<< (*p1)[1][0] << '\t'
			<< (*p1)[2][0] << '\t'
			<< (*p1)[3][0] << '\n';
	return output;
}

void point::in(std::istream& input){
	//TODO
	input.get();
	color = (unsigned int)(input.get());
	(*p1)[0][0] = (double)(input.get());
	(*p1)[1][0] = (double)(input.get());
	(*p1)[2][0] = (double)(input.get());
	(*p1)[3][0] = (double)(input.get());
}
