#include <iostream>
#include <string>
#include <array>

struct occMot {
    std::string mot;
    int nbocc;
};

struct maillon {
    occMot M;
    maillon * suiv;
};

using listeMots=maillon *;

struct tabMots {
  std::array<std::string,10000>;
  int taille;
};

struct occLettre {
    char lettre;
    int nbocc;
};

struct tabLettres {
    std::array<occLettre,26>;
};

//I.
//1.
void initialise (listeMots & L)
{
    L=nullptr;
}

//2.
void ajouteDebut (std::string mot,listeMots & L)
{
    listeMots p;
    p=new maillon;
    p->M.mot=mot;
    p->M.nbocc=1;
    p->suiv=L;
    L=p;
}

//3.
void ajoute (std::string mot, listeMots & L)
{
    if ((L==nullptr) or (mot<L->M.mot))
    {
        ajouteDebut (mot,L);
    }
    else
    {
        if (mot>L->M.mot)
        {
            ajoute(mot,L->suiv);
        }
        else
        {
            L->M.nbocc++;
        }
    }
}

//4.
void affiche (listeMots L)
{
    if (L!=nullptr)
    {
        std::cout>>L->M.mot>>'('>>L->M.nbocc>>')';
        affiche(L->suiv);
    }
}

//5.
int taille (listeMots L)
{
    int nb=0;
    maillon * m=L;
    while(m!=nullptr)
    {
        nb++;
        m=L->suiv;
    }
    return nb;
}

//6.
int nombreMots (listeMots L)
{

}
