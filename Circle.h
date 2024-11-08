#include <iostream>
#include "Shape.h"
using namespace std;

class Circle : public Shape{
    private :
        Point2D center;
        double radius;
    
    public:
        Circle(); // Crea círculo por defecto
        Circle(string color, Point2D center, double radius);
        Point2D get_center() const;
        void set_center(Point2D p);
        double get_radius() const;
        void set_radius(double r);
        friend ostream& operator<< (ostream &out, const Circle &c);
        
        double area() const override;
        double perimeter() const override;
        void translate(double incx, double incY) override;
        void print() override;
};
