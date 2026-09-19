//Ex1:
struct noeud{
    noeud** N;
};

using dictionnaire = noeud*;

//1)
void initialisation(dictionnaire & D){
    D=nullptr;
}

int main(){
    dictionnaire D;
    initialisation(D);
}

//2)
