#include "DosyaOkuma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Kisi.h"         // Kisi bağlı liste yapısı
#include "UzayAraci.h"    // Uzay Aracı bağlı liste yapısı
#include "Gezegenler.h"   // Gezegen bağlı liste yapısı
#include "Liste.h"


Dosya new_Dosya(){
    Dosya this;
    this = (Dosya)malloc(sizeof(struct DOSYA));

    this->yol = NULL;
    this->icerik = NULL;

    
    this->araclariOku = &araclariOku;
    this->gezegenleriOku =&gezegenleriOku;
    this->kisileriOku =&kisileriOku;
    this->delete_Dosya = &delete_Dosya;
    
    return this;
}


int araclariOku(Dosya dosya1, Liste* liste, const char* dosyaAdi) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (!dosya) {
        printf("Araclar.txt dosyasi acilamadi.\n");
        return 0;
    }

    char satir[256];
    int satirNo = 0;
    while (fgets(satir, sizeof(satir), dosya)) {
        satirNo++;

        // Satırdaki sadece boşluk, tab, \n gibi şeyleri temizleyelim
        int BoslukVarMi = 1;
        for (int i = 0; satir[i] != '\0'; i++) {
            if (satir[i] != ' ' && satir[i] != '\t' && satir[i] != '\n' && satir[i] != '\r') {
                BoslukVarMi = 0;
                break;
            }
        }

        if (BoslukVarMi) {
            printf("HATA: %s dosyasinda %d. satir tamamen bos! Dosya formati hatali.\n", dosyaAdi, satirNo);
            fclose(dosya);
            return 0;
        }

        // Satırın sonundaki newline karakterini temizle
        satir[strcspn(satir, "\r\n")] = '\0';

        char* aracAdi = strtok(satir, "#");
        char* cikisGezegeni = strtok(NULL, "#");
        char* varisGezegeni = strtok(NULL, "#");
        char* tarihStr = strtok(NULL, "#");
        char* mesafeStr = strtok(NULL, "#");

        // Eksik veri kontrolü
        if (!aracAdi || !cikisGezegeni || !varisGezegeni || !tarihStr || !mesafeStr) {
            printf("HATA: %s dosyasinda %d. satirda eksik bilgi var!\n", dosyaAdi, satirNo);
            fclose(dosya);
            return 0;
        }

        int mesafe = atoi(mesafeStr);
        Tarih cikisTarihi = new_Tarih(tarihStr);
        UzayAraci yeniArac = new_UzayAraci(strdup(aracAdi), strdup(cikisGezegeni), strdup(varisGezegeni), cikisTarihi, mesafe);
        liste->ekle_M(liste, (void*)yeniArac);
    }

    fclose(dosya);
    return 1;
}



int gezegenleriOku(Dosya dosya2,Liste* liste, const char* dosyaAdi) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (!dosya) {
        printf("Gezegenler.txt dosyasi acilamadi.\n");
        return 0;
    }

    char satir[128];
    int satirNo = 0;
    while (fgets(satir, sizeof(satir), dosya)) {
        satirNo++;

        // Boş satır kontrolü
        int BoslukVarMi = 1;
        for (int i = 0; satir[i] != '\0'; i++) {
            if (satir[i] != ' ' && satir[i] != '\t' && satir[i] != '\n' && satir[i] != '\r') {
                BoslukVarMi = 0;
                break;
            }
        }

        if (BoslukVarMi) {
            printf("HATA: %s dosyasinda %d. satir tamamen bos!\n", dosyaAdi, satirNo);
            fclose(dosya);
            return 0;
        }

        char* ad = strtok(satir, "#");
        int tur = atoi(strtok(NULL, "#"));
        int birGunSaati = atoi(strtok(NULL, "#"));
        char* tarihStr = strtok(NULL, "\n");

        // Tarih nesnesi oluştur
        Tarih tarih = new_Tarih(tarihStr);

        // Gezegen nesnesi oluştur
        Gezegen yeniGezegen = new_Gezegen(strdup(ad), tur, birGunSaati, tarih);

        // Türüne göre yaşlanma hızlarını atıyoruz.
        switch (tur) {
            case 0:
                Gezegen_setYaslanmaHizi(yeniGezegen, 1.0);
                break;
            case 1:
                Gezegen_setYaslanmaHizi(yeniGezegen, 0.1);
                break;
            case 2:
                Gezegen_setYaslanmaHizi(yeniGezegen, 0.5);
                break;
            case 3:
                Gezegen_setYaslanmaHizi(yeniGezegen, 0.01);
                break;
            default:
                printf("Bilinmeyen gezegen türü: %s\n", ad);
                return 0;
        }

        liste->ekle_M(liste, (void*)yeniGezegen);
    }

    fclose(dosya);
    return 1;
}



int kisileriOku(Dosya dosya3 ,Liste* liste, const char* dosyaAdi, Liste* araclarListesi) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (!dosya) {
        printf("Kisiler.txt dosyasi acilamadi.\n");
        return 0;
    }

    char satir[128];
    int satirNo = 0;
    while (fgets(satir, sizeof(satir), dosya)) {
        satirNo++;

        // Boş satır kontrolü
        int BoslukVarMi = 1;
        for (int i = 0; satir[i] != '\0'; i++) {
            if (satir[i] != ' ' && satir[i] != '\t' && satir[i] != '\n' && satir[i] != '\r') {
                BoslukVarMi = 0;
                break;
            }
        }

        if (BoslukVarMi) {
            printf("HATA: %s dosyasinda %d. satir tamamen bos!\n", dosyaAdi, satirNo);
            fclose(dosya);
            return 0;
        }

        char* isim = strtok(satir, "#");
        int yas = atoi(strtok(NULL, "#"));
        double kalanOmur = atof(strtok(NULL, "#"));
        char* uzayAraciAdi = strtok(NULL, "\n");

        Kisi yeniKisi = new_Kisi(strdup(isim), yas, kalanOmur, strdup(uzayAraciAdi));
        liste->ekle_M(liste, (void*)yeniKisi);

        Dugum* aracDugum = araclarListesi->ilk;
        while (aracDugum != NULL) {
            UzayAraci arac = (UzayAraci)aracDugum->veri;
            if (strcmp(UzayAraci_getAracAdi(arac), uzayAraciAdi) == 0) {
                UzayAraci_ekleKisi(arac, yeniKisi);
                break;
            }
            aracDugum = aracDugum->sonraki;
        }
    }

    fclose(dosya);
    return 1;
}





void delete_Dosya(Dosya this) {
    if (this->icerik) free(this->icerik);
    free(this);
}
