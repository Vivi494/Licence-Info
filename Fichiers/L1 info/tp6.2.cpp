//exo6.2
#include <iostream>
#include <array>
#include <cstdlib>
int main()
{
    srand(time(nullptr));
    const int taillemax=10;
    using ligne = std::array <unsigned int,taillemax>;
    using matrice = std::array <ligne,taillemax>;
    matrice grille;unsigned int nbb;
    do{
        std::cout<<"Nombre de bateaux : ";std::cin>>nbb;
        if(nbb<2){std::cout<<"plus que 2 stp\n";}
        if(nbb>10){std::cout<<"pas plus que 10 stp\n";}
    }while(nbb<2 or nbb>10);
    ligne b;
    
    for (unsigned int i=1;i<=nbb;i++){
        do{std::cout<<"Longueur du bateau no."<<i<<" : ";std::cin>>b[i];
            if(b[i]<2){std::cout<<"plus grand que 2 stp\n";}
            if(b[i]>10){std::cout<<"pas plus que 10 stp\n";}
        }while(b[i]<2 or b[i]>10);
    }
    
    for (unsigned int i=0;i<taillemax;i++){
        for (unsigned int j=0;j<taillemax;j++){
            grille[i][j]=0;
        }
    }
    
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
    
    std::cout<<"Grille :"<<'\n';
    for (unsigned int i=0;i<taillemax;i++){
        for (unsigned int j=0;j<taillemax;j++){std::cout<<grille[j][i]<<' ';}
        std::cout<<'\n';
    }
    return 0;
}
