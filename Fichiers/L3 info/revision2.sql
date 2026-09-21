select nomnag,prenomnag
from nageur
where nomclub='ANGERS NAT SYNCHRO';

select nomnag,prenomnag
from nageur as n
join club as c
on n.nomclub=c.nclub
where Region='PAYS DE LA LOIRE';

select nomnag,prenomnag,nomclub
from nageur as n
join resultat as r
on n.numeronag=r.numeronag
where 