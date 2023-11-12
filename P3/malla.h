// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "auxiliar.h"
#include "material.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:

   void draw(int color) ;
   GLuint crearVBO(GLuint tipo_vbo, GLuint tam, GLvoid * puntero_ram);
   void setColor(int c);
   void setColorSeleccion(Tupla3f color_sel);
   void setNormales();
   void setMaterial(Material material);
   std::vector<Tupla3f> v ;   
   std::vector<Tupla3i> f ; 
   std::vector<Tupla3f> c[4] ;
   std::vector<Tupla3f> nv ;  
   
   protected:



   



   const Tupla3f c_puntos = Tupla3f(0.860, 0.0774, 0.403);
   const Tupla3f c_linea = Tupla3f(0.970, 0.763, 0.194);
   const Tupla3f c_solido = Tupla3f(0.0948, 0.790, 0.651);
   const Tupla3f c_seleccionado = Tupla3f(0.781, 0.520, 0.800);


   GLuint id_vbo_v = 0;
   GLuint id_vbo_f = 0;
   GLuint id_vbo_c[4] = {0};
   GLuint id_vbo_nv = 0;

   Material m;

   
} ;


#endif
