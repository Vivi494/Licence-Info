 #include <iostream>
#include <string>
/*ex 1.5
void nbonj (unsigned int n)
{
    if (n>0)
    {
        std::cout<<"bonjour\n";
        nbonj(n-1);
    }
}

int main()
{
    int n;
    std::cout<<"n ?";std::cin>>n;
    nbonj(n);
}*/

/*ex 1.6
int diviseur (int d,int n)
{
    if (n%(d+1)==0)return d+1;
    else diviseur(d+1,n);
}

bool est_premier(int d,int n)
{
    if(diviseur(d,n)==n)return true;
    else return false;
}

void affiche_premiers (int n)
{
    if (n>1)
    {
        affiche_premiers(n-1);
        if (est_premier(1,n)==1)std::cout<<n<<' ';
    }
}

int main()
{
    int d,n;
    std::cout<<"d et n ?";std::cin>>d>>n;
    std::cout<<diviseur(d,n)<<'\n';
    std::cout<<est_premier(d,n)<<'\n';
    affiche_premiers(n);
}*/

/*ex 1.9
std::string extraire (int n,std::string s1,int l,std::string &s2)
{
    if (l>0)
    {
        extraire(n,s1,l-1,s2);
        s2=s2+s1[n-1+l-1];
    }
    return s2;
}

bool palindrome (std::string s,unsigned int n,bool &pal)
{
    if (n<=s.length()/2)
    {
        if(s[n]!=s[s.length()-n-1]){pal=false;}
        palindrome(s,n+1,pal);
    }
    return pal;
}

int occurence (char lettre,int i,std::string s,int &nb)
{
    if (i<=s.length())
    {
        if(s[i]==lettre)nb=nb+1;
        occurence(lettre,i+1,s,nb);
    }
    return nb;
}

int main()
{
    std::string s1,s2="";int n,l,i,nb=0;bool pal=true;char lettre;
    std::cout<<"chaine de caractère ? ";std::getline (std::cin,s1);
    std::cout<<"n et l ? ";std::cin>>n>>l;
    std::cout<<"lettre à vérifier ?";std::cin>>lettre;
    std::cout<<extraire(n,s1,l,s2)<<'\n';
    palindrome(s1,0,pal);
    std::cout<<pal<<'\n';
    std::cout<<occurence(lettre,0,s1,nb)<<'\n';
}*/


//exo 2.2

struct fraction
{
    int num;
    int den;
};

void saisie (fraction &a)
{
    std::cout<<"numérateur et dénominateur ? ";std::cin>>a.num>>a.den;
}

void affichage (fraction a)
{
    std::cout<<a.num<<'/'<<a.den<<'\n';
}

fraction mult (fraction a,fraction b)
{
    fraction c;
    c.num=a.num*b.num;
    c.den=a.den*b.den;
    return c;
}

fraction add (fraction a,fraction b)
{
    fraction c;
    c.num=a.num*b.den+a.den*b.num;
    c.den=a.den*b.den;
    return c;
}

fraction opp (fraction a)
{
    fraction c;
    c.num=-1*a.num;
    c.den=a.den;
    return c;
}

fraction inv (fraction a)
{
    fraction c;
    c.num=a.den;
    c.den=a.num;
    return c;
}

fraction soustr (fraction a,fraction b)
{
    fraction c;
    c.num=a.num*b.den-a.den*b.num;
    c.den=a.den*b.den;
    return c;
}

fraction div (fraction a,fraction b)
{
    fraction c;
    c.num=a.num*b.den;
    c.den=a.den*b.num;
    return c;
}

int pgcd (fraction a,fraction b)
{
    if((a.num/a.den)%(b.num/b.den)==0)
    {
        return b;
    }
    else
    {
        return pgcd(b,a%b);
    }
}

int main()
{
    fraction a,b;
    saisie(a);
    saisie(b);
    affichage(a);
    affichage(mult(a,b));
    affichage(add(a,b));
    affichage(opp(a));
    affichage(inv(a));
    affichage(soustr(a,b));
    affichage(div(a,b));
    affichage(pgcd(a,b));
}
