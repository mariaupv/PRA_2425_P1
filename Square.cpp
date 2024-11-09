#include <iostream>
#include <cmath>
#include "Square.h"
using namespace std;

bool Square::check(Point2D* vertices){
    double d01 = Point2D::distance(vertices[0],vertices[1]);
 	double d12 = Point2D::distance(vertices[1],vertices[2]);
	double d23 = Point2D::distance(vertices[2],vertices[3]);
	double d30 = Point2D::distance(vertices[3],vertices[0]);
	
	if(d01 == d12 && d01 == d23 && d01 == d30){
		return true;
	}else{
		return false;
	}
}

Square::Square(){
	vs = new Point2D[4];
	vs[0].x = -1;
	vs[0].y = 1;
	vs[1].x = 1;
	vs[1].y = 1;
	vs[2].x = 1;
	vs[2].y = -1;
	vs[3].x = -1;
	vs[3].y = -1;
}
Square::Square(string color, Point2D* vertices){
   vs = new Point2D[4];
   bool rect = check(vertices);
   if(rect == true){
      this->color = color;
      for(int i=0; i<4; i++){
        vs[i]=vertices[i];
      }
   }
   else{
      throw invalid_argument("No se forma un rectángulo");
   }
}

void Square::set_vertices(Point2D* vertices){
	bool sol = check(vertices);
	if(sol == true){
		this->color = color;
		for(int i = 0; i < 4; i++){
			vs[i] = vertices[i];
		}
	}else{
		throw invalid_argument("Vertices NOO forman un cuadrado\n");
	}
}

ostream& operator<<(ostream &out, const Square &square){
	out <<"[Square:"<< "color = " << square.get_color() << "; Vertices: v0 = (" << square.vs[0].x <<","<< square.vs[0].y << "); v1 = (" << square.vs[1].x <<","<< square.vs[1].y << "); v2 = (" << square.vs[2].x <<","<< square.vs[2].y << "); v3 = (" << square.vs[3].x <<","<< square.vs[3].y << ")]";
    return out;
}

void Square::print(){
	cout << *this;
}

