// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef LUZ_POSICIONAL_INCLUDED
#define LUZ_POSICIONAL_INCLUDED

#include "auxiliar.h"
#include "luz.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class LuzPosicional : public Luz { 
public: 
   LuzPosicional ( const Tupla3f & p, GLenum id_, Tupla4f amb, Tupla4f dif, Tupla4f spe );
};

#endif






