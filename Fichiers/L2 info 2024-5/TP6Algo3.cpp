#include<iostream>

//1)
struct Noeud{
    int val;
    Noeud* droit;
    Noeud* gauche;
    int hauteur;
};

using Arbre=Noeud*;

//2)
Arbre insere(Arbre A,int i){
    A->val=i;
    return A;
}

void ajouter(Arbre &A,int i){
    if(A->val<i){
        if(A->droit==nullptr){
            A->droit=insere(A->droit,i);
        }
        else{
            ajouter(A->droit,i);
        }
    }
    else{
        if(A->gauche==nullptr){
            A->gauche=insere(A->droit,i);
        }
        else{
            ajouter(A->gauche,i);
        }
    }
}

//3)
Arbre generer(int* tab,int taille){
    Arbre A;
    for(int i=0;i<taille;i++){
        ajouter(A,tab[i]);
    }
    return A;
}

//4)
void afficher(Arbre A){
    if(A!=nullptr){
        afficher(A->gauche);
        std::cout<<A->val<<' ';
        afficher(A->droit);
    }
}

//5)
bool search(Arbre A,int i){
    if(A==nullptr)return false;
    if(A->val==i)return true;
    if(A->val<i)return search(A->droit,i);
    return search(A->gauche,i);
}

//6)
int plus_grand(Arbre A){
    if(A->droit!=nullptr)return plus_grand(A->droit);
    return A->val;
}

void remplacer(Arbre A);

void suppr(Arbre A,int i){
    if(A!=nullptr){
        if(A->val==i)remplacer(A);
        else{
            if(A->val<i)suppr(A->droit,i);
            else suppr(A->gauche,i);
        }
    }
}

void remplacer(Arbre A){
    Arbre tmp=nullptr;
    if(A->gauche!=nullptr and A->droit==nullptr){
        tmp=A;
        A=A->gauche;
        delete tmp;
    }
    if(A->droit!=nullptr and A->gauche==nullptr){
        tmp=A;
        A=A->droit;
        delete tmp;
    }
    if(A->gauche==nullptr and A->droit==nullptr){
        delete A;
    }
    else{
        A->val=plus_grand(A->gauche);
        suppr(A->gauche,plus_grand(A->gauche));
    }
}

//7)
int calcul(Arbre A,int i){
    if(A->val<i){
        return 1+calcul(A->droit,i)+calcul(A->gauche,i);
    }
    else return calcul(A->gauche,i);
}

//8)
void fusionner(Arbre &A1,Arbre &A2){
    ajouter(A1,A2->val);
    fusionner(A1,A2->gauche);
    fusionner(A1,A2->droit);
    delete A2;
}

//9)
int profondeur(Arbre A){
    if(A==nullptr){
        return 0;
    }
    if(profondeur(A->droit)<profondeur(A->gauche))return 1+profondeur(A->droit);
    return profondeur(A->gauche);
}

bool equilibre(Arbre A){
    if(A==nullptr)return true;
    if(profondeur(A->droit)-profondeur(A->gauche)==0 or profondeur(A->droit)-profondeur(A->gauche)==-1 or profondeur(A->droit)-profondeur(A->gauche)==1){
        if(equilibre(A->droit) and equilibre(A->gauche))return true;
    }
    return false;
}

//10)
void deletepost(Arbre A){
    deletepost(A->gauche);
    deletepost(A->droit);
    delete A;
}

//11)
void majh(Arbre A,int h){
    A->hauteur=h;
    majh(A->gauche,h+1);
    majh(A->droit,h+1);
}

//12)
