#include "sequence.hpp"
#include <iostream>
#include <vector>

std::vector<int> saisieVecteur(){
    std::vector<int> v;
    int val;
    for(int i=0;i<10;i++){
        std::cout<<"Valeurs ?";std::cin>>val;
        v.push_back(val);
    }
    return v;
}

int maxIndice(std::vector<int> v){
    int max=v[0];
    for (std::vector<int>::size_type i(0); i<v.size(); ++i){
        if(v[i]>max){
            max=v[i];
        }
    }
    return max;
}

int maxIterateur(std::vector<int> v){
    int max=v[0];
    for (std::vector<int>::const_iterator i(v.begin()); i!=v.end(); ++i){
        if(*i>max){
            max=*i;
        }
    }
    return max;
}

int maxBoucle(std::vector<int> v){
    int max=v[0];
    for (auto i : v){
        if(i>max){
            max=i;
        }
    }
    return max;
}

int main() {
    sequence a;
    a.ajouter(couleur::rouge);
    a.ajouter(couleur::bleu);
    a.ajouter(couleur::rouge);
    a.ajouter(couleur::vert);
    sequence b(a); // voir question 3
    a.afficher(a.acces(0)); std::cout << "\n";
    for (indicesequence i=0; i<a.taille(); ++i) {
        a.afficher(a.acces(i));
        std::cout << " ";
    }
    std::cout << "\n";
    a.vider();
    std::cout << "A: "; a.afficher(std::cout); std::cout << "\n"; // cf. q4
    std::cout << "B: "; b.afficher(std::cout); std::cout << "\n";
    std::cout << a.comparer(b) << "\n";
    a.copier(b); // voir question 5
    std::cout << a.comparer(b) << "\n";
    return 0;
}
