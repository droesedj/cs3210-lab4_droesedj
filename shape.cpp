/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file shape.cpp
 */

#include "shape.h"

shape::shape(){
	color = 0;
	p1 = new matrix(4,1);
}

shape::~shape(){
	delete p1;
}

shape& shape::operator=(const shape& from){
	color = from.color;

	delete p1;

	p1 = from.p1;

	return *this;
}

matrix* shape::getOrigin(){
	return p1;
}

std::ostream& shape::out(std::ostream& output){
	return output;
}

void shape::in(std::istream& input){

}
