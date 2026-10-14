#include "Kisi.h"
#include <stdio.h>
#include <stdlib.h>

Kisi new_Kisi(char* isim,int yas,int kalanOmur,char* uzayAraciAdi){
    Kisi this;
    this = (Kisi)malloc(sizeof(struct KISI));
    this->isim = isim;
    this->yas = yas;
    this->kalanOmur = kalanOmur;
    this->uzayAraciAdi = uzayAraciAdi;
    
    
    this->Kisi_getKalanOmur = &Kisi_getKalanOmur;
    this->Kisi_getUzayAraciAdi = &Kisi_getUzayAraciAdi;
    this->delete = &delete_Kisi;
    return this;
}


int Kisi_getKalanOmur(const Kisi this){
    return this->kalanOmur;
}

char* Kisi_getUzayAraciAdi(const Kisi this){
    return this->uzayAraciAdi;
}
void delete_Kisi(const Kisi this){
    if(this == NULL) return;
   
    free(this);
}



