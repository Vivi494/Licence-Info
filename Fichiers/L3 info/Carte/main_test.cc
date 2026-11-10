#include <catch2/catch_test_macros.hpp>
#include "element.hpp"

TEST_CASE("Q1 - Constructeur et accesseurs", "[Q1]") {
	element e(position_t(4, 2), taille_t(5, 3));

	CHECK(e.accesposition().x() == 4);
	CHECK(e.accesposition().y() == 2);
	CHECK(e.accestaille().largeur() == 5);
	CHECK(e.accestaille().hauteur() == 3);
}

TEST_CASE("Q1 - les accesseurs fonctionnent sur un element constant", "[Q1]") {
	element const e(position_t(1, 2), taille_t(3, 4));

	CHECK(e.accesposition().x() == 1);
	CHECK(e.accesposition().y() == 2);
	CHECK(e.accestaille().largeur() == 3);
	CHECK(e.accestaille().hauteur() == 4);
}

TEST_CASE("Q2 - element::tostring", "[Q2]") {
	element e(position_t(4, 2), taille_t(5, 3));

	CHECK(e.tostring() == "(4,2)[5,3]");
}

TEST_CASE("Q3 - contientposition (point à l'interieur)", "[Q3]") {
	element e(position_t(10, 20), taille_t(5, 3));

	CHECK(e.contientposition(position_t(12, 21)));
	CHECK(e.contientposition(position_t(13, 22)));
}

TEST_CASE("Q3 - contientposition (point à l'extérieur)", "[Q3]") {
	element e(position_t(10, 20), taille_t(5, 3));

	CHECK_FALSE(e.contientposition(position_t(9, 21)));
	CHECK_FALSE(e.contientposition(position_t(0, 21)));

	CHECK_FALSE(e.contientposition(position_t(16, 21)));
	CHECK_FALSE(e.contientposition(position_t(1000, 21)));

	CHECK_FALSE(e.contientposition(position_t(12, 19)));
	CHECK_FALSE(e.contientposition(position_t(12, 0)));

	CHECK_FALSE(e.contientposition(position_t(12, 24)));
	CHECK_FALSE(e.contientposition(position_t(12, 1000)));

	CHECK_FALSE(e.contientposition(position_t(5, 10))); // haut gauche
	CHECK_FALSE(e.contientposition(position_t(20, 10))); // haut droite
	CHECK_FALSE(e.contientposition(position_t(5, 30))); // bas gauche
	CHECK_FALSE(e.contientposition(position_t(20, 30))); // bas droite

	CHECK_FALSE(e.contientposition(position_t(12, 5)));
	CHECK_FALSE(e.contientposition(position_t(2, 21)));
}

TEST_CASE("Q4 - obstacle : position et taille", "[Q4]") {
	obstacle o(position_t(3, 4), taille_t(10, 20));

	CHECK(o.accesposition().comparaison(position_t(3, 4)));
	CHECK(o.accestaille().comparaison(taille_t(10, 20)));
}

TEST_CASE("Q4 - objetramassable : position, taille et nombre de points", "[Q4]") {
	objetramassable o(position_t(6, 7), taille_t(2, 3), 25);

	CHECK(o.accesposition().comparaison(position_t(6, 7)));
	CHECK(o.accestaille().comparaison(taille_t(2, 3)));
	CHECK(o.nbpoints() == 25);
}

TEST_CASE("Q4 - personnage : position, taille et nom", "[Q4]") {
	personnage p(position_t(8, 9), taille_t(4, 5), "Alice");

	CHECK(p.accesposition().comparaison(position_t(8, 9)));
	CHECK(p.accestaille().comparaison(taille_t(4, 5)));
	CHECK(p.nom() == "Alice");
}

TEST_CASE("Q4 - personnage : 0 point au debut de la partie", "[Q4]") {
	personnage p(position_t(8, 9), taille_t(4, 5), "Alice");

    CHECK(p.nbpoints() == 0);
}

TEST_CASE("Q5 - obstacle::tostring", "[Q5]") {
	obstacle o(position_t(4, 2), taille_t(5, 3));

	CHECK(o.tostring() == "obs (4,2)[5,3]");
}

TEST_CASE("Q5 - objetramassable::tostring", "[Q5]") {
	objetramassable o(position_t(4, 2), taille_t(5, 3), 12);

	CHECK(o.tostring() == "obj (4,2)[5,3] 12pts");
}

TEST_CASE("Q5 - personnage::tostring", "[Q5]") {
	personnage p(position_t(4, 2), taille_t(5, 3), "nom");

	CHECK(p.tostring() == "per (4,2)[5,3] 0pts nom");
}

TEST_CASE("Q6 - personnage::tostring apres avoir ramasse un objet", "[Q6]") {
	personnage p(position_t(4, 2), taille_t(5, 3), "nom");
	objetramassable o(position_t(0, 0), taille_t(1, 1), 12);

	REQUIRE(p.nbpoints() == 0);
	p.ramasser(o);
	REQUIRE(p.nbpoints() == 12);
	CHECK(p.tostring() == "per (4,2)[5,3] 12pts nom");
}
