/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file shape.cpp
 */

#include "shape.h"

shape::shape(){
	// default color
	color = GraphicsContext::WHITE;
	p1 = new matrix(4,1);
	next = nullptr;
}

shape::~shape(){
	delete p1;
	// Let the destructor kill the next shape in the chain and so on.
	if(next != nullptr){
		delete next;
	}
}

shape& shape::operator=(const shape& from){
	color = from.color;

	delete p1;
	delete next;

	p1 = from.p1;
	next = from.next;

	return *this;
}

matrix* shape::getOrigin(){
	return p1;
}

std::ostream& shape::out(std::ostream& output){
	//TODO
	output << "SHAPE\t" << color << '\t';
	return output;
}

void shape::in(std::istream& input){
	//TODO
}

shape* shape::getNext(){
	return next;
}

void shape::setNext(shape* shape){
	next = shape;
}
