#include "auxiliar.h"
#include "malla.h"
#include "piramidepentagonal.h"

PiramidePentagonal::PiramidePentagonal(float h, float r)
{

   // inicializar la tabla de vértices
        
   // inicializar la tabla de caras o triángulos:
   
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

   float lado = 2.0 *r * cos(DEG_TO_RAD*36);

   float x1 = lado * cos(DEG_TO_RAD*54);
   float z1 = r - lado*cos(DEG_TO_RAD*36);//r * cos(DEG_TO_RAD*54);

   float x2 = lado/2.0;
   float z2 = r * cos(DEG_TO_RAD*54);

   // P1: inicializar la tabla de vértices
   v.resize(6);
   
   for(int i=0; i<5; i++){
      v[i] = Tupla3f(r*cos(i*72*DEG_TO_RAD), 0, r*sin(i*72*DEG_TO_RAD));
   }
   
   v[5] = Tupla3f(0, h, 0);

   // P1: inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior)
   f.resize(8);
   f[0] = Tupla3i(5,0,4);
   f[1] = Tupla3i(5,4,3);
   f[2] = Tupla3i(5,3,2);
   f[3] = Tupla3i(5,2,1);
   f[4] = Tupla3i(5,1,0);

   f[5] = Tupla3i(0,1,4);
   f[6] = Tupla3i(4,1,2);
   f[7] = Tupla3i(4,2,3);

   // inicializar la/s tabla/s de colores
   setColorSeleccion(getColorSel());
   setColor();

   
   
}

void PiramidePentagonal::setColor(){
    for(int i=0; i<v.size();i++){
        c[0].push_back(c_puntos);
        c[1].push_back(c_linea);
    }

    /*
    
    c[2].resize(8);
    c[2][0]={1,0,1}; //+x-y+z
    c[2][1]={1,0,0}; //+x-y-z
    c[2][2]={0,0,0}; //-x-y-z
    c[2][3]={0,0,1}; //-x-y+z
    c[2][4]={1,1,1}; //+x+y+z
    c[2][5]={1,1,0}; //+x+y-z
    c[2][6]={0,1,0}; //-x+y-z
    c[2][7]={0,1,1}; //-x+y+z
    
    
    
    */
    
}

Tupla3f PiramidePentagonal::getColorSel(){
   Tupla3f colorsel = {0,0.0,0};
   return colorsel;
}