#ifndef TARIH_H
#define TARIH_H


struct TARIH {
    int gun;
    int ay;
    int yil;

    int (*Tarih_artikYilMi)(int yil);
    int (*Tarih_ayKacGunCeker)(int ay, int yil);
    void (*getTarih)(struct TARIH*);
    char* (*Tarih_toString)(struct TARIH*);
    void (*Tarih_gunEkle)(struct TARIH*,int gun);
    int (*Tarih_gunFarki)(struct TARIH*, struct TARIH*);
    int (*TarihKucukEsitMi)(struct TARIH*,struct TARIH*);
    void (*delete_Tarih)(struct TARIH*);
};

typedef struct TARIH* Tarih;

Tarih new_Tarih(const char*);
Tarih Tarih_kopyala(Tarih orijinal);
int Tarih_artikYilMi(int yil);
int Tarih_ayKacGunCeker(int ay, int yil);
void getTarih(const Tarih);
char* Tarih_toString(const Tarih);
void Tarih_gunEkle(Tarih this, int gun);
int Tarih_gunFarki(Tarih cikisTarihi, Tarih varisTarihi);
int TarihKucukEsitMi(Tarih t1, Tarih t2);
void delete_Tarih(Tarih);
#endif
