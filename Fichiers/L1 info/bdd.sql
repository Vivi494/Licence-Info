--TP1

--exercice 1
/*
select * 
from Produit;
*/

--exercice 2
/*
Select NomF,villeF 
from Fournisseur;
*/

--exercice 3
/*
Select NomP 
from Produit 
WHERE Prix > 1300;
*/

--exercice 4
/*
Select NomP 
from Produit 
WHERE Prix BETWEEN 1300 AND 1500;
*/

--exercice 5
/*
Select NomP 
from Produit 
WHERE Prix=1300 or prix=1500;
*/

--exercice 6
/*
Select NomC,VilleC 
from Client 
Where NomC like 'J%';
*/

--exercice 7
/*
Select DISTINCT NomP 
From Produit 
ORDER BY NomP;
*/

--exercice 8
/*
Select NomC 
FROM Client 
WHERE 2024 - client.anneenaissc > 40;
*/

--exercice 9
/*
Select NumF 
FROM Produit 
WHERE NomP='parpaing' AND Prix > 1300;
*/

--exercice 10
/*
Select distinct NomF 
from Fournisseur F join Produit P 
ON F.NumF = P.NumF 
Where NomP ='parpaing' OR NomP='briques';
*/

--exercice 11
/*
Select distinct NomC 
FROM Client C JOIN Commande COM 
ON C.NumC = COM.NumC 
where NomP='briques' 
ORDER BY NomC;
*/

--exercice 12
/*
Select NomF 
from Fournisseur F JOIN Produit P 
ON F.NumF = P.NumF 
WHERE VilleF ='Paris';
*/

--exercice 13
/*
Select NomC,VilleC 
FROM Client C JOIN Commande COM 
ON C.NumC = COM.NumC 
WHERE NomP = 'briques' AND Qte BETWEEN 8 AND 14;
*/

--TP2

--exercice 1
/*
\d;
*/

--exercice 2
/*
select *
from SERVICES;
select *
from PERSONNELS;
select *
from PATIENTS;
select *
from CONSULTATIONS;
select *
from CONGES;
*/
--exercice 3
/*
select nom,localis,batim 
FROM SERVICES;
*/

--exercice 4
/*
select qualif, codeserv 
FROM PERSONNELS;
*/

--exercice 5
/*
select Nom,prenom datnais
from PERSONNELS
where poste='CHEF DE SERVICE'
*/

--exercice 6
/*
select nom,prénom,sexe,qualification
from PERSONNELS
where hsupp is null;
*/

--exercice 7
/*
select distinct qualification
from PERSONNELS
where hsupp is null;
*/

--exercice 8
/*
select nom, prenom, sx, qualif, salaire
from personnels
where salaire between 20000 and 35000;
*/

--exercice 9
/*
select nom, prenom, sx, qualif, salaire AS francs
from personnels
where salaire between 20000 and 35000;
*/

--exercice 10
/*
select nom, prenom, datnais, sx, qualif
from personnels
where qualif='CHEF DE SERVICE' or qualif='ASSISTANT';
*/

--exercice 11
/*
select nom, prenom, sx, qualif
from personnels
where nom like 'BOU%'
*/

--exercice 12
/*
select nom, prenom, sx, qualif
from personnels
where nom like '_AR%'
*/

--exercice 13
/*
select nom, prenom, datnais, sx, qualif
from personnels
where sx=2 and qualif in ('INTERNE','DOCTEUR');
*/

--exercice 14
/*
select nom, prenom, datnais, sx, qualif
from personnels
where (qualif='INTERNE') or (sx=2 and qualif='DOCTEUR');
*/

--exercice 15
/*
select nom, prenom, datint, sx, qualif
from personnels
where datint>1990-01-01;
*/

--exercice 16
/*
select nom, prenom, datnais,sx, qualif, salaire
from personnels
where qualif in ('CHEF DE SERVICE','ASSISTANT')
order by salaire [ASC];
*/

--exercice 17
/*
select nom, prenom, datnais,sx, qualif, salaire
from personnels
where qualif in ('CHEF DE SERVICE','ASSISTANT')
order by datnais [DESC];
*/

