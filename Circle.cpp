#include <iostream>
#include <cmath>
#include "Circle.h"
using namespace std;
#define PI 3.1416

Circle::Circle(){//constructor por defecto->color def, centro(0,0) y radio 1
    center.x = 0; 
    center.y = 0;
    radius = 1;
}
Circle::Circle(string color, Point2D center, double radius){//constructor
    this->color = color;
    this->center = center;
    this->radius = radius;
}

Point2D Circle::get_center() const{//consultor de atributo center
    return center;
}
void Circle::set_center(Point2D p){// modificador de center
    center = p;
} 
double Circle::get_radius() const{// consultor de radio
    return radius;
} 
void Circle::set_radius(double r){// modificador de radio
    radius = r;
} 
ostream& operator<< (ostream &out, const Circle &c){
    out << "[Circle:"<< "color = " << c.get_color() << "; center = (" << c.get_center().x <<","<< c.get_center().y << "); radius = " << c.get_radius() << "]";
    return out;
} 
        
double Circle::area()const{
    double area = PI * pow(radius,2);
    return area;
}
double Circle::perimeter()const{
    int perimetro = 2 * PI * radius;
    return perimetro;
}
void Circle::translate(double incX, double incY){
    center.x += incX;
    center.y += incY;

}
void Circle::print(){
    cout << *this;
}

