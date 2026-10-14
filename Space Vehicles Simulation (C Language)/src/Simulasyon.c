#include <stdio.h>
#include <stdlib.h>

#include "Simulasyon.h"
#include "DosyaOkuma.h"
#include "Liste.h"
#include "Tarih.h"
#include "UzayAraci.h"
#include "windows.h"
#include "Gezegenler.h"
#include "BuzdeviGezegen.h"
#include "CuceGezegen.h"
#include "GazdeviGezegen.h"
#include "KayacGezegen.h"
#include "Zaman.h"



Simulasyon new_Simulasyon() {
    Simulasyon this = (Simulasyon)malloc(sizeof(struct SIMULASYON));
    this->simulasyonBaslat = &simulasyonBaslat;
    this->durumKontrol = &durumKontrol;
    this->simulasyonSil = &simulasyonSil;
    return this;
}

   void simulasyonSil(const Simulasyon this){
    if(this== NULL) return;
        free(this);
   }


void durumKontrol(UzayAraci arac, Liste* gezegenlerListesi) {
    if (UzayAraci_herkesOlduMu(arac)) {
        UzayAraci_setDurum(arac, 3);  // "İMHA"
        UzayAraci_setKalanMesafe(arac, 0); // Mesafeyi sıfırla
        return; // İmha olmuş bir araçla daha fazla işlem yapmaya gerek yok.
    }

    // Hedef Gezegen Tarihini Bulalım
    char* CikisGezegeniAdi = UzayAraci_getCikisGezegeni(arac);
    Dugum* gecici = gezegenlerListesi->ilk;
    Tarih cikisGezegenininTarihi = NULL;

    // Hedef gezegeni arama işlemi
    while (gecici != NULL) {
        Gezegen gezegen = (Gezegen)gecici->veri;
        if (strcmp(Gezegen_getAd(gezegen), CikisGezegeniAdi) == 0) {
            cikisGezegenininTarihi = Gezegen_getTarih(gezegen);
            break;
        }
        gecici = gecici->sonraki;
    }

    // Hedef gezegen bulunamadıysa devam etme
    if (cikisGezegenininTarihi == NULL) {
        printf("Varis gezegeni bulunamadi!\n");
        return;
    }

    //  Tarih karşılaştırması: Eğer çıkış tarihi gezegenin tarihi ile aynıysa "Yolda" durumuna geç
    if (TarihKucukEsitMi(UzayAraci_getCikisTarihi(arac),cikisGezegenininTarihi)) {
        UzayAraci_setDurum(arac, 1);  // "Yolda"
    }

    //  Mesafe 0'a eşit mi kontrolü
    if (UzayAraci_getMesafe(arac) == 0) {
        UzayAraci_setDurum(arac, 2);  // "Vardı"
    }
}

//okuma yaparken yardımcı olsun diye //--- veya //+++ bıraktım , 

//Bunu yapma amacım hangi işlem yapılırken , kodu nereye kadar gidiyor onu kolay görmek için.




