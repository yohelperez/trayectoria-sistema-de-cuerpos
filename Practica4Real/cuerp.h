#ifndef CUERP_H
#define CUERP_H

#include <iostream>
#include <cmath>


using namespace std;

class cuerp
{
private:        // Atributos de la clase
    float px;
    float py;
    float masa;
    float radio;
    float vx;
    float vy;


public:         // metodos de la clase
    cuerp(float px_=0, float py_=0, float masa_ =0, float radio_ =0, float vx_=0, float vy_=0);     // constructor
    void set_body(float px_, float py_,float masa_, float radio_, float vx_=0, float vy_=0);        // metodo modificar atributos
    float get_px();             // metodo retorna posicion en x
    float get_py();             // metodo retorna posicion en y
    float get_mas();            // metodo retorna masa
    float cal_ax(float px1,float px2,float py1,float py2,float mas);    // metodo calcula aceleracion en x
    float cal_ay(float px1,float px2,float py1,float py2,float mas);    // metodo calcula aceleracion en y
    void calc_pos(float dt, float acx, float acy);                      // metodo calcula posicion x y y
};

#endif // CUERP_H
