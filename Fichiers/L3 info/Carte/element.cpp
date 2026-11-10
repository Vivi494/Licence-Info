#include "element.hpp"

element::element(const position_t & position, const taille_t & taille): _position(position),_taille(taille){}

taille_t element::accestaille() const{
    return _taille;
}

position_t element::accesposition() const{
    return _position;
}

std::string element::tostring() const{
    return _position.tostring()+_taille.tostring();
}

bool element::contientposition(const position_t &P) const{
    if(P.x()<=_position.x()+_taille.largeur() && P.x()>=_position.x() && P.y()<=_position.y()+_taille.hauteur() && P.y()>=_position.y()){
        return true;
    }
    else return false;
}

obstacle::obstacle(const position_t &position, const taille_t &taille) : element(position,taille) {}

std::string obstacle::tostring()const{
    return "obs "+element::tostring();
}

personnage::personnage(const position_t &position, const taille_t &taille, const std::string & nom) : element(position,taille), _nbpoints(0), _nom(nom){}

int personnage::nbpoints()const{
    return _nbpoints;
}

std::string personnage::nom()const{
    return _nom;
}

std::string personnage::tostring()const{
    return "per "+element::tostring()+" "+std::to_string(_nbpoints)+"pts "+_nom;
}

void personnage::ramasser(const objetramassable & O){
    _nbpoints=_nbpoints+O.nbpoints();
}

objetramassable::objetramassable(const position_t &position, const taille_t &taille, const int &nbpoints): element(position,taille), _nbpoints(nbpoints){}

int objetramassable::nbpoints()const{
    return _nbpoints;
}

std::string objetramassable::tostring()const{
    return  "obj "+element::tostring()+" "+std::to_string(_nbpoints)+"pts";
}
