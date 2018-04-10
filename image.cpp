/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date April 10, 2018
 *  @file image.cpp
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
	output << "IMAGE START\n";
	if(firstShape != nullptr){
		shape* iterator = firstShape;

		//iterate through all of the shapes.
		while(iterator->getNext() != nullptr){
			iterator->out(output);
			iterator = iterator->getNext();
		}
		//output the last shape
		iterator->out(output);
	}
	output << "IMAGE END\n";
	return output;
}
