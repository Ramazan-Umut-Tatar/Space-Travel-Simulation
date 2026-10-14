/** 
* 
* @author Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
* @since  20.04.2025
* <p> 
*  Bu sınıf kisi bilgilerini tutar.
* </p> 
*/

import java.util.ArrayList;
import java.util.List;

public class Kisi {

	String isim;
    int yas;
    int kalanOmur;
    String uzayAraciAdi;


    
    public Kisi(String isim, int yas, int kalanOmur, String uzayAraci) {
        this.isim = isim;
        this.yas = yas;
        this.kalanOmur = kalanOmur;
        this.uzayAraciAdi = uzayAraci;
    }

	public String getIsim() {
		return isim;
	}

	public void setIsim(String isim) {
		this.isim = isim;
	}

	public int getYas() {
		return yas;
	}

	public void setYas(int yas) {
		this.yas = yas;
	}

	public int getKalanOmur() {
		return kalanOmur;
	}

	public void setKalanOmur(int kalanOmur) {
		this.kalanOmur = kalanOmur;
	}

	public String getUzayAraciAdi() {
		return uzayAraciAdi;
	}

	public void setUzayAraci(String uzayAraci) {
		this.uzayAraciAdi = uzayAraci;
	}
	
	
	
}
