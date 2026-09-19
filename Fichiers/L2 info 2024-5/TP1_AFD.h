#include <iostream>
#include <fstream>


struct Automate{
    unsigned int tailleAlphabet;
    std::string alphabet;

    unsigned int nbEtats;
    bool* etatsAcceptants;

    unsigned int** transition;

};

//On suppose que le fichier est bien construit :)
Automate litAutomate(std::string fichier){
    Automate A;

    //Création du flux
    std::ifstream read;
    read.open(fichier);

    if(!read.is_open()){
        std::cerr << "Le fichier ne peut pas être ouvert";
        return A;
    }

//Récupération de la taille de l'alphabet
    read >> A.tailleAlphabet;

//récupération du nombre d'états
    read >> A.nbEtats;

//Récupération du nombre d'états acceptants (pour savoir après combien de cars s'arrêtter en lisant les états acceptants)
    unsigned int nbAcceptants;
    read >> nbAcceptants;

//récupération de l'alphabet
    read >> A.alphabet;

//Initialisation de etatsAcceptants
    A.etatsAcceptants = new bool[A.nbEtats];
    for(unsigned int i=0; i<A.nbEtats; i++){
        A.etatsAcceptants[i] = false;
    }

//Assignation des états acceptants
    int acc;
    for(unsigned int i=0; i<nbAcceptants; i++){
        read >> acc;
        A.etatsAcceptants[acc] = true;
    }

//Initialisation des transitions
    A.transition = new unsigned int*[A.nbEtats];
    for(unsigned int i=0; i<A.nbEtats; i++){
        A.transition[i] = new unsigned int[A.tailleAlphabet];
    }

    for(unsigned int etat=0; etat<A.nbEtats; etat++){
        for(unsigned int lettre=0; lettre<A.tailleAlphabet; lettre++){
            read >> A.transition[etat][lettre];
        }
    }

    return A;
}

void detruireAutomate(Automate &A) {
    delete[] A.etatsAcceptants;
    for (unsigned int i = 0; i < A.nbEtats; i++) {
        delete[] A.transition[i];
    }
    delete[] A.transition;
}
/* ###############
 *      EX 3
 * ###############
 */

void afficheEtatsAcceptants(Automate A){
    int nbEtatsAcceptants = 0;
    for(unsigned int i=0; i<A.nbEtats; i++){
        if(A.etatsAcceptants[i]) nbEtatsAcceptants++;
    }

    if(nbEtatsAcceptants == 0){
        std::cout << "Il n'y a aucun état acceptant" << std::endl;
    }
    else{
        if(nbEtatsAcceptants == 1){
            std::cout << "L'état acceptant est : ";
            int i=0;
            while(!A.etatsAcceptants[i]){
                i++;
            }
            std::cout << i << "\n" <<std::endl;
        }
        else{
            std::cout << "Les états acceptants sont : ";
            unsigned int i=0;
            while(!A.etatsAcceptants[i]){
                i++;
            }
            std::cout << i;
            i++;
            while(i < A.nbEtats){
                if(A.etatsAcceptants[i]){
                    std::cout << " et " << i;
                }
                i++;
            }

            std::cout << std::endl;
        }
    }
}


void afficheAutomate(Automate A){
    std::cout << "L'alphabet est :" << std::endl;
    std::cout << A.alphabet[0];
    for(unsigned int i=1; i<A.tailleAlphabet; i++){
        std::cout << ", " << A.alphabet[i];
    }
    std::cout << "\n" << std::endl;

    std::cout << "Il y a " << A.nbEtats << " états\n" << std::endl;

    afficheEtatsAcceptants(A);

    for(unsigned int etat=0; etat<A.nbEtats; etat++){
        for(unsigned int lettre=0; lettre<A.tailleAlphabet; lettre++){
            std::cout << '(' << etat << ',' << A.alphabet[lettre] << ") = " << A.transition[etat][lettre] << "   ";
        }
        std::cout << std::endl;
    }
}

/* ###############
 *      EX 4
 * ###############
 */

int indice_car(char c, std::string s){
    int i = s.length()-1;

    while( (i >= 0) && (s[i] != c) ){
        i--;
    }

    return i;
}

/* ###############
 *      EX 5
 * ###############
 */

int etatSuivant(char c, int etat, Automate A){
    int lettre = indice_car(c, A.alphabet);

    if(lettre == -1){
        return -1;
    }
    else{
        return A.transition[etat][lettre];
    }
}

bool strAppartientAFD(std::string s, Automate A){
    //L'état initial est toujours 0
    int etat = 0;
    int len = s.length();

    int i=0;

    while( (i<len) && (etat != -1) ){
        etat = etatSuivant(s[i], etat, A);
        i++;
    }


    if(etat == -1)
        return false;
    else
        return A.etatsAcceptants[etat];
}


void afficheEstDansAFD(std::string s, Automate A){
    std::string mot;
    if(s == ""){
        mot = "La chaîne vide";
    }
    else{
        mot = "\"" + s + "\"";
    }

    if(strAppartientAFD(s, A)){
        std::cout << mot << " appartient au langage de l'AFD" << std::endl;
    }
    else{
        std::cout << mot << " n'appartient pas au langage de l'AFD" << std::endl;
    }
}

/*
int main(){

    std::string fichier1 = "AFD_1.txt";
    std::string fichier2 = "AFD_2.txt";


    Automate A1 = litAutomate(fichier1);
    Automate A2 = litAutomate(fichier2);

/*
    std::cout << "----- Automate A1 -----" << std::endl;
    afficheAutomate(A1);

    std::string tabTest []= {"", "a", "b", "aa", "ab",
                            "ba", "bb", "0", "ababa", "abababababab"};
    int tailleTabTest = 10;

std::cout << "----- tests de l'Automate A1 -----" << std::endl;
    for(unsigned int i=0; i<tailleTabTest; i++){
        afficheEstDansAFD(tabTest[i], A1);
    }
*/
/*
    std::cout << "----- Automate A2 -----" << std::endl;
    afficheAutomate(A2);

    std::string tests []= {""};
*/
/*
    afficheAutomate(A1);
    std::cout << std::endl;
    std::string s;
    while(true){
        std::cout << "Quelle chaîne ? : ";
        std::cin >> s;
        afficheEstDansAFD(s, A1);
    }



    detruireAutomate(A1);
    detruireAutomate(A2);

    return 0;
}
*/
