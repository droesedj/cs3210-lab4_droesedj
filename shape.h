/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file shape.h
 */
 
/*
	Specifies the shape class.  Abstract.
*/
#include "matrix.h"
#include "x11context.h"
#include <unistd.h>
#include <iostream>

class shape {
	
protected:
	
	//TODO origin coordinates, bounds, color.
	unsigned int color;
	
	matrix p1;
	
	shape();
	
public:
	
	/**
	*	Draws the shape.
	*/
	virtual void draw(GraphicsContext* gc) = 0;
	
	/**
	*	Erases the shape and frees it from memory.
	*/
	virtual void erase() = 0;
	
	/**
	*	Outputs the properties of the shape to an ostream.
	*/
	virtual std::ostream& out(std::ostream& output);
	
	/**
	*	Reads and applies shape properties from an istream.
	*/
	virtual void in(std::istream& input);
};