#include <iostream>
#include <cstdlib>
#include <chrono>

// ------------------ GESTION CHRONOS ET GRAINE -----------------------
auto chrono = std::chrono::system_clock::now();
void init_chrono ()
{
	chrono = std::chrono::system_clock::now();
}
float etat_chrono ()
{
	return (0.0 + std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - chrono).count()) / 1000;
}
unsigned random_seed ()
{
	return chrono.time_since_epoch().count();
}

// --------------------------------------------------------------------
int * genere (int n)
{
	int * T = new int [n];
	for (int i = 0; i < n; ++i)
		T[i] = rand();
	return T;
}

void affiche (int * T, int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << T[i] << " ";
	std::cout << std::endl;
}

bool verif_tri (int * T, int n)
{
	for (int i = 0; i < n-1; ++i)
		if (T[i] > T[i+1])
			return false;
	return true;
}

// --------------------------------------------------------------------

void echange (int & x, int & y)
{
	int z = x; x = y; y = z;
}

// ***** Tri par sélection *****
void tri_selection (int * T, int n)
{
	for (int i = n-1; i > 0; --i)
	{
		int p = 0;
		for (int j = 1; j <= i; ++j)
			if (T[j] > T[p])
				p = j;
		echange(T[p],T[i]);
	}
}

// ***** Tri à bulles *****
void tri_bulle (int * T, int n)
{
	for (int i = n-1; i > 0; --i)
		for (int j = 0; j < i; ++j)
			if (T[j] > T[j+1])
				echange(T[j],T[j+1]);
}

// ***** Tri par insertion *****
void tri_insertion (int * T, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int x = T[i];
		int j = i;
		while ((j > 0) and (T[j-1] > x))
		{
			T[j] = T[j-1];
			--j;
		}
		T[j] = x;
	}
}

// ***** Tri à peigne *****
void tri_peigne (int * T, int n)
{
	bool ech;
	int inter = n;
	do
	{
		ech = false;
		//inter = static_cast<int>(inter/1.25);
		inter = inter * 4/5;
		if (inter == 0) inter = 1;
		for (int j = 0; j < n-inter; ++j)
			if (T[j] > T[j+inter])
			{
				echange(T[j],T[j+inter]);
				ech = true;
			}
	} while ((inter > 1) or ech);
}

// ***** Tri rapide *****
int partitionnement (int * T, int d, int f)
{
	int p = T[f];
	int j = d; 
	for (int i = d; i < f; ++i)
		if (T[i] < p) 
		{
			echange(T[i], T[j]);
			++j;
		}
	echange(T[f], T[j]);
	return j;
}


void tri_rapide (int * T, int d, int f)
{
	if (f-d > 0) 	
	{
		int k = partitionnement(T,d,f);
		tri_rapide(T,d,k-1);
		tri_rapide(T,k+1,f);
	}
}

void tri_rapide (int * T, int n)
{
	tri_rapide(T,0,n-1);
}

// ***** Tri rapide + insertion *****
void tri_rapide_incomplet (int * T, int d, int f)
{
	if (f-d > 15) 	
	{
		int k = partitionnement(T,d,f);
		tri_rapide_incomplet(T,d,k-1);
		tri_rapide_incomplet(T,k+1,f);
	}
}

void tri_rapide_insertion (int * T, int n)
{
	tri_rapide_incomplet(T,0,n-1);
	tri_insertion(T,n);
}

// ***** Tri fusion *****
void tri_fusion (int * T, int d, int f)
{
	if (f-d > 0) 	
	{
		int m = (f+d)/2;
		int i = d;
		int j = m+1;
		tri_fusion(T,d,m);
		tri_fusion(T,j,f);
		int * F = new int [f-d+1];
		int k = 0;
		while ((i <= m) and (j <= f))
			if (T[i] <= T[j])
				F[k++] = T[i++];
			else
				F[k++] = T[j++];
		while (i <= m)
			F[k++] = T[i++];
		while (j <= f)
			F[k++] = T[j++];
		k = 0;
		for (i = d; i <= f; ++i)
			T[i] = F[k++];
		delete[] F;
	}
}

