#ifndef CUCEGEZEGEN_H
#define CUCEGEZEGEN_H
#include "Gezegenler.h"
#include "stdlib.h"
#include "stdio.h"

struct CUCEGEZEGEN{

    Gezegen super;
    void (*delete_CuceGezegen)(struct CUCEGEZEGEN*);
};
typedef struct CUCEGEZEGEN* CuceGezegen;

CuceGezegen new_CuceGezegen(char* ad, int tur, int birGunSaati, Tarih tarih);
void delete_CuceGezegen(const CuceGezegen this);

#endif 