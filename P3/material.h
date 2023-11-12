// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef MATERIAL_INCLUDED
#define MATERIAL_INCLUDED

#include "auxiliar.h"


// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Material { 
private : 
    Tupla4f ambient = {0.0, 0.0, 1.0, 1.0};    
    Tupla4f diffuse = {1.0, 0.0, 0.0, 1.0}; 
    Tupla4f specular = {0.0, 1.0, 0.0, 1.0}; 
    float brightness = 0.5; 
    
public : 
    Material ();
    Material ( Tupla4f amb , Tupla4f dif , Tupla4f spe , float bright ); 
    void apply(); 
};

#endif



