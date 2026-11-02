#include "sequence.hpp"

sequence::sequence(){
    this->_taille=0;
    this->_tab=nullptr;
}
sequence::sequence(indicesequence taille,couleur* tab){
    this->_taille=taille;
    this->_tab=tab;
}
