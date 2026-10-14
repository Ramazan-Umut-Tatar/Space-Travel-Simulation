#ifndef KISI_H
#define KISI_H


struct KISI{
    char* isim;
    int yas;
    float kalanOmur;
    char* uzayAraciAdi;

   
    int (*Kisi_getKalanOmur)(struct KISI*);
    char* (*Kisi_getUzayAraciAdi)(struct KISI*);
    void (*delete)(struct KISI*);
    
};
typedef struct KISI* Kisi;


Kisi new_Kisi(char*,int,int,char*);
int Kisi_getKalanOmur(const Kisi);
void delete_Kisi(const Kisi);
char* Kisi_getUzayAraciAdi(const Kisi);
//soldaki parametre döndürülen nesneye işaret eder,sağdaki parametre ise fonksiyonun çağrıldığı nesneye işaret eder.







#endif