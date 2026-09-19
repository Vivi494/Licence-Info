#include<iostream>
#include<fstream>

struct Noeud{
    std::string str;
    Noeud* droit;
    Noeud* gauche;
    Noeud* pere;
    file livraison;
};

using ArbreBinaire=Noeud*;

struct maillon{
    char carac;
    maillon* suiv;
}

using file=maillon*;

void init_file(file A){
    A=nullptr;
}

bool est_vide(file A){
    if(A==nullptr)return true;
    return false;
}

char consulter(file A){
    if(A!=nullptr)return A->suiv->carac;
}

void ajouter(file & A,char car){
    m=new maillon;
    m->carac=car;
    if(A==nullptr){
    m->suiv=m;
    }
    else{
        m->suiv=A->suiv;
        A->suiv=m;
    }
    A=m;
}

void retirer(file & A){
    if(A!=nullptr){
        if(A->suiv==A){
            delete A;
            A=nullptr;
        }
        else{
            file tmp=A->suiv;
            A->suiv=A->suiv->suiv;
            delete tmp;
        }
    }
}

void affiche_file(file A){
    if(A!=nullptr){
        file tmp=A->suiv;
        std::cout<<A->carac<<'\n';
        while(tmp!=A){
            std::cout<<tmp->carac;
            tmp=tmp->suiv;
        }
    }
}

int* Init_tab_int(int taille){
    if(taille<=0){
        return nullptr;
    }
    else{
        int* T;
        T=new int [taille];
        for(int i=0;i<taille;i++){T[i]=0;}
    return T;
    }
}

std::string* Init_tab_str(int taille){
    if(taille<=0){
        return nullptr;
    }
    else{
        std::string* T;
        T=new std::string [taille];
        for(int i=0;i<taille;i++){T[i]="";}
    return T;
    }
}

struct ArbreTab{
    int taille;
    int racine;
    std::string* etiquettes;
    int* gauche;
    int* droite;
    int* pere;
};

void fairepere(ArbreTab & A,int I){

    if(A.droite[I]!=0){
        A.pere[A.droite[I]]=I;
        fairepere(A,A.droite[I]);
    }
    if(A.gauche[I]!=0){
        A.pere[A.gauche[I]]=I;
        fairepere(A,A.gauche[I]);
    }
}

ArbreTab construire(std::string fichier){
    ArbreTab A;
    std::ifstream fic(fichier);
    if(not fic.eof()){
        fic >> A.taille;
        if(!fic.good()){
            std::cout<<"Problème de Lecture Taille";
            return A;
        }
        fic >> A.racine;
        if(!fic.good()){
            std::cout<<"Problème de Lecture Racine";
            return A;
        }
        A.etiquettes=Init_tab_str(A.taille+1);
        A.gauche=Init_tab_int(A.taille+1);
        A.droite=Init_tab_int(A.taille+1);
        A.pere=Init_tab_int(A.taille+1);
        for(int i=1;i<A.taille+1;i++){
            fic >> A.etiquettes[i];
            fic >> A.gauche[i];
            fic >> A.droite[i];
            if(!fic.good()){
                std::cout<<"Problème de Lecture E/G/D";
                return A;
            }
        }
        A.pere[A.racine]=0;
        fairepere(A,A.racine);
    }
    return A;
}

int prof(ArbreTab A,int indice){
    if(indice!=0){
        return prof(A,A.pere[indice])+1;
    }
    return 0;
}

std::string afficheN(ArbreTab A,int V){
    if(V!=0)return A.etiquettes[V];
    return "*";
}

void affiche(ArbreTab A,int racine){
    if(racine!=0){
        std::cout<<A.etiquettes[racine]<<' '<<afficheN(A,A.gauche[racine])<<' '<<afficheN(A,A.droite[racine])<<' '<<afficheN(A,A.pere[racine])<<' '<<prof(A,racine)<<'\n';
        affiche(A,A.gauche[racine]);
        affiche(A,A.droite[racine]);
    }
}

ArbreBinaire convert(ArbreTab A,int racine){
    ArbreBinaire AB=new Noeud;
    AB->pere=nullptr;
    AB->str=A.etiquettes[racine];
    init_file(AB->file);
    if(A.gauche[racine]!=0){
        AB->gauche=convert(A,A.gauche[racine]);
        AB->gauche->pere=AB;
    }
    else AB->gauche=nullptr;
    if(A.droite[racine]!=0){
        AB->droit=convert(A,A.droite[racine]);
        AB->droit->pere=AB;
    }
    else AB->droit=nullptr;
    return AB;
}

