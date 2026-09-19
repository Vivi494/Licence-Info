#include <iostream>
#include <string>
#include <array>
#include <fstream>

/*TP1

//Déclaration de Types

struct occMot{
    std::string str;
    int nbocc;
};

struct Maillon{
    occMot O;
    Maillon* suiv;
};

using listeMots=Maillon*;

struct tabMots{
    std::string* tab;
    int taille;
};

//Partie I

//1)

void initialise(listeMots& L){
    L=nullptr;
}

//2)

void ajouteDebut(std::string mot, listeMots& L){
    Maillon* m=new Maillon;
    m->O.str=mot;
    m->O.nbocc=1;
    m->suiv=L;
    L=m;
}

//3)

void ajoute(std::string mot, listeMots& L){
    if(L==nullptr){
        ajouteDebut(mot,L);
    }
    else{
        if(L->O.str>mot){
            ajouteDebut(mot,L);
        }
        else if(L->O.str<mot){
            ajoute(mot,L->suiv);
        }
        else{
            L->O.nbocc++;
        }
    }
}

//4)

void affiche(listeMots L){
    if(L!=nullptr){
        std::cout<<L->O.str<<'('<<L->O.nbocc<<')'<<' ';
        affiche(L->suiv);
    }
}

//5)
int taille(listeMots L){
    if(L==nullptr){
        return 0;
    }
    else{
        return taille(L->suiv)+1;
    }
}

//6)
int NombreMots(listeMots L){
    if(L==nullptr){
        return 0;
    }
    else{
        return NombreMots(L->suiv)+L->O.nbocc;
    }
}

//7)
bool estValide(listeMots L){
    if(L==nullptr){
        return true;
    }
    if(L->suiv!=nullptr && L->suiv->O.str<=L->O.str){
        return false;
    }
    if(L->O.nbocc<1){
        return false;
    }
    return estValide(L->suiv);
}

//8)
long unsigned int plusLong(listeMots L){
    if(L==nullptr){
        return 0;
    }
    if(L->O.str.length()>=plusLong(L->suiv)){
        return L->O.str.length();
    }
    else return plusLong(L->suiv);
}

//9)
void afficheLongueur(listeMots L, long unsigned int longueur){
    if(L!=nullptr){
        if(L->O.str.length()==longueur){
            std::cout<<L->O.str<<' ';
        }
    }
}

//10)
void afficheTriLongueur(listeMots L){
    for(long unsigned int i=1;i<plusLong(L);i++){
        afficheLongueur(L,i);
    }
}

//11)
void saisit(listeMots& L){
    std::string mot;
    std::cout<<"Entrez des mots(fin pour terminer)";
    std::cin>>mot;
    while(mot!="fin"){
        ajoute(mot, L);
        std::cin>>mot;
    }
}

//12)
void construit(listeMots& L, std::string nomFichier){
    std::string ch = nomFichier;
    std::ifstream fic;
    fic.open(ch);
    if(fic.is_open()){
        std::string mot;
        while(fic.good()){
            fic>>mot;
            ajoute(mot, L);
        }
    }
}

//13)
void remplit(tabMots& T, listeMots L){
    listeMots tmp=L;
    T.taille = taille(L);
    T.tab = new std::string[T.taille];
    int i = 0;
    while(tmp!=nullptr){
        T.tab[i++]=tmp->O.str;
        tmp=tmp->suiv;
    }
}

//14)
void affiche(tabMots& T){
    for(int i=0;i<T.taille;i++){
        std::cout<<T.tab[i]<<' ';
    }
}

//15)

bool appartient(std::string mot, tabMots T,int d,int f){
    if(d>f){
        return false;
    }
    int m=(d+f)/2;
    if(T.tab[m]==mot){
        return true;
    }
    if(T.tab[m]>mot){
        return appartient(mot, T, d, m-1);
    }
    return appartient(mot, T, m+1, f);
}

//Partie II

//17)

struct occLettre{
    char c;
    int nbocc;
};

using tabLettres= std::array<occLettre,26>;

//18)

void initialise(tabLettres& T){
    for(int i=0;i<26;i++){
        T[i].c=(char)i+97;
        T[i].nbocc=0;
    }
}

//19)

void ajoute(char lettre, tabLettres& T){
    int l=(int)lettre-97;
    T[l].nbocc++;
}

//20)

void comptabilise(tabLettres& T, listeMots L){
    if(L!=nullptr){
        std::string mot=L->O.str;
        for(char car:mot){
            ajoute(car,T);
        }
        comptabilise(T, L->suiv);
    }
}

//21)

void trie(tabLettres& T){
    for(int i=1;i<26;i++){
        for(int j=0;j<25;j++){
            if(T[i].nbocc>T[j].nbocc){
                occLettre tmp=T[i];
                T[i]=T[j];
                T[j]=tmp;
            }
        }
    }
}

//22)

void affiche(tabLettres T){
    for(int i=0;i<26;i++){
        std::cout<<T[i].c<<'['<<T[i].nbocc<<"] ";
    }
    std::cout<<std::endl;
}

//main

//16.23)

int main(){
    listeMots L;
    tabMots T;
    std::string mot;
    initialise(L);
    construit(L,"bouledesuif.txt");
    remplit (T,L);
    affiche(T);
    std::cout<<'\n'<<"De quel mot voulez vous connaitre l'appartenance ?\n";
    std::cout<<T.taille<<'\n';
    std::cin>>mot;
    std::cout<<std::boolalpha<<appartient(mot, T, 0, T.taille)<<'\n';
    tabLettres Tab;
    initialise(Tab);
    comptabilise(Tab,L);
    trie(Tab);
    affiche(Tab);
    return 0;
}
*/

