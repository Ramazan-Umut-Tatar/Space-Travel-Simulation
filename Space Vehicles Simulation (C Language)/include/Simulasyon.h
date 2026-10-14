#ifndef SIMULASYON_H
#define SIMULASYON_H
#include "Gezegenler.h"
#include "Liste.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "UzayAraci.h"

struct SIMULASYON{

    void (*simulasyonBaslat)();
    void (*durumKontrol)(UzayAraci araclar,Liste* gezegenlerListesi);
    void (*simulasyonSil)(struct SIMULASYON*);
};
typedef struct SIMULASYON* Simulasyon;

Simulasyon new_Simulasyon();
void simulasyonBaslat();
void durumKontrol(UzayAraci araclar,Liste* gezegenlerListesi);
void simulasyonSil(struct SIMULASYON*);
#endif