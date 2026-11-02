#pragma once

using coordonnee = int;

class position_t{
private:
    coordonnee _x;
    coordonnee _y;
public:
    position_t(coordonnee x, coordonnee y);
    position_t(const position_t & P);
    coordonnee x() const;
    coordonnee y() const;
    void setx(coordonnee x);
    void sety(coordonnee y);
    bool comparaison(const position_t & P) const;
};

class taille_t{
private:
    coordonnee _largeur;
    coordonnee _hauteur;
public:
    taille_t(coordonnee largeur, coordonnee hauteur);
    coordonnee largeur() const;
    coordonnee hauteur() const;
    void setlargeur(coordonnee largeur);
    void sethauteur(coordonnee hauteur);
    bool comparaison(const taille_t & T) const;
};
