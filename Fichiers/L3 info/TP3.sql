drop table if exists Segment,Salle,Poste,Logiciel,Installer cascade;

create table SEGMENT(
    indIP varchar(15) primary key,
    nomSegment varchar(50),
    nbPoste int
);

create table SALLE(
    nsalle int primary key,
    nomSalle varchar(50),
    nbPoste int,
    indIP varchar(15)
);

create table POSTE(
    nposte int primary key,
    nomPoste varchar(50),
    typePoste varchar(50),
    nsalle int,
    nblog int
);

create table LOGICIEL(
    nlog int primary key,
    nomLog varchar(50),
    dateAch date,
    version varchar(50),
    typeLog varchar(50),
    prix int,
    nbInstal int
);

create table INSTALLER(
    nposte int,
    nLog int,
    numIns int,
    dateIns date,
    delai int default null,
    primary key(nposte,nLog)
);

insert into SEGMENT
values
    ("5,168.15","l'entreprise",10);

insert into SALLE
values
    (1,"salle 1",5,"168.15"),
    (2,"salle 2",5,"168.15");

insert into POSTE
values
    (1,"poste 1","bureau",1,0),
    (2,"poste 2","bureau",1,0),
    (3,"poste 3","bureau",1,0),
    (4,"poste 4","bureau",1,0),
    (5,"poste 5","bureau",1,0),
    (6,"poste 6","bureau",2,0),
    (7,"poste 7","bureau",2,0),
    (8,"poste 8","bureau",2,0),
    (9,"poste 9","bureau",2,0),
    (10,"poste 10","bureau",2,0);

insert into LOGICIEL
values 
    (1,'Rust','01-01-1000','1.0.0','coding',150,0),
    (2,'CPP','02-02-2000','1.0.0','coding',250,0),
    (3,'PYTHON','03-03-3000','1.0.0','coding',350,0),
    (4,'OCAML','04-04-4000','1.0.0','coding',450,0),
    (5,'JAVA','05-05-5000','1.0.0','coding',550,0);

insert into INSTALLER(nposte, nLog, numIns, dateIns)
values
    (1,1,1,'01-01-1001'),
    (2,2,1,'02-02-2001'),
    (3,3,1,'03-03-3001'),
    (4,4,1,'04-04-4001'),
    (5,5,1,'05-05-5001');

create or replace function CalculTemps() returns void as
$$

declare
    curse cursor for select L.dateAch,I.dateIns,I.delai from INSTALLER as I join LOGICIEL as L on I.nLog = L.nlog FOR UPDATE OF I;
    v_dateAch LOGICIEL.dateAch %type;
    v_dateIns INSTALLER.dateIns %type;
    v_delai INSTALLER.delai %type;
begin
    for ligne in curse
    loop
        UPDATE INSTALLER set delai = ligne.dateIns - ligne.dateAch where current of curse;
        if v_dateAch>v_dateIns
        then
            raise notice 'Date d achat postérieur à la date d installaton !!!';
        end if;
        if v_dateAch is null
        then
            raise notice 'Date d achat inconnue !!!';
        end if;
        if v_dateIns is null
        then
            raise notice 'Date d installation inconnue !!!';
        end if;
    end loop;
end

$$language 'plpgsql';

select CalculTemps();

create or update function installLogSeg(int)
$$

declare
begin
end

$$language 'plpgsql';

/*
SEGMENT : indIP, nomSegment, nbPoste
SALLE : nsalle, nomSalle, nbPoste, indIP
POSTE : nposte, nomPoste, typePoste, nsalle, nblog
LOGICIEL : nlog, nomLog, dateAch, version, typeLog,prix, nbInstal
INSTALLER : nposte, nLog, numIns, dateIns, delai
*/