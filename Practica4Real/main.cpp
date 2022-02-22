#include <iostream>
#include <fstream>
#include "cuerp.h"              // clase para los cuerpos

using namespace std;

int main(int argc, char *argv[])
{
    int n;

    cout<<"Ingrese Total cuerpos a Interactuar: ";
    cin>>n;
    float ax[n]={0};        // vector que guarda las aceleraciones en x de n cuerpos
    float ay[n]={0};        // vector que guarda las aceleraciones en y de n cuerpos

    cuerp obj[n];           // se crea un vertor de objetos de la clase cuerp con n objetos
    float px=0,py,masa,radio,vx,vy;     // atributos de los objetos
    for(int i =0; i<n;i++){             // for que pide los datos para cada objeto y los asigna
        cout<<"Ingrese posicion en x para el cuerpo"<<(i+1)<<": ";
        cin>>px;
        cout<<"Ingrese posicion en y para cuerpo el cuerpo"<<(i+1)<<": ";
        cin>>py;
        cout<<"Ingrese masa del cuerpo"<<(i+1)<<": ";
        cin>>masa;
        cout<<"Ingrese radio del cuerpo"<<(i+1)<<": ";
        cin>>radio;
        cout<<"Ingrese velocidad en x para cuerpo"<<(i+1)<<": ";
        cin>>vx;
        cout<<"Ingrese velocidad en y para cuerpo"<<(i+1)<<": ";
        cin>>vy;
        obj[i].set_body(px,py,masa,radio,vx,vy);        // asigna atributos a los objetos
        cout<<endl;
    }

 //*****************************************************************************************

    ofstream fout;          // creamos un objeto de la clase ofstream
    fout.open("cuerpo.txt");    // abre archivo para escritura y si no lo encuentra lo crea
    for(int i=0; i<10000; i++){     // for que simula el numero de iteraciones de los cuerpos
        for(int j=0;j<n;j++){       // for para controlar cada objeto
            for(int c=0;c<n;c++){   // for para controlar los siguientes objetos (simular datos de iteracion de un objeto con los demas)
                if(j != c){         // condicional para compara que no se evalue el mismo objeto
                    ax[j] += obj[j].cal_ax(obj[j].get_px(),obj[c].get_px(),obj[j].get_py(),obj[c].get_py(),obj[c].get_mas());   // calcular la aceleracion en x de cada cuerpo
                    ay[j] += obj[j].cal_ay(obj[j].get_px(),obj[c].get_px(),obj[j].get_py(),obj[c].get_py(),obj[c].get_mas());   // calcular la aceleracion en y de cada cuerpo
                }
            }
        }
        for(int i=0;i<n;i++){
            fout<<obj[i].get_px()<<"\t"<<obj[i].get_py()<<"\t"; // guardar posiciones en x y en y de cada cuerpo
        }
        fout<<endl;                             // cambio de linea del archivo

        for(int i=0;i<n;i++){                   // ciclo recorre los objetos
            obj[i].calc_pos(1,ax[i],ay[i]);     //calcula posicion de cada objeto
        }
        for(int i=0;i<n;i++){               // for para recorrer las aceleraciones
            ax[i]=0;                        // inicializo las aceleraciones x en 0
            ay[i]=0;                        // inicializo las aceleraciones y en 0
        }
    }
    fout.close();                           // cerramos el archivo para escritura
    return 0;
}

