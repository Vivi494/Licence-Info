--1)
drop table if exists etudiant,groupe,controle,passcont,matiere,enseignant cascade;
drop sequence if exists NumEt,NumCont,NumEns cascade;

create table groupe
(NomGroupe varchar(5) primary key,
constraint NomGroupe check(NomGroupe in('A1','A2','A3','A4','A5','A6')),
IntituleGroupe varchar(30));

create sequence NumEt start 1111;

create table etudiant
(NumEt int primary key default nextval('NumEt'),
NomEt varchar(30),
PrenomEt varchar(30),
AdrEt varchar(50),
DatNais date,
constraint DatNais check(extract(year from current_date)-extract(year from DatNais)>16 and extract(year from current_date)-extract(year from DatNais)<35),
NomGr varchar(5),
foreign key(NomGr)
references groupe(NomGroupe)
on update cascade
on delete cascade);

create table controle
(NumCont serial primary key,
NomMat varchar(15),
DatCont date,
Coef int,
constraint Coef check(coef BETWEEN 1 and 3));

create table passcont
(NumEt int,
foreign key(NumEt)
references etudiant(NumEt)
on update cascade
on delete cascade,
NumCont int,
foreign key(NumCont)
references controle(NumCont)
on update cascade
on delete cascade,
Note float,
constraint Note check(Note between 0 and 20));

create sequence NumEns start 1;

create table enseignant
(NumEns int primary key default nextval('NumEns'),
NomEns varchar(30));

create table matiere
(NomMat varchar(15) primary key,
CoefMat int,
constraint CoefMat check(CoefMat between 1 and 8),
NumEns int,
foreign key (NumEns)
references enseignant(NumEns)
on update cascade
on delete cascade);

insert into groupe
values ('A1','Informatique'),
('A2','Math-Info'),
('A3','Bio-Info'),
('A4','Chimie'),
('A5','Math');

insert into etudiant(NomEt,PrenomEt,AdrEt,DatNais,NomGr)
values ('AHDJOUDJ','Yannick','Angers','18/01/2003','A1'),
('AMEUR','Adil','Cholet','17/02/2002','A1'),
('CALVAIRE','Isabelle','Nantes','01/03/2004','A2'),
('GHULAM','William','Cholet','27/04/2004','A2'),
('MIRMONT','Jean','Paris','07/05/2002','A3'),
('TOTO','Sylvie','Tours','17/06/2001','A3'),
('WINTERHA','Shahidah','Toulouse','07/07/2003','A3');

insert into controle(NomMat,DatCont,Coef)
values ('Algo 2','15/01/2023','1'),
('Algo 2','12/12/2022','3'),
('Algo 3','17/02/2023','2'),
('Algo 3','27/03/2023','3'),
('Math1','17/01/2023','1'),
('Gestion','07/02/2023','2'),
('TE','27/03/2023','2'),
('Math2','17/01/2023','1'),
('Anglais','27/01/2023','2');

insert into passcont
values ('1111','1','10'),
('1112','1','20'),
('1113','1','11.5'),
('1114','1','3'),
('1115','1','10.5'),
('1116','1','12'),
('1111','2','10.5'),
('1112','2','6.6'),
('1113','2','4.5'),
('1114','2','9'),
('1115','2','8.5'),
('1116','2','2.5'),
('1111','3','14.5'),
('1112','3','11.5'),
('1113','3','3.5'),
('1114','3','12.5'),
('1115','3','20'),
('1116','3','9.5');

insert into enseignant(NomEns(NomEt,PrenomEt,AdrEt,DatNais,NomGr))
values('Carter'),
('Clinton'),
('Bush'),
('Paolo'),
('Vissou'),
('Charlemagne'),
('Léandri');

insert into matiere
values('Algo 2','6','1'),
('Algo 3','7','2'),
('Math1','6','3'),
('Gestion','7','4'),
('TE','7','5'),
('Math2','6','6'),(NomEt,PrenomEt,AdrEt,DatNais,NomGr)
('Anglais','7','7');

--2)
insert into etudiant
values('1200','ZIDANE','Zinedine','Marseille','23/06/1972','A1');
--trop vieux

--3)
insert into etudiant
values('1300','MBAPPE','Kylian','Paris','20/12/1998','A6');
--A6 n'est pas présent dans NomGroupe.

--4)
insert into groupe
values('A6','Football');

--5)
insert into etudiant
values('1300','MBAPPE','Kylian','Paris','20/12/1998','A6');

--6)
insert into passcont
values('1118','1','15');
--l'étudiant numéro 1118 n'existe pas.

--7)
insert into etudiant(NomEt,PrenomEt,AdrEt,DatNais,NomGr)
values('POGBA','Paul','Turin','15/03/1993','A6');

--8)
insert into passcont
values('1118','1','15');

--9)
update enseignant
set NumEns=101
where NomEns='Carter';

--10)
insert into etudiant(NomEt,PrenomEt,AdrEt,DatNais,NomGr)
values('CAMAVINGA','Eduardo','Madrid','10/11/2002',(select NomGroupe from groupe where NomGroupe='Informatique'));

--11)
alter table groupe
add salle varchar(5);

--12)
update groupe
set salle='L00'||substr(NomGroupe,2,4);

select * from etudiant;
select * from groupe;
select * from controle;
select * from passcont;
select * from matiere;
select * from enseignant;
