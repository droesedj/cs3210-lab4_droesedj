/*
 * image.cpp
 *
 *  Created on: Apr 10, 2018
 *      Author: cs3841
 */

#include "image.h"
#include "shape.h"


image::image(){
	firstShape = nullptr;
}

image::~image(){
	if(firstShape != nullptr){
		delete firstShape;
	}
}

image& image::operator=(const image& from){
	if(firstShape != nullptr){
		delete firstShape;
	}

	firstShape = from.firstShape;

	return *this;
}

void image::add(shape* addShape){
	if(firstShape == nullptr){
		firstShape = addShape;
	} else {
		shape* iterator = firstShape;

		//iterate through all of the shapes until next is null
		while(iterator->getNext() != nullptr){
			iterator = iterator->getNext();
		}
		iterator->setNext(addShape);
	}
}

void image::draw(GraphicsContext* gc){
	//TODO
	if(firstShape != nullptr){
		shape* iterator = firstShape;

		//iterate through all of the shapes.
		while(iterator->getNext() != nullptr){
			iterator->draw(gc);
			iterator = iterator->getNext();
		}
		//draw the last shape.
		iterator->draw(gc);
	}
}

void image::erase(){
	if(firstShape != nullptr){
		delete firstShape;
	}
	firstShape = nullptr;
}

void image::in(std::istream& input){
	//TODO
}

std::ostream& image::out(std::ostream& output){
	//TODO
	return output;
}
