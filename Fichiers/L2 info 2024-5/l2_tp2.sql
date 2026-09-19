drop table if exists societe,campagne,spot,tarif,programmation,spot2,client,employe cascade;

create table societe
(codesoc int,
nom varchar(15) not null,
adresse char(50),
primary key(codesoc));

create table campagne
(codecamp varchar(5),
titre varchar,
codesoc int,
foreign key(codesoc) references societe(codesoc),
produit varchar,
cible varchar(4)
constraint cible check(cible in('ENF','ADO','MM50','TOUS')),
primary key(codecamp));

create table spot
(codespot char(3) primary key,
libellé varchar(50),
durée int,
codecamp varchar(5),
foreign key(codecamp) references campagne(codecamp));

create table tarif
(média varchar(7)
constraint média check(média in('TF1','FRANCE2','FRANCE3','CANAL+','M6','C8')),
moment varchar(7)
constraint moment check(moment in('JOUR','DEBSOIR','SOIR','FINS')),
prix numeric(3),
primary key(média,moment));

create table programmation
(codespot char(3),
foreign key(codespot) references spot(codespot),
média varchar(7)
constraint média check(média in('TF1','FRANCE2','FRANCE3','CANAL+','M6','C8')),
moment varchar(7)
constraint moment check(moment in('JOUR','DEBSOIR','SOIR','FINS')),
datep date,
primary key(codespot,média,moment,datep));

--1)
insert into societe
values('101','Nescafé','523 rue des grains Paris 13'),
('102','CIC','5 rue du brigand Paris 15'),
('120','Peugeot','36 avenue de la routourne Angers');

insert into campagne
values ('NE025','Nespresso-Clooney','101','Café','MM50'),
('P208P','208-Pinocchio','120','Voiture','TOUS'),
('BA75','Le monde bouge','102','Banque','MM50');

insert into spot
values ('NS1','Rencontre au bar','135','NE025'),
('NS2','Soirée','115','NE025'),
('P12','Mobile','60','BA75'),
('P13','Premier emploi','75','BA75'),
('P14','Séjour étranger','45','BA75');

insert into tarif
values ('TF1','SOIR','500'),
('TF1','DEBSOIR','400'),
('FRANCE2','JOUR','50'),
('FRANCE3','JOUR','50'),
('FRANCE3','DEBSOIR','200');

insert into programmation
values ('NS1','TF1','SOIR','2017/02/18'),
('NS1','FRANCE3','JOUR','2017/02/20'),
('NS2','TF1','DEBSOIR','2017/02/20'),
('P12','TF1','DEBSOIR','2017/02/19'),
('P13','TF1','DEBSOIR','2017/02/20'),
('P13','FRANCE3','DEBSOIR','2017/02/20');

--3)
alter table tarif
drop constraint média;

alter table tarif
add check(média in('TF1','FRANCE2','FRANCE3','CANAL+','M6','OFTV'));

insert into tarif
values('OFTV','FINS','50'),
('OFTV','SOIR','80');

--4)
update spot
set libellé='Rencontre en soirée'
where codespot='NS2';

--5)
insert into societe
values('100','Adidas',null);

--7)
insert into spot(codespot,libellé,codecamp)
select 'NS3','A la maison',codecamp
from campagne
where titre='Nespresso-Clooney';

--6)
insert into programmation
values('NS3','TF1','SOIR','2017/02/18');

--8)
create table spot2
(libellé varchar(50) primary key,
durée int);

insert into spot2
select libellé,durée
from spot;

--9)
create table client
(numc char(6) primary key,
nomc varchar(7),
anneenaissc numeric(4),
villec varchar(50));

insert into client
values('CLI001','Jean','1975','75006 Paris'),
('CLI002','Paul','1978','75003 Paris'),
('CLI003','Vincent','1984','94200 Evry'),
('CLI004','Pierre','1970','92400 Courbevoie'),
('CLI005','Daniel','1963','44112 Nantes');

create table employe
(codesoc int,
foreign key(codesoc) references societe(codesoc),
numc char(6),
foreign key(numc) references client(numc),
primary key(codesoc,numc));

insert into employe
select *
from(select codesoc from societe where nom='Nescafé')as n
cross join(select numc from client where nomc='Daniel')as d;

insert into employe
select *
from(select codesoc from societe where nom='Peugeot')as p
cross join(select numc from client where villec like '%Paris')as pa;

--10)

--1.
create view spot_tf1_20
as(select codespot
from programmation
where datep='2017/02/20' and média='TF1');

--2.
create view spot_nespresso
as(select libellé,durée
from campagne
join spot
on campagne.codecamp=spot.codecamp
where titre='Nespresso-Clooney');

--3.
create view spot_menagere
as(select codespot,libellé
from campagne
join spot
on campagne.codecamp=spot.codecamp
where cible='MM50'
order by libellé);

--4.
create view spot_debsoir
as(select distinct(spot.codecamp),titre
from campagne
join spot
on campagne.codecamp=spot.codecamp
join programmation
on spot.codespot=programmation.codespot
where moment='DEBSOIR');

--5.
create view spot_tt_debsoir
as(select distinct(spot.codecamp),titre
from campagne
join spot
on campagne.codecamp=spot.codecamp
join programmation
on spot.codespot=programmation.codespot
where moment='DEBSOIR'
except (select distinct(spot.codecamp),titre
from campagne
join spot
on campagne.codecamp=spot.codecamp
join programmation
on spot.codespot=programmation.codespot
where moment!='DEBSOIR'));

--6.
create view spot_juste_tf1
as(select titre
from campagne
join spot
on campagne.codecamp=spot.codecamp
join (select codespot
from spot_tf1_20
except select codespot
from programmation
where datep='2017/02/20' and média!='TF1')as prog
on spot.codespot=prog.codespot);

--7.
create view spot_40k
as(select spot.codespot,libellé,prix*durée as cout
from spot
join programmation
on spot.codespot=programmation.codespot
join tarif
on programmation.média=tarif.média and programmation.moment=tarif.moment
where prix*durée>=40000);

--8)
create view moy_prix
as(select média,avg(prix) as moyenne
from tarif
group by média);

--9)
create view on_all_media
as(select libellé
from .)

--2)
select * from societe;
select * from campagne;
select * from spot;
select * from tarif;
select * from programmation;
select * from spot2;
select * from client;
select * from employe;
select * from spot_tf1_20;
select * from spot_nespresso;
select * from spot_menagere;
select * from spot_debsoir;
select * from spot_tt_debsoir;
select * from spot_juste_tf1;
select * from spot_40k;
select * from moy_prix;