/*TP2

//declaration de types

using element=int;

struct maillon{
    element e;
    maillon* suiv;
    maillon* prec;
};

struct liste{
    maillon* first;
    maillon* last;
};

//1)

void initialise(liste& L){
    L.first=nullptr;
    L.last=nullptr;
}


//2)

bool estVide(liste L){
    if(L.first==nullptr){
        return true;
    }
    return false;
}

//3)

void insereTete(liste& L,element e){
    maillon* m=new maillon;
    m->e=e;
    m->suiv=L.first;
    m->prec=nullptr;
    if(!estVide(L)){
        L.first->prec=m;
    }
    else{
        m->suiv=nullptr;
        L.last=m;
    }
    L.first=m;
}

//4)

void insereQueue(liste& L,element e){
    maillon* m=new maillon;
    m->e=e;
    m->prec=L.last;
    m->suiv=nullptr;
    std::cout<<"oui"<<std::endl;
    if(estVide(L)){
        m->prec=nullptr;
        L.first=m;
    }
    else{
        L.last->suiv=m;
    }
    L.last=m;
}

//5)

void afficherRecu(maillon* m){
    if(m!=nullptr){
        std::cout<<m->e<<' ';
        afficherRecu(m->suiv);
    }
}

void afficherRec(liste L){
    afficherRecu(L.first);
}

void afficherIte(liste L){
    maillon* tmp=L.first;
    while(tmp!=L.last){
        std::cout<<tmp->e<<' ';
        tmp=tmp->suiv;
    }
    std::cout<<tmp->e<<' ';
}

//6)
void afficherQueue(liste L){
    maillon* tmp=L.last;
    while(tmp!=L.first){
        std::cout<<tmp->e<<' ';
        tmp=tmp->prec;
    }
    std::cout<<tmp->e<<' ';
}

//7)

int longueur(liste L){
    if(estVide(L)){
        return 0;
    }
    int taille=0;
    maillon* tmp=L.first;
    while(tmp!=L.last){
        taille++;
        tmp=tmp->suiv;
    }
    return ++taille;
}

//8)

void supprimerTete(liste& L){
    if(!estVide(L)){
        if(L.first==L.last){
            delete L.first;
            L.first=nullptr;
            L.last=nullptr;
        }
        else{
            L.first=L.first->suiv;
            delete L.first->prec;
            L.first->prec=nullptr;
        }
    }
}

//9)

void supprimerQueue(liste& L){
    if(!estVide(L)){
        if(L.first==L.last){
            delete L.first;
            L.first=nullptr;
            L.last=nullptr;
        }
        else{
            L.last=L.last->prec;
            delete L.last->suiv;
            L.last->suiv=nullptr;
        }
    }
}

//10)

maillon* appartient(maillon* m,element x){
    if(m==nullptr){
        return nullptr;
    }
    else if(m->e==x){
        return m;
    }
    else{
        return appartient(m->suiv,x);
    }
}

maillon* appartient(liste L,element x){
    if(L.first==nullptr){
        return nullptr;
    }
    else{
        return appartient(L.first,x);
    }
}

//11)

void insererApres(element y,element x,liste& L){
    maillon* tmp=appartient(L,x);
    if(tmp!=nullptr){
        maillon* m=new maillon;
        m->prec=tmp;
        m->suiv=tmp->suiv;
        tmp->suiv=m;
        m->e=y;
        if(m->suiv!=nullptr){
            m->suiv->prec=m;
            L.first=m;
        }
    }
}

//13)

void insererAvant(element y,element x,liste& L){
    maillon* tmp=appartient(L,x);
    if(tmp!=nullptr){
        maillon* m=new maillon;
        m->suiv=tmp;
        m->prec=tmp->prec;
        tmp->prec=m;
        m->e=y;
        if(m->prec!=nullptr){
            m->prec->suiv=m;
            L.last=m;
        }
    }
}

//14)

void supprimer(liste& L){
    if(L.first==L.last){
        supprimerTete(L);
    }
    else{
        supprimerTete(L);
        supprimer(L);
    }
}

//15)

void supprimer(liste& L,maillon* p){
    if(L.last!=p){
        supprimerQueue(L);
        supprimer(L,p);
    }
}

//main

int main(){
    liste L;
    initialise(L);
    insereQueue(L,12);
    insereTete(L,11);
    return 0;
}*/

