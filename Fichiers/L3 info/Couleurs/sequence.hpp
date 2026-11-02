#pragma once

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
};
