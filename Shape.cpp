#include <iostream>
#include "Shape.h"
using namespace std;

//string color
Shape::Shape(){
    color = "red";
}
Shape::Shape(string color){
    if(color == "rojo" || color == "verde" || color == "azul"){
        this -> color = color;
    }else{
        throw invalid_argument("Color no válido.\n");
    }
}


string Shape::get_color() const{
    return color;
}

void Shape::set_color(string c){
    if(c == "rojo" || c == "verde" || c == "azul"){
        c = color;
    }else{
        throw invalid_argument("El color no es valido.\n");
    }
}