void simulasyonBaslat() {

    int VarisTarihiHesaplandiMi = 1; //varis tarihi 1 defa hesaplanır ve fonksiyon bitince değer 0 olur ve birdaha çalışmaz
    int dongudeGecenSaat =0; //döngüdeki saat (gezegenlerin bir günlük saatine bölünüp 1 gün arttırmak için kullanılır)

    Liste* kisilerListesi = new_Liste();
    Liste* araclarListesi = new_Liste();
    Liste* gezegenlerListesi = new_Liste();

    Dosya araclar = new_Dosya();
    Dosya kisiler = new_Dosya();
    Dosya gezegenler = new_Dosya();


    if (!araclar->araclariOku(araclar, araclarListesi, "Araclar.txt")) {
        printf("Araclar dosyasi okunamadi. Simulasyon sonlandiriliyor.\n");
        return;     //Araclar.txt dosya okuma ve hata kontrolü
    }

    if (!kisiler->kisileriOku(kisiler, kisilerListesi, "Kisiler.txt", araclarListesi)) {
        printf("Kisiler dosyasi okunamadi. Simulasyon sonlandiriliyor.\n");
        return;     //Kisiler.txt dosya okuma ve hata kontrolü
    }

    if (!gezegenler->gezegenleriOku(gezegenler, gezegenlerListesi, "Gezegenler.txt")) {
        printf("Gezegenler dosyasi okunamadi. Simulasyon sonlandiriliyor.\n");
        return;     //Gezegenler.txt dosya okuma ve hata kontrolü
    }    

    int herkesVardiMi = 0;
    
    while(herkesVardiMi == 0){
 
        herkesVardiMi = UzayAraci_herkesVardiMi(araclarListesi);//bunun en başta olma sebebi,
                                                                //en sonda olunca son varış yapan aracı ekrana yazamıyoruz.

        system("cls"); //ekranı temizle

        printf("Gezegenler: \n");

        printf("\t\t\t");
    
        Dugum* gecici = gezegenlerListesi->ilk; //---
        while(gecici!=NULL){

            Gezegen gezegenler = (Gezegen)gecici->veri;
            printf("--- %s ---\t\t",Gezegen_getAd(gezegenler)); //gezegen adlarını yazdırıyorum

            gecici= gecici->sonraki;            //---
        }


        printf("\nTarih \t\t\t");       //+++

        Dugum* tarih = gezegenlerListesi->ilk;
        while(tarih!=NULL){                   //gezegenlerin tarihlerini yazdırıyorum
            Gezegen gezegenler = (Gezegen)tarih->veri;
            Tarih gezegenTarihi = Gezegen_getTarih(gezegenler);
            char* tarihStr = Tarih_toString(gezegenTarihi); //"%02d.%02d.%04d şeklinde tarihleri yazdırır.
            printf("%s\t\t", tarihStr);
            free(tarihStr);
            tarih = tarih->sonraki;     //+++ 
        }

     //------------------------------------------------------------------------------------------------NÜFUS SAYIMI BAŞLANGIÇ
        Dugum* gecici2 = gezegenlerListesi->ilk; //gezegen nüfuslarını sıfır yap
        while(gecici2!=NULL){
            Gezegen gezegenler = (Gezegen)gecici2->veri;// her bir gezegen için kişi sayısı bulunurken,
            gezegenler->Gezegen_setNufus(gezegenler,0); // önce nüfusların hepsi sıfırlanır sonra kim nerede yaşıyor hesaplanır,
            gecici2 =gecici2->sonraki;                  //çünkü arttırma azaltma işlemine girsem ömrümden ömür gider.
        }

        Dugum* aracDugum = araclarListesi->ilk; 
        while (aracDugum != NULL) {             //araclar listesini gezen while başlangıcı
            UzayAraci arac = (UzayAraci)aracDugum->veri;
            int yasayanKisiSayisi = 0;
    
            // Aracın içindeki kişileri dolaşarak yaşayan kişi sayısını bul
            Dugum* kisiDugum = arac->kisilerListesi->ilk; // aracın içindeki kişilerin listesidir !!!
            while (kisiDugum != NULL) {                   // kisilerListesi değildir !!!
                Kisi kisi = (Kisi)kisiDugum->veri;
                if (kisi->kalanOmur > 0) {
                yasayanKisiSayisi++;
                }
                kisiDugum = kisiDugum->sonraki;
            }

            // Aracın durumuna göre gezegen bul ve nüfusu ekle
            if (strcmp(UzayAraci_getDurum(arac), "Bekliyor") == 0) {
                Gezegen cikisGezegeni = gezegenDondur(UzayAraci_getCikisGezegeni(arac), gezegenlerListesi);
                if (cikisGezegeni != NULL) {
                    int mevcutNufus = Gezegen_getNufus(cikisGezegeni);
                    Gezegen_setNufus(cikisGezegeni, mevcutNufus + yasayanKisiSayisi);
                }
                } else if (strcmp(UzayAraci_getDurum(arac), "Vardi   ") == 0) {
                Gezegen varisGezegeni = gezegenDondur(UzayAraci_getVarisGezegeni(arac), gezegenlerListesi);
                if (varisGezegeni != NULL) {
                    int mevcutNufus = Gezegen_getNufus(varisGezegeni);
                    Gezegen_setNufus(varisGezegeni, mevcutNufus + yasayanKisiSayisi);
                }
            }

            aracDugum = aracDugum->sonraki;//sonraki araca git
        }
        

        printf("\nNufus:\t\t\t");
        Dugum* nufus = gezegenlerListesi->ilk;
        while (nufus!=0)                        //Hesaplanan nüfusu yazdırıyoruz
        {
            Gezegen gezegenler = (Gezegen)nufus->veri;
            printf("    %d\t\t\t",Gezegen_getNufus(gezegenler));
            nufus = nufus->sonraki;
        }
     //------------------------------------------------------------------------------------------------NÜFUS SAYIMI BİTİŞ   


                                            
        printf("\n\n\n\nUzay Araclari:\n");
        printf("Arac Adi: \t\tDurum\t      Cikis\tVaris\t\t\tHedefe Kalan Saat\t\t\tHedefe Varacagi Tarih \n");

        Dugum* gecici4 = araclarListesi->ilk;
        while(gecici4!=NULL){                   //Bütün uzay araclarını gezdiğimiz while döngüsü başlangıcı 
            UzayAraci araclar = (UzayAraci)gecici4->veri;

            printf("%s\t\t\t",UzayAraci_getAracAdi(araclar));

            durumKontrol(araclar,gezegenlerListesi); //aracların DURUM kontrolü
            printf("%s\t",UzayAraci_getDurum(araclar));

            printf("%s\t",UzayAraci_getCikisGezegeni(araclar)); // cıkıs gezegenleri yazdırımı
            printf("%s\t\t\t",UzayAraci_getVarisGezegeni(araclar)); //varis gezegenleri yazdırımı 

            if (strcmp(UzayAraci_getDurum(araclar), "IMHA    ") == 0) //arac imha olmuşsa hedefe kalan saat -- yazdır 
            { 
                printf("--\t\t\t\t\t"); //arac imha olmuşsa hedefe kalan saat -- yazdır 

            }
            else //imha değilse kalan saati yazdır
            {
                kalanMesafeKontrol(araclar,gezegenlerListesi);  //kalanMesafe kontrol ediliyor
                printf("%d\t\t\t\t\t",UzayAraci_getMesafe(araclar));    //kalanMesafe yazdırımı
            }

                if (VarisTarihiHesaplandiMi) { //varis tarihi hesaplanmadıysa hesapla ve birdaha hesaplama

                   varisTarihiHesapla(araclar, gezegenDondur(UzayAraci_getVarisGezegeni(araclar), gezegenlerListesi),gezegenDondur(UzayAraci_getCikisGezegeni(araclar),gezegenlerListesi));
                    
                    if(gecici4->sonraki == NULL) 
                       VarisTarihiHesaplandiMi = 0;//bütün araçlar için varış tarihi hesaplandıysa 0 yap

                /*varış tarihi 1 kere hesaplanmalı ama döngü içerisinde bütün araçları gezip tekrardan hesaplanmaması gerekiyor.
                 Bunun çözümü if içindeki gecici4->sonraki ==NULL bloğunda yatıyor,
                 eğer aracların hepsi gezildi ise varisTarihiHesapşlandiMi ' yı 0 yapıyoruz ve false döndüğü için tekrar hesaplanmıyor*/
                }

                    if (strcmp(UzayAraci_getDurum(araclar),"IMHA    ") == 0) //arac imha olmuşsa hedefe kalan saat -- yazdır 
                    { 
                        printf("--\n"); //arac imha olmuşsa varacağı tarihi -- yazdır
                    }
                    else
                    {   char* varisTarihiStr = Tarih_toString(UzayAraci_getVarisTarihi(araclar));
                        printf("%s\n",varisTarihiStr); //varış tarihi yazdırımı  
                        free(varisTarihiStr);   
                    }
                    
                   
                omurAzalt(araclar, gezegenlerListesi); //omur azaltma işlemi
            gecici4 = gecici4->sonraki; //sonraki uzay aracına geç

        }//Bütün uzay araclarını gezdiğimiz while döngüsü BİTİŞİ
        
        

        Liste_gezegenTarihiGuncelle(gezegenlerListesi,dongudeGecenSaat);//döngü sonu gezegenlerdeki saati arttır
        dongudeGecenSaat++;//saati 1 arttır
    }
     
    // BELLEĞİ TEMİZLEME İŞLEMLERİ 
    silListe(gezegenlerListesi);
    silListe(araclarListesi);
    silListe(kisilerListesi);
    
    delete_Dosya(gezegenler);
    delete_Dosya(araclar);
    delete_Dosya(kisiler);
}


