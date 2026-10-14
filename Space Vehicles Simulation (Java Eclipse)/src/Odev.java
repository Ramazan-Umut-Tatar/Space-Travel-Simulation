/** 
* 
* @author Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
* @since  20.04.2025
* <p> 
*  Bu sınıf simülasyonu başlatır.
* </p> 
*/

import java.util.List;

public class Odev {

	public static void main(String[] args) {
        // Simülasyonu başlat
		
		 List<Kisi> kisiler = Dosya_Okuma.kisileriOku("Kisiler.txt");
		 	Simulasyon simulasyon = new Simulasyon();       
		 	Dosya_Okuma.kisileriOku("Kisiler.txt");
		 	Dosya_Okuma.araclarOku("Araclar.txt",kisiler);
		 	Dosya_Okuma.gezegenleriOku("Gezegenler.txt");
        
       
       	simulasyon.baslat();		
	}
}
