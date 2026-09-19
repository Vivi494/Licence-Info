#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <cstdlib>
#include <fstream>
/*exo 1.2
void MesTri (float &a,float &b,float &c)
{
    std::cout<<"Longueurs 3 cotes ?";std::cin>>a>>b>>c;
}

bool TriVal (float a,float b,float c)
{
    bool val=true;
    if (a<0 or b<0 or c<0)return false;
    if (a+b<c)val=false;
    if (a+c<b)val=false;
    if (c+b<a)val=false;
    return val;
}

float per (float a,float b,float c)
{
    return a+b+c;
}

float aire (float a,float b,float c)
{
    int s=(a+b+c)/2;
    int aire = sqrt(s*(s-a)*(s-b)*(s-c));;
    return aire;
}

bool equi(float a,float b,float c)
{
    if (a==b and a==c)return true;
    return false;
}

bool iso(float a,float b,float c)
{
    if (a==b)return true;
    if (a==c)return true;
    if (b==c)return true;
    return false;
}

bool rec(float a,float b,float c)
{
    if (a*a==b*b+c*c)return true;
    if (b*b==a*a+c*c)return true;
    if (c*c==b*b+a*a)return true;
    return false;
}

bool plat(float a,float b,float c)
{
    if (a+b==c)return true;
    if (a+c==b)return true;
    if (c+b==a)return true;
    return false;
}

std::string nature (float a,float b,float c)
{
    std::string nature="triangle";
    if (rec(a,b,c)==true)nature=nature+" rectangle";
    if (equi(a,b,c)==true)nature=nature+" equilateral";
    else (iso(a,b,c)==true)nature=nature+" isocele";
    if (plat(a,b,c)==true)nature=nature+" plat";
    return nature;
}

int main()
{
    float a,b,c;
    MesTri (a,b,c);
    std::cout<<"a="<<a<<" b="<<b<<" c="<<c;
    std::cout<<"\nTriangle valide ?"<<std::boolalpha<<TriVal (a,b,c)<<'\n';
    std::cout<<"Perimetre  : "<<per (a,b,c)<<'\n';
    std::cout<<"Aire : "<<aire (a,b,c)<<'\n';
    std::cout<<"Equilateral : "<<equi (a,b,c)<<'\n';
    std::cout<<"Isocele : "<<iso (a,b,c)<<'\n';
    std::cout<<"Rectangle : "<<rec (a,b,c)<<'\n';
    std::cout<<"Plat : "<<plat (a,b,c)<<'\n';
    std::cout<<"Nature : "<<nature (a,b,c)<<'\n';
    return 0;
}*/

/*exo 2.3
const int MAX=12;
using TabPrecipitations = std::array<int,MAX>;

void SaisieTab(TabPrecipitations &TP)
{
    int a;
    for (int i=0;i<MAX;i++)
    {
        std::cout<<"Température ? ";std::cin>>a;
        TP[i]=a;
    }
}

int min(TabPrecipitations TP)
{
    int min=TP[0];
    for (int i=1;i<MAX;i++)
    {
        if (TP[i]<min)min=TP[i];
    }
    return min;
}

int max(TabPrecipitations TP)
{
    int max=TP[0];
    for (int i=1;i<MAX;i++)
    {
        if (TP[i]>max)max=TP[i];
    }
    return max;
}

int MinTotal(TabPrecipitations A,TabPrecipitations N,TabPrecipitations R)
{
    if (min(A)<min(N)){
        if (min(A)<min(R))return min(A);
    }
    if (min(N)<min(R))return min(N);
    return min(R);
}

int MaxTotal(TabPrecipitations A,TabPrecipitations N,TabPrecipitations R)
{
    if (max(A)>max(N)){
        if (max(A)<max(R))return max(A);
    }
    if (max(N)>max(R))return max(N);
    return max(R);
}

void AffichTab(TabPrecipitations &TP)
{
    for (int i=0;i<MAX;i++)
    {
        std::cout<<TP[i]<<' ';
    }
}

int main()
{
    TabPrecipitations A,N,R;
    SaisieTab(A);AffichTab(A);
    std::cout<<'\n';
    SaisieTab(N);AffichTab(N);
    std::cout<<'\n';
    SaisieTab(R);AffichTab(R);
    std::cout<<'\n'<<min(A);
    std::cout<<'\n'<<max(A);
    std::cout<<'\n'<<min(N);
    std::cout<<'\n'<<max(N);
    std::cout<<'\n'<<min(R);
    std::cout<<'\n'<<max(R)<<'\n';
    std::cout<<MinTotal(A,N,R)<<'\n';
    std::cout<<MaxTotal(A,N,R)<<'\n';
}*/

