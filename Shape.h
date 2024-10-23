#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"
using namespace std;
class Shape{
    protected:
        string color =  ("red", "green", "blue");

    public:

        Shape();
        Shape(string color);
        string get_color() const;
        void set_color(string c);
        virtual double area() const;
        virtual double perimeter() const;
        virtual void translate(double incx, double incY);
        virtual void print();
};
#endif

