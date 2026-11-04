#include "sequence.hpp"
#include <iostream>

sequence::sequence(): _tab(std::vector<couleur>()){
}
sequence::sequence(std::vector<couleur> tab): _tab(std::vector<couleur>()){
    this->_tab=tab;
}
sequence::sequence(const sequence & S): _tab(std::vector<couleur>()){
    this->_tab=S._tab;
}
std::vector<couleur>::size_type sequence::taille() const{
    return this->_tab.size();
}
std::string sequence::toString(couleur c) const{
    switch (c) {
    case couleur::rouge:
        return "rouge";
        break;
    case couleur::bleu:
        return "bleu";
        break;
    case couleur::jaune:
        return "jaune";
        break;
    case couleur::vert:
        return "vert";
        break;
    default:
        return "Erreur : cette couleur n'existe pas";
        break;
    }
}
couleur sequence::acces(std::vector<couleur>::size_type i){
    return this->_tab[i];
}
bool sequence::comparer(const sequence & S) const{
    if (this->taille() != S.taille())
        return false;
    else {
        for (std::vector<couleur>::size_type i=0; i<this->taille(); ++i)
            if (this->_tab[i] != S._tab[i])
                return false;
        return true;
    }
}
void sequence::afficher(const couleur & C) const{
    std::cout<<toString(C);
}
void sequence::afficher(std::ostream & Sortie) const{
    for(std::vector<couleur>::size_type i=0;i<this->taille();i++){
        Sortie<<toString(this->_tab[i])<<" ";
    }
}
void sequence::vider(){
    this->_tab.clear();
}
void sequence::copier(const sequence & S){
    this->vider();
    for(std::vector<couleur>::size_type i=0 ; i<S.taille();i++){
        this->ajouter(S._tab[i]);
    }
}
void sequence::ajouter(const couleur & C){
    _tab.push_back(C);
}
