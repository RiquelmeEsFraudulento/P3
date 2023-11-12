

#include "auxiliar.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );

    // crear los objetos de la escena....
    // .......completar: ...
    // .....

   cubo = new Cubo(500);
   piramide = new PiramidePentagonal(100, 50);
   cilindro = new Cilindro(4, 10, 100, 50);
   cono = new Cono(3, 10, 100, 50);
   esfera = new Esfera(20, 20, 3, 125);
   copa = new ObjRevolucion("copa.ply", 200);
   peonblanco = new ObjRevolucion("peon.ply", 200);
   peonnegro = new ObjRevolucion("peon.ply", 200);



   const Tupla2f orientation = {0.0,0.0};
   const Tupla3f pos_dir = {0.0,10.0,0.0};
   const Tupla3f pos_pos = {0.0,0.0,0.0};

   luz_pos  = new LuzPosicional (pos_pos, GL_LIGHT0, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0});
   luz_dir  = new LuzDireccional ( orientation, GL_LIGHT1, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0});


   polishedsilver = new Material({ 0.23125f, 0.23125f, 0.23125f, 1.0f }, {0.2775f, 0.2775f, 0.2775f, 1.0f }, {0.773911f, 0.773911f, 0.773911f, 1.0f }, 89.6f);
   emerald = new Material({ 0.0215f, 0.1745f, 0.0215f, 0.55f }, {0.07568f, 0.61424f, 0.07568f, 0.55f }, {0.633f, 0.727811f, 0.633f, 0.55f }, 76.8f);
   cyanplastic = new Material({ 0.0f,0.1f,0.06f ,1.0f}, { 0.0f,0.50980392f,0.50980392f,1.0f}, {0.50196078f,0.50196078f,0.50196078f,1.0f }, 32.0f);
   amathyst = new Material({0.396f, 0.247f, 0.419f, 1.0f}, {0.627f, 0.412f, 0.690f, 1.0f}, {0.529f, 0.467f, 0.537f, 1.0f}, 32.0f);
   polistedcopper = new Material({ 0.2295f, 0.08825f, 0.0275f, 1.0f }, {0.5508f, 0.2118f, 0.066f, 1.0f }, {0.580594f, 0.223257f, 0.0695701f, 1.0f }, 51.2f);
   turquoise = new Material({ 0.1f, 0.18725f, 0.1745f, 0.8f }, {0.396f, 0.74151f, 0.69102f, 0.8f }, {0.297254f, 0.30829f, 0.306678f, 0.8f }, 12.8f);
   gold = new Material({ 0.24725f, 0.1995f, 0.0745f, 1.0f }, {0.75164f, 0.60648f, 0.22648f, 1.0f }, {0.628281f, 0.555802f, 0.366065f, 1.0f },51.2f);


   whitepawn = new Material ({1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}, 0.0f);
   blackpawn = new Material ({0.0f, 0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, 64.0f);


   cubo->setMaterial(*polishedsilver);
   piramide->setMaterial(*emerald); 
   cilindro->setMaterial(*cyanplastic);
   cono->setMaterial(*amathyst);
   esfera->setMaterial(*polishedsilver);
   copa->setMaterial(*turquoise);
   peonblanco->setMaterial(*whitepawn);
   peonnegro->setMaterial(*blackpawn );

   std::cout << "Pulse O para iniciar el modo de selección de objeto" << std::endl;
   std::cout << "Pulse V para iniciar el modo de visualización" << std::endl;


}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
    ejes.draw();
    // COMPLETAR
    //   Dibujar los diferentes elementos de la escena
    // Habrá que tener en esta primera práctica una variable que indique qué objeto se ha de visualizar
    // y hacer 
    // cubo->draw()
    // o    piramide->draw()
   if(modo_alambre){
      glEnable(GL_CULL_FACE);
   }else{
      glDisable(GL_CULL_FACE);
   }

   if(modo_luz){
      glEnable(GL_LIGHTING);
   }else{
      glDisable(GL_LIGHTING);
   }

   glPointSize(5.0); 


   


   if(modo_piramide){
      glPushMatrix (); 
      glTranslatef ( 0, 0, 0 );
      glScalef(1.5,1.5,1.5);
      
      

      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         piramide->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         piramide->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         piramide->draw(2);
      }

      if(modo_suave){
        piramide->draw(3); 
      }

      

      glPopMatrix ();
   }
   

   if(modo_cubo){

      glPushMatrix (); 

      glTranslatef ( 0, 0, 0 );
      glScalef(0.3,0.3,0.3);
      
      
      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         cubo->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         cubo->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         cubo->draw(2);
      }

      if(modo_suave){
        cubo->draw(3); 
      }

      

      glPopMatrix ();
   }

   if(modo_esfera){

      glPushMatrix (); 

      glTranslatef (80,80,0);
      glScalef(0.6,0.6,0.6);;
      glTranslatef ( 0, 0, 0 );

      
      
      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         esfera->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         esfera->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         esfera->draw(2);
      }

      if (modo_suave){
         esfera->draw(3);
      }

      

      glPopMatrix ();
   }

   if(modo_cono){

      glPushMatrix (); 

      glTranslatef (-80,80,0);
      glScalef(1,1,1);
      glTranslatef ( 0, 0, 0 );

      
      
      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         cono->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         cono->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         cono->draw(2);
      }

      if (modo_suave){
         cono->draw(3);
      }

      

      glPopMatrix ();
   }

   if(modo_cilindro){

      glPushMatrix (); 

      glTranslatef (80,-110,0);
      glScalef(1,1,1);
      glTranslatef ( 0, 0, 0 );

      
      
      if (modo_punto) {
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         cilindro->draw(0);
      }


      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         cilindro->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         cilindro->draw(2);
      }

      if (modo_suave){
         cilindro->draw(3);
      }



      

      glPopMatrix ();
   }

   if(modo_copa){

      glPushMatrix (); 

      glTranslatef (0,0,0);
      glScalef(15,15,15);

      
      
      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         copa->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         copa->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         copa->draw(2);
      }

      if (modo_suave){
         copa->draw(3);
      }

      

      glPopMatrix ();
   }


   if(modo_peonblanco){

      glPushMatrix (); 

      glTranslatef (+6,+6,0);
      glScalef(15,15,15);

      
      
      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         peonblanco->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         peonblanco->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         peonblanco->draw(2);
      }

      if (modo_suave){
         peonblanco->draw(3);
      }

      

      glPopMatrix ();
   }


   if(modo_peonnegro){

      glPushMatrix (); 

      glTranslatef (+6,+6,0);
      glScalef(15,15,15);

      
      
      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         peonnegro->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         peonnegro->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         peonnegro->draw(2);
      }

      if (modo_suave){
         peonnegro->draw(3);
      }

      

      glPopMatrix ();
   }

          
}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada(unsigned char tecla, int x, int y) {
    using namespace std;
    cout << "Tecla pulsada: '" << tecla << "'" << endl;
    bool salir = false;
    switch (toupper(tecla)) {
        case 'Q':
            if (modoMenu == SELVISUALIZACION || modoMenu == SELOBJETO) {
                cout << "Pulse O para iniciar el modo de selección de objeto" << endl;
                cout << "Pulse V para iniciar el modo de visualización" << endl;
                modoMenu = NADA;
            } else {
                salir = true;
            }
            break;

        case 'O':
            cout << "Iniciado modo selección de objeto:" << endl;
            cout << "\tTecla ’C’: Se visualiza/oculta el Cubo" << endl;
            cout << "\tTecla ’P’: Se visualiza/oculta la Pirámide" << endl;
            cout << "\tTecla ’H’: Se visualiza/oculta la Esfera" << endl;
            cout << "\tTecla ’J’: Se visualiza/oculta la Cono" << endl;
            cout << "\tTecla ’K’: Se visualiza/oculta la Cilindro" << endl;
            cout << "\tTecla ’G’: Se visualiza/oculta la Copa" << endl;
            cout << "\tTecla ’U’: Se visualiza/oculta el peón blanco" << endl;
            cout << "\tTecla ’Y’: Se visualiza/oculta el peón negro" << endl;
            cout << "\tTecla ’Q’: Se sale del modo selección de objeto." << endl;
            modoMenu = SELOBJETO;
            break;

        case 'V':
            cout << "Iniciado modo de visualización:" << endl;
            cout << "\tPulse D para puntos" << endl;
            cout << "\tPulse L para líneas" << endl;
            cout << "\tPulse S para sólido" << endl;
            cout << "\tPulse A para alambre" << endl;
            cout << "\tPulse I para iluminación" << endl;
            cout << "\tPulse T para sombreado suave" << endl;
            cout << "\tPulse Q para salir" << endl;
            modoMenu = SELVISUALIZACION;
            break;

        case 'C':
            if (modoMenu == SELOBJETO) {
                if (modo_cubo == false) {
                    cout << "Viendo en modo cubo" << endl;
                } else {
                    cout << "Se oculta el modo cubo" << endl;
                }
                modo_cubo = !modo_cubo;
            } else {
                cout << "Para salir pulse Q" << endl;
            }
            break;

        case 'P':
            if (modoMenu == SELOBJETO) {
                if (modo_piramide == false) {
                    cout << "Viendo en modo pirámide" << endl;
                } else {
                    cout << "Se oculta el modo pirámide" << endl;
                }
                modo_piramide = !modo_piramide;
            } else {
                cout << "Para salir pulse Q" << endl;
            }
            break;

        case 'H':
            if (modoMenu == SELOBJETO) {
                if (modo_esfera == false) {
                    cout << "Viendo en modo esfera" << endl;
                } else {
                    cout << "Se oculta el modo esfera" << endl;
                }
                modo_esfera = !modo_esfera;
            } else {
                cout << "Para salir pulse Q" << endl;
            }
            break;

        case 'J':
            if (modoMenu == SELOBJETO) {
                if (modo_cono == false) {
                    cout << "Viendo en modo cono" << endl;
                } else {
                    cout << "Se oculta el modo cono" << endl;
                }
                modo_cono = !modo_cono;
            } else {
                cout << "Para salir pulse Q" << endl;
            }
            break;

        case 'K':
            if (modoMenu == SELOBJETO) {
                if (modo_cilindro == false) {
                    cout << "Viendo en modo cilindro" << endl;
                } else {
                    cout << "Se oculta el modo cilindro" << endl;
                }
                modo_cilindro = !modo_cilindro;
            } else {
                cout << "Para salir pulse Q" << endl;
            }
            break;

        case 'G':
            if (modoMenu == SELOBJETO) {
                if (modo_copa == false) {
                    cout << "Viendo en modo copa" << endl;
                } else {
                    cout << "Se oculta el modo copa" << endl;
                }
                modo_copa = !modo_copa;
            } else {
                cout << "Para salir pulse Q" << endl;
            }
            break;

        case 'U':
            if (modoMenu == SELOBJETO) {
                if (modo_peonblanco == false) {
                    cout << "Viendo en modo peón blanco" << endl;
                } else {
                    cout << "Se oculta el modo peón blanco" << endl;
                }
                modo_peonblanco = !modo_peonblanco;
            } else {
                cout << "Para salir pulse Q" << endl;
            }
            break;

        case 'Y':
            if (modoMenu == SELOBJETO) {
                if (modo_peonnegro == false) {
                    cout << "Viendo en modo peón negro" << endl;
                } else {
                    cout << "Se oculta el modo peón negro" << endl;
                }
                modo_peonnegro = !modo_peonnegro;
            } else {
                cout << "Para salir pulse Q" << endl;
            }
            break;

        case 'D':
            if (modoMenu == SELVISUALIZACION) {
                if (modo_punto == false) {
                    cout << "Viendo en modo punto" << endl;
                } else {
                    cout << "Se oculta el modo punto" << endl;
                }
                modo_punto = !modo_punto;

                cout << "También se desactiva la luz" << endl;
                modo_luz = false;
            } else {
                cout << "Para cambiar modo puntos, active antes el modo selección de visualización (V)" << endl;
            }
            break;

        case 'L':
            if (modoMenu == SELVISUALIZACION) {
                if (modo_linea == false) {
                    cout << "Viendo en modo líneas" << endl;
                } else {
                    cout << "Se oculta el modo líneas" << endl;
                }
                modo_linea = !modo_linea;

                cout << "También se desactiva la luz" << endl;
                modo_luz = false;
            } else {
                cout << "Para cambiar modo líneas, active antes el modo selección de visualización (V)" << endl;
            }
            break;

        case 'S':
            if (modoMenu == SELVISUALIZACION) {
                if (modo_solido == false) {
                    cout << "Viendo en modo sólido" << endl;
                } else {
                    cout << "Se oculta el modo sólido" << endl;
                }
                modo_solido = !modo_solido;

                cout << "También se desactiva la luz" << endl;
                modo_luz = false;
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V)" << endl;
            }
            break;

        case 'A':
            if (modoMenu == SELVISUALIZACION && modo_luz != true) {
                if (modo_alambre == false) {
                    cout << "Viendo en modo alambre" << endl;
                } else {
                    cout << "Se oculta el modo alambre" << endl;
                }
                modo_alambre = !modo_alambre;

                cout << "También se desactiva la luz" << endl;
                modo_luz = false;
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V)" << endl;
            }

            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se modificara la Alfa" << endl;
                    alpha = true;
                } else {
                    cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
                }
            }
            break;

        case 'I':
            if (modoMenu == SELVISUALIZACION) {
                if (modo_luz == false) {
                    cout << "Viendo en modo luz" << endl;
                } else {
                    cout << "Se oculta el modo luz" << endl;
                }
                modo_luz = !modo_luz;
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V)" << endl;
            }
            break;

        case 'T':
            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_suave) {
                    cout << "Viendo sombreado suave" << endl;
                } else {
                    cout << "Se oculta sombreado suave" << endl;
                }
                modo_suave = !modo_suave;
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;

        case '0':
            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se activa la luz 0" << endl;
                    glEnable(GL_LIGHT0);
                } else {
                    cout << "Se oculta la luz 0" << endl;
                    glDisable(GL_LIGHT0);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;

        case '1':
            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se activa la luz 1" << endl;
                    glEnable(GL_LIGHT1);
                } else {
                    cout << "Se oculta la luz 1" << endl;
                    glDisable(GL_LIGHT1);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;

        case '2':
            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se activa la luz 2" << endl;
                    glEnable(GL_LIGHT2);
                } else {
                    cout << "Se oculta la luz 2" << endl;
                    glDisable(GL_LIGHT2);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;

        case '3':
            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se activa la luz 3" << endl;
                    glEnable(GL_LIGHT3);
                } else {
                    cout << "Se oculta la luz 3" << endl;
                    glDisable(GL_LIGHT3);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;

        case '4':
            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se activa la luz 4" << endl;
                    glEnable(GL_LIGHT4);
                } else {
                    cout << "Se oculta la luz 4" << endl;
                    glDisable(GL_LIGHT4);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;

        case '5':
            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se activa la luz 5" << endl;
                    glEnable(GL_LIGHT5);
                } else {
                    cout << "Se oculta la luz 5" << endl;
                    glDisable(GL_LIGHT5);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;

        case '6':
            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se activa la luz 6" << endl;
                    glEnable(GL_LIGHT6);
                } else {
                    cout << "Se oculta la luz 6" << endl;
                    glDisable(GL_LIGHT6);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;
                    
         case '7':
            if (modoMenu == SELVISUALIZACION && modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se activa la luz 7" << endl;
                    glEnable(GL_LIGHT7);
                } else {
                    cout << "Se oculta la luz 7" << endl;
                    glDisable(GL_LIGHT7);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;

        case 'B':
            if (modoMenu == SELVISUALIZACION || modo_luz == true) {
                if (modo_luz == true) {
                    cout << "Se modificara la Beta" << endl;
                    alpha = false;
                } else {
                    cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
                }
            }
            break;

        case '>':
            if (modoMenu == SELVISUALIZACION || modo_luz == true) {
                if (alpha == true) {
                    cout << "Se agranda Alfa" << endl;
                    luz_dir->changeAlfa(5);
                } else {
                    cout << "Se agranda Beta" << endl;
                    luz_dir->changeBeta(5);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;

        case '<':
            if (modoMenu == SELVISUALIZACION || modo_luz == true) {
                if (alpha == true) {
                    cout << "Se encoge Alfa" << endl;
                    luz_dir->changeAlfa(-5);
                } else {
                    cout << "Se encoge Beta" << endl;
                    luz_dir->changeBeta(-5);
                }
            } else {
                cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V) o active el modo luz" << endl;
            }
            break;
    }

    return salir;
}


//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
         Observer_angle_x++ ;
         break;
	   case GLUT_KEY_PAGE_UP:
         Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         Observer_distance /= 1.2 ;
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   const float wx = float(Height)*ratio_xy ;
   glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -Observer_distance );
   glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
}
