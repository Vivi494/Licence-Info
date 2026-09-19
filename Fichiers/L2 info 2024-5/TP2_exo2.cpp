#include <fstream>
#include <iostream>
#include <string>
#include "TP1_AFD.h"

unsigned int delta(int k,char x,std::string motif){
    int j=std::min(k+1,motif.length());
}

Automate creer_AFD(std::string motif){
    Automate A;
    A.nbEtats=motif.length()+1;
    A.alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    A.tailleAlphabet=A.alphabet.length();
    A.etatsAcceptants = new bool[A.nbEtats];
    for(int i=0;i<motif.length()+1;i++){
        if(i==motif.length()){
            A.etatsAcceptants[i]=true;
        }
        else{
            A.etatsAcceptants[i]=false;
        }
    }
    A.transition=new unsigned int*[A.nbEtats];
    for(int i=0;i<A.nbEtats;i++){
        A.transition[i]=new unsigned int[A.tailleAlphabet];
    }
    for(int i=0;i<A.nbEtats;i++){
        for(int j=0;j<A.tailleAlphabet;i++){
            A.transition[i][j]=delta(i,A.alphabet[j],motif);
        }
    }
}

int main(){
    std::string motif,texte;
    int nbcomp;
    std::cout<<"Motif ? ";std::getline(std::cin,motif);
    std::cout<<"Fichier Texte ? ";std::getline(std::cin,texte);
    std::cout<<nbcomp<<std::endl;
    return 0;
}
