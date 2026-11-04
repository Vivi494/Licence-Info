#pragma once
#include <vector>

enum class etatcellule{
    vivant,mort
};

using coordonnee=int;

class grille{
private:
    coordonnee _longueur;
    coordonnee _largeur;
    std::vector<std::vector<etatcellule>> _grille;
public:
    grille(coordonnee longueur, coordonnee largeur);
};
