#include <iostream>
#include <string>
#include <array>
#include <fstream>

struct occMot {
    std::string mot;
    int nbocc;
};

struct maillon {
    occMot M;
    maillon * suiv;
};

using listeMots=maillon *;

using tableau=std::array<std::string,10000>;

struct tabMots{
    tableau T;
    unsigned int taille;
};

//17.
struct occLettre {
    char lettre;
    int nbocc;
};

using tabLettres=std::array<occLettre,26>;

//I.
//1.
void initialise (listeMots & L)
{
    L=nullptr;
}

//2.
void ajouteDebut (std::string mot,listeMots & L)
{
    listeMots p;
    p=new maillon;
    p->M.mot=mot;
    p->M.nbocc=1;
    p->suiv=L;
    L=p;
}

//3.
void ajoute (std::string mot, listeMots & L)
{
    if ((L==nullptr) or (mot<L->M.mot))
    {
        ajouteDebut (mot,L);
    }
    else
    {
        if (mot>L->M.mot)
        {
            ajoute(mot,L->suiv);
        }
        else
        {
            L->M.nbocc++;
        }
    }
}

//4.
void affiche (listeMots L)
{
    if (L!=nullptr)
    {
        std::cout<<L->M.mot<<'('<<L->M.nbocc<<") ";
        affiche(L->suiv);
    }
}

//5.
int taille (listeMots L)
{
    if(L!=nullptr)
    {
        return taille(L->suiv)+1;
    }
    else return 0;
}

//6.
int nombreMots (listeMots L)
{
    if(L!=nullptr)
    {
        return L->M.nbocc+nombreMots(L->suiv);
    }
    else return 0;
}

//7.

bool triee (listeMots L)
{
    for(int i=0;i<taille(L);i++)
    {
        if(L->M.mot>L->suiv->M.mot){return false;}
    }
    return true;
}

bool occ1 (listeMots L)
{
    for(int i=0;i<taille(L);i++)
    {
        if(L->M.nbocc!=1){return false;}
    }
    return true;
}

bool estValide (listeMots L)
{
    if(L==nullptr){return true;}
    if(taille(L)!=nombreMots(L)){return false;}
    if(triee(L)==false){return false;}
    if(occ1(L)==false){return false;}
    return true;
}

//8.
unsigned int plusLong (listeMots L)
{
    if(L==nullptr){return 0;}
    unsigned int tailleMax=plusLong(L->suiv);
    if(L->M.mot.length()<tailleMax){return tailleMax;}
    else return L->M.mot.length();
}

//9.
void afficheLongueur (listeMots L,unsigned int longueur)
{
    if(L!=nullptr)
    {
        if(L->M.mot.length()==longueur){std::cout<<L->M.mot<<' ';}
        afficheLongueur(L->suiv,longueur);
    }
}

//10.
void afficheTriLongueur (listeMots L)
{
    for(unsigned int i=1;i<plusLong(L)+1;i++)
    {
        afficheLongueur(L,i);
    }
}

//11.
void saisit (listeMots & L)
{
    std::string mot;
    std::cout<<"saisir un ensemble de mots (terminer par /)";
    std::getline(std::cin,mot);
    if (mot!="/")
    {
        ajoute(mot,L);
        saisit(L);
    }
}

//12.
void construit (listeMots & L, std::string nomFichier)
{
    std::string mot;
    std::ifstream open(nomFichier);
    while(open>>mot)
    {
        ajoute(mot,L);
    }
}

//13.
void remplit (tabMots & T, listeMots L)
{
    while(L!=nullptr)
    {
        T.T[T.taille]=L->M.mot;
        T.taille++;
        L=L->suiv;
    }
}

//14.
void affiche (tabMots & T)
{
    for(unsigned int i=0;i<T.taille;i++)
    {
        std::cout<<T.T[i]<<' ';
    }
}

//15.
bool appartient (std::string mot, tabMots T,unsigned int debut,unsigned int fin)
{
    std::cout<<"debut="<<debut<<" fin="<<fin<<std::endl;
    if(fin<debut)
    {
        return false;
    }
    unsigned int milieu=(fin-debut)/2+debut;
    std::cout << "milieu=" << milieu << " ŧ(milieu)=" << T.T[milieu] << std::endl;
    if((fin==debut) and (mot!=T.T[milieu]))
    {
        return false;
    }
    if(mot==T.T[milieu])
    {
        return true;
    }
    if(mot<T.T[milieu])
    {
        return appartient(mot,T,debut,milieu-1);
    }
    else
    {
        return appartient(mot,T,milieu+1,fin);
    }
}

bool appartient (std::string mot, tabMots T)
{
    std::cout << "appartient(" << mot << ")" << std::endl;
    return appartient(mot,T,0,T.taille-1);
}

//18.
void initialise (tabLettres & T)
{
    char c='a';
    for (int i=0;i<26;i++)
    {
        T[i].lettre=c;
        T[i].nbocc=0;
        c++;
    }
}

//19.
void ajoute (char lettre, tabLettres & T)
{
    for(int i=0;i<26;i++)
    {
        if(lettre==T[i].lettre)
        {
            T[i].nbocc++;
        }
    }
}

//20.
void comptabilise (tabLettres & T, std::string mot)
{
    for(unsigned int i=0;i<mot.length();i++)
    {
        ajoute(mot[i],T);
    }
}

void comptabilise (tabLettres & T, listeMots L)
{
    while(L!=nullptr)
    {
        for(int i=0;i<L->M.nbocc;i++)
        {
            comptabilise(T,L->M.mot);
        }
        comptabilise(T,L->suiv);
    }
}

//21.
int plusnombre (tabLettres & T,int debut)
{
    int tmp=debut;
    for(int i=debut+1;i<26;i++)
    {
        if(T[i].nbocc>T[tmp].nbocc)
        {
            tmp=i;
        }
    }
    return tmp;
}

void trie (tabLettres & T)
{
    occLettre tmp;
    for(int i=0;i<26;i++)
    {
        int a=plusnombre(T,i);
        tmp.lettre=T[i].lettre;
        tmp.nbocc=T[i].nbocc;
        T[i].lettre=T[a].lettre;
        T[i].nbocc=T[a].nbocc;
        T[a].lettre=tmp.lettre;
        T[a].lettre=tmp.nbocc;
    }
}

//22.
void affiche (tabLettres T)
{
    for(int i=0;i<26;i++)
    {
        std::cout<<T[i].lettre<<'('<<T[i].nbocc<<") ";
    }
    std::cout<<std::endl;
}

//16.
int main() {
    tabMots Tab;
    Tab.taille=0;
    listeMots L;
    initialise(L);
    construit(L,"bouledesuif.txt");
    affiche(L);
    std::cout<<"donner un mot : ";
    std::string mot;
    std::getline(std::cin,mot);
    remplit(Tab,L);
    std::cout << "mot=" << mot << std::endl;
    if(appartient(mot,Tab)==true)
    {
        std::cout<<"Le mot appartient à la liste.";
    }
    else
    {
        std::cout<<"Le mot n'appartient pas à la liste.";
    }
    std::cout<<std::endl;
//23.
    tabLettres T;
    initialise(T);
    comptabilise(T,L);
    trie(T);
    affiche(T);
    return 0;
}
