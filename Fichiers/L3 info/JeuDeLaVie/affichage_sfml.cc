#include "affichage_sfml.hh"

affichage_jeu_de_la_vie::affichage_jeu_de_la_vie(unsigned int largeur, unsigned int hauteur, unsigned int zoom)
	: _fenetre(sf::VideoMode(largeur * _largeur_cellule * zoom, hauteur * _largeur_cellule * zoom), "Jeu de la vie"),
	  _vue(sf::FloatRect(0, 0, largeur * _largeur_cellule, hauteur * _largeur_cellule)),
	  _action_courante(action::inverser_cellule) {
	_fenetre.setView(_vue);
	_fenetre.setVerticalSyncEnabled(false);
	_fenetre.setFramerateLimit(5);
}

bool affichage_jeu_de_la_vie::fenetre_ouverte() const {
	return _fenetre.isOpen();
}

bool affichage_jeu_de_la_vie::recuperer_action_joueur(action& aj, unsigned int& x, unsigned int& y) {
	aj = action::rien;
	sf::Event ev;
	while (_fenetre.pollEvent(ev) && (aj == action::rien)) {
		if (ev.type == sf::Event::Closed)
			_fenetre.close();
		else if (ev.type == sf::Event::KeyPressed) {
			if (ev.key.code == sf::Keyboard::Space)
				_action_courante = action::inverser_cellule;
			else if (ev.key.code == sf::Keyboard::L)
				_action_courante = action::ajouter_oscillateurligne;
			else if (ev.key.code == sf::Keyboard::F)
				_action_courante = action::ajouter_floraison;
			else if (ev.key.code == sf::Keyboard::P)
				_action_courante = action::ajouter_planeur;
			else if (ev.key.code == sf::Keyboard::C)
				_action_courante = action::ajouter_oscillateurcroix;
			else if (ev.key.code == sf::Keyboard::Return) {
				aj = action::pause_oui_non;
				x = y = 0;
			}
		}
		else if (ev.type == sf::Event::MouseButtonPressed) {
			if (ev.mouseButton.button == sf::Mouse::Left) {
				aj = _action_courante;
				auto zoom = static_cast<unsigned int>(_fenetre.getSize().x / _vue.getSize().x);
				x = ev.mouseButton.x / zoom / _largeur_cellule;
				y = ev.mouseButton.y / zoom / _largeur_cellule;
			}
		}
	}
	return aj != action::rien;
}

void affichage_jeu_de_la_vie::affichage_commencer() {
	_fenetre.clear(sf::Color::White);
}

void affichage_jeu_de_la_vie::afficher_grille_vide() {
	sf::RectangleShape rs(sf::Vector2f(static_cast<float>(_largeur_cellule), static_cast<float>(_largeur_cellule)));
	rs.setOutlineColor(sf::Color::Black);
	rs.setOutlineThickness(1.f);
	for (unsigned int i = 0; i <= _vue.getSize().x; i += _largeur_cellule)
		for (unsigned int j = 0; j <= _vue.getSize().y; j += _largeur_cellule) {
			rs.setPosition(static_cast<float>(i), static_cast<float>(j));
			_fenetre.draw(rs);
		}
}

void affichage_jeu_de_la_vie::afficher_cellule_vivante(unsigned int x, unsigned int y) {
	sf::RectangleShape rs(sf::Vector2f(static_cast<float>(_largeur_cellule-3), static_cast<float>(_largeur_cellule-3)));
	rs.setFillColor(sf::Color::Blue);
	rs.setPosition(static_cast<float>(x * _largeur_cellule +1), static_cast<float>(y * _largeur_cellule +1));
	_fenetre.draw(rs);
}

void affichage_jeu_de_la_vie::affichage_terminer() {
	_fenetre.display();
}

