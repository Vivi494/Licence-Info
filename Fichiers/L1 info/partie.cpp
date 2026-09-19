#include <iostream>
#include "grille.h"
#include "ia.h"
#include "joueur.h"
#include "partie.h"


bool unique_caractere(participant *F,int n,char c) // Existence du caractère c dans le tableau F
{
    for(int i=0;i<n;i++)
    {
        if(c==F[i].symbole)
        {
            return false;
        }
    }
    return true;
}

void initialisation_partie(participant* &T,int &n) // Création d'un tableau qui répertorie les participants (humain ou IA ) avec leurs symbole associé
{
    std::cout<<"Nombre de joueur : ";
    std::cin>>n;
    T=new participant[n];
    char s;
    
    for(int i=0;i<n;i++)
    {
        do{
        std::cout<<"Joueur ou IA : J ou I ";
        std::cin>>s;
        }while((s!='J')and(s!='I'));
        T[i].joueur=(s=='J');
        do{
        std::cout<<"Caratere associé au joueur "<<i<<" : ";
        std::cin>>s;
        }while(unique_caractere(T,i,s)==false);
        T[i].symbole=s;
    }
}

void tour(grille T,int n,int m,participant* F,int i, bool &fin,int aire)
{
    std::cout<<"C'est au joueur "<<i<<" de jouer\n";
    int x,y;
    if(F[i].joueur)
    {
        co=joue_joueur(T,n,m,F[i].symbole,x,y);
    }
    else{
        co=joue_ia(T,n,m,F[i].symbole,x,y);   
    }
    T[case_libre][co]=c;
    x=case_libre;
    y=co;
    aire--;
    afficher_grille(T,n,m);
    if(gagne(T,n,m,x,y))
    {
        detruire_grille(T,n);
        detruire_grille(F,nb_joueur);
        std::cout<<"Le joueur "<<i<<" a gagné\n";
        fin=true;
    }
    else{
        if(aire==0)
        {
            detruire_grille(T,n);
            detruire_grille(F,nb_joueur);
            fin=true;
            std::cout<<"Pas de gagnant\n";
        }
    }
}