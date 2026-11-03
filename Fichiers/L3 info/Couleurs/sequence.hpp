#pragma once
#include <iostream>

enum class couleur{
    rouge,bleu,vert,jaune
};

using indicesequence = unsigned int;

class sequence{
private:
    indicesequence _taille;
    couleur* _tab;
public:
    sequence();
    sequence(indicesequence taille,couleur* tab);
    sequence(const sequence & S);
    indicesequence taille() const;
    couleur acces(indicesequence i);
    std::string toString(couleur c) const;
    bool comparer(const sequence & S) const;
    void afficher(const couleur & C) const;
    void afficher(std::ostream & Sortie) const;
    void vider();
    void copier(const sequence & S);
    void ajouter(const couleur & C);
};
