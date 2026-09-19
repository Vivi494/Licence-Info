drop table if exists Etudiant,Groupe,Contrôle,PassCont,Matiere,Enseignant cascade;
drop sequence if exists NumEtSeq,NumContSeq,NumEnsSeq;

--1)

create sequence NumEtSeq start 1111;

create table Groupe
(
    NomGroupe varchar(5) primary key,
    IntituleGroupe varchar(15),
    constraint GroupeValide check (NomGroupe in ('A1', 'A2', 'A3', 'A4', 'A5', 'A6'))
);

create table Etudiant
(
    NumEt int primary key,
    NomEt varchar(30),
    PrenomEt varchar(30),
    AdrEt varchar(50),
    DatNais date,
    NomGr varchar(5),
    foreign key(NomGr) references Groupe(NomGroupe) on update cascade on delete cascade,
    constraint Age check(2025-extract(year from DatNais)>15 and 2025-extract(year from DatNais)<36),
    constraint GrValide check (NomGr in ('A1', 'A2', 'A3', 'A4', 'A5', 'A6'))
);

create sequence NumContSeq;

create sequence NumEnsSeq;

create table Enseignant
(
    NumEns int primary key,
    NomEns varchar(30)
);

create table Matiere
(
    NomMat varchar(15) primary key,
    CoefMat int,
    NumEns int,
    foreign key(NumEns) references Enseignant(NumEns) on update cascade on delete cascade,
    constraint CoefMatValide check(CoefMat>0 and CoefMat<9)
);

create table Contrôle
(
    NumCont int primary key,
    NomMat varchar(15),
    DatCont date,
    Coef int,
    foreign key(NomMat) references Matiere(NomMat) on update cascade on delete cascade,
    constraint ValideCoeff check(Coef>0 and Coef<4)
);

create table PassCont
(
    NumEt int,
    NumCont int,
    Note float,
    primary key(NumEt,NumCont),
    foreign key(NumEt) references Etudiant(NumEt) on update cascade on delete cascade,
    foreign key(NumCont) references Contrôle(NumCont) on update cascade on delete cascade,
    constraint NoteValide check(Note>=0 and Note<=20)
);

insert into Groupe
values
    ('A1', 'Informatique'),
    ('A2', 'Math-Info'),
    ('A3', 'Bio-Info'),
    ('A4', 'Chimie'),
    ('A5', 'Math');

insert into Etudiant
values
    (nextval('NumEtSeq'), 'AHDJOUDJ', 'Yannick', 'Angers', '18/01/2003', 'A1'),
    (nextval('NumEtSeq'), 'AMEUR', 'Adil', 'Cholet', '17/02/2002', 'A1'),
    (nextval('NumEtSeq'), 'CALVAIRE', 'Isabelle', 'Nantes', '01/03/2004', 'A2'),
    (nextval('NumEtSeq'), 'GHULAM', 'William', 'Cholet', '27/04/2004', 'A2'),
    (nextval('NumEtSeq'), 'MIRMONT', 'Jean', 'Paris', '07/05/2002', 'A3'),
    (nextval('NumEtSeq'), 'TOTO', 'Sylvie', 'Tours', '17/06/2001', 'A3'),
    (nextval('NumEtSeq'), 'WINTERHA', 'Shahidah', 'Toulouse', '07/07/2003', 'A3');

insert into Enseignant
values
    (nextval('NumEnsSeq'), 'Carter'),
    (nextval('NumEnsSeq'), 'Clinton'),
    (nextval('NumEnsSeq'), 'Bush'),
    (nextval('NumEnsSeq'), 'Paolo'),
    (nextval('NumEnsSeq'), 'Vissou'),
    (nextval('NumEnsSeq'), 'Charlemagne'),
    (nextval('NumEnsSeq'), 'Léandri');

insert into Matiere
values
    ('Algo 2', 6, 1),
    ('Algo 3', 7, 2),
    ('Math1', 6, 3),
    ('Gestion', 7, 4),
    ('TE', 7, 5),
    ('Math2', 6, 6),
    ('Anglais', 7, 7);

insert into Contrôle
values
    (1, 'Algo 2', '15/01/2023', 1),
    (2, 'Algo 2', '12/12/2022', 3),
    (3, 'Algo 3', '17/02/2023', 2),
    (4, 'Algo 3', '27/03/2023', 3),
    (5, 'Math1', '17/01/2023', 1),
    (6, 'Gestion', '07/02/2023', 2),
    (7, 'TE', '27/03/2023', 2),
    (8, 'Math2', '17/01/2023', 1),
    (9, 'Anglais', '27/01/2023', 2);

insert into PassCont
values
    (1111, 1, 10),
    (1112, 1, 20),
    (1113, 1, 11.5),
    (1114, 1, 3),
    (1115, 1, 10.5),
    (1116, 1, 12),
    (1111, 2, 10.5),
    (1112, 2, 6.6),
    (1113, 2, 4.5),
    (1114, 2, 9),
    (1115, 2, 8.5),
    (1116, 2, 2.5),
    (1111, 3, 14.5),
    (1112, 3, 11.5),
    (1113, 3, 3.5),
    (1114, 3, 12.5),
    (1115, 3, 20),
    (1116, 3, 9.5);

--2)

insert into Etudiant
VALUES
    (1200, 'ZIDANE', 'Zinedine', 'Marseille', '23/06/1972', 'A1');
--Trop agé pour etre inséré.

--4)

insert into Groupe
VALUES
    ('A6','Football');

--3) 5)

insert into Etudiant
VALUES
    (1300, 'MBAPPE', 'Kylian', 'Madrid', '20/12/1998', 'A6');
--lorsque A6 n'est pas insere dans Groupe, kylian n'est pas inserable.

--7)

insert into Etudiant
VALUES
    (nextval('NumEtSeq'),'DOUE','Desire','Paris','03/06/2005','A1');

--6) 8)

 insert into PassCont
 values
    (1118,1,15);
--avant insertion de desire doue, 1118 n'existe pas et dons viole la contrainte.

--9)

update Enseignant
set NumEns=101
where NomEns='Carter';

--10)

insert into Etudiant
VALUES
    (nextval('NumEtSeq'),'CAMAVINGA','Edouardo','Madrid','10/11/2002',(select NomGroupe from Groupe where IntituleGroupe='Informatique'));

--11)

alter table Groupe
add Salle varchar(5);

--12)

update Groupe
set Salle=('L00'||(substring(Nomgroupe from 2 for 2)));

--13)

select A.Nomgr,A.NumCont,Avg(A.Note) from (select P.NumCont,P.Note, E.NomGr from Etudiant as E join PassCont as P on E.NumEt=P.NumEt)as A group by NumCont,NomGr having Avg(Note)<8;
