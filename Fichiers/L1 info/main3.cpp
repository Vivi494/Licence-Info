#include <iostream>
#include <array>
#include <cstdlib>
/*exercice 1.2
struct personne
{
    std::string nom;
    std::string prenom;
    std::string tel;
};
    
struct maillon
{
    personne val;
    maillon * suiv;
};
    
using repertoire = maillon *;

void initialiserRepertoire (repertoire &R)
{
    R=nullptr
}

void ajouterEnTete (std::string nom, std::string prenom, std::string tel, repertoire &R)
{
    repertoire p = new maillon;
    p->val.nom=nom;
    p->val.prenom=prenom;
    p->val.tel=tel;
    p->suiv=R;
    R=p;
    
}

void ajouterEnQueue (std::string nom, std::string prenom, std::string tel, repertoire & R)
{
    if(R==nullptr)
    {
        R=new maillon;
        R->val.nom=nom;
        R->val.prenom=prenom;
        R->val.tel=tel;
    }
    else
    {
        ajouterEnQueue(nom,prenom,tel,R->suiv);
    }
}

void afficherPersonne (personne P)
{
    std::cout<<'['<<P.nom<<','<<P.prenom<<','<<P.tel<<"]\n";
}

void afficherRepertoire (repertoire R)
{
    if(R!=nullptr)
    {
        std::cout<<'['<<P.nom<<','<<P.prenom<<','<<P.tel<<"]\n";
        afficherRepertoire(R->suiv);
    }
}

std::string telephone (std::string nom, std::string prenom, repertoire R)
{
    if(R!=nullptr)
    {
        if(R->val.nom==nom and R->val.prenom==prenom)
        {
        return R->val.tel;
        }
        telephone(nom,prenom,R->suiv);
    }
    return "";
}

int rechercherPosition (std::string nom, std::string prenom, repertoire R)
{
    int pos=0;
    while(R!=nullptr)
    {
        pos++;
        if(R->val.nom==nom and R->val.prenom==prenom)
        {
            return pos;
        }
        
    }
    return 0;
}

void ajouter (int position, std::string nom, std::string prenom, std::string tel, repertoire & R)
{
    if(R!=nullptr)
    {
        if(position!=1)
        {
            ajouter(position-1,nom,prenom,tel,R->suiv);
        }
        else
        {
            if(position==1)
            {
                ajouterEnTete(nom,prenom,tel,R);
            }
        }
    }
    else
    {
        ajouterEnTete(nom,prenom,tel,R);
    }
}

void supprimer (int position, repertoire & R)
{
    
}

void supprimer (std::string nom, repertoire & R)
{
    
}

int main()
{
    initialiserRepertoire(R);
}
*/

/*exercice 1.4
struct monome
{
    float a;
    int b;
};

struct polynome
{
    monome m;
    polynome * suiv;
};

void saisie(polynome &P,int n)
{
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            std::cout<<"entrez a et b : ";
            std::cin>>P.m.a>>P.m.b;
        }
        else
        {
            monome M=new monome;
            std::cout<<"entrez a et b : ";
            std::cin>>M.a>>M.b;
            polynome p=new polynome;
            p.m=M;
            P[i].suiv=p;
        }
    }
}

void affiche(monome M)
{
    std::cout<<M.a<<M.b;
}

void afficheP(polynome P)
{
    if(P!=nullptr)
    {
        affiche(P.m);
        afficheP(P.suiv);
    }
}

int main()
{
    polynome P;
    int n;
    std::cout<<"n? ";std::cin>>n;
    saisie(P,n);
    afficheP(P);
}
*/

//exercice 2.1

