#ifndef BUZDEVIGEZEGEN_H
#define BUZDEVIGEZEGEN_H
#include "Gezegenler.h"
#include "stdlib.h"
#include "stdio.h"

struct BUZDEVIGEZEGEN{

    Gezegen super;

    double (*BuzdeviGezegen_getYaslanmaHizi)(struct GEZEGEN*);
    void (*delete_BuzdeviGezegen)(struct BUZDEVIGEZEGEN*);
};
typedef struct BUZDEVIGEZEGEN* BuzdeviGezegen;

BuzdeviGezegen new_BuzdeviGezegen(char* ad, int tur, int birGunSaati, Tarih tarih);
double BuzdeviGezegen_getYaslanmaHizi(Gezegen this);
void delete_BuzdeviGezegen(BuzdeviGezegen this);
#endif