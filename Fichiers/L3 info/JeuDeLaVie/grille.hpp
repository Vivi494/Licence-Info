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
    grille(const coordonnee & largeur, const coordonnee & hauteur);
    void vider();
    bool vivante(const coordonnee & largeur, const coordonnee & hauteur)const;
    void generer(const coordonnee & largeur, const coordonnee & hauteur);
    void tuer(const coordonnee & largeur, const coordonnee & hauteur);
    void afficher()const;
    bool appartientCellule(const coordonnee & largeur, const coordonnee & hauteur)const;
    void ajouterOscillateurLigne(const coordonnee & largeur, const coordonnee & hauteur);
    void ajouterFloraison(const coordonnee & largeur, const coordonnee & hauteur);
    void ajouterPlaneur(const coordonnee & largeur, const coordonnee & hauteur);
    void ajouterOscillateurCroix(const coordonnee & largeur, const coordonnee & hauteur);
    void ajouterstructure(const structure & S, const coordonnee & largeur, const coordonnee & hauteur);
    unsigned int vivantes(const coordonnee & largeur, const coordonnee & hauteur)const;
    void evolution(grille & resultat)const;
};
