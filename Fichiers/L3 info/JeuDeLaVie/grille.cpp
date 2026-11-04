#include "grille.hpp"

grille::grille(coordonnee longueur,coordonnee largeur): _longueur(longueur),_largeur(largeur),_grille(std::vector<std::vector<etatcellule>>()){
    std::vector<etatcellule> tmp(_longueur,etatcellule::mort);
    _grille=std::vector<std::vector<etatcellule>>(_largeur,tmp);
}
