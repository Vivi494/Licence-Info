#include <iostream>
#include "tailleposition.h"

using namespace std;

int main()
{
    coordonnee hauteur,largeur,x,y;
    std::cout<<"x et y ? ";std::cin>>x>>y;
    position_t P1 = position_t(x,y);
    position_t P2 = position_t(P1);
    std::cout<<"P1==P2 ? "<<P2.comparaison(P1)<<'\n';
    std::cout<<"rappel de x et y : "<<P1.x()<<","<<P1.y()<<'\n';
    std::cout<<"nouveaux x et y ? ";std::cin>>x>>y;
    P1.setx(x);
    P1.sety(y);
    std::cout<<"P1==P2 ? "<<P2.comparaison(P1)<<'\n';
    std::cout<<"hauteur et largeur ? ";std::cin>>hauteur>>largeur;
    taille_t T1 = taille_t(largeur,hauteur);
    taille_t T2 = taille_t(largeur,hauteur);
    std::cout<<"T1==T2 ? "<<T2.comparaison(T1)<<'\n';
    std::cout<<"rappel de hauteur et largeur : "<<T1.hauteur()<<","<<T1.largeur()<<'\n';
    std::cout<<"nouveaux hauteur et largeur ? ";std::cin>>hauteur>>largeur;
    T1.setlargeur(largeur);
    T1.sethauteur(hauteur);
    std::cout<<"T1==T2 ? "<<T2.comparaison(T1)<<'\n';
}
