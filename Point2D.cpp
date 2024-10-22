#include <iostream>
#include <math.h>
#include "Point2D.h"



	Point2D::Point2D(double x, double y){
		this -> x = x;
		this -> y = y;
	}

	double Point2D::distance(const Point2D &a, const Point2D &b){
		int uno = pow(a.x - b.x, 2);
		int dos = pow(a.y - b.y, 2);
		int d = sqrt(uno + dos);
		return d;
	}

	bool operator==(const Point2D &a, const Point2D &b){
		return (a.x == b.x && a.y == b.y);
	}

	bool operator!=(const Point2D &a, const Point2D &b){
		return (a.x != b.x || a.y != b.y);
	}

	std::ostream& operator<<(std::ostream &out, const Point2D &p){
		out << "( " << p.x << "," << p.y << ")";
		return out;
	}