void tri_fusion (int * T, int n)
{
	tri_fusion(T,0,n-1);
}

// --------------------------------------------------------------------

float tri (int * T, int n, std::string algo)
// Trie un tableau selon l'algorithme spécifié
{
	init_chrono();
	if (algo == "selection") tri_selection(T,n);
	if (algo == "bulle") tri_bulle(T,n);
	if (algo == "insertion") tri_insertion(T,n);
	if (algo == "peigne") tri_peigne(T,n);
	if (algo == "rapide") tri_rapide(T,n);
	if (algo == "rapide insertion") tri_rapide_insertion (T,n);
	if (algo == "fusion") tri_fusion(T,n);
	return etat_chrono();
}

// --------------------------------------------------------

int * copie (int * T, int n)
// Retourne une copie du tableau T
{
	int * C = new int [n];
	for (int i = 0; i < n; ++i)
		C[i] = T[i];
	return C;
}

int ** ensemble_copies (int * T, int nb_copies, int n)
// Retourne un tableau composé de plusieurs copies de T (T placé en position 0)
{
	int ** E = new int * [nb_copies];
	E[0] = T;
	for (int i = 1; i < nb_copies; ++i)
		E[i] = copie(T,n);
	return E;
}

void supprime (int ** E, int nb_tab)
// Supprime un ensemble de tableaux (mémoire libérée)
{
	for (int k = 0; k < nb_tab; ++k)
		delete[] E[k];
	delete[] E;
}

// --------------------------------------------------------------------
// Liste d'algorithmes de tri, avec temps de calcul

struct maillon
{
	std::string nom;
	float temps;
	maillon * suiv;
};
using liste_tris = maillon *;

void ajoute (std::string nom_tri, liste_tris & L)
{
	if (L == nullptr)
	{
		L = new maillon;
		L->nom = nom_tri;
		L->temps = 0;
		L->suiv = nullptr;
	}
	else ajoute(nom_tri,L->suiv);
}

void supprime_premier (liste_tris & L)
{
	if (L != nullptr)
	{
		liste_tris aux = L;
		L = L->suiv;
		delete aux;
	}
}

int taille (liste_tris L)
{
	if (L == nullptr) return 0;
	else return 1 + taille(L->suiv);
}


// --------------------------------------------------------------------
void compare_tris (int n, liste_tris & L)
// Applique les algorithmes de tri de la liste à un même tableau de taille n, généré aléatoirement
// Les chronos sont enregistrés dans la liste
{
	int nb_algos = taille(L);
	int * T = genere(n);
	int ** E = ensemble_copies(T,nb_algos,n);
	liste_tris p = L;
	for (int k = 0; k < nb_algos; ++k)
	{
		p->temps = tri(E[k],n,p->nom);
		std::cout << p->temps << " s " << p->nom;
		if (verif_tri(E[k],n)) std::cout << " OK"; else std::cout << " ERREUR";
		std::cout << std::endl;
		p = p->suiv;
	}	
	supprime(E,nb_algos);
}

void elimine_tris_lents (liste_tris & L, float tempsmax)
// Supprime dans la liste les algorithmes dont le temps de calcul dépasse le seuil
{
	if (L != nullptr) 
	{
		if (L->temps > tempsmax) 
		{
			supprime_premier(L);
			elimine_tris_lents(L,tempsmax);
		}
		else elimine_tris_lents(L->suiv,tempsmax);
	}
}

// --------------------------------------------------------------------

int main ()
{
	srand(random_seed());
	liste_tris L = nullptr;
	ajoute("selection",L);
	ajoute("bulle",L);
	ajoute("insertion",L);
	ajoute("peigne",L);
	ajoute("rapide",L);
	ajoute("rapide insertion",L);
	ajoute("fusion",L);
	
	float tempsmax = 15.0;
	
	int n = 1;
	while (L != nullptr)
	{	
		std::cout << "\nn = " << n << std::endl;
		compare_tris(n,L);
		elimine_tris_lents(L,tempsmax);
		n *= 2;
	}

	return 0;
}
