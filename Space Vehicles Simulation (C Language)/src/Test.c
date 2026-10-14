#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "Liste.h"
#include "Simulasyon.h"
#include "DosyaOkuma.h"
#include "Gezegenler.h"
#include "Kisi.h"
#include "UzayAraci.h"
int main(){


        Simulasyon simulasyon = new_Simulasyon();
        simulasyon->simulasyonBaslat();
        
        simulasyonSil(simulasyon);
        
    return 0;
}






