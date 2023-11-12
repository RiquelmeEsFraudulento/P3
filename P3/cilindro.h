// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)




class Cilindro : public ObjRevolucion{
private:
    float _h;
    float _r;

public: 
    Cilindro ( 
        const int num_vert_perfil , 
        const int n , 
        const float h , 
        const float r );
} ;

#endif



