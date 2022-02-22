#include "cuerp.h"
#include <math.h>

cuerp::cuerp(float px_, float py_, float masa_, float radio_, float vx_, float vy_):px(px_),py(py_),masa(masa_),radio(radio_),vx(vx_),vy(vy_){      // constructor

}

void cuerp::set_body(float px_, float py_,float masa_, float radio_, float vx_, float vy_)  // metodo modificar atributos
{
   px=px_;
   py=py_;
   masa=masa_;
   radio=radio_;
   vx=vx_;
   vy=vy_;
}

float cuerp::get_px(){  // metodo retorna psicion x
    return px;
}

float cuerp::get_py(){  // metodo retorna posicion y
    return py;
}

float cuerp::get_mas(){ // metodo retorna masa
    return masa;
}
float cuerp::cal_ax(float px1,float px2,float py1,float py2,float mas){     // metodo calcular aceleracion en x
    float ax;                                       // variable a almacenar aceleracion y a retornar
    ax = ((1*mas)/(pow((px2-px1),2)+(pow((py2-py1),2))))*(cos(atan2((py2-py1),(px2-px1))));     // operacion con la formula para allar la aceleracion en x
    return ax;          // retorno
}
float cuerp::cal_ay(float px1,float px2,float py1,float py2,float mas){     // metodo calcular aceleracion en y
    float ay;                                       // variable a almacenar aceleracion y a retornar
    ay = ((1*mas)/(pow((px2-px1),2)+(pow((py2-py1),2))))*(sin(atan2((py2-py1),(px2-px1))));     // operacion con la formula para allar la aceleracion en y
    return ay;          // retorno
}

//calcula la posicion de un cuerpo despues de dt unidades de tiempo
void cuerp::calc_pos(float dt, float acx, float acy){
    px+=vx*dt+acx*dt*dt/2;
    py+=vy*dt+acy*dt*dt/2;
    vy+=acy*dt;
    vx+=acx*dt;
}
