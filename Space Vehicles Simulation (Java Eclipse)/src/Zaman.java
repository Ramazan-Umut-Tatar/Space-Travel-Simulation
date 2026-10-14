/** 
* 
* @author Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
* @since  20.04.2025
* <p> 
*  Bu sınıf zaman bilgilerini tutar.
* </p> 
*/
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.List;

public class Zaman {
    private int gunSaatleri;
    private String tarih;
    
    public Zaman(int gunSaatleri, String tarih) {
        this.gunSaatleri = gunSaatleri;
        this.tarih = tarih;
    }
    
    public void saatIlerle() {
       
    }
    
	public void KalanSaat() {
		// Kalan saat hesaplama işlemi
	}
    
	public static void ZamanIleriyeAl(List<Gezegen> gezegenler,int saatSayaci) {

		  for (Gezegen gezegen : gezegenler) {
	            int gunSaatleri = gezegen.getGunSaatleri();
	            if (saatSayaci % gunSaatleri == 0 && saatSayaci != 0) {
	                gezegen.setTarih(gezegen.getTarih().plusDays(1));
	            }
	        }
		
	}
	
	
	 
	 
	 
	 
	 
	 
	
}