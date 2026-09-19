#TP1

#exercice 1
"""
n=input('prénom ? ')
print ('Hello',n,'!')
"""

#exercice 2
"""
nn=int(input('Début compte à rebours ? '))
while(nn<=0):
    nn=input('Début compte à rebours ? ')
for i in range (nn):
    print(nn-i)
print('GO')
"""

#exercice 3
"""
n=input('Mot ? ')
l=[]
while n!='':
    l.append(n)
    n=input('Mot ? ')
for i in l:
    if len(i)>=4:
        print(i)
"""

#exercice 4
"""
d={"un":"one","deux":"two","trois":"three","quatre":"four"}
for cle in d.keys():
    print(cle)

for value in d.values():
    print(value)

for cle,value in d.items():
    print(cle,'->',value)
"""

#exercice 5
"""
a=int(input('Entrez le premier nombre : '))
b=int(input('Entrez le deuxième nombre : '))

while a%b!=0:
    c=a%b
    a=b
    b=c
print(b)
"""

#exercice 6
"""
def saisie(l):
    n=int(input('Entier ? '))
    while n>0:
        l.append(n)
        n=int(input('Entier ? '))

def avant_der(l):
    return l[-2]

def somme(l):
    s=0
    for i in l[1:len(l)-1]:
        s=s+i
    return s

l=[]
saisie(l)
print(avant_der(l))
print(somme(l))
"""

#exercice 7
"""

"""


#TP2
"""
def changer_c(c,l,d):
    if c==" ":
        return " "
    for i in range(26):
        if l[i]==c:
            return l[(i+d)%26]
    return ""

def chiffrer_cesar(s,d,l1,l2):
    c=""
    for j in s:
        c+=changer_c(j,l1,d)
        c+=changer_c(j,l2,d)
    return c

n=input("Chiffrer ou Déchiffrer")
d=int(input("Décalage ?"))
minuscule=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
majuscule=["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
lire=open("text.txt","r")
ecrire=open("text2.txt","w")
if n=="Chiffrer":
    for s in lire.readline():
        ecrire.write(chiffrer_cesar(s,d,majuscule,minuscule))
else :
    if n=="Déchiffrer":
        for s in lire.readline():
            ecrire.write(chiffrer_cesar(s,-d, majuscule, minuscule))
"""