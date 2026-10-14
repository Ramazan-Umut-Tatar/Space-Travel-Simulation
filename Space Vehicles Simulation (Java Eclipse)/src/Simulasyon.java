/** 
* 
* @author Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
* @since  20.04.2025
* <p> 
*  Bu sınıf simülasyonu başlatır.Programın bütün yükü işleyişi döngüleri sistemi buradadır.
* </p> 
*/

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.io.IOException;
public class Simulasyon {
	
	
	int saatSayaci = 0;
	boolean devam = true;
	
	private Gezegen gezegenDondur(String gezegenAdi, List<Gezegen> gezegenler) {
		
		for (int i = 0; i < gezegenler.size(); i++) {
			if (gezegenler.get(i).getAdi().equals(gezegenAdi)) {
				return gezegenler.get(i);
			}
		}
		return null;
	}
	
	 public static void temizle() {
	        String os = System.getProperty("os.name").toLowerCase();
	        
	       try {
	            ProcessBuilder pb;
	            if (os.contains("win")) {
	                // Windows için cls komutu
	                pb = new ProcessBuilder("cmd", "/c", "cls");
	            } else {
	                // Unix/Linux/Mac için clear komutu
	                pb = new ProcessBuilder("clear");
	            }
	            pb.inheritIO().start().waitFor();
	        } catch (IOException | InterruptedException e) {
	            e.printStackTrace();
	        }

	 }
	
	 public  long gunFarki(LocalDate baslangic, LocalDate bitis) {
	        return ChronoUnit.DAYS.between(baslangic, bitis);
	    } 
	
