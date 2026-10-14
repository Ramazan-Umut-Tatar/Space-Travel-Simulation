#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liste.h"
#include "Gezegenler.h"


// Dugum oluşturma fonksiyonu
Dugum* new_Dugum(char* veri) {
    Dugum* this = (Dugum*)malloc(sizeof(Dugum));
    this->veri = strdup(veri);  // Veri kopyalanır
    this->sonraki = NULL;
    return this;
}

// Liste oluşturma fonksiyonu
Liste* new_Liste() {
    Liste* this = (Liste*)malloc(sizeof(Liste));
    this->ilk = NULL;
    this->ekle_M = &ekle_M;
    this->ekle_S = &ekle_S;
    this->silListe = &silListe;
    return this;
}

// metin ekleme fonksiyonu
void ekle_M(Liste* liste, void* veri) {
    Dugum* yeniDugum = (Dugum*)malloc(sizeof(Dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;

    if (liste->ilk == NULL) {
        liste->ilk = yeniDugum;
    } else {
        Dugum* gecici = liste->ilk;
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniDugum;
    }
}



void ekle_S(Liste* this, int veri) {
    // Bellekte yer ayırıp, tam sayı değerini metin formatına çeviriyorum
    char* kopyaVeri = (char*)malloc(12); 
    if (kopyaVeri == NULL) {
        printf("Bellek tahsis edilemedi.\n");
        return;
    }
    sprintf(kopyaVeri, "%d", veri);  // Tam sayı değeri string'e çevrildi

    // Yeni düğüm oluştur
    Dugum* yeni = (Dugum*)malloc(sizeof(Dugum));
    yeni->veri = kopyaVeri;
    yeni->sonraki = NULL;

    // Liste boşsa, ilk eleman olarak ekle
    if (this->ilk == NULL) {
        this->ilk = yeni;
    } else {
        // Son düğümü bul ve ekle
        Dugum* gecici = this->ilk;
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
}



void Liste_gezegenTarihiGuncelle(Liste* gezegenlerListesi, int saatSayaci) {
    if (gezegenlerListesi == NULL) return;

    Dugum* gezegenDugum = gezegenlerListesi->ilk;

    while (gezegenDugum != NULL) {
        Gezegen gezegen = (Gezegen)gezegenDugum->veri;
        int gunSaatleri = Gezegen_getBirGunSaati(gezegen);//gezegenin 1 gününün kaç saat olduğunu alıyoruz


        if (saatSayaci % gunSaatleri == 0 && saatSayaci!=0) { //saat sayacı gezegeninin 1 gunluk saatine bölünürse gün 1 artar
            Tarih gezegenTarihi = Gezegen_getTarih(gezegen);
            
            Tarih_gunEkle(gezegenTarihi, 1);
            Gezegen_setTarih(gezegen, gezegenTarihi);

        }

        gezegenDugum = gezegenDugum->sonraki;
    }
}








Dugum* Liste_sil(Liste* this, void* arananVeri) {
    if (this->ilk == NULL) return NULL;

    Dugum* gecici = this->ilk;
    Dugum* onceki = NULL;

    while (gecici != NULL) {
        if (gecici->veri == arananVeri) {
            if (onceki == NULL) {
                // İlk düğümü siliyoruz
                this->ilk = gecici->sonraki;
            } else {
                // Ortada veya sondaki düğümü siliyoruz
                onceki->sonraki = gecici->sonraki;
            }
            Dugum* sonraki = gecici->sonraki;
            free(gecici->veri);
            free(gecici);
            return sonraki; // Silinen düğümden sonrakini döndür
        }
        onceki = gecici;
        gecici = gecici->sonraki;
    }
    return NULL; 
}



void silListe(Liste* this) { //BağlıListeliste bellek iade fonksiyonu
    Dugum* gecici = this->ilk;
    while (gecici != NULL) {
        Dugum* silinecek = gecici;
        gecici = gecici->sonraki;

        if (silinecek->veri != NULL) {
            free(silinecek->veri);
        }
        free(silinecek);
    }
    this->ilk = NULL;
}




