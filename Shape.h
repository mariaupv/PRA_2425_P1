#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"
using namespace std;
class Shape{
    protected:
        string color;

    public:

        Shape(); // Crea figura de color rojo
        Shape(string color); // Crea figura de un color específico
        string get_color() const; // Devuelve el color de relleno de la figura
        void set_color(string c); // Modifica color de relleno
        virtual double area() const = 0; // Calcula área de la figura
        virtual double perimeter() const = 0; // Calcula perímetro de la figura
        virtual void translate(double incx, double incY) = 0; // traslada figura sobre espacio de representación
        virtual void print() = 0; // Imprime info básica de la figura
};
#endif

