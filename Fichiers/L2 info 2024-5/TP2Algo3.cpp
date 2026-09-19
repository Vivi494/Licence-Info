struct maillon{
    element val;
    maillon *prec;
    maillon *suiv;
};

struct liste{
    maillon *tete;
    maillon *queue;
};

void creer(liste &L){
    l.tete=nullptr;
    l.queue=nullptr;
}

void insereTete(liste &L,element e){
    maillon *m=new maillon;
    m->val=e;
    m->prec=nullptr;
    m->suiv=l.tete;
    if(estVide(L)){
        l.queue=m;
    }
    else{
        L.tete->prec=m;
    }
    L.tete=m;
}
