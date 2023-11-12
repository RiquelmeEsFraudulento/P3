// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef LUZ_INCLUDED
#define LUZ_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Luz {
public:
    Tupla4f position;
    GLenum id;
    Tupla4f AmbientColor;
    Tupla4f DifuseColor;
    Tupla4f SpecularColor;
    bool isActivated = false;

    void activate();
    void desactivate();
    bool isActivate();
};


#endif

