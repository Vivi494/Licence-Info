#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class affichage_jeu_de_la_vie {
  public:
	enum class action {
		inverser_cellule,
		ajouter_oscillateurligne,
		ajouter_floraison,
		ajouter_planeur,
		ajouter_oscillateurcroix,
		pause_oui_non,
		rien
	};

  public:
	affichage_jeu_de_la_vie(unsigned int largeur, unsigned int hauteur, unsigned int zoom);
	bool fenetre_ouverte() const;
	bool recuperer_action_joueur(action &aj, unsigned int & x, unsigned int &y);

	void affichage_commencer();
	void afficher_grille_vide();
	void afficher_cellule_vivante(unsigned int x, unsigned int y);
	void affichage_terminer();

  private:
	const unsigned int _largeur_cellule = 16;
	sf::RenderWindow _fenetre;
	sf::View _vue;
	action _action_courante;
};
