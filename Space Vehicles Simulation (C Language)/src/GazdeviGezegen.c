#include "GazdeviGezegen.h"


GazdeviGezegen new_GazdeviGezgen(char* ad, int tur, int birGunSaati, Tarih tarih){
    GazdeviGezegen this;
    this = (GazdeviGezegen)malloc(sizeof(struct GAZDEVIGEZEGEN));

    this->super= new_Gezegen(ad,tur,birGunSaati,tarih);
    this->super->yaslanmaHizi =0.1;

    return this;
}


void delete_GazdeviGezegen(GazdeviGezegen this){
    if(this == NULL) return;
        delete_Gezegen(this->super);
        free(this);
}

