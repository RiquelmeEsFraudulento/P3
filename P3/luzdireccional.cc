#include "luzdireccional.h"

LuzDireccional::LuzDireccional( const Tupla2f & orientation, GLenum id_ , Tupla4f amb, Tupla4f dif, Tupla4f spe ){
    
    id = id_;
    AmbientColor = amb;
    DifuseColor = dif;
    SpecularColor = spe;
    alpha = orientation(X);
    beta  = orientation(Y);

    float x = sin(alpha) * cos(beta);
    float y = sin(alpha) * cos(beta);
    float z = cos(alpha);

    position = {x, y, z, 0};
}
    

void LuzDireccional::changeAlfa( float increment ){
   alpha += increment;
   Tupla4f original_value = position;

   if (alpha > PI ){
      alpha = PI;

   } else if (alpha < -PI){
      alpha = PI;
   }

   position(0) = sin(alpha) * cos(beta) * sqrt(original_value.lengthSq());
   position(1) = sin(beta) * sin(alpha) * sqrt(original_value.lengthSq());
   position(2) = cos(alpha) * sqrt(original_value.lengthSq());
}

void LuzDireccional::changeBeta ( float increment ){
    beta += increment;
   Tupla4f original_value = position;
    
   if (beta > PI ){
      beta = PI;

   } else if (beta < -PI){
      beta = -PI;
   }

   position(0) = sin(alpha) * cos(beta) * sqrt(original_value.lengthSq());
   position(1) = sin(alpha) * sin(beta) * sqrt(original_value.lengthSq());
   position(2) = cos(alpha) * sqrt(original_value.lengthSq());
}