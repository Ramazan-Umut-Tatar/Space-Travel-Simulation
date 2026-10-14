#include "CuceGezegen.h"




CuceGezegen new_CuceGezegen(char* ad, int tur, int birGunSaati, Tarih tarih) {
    CuceGezegen this;
    this = (CuceGezegen)malloc(sizeof(struct CUCEGEZEGEN));
   
    this->super = new_Gezegen(ad, tur, birGunSaati, tarih);
    this->super->yaslanmaHizi = 0.01;

    return this;
}

void delete_CuceGezegen(CuceGezegen this){//
    if(this == NULL) return;
    delete_Gezegen(this->super);  
    free(this);
}