/*exo 2.6

const int M=3;
const int TAILLE =2*M+1;
using Tab=std::array<char,M>;

void afficher (const int TAILLE,Tab SM)
{
    for (int i=0;i<TAILLE;i++){}
}



int main()
{
    
}*/

/*exo 3.2

std::string copie (std::string s,int i,int j)
{
    std::string ret="";
    for (int b=0;b<j;b++)
    {
        ret=ret+s[i+b];
    }
    return ret;
}

void supprime(std::string &s,int i,int j)
{
    std::string s3="";
    for (int b=0;b<i;b++)
    {
        s3+=s[b];
    }
    for (unsigned int c=i+j;c<s.length();c++)
    {
        s3+=s[c];
    }
    s=s3;
}

void insere(std::string s1,std::string &s2,int i)
{
    std::string s3="",s4="";
    for (int b=0;b<i;b++)
    {
        s3+=s2[b];
    }
    
    for (unsigned int d=i;d<s2.length();d++)
    {s4+=s2[d];}
    s2=s3+s1+s4;
}

int position (std::string s1,std::string s2)
{
    int taille=s1.length();
    for (unsigned int i=0;i<s2.length();i++)
    {
        if (copie(s2,i,taille)==s1)return i;
    }
    return -1;
}

int main()
{
    std::string s,s1,s2;int i,j;
    std::cout<<"Chaîne de caractères ? ";std::getline(std::cin,s);
    std::cout<<"i et j ? ";std::cin>>i>>j;
    std::cin.ignore();
    std::cout<<"Chaîne de caractères ? ";std::getline(std::cin,s1);
    std::cout<<"Chaîne de caractères ? ";std::getline(std::cin,s2);
    std::cout<<copie(s,i,j)<<'\n';
    supprime(s,i,j);
    std::cout<<s<<'\n';
    insere(s1,s2,i);
    std::cout<<s2<<'\n';
    std::cout<<position(s1,s2)<<'\n';
    return 0;
}*/

/*exo 4.2
const unsigned int taillemax=10;
using ligne = std::array <unsigned int,taillemax>;
using matrice = std::array <ligne,taillemax>;

void bat (ligne &b,unsigned int &nbb)
{
    do{
        std::cout<<"Nombre de bateaux : ";std::cin>>nbb;
        if(nbb<2){std::cout<<"plus que 2 stp\n";}
        if(nbb>10){std::cout<<"pas plus que 10 stp\n";}
    }while(nbb<2 or nbb>10);
    
    for (unsigned int i=1;i<=nbb;i++){
        do{std::cout<<"Longueur du bateau no."<<i<<" : ";std::cin>>b[i];
            if(b[i]<2){std::cout<<"plus grand que 2 stp\n";}
            if(b[i]>10){std::cout<<"pas plus que 10 stp\n";}
        }while(b[i]<2 or b[i]>10);
    }
}

void place (matrice &grille,ligne b,unsigned int nbb)
{
    for (unsigned int i=1;i<=nbb;i++){
        bool placable;unsigned int xplacable,yplacable,sens;
        do{ sens=rand()%2;
            placable=true;
            int x=rand()%taillemax;
            int y=rand()%taillemax;
            if (sens==0){
                if (grille[x][y]!=0){placable=false;}
                for (unsigned int j=1;j<b[i];j++){
                    if (grille[x][y+j]!=0 or y+j>=10){placable=false;}
                }
            }
            else {
                if (grille[x][y]!=0){placable=false;}
                for (unsigned int j=1;j<b[i];j++){
                    if (grille[x+j][y]!=0 or x+j>=10){placable=false;}
                }
            }
        xplacable=x;
        yplacable=y;
        }while (placable==false);
        if (sens==0){
            for (unsigned int k=0;k<b[i];k++){
                grille[xplacable][yplacable+k]=i;
            }
        }
        else {
            for (unsigned int k=0;k<b[i];k++){
                grille[xplacable+k][yplacable]=i;}
        }
    }
}

void affiche (matrice grille)
{
    std::cout<<"Grille :"<<'\n';
    for (unsigned int i=0;i<taillemax;i++){
        for (unsigned int j=0;j<taillemax;j++){std::cout<<grille[j][i]<<' ';}
        std::cout<<'\n';
    }
}

int main()
{
    srand(time(nullptr));
    matrice grille;unsigned int nbb;
    for (unsigned int i=0;i<taillemax;i++){
        for (unsigned int j=0;j<taillemax;j++){
            grille[i][j]=0;
        }
    }
    ligne b;bat(b,nbb);place(grille,b,nbb);affiche(grille);
    return 0;
}*/

