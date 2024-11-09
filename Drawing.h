#ifndef DRAWING_H
#define DRAWING_H

#include <stdexcept>
#include <iostream>
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Shape.h"
#include "Point2D.h"
#include "List.h"
#include "ListLinked.h"

using namespace std;

class Drawing{

	private:
		List<Shape*>* shapes;
	
	public:
		Drawing();
		~Drawing();
		void add_front(Shape* shape);
		void add_back(Shape* shape);
		void print_all();
		double get_area_all_circles();
		void move_squares(double incX, double incY);

};
#endif
