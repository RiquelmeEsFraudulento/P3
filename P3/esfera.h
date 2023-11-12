// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

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

class Esfera : public ObjRevolucion{
private:
    float _r;
    

public: 
    Esfera ( 
        const int m , 
        const int n , 
        const float h , 
        const float r );
} ;




#endif
