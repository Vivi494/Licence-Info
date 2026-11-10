#pragma once
#include "tailleposition.hpp"
#include <string>

class element{
private:
    position_t _position;
    taille_t _taille;
public:
    element(const position_t & position, const taille_t & taille);
    taille_t accestaille() const;
    position_t accesposition() const;
    std::string tostring()const;
    bool contientposition(const position_t & P)const;
};

class obstacle: public element{
public:
    obstacle(const position_t & position, const taille_t & taille);
    std::string tostring()const;
};

class objetramassable: public element{
private:
    int _nbpoints;
public:
    objetramassable(const position_t & position, const taille_t & taille, const int & nbpoints);
    int nbpoints()const;
    std::string tostring()const;
};

class personnage: public element{
private:
    int _nbpoints;
    std::string _nom;
public:
    personnage(const position_t & position, const taille_t & taille, const std::string & nom);
    int nbpoints()const;
    std::string nom()const;
    std::string tostring()const;
    void ramasser(const objetramassable & O);
};