/*
int main()
{
    const unsigned int N=10;
    int T[10]={-1,-1,0,152,186,856,486,-3};
    int Somme=T[0];
    int Imax=0;
    int Imin=0;
    for (int i=1;i<N;i++)
    {
        Somme=Somme+T[i];
        if(T[i]>T[Imax])
        {
            Imax=i;
        }
        else 
        {
            if(T[i]<T[Imin])
            {
                Imin=i;
            }
        }
    }
    std::cout<<"Somme : "<<Somme<<", T[Imin] : "<<T[Imin]<<", T[Imax] : "<<T[Imax]<<'\n';
    return 0;
}
*/
/*
int main()
{
    const int N=10;
    int A[10][10]={ {-1,-1,0,152,186,856,486,-3},
                    {-1,-1,0,152,186,856,486,-3},
                    {-1,-1,0,152,186,856,486,-3},
                    {-1,-1,0,152,186,856,486,-3},
                    {-1,-1,0,152,186,856,486,-3},
                    {-1,-1,0,152,186,856,486,-3},
                    {-1,-1,0,152,186,856,486,-3},
                    {-1,-1,0,152,186,856,486,-3},
                    {-1,-1,0,152,186,856,486,-3},
                    {-1,-1,0,152,186,856,486,-3}    };
    for(int i=0;i<N;i++)
    {
        A[i][i]=0;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;i<N;i++)
        {
            if(A[i][j]<0)
            {
                A[i][j]=0;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
             std::cout<<A[i][j]<<' ';
        }
        std::cout<<'\n';
    }
    return 0;
}
*/


/*exercice 2.3

int main()
{
    
    return 0;
}
*/

/*exercice 2.5
const unsigned int N=10;
using tableau = std::array<int,N>;
void randomize (tableau &T)
{
    for (unsigned int i=0;i<N;i++)
    {
        T[i]=rand()%100;
    }
}

void affichage(tableau T)
{
    for (unsigned int i=0;i<N;i++)
    {
        std::cout<<T[i]<<' ';
    }
    std::cout<<'\n';
}

unsigned int indice_max(tableau T,unsigned int n)
{
    unsigned int indicemax=0;
    int max=T[0];
    for (unsigned int i=1;i<n;i++)
    {
        if(T[i]>max)
        {
            max=T[i];
            indicemax=i;
        }
    }
    return indicemax;
}

void echange(tableau &T,unsigned int indice1,unsigned int indice2)
{
    int i;
    i=T[indice1];
    T[indice1]=T[indice2];
    T[indice2]=i;
}

void tri_selec (tableau &T)
{
    for (unsigned int i=0;i<N;i++)
    {
        echange(T,indice_max(T,N-i),N-i);
    }
}

void tri_bulle(tableau &T)
{
    for (unsigned int i=1;i<N;i++)
    {
        for (int j=i;j>0;j--)
        {
            if(T[j]<T[j-1])
            {
                echange(T,j,j-1);
            }
        }
    }
}

void inser(tableau &T,int x,unsigned int j)
{
    while ((j > 0) and (T[j-1] > x))
		{
			T[j] = T[j-1];
			--j;
		}
		T[j] = x;
}

void tri_inser(tableau &T)
{
    for (unsigned int i = 1; i < N; ++i)
	{
        inser(T,T[i],i);
	}
}

int main()
{
    tableau T;
    randomize(T);
    affichage(T);
    tri_inser(T);
    affichage(T);
    return 0;
}
*/

//exercice 2.6

const unsigned int N=10;
using tableau = std::array<int,N>;
void randomize (tableau &T)
{
    for (unsigned int i=0;i<N;i++)
    {
        T[i]=rand()%100;
    }
}

void affichage(tableau T)
{
    for (unsigned int i=0;i<N;i++)
    {
        std::cout<<T[i]<<' ';
    }
    std::cout<<'\n';
}

void echange(tableau &T,unsigned int indice1,unsigned int indice2)
{
    int i;
    i=T[indice1];
    T[indice1]=T[indice2];
    T[indice2]=i;
}

int partitionnement (tableau &T, int d, int f)
{
	int p = T[f];
	int j = d; 
	for (int i = d; i < f; ++i)
		if (T[i] < p) 
		{
			echange(T,i,j);
			++j;
		}
	echange(T,f,j);
	return j;
}


void tri_rapide (tableau &T, int d, int f)
{
	if (f-d > 0) 	
	{
		int k = partitionnement(T,d,f);
		tri_rapide(T,d,k-1);
		tri_rapide(T,k+1,f);
	}
}

void tri_rapide (tableau &T, int n)
{
	tri_rapide(T,0,n-1);
}

int main()
{
    tableau T;
    randomize(T);
    affichage(T);
    tri_rapide(T,N);
    affichage(T);
    return 0;
}
