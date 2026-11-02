#include "tailleposition.h"

position_t::position_t(coordonnee x, coordonnee y){
    this->_x=x;
    this->_y=y;
}
position_t::position_t(const position_t & P){
    this->_x=P._x;
    this->_y=P._y;
}
coordonnee position_t::x() const{
    return this->_x;
}
coordonnee position_t::y() const{
    return this->_y;
}
void position_t::setx(coordonnee x){
    this->_x=x;
}
void position_t::sety(coordonnee y){
    this->_y=y;
}
bool position_t::comparaison(const position_t & P) const{
    return (this->_x==P._x && this->_y==P._y);
}

taille_t::taille_t(coordonnee largeur, coordonnee hauteur){
    this->_largeur=largeur;
    this->_hauteur=hauteur;
}

coordonnee taille_t::largeur() const{
    return this->_largeur;
}

coordonnee taille_t::hauteur() const{
    return this->_hauteur;
}

void taille_t::setlargeur(coordonnee largeur){
    this->_largeur=largeur;
}

void taille_t::sethauteur(coordonnee hauteur){
    this->_hauteur=hauteur;
}

bool taille_t::comparaison(const taille_t & T) const{
    return (this->_largeur==T._largeur && this->_hauteur==T._hauteur);
}
