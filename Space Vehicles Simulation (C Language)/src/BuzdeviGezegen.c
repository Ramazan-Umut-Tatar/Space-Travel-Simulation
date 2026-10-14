#include "BuzdeviGezegen.h"

BuzdeviGezegen new_BuzdeviGezegen(char* ad, int tur, int birGunSaati, Tarih tarih){
    BuzdeviGezegen this;
    this=(BuzdeviGezegen)malloc(sizeof(struct BUZDEVIGEZEGEN));

    this->super = new_Gezegen(ad,tur,birGunSaati,tarih);
    this->super->yaslanmaHizi = 0.5;
    this->BuzdeviGezegen_getYaslanmaHizi = &BuzdeviGezegen_getYaslanmaHizi;
    return this;
}

double BuzdeviGezegen_getYaslanmaHizi(Gezegen this) {
    BuzdeviGezegen buzDev = (BuzdeviGezegen)this;
    return buzDev->super->yaslanmaHizi;
}


void delete_BuzdeviGezegen(BuzdeviGezegen this){
    if(this == NULL) return;
        delete_Gezegen(this->super);  
        free(this);
}











