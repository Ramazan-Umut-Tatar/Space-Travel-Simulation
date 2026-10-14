#include "KayacGezegen.h"


KayacGezegen new_KayacGezegen(char* ad, int tur, int birGunSaati, Tarih tarih){
    KayacGezegen this;
    this = (KayacGezegen)malloc(sizeof(struct KAYACGEZEGEN));

    this->super= new_Gezegen(ad,tur,birGunSaati,tarih);
    this->super->yaslanmaHizi =1.0;

    return this;
}


void delete_KayacGezegen(KayacGezegen this){
    if(this == NULL) return;
        delete_Gezegen(this->super);
        free(this);
}





