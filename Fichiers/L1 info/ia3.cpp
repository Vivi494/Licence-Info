#include "grille.h"
#include "joueur.h"
#include <string>
#include <stdlib.h>
#include <ctime>
#include "partie.h"

struct coordonnee{
    int ligne;
    int colonne;
    int score;
};



coordonnee* coups_jouable(grille T,int n,int m,int &taille)
{
    int compt=0;
    int case_libre=0;
    for(int i=0;i<m;i++)
    {
        if(colonne_libre(T,n,i,case_libre))
        {
            compt++;
        }
    }
    if(compt==0) return nullptr;
    coordonnee* C=new coordonnee[compt];
    taille=compt;
    for(int i=0;i<m;i++)
    {
        if(colonne_libre(T,n,i,case_libre))
        {
            C[i].ligne=case_libre;
            C[i].colonne=i;
        }
    }
    return C;
}

int ligne_cara_compter(grille T,int n,int m,int x,int y,char cara)
{
    int compt=1;
    bool droite=true;
    bool gauche=true;
    for(int i=1;(i<4)and((droite)or(gauche));i++)
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
    return compt;
}


int colonne_cara_compter(grille T,int n,int m,int x,int y,char cara)
{
    int compt=1;
    bool bas=true;
    for(int i=1;(i<4)and(bas);i++)
    {
        if((x+i<n)and(T[x+i][y]==cara)and(bas))
        {
            compt++;
        }
        else{
            bas=false;
        }
    }
    return compt;
}


int diagonale1_cara_compter(grille T,int n,int m,int x,int y,char cara)
{
    int compt=1;
    bool droite=true;
    bool gauche=true;
    for(int i=1;(i<4)and((droite)or(gauche));i++)
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
    return compt;
    
}

int diagonale2_cara_compter(grille T,int n,int m,int x,int y,char cara)
{
    int compt=1;
    bool droite=true;
    bool gauche=true;
    for(int i=1;(i<4)and((droite)or(gauche));i++)
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
    return compt;
}

int par_case_cara(grille T,int n,int m,int x,int y,char cara)
{
    int plus_grand;
    if(diagonale2_cara_compter(T,n,m,x,y,cara)<diagonale1_cara_compter(T,n,m,x,y,cara))
    {
        plus_grand=diagonale1_cara_compter(T,n,m,x,y,cara);
    }
    else
    {
        plus_grand=diagonale2_cara_compter(T,n,m,x,y,cara);
    }
    if(plus_grand<colonne_cara_compter(T,n,m,x,y,cara))
    {
        plus_grand=colonne_cara_compter(T,n,m,x,y,cara);
    }
    if(plus_grand<ligne_cara_compter(T,n,m,x,y,cara))
    {
        plus_grand=ligne_cara_compter(T,n,m,x,y,cara);
    }
    return plus_grand;
}

int par_case(grille T,int n,int m,int x,int y,participant* P,int nb_joueur)
{
    int plus_grand;
    for(int i=0;i<nb_joueur;i++)
    {
        if(par_case_cara(T,n,m,x,y,P[i].symbole)>plus_grand)
        {
            plus_grand=par_case_cara(T,n,m,x,y,P[i].symbole);
        }
    }
    return plus_grand;
}

int quelle_colonne(grille T,int n,int m,int x,int y,participant* P,int nb_joueur,coordonnee* coups_jouable,int taille)
{
    int plus_grand,colonne;
    for(int i=0;i<taille;i++)
    {
        if(par_case(T,n,m,coups_jouable[i].ligne,coups_jouable[i].colonne,P,nb_joueur)>plus_grand)
        {
            plus_grand=par_case(T,n,m,coups_jouable[i].ligne,coups_jouable[i].colonne,P,nb_joueur);
            colonne=i;
        }
    }
    return colonne;
}

void joue_ia(grille T,int n,int m,char c,int &x,int &y,participant* P,int nb_joueur)
{
    int taille=0;
    int co;
    int case_libre;
    if(T[n][m/2]==' ')
    {
        co=m/2;
    }
    else
    {
        co=quelle_colonne(T,n,m,x,y,P,nb_joueur,coups_jouable(T,n,m,taille),taille); 
    }
    return co;
}