#ifndef GAZDEVIGEZEGEN_H
#define GAZDEVIGEZEGEN_H
#include "Gezegenler.h"
#include "stdlib.h"
#include "stdio.h"

struct GAZDEVIGEZEGEN{

    Gezegen super;
   
    void (*delete_GazdeviGezegen)(struct GAZDEVIGEZEGEN*);
};
typedef struct GAZDEVIGEZEGEN* GazdeviGezegen;

GazdeviGezegen new_GazdeviGezgen(char* ad, int tur, int birGunSaati, Tarih tarih);
void delete_GazdeviGezegen(GazdeviGezegen this);




#endif