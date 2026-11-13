#include "grille.hpp"
#include <iostream>
#include "affichage_sfml.hh"

int main(){
    coordonnee largeur(50),hauteur(50);
    bool pause(false);
    float zoom(2);
    grille MaGrille(largeur,hauteur);
    grille MaGrille2(largeur,hauteur);
    MaGrille.generer(0,5);
    MaGrille.generer(10,5);
    MaGrille.generer(2,6);
    MaGrille.generer(4,35);
    MaGrille.generer(40,19);
    MaGrille.generer(25,12);
    MaGrille.generer(6,2);
    affichage_jeu_de_la_vie affichage(largeur,hauteur,zoom);
    affichage_jeu_de_la_vie::action aj; unsigned int x, y;
    while (affichage.recuperer_action_joueur(aj, x, y)|true) {
        affichage.affichage_commencer();
        switch (aj) {
        case affichage_jeu_de_la_vie::action::inverser_cellule:
            if (MaGrille.vivante(x, y))
                MaGrille.tuer(x, y);
            else
                MaGrille.generer(x, y);
            break;
        case affichage_jeu_de_la_vie::action::ajouter_floraison:
            MaGrille.ajouterFloraison(x,y);
            break;
        case affichage_jeu_de_la_vie::action::ajouter_oscillateurligne:
            MaGrille.ajouterOscillateurLigne(x,y);
            break;
        case affichage_jeu_de_la_vie::action::ajouter_oscillateurcroix:
            MaGrille.ajouterOscillateurCroix(x,y);
            break;
        case affichage_jeu_de_la_vie::action::ajouter_planeur:
            MaGrille.ajouterPlaneur(x,y);
            break;
        case affichage_jeu_de_la_vie::action::pause_oui_non:
            pause=(!pause);
            break;
        }
        if(!pause){
            MaGrille.evolution(MaGrille2);
            MaGrille=MaGrille2;
        }
        affichage.afficher_grille_vide();
        for (unsigned int i = 0; i < largeur; ++i)
            for (unsigned int j = 0; j < hauteur; ++j)
                if (MaGrille.vivante(i, j))
                    affichage.afficher_cellule_vivante(i, j);
        affichage.affichage_terminer();
    }
}
