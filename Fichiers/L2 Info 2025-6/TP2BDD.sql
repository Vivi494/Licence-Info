--1)
drop table if exists SOCIETE,CAMPAGNE,SPOT,TARIF,PROGRAMMATION,SPOT2,CLIENT,EMPLOYE cascade;

create table SOCIETE
(
    CodeSoc int,
    Nom varchar(15) NOT NULL,
    Adresse varchar(50),
    Primary Key(CodeSoc)
);

insert into SOCIETE
values
    (101,'Nescafé','523 rue des grains Paris 13'),
    (102,'CIC','5 rue du brigand Paris 15'),
    (120,'Peugeot','36 avenue de la routourne Angers');

create table CAMPAGNE
(
    CodeCamp varchar(5) Primary Key,
    Titre varchar(30),
    CodeSoc int,
    Foreign Key(CodeSoc) references SOCIETE(CodeSoc),
    Produit varchar(10),
    Cible varchar(4),
    check (Cible in ('ENF','ADO','MM50','TOUS'))
);

INSERT into CAMPAGNE
values
    ('NE025','Nespresso-Clooney',101,'Café','MM50'),
    ('P208P','208-Pinocchio',120,'Voiture','TOUS'),
    ('BA75','Le monde bouge',102,'Banque','MM50');

create table SPOT
(
    CodeSpot char(3) primary key,
    Libelle varchar(40),
    duree int,
    CodeCamp varchar(5),
    foreign key(CodeCamp) references CAMPAGNE(CodeCamp)
);

insert into SPOT
VALUES
    ('NS1','Rencontre au bar',135,'NE025'),
    ('NS2','Soirée',115,'NE025'),
    ('P12','Mobile',60,'BA75'),
    ('P13','Premier emploi',75,'BA75'),
    ('P14','Séjour étranger',45,'BA75');

create table TARIF
(
    Media varchar(7),
    CONSTRAINT chaine check (Media in( 'TF1', 'FRANCE2', 'FRANCE3', 'CANAL+', 'M6', 'C8')),
    Moment varchar(7),
    check (Moment in( 'JOUR', 'DEBSOIR', 'SOIR', 'FINS')),
    Prix int,
    Primary key(Media,Moment)
);

insert into TARIF
VALUES
    ('TF1', 'SOIR', 500),
    ('TF1', 'DEBSOIR', 400),
    ('FRANCE2', 'JOUR', 50),
    ('FRANCE3', 'JOUR', 50),
    ('FRANCE3', 'DEBSOIR', 200);

create table PROGRAMMATION
(
    CodeSpot char(3),
    Media varchar(7),
    Moment varchar(7),
    Datep date,
    primary key(CodeSpot,Media,Moment,Datep),
    foreign key(CodeSpot) references SPOT(CodeSpot),
    foreign key(Media,Moment) references TARIF(Media,Moment)
);

insert into PROGRAMMATION
values
    ('NS1', 'TF1', 'SOIR', '18/02/25'),
    ('NS1', 'FRANCE3', 'JOUR', '20/02/25'),
    ('NS2', 'TF1', 'DEBSOIR', '20/02/25'),
    ('P12', 'TF1', 'DEBSOIR', '19/02/25'),
    ('P13', 'TF1', 'DEBSOIR', '20/02/25'),
    ('P13', 'FRANCE3', 'DEBSOIR', '20/02/25');

--2)
select * from SOCIETE;
select * from CAMPAGNE;
select * from SPOT;
select * from TARIF;
select * from PROGRAMMATION;

--3)
alter table TARIF
drop CONSTRAINT chaine;

alter table TARIF
add CONSTRAINT chaine check (Media in( 'TF1', 'FRANCE2', 'FRANCE3', 'CANAL+', 'M6', 'Novo 19'));

insert into TARIF
VALUES
    ('Novo 19', 'FINS', 50),
    ('Novo 19', 'SOIR', 80);

