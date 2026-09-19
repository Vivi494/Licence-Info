DROP table if exists LIVRE,AUTEUR,PERSONNAGE,PARTICIPE,LIVRE_AUTEUR cascade;
drop sequence if exists reflivreSeq,refpersSeq cascade;

--1)

create sequence reflivreSeq start 1;

create sequence refpersSeq start 101;

create table AUTEUR(
    nom varchar(30) primary key,
    nom_complet varchar(70),
    pays char(3),
    siecle int
);

create table LIVRE(
    reflivre int primary key default nextval('reflivreSeq'),
    titre varchar(100) not null,
    parution int,
    type varchar(10)  default 'autre',
    constraint typeConstraint check( type in('roman',
'théâtre', 'récit','autre')),
    nomauteur varchar(30),
    foreign key(nomauteur) references AUTEUR(nom)
);

create table PERSONNAGE(
    refpers int primary key default nextval('refpersSeq'),
    nom varchar(50),
    metier varchar(50),
    sexe char(1),
    constraint sexeConstraint check(sexe in('M','F'))
);

create table PARTICIPE(
    idpers int,
    idlivre int,
    nbcitations int,
    primary key(idpers,idlivre),
    foreign key(idlivre) references LIVRE(reflivre),
    foreign key(idpers) references PERSONNAGE(refpers)
);

--2)

insert into AUTEUR
VALUES
    ('Hugo', 'Victor Hugo', 'FRA', 19),
    ('Shakespeare', 'William Shakespeare', 'GBR', 16);

insert into LIVRE(titre, parution, type, nomauteur)
values
    ('Les Misérables', 1862, 'roman', 'Hugo'),
    ('Ruy Blas',NULL,'théâtre', 'Hugo'),
    ('Roméo et Juliette' ,1597, 'théâtre', 'Shakespeare');

insert into PERSONNAGE(nom, metier, sexe)
VALUES
    ('Juliette', 'princesse', 'F'),
    ('Roméo', 'prince', 'M'),
    ('Cosette', 'femme de ménage', 'F');

insert into PARTICIPE
VALUES
    (101, 3, 134),
    (102, 3, 112);

--3)

UPDATE LIVRE
set parution=1400
where parution is NULL;

--4)

alter table LIVRE
drop constraint typeConstraint,
add constraint typeConstraint check(type in('roman',
'théâtre', 'récit','autre','poésie'));

--5)

/*insert into LIVRE(titre, parution, type, nomauteur)
values
    ('Le Grand Meaulnes', 1913, 'roman', 'Alain-Fournier')

Alain-Fournier n'est pas present dans la table des auteurs et on ne peut donc pas l'ajouter.
*/

--6)

insert into PARTICIPE
VALUES
    (103,1,324);

--7)

/*delete from LIVRE
where titre='Roméo et Juliette';

On ne peut pas supprimer la ligne car on en a besoin pour la table participe.
*/

--8)

create table LIVRE_AUTEUR(
    titre varchar(100) not null,
    nom_complet varchar(70)
);

--9)

create view V_LIVRE_AUTEUR
as select l.titre,a.nom_complet
from LIVRE as l
join AUTEUR as a
on l.nomauteur=a.nom;

--10)

insert into LIVRE_AUTEUR
VALUES
    ('L étranger','Albert Camus');

/*
La vue prends tous les n-uplets correspondant dans la jointure de table demandée alors que la table doit etre incrementer de tous les n-uplets.
*/

--11)

create view V_AUTEUR_PERS_FEMME
as select sum(p.nbcitations),l.nomauteur
from LIVRE as l
join ( select b.nbcitations,b.idlivre
from PARTICIPE as b
join PERSONNAGE as a
on a.refpers=b.idpers
where sexe='F') as p
on l.reflivre=p.idlivre
group by l.nomauteur;

--12)

create view V_LIVRE_SIECLE_M
as select count(reflivre),siecle
from
group by siecle;

/*LIVRE (reflivre, titre, parution, type, nomauteur)
AUTEUR (nom, nom_complet , pays, siecle)
PERSONNAGE (refpers, nom, metier, sexe)
PARTICIPE (idpers, idlivre, nbcitations)*/
