#ifndef DOSYAOKUMA_H
#define DOSYAOKUMA_H
#include "math.h"
#include "setjmp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DosyaOkuma.h"
#include "Kisi.h"         // Kisi bağlı liste yapısı
#include "UzayAraci.h"    // Uzay Aracı bağlı liste yapısı
#include "Gezegenler.h"      // Gezegen bağlı liste yapısı
#include "Liste.h"

jmp_buf jumper;

#define try do{if(!setjmp(jumper)){
#define catch }else{
#define throw longjmp(jumper,-1)
#define tryend }} while(0)
//C99 hatasından kaynaklı }}'in sağ ve solunda boşluk bırakmak lazımmış

 //    Node kisi 
 

struct DOSYA {
    char* yol;
    char* icerik;
    int (*araclariOku)(struct DOSYA*, struct LISTE*, const char*);
    int (*kisileriOku)(struct DOSYA*, struct LISTE*, const char*, struct LISTE*);
    int (*gezegenleriOku)(struct DOSYA*, struct LISTE*, const char*);
    void (*delete_Dosya)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya new_Dosya();
int gezegenleriOku(Dosya dosya,Liste* liste,const char*);
int kisileriOku(Dosya d,Liste* liste,const char*,Liste* araclarListesi);
int araclariOku(Dosya d,Liste* liste,const char*);
void delete_Dosya(Dosya);
#endif