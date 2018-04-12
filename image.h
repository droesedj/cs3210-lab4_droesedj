/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date April 10, 2018
 *  @file image.h
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "matrix.h"
#include "x11context.h"
#include <unistd.h>
#include <iostream>
#include <vector>
#include "shape.h"


class image {
private:

	/// Vector that stores all of the shapes.
	std::vector<shape*> storage;

public:

	/// Default constructor
	image();

	/// Destructor
	~image();

	/**
	 * @param from image to copy from
	 * @return this shape
	 */
	image& operator=(const image& from);

	/**
	 * Adds a given shape to the image.
	 * @param shape Shape to add to the image.
	 */
	void add(shape* shape);

	/**
	 * Draws all shapes in the image onto the given GraphicsContext.
	 * @param gc GraphicsContext to draw on.
	 */
	void draw(GraphicsContext* gc);

	/**
	 * Removes all shapes from the image.
	 */
	void erase();

	/**
	*	Outputs the properties of the image to an ostream.
	*/
	std::ostream& out(std::ostream& output);

	/**
	*	Reads and applies image properties from an istream.
	*/
	void in(std::istream& input);

};

#endif /* IMAGE_H_ */
