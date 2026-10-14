#ifndef GEZEGEN_H
#define GEZEGEN_H
#include "Tarih.h"
#include "Liste.h"

struct GEZEGEN{
    char* ad;
    int tur;
    int birGunSaati;
    Tarih GezegenTarihi;
    int nufus;
    float yaslanmaHizi;
    int kalanSaat;

    char* (*Gezegen_getAd)(struct GEZEGEN*);
    int (*Gezegen_getTur)(struct GEZEGEN*);
    int (*Gezegen_getBirGunSaati)(struct GEZEGEN*);
    int (*Gezegen_getNufus)(struct GEZEGEN*);
    void (*Gezegen_setNufus)(struct GEZEGEN*,int );
    Tarih (*Gezegen_getTarih)(struct GEZEGEN*);
    void (*Gezegen_setTarih)(struct GEZEGEN*, Tarih);
    float (*Gezegen_getYaslanmaHizi)(struct GEZEGEN*);
    void (*Gezegen_setYaslanmaHizi)(struct GEZEGEN*, float);
    int (*Gezegen_getKalanSaat)(struct GEZEGEN*);
    void (*Gezegen_setKalanSaat)(struct GEZEGEN*, int saat);

    void (*delete_Gezegen)(struct GEZEGEN*);

};
typedef struct GEZEGEN* Gezegen;

Gezegen new_Gezegen(char* ad,int tur,int birGunSaati,Tarih tarih);
char* Gezegen_getAd(const Gezegen);
int Gezegen_getTur(const Gezegen);
int Gezegen_getBirGunSaati(const Gezegen);
int Gezegen_getNufus(const Gezegen);
void Gezegen_setNufus(const Gezegen, int nufus);
Tarih Gezegen_getTarih(const Gezegen);
void Gezegen_setTarih(const Gezegen,Tarih tarih);
Gezegen gezegenDondur(char* gezegenAdi, Liste* gezegenlerListesi);
float Gezegen_getYaslanmaHizi(const Gezegen);
void Gezegen_setYaslanmaHizi(const Gezegen, float yaslanmaHizi);
int Gezegen_getKalanSaat(Gezegen this);
void Gezegen_setKalanSaat(Gezegen this, int saat);

void delete_Gezegen(const Gezegen);








#endif