/*exo 4.3

const int TAILLE=4;
using ligne = std::array<char,TAILLE>;
using matrice = std::array<ligne,TAILLE>;

void grille (matrice &g)
{
    for (int i=0;i<TAILLE;i++)
    {
        for (int j=0;j<TAILLE;j++)
        {
            g[i][j]=' ';
        }
    }
}

void nom(std::string &joueur1,std::string &joueur2)
{
    std::cout<<"nom joueur1 ? ";std::getline(std::cin,joueur1);
    std::cout<<"nom joueur2 ? ";std::getline(std::cin,joueur2);
}

void change(char &joueur)
{
    if (joueur=='X'){joueur='O';}
    else {joueur='X';}
}

void aff(matrice g)
{
    for (int i=0;i<TAILLE;i++)
    {
        for (int j=0;j<TAILLE;j++)
        {
            if (j<TAILLE-1){std::cout<<g[i][j]<<'|';}
            else {std::cout<<g[i][j];}
        }
        std::cout<<'\n';
        if (i<TAILLE-1){
            for (int g=0;g<TAILLE;g++)
            {
                if (g<TAILLE-1){std::cout<<"-|";}
                else {std::cout<<'-';}
            }
            std::cout<<'\n';
        }
    }
}

void jouer(char joueur,matrice &g)
{
    int x,y;
    std::cout<<"Case ? (ex: 0 0) ";std::cin>>x>>y;
    if (g[x][y]==' '){g[x][y]=joueur;}
}

void test(bool &Fin,char joueur,matrice &g)
{
    int ok;
    for (int i=0;i<TAILLE;i++)
    {
        ok=1;
        for (int j=0;j<TAILLE;j++)
        {
            if(g[i][j]!=joueur){ok=0;}}
        if (ok==1){Fin=1;}}
    for (int i=0;i<TAILLE;i++)
    {
        ok=1;
        for (int j=0;j<TAILLE;j++)
        {
            if(g[j][i]!=joueur){ok=0;}}
        if (ok==1){Fin=1;}}
    
    ok=1;
    for (int i=0;i<TAILLE;i++)
    {
        
        if(g[i][i]!=joueur){ok=0;}}
    if (ok==1){Fin=1;}
    ok=1
    for (int i=0;i<TAILLE;i++)
    {
        if(g[TAILLE-i][i]!=joueur){ok=0;}}
    if (ok==1){Fin=1;}
}

void nul (bool &egal,bool &Fin,matrice g)
{
    egal=1;
    for (int i=0;i<TAILLE;i++)
    {
        for (int j=0;j<TAILLE;j++)
        {
            if(g[i][j]==' '){egal=0;}}}
    if (egal==1){Fin=1;}
}

int main()
{
    matrice g;std::string joueur1,joueur2;char joueur='O';bool Fin=0,egal=0;
    nom(joueur1,joueur2);
    grille(g);
    aff(g);
    do{
        change(joueur);
        if (joueur=='X'){std::cout<<joueur1<<" : ";}
        else {std::cout<<joueur2<<" : ";}
        jouer(joueur,g);
        test(Fin,joueur,g);
        aff(g);
        nul(egal,Fin,g);
    }while(Fin==0);
    if(egal==0){std::cout<<"Le joueur ayant les "<<joueur<<" a gagné!!!\n";}
    else std::cout<<"égalité\n";
}*/

