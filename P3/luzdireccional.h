// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef LUZ_DIRECCIONAL_INCLUDED
#define LUZ_DIRECCIONAL_INCLUDED

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

class LuzDireccional : public Luz{
   protected: 
      float alpha; 
      float beta; 
      
   public : 
      LuzDireccional ( const Tupla2f & orientation, GLenum id_ , Tupla4f amb, Tupla4f dif, Tupla4f spe ) ; 

      void changeAlfa( float increment ) ; 
      void changeBeta ( float increment ) ; 
      
};




#endif