/*TP3

//1)

using element=float;

struct maillon{
    element e;
    maillon* suiv;
};

using pile = maillon*;

const int MAXTAILLE=100;

using Tableau=std::array<std::string,MAXTAILLE>;

void initialiser(pile& P){
    P=nullptr;
}

void empiler(element e,pile& P){
    maillon* m=new maillon;
    m->suiv=P;m->e=e;
    P=m;
}

element depiler(pile& P){
    if(P!=nullptr){
        element e=P->e;
        maillon* tmp=P;
        P=P->suiv;
        delete(tmp);
        return e;
    }
    return 0;
}

void afficherTableau(Tableau Tab,int taille){
    for(int i=0;i<taille;i++){
        std::cout<<Tab[i];
    }
}

float calculer(Tableau Tab,int taille,pile P){
    for(int i=0;i<taille;i++){
        if(Tab[i]!="+" && Tab[i]!="-" && Tab[i]!="*" && Tab[i]!="/"){
            std::cout<<Tab[i]<<std::endl;
            empiler((std::stof(Tab[i])),P);
        }
        else{
            if(Tab[i]!="+"){
                empiler((depiler(P)+depiler(P)),P);
            }
            if(Tab[i]!="-"){
                float b=depiler(P);
                float a=depiler(P);
                empiler((a-b),P);
            }
            if(Tab[i]!="*"){
                empiler((depiler(P)*depiler(P)),P);
            }
            if(Tab[i]!="/"){
                float b=depiler(P);
                float a=depiler(P);
                empiler((a/b),P);
            }
        }
    }
    return depiler(P);
}

int main(){
    Tableau Tab;
    pile P;
    initialiser(P);
    std::string tmp="";
    int i=0;
    std::cin>>tmp;
    while(tmp!="a"){
        Tab[i]=tmp;
        i++;
        std::cin>>tmp;
    }
    std::cout<<calculer(Tab,i,P);;
    return 0;
}
*/

/*TP4

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
    individu I;
    abGen* parent1;
    abGen* parent2;
};

using Arbre=abGen*;


//2)

void SaisirInfosIndividu(individu& I,std::string nom,std::string prenom,int jour,int mois,int annee){
    I.nom=nom;
    I.prenom=prenom;
    I.datenaiss.jour=jour;
    I.datenaiss.mois=mois;
    I.datenaiss.annee=annee;
}

//3)

bool CompareIndividu(individu I1,individu I2){
    if(I1.nom==I2.nom && I1.prenom==I2.prenom && I1.datenaiss.jour==I2.datenaiss.jour && I1.datenaiss.mois==I2.datenaiss.mois && I1.datenaiss.annee==I2.datenaiss.annee){
        return true;
    }
    else{
        return false;
    }
}

//4)

Arbre RechercheIndividu(Arbre A,individu I){
    if(A==nullptr){
        return nullptr;
    }
    else if(CompareIndividu(A->I,I)==true){
        return A;
    }
    else{
        Arbre parent1=RechercheIndividu(A->parent1,I);
        if(parent1!=nullptr){
            return parent1;
        }
        else{
            Arbre parent2=RechercheIndividu(A->parent2,I);
            if(parent2!=nullptr){
                return parent2;
            }
        }
    }
    return nullptr;
}

//5)

void InitialiserArbre(Arbre & A,individu I){
    A=new abGen;
    A->I=I;
    A->parent1=nullptr;
    A->parent2=nullptr;
}

void ajouterArbre(Arbre& A,individu I,individu parent){
    Arbre Ancetre=RechercheIndividu(A,parent);
    if(Ancetre!=nullptr){
        if(Ancetre->parent1==nullptr){
            Arbre tmp=new abGen;
            tmp->I=I;
            Ancetre->parent1=tmp;
        }
        else if(Ancetre->parent2==nullptr){
            Arbre tmp=new abGen;
            tmp->I=I;
            Ancetre->parent2=tmp;
        }
    }
}

//6)

void echanger(Arbre A){
    Arbre tmp=A->parent1;
    A->parent1=A->parent2;
    A->parent2=tmp;
}

//7)

void afficherIndividu(individu I){
    std::cout<<I.nom<<' '<<I.prenom<<' '<<I.datenaiss.jour<<' '<<I.datenaiss.mois<<' '<<I.datenaiss.annee<<'\n';
}

//8)
void afficherArbre(Arbre A){
    if(A!=nullptr){
        afficherIndividu(A->I);
        afficherArbre(A->parent1);
        afficherArbre(A->parent2);
    }
}

//question supplementaire:utiliser des files

//9)

int GenMax(Arbre A){
    if(A==nullptr){
        return 0;
    }
    int prof1=GenMax(A->parent1);
    int prof2=GenMax(A->parent2);
    if(prof1<prof2){
        return prof2+1;
    }
    return prof1+1;
}

//10)

int GenMin(Arbre A){
    if(A==nullptr){
        return 0;
    }
    int prof1=GenMin(A->parent1);
    int prof2=GenMin(A->parent2);
    if(prof1>prof2){
        return prof2+1;
    }
    return prof1+1;
}

//11)

bool ValiditeParent(individu I,individu I2){
    if(I.datenaiss.annee>I2.datenaiss.annee){
    return false;
    }
    else if(I.datenaiss.annee<I2.datenaiss.annee){
        return true;
    }
    else{
        if(I.datenaiss.mois>I2.datenaiss.mois){
            return false;
        }
        else if(I.datenaiss.annee<I2.datenaiss.annee){
            return true;
        }
        else{
            if(I.datenaiss.annee<I2.datenaiss.annee){
                return true;
            }
            else return false;
        }
    }
}

bool ValiditeArbre(Arbre A){
    if(A==nullptr){
        return true;
    }
    if(A->parent1==nullptr && A->parent2==nullptr){
        return true;
    }
    if((ValiditeParent(A->I,A->parent1->I)==true) && (ValiditeParent(A->I,A->parent2->I)==true)){
        if(ValiditeArbre(A->parent1)==true && ValiditeArbre(A->parent2)==true){
            return true;
        }
    }
    return false;
}

//12)

Arbre fusion(Arbre A1,Arbre A2,individu I){
    Arbre A=new abGen;
    A->I=I;
    A->parent1=A1;
    A->parent2=A2;
    return A;
}

//13)

Arbre lireFichier(std::string NomFichier){
    Arbre A;
    std::ifstream fic;
    fic.open(NomFichier);
    std::array<Arbre,1000> Tab;
    individu I;
    int id;
    int parent1;
    int parent2;
    Tab[0]=nullptr;
    fic>>id;
    fic>>I.nom;
    fic>>I.prenom;
    fic>>I.datenaiss.annee;
    fic>>I.datenaiss.mois;
    fic>>I.datenaiss.jour;
    fic>>parent1;
    fic>>parent2;
    Tab[id]=new abGen;
    Tab[id]->I=I;
    InitialiserArbre(A,I);
    while(fic.good()){
        fic>>id;
        fic>>I.nom;
        fic>>I.prenom;
        fic>>I.datenaiss.annee;
        fic>>I.datenaiss.mois;
        fic>>I.datenaiss.jour;
        fic>>parent1;
        fic>>parent2;
        Tab[id]=fusion(Tab[parent1],Tab[parent2],I);
    }
    return Tab[1];
}

int main(){
    std::string NomFichier="genealogie.txt";
    afficherArbre(lireFichier(NomFichier));
}
*/

