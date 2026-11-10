#pragma once
#include <vector>

enum class etatcellule{
    vivant,mort
};

using coordonnee=int;

enum class structure{
    oscillateurligne, floraison, planeur, oscillateurcroix
};

class grille{
private:
    coordonnee _hauteur;
    coordonnee _largeur;
    std::vector<std::vector<etatcellule>> _grille;
public:
    grille(const coordonnee & hauteur, const coordonnee & largeur);
    void vider();
    bool vivante(const coordonnee & longueur, const coordonnee & largeur)const;
    void generer(const coordonnee & longueur, const coordonnee & largeur);
    void tuer(const coordonnee & longueur, const coordonnee & largeur);
    void afficher()const;
    bool appartientCellule(const coordonnee & hauteur, const coordonnee & largeur)const;
    void ajouterOscillateurLigne(const coordonnee & longueur, const coordonnee & largeur);
    void ajouterFloraison(const coordonnee & longueur, const coordonnee & largeur);
    void ajouterPlaneur(const coordonnee & longueur, const coordonnee & largeur);
    void ajouterOscillateurCroix(const coordonnee & longueur, const coordonnee & largeur);
    void ajouterstructure(const structure & S, const coordonnee & longueur, const coordonnee & largeur);
};
