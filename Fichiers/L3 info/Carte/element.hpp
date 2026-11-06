#pragma once
#include "tailleposition.hpp"
#include <string>

class element{
private:
    position_t _position;
    taille_t _taille;
public:
    element(const position_t & position, const taille_t & taille);
    element(const taille_t & taille, const position_t & position);
    taille_t accestaille() const;
    position_t accesposition() const;
    std::string tostring()const;
    bool contientposition(const position_t & P)const;
};

class obstacle: public element{
public:
    obstacle(const position_t & position, const taille_t & taille);
    obstacle(const taille_t & taille, const position_t & position);
};

class personnage: public element{
private:
    int nbpoints;
    std::string nom;
public:
    personnage(const position_t & position, const taille_t & taille, const int & nbpoints, const std::string & nom);
    personnage(const taille_t & taille, const position_t & position, const int & nbpoints, const std::string & nom);
};

class objetramassable: public element{
private:
    int _nbpoints;
public:
    objetramassable(const position_t & position, const taille_t & taille, const int & nbpoints);
    objetramassable(const taille_t & taille, const position_t & position, const int & nbpoints);
};