/*TP5

//1)
struct ArbreTab{
    int taille;
    int racine;
    std::array<std::string,100> etiquettes;
    std::array<int,100> gauche;
    std::array<int,100> droite;
    std::array<int,100> pere;
};

struct maillon{
    std::string nom;
    maillon* sag;
    maillon* sad;
};

using Arbre=maillon*;

//2)
ArbreTab lireFichier(std::string NomFichier){
    ArbreTab A;
    std::ifstream fic;
    fic.open(NomFichier);
    fic>>A.taille;
    fic>>A.racine;
    int indice=1;
    A.pere[A.racine]=0;
    while(fic.good() && (indice <= A.taille)){
        fic>>A.etiquettes[indice];
        fic>>A.gauche[indice];
        if(A.gauche[indice]!=0){
            A.pere[A.gauche[indice]]=indice;
        }
        fic>>A.droite[indice];
        if(A.droite[indice]!=0){
            A.pere[A.droite[indice]]=indice;
        }
        indice++;
    }
    return A;
}

Arbre construireMaillon(ArbreTab Tab,int indice){
    if(indice!=0){
        Arbre A;
        A=new maillon;
        A->nom=Tab.etiquettes[indice];
        A->sag=construireMaillon(Tab,Tab.gauche[indice]);
        A->sad=construireMaillon(Tab,Tab.droite[indice]);
        return A;
    }
    else return nullptr;
}

Arbre construire(ArbreTab Tab){
    Arbre A;
    A=new maillon;
    A->nom=Tab.etiquettes[Tab.racine];
    A->sag=construireMaillon(Tab,Tab.gauche[Tab.racine]);
    A->sad=construireMaillon(Tab,Tab.droite[Tab.racine]);
    return A;
}

void afficherArbre(Arbre A){
    if(A!=nullptr){
        std::cout<<A->nom<<"\n";
        afficherArbre(A->sag);
        afficherArbre(A->sad);
    }
}

//3)
int profondeur(ArbreTab Tab,int indice){
    if(indice!=0){
        int gauche,droite;
        droite=profondeur(Tab,Tab.droite[indice]);
        gauche=profondeur(Tab,Tab.gauche[indice]);
        if(gauche<droite){
            return 1+droite;
        }
        return 1+gauche;
    }
    return -1;
}

//4)
void afficherNoeud(ArbreTab Tab,int indice){
    std::string str=Tab.etiquettes[indice];
    if(Tab.gauche[indice]!=0){
        str=str+" "+Tab.etiquettes[Tab.gauche[indice]];
    }
    else{
        str=str+" *";
    }
    if(Tab.droite[indice]!=0){
        str=str+" "+Tab.etiquettes[Tab.droite[indice]];
    }
    else{
        str=str+" *";
    }
    if(Tab.pere[indice]!=0){
        str=str+" "+Tab.etiquettes[Tab.pere[indice]];
    }
    else{
        str=str+" *";
    }
    std::cout<<str<<'\n';
    if(Tab.gauche[indice]!=0){
        afficherNoeud(Tab,Tab.gauche[indice]);
    }
    if(Tab.droite[indice]!=0){
        afficherNoeud(Tab,Tab.droite[indice]);
    }
}


void afficherTab(ArbreTab Tab){
    std::string str=Tab.etiquettes[Tab.racine];
    if(Tab.gauche[Tab.racine]!=0){
        str=str+" "+Tab.etiquettes[Tab.gauche[Tab.racine]];
    }
    else{
        str=str+" *";
    }
    if(Tab.droite[Tab.racine]!=0){
        str=str+" "+Tab.etiquettes[Tab.droite[Tab.racine]];
    }
    else{
        str=str+" *";
    }
    if(Tab.pere[Tab.racine]!=0){
        str=str+" "+Tab.etiquettes[Tab.pere[Tab.racine]];
    }
    else{
        str=str+" *";
    }
    std::cout<<str<<'\n';
    if(Tab.gauche[Tab.racine]!=0){
        afficherNoeud(Tab,Tab.gauche[Tab.racine]);
    }
    if(Tab.droite[Tab.racine]!=0){
        afficherNoeud(Tab,Tab.droite[Tab.racine]);
    }
}

//13)
struct mailloncar{
    char c;
    mailloncar* suiv;
};

struct filecara{
    mailloncar* premier;
    mailloncar* dernier;
};

void initialiserfile(filecara& F){
    F.premier=nullptr;
    F.dernier=nullptr;
}

bool estVidefile(filecara F){
    if(F.premier==nullptr){
        return true;
    }
    return false;
}

char consulter(filecara F){
    if(F.premier!=nullptr){
        return F.premier->c;
    }
    return 0;
}

void ajouter(filecara& F,char c){
    mailloncar* m=new mailloncar;
    m->c=c;
    if(estVidefile(F)){
        F.premier=m;
        F.dernier=m;
    }
    else{
        F.dernier->suiv=m;
        F.dernier=m;
    }
}

void retirer(filecara& F){
    if(!estVidefile(F)){
        mailloncar* tmp=F.premier;
        if(F.premier->suiv==nullptr){
            F.premier=nullptr;
            F.dernier=nullptr;
        }
        else{
            F.premier=F.premier->suiv;
        }
        delete tmp;
    }
}

void afficheFile(filecara F){
    if(!estVidefile(F)){
        mailloncar* tmp=F.premier;
        while(tmp!=nullptr){
            std::cout<<tmp->c<<" ";
            tmp=tmp->suiv;
        }
        std::cout<<'\n';
    }
}

//5)
struct Noeud{
    std::string str;
    Noeud* sag;
    Noeud* sad;
    Noeud* pere;
    filecara F;
};

using ArbreBinaire=Noeud*;

//6)
ArbreBinaire construireMaillonBinaire(ArbreTab Tab,int indice){
    if(indice!=0){
        ArbreBinaire A;
        A=new Noeud;
        A->str=Tab.etiquettes[indice];
        initialiserfile(A->F);
        A->sag=construireMaillonBinaire(Tab,Tab.gauche[indice]);
        A->sad=construireMaillonBinaire(Tab,Tab.droite[indice]);
        if(A->sag!=nullptr){
            A->sag->pere=A;
        }
        if(A->sad!=nullptr){
            A->sad->pere=A;
        }
        return A;
    }
    else return nullptr;
}

ArbreBinaire construireBinaire(ArbreTab Tab){
    ArbreBinaire A;
    A=new Noeud;
    A->str=Tab.etiquettes[Tab.racine];
    A->sag=construireMaillonBinaire(Tab,Tab.gauche[Tab.racine]);
    A->sad=construireMaillonBinaire(Tab,Tab.droite[Tab.racine]);
    A->pere=nullptr;
    if(A->sag!=nullptr){
        A->sag->pere=A;
    }
    if(A->sad!=nullptr){
        A->sad->pere=A;
    }
    return A;
}

int profondeurBin(ArbreBinaire A){
    if(A==nullptr){
        return -1;
    }
    else{
        int profg=profondeurBin(A->sag);
        int profd=profondeurBin(A->sad);
        if(profd>profg){
            return profd+1;
        }
        else return profg+1;
    }
}

void afficherArbreBinaire(ArbreBinaire A){
    if(A!=nullptr){
        std::string str=A->str;
        if(A->sag!=nullptr){
            str=str+" "+A->sag->str;
        }
        else{
            str=str+" *";
        }
        if(A->sad!=nullptr){
            str=str+" "+A->sad->str;
        }
        else{
            str=str+" *";
        }
        if(A->pere!=nullptr){
            str=str+" "+A->pere->str;
        }
        else{
            str=str+" *";
        }
        std::cout<<str<<'\n';
        afficherArbreBinaire(A->sag);
        afficherArbreBinaire(A->sad);
    }
}

//7)
bool estFeuille(ArbreBinaire A){
    if(A->sad==nullptr && A->sag==nullptr){
        return true;
    }
    return false;
}

bool estRacine(ArbreBinaire A){
    if(A->pere==nullptr){
        return true;
    }
    return false;
}

bool estNoeudInterne(ArbreBinaire A){
    if(estFeuille(A)==false && estRacine(A)==false){
        return true;
    }
    return false;
}

bool estFilsGauche(ArbreBinaire A){
    if(A==nullptr){
        return false;
    }
    if(A->pere==nullptr){
        return false;
    }
    if(A->pere->sag==A){
        return true;
    }
    return false;
}

bool estFilsDroit(ArbreBinaire A){
    if(A==nullptr){
        return false;
    }
    if(A->pere==nullptr){
        return false;
    }
    if(A->pere->sad==A){
        return true;
    }
    return false;
}

//8)
int NBFeuilles(ArbreBinaire A){
    if(A==nullptr){
        return 0;
    }
    if(estFeuille(A)){
        return 1;
    }
    else{
        return NBFeuilles(A->sad)+NBFeuilles(A->sag);
    }
}

//9)
void afficheFeuilles(ArbreBinaire A){
    if(A!=nullptr){
        if(estFeuille(A)){
            std::cout<<A->str<<" ";
        }
        else{
            afficheFeuilles(A->sag);
            afficheFeuilles(A->sad);
        }
    }
}

//10)
int hauteur(ArbreBinaire A){
    if(A->pere!=nullptr){
        return hauteur(A->pere);
    }
    else return profondeurBin(A);
}

//11)
ArbreBinaire recherche(ArbreBinaire A,std::string str){
    if(A==nullptr){
        return nullptr;
    }
    if(A->str==str){
        return A;
    }
    ArbreBinaire gauche=recherche(A->sag,str);
    if(gauche!=nullptr){
        return gauche;
    }
    return recherche(A->sad,str);
}

//12)
void supprime(ArbreBinaire& A){
    if(A!=nullptr){
        supprime(A->sag);
        supprime(A->sad);
        delete A;
    }
}

//16)
void passercommandeM(ArbreBinaire A,ArbreBinaire B){
    if(A!=nullptr and B!=nullptr){
        if(A!=B){
            if(estFilsGauche(B)){
                ajouter(B->pere->F,'G');
            }
            else if(estFilsDroit(B)){
                ajouter(B->pere->F,'D');
            }
            passercommandeM(A,B->pere);
        }
    }
}

void passercommande(ArbreBinaire A,std::string commanditaire){
    if(commanditaire!=A->str){
        ArbreBinaire B=recherche(A,commanditaire);
        std::cout<<"B=" <<B<<std::endl;
        if(estFilsGauche(B)){
            std::cout<<"oui"<<std::endl;
            ajouter(B->pere->F,'G');
        }
        else if(estFilsDroit(B)){
            std::cout<<"oui"<<std::endl;
            ajouter(B->pere->F,'D');
        }
        passercommandeM(A,B->pere);
    }
}

//17)
void livrer(ArbreBinaire A){
    if(!estVidefile(A->F)){
        char c=consulter(A->F);
        retirer(A->F);
        std::cout<<A->str<<" => ";
        if(c=='G'){
            livrer(A->sag);
        }
        else{
            livrer(A->sad);
        }
    }
    else{
        std::cout<<A->str<<'\n';
    }

}

void livraison(ArbreBinaire A){
    while(!estVidefile(A->F)){
        livrer(A);
    }
}

//18)
void afficheEtat(ArbreBinaire A){
    if(A!=nullptr){
        std::cout<<A->str<<' ';
        afficheFile(A->F);
        afficheEtat(A->sag);
        afficheEtat(A->sad);
    }
}

//19)
void simuleF3(ArbreBinaire A){
    passercommande(A,"magasin_1");
    passercommande(A,"magasin_5");
    passercommande(A,"magasin_1");
    passercommande(A,"magasin_4");
    passercommande(A,"magasin_4");
    passercommande(A,"magasin_2");
    passercommande(A,"magasin_3");
    passercommande(A,"magasin_5");
    afficheEtat(A);
    std::cout<<std::endl;
    livraison(A);
    afficheEtat(A);
    std::cout<<std::endl;
}

int main(){
    ArbreTab Tab=lireFichier("usine1.txt");
    Arbre A=construire(Tab);
    afficherArbre(A);
    std::cout<<profondeur(Tab,Tab.racine)<<'\n';
    afficherTab(Tab);
    ArbreBinaire AB=construireBinaire(Tab);
    std::cout<<profondeurBin(AB)<<'\n';
    afficherArbreBinaire(AB);
    filecara F;
    initialiserfile(F);
    simuleF3(AB);
    return 0;
}
*/

