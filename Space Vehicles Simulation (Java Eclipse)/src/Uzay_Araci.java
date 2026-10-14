/** 
* 
* @author Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
* @since  20.04.2025
* <p> 
*  Bu sınıf uzay aracı bilgilerini tutar.
* </p> 
*/

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Uzay_Araci {

private	String aracAdi;
private String cikisGezegeni;
private String varisGezegeni;
private LocalDate cikisTarihi;
private int mesafe;
private boolean imha;
private boolean uctuMu;
private boolean vardiMi;
private String Durum = "Bekliyor";
private LocalDate varisTarihi; // + getter/setter


private static String[] AracDurum = {"Bekliyor","Yolda   ","Vardı   ","İMHA    "}; // 0: bekliyor, 1: yolda, 2: vardi, 3: imha;
private List<Kisi> kisiler = new ArrayList<>();    

    public Uzay_Araci(String aracAdi, String cikisGezegeni, String varisGezegeni, LocalDate cikisTarihi, int mesafe) {
        this.aracAdi = aracAdi;
        this.cikisGezegeni = cikisGezegeni;
        this.varisGezegeni = varisGezegeni;
        this.cikisTarihi = cikisTarihi;
        this.mesafe = mesafe;
        this.imha = false;
        this.uctuMu = false;
        this.vardiMi = false;
    }

	public String getAracAdi() {
		return aracAdi;
	}

	public void setAracAdi(String adi) {
		this.aracAdi = adi;
	}

	public String getCikisGezegeni() {
		return cikisGezegeni;
	}

	public void setCikisGezegeni(String cikisGezegeni) {
		this.cikisGezegeni = cikisGezegeni;
	}

	public String getVarisGezegeni() {
		return varisGezegeni;
	}

	public void setVarisGezegeni(String varisGezegeni) {
		this.varisGezegeni = varisGezegeni;
	}

	public LocalDate getCikisTarihi() {
		return cikisTarihi;
	}

	public void setCikisTarihi(LocalDate cikisTarihi) {
		this.cikisTarihi = cikisTarihi;
	}

	public int getMesafe() {
		return mesafe;
	}

	public void setMesafe(int mesafe) {
		this.mesafe = mesafe;
	}

	public boolean isImha() {
		return imha;
	}

	public void setImha(boolean imha) {
		this.imha = imha;
	}
	
	public  boolean getKalktiMi() {
		return uctuMu;
	}
    public  void setKalktiMi(boolean uctuMu) {
    	        this.uctuMu = uctuMu;
    }
    
    public  boolean getVardiMi() {
    	        return vardiMi;
    }

	public  void setVardiMi(boolean vardiMi) {
		this.vardiMi = vardiMi;
	}

	public String getDurum() {
		return Durum;
	}

	public void setDurum(int durum) {
	    if (durum >= 0 && durum < AracDurum.length) {
	        this.Durum = AracDurum[durum];
	    } else {
	        System.out.println("Durum bulunamadı");
	    }
	}


	public  boolean getUctuMu() {
		return uctuMu;
	}

	public  void setUctuMu(boolean uctuMu) {
		this.uctuMu = uctuMu;
	}

	public List<Kisi> getKisiler() {
	    return kisiler;
	}

	public void setKisiler(List<Kisi> kisiler) {
	    this.kisiler = kisiler;
	}

	public LocalDate getVarisTarihi() {
		return varisTarihi;
	}

	public void setVarisTarihi(LocalDate varisTarihi) {
		this.varisTarihi = varisTarihi;
	}
	
	
	
}
