/** 
* 
* @author Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
* @since  20.04.2025
* <p> 
*  Bu sınıf gezegen bilgilerini tutar.
* </p> 
*/
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Gezegen {

	 private  String adi;
	 private  LocalDate  tarih;
	 private  int gunSaatleri;
	 private int nufus;
	    
	    public Gezegen(String adi, int gunSaatleri,LocalDate tarih) {
	        this.adi = adi;
	        this.gunSaatleri = gunSaatleri;
	        this.tarih = tarih;
	        this.nufus =0;
	    }

		public String getAdi() {
			return adi;
		}

		public int getNufus() {
			return nufus;
		}
		
		public void setNufus(int nufus) {
			this.nufus = nufus;
		}
		
		public void setAdi(String adi) {
			this.adi = adi;
		}

		public LocalDate getTarih() {
			return tarih;
		}

		public void setTarih(LocalDate tarih) {
			this.tarih = tarih;
		}

		public int getGunSaatleri() {
			return gunSaatleri;
		}

		public void setGunSaatleri(int gunSaatleri) {
			this.gunSaatleri = gunSaatleri;
		}
	    
	
		public int getGun() {
		    return tarih.getDayOfMonth();
		}

		public int getAy() {
		    return tarih.getMonthValue();
		}

		public int getYil() {
		    return tarih.getYear();
		}
		
		public int setGun(int gun) {
			return tarih.getDayOfMonth();
		}

		public int setAy(int ay) {
			return tarih.getMonthValue();
		}

		public int setYil(int yil) {
			return tarih.getYear();
		}
		
		
		
		public void gezegenleriListele() {
			
			List<Gezegen> gezegenler = Dosya_Okuma.gezegenleriOku("gezegenler.txt");
			
			
			
		}
}
