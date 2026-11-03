#include "sequence.hpp"
#include <iostream>

sequence::sequence(){
    this->_taille=0;
    this->_tab=nullptr;
}
sequence::sequence(indicesequence taille,couleur* tab){
    this->_taille=taille;
    this->_tab=tab;
}
sequence::sequence(const sequence & S){
    this->_taille=S._taille;
    this->_tab=S._tab;
}
indicesequence sequence::taille() const{
    return this->_taille;
}
std::string sequence::toString(couleur c) const{
    switch (c) {
    case couleur::rouge: return "rouge"; break;
    case couleur::bleu: return "bleu"; break;
    case couleur::jaune: return "jaune"; break;
    case couleur::vert: return "vert"; break;
    default: return "Erreur : cette couleur n'existe pas";
    }
}
couleur sequence::acces(indicesequence i){
    return this->_tab[i];
}
bool sequence::comparer(const sequence & S) const{
    if (this->_taille != S._taille)
        return false;
    else {
        for (indicesequence i=0; i<this->_taille; ++i)
            if (this->_tab[i] != S._tab[i])
                return false;
        return true;
    }
}
void sequence::afficher(const couleur & C) const{
    std::cout<<toString(C);
}
void sequence::afficher(std::ostream & Sortie) const{
    for(indicesequence i=0;i<this->_taille;i++){
        Sortie<<toString(this->_tab[i]);
    }
}
void sequence::vider(){
    delete[] this->_tab;
    this->_taille=0;
}
void sequence::copier(const sequence & S){
    this->vider();
    this->_tab=S._tab;
    this->_taille=S._taille;
}
void sequence::ajouter(const couleur & C){
    if(this->_taille%5==0){
        sequence tmp(*this);
        this->_tab=new couleur[this->_taille+5];
        for (indicesequence i=0; i<tmp._taille; ++i){
            this->_tab[i] = tmp._tab[i];
        }
    }
    this->_tab[this->_taille]=C;
    this->_taille=this->_taille+1;
}
