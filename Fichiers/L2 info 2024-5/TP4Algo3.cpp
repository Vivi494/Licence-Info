#include <iostream>

//1)
struct date{
    int jour;
    int mois;
    int annee;
};

struct individu{
    std::string nom;
    std::string prenom;
    date datenaiss;
};

struct abGen{
    individu LeMec;
    abGen* parent1;
    abGen* parent2;
}

using arbre=abGen*;

//2)
void saisirIndividu(individu &I,std::string nom,std::string prenom,int jour,int mois,int annee){
    I.nom=nom;
    I.prenom=prenom;
    I.date.jour=jour;
    I.date.mois=mois;
    I.date.annee=annee;
}

//3)
bool estidentique (individu I1,individu I2)
{
    if (I1.nom==I2.nom and I1.prenom==I2.prenom and I1.datenaiss.jour==I2.datenaiss.jour and I1.datenaiss.mois==I2.datenaiss.mois and I1.datenaiss.annee==I2.datenaiss.annee){
        return true;
    }
    return false;
}

//4)
arbre adresse(arbre A,individu I){
    if(A==nullptr){
        return nullptr;
    }
    if(estidentique(I,A.LeMec)){
        return A;
    }
    if(adresse(A->parent1,I)!=nullptr){
        return adresse(A->parent1,I);
    }
    if(adresse(A->parent2,I)!=nullptr){
        return adresse(A->parent2,I);
    }
}

//5)
void ajouter(arbre &A,individu I1,individu I2){
    if(adresse(A,I2)!=nullptr){
        if(adresse(A,I2)->parent1==nullptr){
            adresse(a,I2)->parent1=I1;
        }
        else if(adresse(a,I2)->parent2==nullptr){
                adresse(a,I2)->parent2=I1;
            }
        else std::cout<<"déja 2 parents"<<std::endl;
    }
}

//6)
void échanger(arbre A){
    arbre tmp=A->parent1;
    A->parent1=A->parent2;
    A->parent2=tmp;
}

//7)
void afficher(individu I){
    std::cout<<"Nom : "<<I.nom<<std::endl<<"Prenom : "<<I.prenom<<std::endl<<"date de naissance : "<<I.datenaiss.jour<<'/'<<I.datenaiss.mois<<'/'<<I.datenaiss.annee<<std::endl;
}

//8)
void afficher(arbre A){
    afficher(A.LeMec);
    afficher(A->parent1);
    afficher(A->parent2);
}

//9)
int nbgen(arbre A){
    if(nbgen(A->parent1)>nbgen(A->parent2)){
        return nbgen(A->parent1)+1;
    }
    else return nbgen(A->parent2)+1;
}

//10)
int nbgencomp(arbre A){
    if(nbgen(A->parent1)>nbgen(A->parent2)){
        return nbgen(A->parent2)+1;
    }
    else return nbgen(A->parent1)+1;
}

//11)
bool estValide(individu I1,individu I2){
    if(I1.datenaiss.annee>I2.datenaiss.annee){
        return true;
    }
    else return false;
}

bool estValide(arbre A){
    if(estValide(A.individu,A->parent1.individu) and estValide(A.individu,A->parent2.individu) and estValide(A->parent1) and estValide(A->parent2)){
        return true;
    }
    return false;
}

//12)
arbre relier(individu I,arbre A1,arbre A2){
    arbre A=new abGen;
    A->LeMec=I;
    A->parent1=A1;
    A->parent2=A2;
    return A;
}

//13)


int main(){
    arbre A=nullptr;
    return 0;
}
