drop table if exists PC,eleveur cascade;
drop type if exists Admin,elevage_type,adresse_type cascade;

create type Admin as (
    num int,
    nom varchar(50),
    age int
);

create table PC(
    num int primary key,
    adresseIP varchar(15),
    admin Admin
);

create table ADMINISTRATEUR of Admin (primary key(num));

insert into ADMINISTRATEUR
values(1,'A1',35),
(2,'A2',29);

insert into PC(num,adresseIP)
values(1,'128.12.1.4'),
(2,'128.12.1.5');

insert into PC
values(4,'128.12.1.6',(select A from ADMINISTRATEUR as A where num=1));

update PC
set admin=(select A from ADMINISTRATEUR as A where num=2) where num in(1,2);

update PC
set admin=(select A from ADMINISTRATEUR as A where num=2) where substring(adresseIP from 1 for 11) ='193.54.227.';

update PC p
set admin=NULL where (substring(adresseIP from 1 for 11) ='193.54.227.') and (p.Admin).num=2;

delete from PC p
where (p.Admin)=NULL;

create type elevage_type as (
    typeanimal varchar(20),
    ageMin int,
    nbrMax int
);

create type adresse_type as (
    nrue int,
    rue varchar(100),
    ville varchar(50),
    code_postale int
);

create table eleveur(
    numLicence int,
    elevage elevage_type,
    adresse adresse_type
);

create table elevage of elevage_type(primary key(typeanimal ,ageMin ,nbrMax));

insert into elevage
values('ovin',18,40),
('porcin',24,20),
('volailles',10,30);

insert into eleveur
values(1,null,null),
(2,null,null),
(3,null,null),
(4,null,null),
(5,null,null);

update eleveur
set elevage=(select e from elevage e where typeanimal='ovin') where numLicence=3;

update eleveur
set elevage=(select e from elevage e where typeanimal='porcin') where numLicence=2;

update eleveur e
set adresse.ville='Bordeaux' , adresse.code_postale='33000' where (e.elevage).typeanimal='ovin';

update eleveur e
set elevage=NULL where (e.adresse).ville='Paris';

create or replace function procedureParis() returns trigger as $$
declare
begin
    if((NEW.adresse).ville=='Paris' and NEW.elevage!=null)then
        raise notice 'A Paris l elevage d animaux a été interdit !';
        return null;
    else
        return NEW;
    end if;
end;
$$language 'plpgsql';

create trigger elevageParis before update or insert on eleveur for each row execute procedure procedureParis();

update eleveur e
set elevage=(select A from elevage as A where typeanimal='volailles') where (e.adresse).ville='Angers';

create or replace function procedureAngers() returns trigger as $$
declare
begin
    if((NEW.adresse).ville=='Angers' and (NEW.elevage).typeanimal!='volailles')then
        raise notice 'A Angers seul l elevage de volailles est autorisé !';
        return null;
    else
        return NEW;
    end if;
end;
$$language 'plpgsql';

create trigger elevageAngers before update or insert on eleveur for each row execute procedure procedureAngers();