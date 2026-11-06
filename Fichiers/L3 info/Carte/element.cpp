#include "element.hpp"

element::element(const position_t & position, const taille_t & taille): _position(position),_taille(taille){}

element::element(const taille_t & taille, const position_t & position): _position(position),_taille(taille){}

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

obstacle::obstacle(const position_t &position, const taille_t &taille){

}

obstacle::obstacle(const taille_t &taille, const position_t &position){

}

personnage::personnage(const position_t &position, const taille_t &taille, const int &nbpoints, const std::string & nom){

}

personnage::personnage(const taille_t &taille, const position_t &position, const int &nbpoints, const std::string & nom){

}

objetramassable::objetramassable(const position_t &position, const taille_t &taille, const int &nbpoints){

}

objetramassable::objetramassable(const taille_t &taille, const position_t &position, const int &nbpoints){

}
