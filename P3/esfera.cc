#include "auxiliar.h"
#include "malla.h"
#include "esfera.h"


Esfera :: Esfera (  const int m , const int n , 
                        const float h , const float r ){
    _r = r;
    std::vector<Tupla3f> perfil ;

    perfil.resize(m);

    float x, y, alfa;

    for(int i=0; i < m; i++){
        alfa = i * PI / m;

        x = -r * sin(alfa);
        y = -r * cos(alfa);

        perfil[i] = {x, y, 0.0};
    }

    perfil.push_back({0.0,r,0.0});

    crearMalla(perfil, n);                
}
