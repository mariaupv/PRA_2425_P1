#include <iostream>
#include "Shape.h"
using namespace std;

//string color
Shape::Shape(){
    color = "red";
}
Shape::Shape(string color){
    if(color == "red" || color == "green" || color == "blue"){
        this -> color = color;
    }else{
        throw invalid_argument("Color no válido.\n");
    }
}


string Shape::get_color() const{
    return color;
}

void Shape::set_color(string c){
    if(c == "red" || c == "green" || c == "blue"){
        color = c;
    }else{
        throw invalid_argument("El color no es valido.\n");
    }
}