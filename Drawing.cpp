#include <iostream>
#include <ostream>
#include <typeinfo>
#include <typeindex>
#include "Drawing.h"


using namespace std;

Drawing::Drawing(){
    shapes = new ListLinked<Shape*>;
}

Drawing::~Drawing(){
    delete[] shapes;
}
void Drawing::add_front(Shape* shape){
    shapes->prepend(shape);
}
void Drawing::add_back(Shape* shape){
    shapes->append(shape);
}
void Drawing::print_all(){
    for(int i = 0; i < shapes->size(); i ++){
        shapes->get(i)->print();
    }
}
double Drawing::get_area_all_circles(){
   double areatotal=0.0; 
   for (int i = 0; i < shapes->size(); i++) {
       Shape* s = shapes->get(i); // se obtiene el puntero de una figura de la lista shapes y se guarda en s
       type_index tipo(typeid(*s)); // el tipo en s se almacena en tipo
       if (tipo == type_index(typeid(Circle))) { // Se verifica si la figura en s es un círculo
           areatotal += s->area(); // si es un círculo se suman todas las áreas
       }
   }
   return areatotal; // Devuelve el área total de los círculos.
}


void Drawing::move_squares(double incX, double incY){
    for(int i=0; i<shapes->size(); i++){
      Shape *s= shapes->get(i);  
      type_index ti(typeid(*s));
      if(ti == type_index(typeid(Square))){ //Si es un cuadrado
         s->translate(incX, incY); // se mueven los cuadrados a la posición indicada
      }
   }
}