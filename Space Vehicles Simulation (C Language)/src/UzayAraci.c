#include "UzayAraci.h"
#include "stdlib.h"
#include "stdio.h"
#include "Tarih.h"
#include "Gezegenler.h"
#include "DosyaOkuma.h"
#include "Kisi.h"

char* aracDurumu[4] = {"Bekliyor","Yolda   ","Vardi   ","IMHA    "};


UzayAraci new_UzayAraci(char* aracAdi, char* cikisGezegeni, char* varisGezegeni,Tarih cikisTarihi,int mesafe){
    UzayAraci this;
    this = (UzayAraci)malloc(sizeof(struct UZAYARACI));
    this->aracAdi = aracAdi;
    this->cikisGezegeni = cikisGezegeni;
    this->varisGezegeni = varisGezegeni;
    this->cikisTarihi = cikisTarihi;
    this->varisTarihi =NULL;
    this->mesafe = mesafe;
    this->yolcu_sayisi = 0;
    this->kisilerListesi = new_Liste();
    this->durum = aracDurumu[0]; // Araçların başlangıç durumları bekliyor olarak atandı
    

    this->UzayAraci_getAracAdi = &UzayAraci_getAracAdi;
    this->UzayAraci_getCikisGezegeni = &UzayAraci_getCikisGezegeni;
    this->UzayAraci_getVarisGezegeni = &UzayAraci_getVarisGezegeni;
    this->UzayAraci_getCikisTarihi = &UzayAraci_getCikisTarihi;
    this->UzayAraci_getMesafe = &UzayAraci_getMesafe;
    this->UzayAraci_getYolcuSayisi = &UzayAraci_getYolcuSayisi;
    this->UzayAraci_getDurum = &UzayAraci_getDurum;
    this->UzayAraci_setDurum = &UzayAraci_setDurum;
    this->UzayAraci_setYolcuSayisi = &UzayAraci_setYolcuSayisi;
    this->UzayAraci_setKalanMesafe = &UzayAraci_setKalanMesafe;
    this->UzayAraci_getVarisTarihi = &UzayAraci_getVarisTarihi;
    this->UzayAraci_setVarisTarihi = &UzayAraci_setVarisTarihi;
    this->UzayAraci_herkesOlduMu = &UzayAraci_herkesOlduMu;
    this->UzayAraci_ekleKisi = &UzayAraci_ekleKisi;
    this->UzayAraci_herkesVardiMi = &UzayAraci_herkesVardiMi;
    return this;
}


void kalanMesafeKontrol(UzayAraci arac,Liste* gezegenlerListesi){
   

    if (UzayAraci_getMesafe(arac) > 0 && strcmp(UzayAraci_getDurum(arac),"Yolda   ") == 0) {
        UzayAraci_setKalanMesafe(arac, UzayAraci_getMesafe(arac) - 1);
    }

    // Mesafe sıfır olduysa, gezegene varmış demektir
    if (UzayAraci_getMesafe(arac) == 0) {
        UzayAraci_setDurum(arac,2); //  2 = Vardi durumudur
    }
}

void UzayAraci_setKalanMesafe(const UzayAraci this,int mesafe){
    this->mesafe = mesafe;
}

char* UzayAraci_getAracAdi(const UzayAraci this){
    return this->aracAdi;
}

char* UzayAraci_getCikisGezegeni(const UzayAraci this){
    return this->cikisGezegeni;
}
char* UzayAraci_getVarisGezegeni(const UzayAraci this){
    return this->varisGezegeni;
}
Tarih UzayAraci_getCikisTarihi(const UzayAraci this){
    return this->cikisTarihi;
}
int UzayAraci_getMesafe(const UzayAraci this){
    return this->mesafe;
}
int UzayAraci_getYolcuSayisi(const UzayAraci this){
    return this->yolcu_sayisi;
}
char* UzayAraci_getDurum(const UzayAraci this) {
    return this->durum;
}

void UzayAraci_setDurum(const UzayAraci this, int durum) {
    if (durum >= 0 && durum < 4) {
        this->durum = aracDurumu[durum];
    } else {
        printf("Boyle bir durum bulunamadi\n");
    }
}

void UzayAraci_setYolcuSayisi(const UzayAraci this, int yolcu_sayisi){
    this->yolcu_sayisi = yolcu_sayisi;
}

int UzayAraci_herkesOlduMu(UzayAraci arac) {
    if (arac == NULL || arac->kisilerListesi == NULL) {
        return 1; // Eğer arac yoksa, imha olmuş kabul ediyorum hocam
    }

    Dugum* kisiDugum = arac->kisilerListesi->ilk;
    
    while (kisiDugum != NULL) {
        Kisi kisi = (Kisi)kisiDugum->veri;
        if (Kisi_getKalanOmur(kisi) > 0) {
            return 0; // Eğer bir kişi bile yaşıyorsa, "İMHA" değil demektir.
        }
        kisiDugum = kisiDugum->sonraki;
    }
    return 1; // Herkes ölmüşse 1 döner.
}

void UzayAraci_ekleKisi(UzayAraci arac, Kisi kisi) {
    if (arac->kisilerListesi == NULL) {
        arac->kisilerListesi = new_Liste();
    }
    arac->kisilerListesi->ekle_M(arac->kisilerListesi, kisi);
}


void UzayAraci_setVarisTarihi(const UzayAraci this, Tarih yeniTarih) {
    free(this->varisTarihi);
    this->varisTarihi = yeniTarih;
}

Tarih UzayAraci_getVarisTarihi(const UzayAraci this) {
    return this->varisTarihi;
}



int UzayAraci_herkesVardiMi(Liste* araclarListesi) {
    if (araclarListesi == NULL || araclarListesi->ilk == NULL) {
        return 1;  // Liste boşsa, hepsi "İMHA" olmuş kabul ediyoruz
    }

    Dugum* aracDugum = araclarListesi->ilk;

    while (aracDugum != NULL) {
        UzayAraci arac = (UzayAraci)aracDugum->veri;

        // Eğer araç "IMHA" değilse ve mesafesi 0 değilse, doğrudan 0 döneriz.
        if (strcmp(UzayAraci_getDurum(arac), "IMHA    ") != 0 && UzayAraci_getMesafe(arac) != 0) {
            return 0;
        }

        aracDugum = aracDugum->sonraki;
    }

    return 1; // Tüm araçlar imha veya mesafe 0 ise 1 döner.
}

