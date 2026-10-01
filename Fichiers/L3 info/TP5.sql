DROP TABLE if exists PERSONNE, SOCIETE, SALAIRE, ACTION, HISTO_Annuel_ACTIONNAIRE;
DROP TYPE if exists TPERSONNE, TSOCIETE;


CREATE TYPE TPERSONNE AS (
    NumSecu integer,
    Nom varchar(50),
    Prenom varchar(50),
    Sexe char, --F M
    dateNaiss Date
);

CREATE TYPE TSOCIETE AS (
    CodeSoc int,
    NonSoc varchar(50),
    Adresse varchar(50)
);

CREATE TABLE PERSONNE OF TPERSONNE (PRIMARY KEY (NumSecu));

CREATE TABLE SOCIETE OF TSOCIETE (PRIMARY KEY (CodeSoc));

CREATE TABLE SALAIRE (
    Personne TPERSONNE,
    Societe TSOCIETE,
    Salaire real,
    PRIMARY KEY(Personne, Societe)
);

CREATE TABLE ACTION (
    Personne TPERSONNE,
    Societe TSOCIETE,
    dateAct date,
    NbrAct int,
    typeAct char -- Achat : A, Vente : V
    CONSTRAINT ConsTypeAct CHECK ( typeAct = 'A' or typeAct = 'V'),
    PRIMARY KEY (Personne, Societe, dateAct)
);

INSERT INTO PERSONNE VALUES 
(501, 'J', 'Victor', 'M', '12-07-2006'),
(502, 'D', 'Ben', 'M', '05-05-2005'),
(503, 'D', 'Dupond', 'M', '06-06-1996');

INSERT INTO SOCIETE VALUES 
(1, 'Intel', 'a1'),
(2, 'AMD', 'g4'),
(3, 'RedHat', 'r8');

INSERT INTO SALAIRE VALUES 
( (SELECT P FROM PERSONNE P WHERE P.NumSecu = 501), (SELECT S FROM SOCIETE S WHERE S.CodeSoc = 2), 1478);


INSERT INTO ACTION VALUES ( 
    (SELECT P FROM PERSONNE P WHERE P.NumSecu = 501),
    (SELECT S FROM SOCIETE S WHERE S.CodeSoc = 2),
    '25-09-2026',
    5,
    'A'
);

CREATE TABLE HISTO_Annuel_ACTIONNAIRE (
    Personne TPERSONNE,
    Societe TSOCIETE,
    Annee int,
    NbrActTotal int,
    Nbr_Achat int,
    Nbr_vente int
    --PRIMARY KEY (Personne, Societe, Annee)
);

create or replace function procAction() returns trigger as
$$
declare
    count int;
    achat int;
    vente int;
begin
    select into count count(Personne) from HISTO_Annuel_ACTIONNAIRE H
    where(NEW.Personne).NumSecu=(H.Personne).NumSecu
        and (NEW.Societe).CodeSoc=(H.Societe).CodeSoc
        and extract(year from(NEW.dateAct)) = H.Annee;

    if(NEW.typeAct='A')then
        achat=NEW.NbrAct;
        vente=0;
    else
        achat=0;
        vente=NEW.NbrAct;
    end if;

    if count = 0 then
        insert into HISTO_Annuel_ACTIONNAIRE values(NEW.Personne,NEW.Societe,extract(year from(NEW.dateAct)),NEW.NbrAct,achat,vente);
    else
        update HISTO_Annuel_ACTIONNAIRE H set NbrActTotal=NbrActTotal+NEW.NbrAct,Nbr_Achat=Nbr_Achat+achat,Nbr_vente=Nbr_vente+vente 
        where (NEW.Personne).NumSecu=(H.Personne).NumSecu
            and (NEW.Societe).CodeSoc=(H.Societe).CodeSoc
            and extract(year from(NEW.dateAct)) = H.Annee;
    end if;
    return NEW;
end;
$$ language 'plpgsql';

create trigger insertAction before insert on action for each row execute procedure procAction();

INSERT INTO ACTION VALUES ( 
    (SELECT P FROM PERSONNE P WHERE P.NumSecu = 502),
    (SELECT S FROM SOCIETE S WHERE S.CodeSoc = 2),
    '23-09-2026',
    3,
    'V'
);


INSERT INTO ACTION VALUES ( 
    (SELECT P FROM PERSONNE P WHERE P.NumSecu = 502),
    (SELECT S FROM SOCIETE S WHERE S.CodeSoc = 2),
    '25-09-2026',
    3,
    'V'
);


INSERT INTO ACTION VALUES ( 
    (SELECT P FROM PERSONNE P WHERE P.NumSecu = 502),
    (SELECT S FROM SOCIETE S WHERE S.CodeSoc = 2),
    '26-09-2026',
    43,
    'A'
);