--4)
update SPOT
set Libelle='Rencontre en soirée'
where CodeSpot='NS2';

--5)
insert into SOCIETE(CodeSoc,Nom)
VALUES
    (100, 'Adidas');

--7)
insert into SPOT(CodeSpot,CodeCamp,Libelle)
VALUES
    ('NS3', (select CodeCamp from CAMPAGNE where Titre='Nespresso-Clooney'), 'A la maison');

--6)
insert into PROGRAMMATION
values
    ('NS3','TF1','SOIR','18/02/25');

--8)
create table SPOT2
as (select Libelle,duree from SPOT);

select * from SPOT2;

--9)
create table CLIENT
(
    numc char(6),
    nomc varchar(15),
    anneenaissc int,
    villec varchar(50)
);

insert into CLIENT
VALUES
('CLI001', 'Jean', 1975, '75006 Paris'),
('CLI002', 'Paul', 1978, '75003 Paris'),
('CLI003', 'Vincent', 1984, '94200 Evry'),
('CLI004', 'Pierre', 1970, '92400 Courbevoie'),
('CLI005', 'Daniel', 1963, '44112 Nantes');

create table EMPLOYE
(
    CodeSoc int,
    CodeEmp char(6),
    foreign key(CodeSoc) references SOCIETE(CodeSoc),
    primary key(CodeSoc,CodeEmp)
);

insert into EMPLOYE
select SOCIETE.CodeSoc,CLIENT.numc
from SOCIETE,CLIENT
where (SOCIETE.Nom='Peugeot' and CLIENT.villec like '%Paris')or(SOCIETE.Nom='Nescafé' and CLIENT.nomc='Daniel');

--10)
create view q1
as select CodeSpot from PROGRAMMATION where Media='TF1' and Datep='20/02/25';

create view q2
as select Libelle,duree from SPOT as s
join CAMPAGNE as c
on s.CodeCamp=C.CodeCamp where C.Titre='Nespresso-Clooney';

create view q3
as select CodeSpot,Libelle
from SPOT as s
join CAMPAGNE as c
on s.CodeCamp=C.CodeCamp
where Cible='MM50';

create view q4
as select A.CodeCamp,c.Titre
from CAMPAGNE as c
join (select distinct CodeCamp
from PROGRAMMATION as p
join SPOT as s
on p.CodeSpot=s.CodeSpot
where p.Moment='DEBSOIR')as A
on c.CodeCamp=A.CodeCamp;

create view q5
as select A.CodeCamp,c.Titre
from CAMPAGNE as c
join ((select distinct CodeCamp
from PROGRAMMATION as p
join SPOT as s
on p.CodeSpot=s.CodeSpot
where p.Moment='DEBSOIR')
except
(select distinct CodeCamp
from PROGRAMMATION as p
join SPOT as s
on p.CodeSpot=s.CodeSpot
where p.Moment!='DEBSOIR'))as A
on c.CodeCamp=A.CodeCamp;

create view q6
as select c.Titre
from CAMPAGNE as c
join(select s.CodeCamp
from SPOT as s
join((select CodeSpot
from PROGRAMMATION
where datep='20/02/25' and media='TF1')
except
(select CodeSpot
from PROGRAMMATION
where datep='20/02/25' and media!='TF1'))as A
on s.CodeSpot=A.CodeSpot)as B
on c.CodeCamp=B.CodeCamp;

create view q7
as select B.CodeSpot,B.Libelle,SUM(B.duree*B.Prix)
from (select s.CodeSpot,s.Libelle,s.duree,A.Prix
from spot as s
join (select Prix,CodeSpot
from PROGRAMMATION as p
join TARIF as t
on t.moment=p.moment and t.media=p.media)as A
on s.CodeSpot=A.CodeSpot)as B
group by B.CodeSpot,B.Libelle
having SUM(B.duree*B.Prix)>=40000;

create view q8
as select media,avg(prix)
from TARIF
group by media;

create view q9
as select
