drop table if exists PRODUIT,PRODUIT2,VOL,PILOTE,AVION cascade;

--Exercice 1

create table PRODUIT(
    NumProd int primary key,
    Designation varchar(50),
    Prix float,
    quantite int
);

create table PRODUIT2(
    NumProd int primary key,
    Designation varchar(50),
    Prix float,
    quantite int
);

insert into PRODUIT
values (1,'1er produit',75,75),
    (2,'2e produit',100,100),
    (3,'3e produit',150,150),
    (4,'4e produit',410,9),
    (5,'5e produit',10,9);

create or replace function insertProduit2() returns void
    as
$$

Declare
    x int;
    tmp float;
    ligne cursor for select * from produit;
begin
    select into x count(NumProd) from PRODUIT;
    if x = 0 then
        insert into PRODUIT2 values(0,'Pas de produit', NULL, NULL);
    else
        for i in ligne
        loop
            if i.prix is null then
                tmp = 0;
            else
                tmp = i.prix;
            end if;
            if i.quantite>50 then
                tmp=tmp*0.3;
            else
                if i.quantite<10 and i.prix>400 then
                    tmp=tmp*1.6;
                end if;
            end if;
            insert into PRODUIT2 values(i.NumProd,UPPER(i.Designation),tmp,i.quantite);
        end loop;
    end if;
end;

$$language 'plpgsql';

select insertProduit2();

select * from PRODUIT2;

/*
PRODUIT(NumProd, Designation, Prix, quantite)
PRODUIT2(NumProd, Designation, Prix, quantite)
*/


--Exercice 2

create table AVION(
    AvNum int primary key,
    Type varchar(50)
);

create table PILOTE(
    PlNum int primary key,
    PlNom varchar(50),
    PlPrenom varchar(50)
);

create table VOL(
    VolNum int primary key,
    PlNum int,
    foreign key(PlNum) references PILOTE(PlNum),
    AvNum int,
    foreign key(AvNum) references AVION(AvNum),
    HeureDep time,
    HeureArr time
);

insert into AVION
values(1,'long courrier'),
(2,'long courrier'),
(3,'long courrier'),
(4,'long courrier'),
(5,'long courrier'),
(6,'long courrier'),
(7,'long courrier'),
(8,'long courrier'),
(9,'long courrier'),
(10,'long courrier');

insert into PILOTE
values(1,'Bruh','Michel');

insert into VOL
values(1,1,1,'03:00:00','04:00:00'),
(2,1,1,'03:00:00','02:00:00'),
(3,1,1,'03:00:00','03:00:00'),
(4,1,2,'03:00:00','04:00:00'),
(5,1,2,'03:00:00',NULL),
(6,1,3,'03:00:00','04:00:00'),
(7,1,3,'03:00:00',NULL),
(8,1,4,'03:00:00','04:00:00'),
(9,1,4,'03:00:00','05:00:00'),
(10,1,5,'03:00:00','04:00:00'),
(11,1,6,'03:00:00','04:00:00'),
(12,1,7,'03:00:00','04:00:00'),
(13,1,8,'03:00:00','04:00:00'),
(14,1,9,'03:00:00','04:00:00'),
(15,1,10,'03:00:00','04:00:00');

create or replace function MaJVol() returns void as
$$
Declare
    nbModifVol int=0;
    ligneVol cursor for select * from VOL;
begin
    for i in ligneVol
    loop
        if i.HeureArr is not null and i.HeureDep is not null and i.HeureArr>i.HeureDep then
            if i.AvNum<5 and i.AvNum>0 then
                i.HeureArr=ADDDATE(i.HeureDep,((TIMEDIFF(i.HeureArr-i.HeureDep))*0.9));
            end if;
            if i.AvNum<9 and i.AvNum>1 then
                i.HeureArr=ADDDATE(i.HeureDep,((TIMEDIFF(i.HeureArr-i.HeureDep))*0.85));
            end if;
            if i.AvNum<9 and i.AvNum>0 then
                nbModifVol=nbModifVol+1;
            end if;
        end if;
    end loop;
    raise 'Nombre de Vols modifiés : %',nbModifVol;
end;

$$language 'plpgsql';

select MaJVol();

select * from VOL;

/*
AVION(AvNum, Type)
PILOTE(PlNum, PlNom, PlPrenom)
VOL(VolNum, PlNum, AvNum, HeureDep, HeureArr)
*/