#include "grille.hpp"
#include <iostream>

grille::grille(const coordonnee & hauteur, const coordonnee & largeur): _hauteur(hauteur),_largeur(largeur),_grille(std::vector<std::vector<etatcellule>>()){
    std::vector<etatcellule> tmp(_largeur,etatcellule::mort);
    _grille=std::vector<std::vector<etatcellule>>(_hauteur,tmp);
}

void grille::vider(){
    for(std::vector<std::vector<etatcellule>>::size_type i(0);i<_hauteur;i++){
        for(std::vector<etatcellule>::size_type j(0);j<_largeur;j++){
            _grille[i][j]=etatcellule::mort;
        }
    }
}

bool grille::vivante(const coordonnee & hauteur, const coordonnee & largeur)const{
    if(_grille[hauteur][largeur]==etatcellule::vivant){
        return true;
    }
    else{
        return false;
    }
}

void grille::generer(const coordonnee & hauteur, const coordonnee & largeur){
    _grille[hauteur][largeur]=etatcellule::vivant;
}

void grille::tuer(const coordonnee & hauteur, const coordonnee & largeur){
    _grille[hauteur][largeur]=etatcellule::mort;
}

void grille::afficher()const{
    for(std::vector<std::vector<etatcellule>>::size_type i(0);i<_hauteur;i++){
        for(std::vector<etatcellule>::size_type j(0);j<_largeur;j++){
            if(vivante(i,j)){
                std::cout<<"[*]";
            }
            else{
                std::cout<<"[ ]";
            }
        }
        std::cout<<'\n';
    }
}

bool grille::appartientCellule(const coordonnee & hauteur, const coordonnee & largeur)const{
    if(hauteur<=_hauteur && largeur<=_largeur){
        return true;
    }
    return false;
}

void grille::ajouterOscillateurLigne(const coordonnee & hauteur, const coordonnee & largeur){
    if(appartientCellule(hauteur, largeur) && appartientCellule(hauteur, largeur+2)){
        generer(hauteur,largeur);
        generer(hauteur,largeur+1);
        generer(hauteur,largeur+2);
    }
}

void grille:: ajouterFloraison(const coordonnee & hauteur, const coordonnee & largeur){
    if(appartientCellule(hauteur, largeur) && appartientCellule(hauteur+2, largeur+4)){
        generer(hauteur,largeur+1);
        generer(hauteur,largeur+2);
        generer(hauteur,largeur+3);
        generer(hauteur+1,largeur);
        generer(hauteur+1,largeur+2);
        generer(hauteur+1,largeur+4);
        generer(hauteur+2,largeur+1);
        generer(hauteur+2,largeur+2);
        generer(hauteur+2,largeur+3);
    }
}

void grille::ajouterPlaneur(const coordonnee & hauteur, const coordonnee & largeur){
    if(appartientCellule(hauteur, largeur) && appartientCellule(hauteur+2, largeur+2)){
        generer(hauteur,largeur);
        generer(hauteur,largeur+1);
        generer(hauteur,largeur+2);
        generer(hauteur+1,largeur+2);
        generer(hauteur+2,largeur+1);
    }
}

void grille::ajouterOscillateurCroix(const coordonnee & hauteur, const coordonnee & largeur){
    if(appartientCellule(hauteur, largeur) && appartientCellule(hauteur+2, largeur+2)){
        generer(hauteur,largeur+1);
        generer(hauteur+1,largeur);
        generer(hauteur+1,largeur+1);
        generer(hauteur+1,largeur+2);
        generer(hauteur+2,largeur+1);
    }
}

void grille::ajouterstructure(const structure & S, const coordonnee & hauteur, const coordonnee & largeur){
    switch(S){
    case structure::oscillateurligne:
        ajouterOscillateurLigne(hauteur,largeur);
        break;
    case structure::floraison:
        ajouterFloraison(hauteur,largeur);
        break;
    case structure::planeur:
        ajouterPlaneur(hauteur,largeur);
        break;
    case structure::oscillateurcroix:
        ajouterOscillateurCroix(hauteur,largeur);
        break;
    }
}
