#ifndef UZAYARACI_H
#define UZAYARACI_H
#include "Tarih.h"
#include "Liste.h"
#include "Kisi.h"


struct UZAYARACI{
    char* aracAdi;
    char* cikisGezegeni;
    char* varisGezegeni;
    Tarih cikisTarihi;
    Tarih varisTarihi;
    double mesafe;
    int yolcu_sayisi;
    char* durum; // 0: Bekliyor, 1: Yolda, 2: Vardı, 3: İMHA
    Liste* kisilerListesi;

    char* (*UzayAraci_getAracAdi)(struct UZAYARACI*);
    char* (*UzayAraci_getCikisGezegeni)(struct UZAYARACI*);
    char* (*UzayAraci_getVarisGezegeni)(struct UZAYARACI*);
    Tarih (*UzayAraci_getCikisTarihi)(struct UZAYARACI*);
    int (*UzayAraci_getMesafe)(struct UZAYARACI*);
    int (*UzayAraci_getYolcuSayisi)(struct UZAYARACI*);
    char* (*UzayAraci_getDurum)(struct UZAYARACI*);
    void (*UzayAraci_setDurum)(struct UZAYARACI*,int);
    void (*UzayAraci_setYolcuSayisi)(struct UZAYARACI*,int);
    int (*UzayAraci_herkesOlduMu)(struct UZAYARACI*);
    void (*kalanMesafeKontrol)(struct UZAYARACI*,Liste* gezegenlerListesi);
    void (*UzayAraci_setKalanMesafe)(struct UZAYARACI*,int);
    void (*UzayAraci_setVarisTarihi)(struct UZAYARACI*, Tarih yeniTarih);
    void (*UzayAraci_ekleKisi)(struct UZAYARACI*, Kisi kisi);
    Tarih (*UzayAraci_getVarisTarihi)(struct UZAYARACI*);
    int (*UzayAraci_herkesVardiMi)(Liste* araclarListesi);
};
typedef struct UZAYARACI* UzayAraci;

UzayAraci new_UzayAraci(char* aracAdi, char* cikisGezegeni, char* varisGezegeni,Tarih cikisTarihi,int mesafe);
Tarih UzayAraci_getCikisTarihi(const UzayAraci this);
char* UzayAraci_getAracAdi(const UzayAraci this);
char* UzayAraci_getCikisGezegeni(const UzayAraci this);
char* UzayAraci_getVarisGezegeni(const UzayAraci this);
char* UzayAraci_getDurum(const UzayAraci this);
int UzayAraci_getMesafe(const UzayAraci this);
int UzayAraci_getYolcuSayisi(const UzayAraci this);
int UzayAraci_herkesOlduMu(const UzayAraci this);
void UzayAraci_setYolcuSayisi(const UzayAraci this, int yolcu_sayisi);
void UzayAraci_setDurum(const UzayAraci this, int durum);
void UzayAraci_setKalanMesafe(const UzayAraci this,int);
void kalanMesafeKontrol(UzayAraci arac,Liste* gezegenlerListesi);
void UzayAraci_ekleKisi(UzayAraci arac, Kisi kisi);
void UzayAraci_setVarisTarihi(const UzayAraci this, Tarih yeniTarih);
int UzayAraci_herkesVardiMi(Liste* araclarListesi);
Tarih UzayAraci_getVarisTarihi(const UzayAraci this);

#endif