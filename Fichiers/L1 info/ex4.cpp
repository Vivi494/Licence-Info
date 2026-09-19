#include <iostream>

struct monome{
    float coeff;
    int puiss;
    monome* suiv;
};

using polynome=monome*;

    
void ajouterdebut(polynome &P, float a, int b)
{
    polynome l=new monome;
    l->coeff=a;
    l->puiss=b;
    l->suiv=P;
    P=l;
}

void ajouterfin(polynome &P, float a, int b)
{
    if(P==nullptr)
    {
        ajouterdebut(P,a,b);
    }
    else{
        ajouterfin(P->suiv,a,b);
    }
}


void saisie(polynome &P, int N)
{
    std::cout<<"Saisir le polynome (coeff puis degre de chaque monome) : ";
    float a;
    int b;
    for(int i=0;i<N;i++)
    {
        std::cin>>a;
        std::cin>>b;
        ajouterfin(P,a,b);
    }
}

void afficher_m(monome M)
{
    if(M.puiss==0){
        if(M.coeff>=0){
            std::cout<<'+'<<M.coeff;
        }
        else{
            std::cout<<M.coeff;
        }
    }
    else{
        
        if(M.coeff>=0){
            std::cout<<'+'<<M.coeff<<'X'<<M.puiss<<' ';
        }
        else{
            std::cout<<M.coeff<<'X'<<M.puiss<<' ';
        }
    }
}

void afficher(polynome P)
{
    while(P!=nullptr)
    {
        afficher_m(*P);
        P=P->suiv;
    }
}

void supprimedebut(polynome &P)
{
    if(P!=nullptr)
    {
        polynome l=P->suiv;
        delete(P);
        P=l;
    }
}

void supprime(polynome &P)
{
    if(P!=nullptr)
    {
        supprimedebut(P);
        supprime(P->suiv);
    }
}

int degre(polynome P)
{
    int max=P->puiss;
    P=P->suiv;
    while(P!=nullptr)
    {
        if(P->puiss>max)
        {
            max=P->puiss;
        }
        P=P->suiv;
    }
    return max;
}

float puissance(float a, int b)
{
    if(b==0)
    {
        return 1;
    }
    return a*puissance(a,b-1);
}


float valeurEn(polynome P,float X)
{
    if(P==nullptr)
        return 0;
    return P->coeff*(puissance(X,P->puiss))+valeurEn(P->suiv,X);
}

polynome derive(polynome P)
{
    polynome po_de=nullptr;
    while(P!=nullptr)
    {
        if(P->puiss!=0){
            ajouterfin(po_de,(P->coeff)*(P->puiss),(P->puiss-1));
        }
        P=P->suiv;
    }
    return po_de;
}

void ajoutMonome(polynome &P, monome M)
{
    ajouterfin(P,M.coeff,M.puiss);
}

void suppimer_deu(polynome &P)
{
    if(P!=nullptr)
    {
        if(P->suiv!=nullptr)
        {
            polynome r=P->suiv;
            P->suiv->suiv=P->suiv->suiv->suiv;
            delete r;
        }
    }
}

polynome simplifier(polynome &P)
{
    polynome p_simp=nullptr;
    polynome m=new monome;
    polynome r=nullptr;
    polynome r1=nullptr;
    while(P!=nullptr)
    {
        m->coeff=P->coeff;
        m->puiss=P->puiss;
        if(P->suiv!=nullptr)
        {
            r=P->suiv;
            r1=P;
            while(r!=nullptr)
            {
                if(r->puiss==m->puiss)
                {
                    
                    m->coeff=m->coeff+r->coeff;
                    r1->suiv=r->suiv;
                    delete(r);
                    r=r1->suiv;
                }
                else{
                    r1=r;
                    r=r->suiv;
                }
            }
        }
        if(m->coeff!=0)
        {
            ajouterfin(p_simp,m->coeff,m->puiss);
        }
        P=P->suiv;
    }
    return p_simp;
}

polynome somme(polynome P1,polynome P2)
{
    polynome p_somme=nullptr;
    while(P1!=nullptr)
    {
        ajouterfin(p_somme,P1->coeff,P1->puiss);
        P1=P1->suiv;
    }
    while(P2!=nullptr)
    {
        ajouterfin(p_somme,P2->coeff,P2->puiss);
        P2=P2->suiv;
    }
    p_somme=simplifier(p_somme);
    return p_somme;
}
   

polynome produit(polynome P1,polynome P2)
{
    polynome p_produit=nullptr;
    polynome P3=P2;
    while(P1!=nullptr)
    {
        while(P3!=nullptr)
        {
            ajouterfin(p_produit,P3->coeff*P1->coeff,P1->puiss+P3->puiss);
            P3=P3->suiv;
        }
        P1=P1->suiv;
        P3=P2;
        
    }
    p_produit=simplifier(p_produit);
    return p_produit;
}

void échange_float(float &a,float &b)
{
    float v=a;
    a=b;
    b=v;
}

void échange_int(int &a,int &b)
{
    int v=a;
    a=b;
    b=v;
}

void boucle(int n,polynome &P)
{
    polynome fin=nullptr;
    polynome deplace=P;
    for(int i=0;i<n;i++)
    {
        deplace=deplace->suiv;
    }

    fin=deplace;
    deplace=P;
    while(deplace->suiv!=fin)
    {
        if(deplace->puiss<=deplace->suiv->puiss)
        {
            échange_int(deplace->puiss,deplace->suiv->puiss);
            échange_float(deplace->coeff,deplace->suiv->coeff);
        }
        deplace=deplace->suiv;
    }
}


void ordonne(polynome &P)
{
    int taille=0;
    polynome r=P;
    while(r!=nullptr)
    {
        taille++;
        r=r->suiv;
    }
    for(int i=taille;i>=1;i--)
    {
        boucle(i,P);
    }
}

int main()
{   
    polynome P=nullptr;
    saisie(P,4);
    std::cout<<"P(X) = ";
    P=simplifier(P);
    afficher(P);
    std::cout<<'\n';
    float x=0;
    std::cout<<"Degre : "<<degre(P)<<'\n';
    std::cout<<"Valeur de X : ";
    std::cin>>x;
    std::cout<<"P("<<x<<") = "<<valeurEn(P,x)<<'\n';
    std::cout<<"P'(X) = " ;
    afficher(derive (P));
    std::cout<<'\n';
    std::cout<<"P(X) + P'(X) =";
    afficher(somme(P,derive(P)));
    std::cout<<'\n';
    std::cout<<"P(X) * P'(X) = ";
    polynome p_produit=produit(P,derive(P));
    afficher(p_produit);
    std::cout<<'\n';
    std::cout<<"Ordonné :";
    ordonne(p_produit);
    afficher(p_produit);
    return 0;
}
            
            
    
    
    

