#include <stdio.h>
#include <stdlib.h>
#include "Tarih.h"
#include <string.h>

Tarih new_Tarih(const char* tarihStr) {
    Tarih this = (Tarih)malloc(sizeof(struct TARIH));

    // Tarih formatının "gg.aa.yyyy" şeklinde olduğunu varsayıyoruz
    char gun[3], ay[3], yil[5];

    strncpy(gun, tarihStr, 2);
    gun[2] = '\0';
    strncpy(ay, tarihStr + 3, 2);
    ay[2] = '\0';
    strncpy(yil, tarihStr + 6, 4);
    yil[4] = '\0';

    this->gun = atoi(gun);
    this->ay = atoi(ay);
    this->yil = atoi(yil);

    this->Tarih_artikYilMi = &Tarih_artikYilMi;
    this->Tarih_ayKacGunCeker =&Tarih_ayKacGunCeker;
    this-> getTarih=&getTarih;
    this-> Tarih_toString = &Tarih_toString;
    this-> Tarih_gunEkle = &Tarih_gunEkle;
    this->Tarih_gunFarki = &Tarih_gunFarki;
    this->TarihKucukEsitMi = &TarihKucukEsitMi;
    this-> delete_Tarih=& delete_Tarih;
    return this;
}

void Tarih_gunEkle(Tarih tarih, int eklenecekGun) {
    while (eklenecekGun > 0) {
        int ayGunSayisi = Tarih_ayKacGunCeker(tarih->ay, tarih->yil);

        if (tarih->gun + eklenecekGun <= ayGunSayisi) {// tarih ekleme işlemi
            tarih->gun += eklenecekGun;
            return;
        } else {
            eklenecekGun -= (ayGunSayisi - tarih->gun + 1);  // +1 eklendi
            tarih->gun = 1;
            tarih->ay++;
                
            if (tarih->ay > 12) {
                tarih->ay = 1;
                tarih->yil++;
            }
        }
    }
}


Tarih Tarih_kopyala(Tarih orijinal) {
    if (orijinal == NULL) return NULL;

    // Yeni bir Tarih nesnesi oluşturuyoruz.
    Tarih kopya = (Tarih)malloc(sizeof(struct TARIH));
    
    // Orijinal tarihin verilerini kopyalıyoruz.
    kopya->gun = orijinal->gun;
    kopya->ay = orijinal->ay;
    kopya->yil = orijinal->yil;

    return kopya;
}


int TarihKucukEsitMi(Tarih t1, Tarih t2) { //t1 çıkış tarihi t2 gezegenin tarihi
    if (t1->yil < t2->yil) return 1;// Eğer gezegenin tarihi çıkış tarihine eşit veya büyükse (t2 >= t1), araç kalkabilir
    if (t1->yil == t2->yil) {
        if (t1->ay < t2->ay) return 1;
        if (t1->ay == t2->ay) {
            if (t1->gun <= t2->gun) return 1;
        }
    }
    return 0;
}


int Tarih_gunFarki(Tarih t1, Tarih t2) {
    int toplamGun1 = t1->yil * 365 + t1->gun;
    int toplamGun2 = t2->yil * 365 + t2->gun;

    for (int i = 1; i < t1->ay; i++)
        toplamGun1 += Tarih_ayKacGunCeker(i, t1->yil);

    for (int i = 1; i < t2->ay; i++)
        toplamGun2 += Tarih_ayKacGunCeker(i, t2->yil);

    return toplamGun1 - toplamGun2;  
}



char* Tarih_toString(const Tarih this) {

    if (this == NULL) {
        return strdup("Hesaplanmamis");
    }

    char* tarihStr = (char*)malloc(11 * sizeof(char)); 
    snprintf(tarihStr, 11, "%02d.%02d.%04d", this->gun, this->ay, this->yil);
    return tarihStr;
}


int Tarih_artikYilMi(int yil) {
    return (yil % 4 == 0 && (yil % 100 != 0 || yil % 400 == 0));
}

int Tarih_ayKacGunCeker(int ay, int yil) {
    switch (ay) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return Tarih_artikYilMi(yil) ? 29 : 28;
        default: return 0;
    }
}

void getTarih(const Tarih this) {
    printf("%d.%d.%d", this->gun, this->ay, this->yil);
}

void delete_Tarih(Tarih this) {
    if(this == NULL) return;
    free(this);
}

