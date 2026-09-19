import random
import json
import string

alphabet=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]

def changer(c,d):
    if((ord(c)>=65)and(ord(c)<=90)):
        a=ord(c)-65 
        b=d%26
        return chr(65+(a+b)%26)
    if((ord(c)<=122)and(ord(c)>=97)):
        a=ord(c)-97 
        b=d%26
        return chr(97+(a+b)%26)
    return c

def chiffrcesar(s,d):
    c=""
    for j in s:
        c+=changer(j,d)
    return c


def codecesar(entree,sortie,cd,d):
    with open(entree,"r") as fichier1, open(sortie,"w") as fichier2:
        if(cd=="Chiffrer"):
            fichier2.write(chiffrcesar(fichier1.read(),d))
        else:
            if(cd=="Déchiffrer"):
                fichier2.write(chiffrcesar(fichier1.read(),-d))


def table(sortie):
    liste=alphabet.copy()
    random.shuffle(liste)
    d={alphabet[i]:liste[i] for i in range(len(alphabet))}
    with open(sortie,"w") as my_file:
        json.dump(d,my_file)
    
def changcara(c,table):
    if((ord(c)>=65)and(ord(c)<=90)):
        return table[c]
    if((ord(c)<=122)and(ord(c)>=97)):
        return table[c]
    return c

def chifdictio(s,table):
    c=""
    for l in s:
        c+=changecara(l,table)
    return c
        

def dictio(entree,sortie,table,cd):
    with open(entree,"r") as fichier1, open(sortie,"w") as fichier2, open(table,"r") as fichier3 :
        if(cd=="Chiffrer"):
            fichier2.write(chifdictio(fichier1.read(),json.load(fichier3)))
        if(cd=="Déchiffrer"):
            d=json.load(fichier3)
            inversd={v:k for k,v in d.items()}
            fichier2.write(chifdictio(fichier1.read(),inversd))

def calculdecal(d):
    maxvalue=0
    maxlettre=""
    for lettre,value in d.items():
        if(value>maxvalue):
            maxvalue=value
            maxlettre=lettre
    return maxlettre

def cassercesar(entree,sortie1,sortie2,sortie3,sortie4):
    with open(entree,"r") as fichier1 :
        d={
            "a":0,"b":0,"c":0,"d":0,"e":0,"f":0,"g":0,"h":0,"i":0,"j":0,"k":0,"l":0,"m":0,
            "n":0,"o":0,"p":0,"q":0,"r":0,"s":0,"t":0,"u":0,"v":0,"w":0,"x":0,"y":0,"z":0,
            "A":0,"B":0,"C":0,"D":0,"E":0,"F":0,"G":0,"H":0,"I":0,"J":0,"K":0,"L":0,"M":0,
            "N":0,"O":0,"P":0,"Q":0,"R":0,"S":0,"T":0,"U":0,"V":0,"W":0,"X":0,"Y":0,"Z":0
        }
        for i in fichier1.read():
            if(((ord(i)>=65)and(ord(i)<=90))or((ord(i)<=122)and(ord(i)>=97))):
                d[i]+=1

        print(d)
        decal=(ord(calculdecal(d))-ord("e"))%26
        print(decal)
        codecesar(entree,sortie1,"Déchiffrer",decal)
        del d[calculdecal(d)]
        decal=(ord(calculdecal(d))-ord("a"))%26
        codecesar(entree,sortie2,"Déchiffrer",decal)
        del d[calculdecal(d)]
        decal=(ord(calculdecal(d))-ord("i"))%26
        codecesar(entree,sortie3,"Déchiffrer",decal)
        del d[calculdecal(d)]
        decal=(ord(calculdecal(d))-ord("s"))%26
        codecesar(entree,sortie4,"Déchiffrer",decal)
        

codecesar("la-folie.txt","textecode.txt","Chiffrer",1)
cassercesar("textecode.txt","texte_e.txt","texte_a.txt","texte_i.txt","texte_s.txt")