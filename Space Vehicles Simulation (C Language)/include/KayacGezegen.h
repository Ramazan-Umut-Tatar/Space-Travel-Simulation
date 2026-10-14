#ifndef KAYACGEZEGEN_H
#define KAYACGEZEGEN_H
#include "Gezegenler.h"
#include "stdlib.h"
#include "stdio.h"

struct KAYACGEZEGEN{

    Gezegen super;
   
    void (*delete_KayacGezegen)(struct KAYACGEZEGEN*);

};
typedef struct KAYACGEZEGEN* KayacGezegen;

KayacGezegen new_KayacGezegen(char* ad,int tur,int birGunSaati,Tarih tarih);
void delete_KayacGezegen(KayacGezegen this);



#endif