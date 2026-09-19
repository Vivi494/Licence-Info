#include <iostream>
#include <cmath>
#include <array>

using element=std::string;

const int MAX=30;

using tab=std::array<element,MAX>;

struct maillon{
    float val;
    maillon * suiv ;
};
using pile = maillon * ;

void creer_pile (pile & P)
{
    P=nullptr;
}

bool est_vide (const pile & P)
{
    return P == nullptr ;
}

float consulter_sommet (const pile & P)
{
    return P->val ;
}

float depiler (pile & P)
{
    float e = P->val ;
    pile aux = P ;
    P = aux->suiv ;
    delete aux ;
    return e ;
}

void empiler (float e, pile & P)
{
    pile aux = P;
    P = new maillon;
    P->val = e;
    P->suiv = aux;
}

bool operateur(element e)
{
    if(e=="^" or e=="+" or e=="-" or e=="*" or e=="/")
    {
        return true;
    }
    return false;
}

float operation(pile &P,element e){
    float a,b,aob;
    b=(depiler(P));
    a=(depiler(P));
    if(e=="-"){
        aob=a-b;
    }
    else if(e=="+"){
        aob=a+b;
    }
    else if(e=="*"){
        aob=a*b;
    }
    else if(e=="/"){
        aob=a/b;
    }
    else if(e=="^"){
        aob=pow(a,b);
    }
    return aob;
}

bool operateurU(element e)
{
    if(e=="RAC")
    {
        return true;
    }
    return false;
}

float operationU(pile &P,element e)
{
    float a,ae;
    a=depiler(P);
    ae=sqrt(a);
    return ae;
}

bool Est_Float(element e)
{
    element a="",b="";bool point=false;
    unsigned int i=0;
    while(e[i]=='1' or e[i]=='2' or e[i]=='3' or e[i]=='4' or e[i]=='5' or e[i]=='6' or e[i]=='7' or e[i]=='8' or e[i]=='9' or e[i]=='0' or e[i]=='.')
    {

    }
    if
}

bool exp_cor(element e)
{
    element tmp="";
    if(e[0]==' ')
    {
        return false;
    }
    while(e[i]!="=")
    {
        if(e[i]==' ')
        {
            if(not(operateur(tmp)) and not(operateurU(tmp)) and tmp!=PI and not(Est_Float(tmp))
            {
                return false;
            }
            tmp="";
        }
        else
        {
            tmp+=e[i];
        }
        i++;
    }
    if (tmp!="")
    {
        return false;
    }
    return true;
}

int main(){
    tab T;
    pile P;
    creer_pile(P);
    element e;
    std::cout<<"calcul : ";
    std::getline(std::cin,e);
    if (not(exp_cor(e)))
    {
        std::cout<<"expression incorrecte";
        return 0;
    }
    element tmp="";
    unsigned int i=0,j=0;
    while(e[i]!='=')
    {
        if(e[i]==' ')
        {
            T[j]=tmp;
            j++;
            tmp="";
        }
        else
        {
            tmp+=e[i];
        }
        i++;
    }
    T[j]="=";
    i=0;
    while(T[i]!="=")
    {
        if(operateur(T[i]))
        {
            empiler(operation(P,T[i]),P);
        }
        else if(operateurU(T[i]))
        {
            empiler(operationU(P,T[i]),P);
        }
        else if(T[i]=="PI")
            empiler(3.14159,P);
        else empiler(std::stof(T[i]),P);
        i++;
    }
    std::cout<<depiler(P)<<std::endl;
    return 0;
}
