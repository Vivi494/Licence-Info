--TP8

--exercice 1
/*
select titre
from film
where Genre='Comédie' and Annee='2003';
*/

--exercice 2
/*
select nom,prenom
from film
join jouer
on film.Num_film=jouer.Num_film
join personne
on jouer.Num_acteur=personne.Num_personne
where titre='La folie des grandeurs';
*/

--exercice 3
/*
select nom,prenom
from personne
join jouer
on jouer.Num_acteur=personne.Num_personne
join film
on film.Num_film=jouer.Num_film
where Num_realisateur=(select Num_personne from personne where nom='Blier' and prenom='Bertrand');
*/

--exercice 4
/*
select Sum(Num_film)
from film
join jouer
on film.Num_personne=jouer.Num_acteur
where nom='depardieu' and prenom='gerard';
*/

--exercice 5
/*
select Num_film,titre,sum(Num_acteur)
from film
join jouer
on film.Num_film=jouer.Num_film
group by Num_film,titre;
*/

--exercice 6
/*
select distinct Nom,prenom
from (select Num_film
    from personne
    join jouer
    on jouer.Num_acteur=personne.Num_personne
    where nom = 'Depardieu' and prenom='Gérard') F
join (select Nom,Prenom,Num_film
    from personne
    join jouer
    on jouer.Num_acteur=personne.Num_personne
    where nom!='Depardieu' or prenom!='Gérard') G
on F.Num_film=G.Num_film;
*/
--exercice 7
/*
select Nom,Prenom
from personne
join film
on personne.Num_personne=film.Num_realisateur
where genre='Comédie'
except
select nom,prenom
from personne
join film
on personne.Num_personne=film.Num_realisateur
where genre!='Comédie';
*/

--exercice 8
/*
select Num_realisateur
from film
group by Num_realisateur
having count(titre)>4;
*/

--exercice 9
/*
select Nom,Prenom
from personne
join (select Num_realisateur
    from film
    group by Num_realisateur
    having count(titre)>4) F
on personne.Num_personne=F.Num_realisateur;
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

--exercice 13
/*

*/
