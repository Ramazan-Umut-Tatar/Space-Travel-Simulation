#include "Zaman.h"
#include "UzayAraci.h"
#include "Tarih.h"
#include "Gezegenler.h"
#include "Kisi.h"
#include "Liste.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"


void varisTarihiHesapla(UzayAraci arac, Gezegen varisGezegeni, Gezegen cikisGezegeni) {
    // Aracın varış tarihi bellekte yoksa oluşturulur
     if (arac->varisTarihi != NULL) {
        free(arac->varisTarihi);
        arac->varisTarihi = NULL;
    }

    // Çıkış tarihi ve çıkış gezegeninin tarihini al
    Tarih cikisTarihi = UzayAraci_getCikisTarihi(arac);

    // Varış gezegeninin tarihini kopyala
    Tarih varisTarihi = Tarih_kopyala(Gezegen_getTarih(varisGezegeni));

    // Çıkış gezegeninin tarihiyle çıkış tarihi arasındaki farkı hesapla
    int toplamGunFarki = Tarih_gunFarki(cikisTarihi, varisTarihi);

    // Toplam gün farkını çıkış gezegeninin bir günlük zaman dilimiyle çarp
    int toplamSaat = toplamGunFarki * Gezegen_getBirGunSaati(cikisGezegeni);

    // Kalan mesafeyi ekle
    toplamSaat += UzayAraci_getMesafe(arac);

    // Toplam saati varış gezegeninin bir günlük zaman dilimine böl ve gün farkını bul
    int eklenenGun = toplamSaat / Gezegen_getBirGunSaati(varisGezegeni);

    // Varış tarihine bu gün farkını ekle
    Tarih_gunEkle(varisTarihi, eklenenGun);

    // Hesaplanan tarihi uzay aracına set et
    UzayAraci_setVarisTarihi(arac, varisTarihi);
}




void omurAzalt(UzayAraci arac, Liste* gezegenlerListesi) {
    Dugum* kisiDugum = arac->kisilerListesi->ilk;
    
    while (kisiDugum != NULL) {
        Kisi kisi = (Kisi)kisiDugum->veri;
        float yaslanmaHizi = 0.0;
        
        // Durumu kontrol et
        if (strcmp(UzayAraci_getDurum(arac), "Bekliyor") == 0) {
            // Bekliyor durumunda, çıkış gezegeninin türüne göre azaltma
            Gezegen cikisGezegeni = gezegenDondur(UzayAraci_getCikisGezegeni(arac), gezegenlerListesi);
            if (cikisGezegeni != NULL) {
                yaslanmaHizi = Gezegen_getYaslanmaHizi(cikisGezegeni);
            }
        } else if (strcmp(UzayAraci_getDurum(arac), "Yolda   ") == 0) {
            // Yolda durumu, kişilerin ömrünü 1 saat azalt
            yaslanmaHizi = 1.0;
        } else if (strcmp(UzayAraci_getDurum(arac), "Vardi   ") == 0) {
            // Vardı durumunda, varış gezegeninin türüne göre azaltma
            Gezegen varisGezegeni = gezegenDondur(UzayAraci_getVarisGezegeni(arac),gezegenlerListesi);
            if (varisGezegeni != NULL) {
                yaslanmaHizi = Gezegen_getYaslanmaHizi(varisGezegeni);
            }
        }   
        
        // Ömrü azalt
        if (kisi->kalanOmur > 0) {
            kisi->kalanOmur -= yaslanmaHizi;
            if (kisi->kalanOmur < 0) {
                kisi->kalanOmur = 0; // Negatif olmaması için sıfıra ayarlıyoruz
            }
        }
        
        kisiDugum = kisiDugum->sonraki;
    }
}