/*TP6

//Partie I

//1)
struct Noeud{
    int val;
    Noeud* sag;
    Noeud* sad;
};

using ABR= Noeud*;

//2)
void Ajouter(ABR& A,int i){
    if(A==nullptr){
        A=new Noeud;
        A->val=i;
    }
    else{
        if(i>A->val){
            Ajouter(A->sad,i);
        }
        else{
            Ajouter(A->sag,i);
        }
    }
}

//3)
ABR Generer(int* T1,int n1){
    ABR A=nullptr;
    for(int i=0;i<n1;i++){
        Ajouter(A,T1[i]);
    }
    return A;
}

//4)
void afficherABR(ABR A){
    if(A!=nullptr){
        afficherABR(A->sag);
        std::cout<<A->val<<" "<<A<<" "<<A->sag<<" "<<A->sad<<'\n';
        afficherABR(A->sad);
    }
}

void printBT(const std::string& prefix, const Noeud* node, bool isLeft){
    if( node != nullptr ){
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->val << std::endl;
        //std::cout << node->hauteur << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│ " : " "), node->sag, true);
        printBT( prefix + (isLeft ? "│ " : " "), node->sad, false);
    }
}

void afficherABRTree(ABR A){
    printBT("",A,false);
}

//5)
bool recherche(ABR A,int i){
    if(A!=nullptr){
        if(A->val==i){
            return true;
        }
        else{
            if(A->val<i){
                return recherche(A->sad,i);
            }
            else{
                return recherche(A->sag,i);
            }
        }
    }
    return false;
}

//6)
ABR plusGrand(ABR A){
    if(A==nullptr){
        return nullptr;
    }
    if(A->sad!=nullptr){
        return plusGrand(A->sad);
    }
    return A;
}

void suppression(ABR &A,int e){
    if(A!=nullptr){
        if(A->val==e){
            if(A->sad!=nullptr){
                if(A->sag!=nullptr){
                    ABR PG=plusGrand(A->sag);
                    A->val=PG->val;
                    suppression(A->sag,PG->val);
                }
                else{
                    ABR tmp=A;
                    A=A->sad;
                    delete tmp;
                }
            }
            else{
                if(A->sag!=nullptr){
                    ABR tmp=A;
                    A=A->sag;
                    delete tmp;
                }
                else{
                    delete A;
                }
            }
        }
        else{
            if(A->val<e){
                suppression(A->sad,e);
            }
            else{
                suppression(A->sag,e);
            }
        }
    }
}

//7)

int calculer(ABR A,int i){
    if(A==nullptr){
        return 0;
    }
    else{
        if(A->val>=i){
            return calculer(A->sag,i);
        }
        else{
            return A->val+calculer(A->sag,i)+calculer(A->sad,i);
        }
    }
}

//8)

void fusionnerABR(ABR& A1,ABR& A2){
    if(A2!=nullptr){
        Ajouter(A1,A2->val);
        fusionnerABR(A1,A2->sag);
        fusionnerABR(A1,A2->sad);
    }
}

//9)

int hauteur(ABR A){
    if(A!=nullptr){
        int gauche=hauteur(A->sag);
        int droite=hauteur(A->sad);
        if(droite>gauche){
            return 1+droite;
        }
        else{
            return 1+gauche;
        }
    }
    return -1;
}

bool estEquilibre(ABR A){
    if(A!=nullptr){
        if(!estEquilibre(A->sag) || !estEquilibre(A->sad)){
            return false;
        }
        else{
            if(hauteur(A->sag)-hauteur(A->sad)<-1 || hauteur(A->sag)-hauteur(A->sad)>1){
                return false;
            }
        }
    }
    return true;
}

//10)

void liberer(ABR A){
    if(A!=nullptr){
        liberer(A->sag);
        liberer(A->sad);
        std::cout<<A->val<<" "<<A<<'\n';
    }
}

//11)

struct NoeudAVL{
    int val;
    NoeudAVL* sag;
    NoeudAVL* sad;
    int hauteur;
};

using AVL= NoeudAVL*;

int hauteur(AVL A){
    if(A!=nullptr){
        int gauche=hauteur(A->sag);
        int droite=hauteur(A->sad);
        if(droite>gauche){
            return 1+droite;
        }
        else{
            return 1+gauche;
        }
    }
    return -1;
}

void majHauteur(AVL &A){
    if(A!=nullptr){
        majHauteur(A->sad);
        majHauteur(A->sag);
        A->hauteur=hauteur(A);
    }
}

void printBTAVL(const std::string& prefix, const NoeudAVL* node, bool isLeft){
    if( node != nullptr ){
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->val << std::endl;
        //std::cout << node->hauteur << std::endl;

        // enter the next tree level - left and right branch
        printBTAVL( prefix + (isLeft ? "│ " : " "), node->sag, true);
        printBTAVL( prefix + (isLeft ? "│ " : " "), node->sad, false);
    }
}

void afficherAVLTree(AVL A){
    printBTAVL("",A,false);
}

//12)

void RotationGauche(AVL& A){
        AVL tmp=A;
        A=A->sad;
        tmp->sad=A->sag;
        A->sag=tmp;
        majHauteur(A);
}

void RotationDroite(AVL& A){
        AVL tmp=A;
        A=A->sag;
        tmp->sag=A->sad;
        A->sad=tmp;
        majHauteur(A);
}

void RotationGaucheDroite(AVL& A){
    RotationGauche(A->sag);
    RotationDroite(A);
    majHauteur(A);
}

void RotationDroiteGauche(AVL& A){
    RotationDroite(A->sad);
    RotationGauche(A);
    afficherAVLTree(A);
    majHauteur(A);
}

//13)

void Reequilibrer(AVL& A){
    if(A!=nullptr){
        if(hauteur(A->sad)-hauteur(A->sag)==-2){
            if(hauteur(A->sag->sad)-hauteur(A->sag->sag)==-1 || hauteur(A->sag->sad)-hauteur(A->sag->sag)==0){
                RotationDroite(A);
            }
            else if(hauteur(A->sag->sad)-hauteur(A->sag->sag)==1){
                RotationGaucheDroite(A);
            }
        }
        if(hauteur(A->sad)-hauteur(A->sag)==2){
            if(hauteur(A->sad->sad)-hauteur(A->sad->sag)==1 || hauteur(A->sad->sad)-hauteur(A->sad->sag)==0){
                RotationGauche(A);
            }
            else if(hauteur(A->sad->sad)-hauteur(A->sad->sag)==-1){
                RotationDroiteGauche(A);
            }
        }
    }
}

//14)

void AjouterAVL(AVL& A,int i){
    if(A==nullptr){
        A=new NoeudAVL;
        A->val=i;
        A->sag=nullptr;
        A->sad=nullptr;
        majHauteur(A);
    }
    else{
        if(i>A->val){
            AjouterAVL(A->sad,i);
            majHauteur(A);
            Reequilibrer(A);
        }
        else{
            AjouterAVL(A->sag,i);
            majHauteur(A);
            Reequilibrer(A);
        }
    }
}

AVL GenererAVL(int* T1,int n1){
    AVL A=nullptr;
    for(int i=0;i<n1;i++){
        std::cout<<"oui"<<std::endl;
        AjouterAVL(A,T1[i]);
        afficherAVLTree(A);
    }
    return A;
}

//17)

void comparer(AVL A,ABR A1){
    afficherAVLTree(A);
    afficherABRTree(A1);
    std::cout<<A->hauteur<<" "<<hauteur(A1)<<std::endl;
}

//main
int main(){
    int Tab[10]={5,3,7,1,8,10,9,5,7,7};
    int Tab2[10]={15 , 10 , 26 , 7 , 9 , 23 , 13 , 26 , 10 , 26};
    int TabTest[4]={5,1,5,6};
    AVL A=GenererAVL(Tab,10);
    ABR A1=Generer(Tab,10);
    afficherAVLTree(A);
    afficherABRTree(A1);
    comparer(A,A1);
    return 0;
}
*/

