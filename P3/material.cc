#include "material.h"

Material::Material ( ){
    diffuse = {1.0, 0.0, 0.0, 1.0}; 
    specular = {0.0, 1.0, 0.0, 1.0}; 
    ambient = {0.0, 0.0, 1.0, 1.0}; 
    brightness = 0.5; 
} 

Material::Material ( Tupla4f amb , Tupla4f dif , Tupla4f spe , float bright ){
    ambient  = amb;
    diffuse = dif;
    specular = spe;
    brightness  = bright;
} 
    
void Material::apply(){
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brightness);

    glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}