1) SELECT nom FROM auteur where pays = 'ITA' ;

2) select distinct(nom),nomauteur
from personnage
join (select nomauteur,idpers
from participe
JOIN livre
on participe.idlivre = livre.reflivre
) as a
on personnage.refpers = a.idpers ;

3) select distinct pays from personnage
join (select pays,idpers
from participe
JOIN (select reflivre,pays
from livre
join auteur
on livre.nomauteur = auteur.nom
) as b
on participe.idlivre = b.reflivre
) as a
on personnage.refpers = a.idpers
where metier = 'voyageur';

4) select nom from auteur where nom_complet is not null ;

5) select count (reflivre),type from livre group by type;

6) select count (reflivre),pays from livre join auteur on livre.nomauteur = auteur.nom where type = 'récit' group by pays ;

7) select count(reflivre),pays from(select nom,pays from auteur where siecle = '19') as a
join livre on a.nom = livre.nomauteur where type = 'roman' group by pays ;

8) select distinct (a.nomauteur) from (select nomauteur from livre where type='récit') as a
join (select nomauteur from livre where type='roman') as b
on a.nomauteur = b.nomauteur ;

9) select nomauteur from (select count(reflivre) as nombre,nomauteur from livre group by nomauteur) as a where nombre >= 3;

10) select nomauteur from livre where select count(reflivre) as nombre = (select max (nombre) from (select count(reflivre) as nombre from livre group by nomauteur) as a);