//TP7

struct occMot{
    std::string str;
    int nbocc;
};

using element=occMot;

struct alveole{
    bool occupe ;
    element val ;
    int suiv ;
};

struct tabHachage{
    alveole * T ;
    int m ;
    int posLibre ;
};

void initialiser (tabHachage & H, int taille)
// m : taille de la zone primaire
// r : taille de la réserve (éventuellement 0)
{
    int m=taille*85/100;
    int r=taille*15/100;
    H.T = new alveole [taille] ;
    H.m = m ;
    H.posLibre = m+r-1 ;
    for (int i = 0; i <= H.posLibre; ++i){
        H.T[i].occupe = false ;
        H.T[i].suiv = -1 ;
    }
}

int h(std::string e,int m){
    int h=5381;
    for(long unsigned int i=0;i<e.size();i++){
        h=(33*h+(int)e[i])%m;
    }
    return h;
}

void ajout (std::string e, tabHachage & H)
// on suppose la table non pleine (H.posLibre >= 0)
{
    int i = h(e,H.m);
    if (H.T[i].occupe){
        if(H.T[i].val.str==e){
            H.T[i].val.nbocc++;
        }
        else{
            while (H.T[i].suiv >= 0 && H.T[i].val.str!=e){
                i = H.T[i].suiv ;
            }
            if(H.T[i].val.str==e){
                H.T[i].val.nbocc++;
            }
            else{
                H.T[i].suiv = H.posLibre ;
                H.T[H.posLibre].val.str = e ;
                H.T[H.posLibre].val.nbocc=1;
                H.T[H.posLibre].occupe = true ;
            }
        }
    }
    else {
        H.T[i].val.str = e ;
        H.T[i].val.nbocc=1;
        H.T[i].occupe = true ;
    }
    while (H.posLibre >= 0 and H.T[H.posLibre].occupe){
        --H.posLibre ;
    }
}

