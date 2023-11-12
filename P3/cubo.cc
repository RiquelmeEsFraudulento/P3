#include "auxiliar.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado)
{

   float l = lado/2;

   // inicializar la tabla de vértices
   v.resize(8);

   v[0] = Tupla3f(l, 0, l);
   v[1] = Tupla3f(l, 0, -l);
   v[2] = Tupla3f(-l, 0, -l);
   v[3] = Tupla3f(-l, 0, l);
   v[4] = Tupla3f(l, lado, l);
   v[5] = Tupla3f(l, lado, -l);
   v[6] = Tupla3f(-l, lado, -l);
   v[7] = Tupla3f(-l, lado, l);

   // inicializar la tabla de caras o triángulos:

   

   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   
   f.resize(12);
   f[0] = Tupla3i(3,0,4);
   f[1] = Tupla3i(3,4,7);

   f[2] = Tupla3i(0,1,5);
   f[3] = Tupla3i(0,5,4);

   f[4] = Tupla3i(2,5,1);
   f[5] = Tupla3i(2,6,5);

   f[6] = Tupla3i(3,6,2);
   f[7] = Tupla3i(3,7,6);

   f[8] = Tupla3i(7,4,5);
   f[9] = Tupla3i(7,5,6);

   f[10] = Tupla3i(1,3,2);
   f[11] = Tupla3i(1,0,3);

   setColorSeleccion(getColorSel());
   setColor();
}

void Cubo::setColor(){
    for(int i=0; i<v.size();i++){
        c[0].push_back(c_puntos);
        c[1].push_back(c_linea);
    }
    
}

Tupla3f Cubo::getColorSel(){
   Tupla3f colorsel = {0,0.0,0};
   return colorsel;
}