	 public void baslat() {
		 
		 Scanner in = new Scanner(System.in);
		    Dosya_Okuma dosyaOkuma = new Dosya_Okuma();
		    List<Gezegen> gezegenler = new ArrayList<>();
		    gezegenler = dosyaOkuma.gezegenleriOku("Gezegenler.txt");

		    List<Kisi> kisiler = new ArrayList<>();
		    kisiler = dosyaOkuma.kisileriOku("Kisiler.txt");

		    List<Uzay_Araci> araclar = new ArrayList<>();
		    araclar = dosyaOkuma.araclarOku("Araclar.txt",kisiler);

		    long toplamSaat = 0;
		    LocalDate varisTarihi = null;
		    
		    if (saatSayaci == 0) {
		        for (Uzay_Araci arac : araclar) {
		         
		        	
		        
					LocalDate cikisTarihi = arac.getCikisTarihi();
					LocalDate gezegenTarihi = gezegenDondur(arac.getCikisGezegeni(), gezegenler).getTarih();
					 long gunFarki = gunFarki(gezegenTarihi, cikisTarihi);
					 	toplamSaat = gunFarki*gezegenDondur(arac.getCikisGezegeni(), gezegenler).getGunSaatleri();
					 	toplamSaat += arac.getMesafe();
					 long varisGunu = toplamSaat / gezegenDondur(arac.getVarisGezegeni(), gezegenler).getGunSaatleri();
					 //varisGezegenTarihi.plusDays(varisGunu);
					    varisTarihi = gezegenDondur(arac.getVarisGezegeni(), gezegenler).getTarih().plusDays(varisGunu);
					
		        	arac.setVarisTarihi(varisTarihi);
		        	
		        	
		        	
		        }
		    }		    
		    
		   while(devam) { 
			  /* 	try {
					Thread.sleep(250); // 0.25 saniye bekle
				} catch (InterruptedException e) {
					e.printStackTrace();
				}*/
		    	
		    	temizle();
		    	
		    	for (int i = 0; i < 25; i++) {		    		
		    		System.out.println();
				}
		    	
		    	for(Uzay_Araci arac: araclar) {
		    		
		    		if (arac.getDurum().trim().equals("Bekliyor") && !arac.isImha()) {
		    		    if (gezegenDondur(arac.getCikisGezegeni(), gezegenler).getTarih().equals(arac.getCikisTarihi())) {
		    		        arac.setUctuMu(true);
		    		        arac.setDurum(1); // Yolda
		    		    }
		    		}

		    	}

		    	
		    	// Gezegenler için günü artırıyoruz (her saat sayacı ile)
		    	Zaman.ZamanIleriyeAl(gezegenler, saatSayaci); //sayac gezegenlerin saati ile tam bölünüyorsa 1 gün geçin 
		    	
		        System.out.println("Gezegenler:");
		        System.out.print(" ".repeat(33));

		        for (int i = 0; i < gezegenler.size(); i++) {
		            System.out.printf("--- %s ---\t\t", gezegenler.get(i).getAdi());
		        }
		        System.out.println();

		        System.out.print("Tarih: ");
		        System.out.print(" ".repeat(26));
		        
		        for (int i = 0; i < gezegenler.size(); i++) { //gezegenin tarihini gün ay yıl olarak yazdırıyoruz
		            int gun = gezegenler.get(i).getTarih().getDayOfMonth();
		            int ay = gezegenler.get(i).getTarih().getMonthValue();
		            int yil = gezegenler.get(i).getTarih().getYear();

		           System.out.print(gun + "." + ay + "." + yil + "\t\t" );
		        }
		        
		//---------------------------------------------------------------------------------------------------NÜFUS        
		    
		        for (Gezegen gezegen : gezegenler) {
		            gezegen.setNufus(0);
		        }

		        for (Uzay_Araci arac : araclar) {
		            int yasayanKisiSayisi = 0;
		            for (Kisi kisi : arac.getKisiler()) {
		                if (kisi.getKalanOmur() > 0) {
		                    yasayanKisiSayisi++;
		                }
		            }

		            if (arac.getDurum().trim().equals("Bekliyor")) {
		                Gezegen cikisGezegeni = gezegenDondur(arac.getCikisGezegeni(), gezegenler);
		                if (cikisGezegeni != null) {
		                    cikisGezegeni.setNufus(cikisGezegeni.getNufus() + yasayanKisiSayisi);
		                }
		            } else if (arac.getDurum().trim().equals("Vardı")) {
		                Gezegen varisGezegeni = gezegenDondur(arac.getVarisGezegeni(), gezegenler);
		                if (varisGezegeni != null) {
		                    varisGezegeni.setNufus(varisGezegeni.getNufus() + yasayanKisiSayisi);
		                }
		            }
		        }



//-----------------------------------------------------------------------------------------------------------------------NÜFUS

		        // Yeni kodu buraya ekle: Nüfus güncellemeleri


		        System.out.println();
			 	
			 	System.out.print("Nüfus: ");
			 	System.out.print(" ".repeat(29));
			 
			 for(int i = 0; i < gezegenler.size(); i++) {
			 		System.out.printf("%d\t\t\t    ", gezegenler.get(i).getNufus());
			 }
		        	
		        
		        
		        System.out.println("\n\n\n\n");
		        // Araç bilgilerini yazdırma kısmı
		        System.out.println("Uzay Araçları: ");
		        System.out.print("Arac Adı: \t\t");
		        System.out.print("Durum \t\t");
		        System.out.print("Çıkış \t\t");
		        System.out.print("Varış \t\t");
		        System.out.print("Hedefe Kalan Saat \t\t");
		        System.out.println("Hedefe Varacağı Tarih ");
		        
		        for(Uzay_Araci arac : araclar) {//araç Durum sistemi 
		        	
					if (!arac.getVardiMi() && !arac.isImha() && arac.getUctuMu()) {
						arac.setDurum(1); //  Araç yolda
					} else if (arac.getVardiMi() && !arac.isImha()) {
						arac.setDurum(2); // Araç varmış
					} else if (arac.isImha()) {
						arac.setDurum(3); // Araç imha oldu
					} else if (!arac.getVardiMi() && !arac.isImha() && !arac.getUctuMu()) {
						arac.setDurum(0); // Araç bekliyor
					} 	
		        }

		        // Her saatte kişilerin kalan ömrünü 1 azaltıyoruz.
		        Iterator<Kisi> kisiIterator = kisiler.iterator();
		        while (kisiIterator.hasNext()) {
		            Kisi kisi = kisiIterator.next();
		            kisi.setKalanOmur(kisi.getKalanOmur() - 1);

		            if (kisi.getKalanOmur() <= 0) {
		                kisiIterator.remove();
		            }
		        }

		     // Araçlardaki insanları kontrol et: herkes öldüyse araç imha olsun
		        for (Uzay_Araci arac : araclar) {
		            if (!arac.isImha()) { // Zaten imha olmuşsa bakmaya gerek yok
		                boolean herkesOlmusMu = true;
		                for (Kisi kisi : arac.getKisiler()) {
		                    if (kisi.getKalanOmur() > 0) {
		                        herkesOlmusMu = false;
		                        break;
		                    }
		                }
		                if (herkesOlmusMu) {
		                    arac.setImha(true);
		                    arac.setDurum(3); // Araç imha oldu
		                }
		            }
		        }      
		        
		        // Tüm araçların varıp varmadığını kontrol et
		        boolean herkesVardimi = true;

		        for (Uzay_Araci arac : araclar) {
		            if (!arac.getVardiMi() && !arac.isImha()) { 
		                herkesVardimi = false;
		                
		                if (arac.getUctuMu()) {
		                    arac.setMesafe(arac.getMesafe() - 1);
		                    if (arac.getMesafe() <= 0) {
		                        arac.setMesafe(0);
		                        arac.setVardiMi(true);
		                        arac.setDurum(2); 
		                        arac.setUctuMu(false);
		                    }
		                }
		            }
		        }

		        
		        //Hepsi imha veya vardı ise bitir.
		        boolean herkesImhami= true;
		        for(Uzay_Araci arac : araclar) {
		        	if(!arac.isImha()) {
		        		herkesImhami = false;
		        		break;
		        	}
		        }
		        	
		        if (herkesVardimi || herkesImhami) {
		            devam = false; // Her araç varmışsa simülasyonu durdur
		        }
		        else {
	                devam = true; // Herkes imha oldu
                }
		   
//-----------------------------------------------------------------------
		        for (int i = 0; i < araclar.size(); i++) {
		            Uzay_Araci arac = araclar.get(i);
		            String cikisGezegenAdi = arac.getCikisGezegeni();
		            String varisGezegenAdi = arac.getVarisGezegeni();
		            LocalDate cikisGezegenTarihi = null;
		            LocalDate varisGezegenTarihi = null;

		            int mesafe = arac.getMesafe(); // saat cinsinden mesafe

		            // Çıkış gezegeni tarihini bul
		            for (int j = 0; j < gezegenler.size(); j++) {
		                if (gezegenler.get(j).getAdi().equals(cikisGezegenAdi)) {
		                    cikisGezegenTarihi = gezegenler.get(j).getTarih();
		                    break;
		                }
		            }

		            // Varış gezegeninin 1 gününün saati
		            int varisGezegenGunSaatleri = 24; // varsayılan
		            for (int j = 0; j < gezegenler.size(); j++) {
		                if (gezegenler.get(j).getAdi().equals(varisGezegenAdi)) {
		                    varisGezegenGunSaatleri = gezegenler.get(j).getGunSaatleri();
		                    break;
		                }
		            }

		            // Varış gezegeni tarihini bul
		            for (int j = 0; j < gezegenler.size(); j++) {
		                if (gezegenler.get(j).getAdi().equals(varisGezegenAdi)) {
		                    varisGezegenTarihi = gezegenler.get(j).getTarih();
		                    break;
		                }
		            }
		            
		           // Zaman.varisTarihi(cikisGezegenTarihi, varisGezegenTarihi);
		            
		            if (cikisGezegenTarihi != null && varisGezegenTarihi != null) {
		                
		                // Araçları yazdır
		                System.out.print(arac.getAracAdi() + "\t\t\t");
		                System.out.print(araclar.get(i).getDurum() + "\t");
		                System.out.print(arac.getCikisGezegeni() + "\t\t");
		                System.out.print(arac.getVarisGezegeni() + "\t\t");

		                if (arac.isImha()) {
		                    System.out.print("--\t\t\t\t");
		                    System.out.print("--");
		                } else {
		                    System.out.print(araclar.get(i).getMesafe() + "\t\t\t\t");
		                    System.out.printf("%02d.%02d.%d", arac.getVarisTarihi().getDayOfMonth(), arac.getVarisTarihi().getMonthValue(), arac.getVarisTarihi().getYear());
		                }
		                
		                System.out.println();
		                
		            }
		        }
		        saatSayaci++;
		    
		   }   
		}


	
}
