#include <iostream>
#include <cmath>
#include "Rectangle.h"
using namespace std;
static int const N_VERTICES = 4; 

bool Rectangle::check(Point2D* vertices){
    double dist01 = Point2D::distance(vertices[0], vertices[1]);
    double dist12 = Point2D::distance(vertices[1], vertices[2]);
    double dist23 = Point2D::distance(vertices[2], vertices[3]);
    double dist30 = Point2D::distance(vertices[3], vertices[0]);
    if(dist01 == dist23 && dist12 == dist30){
        return true;
    }else{
        return false;
    }
}

Rectangle::Rectangle(){//vértices: v0=(-1,0.5); v1=(1,0.5), v2=(1,-0.5), y v3=(-1,-0.5).
    vs = new Point2D[4];
    vs[0].x = -1;
    vs[0].y = 0.5;
    vs[1].x = 1;
    vs[1].y = 0.5;
    vs[2].x = 1;
    vs[2].y = -0.5;
    vs[3].x = -1;
    vs[3].y = -0.5;
}
Rectangle::Rectangle(string color, Point2D* vertices){
    vs = new Point2D[4];
    bool rect = check(vertices);
    if(rect == true){
        this->color = color;
        for(int i = 0; i < 4; i++){
            vs[i] = vertices[i];
        }
    }else{
        throw invalid_argument("Valores del rectangulo no validos\n");
    }
}
Rectangle::Rectangle(const Rectangle &r){
    vs = new Point2D[4];
    for(int i = 0; i < 4; i++){
        vs[i] = r.vs[i];
    }
    color = r.color;
}
Rectangle::~Rectangle(){
    delete[] vs;
}
Point2D Rectangle::get_vertex(int ind) const{
    if(ind > N_VERTICES){
        throw out_of_range("Valor fuera del rango\n");
    }else{
        return vs[ind];
    }
}
Point2D Rectangle::operator[](int ind) const{
    if(ind > N_VERTICES){
        throw out_of_range("Valor fuera del rango\n");
    }else{
        return vs[ind];
    }
}
void Rectangle::set_vertices(Point2D* vertices){ //modificar vertices a partir de vertices
    bool nuevo = check(vertices);
    if(nuevo == true){
        this->color = color;
        for(int i = 0; i < 4; i++){
            vs[i] = vertices[i];
        }
    }else{
        throw invalid_argument("Valores del rectangulo no validos\n");
    }
}
Rectangle& Rectangle::operator=(const Rectangle &r){
    vs = new Point2D[4];
    for(int i = 0; i < 4; i++){
        vs[i] = r.vs[i];
    }
    color = r.color;
    return *this;

}

ostream& operator<<(ostream &out, const Rectangle &r){
    out <<"[Rectangle:"<< "color = " << r.get_color() << "; v0 = (" << r.vs[0].x <<","<< r.vs[0].y << "); v1 = (" << r.vs[1].x <<","<< r.vs[1].y << "); v2 = (" << r.vs[2].x <<","<< r.vs[2].y << "); v3 = (" << r.vs[3].x <<","<< r.vs[3].y << ")]";
    return out;
}

double Rectangle::area()const{
    double dist01 = Point2D::distance(vs[0], vs[1]);
    double dist12 = Point2D::distance(vs[1], vs[2]);
    return dist01 * dist12;
}
double Rectangle::perimeter()const{
    double dist01 = Point2D::distance(vs[0], vs[1]);
    double dist12 = Point2D::distance(vs[1], vs[2]);
    double dist23 = Point2D::distance(vs[2], vs[3]);
    double dist30 = Point2D::distance(vs[3], vs[0]);
    return dist01 + dist12 + dist23 + dist30;
}
void Rectangle::translate(double incX, double incY){
    for(int i = 0; i < N_VERTICES; i++){
        vs[i].x += incX;
        vs[i].y += incY;
    }

}
void Rectangle::print(){
    cout << *this;
}