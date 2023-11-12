#include "luzposicional.h"

LuzPosicional::LuzPosicional ( const Tupla3f & p, GLenum id_, Tupla4f amb, Tupla4f dif, Tupla4f spe ){
    id = id_;

    AmbientColor = amb;
    DifuseColor = dif;
    SpecularColor = spe;


    position = {p(X), p(Y), p(Z), 1};
}
