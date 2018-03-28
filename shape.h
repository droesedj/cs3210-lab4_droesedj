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
	
	//TODO
	unsigned int color;
	
	matrix* p1;
	
	shape();
	virtual ~shape();

public:

	/**
	*	Draws the shape.
	*/
	virtual void draw(GraphicsContext* gc) = 0;
	
	/**
	*	Erases the shape and frees it from memory.
	*/
	virtual void erase() = 0;
	
	/*
	 * @param from Shape to copy from
	 * @return this shape
	 */
	virtual shape& operator=(const shape& from);

	/**
	*	Outputs the properties of the shape to an ostream.
	*/
	virtual std::ostream& out(std::ostream& output);
	
	/**
	*	Reads and applies shape properties from an istream.
	*/
	virtual void in(std::istream& input);

	/**
	 * @return Matrix containing the origin of the shape.
	 */
	virtual matrix* getOrigin();
};

///===================
/// DERIVED CLASSES
///===================

/**
 * Point class.
 * Represents a point (1 pixel).
 */
class point: public shape {
protected:

public:

	point(double x, double y, double z);
	~point();

	void draw(GraphicsContext* gc);
	void erase();
	std::ostream& out(std::ostream& output);
	void in(std::istream& input);
};

/**
 * Line class.
 * Represents a line connecting two coordinates.
 */
class line: public shape {
protected:

	matrix* p2;

public:

	line(double x0, double y0, double z0, double x1, double y1, double z1);
	~line();

	void draw(GraphicsContext* gc);
	void erase();
	std::ostream& out(std::ostream& output);
	void in(std::istream& input);
};


/**
 * Circle class.
 * Represents a circle.
 */
class circle: public shape {
protected:

	unsigned int radius;

public:
	circle(double x, double y, double z, double r);
	~circle();
	circle& operator=(const circle& from);
	void draw(GraphicsContext* gc);
	void erase();
	std::ostream& out(std::ostream& output);
	void in(std::istream& input);
};
