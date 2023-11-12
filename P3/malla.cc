#include "auxiliar.h"
#include "malla.h"

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
// Función de visualización de la malla,


GLuint Malla3D::crearVBO(GLuint tipo_vbo, GLuint tam, GLvoid * puntero_ram){
   GLuint id_vbo;

   glGenBuffers(1, & id_vbo);          //crear nuevo VBO, obtener su id
   glBindBuffer(tipo_vbo, id_vbo);     //activar VBO usando su id

   //Transferencia de datos RAM->GPU
   glBufferData(tipo_vbo, tam, puntero_ram, GL_STATIC_DRAW);

   glBindBuffer(tipo_vbo, 0);          //desactivar VBO

   return id_vbo;
}


void Malla3D::draw(int color)
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....

    if(id_vbo_v == 0) {
      id_vbo_v = crearVBO(GL_ARRAY_BUFFER, v.size() * 3 * sizeof(float), v.data());
   }

   if(id_vbo_f == 0) {
      id_vbo_f = crearVBO(GL_ELEMENT_ARRAY_BUFFER, f.size() * 3 * sizeof(int), f.data());
   }

   if(id_vbo_nv == 0) {
      setNormales();
      id_vbo_nv = crearVBO(GL_ARRAY_BUFFER, nv.size() * 3 * sizeof(float), nv.data());
   }

   setColor(color);

   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_v);
   glVertexPointer(3, GL_FLOAT, 0, 0);
   glBindBuffer(GL_ARRAY_BUFFER, 0);

   if (color == 3) {
      // Apply Gouraud shading
      glEnableClientState( GL_COLOR_ARRAY );
      glBindBuffer(GL_ARRAY_BUFFER, id_vbo_c[0]);  // Assuming you have color information in id_vbo_c[0]
      glColorPointer(3, GL_FLOAT, 0, 0);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
   } else {
      // Use flat shading or other shading as needed
      glEnableClientState( GL_COLOR_ARRAY );       
      glBindBuffer(GL_ARRAY_BUFFER, id_vbo_c[color]);  
      glColorPointer(3, GL_FLOAT, 0, 0);           
      glBindBuffer(GL_ARRAY_BUFFER, 0);
   }

   if (glIsEnabled(GL_LIGHTING)){
      glEnableClientState(GL_NORMAL_ARRAY);
      glBindBuffer(GL_ARRAY_BUFFER, id_vbo_nv);
      glNormalPointer(GL_FLOAT, 0, 0);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
   }

   glEnableClientState(GL_VERTEX_ARRAY);

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_f);
   glDrawElements(GL_TRIANGLES, 3 * f.size(), GL_UNSIGNED_INT, 0);   
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   glDisableClientState(GL_VERTEX_ARRAY);
   glDisableClientState(GL_COLOR_ARRAY);
   glDisableClientState(GL_NORMAL_ARRAY);
}






void Malla3D::setColor(int tipo){
   if(tipo<4){
      for(int i=0; i<v.size();i++){
         c[0].push_back(c_puntos);
         c[1].push_back(c_linea);
         c[2].push_back(c_solido);
      }

      if(id_vbo_c[tipo] == 0){
         id_vbo_c[tipo] = crearVBO(GL_ARRAY_BUFFER, c[tipo].size()*3*sizeof(float), c[tipo].data());
      }
   }

   if(tipo==4){
      c[2].clear();
      for(int i=0; i<v.size();i++){
         c[2].push_back(c_seleccionado);
      }
      
   }
     
}


void Malla3D::setColorSeleccion(Tupla3f color_sel){
   for(int i=0; i<v.size();i++){
      c[3].push_back(color_sel);
   }
}

void Malla3D::setNormales(){
   Tupla3f p, q, r;
   Tupla3f a, b;
   Tupla3f perpendicular, m;

   nv.resize(v.size());
   
   for(int i=0; i<nv.size();i++){
      nv[i] = {0.0, 0.0, 0.0};
   }

   for(int i=0; i<f.size(); i++){
      p = v[f[i](X)];
      q = v[f[i](Y)];
      r = v[f[i](Z)];

      a = q-p;
      b = r-p;

      perpendicular = a.cross(b);

      nv[f[i](X)] = perpendicular  + nv[f[i](X)];
      nv[f[i](Y)] = perpendicular  + nv[f[i](Y)];
      nv[f[i](Z)] = perpendicular  + nv[f[i](Z)];
   }

   for(int i=0; i<nv.size();i++){
      nv[i] = nv[i].normalized();
   }

}


void Malla3D::setMaterial(Material material){
   m = material;
}