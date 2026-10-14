#ifndef ZAMAN_H
#define ZAMAN_H
#include "UzayAraci.h"
#include "Gezegenler.h"
#include "math.h"

struct ZAMAN {
  
void (*varisTarihiHesapla)(UzayAraci arac, Gezegen varisGezegeni,Gezegen cikisGezegeni);
void (*omurAzalt)(UzayAraci arac, Liste* gezegenlerListesi);
};
typedef struct ZAMAN* Zaman;


void varisTarihiHesapla(UzayAraci arac, Gezegen varisGezegeni,Gezegen cikisGezegeni);
void omurAzalt(UzayAraci arac, Liste* gezegenlerListesi);







#endif