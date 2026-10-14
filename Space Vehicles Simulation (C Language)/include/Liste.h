#ifndef BAGLI_LISTE_H
#define BAGLI_LISTE_H
#include "Tarih.h"


typedef struct DUGUM {
    void* veri;
    struct DUGUM* sonraki;
} Dugum;

// Liste yapısı tanımı
typedef struct LISTE {
    Dugum* ilk;
    void (*ekle_M)(struct LISTE*,void* metin);
    void (*ekle_S)(struct LISTE*, int veri);
    void (*silListe)(struct LISTE* this);
    Dugum* (*Liste_sil)(struct LISTE*,void* arananVeri);
    void (*Liste_gezegenTarihiGuncelle)(struct LISTE*, int saat);
} Liste;

Liste* new_Liste();
void ekle_M(Liste*, void* veri);
void ekle_S(Liste*, int veri);
void silListe(Liste* this);
Dugum* Liste_sil(Liste* this, void* arananVeri);
void Liste_gezegenTarihiGuncelle(Liste* gezegenlerListesi, int saat);
#endif
