#include "sequence.hpp"
#include <iostream>

/*void sc_initialiservide(sequence & s) {
    s.taille = 0;
}

void sc_ajouter(sequence & s, couleur c) {
    s.contenu.at(s.taille++) = c;
}

void sc_copier(sequence & destination, sequence const & source) {
    for (indicesequence i=0; i<source.taille; ++i)
        destination.contenu[i] = source.contenu[i];
    destination.taille = source.taille;
}

couleur sc_acces(sequence const & s, indicesequence i) {
    return s.contenu.at(i);
}

void sc_afficher(couleur c) {
    switch (c) {
    case couleur::rouge: std::cout << "rouge"; break;
    case couleur::bleu: std::cout << "bleu"; break;
    case couleur::jaune: std::cout << "jaune"; break;
    case couleur::vert: std::cout << "vert"; break;
    }
}

void sc_vider(sequence & s) {
    s.taille = 0;
}

void sc_afficher(sequence const & s) {
    for (indicesequence i=0; i<s.taille; ++i) {
        sc_afficher(sc_acces(s,i));
        std::cout << " ";
    }
}

bool sc_comparer(sequence const & a, sequence const & b) {
    if (a.taille != b.taille)
        return false;
    else {
        for (indicesequence i=0; i<a.taille; ++i)
            if (a.contenu[i] != b.contenu[i])
                return false;
        return true;
    }
}
*/

void sc_initialiservide(sequence & s){
    s.taille=0;
    s.couleurs = nullptr;
}

void sc_ajouter(sequence & s, couleur c){
    if(s.taille%5==0){
        sequence tmp;
        sc_initialiservide(tmp);
        sc_copier(tmp,s);
        s.couleurs=new couleur[s.taille+5];
        for (indicesequence i=0; i<tmp.taille; ++i){
            s.couleurs[i] = tmp.couleurs[i];
        }
    }
    s.couleurs[s.taille]=c;
    s.taille=s.taille+1;
}

void sc_copier(sequence & destination, sequence const & source) {
    sc_vider(destination);
    sc_initialiservide(destination);
    for (indicesequence i=0; i<source.taille; ++i)
        sc_ajouter(destination,source.couleurs[i]);
}

couleur sc_acces(sequence const & s, indicesequence i) {
    return s.couleurs[i];
}

void sc_afficher(couleur c) {
    switch (c) {
    case couleur::rouge: std::cout << "rouge"; break;
    case couleur::bleu: std::cout << "bleu"; break;
    case couleur::jaune: std::cout << "jaune"; break;
    case couleur::vert: std::cout << "vert"; break;
    }
}

void sc_vider(sequence & s) {
    if(s.couleurs!=nullptr){
        delete[] s.couleurs;
    }
    sc_initialiservide(s);
}

void sc_afficher(sequence const & s) {
    for (indicesequence i=0; i<s.taille; ++i) {
        sc_afficher(sc_acces(s,i));
        std::cout << " ";
    }
}

bool sc_comparer(sequence const & a, sequence const & b) {
    if (a.taille != b.taille)
        return false;
    else {
        for (indicesequence i=0; i<a.taille; ++i)
            if (a.couleurs[i] != b.couleurs[i])
                return false;
        return true;
    }
}