int ProfBin(ArbreBinaire A){
    if(A==nullptr)return 0;
    return ProfBin(A->pere)+1;
}

std::string AfficheN(ArbreBinaire A){
    if(A!=nullptr)return A->str;
    return "*";
}

void AfficheBin(ArbreBinaire A){
    if(A!=nullptr){
        std::cout<<A->str<<' '<<AfficheN(A->gauche)<<' '<<AfficheN(A->droit)<<' '<<AfficheN(A->pere)<<' '<<ProfBin(A)<<'\n';
        AfficheBin(A->gauche);
        AfficheBin(A->droit);
    }
}

bool racine(ArbreBinaire A){
    if(A->pere==nullptr)return true;
    return false;
}

bool feuille(ArbreBinaire A){
    if(A->droit==nullptr and A->gauche==nullptr)return true;
    return false;
}

bool noeudint(ArbreBinaire A){
    if(not(racine(A)) and not(feuille(A)))return true;
    return false;
}

bool filsdroit(A){
    if(A->pere->droit==A)return true;
    return false;
}

bool filsgauche(A){
    if(A->pere->gauche==A)return true;
    return false;
}

int nbfeuille(ArbreBinaire A){
    if(feuille(A))return 1;
    else return feuille(A->droit)+feuille(A->gauche);
}

void affiche_etiquettes(A){
    if(feuille(A))std::cout<<A->str;
    else{
        affiche_etiquettes(A->gauche);
        affiche_etiquettes(A->droit);
    }
}

int hauteur(A){
    if(A==nullptr){return -1;}
    if(feuille(A))return 0;
    if(hauteur(A->droit<A->gauche))return hauteur(A->gauche)+1;
    return hauteur(A->droit)+1;
}

ArbreBinaire srcheti(ArbreBinaire A,std::string etiquette){
    if(A->str==etiquette)return A;
    if(srcheti(A->gauche,etiquette)!=nullptr)return srcheti(A->gauche,etiquette);
    if(srcheti(A->droit,etiquette)!=nullptr)return srcheti(A->droit,etiquette);
    return nullptr;
}

void supprN(ArbreBinaire & A){
    delete A;
    A=nullptr;
}

void suppr(ArbreBinaire & A){
    if(A!=nullptr){
        suppr(A->gauche);
        suppr(A->droit);
        supprN(A);
    }
}

void livrer1(ArbreBinaire A){
    if(A->pere!=nullptr){
        if(A->pere->gauche==A){
            ajouter(A->pere>file,'G');
        }
        else{
            ajouter(A->pere->file,'D');
        }
        livrer1(A->pere);
    }
}

void livrer2(ArbreBinaire A){
    std::cout<<A->str;
    if(A->file=='G'){
        std::cout<<"=>";
        retirer(A->file);
        livrer2(A->gauche);
    }
    else if(A->file=='D'){
        std::cout<<"=>";
        retirer(A->file);
        livrer2(A->droit);
    }
}

void livrer(ArbreBinaire A){
    std::string comm;
    std::cout<<'Qui fait la commande ?(ne rien mettre pour finir) ';std::cin>>comm;
    while(comm!=""){
        livrer1(srcheti(A,comm));
        std::cout<<'Qui fait la commande ?(ne rien mettre pour finir) ';std::cin>>comm;
    }
    while(A->file!=nullptr){
        livrer2(A);
    }
}

void livrer_figure3(ArbreBinaire A){
    livrer1("magasin_1");
    livrer1("magasin_5");
    livrer1("magasin_1");
    livrer1("magasin_4");
    livrer1("magasin_4");
    livrer1("magasin_2");
    livrer1("magasin_3");
    livrer1("magasin_5");
    while(A->file!=nullptr){
        livrer2(A);
    }
}

void affiche_etat(ArbreBinaire A){
    if(A->file!=nullptr){
        file tmp=A->file;
        while(tmp!=nullptr){
            std::cout<<file->carac<<' ';
            tmp=tmp->suiv;
        }
        std::cout<<'\n';
        affiche_etat(A->gauche);
        std::cout<<'\n';
        affiche_etat(A->droit);
    }
}

int main(){
    ArbreTab A=construire("usine1.txt");
    affiche(A,A.racine);
    ArbreBinaire AB=convert(A,A.racine);
    AfficheBin(AB);
    return 0;
}
