#include "luz.h"

void Luz::activate(){
    isActivated = true;
    glEnable(GL_LIGHTING);
    glEnable(id);

    glLightfv(id, GL_DIFFUSE, DifuseColor );
    glLightfv(id, GL_AMBIENT, AmbientColor );
    glLightfv(id, GL_SPECULAR, SpecularColor );
    
    glLightfv(id, GL_POSITION, position);

    
}

void Luz::desactivate(){
    isActivated = false;
    //glDisable(GL_LIGHTING);
    glDisable(id); 
    
       
}

bool Luz::isActivate(){
    return isActivated;
}


