/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date March 28, 2018
 *  @file shape.h
 */

// compile guard
#ifndef SHAPE_H
#define SHAPE_H

#include "matrix.h"
#include "x11context.h"
#include <unistd.h>
#include <string>
#include <sstream>
#include <iostream>



/**
 * Shape Class.
 * Abstract base for all other shapes to be based off of.
 */
class shape {
	
protected:
	
	/// 24-BIT unsigned int representing the color of the line.
	/// Each color gets 8-bits.
	unsigned int color;
	
	/// Matrix where the origin of the shape's coordinates are stored.
	matrix* p1;

	/// Constructor.
	shape();

public:

	/// Destructor.
	virtual ~shape();

	/**
	*	Draws the shape.
	*/
	virtual void draw(GraphicsContext* gc) = 0;
	
	/**
	 * @param from Shape to copy from
	 * @return this shape
	 */
	virtual shape& operator=(const shape& from);

	/**
	*	Outputs the properties of the shape to an ostream.
	*/
	virtual std::ostream& out(std::ostream& output) = 0;
	
	/**
	*	Reads and applies shape properties from an istream.
	*/
	virtual void in(std::istream& input) = 0;

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

	/**
	 * Defines a point at the given coordinates.
	 * @param x X-coordinate.
	 * @param y Y-coordinate.
	 * @param z Z-coordinate.
	 */
	point(double x, double y, double z);

	/// Constructor with specified color.
	point(double x, double y, double z, unsigned int col);

	/// Destructor.
	~point();

	/**
	 * Draws the point on the given GraphicsContext
	 * @param gc pointer to the GraphicsContext to draw the point on.
	 */
	void draw(GraphicsContext* gc);

	std::ostream& out(std::ostream& output);
	void in(std::istream& input);
};

/**
 * Line class.
 * Represents a line connecting two coordinates.
 */
class line: public shape {
protected:

	/// Matrix representing the coordinates of the second point of the line.
	matrix* p2;

public:
	/// Constructs a line with given coordinates.
	line(double x0, double y0, double z0, double x1, double y1, double z1);
	/// Same as default constructor with additional color parameter.
	line(double x0, double y0, double z0, double x1, double y1, double z1, unsigned int col);
	~line();
	line& operator=(const line& from);
	void draw(GraphicsContext* gc);
	std::ostream& out(std::ostream& output);
	void in(std::istream& input);
};


/**
 * Circle class.
 * Represents a circle.
 */
class circle: public shape {
protected:

	/// Radius of the circle in pixels.
	unsigned int radius;

public:
	/// Construct a circle explicitly with coordinates and radius specified.
	circle(double x, double y, double z, double r);
	/// Same as default constructor, but includes color.
	circle(double x, double y, double z, double r, unsigned int col);
	~circle();
	circle& operator=(const circle& from);
	void draw(GraphicsContext* gc);
	std::ostream& out(std::ostream& output);
	void in(std::istream& input);
};


/**
 * Triangle class.
 * Represents a triangle.
 */
class triangle: public shape {
protected:

	/// Second corner point of the triangle.
	matrix* p2;
	/// Third corner point of the triangle.
	matrix* p3;

public:
	/// Construct a triangle explicitly with 3 given coordinate points.
	triangle(double x, double y, double z,
			 double x1, double y1, double z1,
			 double x2, double y2, double z2);

	/// Constructor with specified color.
	triangle(double x, double y, double z,
				 double x1, double y1, double z1,
				 double x2, double y2, double z2,
				 unsigned int col);

	/// Construct a triangle with 3 matrices of coordinates.
	triangle(matrix* m0, matrix* m1, matrix* m2);
	~triangle();
	triangle& operator=(const triangle& from);
	void draw(GraphicsContext* gc);
	std::ostream& out(std::ostream& output);
	void in(std::istream& input);
};


#endif
