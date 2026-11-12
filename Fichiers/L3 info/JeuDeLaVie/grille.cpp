#include "grille.hpp"
#include <iostream>

grille::grille(const coordonnee & largeur, const coordonnee & hauteur): _hauteur(hauteur),_largeur(largeur),_grille(std::vector<std::vector<etatcellule>>()){
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

bool grille::vivante(const coordonnee & largeur, const coordonnee & hauteur)const{
    if(_grille[hauteur][largeur]==etatcellule::vivant){
        return true;
    }
    else{
        return false;
    }
}

void grille::generer(const coordonnee & largeur, const coordonnee & hauteur){
    _grille[hauteur][largeur]=etatcellule::vivant;
}

void grille::tuer(const coordonnee & largeur, const coordonnee & hauteur){
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

bool grille::appartientCellule(const coordonnee & largeur, const coordonnee & hauteur)const{
    if(hauteur<_hauteur && hauteur>=0 && largeur>=0 && largeur<_largeur){
        return true;
    }
    return false;
}

void grille::ajouterOscillateurLigne(const coordonnee & largeur, const coordonnee & hauteur){
    if(appartientCellule(largeur,hauteur) && appartientCellule(largeur+2,hauteur)){
        generer(largeur,hauteur);
        generer(largeur+1,hauteur);
        generer(largeur+2,hauteur);
    }
}

void grille:: ajouterFloraison(const coordonnee & largeur, const coordonnee & hauteur){
    if(appartientCellule(largeur,hauteur) && appartientCellule(largeur+4,hauteur+2)){
        generer(largeur+1,hauteur);
        generer(largeur+2,hauteur);
        generer(largeur+3,hauteur);
        generer(largeur,hauteur+1);
        generer(largeur+2,hauteur+1);
        generer(largeur+4,hauteur+1);
        generer(largeur+1,hauteur+2);
        generer(largeur+2,hauteur+2);
        generer(largeur+3,hauteur+2);
    }
}

void grille::ajouterPlaneur(const coordonnee & largeur, const coordonnee & hauteur){
    if(appartientCellule(largeur, hauteur) && appartientCellule(largeur+2,hauteur+2)){
        generer(largeur,hauteur);
        generer(largeur+1,hauteur);
        generer(largeur+2,hauteur);
        generer(largeur+2,hauteur+1);
        generer(largeur+1,hauteur+2);
    }
}

void grille::ajouterOscillateurCroix(const coordonnee & largeur, const coordonnee & hauteur){
    if(appartientCellule(largeur, hauteur) && appartientCellule(largeur+2, hauteur+2)){
        generer(largeur+1,hauteur);
        generer(largeur,hauteur+1);
        generer(largeur+1,hauteur+1);
        generer(largeur+2,hauteur+1);
        generer(largeur+1,hauteur+2);
    }
}

void grille::ajouterstructure(const structure & S, const coordonnee & largeur, const coordonnee & hauteur){
    switch(S){
    case structure::oscillateurligne:
        ajouterOscillateurLigne(largeur,hauteur);
        break;
    case structure::floraison:
        ajouterFloraison(largeur,hauteur);
        break;
    case structure::planeur:
        ajouterPlaneur(largeur,hauteur);
        break;
    case structure::oscillateurcroix:
        ajouterOscillateurCroix(largeur,hauteur);
        break;
    }
}

unsigned int grille::vivantes(const coordonnee & largeur, const coordonnee & hauteur)const{
    unsigned int nbvivantes(0);
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if( (i!=0 || j!=0) && appartientCellule(largeur+i,hauteur+j)){
                if((vivante(largeur+i,hauteur+j))){
                    nbvivantes++;
                    std::cout<<"["<<largeur+i<<","<<hauteur+j<<"]";
                }
            }
        }
    }
    return nbvivantes;
}

void grille::evolution(grille & resultat)const{
    resultat.vider();
    for(std::vector<std::vector<etatcellule>>::size_type i(0);i<_hauteur;i++){
        for(std::vector<etatcellule>::size_type j(0);j<_largeur;j++){
            if(vivantes(j,i)<2 || vivantes(j,i)>3){
                resultat.tuer(j,i);
            }
            else if(vivantes(j,i)==3){
                resultat.generer(j,i);
            }
            else if(this->vivante(j,i)){
                resultat.generer(j,i);
            }
        }
    }
}