/*exo 5.1

std::string ident (std::string f1,std::string f2)
{
    std::ifstream flux1,flux2;
    flux1.open(f1);
    flux2.open(f2);
    std::string s1,s2;
    std::getline(flux1,s1);
    std::getline(flux2,s2);
    if(!flux1 or !flux2)
{
    return "Non applicable\n";
}
    while (flux1.good() and flux2.good())
    {
        if(s1!=s2)
        {
            return "Non\n";
        }
    std::getline(flux1,s1);
    std::getline(flux2,s2);
    }
    return "Oui\n";
}

std::string identGet (std::string f1,std::string f2)
{
    std::ifstream flux1,flux2;
    flux1.open(f1);
    flux2.open(f2);
    char s1,s2;
    flux1.get(s1);
    flux2.get(s2);
    if(!flux1 or !flux2)
    {
        return "Non applicable\n";
    }
    while (flux1.good() and flux2.good())
    {
        if(s1!=s2)
        {
            return "Non\n";
        }
        flux1.get(s1);
        flux2.get(s2);
    }
    return "Oui\n";
}

std::string identOpe (std::string f1,std::string f2)    //impossible car ne compte pas les espaces
{
    std::ifstream flux1,flux2;
    flux1.open(f1);
    flux2.open(f2);
    char s1,s2;
    flux1>>s1;
    flux2>>s2;
    if(!flux1 or !flux2)
    {
        return "Non applicable\n";
    }
    while (flux1.good() and flux2.good())
    {
        if(s1!=s2)
        {
            return "Non\n";
        }
        flux1>>s1;
        flux2>>s2;
    }
    return "Oui\n";
}

int main()
{
    std::cout<<ident("fic1.txt","fic3.txt");
    std::cout<<identGet("fic1.txt","fic3.txt");
    std::cout<<identOpe("fic1.txt","fic3.txt");
    return 0;
}*/

//Algo 2

/*exo 1.5
void affiche (unsigned int n)
{
    if (n>0)
    {
        std::cout<<"Bonjour ";
        affiche(n-1);
    }
    else std::cout<<'\n';
}

unsigned int carrés (unsigned int n,unsigned int &somme)
{
    if(n>0)
    {
        carrés(n-1,somme);
        somme+=n*n;
    }
    return somme;
}

int main()
{
    unsigned int n,somme=0;
    std::cout<<"n? ";std::cin>>n;
    affiche(n);
    std::cout<<"somme des carrés : "<<carrés(n,somme)<<'\n';
}*/

/*exo 1.6

int diviseur (int d,int n)
{
    if (d+1<n+1)
    {
        if (n%(d+1)==0)
        {
            return d+1;
        }
        diviseur(d+1,n);
    }
}

bool est_premier (int n)
{
    if (diviseur(1,n)==n)return true;
    else return false;
}

void affiche_premiers (int n)
{
    if (n>1)
    {
        affiche_premiers(n-1);
        if (diviseur(1,n)==n)std::cout<<n<<' ';
    }
}

int main()
{
    int  d,n;
    std::cout<<"n et d ? ";std::cin>>n>>d;
    std::cout<<"plus petit diviseur : "<<diviseur(d,n)<<'\n';
    std::cout<<n<<"est premier ? "<<est_premier(n)<<'\n';
    std::cout<<"nombres premiers : ";affiche_premiers(n);
}*/
