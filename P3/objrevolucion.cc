#include "auxiliar.h"
#include "objrevolucion.h"




// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un profile (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias) {
    std::vector<Tupla3f> vertices;

    // Llama a la función ply::read para leer el archivo PLY y obtener los vértices y caras
    ply::read_vertices(archivo, vertices);

    // Llama a la función crearMalla con los vértices y el número de instancias
    crearMalla(vertices, num_instancias);
}


// *****************************************************************************
// objeto de revolución obtenido a partir de un profile (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) {
   crearMalla(archivo, num_instancias);
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> originalprofile, int num_instancias) {
   setColorSeleccion(colorsel);

   float y_ini = originalprofile.front()(Y);
   float y_fin = originalprofile.back()(Y);

   rising = ( y_ini < y_fin);

   std::vector<Tupla3f> profile;

   if(!rising){
      for(int i=originalprofile.size(); i>=0; i--){
         profile.push_back(originalprofile[i]);
         std::cout << "Objeto con profile descendente\n";
      }
   }else {
      profile = originalprofile;
   }


   Tupla2f xz_start = Tupla2f(profile.front()(X), profile.front()(Z));
   Tupla2f xz_finish = Tupla2f(profile.back()(X), profile.back()(Z));

   setPoles(profile, xz_start, xz_finish);

   if(havenorthpole){
      profile.pop_back();
   }
   if(havesouthpole){
      profile.erase(profile.begin());
   }

   int n = num_instancias;
   int m = profile.size();

   float x, z, alfa;

   v.clear();

   for(int i=0; i<n; i++){
      alfa = (i * 2 * PI) / n;

      for(int j=0; j<m; j++){
         x = profile[j](X) * cos(alfa) + profile[j](Z) * sin(alfa);
         z = profile[j](Z) * cos(alfa) - profile[j](X) * sin(alfa);

         v.push_back( Tupla3f(x, profile[j](Y), z) );
      } 
   }

   int a, b;
   f.clear();

   for (int i=0; i<n; i++) {
      for(int j=0; j<m-1; j++) {
         a = m*i + j;
         b = m * ((i + 1) % n) + j;

         f.push_back({a, b, b+1});
         f.push_back({a, b+1, a+1});
      }
   }

   int f1, f2, f3;

   if (havesouthpole){
      v.push_back(southpole);

      for(int i=0; i<n-1; i++) {
         f1 = profile.size()*i;
         f2 = v.size() - 1;
         f3 = f1 + profile.size();

         f.push_back({f1,f2,f3});
      }
      f1 = profile.size() * (n - 1);

      f.push_back({f1, f2, 0});
   }

   if (havenorthpole){
      v.push_back(northpole);

      for(int i=0; i<n-1; i++) {
         f1 = profile.size() * (i + 1) - 1 ;;
         f2 = v.size() - 1;
         f3 = f1 + profile.size();

         f.push_back({f3,f2,f1});
      }
      f1 = profile.size() * n - 1;
      f3 = profile.size() - 1;

      f.push_back({f3,f2,f1});
   }

}


void ObjRevolucion::setPoles(std::vector<Tupla3f> profile, Tupla2f xz_start, Tupla2f xz_finish){
   float x0 = xz_start(0); 
   float x1 = xz_finish(0); 
   float z0 = xz_start(1); 
   float z1 = xz_finish(1); 

   havenorthpole = abs(0.0 - x1) < 1e-7 && abs(0.0 - z1) < 1e-7;
   havesouthpole   = abs(0.0 - x0) < 1e-7 && abs(0.0 - z0) < 1e-7;

   if(havenorthpole){
      northpole = profile.back();
   }
   if(havesouthpole){
      southpole = Tupla3f(profile.front());
   }

}