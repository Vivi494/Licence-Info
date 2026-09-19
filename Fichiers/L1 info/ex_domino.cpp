#include <iostream>
#include <cstdlib>

struct domino{
    int a;
    int b;
    domino* suiv;
};

using liste=domino*;

void saisie(liste d)
{
    std::cout<<"Veuillez saisir les 2 parties du domino :";
    std::cin>>d->a;
    std::cin>>d->b;
    d->suiv=nullptr;
}

void initialiser(liste &L)
{
    L=nullptr;
}

void ajoutegauche(liste &L, liste d)
{
    liste p=d;
    p->suiv=L;
    L=p;
}

void ajoutedroite(liste &L, liste d)
{
    if(L==nullptr)
        ajoutegauche(L,d);
    else
        ajoutedroite(L->suiv,d);
}

void saisie_main(liste &L)
{
    int n=0;
    std::cout<<"Taille de la main :";
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        liste p=new domino;
        saisie(p);
        ajoutedroite(L,p);
    }
}

void affichage_main(liste L)
{
    if(L!=nullptr)
    {
        std::cout<<'('<<L->a<<':'<<L->b<<')'<<'\t';
        affichage_main(L->suiv);
    }
}

void supprime_premier(liste &L)
{
    if(L!=nullptr)
    {
        liste p=L;
        L=L->suiv;
        delete p;
        p=nullptr;
    }
}

int taille(liste L)
{
    if(L==nullptr)
    {
        return 0;
    }
    return taille(L->suiv)+1;
}
void liste_pioche(liste &P)
{
    for(int i=0;i<7;i++)
    {
        for(int j=i;j<7;j++)
        {
            liste m=new domino;
            m->a=i;
            m->b=j;
            ajoutedroite(P,m);
        }
    }
}

void supprime_pioche(liste &P,liste d)
{
    if(((P->a==d->a)and(P->b==d->b))or((P->b==d->a)and(P->a==d->b)))
    {
            supprime_premier(P);
            return;
    }
    liste r=P;
    while(r!=nullptr)
    {
        if(r->suiv!=nullptr)
        {
            if(((r->suiv->a==d->a)and(r->suiv->b==d->b))or((r->suiv->b==d->a)and(r->suiv->a==d->b)))
            {
                liste m=r->suiv;
                r->suiv=m->suiv;
                delete m;
            }
        }
        r=r->suiv;
    }
}

void piocher(liste &P,liste &L)
{
    int taille_pioche=taille(P);
    int n=rand()%taille_pioche;
    liste d=P;
    for(int i=0;i<n;i++)
    {
        d=d->suiv;
    }
    liste r=new domino;
    r->a=d->a;
    r->b=d->b;
    r->suiv=nullptr;
    ajoutedroite(L,r);
    supprime_pioche(P,d);
}

void genere_main(int n,liste &P ,liste &L)
{
    for(int i=0;i<n;i++)
    {
        piocher(P,L);
    }
}

int nombre_point(liste L)
{
    if(L==nullptr)
    {
        return 0;
    }
    return L->a+L->b+nombre_point(L->suiv);
}

void retourne(liste d)
{
    int v=d->a;
    d->a=d->b;
    d->b=v;
}

int aGauche(liste t)
{
    if(t!=nullptr)
    {
        return t->a;
    }
    return -1;
}

int aDroite(liste t)
{
    if(t->suiv==nullptr)
    {
        return t->b;
    }
    return aDroite(t->suiv);
}

void jouer(liste &m, liste&j, bool &bloque)
{
    int droite=aDroite(j);
    int gauche=aGauche(j);
    liste r=m;
    bool existe=false;
    while((r!=nullptr)and(existe==false))
    {
        if((droite==r->a)and(existe==false))
        {
            liste l=new domino;
            l->a=r->a;
            l->b=r->b;
            l->suiv=nullptr;
            ajoutedroite(j,l);
            supprime_pioche(m,l);
            existe=true;
            
        }
        if((droite==r->b)and(existe==false))
        {
            liste l=new domino;
            l->a=r->b;
            l->b=r->a;
            l->suiv=nullptr;
            ajoutedroite(j,l);
            supprime_pioche(m,l);
            existe=true;
        }
        if((gauche==r->a)and(existe==false))
        {
            liste l=new domino;
            l->a=r->b;
            l->b=r->a;
            l->suiv=nullptr;
            ajoutegauche(j,l);
            supprime_pioche(m,l);
            existe=true;
            
        }
        if((gauche==r->b)and(existe==false))
        {
            liste l=new domino;
            l->a=r->a;
            l->b=r->b;
            l->suiv=nullptr;
            ajoutegauche(j,l);
            supprime_pioche(m,l);
            existe=true;
        }
        r=r->suiv;
    }
    if(existe==false)
    {
        bloque=true;
    }
    else{
        bloque=false;
    }
}

void afficher_partie(liste L,liste t)
{
    std::cout<<"Main  du joueur :";
    affichage_main(L);
    std::cout<<"Table :";
    affichage_main(t);
    std::cout<<'\n';
}

void partie1(bool start)
{
    liste L=nullptr;
    liste P=nullptr;
    liste t=nullptr;
    bool bloque=false;
    int n;
    liste_pioche(P);
    do{
        std::cout<<"Nombre de domino pour la main de départ :";
        std::cin>>n;
    }while((n<0)or(n>27));
    genere_main(n,P,L);
    genere_main(1,P,t);
    afficher_partie(L,t);
    while(((bloque==false)or(taille(P)!=0))and(taille(L)!=0))
    {
        jouer(L,t,bloque);
        if(bloque==true)
        {
            if(taille(P)!=0)
            {
                piocher(P,L);
            }
        }
        afficher_partie(L,t);
    }
    if(taille(L)==0)
    {
        std::cout<<"Partie gagné!";
    }
    else{
        std::cout<<"Partie perdue, Nombre de points : "<<nombre_point(L);
    }
}

int main()
{
    bool start=true;
    partie1(start);
    return 0;
}

