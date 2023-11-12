// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "objply.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class ObjRevolucion : public Malla3D
{
    


   public:
        ObjRevolucion();
        ObjRevolucion(const std::string & archivo, int num_instancias);
        ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias);
        void crearMalla(std::vector<Tupla3f> originalprofile, int num_instancias);
        void setPoles(std::vector<Tupla3f> profile, Tupla2f xz_start, Tupla2f xz_finish);


private:
    bool rising = true;
    bool havenorthpole = false;
    bool havesouthpole = false;
    Tupla3f northpole;
    Tupla3f southpole;
    Tupla3f colorsel = {0,0,1.0};

} ;




#endif
