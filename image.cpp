/**
 *	LAB WEEK 4: SHAPES
 *	CS3210
 *	@author Dennis Droese
 *	@date April 10, 2018
 *  @file image.cpp
 */

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "image.h"
#include "shape.h"

using namespace std;

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

void image::in(istream& input){
	string txtLine;
	while(getline(input,txtLine)){
		string word;

		stringstream(txtLine) >> word;
		istringstream lineOut(txtLine);

		if(word.compare("POINT") == 0){
			point* myPoint = new point(0.0,0.0,0.0);
			myPoint->in(lineOut);
			this->add(myPoint);

		} else if(word.compare("LINE") == 0){
			line* myLine = new line(0.0,0.0,0.0,0.0,0.0,0.0);
			myLine->in(lineOut);
			this->add(myLine);

		} else if(word.compare("TRI") == 0){
			triangle* myTri = new triangle(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0);
			myTri->in(lineOut);
			this->add(myTri);
		} else if(word.compare("CIRCLE") == 0){
			circle* myCircle = new circle(0,0.0,0.0,0.0);
			myCircle->in(lineOut);
			this->add(myCircle);
		} else if(word.compare("IMAGE-END") == 0){
			break;
		}
	}
}

std::ostream& image::out(std::ostream& output){
	output << "IMAGE-START\n";
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
	output << "IMAGE-END\n";
	return output;
}
