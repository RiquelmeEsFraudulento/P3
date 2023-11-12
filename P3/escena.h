#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "piramidepentagonal.h"
#include "esfera.h"
#include "cono.h"
#include "cilindro.h"
#include "objrevolucion.h"
#include "objply.h"
#include "ply_reader.h"
#include "luzdireccional.h"
#include "luzposicional.h"
typedef enum {NADA, SELOBJETO,SELVISUALIZACION} menu;
class Escena
{

   private:

   bool modo_piramide = 0;
   bool modo_cubo = 0;
   bool modo_esfera = 0;
   bool modo_cono = 0;
   bool modo_cilindro = 0;
   bool modo_copa = 0;
   bool modo_peonblanco = 0;
   bool modo_peonnegro = 0;

   bool modo_punto  = 0;
   bool modo_linea  = 0;
   bool modo_solido = 0;
   bool modo_alambre = 0;
   bool modo_luz = 1;
   bool modo_suave = 0;
   


   bool alpha = true;

 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();
    


   void clear_window();

   menu modoMenu=NADA;
   Ejes ejes;
   Cubo * cubo = nullptr ; 
   PiramidePentagonal * piramide= nullptr ;
   Esfera * esfera = nullptr;
   Cono * cono = nullptr;
   Cilindro * cilindro = nullptr;
   ObjRevolucion * copa = nullptr;
   ObjRevolucion * peonblanco = nullptr;
   ObjRevolucion * peonnegro = nullptr;
    

   LuzDireccional * luz_dir = nullptr;
   LuzPosicional * luz_pos = nullptr;


   Material * polishedsilver = nullptr;
   Material * emerald = nullptr;
   Material * cyanplastic = nullptr;
   Material * amathyst = nullptr;
   Material * polistedcopper = nullptr;
   Material * turquoise = nullptr;
   Material * gold = nullptr;

   Material * whitepawn = nullptr;
   Material * blackpawn = nullptr;


   public:

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	void dibujar() ;

	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );



};
#endif