--exercice 18
/*
select nom, prenom, datnais,sx, qualif, salaire
from personnels
where qualif='ASSISTANT'
order by salaire [DESC];
select nom, prenom, datnais,sx, qualif, salaire
from personnels
where qualif='CHEF DE SERVICE'
order by salaire [DESC];
*/

--TP 3

--exercice 1
/*
(select NomF,NomP,PrixP
from Fournisseur
join produit
on fournisseur.NumF=produit.NumF)
join (select NomP
from client
join commande
on client.NumC=commande.NumC
where NomC='Jean')
on (select NomF,NomP,PrixP
from Fournisseur
join produit
on fournisseur.NumF=produit.NumF).NomP
=
(select NomP
from client
join commande
on client.NumC=commande.NumC
where NomC='Jean').NomP
;
*/

--exercice 2
/*
(select NomF,NomP,PrixP
from Fournisseur
join produit
on fournisseur.NumF=produit.NumF)
join (select NomP
from client
join commande
on client.NumC=commande.NumC
where NomC='Jean')
on (select NomF,NomP,PrixP
from Fournisseur
join produit
on fournisseur.NumF=produit.NumF).NomP
=
(select NomP
from client
join commande
on client.NumC=commande.NumC
where NomC='Jean').NomP
order by NomP [DESC]
order by NomF [ASC];
*/

--exercice 3
/*
select MIN(NomP)
from produit;
*/

--exercice 4
/*
select NomP,AVG(Prix)
from produit
group by NomP;
*/

--exercice 5
/*
select NomP,AVG(Prix)
from produit
group by NomP
having AVG(Prix)>1000;
*/

--exercice 6
/*
select NomP
from produit
where Prix>(select AVG(Prix) from produit);
*/

--exercice 7
/*
select NomP,AVG(Prix)
from produit
join fournisseur
on produit.NumF=fournisseur.NumF

*/

--exercice 8
/*
select NomP,Prix
from produit
       join fournisseur on produit.NumF=fournisseur.NumF
       join commande on produit.NomP=commande.NomP$
       join client on commande.numcom=client.numc
where villef like '%ANGERS' and villec like '%PARIS';
*/

--TP4

--exercice 1
/*
select nom 
from personnels
where ='infirmiere'
join personnels
on personnels.nom=personnels.nom
where ='secretaire medicale';
*/

--exercice 2
/*
select nom,prenom 
from personnels
;
*/

--exercice 3
/*

*/

--exercice 4
/*

*/

--exercice 5
/*

*/

--exercice 6
/*

*/

--exercice 7
/*

*/

--exercice 8
/*

*/

--exercice 9
/*

*/

--TP6

--exercice 1
/*
select nom,prenom
from musicien
where datnaiss<'1930';
*/

--exercice 2
/*
select nom,prenom
from album 
join joue
on album.refalbum=joue.refalbum
where titre='Electric Ladyland';
*/

--exercice 3
/*
select ville
from album
join joue
on album.refalbum=joue.refalbum
join label
on album.nomLabel=label.nomLabel
where nom='Coltrane' and prenom='John';
*/

--exercice 4
/*
select titre
from album
join album
on album.annee=album.annee
where titre='Are You Experienced';
*/

--exercice 5
/*
select Max(duree)
from album;
*/

--exercice 6
/*
select Sum(label)
from label
group by ville;
*/

--exercice 7
/*
select sum(album)
from album
join joue
on album.refalbum=joue.refalbum
where nom='Coltrane' and prenom='john';
*/

--exercice 8
/*
select nom,prenom
from album
join joue
on album.refalbum=joue.refalbum
where 
sum(titre)
group by nom,prenom >
sum(album) 
where nom='Coltrane' and prenom='john';
*/

--exercice 9
/*
select nomLabel
from album
join joue
on album.refalbum=joue.refalbum
where nom='Hendrix' and prenom='Jimi';
*/

--exercice 10
/*

*/

--exercice 11
/*

*/

--exercice 12
/*

*/
