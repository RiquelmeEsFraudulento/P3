#include "auxiliar.h"
#include "malla.h"
#include "cono.h"


Cono :: Cono (  const int num_vert_perfil , const int n , 
                        const float h , const float r ){
    _h = h;
    _r = r;

    std::vector<Tupla3f> perfil ;
    perfil.resize(num_vert_perfil);

    perfil[0] = {0,0,0}; 
    perfil[1] = {r,0,0}; 
    perfil[2] = {0,h,0}; 

    crearMalla(perfil, n);                
}