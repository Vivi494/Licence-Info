#pragma once
#include <array>
#include <cstddef>

/*enum class couleur {
    rouge,
    bleu,
    jaune,
    vert
};

using indicesequence = std::size_t;

struct sequence {
    std::array<couleur, 100> contenu;
    indicesequence taille;
};

void sc_initialiservide(sequence & s);
void sc_ajouter(sequence & s, couleur c);
void sc_copier(sequence & destination, sequence const & source);
couleur sc_acces(sequence const & s, indicesequence i);
void sc_afficher(couleur c);
void sc_vider(sequence & s);
void sc_afficher(sequence const & s);
bool sc_comparer(sequence const & a, sequence const &b);
*/

using indicesequence = std::size_t;

enum class couleur {
    rouge,
    bleu,
    jaune,
    vert
};

struct sequence {
    couleur * couleurs;
    indicesequence taille;
};

void sc_initialiservide(sequence & s);
void sc_ajouter(sequence & s, couleur c);
void sc_copier(sequence & destination, sequence const & source);
couleur sc_acces(sequence const & s, indicesequence i);
void sc_afficher(couleur c);
void sc_vider(sequence & s);
void sc_afficher(sequence const & s);
bool sc_comparer(sequence const & a, sequence const &b);
