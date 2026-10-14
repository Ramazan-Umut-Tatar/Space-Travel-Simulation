/** 
* 
* @author Ramazan Umut Tatar ramazan.tatar@ogr.sakarya.edu.tr
* @since  20.04.2025
* <p> 
*  Bu sınıf dosyaları okuma işlemlerini gerçekleştirir.
* </p> 
*/

import java.io.*;
import java.util.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Dosya_Okuma {

    private static final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("d.M.yyyy");

    public static List<Kisi> kisileriOku(String dosyaAdi) {
    	
    	
    	//Uzay_araci_adi#cikis_gezegeni#varis_gezegeni#cikis_tarihi#mesafe_saat_olarak  =>  A#X#Y#3.11.2022#580  arac.txt okuma mantığı
    	//isim#yas#kalan_omur#bulundugu_uzay_aracı_adi   ====> Ahmet#25#8500#A kisiler.txt okuma mantığı
    	//Gezegen_Adi#Gunun_kac_saat_oldugu#Gezegendeki_tarih    ====>  X#24#5.10.2020 gezegen.txt okuma mantığı
        List<Kisi> kisiler = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(dosyaAdi))) {
            String satir;

            while ((satir = br.readLine()) != null) {
                String[] ayirma = satir.split("#");

                String isim = ayirma[0];
                int yas = Integer.parseInt(ayirma[1]);
                int kalanOmur = Integer.parseInt(ayirma[2]);
                String uzayAraci = ayirma[3];

                kisiler.add(new Kisi(isim, yas, kalanOmur, uzayAraci));
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return kisiler;
    }

    public static List<Uzay_Araci> araclarOku(String dosyaAdi, List<Kisi> kisiler) {
        List<Uzay_Araci> araclar = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(dosyaAdi))) {
            String satir;

            while ((satir = br.readLine()) != null) {
                String[] ayirma = satir.split("#");

                String uzayAraciAdi = ayirma[0];
                String cikisGezegeni = ayirma[1];
                String varisGezegeni = ayirma[2];
                LocalDate cikisTarihi = LocalDate.parse(ayirma[3], formatter);
                int mesafeSaat = Integer.parseInt(ayirma[4]);

                Uzay_Araci a = new Uzay_Araci(uzayAraciAdi, cikisGezegeni, varisGezegeni, cikisTarihi, mesafeSaat);

                // Şimdi kişileri bu araca göre ekleyeceğiz
                List<Kisi> aracaAitKisiler = new ArrayList<>();
                for (Kisi kisi : kisiler) {
                    if (kisi.getUzayAraciAdi().equalsIgnoreCase(uzayAraciAdi)) {
                        aracaAitKisiler.add(kisi);
                    }
                }
                a.setKisiler(aracaAitKisiler);

                araclar.add(a);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return araclar;
    }

    public static List<Gezegen> gezegenleriOku(String dosyaAdi) {
        
        List<Gezegen> gezegenler = new ArrayList<>();
        
        try (BufferedReader br = new BufferedReader(new FileReader(dosyaAdi))) {
            
            String satir;
            
            while ((satir = br.readLine()) != null) {
                String[] ayir = satir.split("#");
                
                String ad = ayir[0];
                int saat = Integer.parseInt(ayir[1]);
                
                // Tarihi String olarak alma! Şimdi LocalDate yapıyoruz
                DateTimeFormatter formatter = DateTimeFormatter.ofPattern("d.M.yyyy");
                LocalDate tarih = LocalDate.parse(ayir[2], formatter);
                
                Gezegen g = new Gezegen(ad, saat, tarih);
                gezegenler.add(g);
            }
            
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        return gezegenler;
    }
}
