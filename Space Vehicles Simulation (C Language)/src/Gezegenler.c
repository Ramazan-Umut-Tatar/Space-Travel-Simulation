#include "Gezegenler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Gezegen new_Gezegen(char* ad,int tur,int birGunSaati,Tarih tarih){
    Gezegen this = (Gezegen)malloc(sizeof(struct GEZEGEN));
    this->ad = ad;
    this->tur = tur;
    this->birGunSaati = birGunSaati;
    this->GezegenTarihi = tarih;
    this->yaslanmaHizi = 1.0;
    this->nufus = 0; // Başlangıçta nufus 0 olarak ayarlanır.
    this->kalanSaat = 0;
    
    this->Gezegen_getAd = &Gezegen_getAd;
    this->Gezegen_getTur = &Gezegen_getTur;
    this->Gezegen_getBirGunSaati = &Gezegen_getBirGunSaati;
    this->Gezegen_getNufus = &Gezegen_getNufus;
    this->Gezegen_setNufus = &Gezegen_setNufus;
    this->Gezegen_getTarih = &Gezegen_getTarih;
    this->Gezegen_setTarih = &Gezegen_setTarih;
    this->Gezegen_getYaslanmaHizi = &Gezegen_getYaslanmaHizi;
    this->Gezegen_setYaslanmaHizi = &Gezegen_setYaslanmaHizi;
    return this;
}

int Gezegen_getKalanSaat(Gezegen this) {
    return this->kalanSaat;
}

void Gezegen_setKalanSaat(Gezegen this, int saat) {
    this->kalanSaat = saat;
}


float Gezegen_getYaslanmaHizi(const Gezegen this){
    return this->yaslanmaHizi;
}
void Gezegen_setYaslanmaHizi(const Gezegen this,float yaslanmaHizi){
    this->yaslanmaHizi = yaslanmaHizi;
}
char* Gezegen_getAd(const Gezegen this){
    return this->ad;
}
int Gezegen_getTur(const Gezegen this){
    return this->tur;
}
int Gezegen_getBirGunSaati(const Gezegen this){
    return this->birGunSaati;
}
int Gezegen_getNufus(const Gezegen this){
    return this->nufus;
}
void Gezegen_setNufus(const Gezegen this,int nufus){
    this->nufus = nufus;
}

Tarih Gezegen_getTarih(const Gezegen this){
    return this->GezegenTarihi;
}
void Gezegen_setTarih(const Gezegen this,Tarih yeniTarih){
    this->GezegenTarihi = yeniTarih;
}

 // Verilen gezegen adını gezegenler listesinde arar ve bulursa gezegeni döndürür
    Gezegen gezegenDondur(char* gezegenAdi, Liste* gezegenlerListesi) {
        if (gezegenlerListesi == NULL) {
        printf("HATA: Gezegenler listesi NULL geldi.\n");
        return NULL;
    }


    Dugum* gecici = gezegenlerListesi->ilk;
    
    while (gecici != NULL) {
        Gezegen gezegen = (Gezegen)gecici->veri;
        
        // Gezegenin adı ile aranan adı karşılaştırıyoruz
        if (strcmp(Gezegen_getAd(gezegen), gezegenAdi) == 0) {
            return gezegen;
        }
        
        gecici = gecici->sonraki;
    }
    
    // Eğer gezegen bulunamazsa NULL döndürür
    return NULL;
}


void delete_Gezegen(Gezegen this){
    if(this == NULL) return;
    free(this->ad);
    free(this->GezegenTarihi);
    free(this);
}



