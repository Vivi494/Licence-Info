#pragma once
#include <iostream>
#include <vector>

enum class couleur{
    rouge,bleu,vert,jaune
};

using indicesequence = unsigned int;

class sequence{
private:
    std::vector<couleur> _tab;
public:
    sequence();
    sequence(std::vector<couleur> tab);
    sequence(const sequence & S);
    std::vector<couleur>::size_type taille() const;
    couleur acces(std::vector<couleur>::size_type i);
    std::string toString(couleur c) const;
    bool comparer(const sequence & S) const;
    void afficher(const couleur & C) const;
    void afficher(std::ostream & Sortie) const;
    void vider();
    void copier(const sequence & S);
    void ajouter(const couleur & C);
};
