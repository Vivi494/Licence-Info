drop table if exists NAGEUR,CLUB,CATEGORIE_EPREUVE,RESULTAT,OFFICIEL cascade;

drop sequence if exists NumNag,NumEp,NumOff cascade;

create sequence NumNag start 101;

create sequence NumEp;

create sequence NumOff;

create table CLUB(
    NClub varchar(50) primary key,
    Region varchar(100)
);

create table NAGEUR(
    NumeroNag int primary key default nextval('NumNag'),
    NomNag varchar(50),
    PrenomNag varchar(50),
    AnneedeNaissance int,
    Sexe char,
    constraint SexeCheck check (Sexe in('M','F')),
    NomClub varchar(50),
    foreign key(NomClub) references CLUB(NClub)
);

create table CATEGORIE_EPREUVE(
    NumeroEp int primary key default nextval('NumEp'),
    Type varchar(50) not null,
    constraint TypeCheck check (Type in('Parcours à sec','Propulsion technique','Technique')),
    Niveau varchar(50) not null,
    constraint NivCheck check (Niveau in('Synchro Découverte','Synchro Argent','Synchro Or'))
);

create table OFFICIEL(
    NumeroOff int primary key default nextval('NumOff'),
    NomOff varchar(50),
    PrenomOff varchar(50),
    Degre char default 'D',
    constraint DegreCheck check (Degre in('A','B','C','D')),
    Nomclub varchar(50),
    foreign key(NomClub) references CLUB(NClub)
);

create table RESULTAT(
    NumeroNag int,
    foreign key(NumeroNag) references NAGEUR(NumeroNag),
    NumeroEp int,
    foreign key(NumeroEp) references CATEGORIE_EPREUVE(NumeroEp),
    Annee int,
    NumeroOff int,
    foreign key(NumeroOff) references OFFICIEL(NumeroOff),
    Note float,
    constraint NoteCheck check (Note between 0 and 10),
    primary key(NumeroNag,NumeroEp,Annee,NumeroOff)
);

insert into CLUB
values ('Angers Nat Synchro','Pays de la Loire');

insert into NAGEUR(NomNag, PrenomNag, AnneedeNaissance, Sexe, Nomclub)
values('ROBERT','Léna',2006,'F','Angers Nat Synchro'),
    ('LECOURT','Clément',2008,'M','Angers Nat Synchro');

insert into CLUB
values('Leo Lagrange Nantes','Pays de la Loire');

insert into NAGEUR(NomNag, PrenomNag, AnneedeNaissance, Sexe, Nomclub)
values('CHAFFES','Lila',2006,'F','Angers Nat Synchro');

insert into OFFICIEL(NomOff, PrenomOff, Nomclub)
values('BOZEC','Rachel','Leo Lagrange Nantes');

insert into CATEGORIE_EPREUVE(Type, Niveau)
values('Propulsion technique','Synchro Or');

insert into RESULTAT
values(103,1,2023,1,7.8);

update OFFICIEL
set Degre='A'
where NumeroOff=1;

alter table CATEGORIE_EPREUVE
drop constraint NivCheck;

alter table CATEGORIE_EPREUVE
add constraint NivCheck check (Niveau in('Enfant','Synchro Découverte','Synchro Argent','Synchro Or'));

delete from RESULTAT
where NumeroNag=103;

delete from NAGEUR
where NumeroNag=103;

/*
table déja drop au début via drop table cascade
*/

/*NAGEUR (NumeroNag, NomNag, PrenomNag, AnneedeNaissance, Sexe, Nomclub)
CLUB (NClub, Region)
CATEGORIE_EPREUVE (NumeroEp, Type, Niveau)
RESULTAT (NumeroNag, NumeroEp, Annee, NumeroOff, Note)
OFFICIEL (NumeroOff, NomOff, PrenomOff, Degre, Nomclub)*/