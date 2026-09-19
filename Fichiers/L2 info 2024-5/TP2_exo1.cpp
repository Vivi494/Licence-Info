#include <iostream>
#include <fstream>
#include <string>

bool recherche2(std::string morceau,std::string motif,int &nbcomp){
    for(int j=0;j<motif.length();j++){
        nbcomp++;
            if(morceau[j]!=motif[j]){
                return false;
            }
        }
        return true;
}

void recherche1(std::string ligne,int numligne,std::string motif,int &nbcomp){
    if(ligne.length()>=motif.length()){
        for(int i=0;i<ligne.length()+1-motif.length();i++){
            std::string morceau="";
            for(int k=0;k<motif.length();k++){
                morceau+=ligne[i+k];
            }
            if(recherche2(morceau,motif,nbcomp)){
                std::cout<<"Ligne : "<<numligne<<" Colonne : "<<i<<'\n';
            }
        }
    }
}

void recherche_naif(std::string texte,std::string motif,int &nbcomp){
    std::string ligne;
    std::ifstream fic;
    fic.open(texte);
    int numligne=1;
    while(fic.good()){
        std::getline(fic,ligne);
        recherche1(ligne,numligne,motif,nbcomp);
        numligne++;
    }
}

int main(){
    std::string motif,texte;
    int nbcomp;
    std::cout<<"Motif ? ";std::getline(std::cin,motif);
    std::cout<<"Fichier Texte ? ";std::getline(std::cin,texte);
    recherche_naif(texte,motif,nbcomp);
    std::cout<<nbcomp<<std::endl;
    return 0;
}
