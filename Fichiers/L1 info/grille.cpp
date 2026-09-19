#include <iostream>
#include "grille.h"

int taille_gagner=4;
void creation(grille &T,int &n,int &m)   //création de la grille 
{
    do{
        std::cout<<"Taille du tableau (ligne puis colonne)";
        std::cin>>n>>m;
    }while((n<=0)or(m<=0));
    T=new char*[n];
    for(int i=0;i<n;i++)
    {
        T[i]=new char[m];
    }
}


void initialiser(grille T,int n,int m)  //remplie le tableau avec des espaces
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            T[i][j]=' ';
        }
    }
}

void afficher_grille(grille T,int n,int m)  //afficher la grille
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            std::cout<<'|'<<T[i][j];
        }
        std::cout<<"|\n";
    }
}


bool ligne_gagne_case(grille T,int n,int m, int x,int y) //détermine s'il y a une ligne qui termine le jeu à partir d'une case (x,y)
{
    char cara=T[x][y];
    int compt=1;
    bool droite=true;
    bool gauche=true;
    for(int i=1;(i<taille_gagner)and((droite)or(gauche));i++)
    {
        if((y+i<m)and(T[x][y+i]==cara)and(droite))
        {
            compt++;
        }
        else{
            droite=false;
        }
        if((y-i>=0)and(T[x][y-i]==cara)and(gauche))
        {
            compt++;
        }
        else{
            gauche=false;
        }
    }
    return compt>=4;
}

bool colonne_gagne_case(grille T,int n,int m,int x,int y) //détermine s'il y a une colonne qui termine le jeu à partir d'une case (x,y)
{
    char cara=T[x][y];
    int compt=1;
    bool bas=true;
    for(int i=1;(i<taille_gagner)and(bas);i++)
    {
        if((x+i<n)and(T[x+i][y]==cara)and(bas))
        {
            compt++;
        }
        else{
            bas=false;
        }
    }
    return compt>=taille_gagner;
}

bool diagonale1_gagne_case(grille T,int n,int m,int x,int y) // détermine s'il y a une diagonale qui termine le jeu à partir d'une case (x,y)
{
    char cara=T[x][y];
    int compt=1;
    bool droite=true;
    bool gauche=true;
    for(int i=1;(i<taille_gagner)and((droite)or(gauche));i++)
    {
        if((x-i>=0)and(y+i<m)and(T[x-i][y+i]==cara)and(droite))
        {
            compt++;
        }
        else
        {
            droite=false;
        }
        if((x+i<n)and(y-i>=0)and(T[x+i][y-i]==cara)and(gauche))
        {
            compt++;
        }
        else
        {
            gauche=false;
        }
    }
    return compt>=taille_gagner;
    
}

bool diagonale2_gagne_case(grille T,int n,int m,int x,int y) // détermine s'il y a une diagonale qui termine le jeu à partir d'une case (x,y)
{
    char cara=T[x][y];
    int compt=1;
    bool droite=true;
    bool gauche=true;
    for(int i=1;(i<taille_gagner)and((droite)or(gauche));i++)
    {
        if((x-i>=0)and(y-i>=0)and(T[x-i][y-i]==cara)and(droite))
        {
            compt++;
        }
        else
        {
            droite=false;
        }
        if((x+i<n)and(y+i<m)and(T[x+i][y+i]==cara)and(gauche))
        {
            compt++;
        }
        else
        {
            gauche=false;
        }
    }
    return compt>=taille_gagner;
}

bool gagne(grille T,int n,int m,int x,int y) //détecte s'il y a un gagnant
{
    return((ligne_gagne_case(T,n,m,x,y)or(colonne_gagne_case(T,n,m,x,y))or(diagonale1_gagne_case(T,n,m,x,y)or(diagonale2_gagne_case(T,n,m,x,y)))));
}

void detruire_grille(grille &T,int n)
{
    for(int i=0;i<n;i++)
    {
        delete T[i];
    }
    delete []T;
}