int totalrempli(tabHachage H,int debut,int fin){
    int i=0;
    for(int i=debut;i<fin;i++){
        if(H.T[i].occupe==true){
            i++;
        }
    }
    return i;
}

int taillechaine(tabHachage T,alveole A){
    if(A.suiv>=0){
        return 1+taillechaine(T,T.T[A.suiv]);
    }
    return 1;
}

int plusgrandpaquet(tabHachage T){
    int nb=0;
    for(int i=0;i<T.m;i++){
        if(taillechaine(T,T.T[i])>nb){
            nb=taillechaine(T,T.T[i]);
        }
    }
    return nb;
}

void afficher(tabHachage H,int taille){
    for(int i=0;i<taille;i++){
        if(H.T[i].occupe==true){
            std::cout<<'['<<i<<']'<<H.T[i].val.str<<" "<<H.T[i].val.nbocc<<" ";
        }
    }
    std::cout<<"Facteur de remplissage de la zone primaire : "<<totalrempli(H,0,taille*85/100)/(taille*85/100)<<std::endl;
    std::cout<<"Facteur de remplissage de la zone de reserve : "<<totalrempli(H,taille*85/100,(taille*85/100)+(taille*15/100))/(taille*15/100)<<std::endl;
    std::cout<<"Facteur de remplissagetotal : "<<totalrempli(H,0,taille)/taille<<std::endl;
    std::cout<<"Taille du plus grand paquet : "<<plusgrandpaquet(H)<<std::endl;
    std::cout<<std::endl;
}

void lireFichier(std::string NomFichier,tabHachage &T){
    std::ifstream fic;
    fic.open(NomFichier);
    if(!fic.is_open()){
        std::cout<<"Fichier Non Ouvert"<<std::endl;
    }
    else{
        std::string str;
        while(fic.good()){
            fic>>str;
            ajout(str,T);
        }
    }
}

int retourne(tabHachage T,std::string str){
    int i=h(str,T.m);
    while(T.T[i].val.str!=str && T.T[i].suiv >= 0){
        i=T.T[i].suiv;
    }
    if(T.T[i].val.str!=str){
        return 0;
    }
    return T.T[i].val.nbocc;
}

int main(){
    tabHachage T;
    int taille=5000;
    initialiser(T,taille);
    lireFichier("bouledesuif.txt",T);
    afficher(T,taille);
    std::cout<<retourne(T,"tandis")<<std::endl;
    return 0;
}
