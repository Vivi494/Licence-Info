#include "grille.hpp"
#include <iostream>


void verifier_cellules(const grille& g,
                       const std::initializer_list<std::pair<coordonnee, coordonnee>>& vivantes,
                       coordonnee largeur, coordonnee hauteur) {
    for (coordonnee y = 0; y < hauteur; ++y)
        for (coordonnee x = 0; x < largeur; ++x) {
            bool attendue = false;
            for (const auto& cellule : vivantes)
                if (cellule.first == x && cellule.second == y)
                    attendue = true;
            std::cout<<(g.vivante(x, y) == attendue)<<'\n';
        }
    std::cout<<"\n";
}

void generer_cellules(grille& g,
                      const std::initializer_list<std::pair<coordonnee, coordonnee>>& cellules) {
    for (const auto& cellule : cellules)
        g.generer(cellule.first, cellule.second);
}

int main(){
    grille Ma_Grille(5,5);
    grille Ma_Grille2(5,5);
    generer_cellules(Ma_Grille,{{0,0}, {0,1}, {0,2}, {1,1}, {1,2}, {1,0}, {2,0}, {2,1}, {2,2}});
    Ma_Grille.afficher();
    std::cout<<'\n';
    std::string s;
    std::getline(std::cin,s);
    if(s.empty()){
        Ma_Grille.evolution(Ma_Grille2);
        Ma_Grille2.afficher();
    }
    else{
        std::cout<<"pas entrer\n";
    }
}
