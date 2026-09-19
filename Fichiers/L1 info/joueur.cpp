#include <iostream>
#include "grille.h" 
#include "joueur.h"



bool colonne_libre(grille T,int n,int c,int &case_libre) // renvoie true si une colonne c est libre 
{
    for(int i=n-1;i>=0;i--)
    {
        if(T[i][c]==' ')
        {   
            case_libre=i;
            return true;
        }
    }
    return false;
}

void joue_joueur(grille T,int n,int m,char c,int &x,int &y) //joue au puissance 4
{
    int co;
    int case_libre;
    do
    {   std::cout<<"Colonne ?";
        std::cin>>co;
    }while((co<0)or(co>n)or(colonne_libre(T,n,co,case_libre))==false);
}