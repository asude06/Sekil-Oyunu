/**       
* @file             AnaProgram
* @description      Tüm komut ve çalışma kontrolleri burda 
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             11.11.2025
* @author           Asude Elif Karaağaç
*/ 

#include <iostream>
#include <cstdlib>      
#include <ctime>        
#include <limits>       

#include "Tuval.hpp"      
#include "CiftListe.hpp"   
#include "SekilListesi.hpp" 
#include "Dikdortgen.hpp"  
#include "Ucgen.hpp"       
#include "Yildiz.hpp"      

const char* DOSYA = "sekil_kayitlari.txt";

// Rastgele sayı üretecini başlatma
void rastgeleBaslat() {
    std::srand(std::time(0));
}

int guvenliGiris(const char* mesaj) {
    int giris;
    std::cout << mesaj;
    while (!(std::cin >> giris)) {
        std::cout << "Gecersiz giris. Lutfen bir tam sayi girin: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return giris;
}

void temizCin() {
    std::cin.clear();  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void sekilYonetimi(SekilListesi* liste, Tuval* tuval) {
            // Tuş komutları için char değişkeni kullanıyoruz
            char komut = ' '; 
            
            if (!liste) {
                std::cout << "Hata: Aktif dugum bos.\n";
                return;
            }

            liste->ilkSekleGec(); 

            while (komut != 'g') { // true

                // Seçili Şekil 
                Sekil* aktif_sekil = liste->aktifSekliGetir();
                if (!aktif_sekil) {
                    std::cout << "Bu dugumde sekil kalmadi.\n";
                    break; 
                }
            
                std::cout << "\n========================================\n";
                std::cout << "    SEKIL YONETIMI (Aktif Dugum)    \n";
                std::cout << "========================================\n";

                if (aktif_sekil) {
                    std::cout << "SECILI SEKIL: Tip: " << aktif_sekil->tipiGetir() 
                              << ", Konum: (" << aktif_sekil->xGetir() << ", " 
                              << aktif_sekil->yGetir() << ")" 
                              << "\n";
                } else {
                    std::cout << "Bu listede silinecek/duzenlenecek sekil kalmadi. Ana menuye donuluyor...\n";
                    break; 
                }
            
                // Alt Menü Komutları
                std::cout << "\n--- YONETIM KOMUTLARI ---\n";
                std::cout << "(q) Onceki Sekil | (e) Sonraki Sekil | (c) Sil | (g) Listeye Don\n";
                std::cout << "\n--- HAREKET (w/a/s/d) ---\n";
                std::cout << " (w) Yukari  | (a) Sola | (s) Asagi | (d) Saga\n";
                std::cout << "Komut girin: ";
                
                std::cin >> komut;
                temizCin();

            switch (komut) {
                // GEZİNME KOMUTLARI 
                case 'q': 
                    liste->oncekiSekleGec();
                    tuval->cizdir(liste);
                    break;
                case 'e':
                    liste->sonrakiSekleGec();
                    tuval->cizdir(liste);
                    break;
                // HAREKET KOMUTLARI sekildeki tasi ile
                
                case 'w': // Yukarı Taşı 
                    if (!aktif_sekil) break;
                    aktif_sekil->tasi(aktif_sekil->xGetir(), aktif_sekil->yGetir() -1);
                    std::cout << "Sekil 1 birim yukari tasindi.\n";
                    tuval->cizdir(liste);
                    break;
                case 's': // Aşağı Taşı
                    if (!aktif_sekil) break; 
                    aktif_sekil->tasi(aktif_sekil->xGetir(), aktif_sekil->yGetir() + 1);
                    std::cout << "Sekil 1 birim asagi tasindi.\n";
                    tuval->cizdir(liste);
                    break;
                    
                case 'a': // Sola Taşı (X - 1)
                    if (!aktif_sekil) break;
                    aktif_sekil->tasi(aktif_sekil->xGetir() - 1, aktif_sekil->yGetir());
                    std::cout << "Sekil 1 birim sola tasindi.\n";
                    tuval->cizdir(liste);
                    break;
                case 'd': // Sağa Taşı (X + 1)
                    if (!aktif_sekil) break;
                    aktif_sekil->tasi(aktif_sekil->xGetir() + 1, aktif_sekil->yGetir());
                    std::cout << "Sekil 1 birim saga tasindi.\n";
                    tuval->cizdir(liste);
                    break;
                
                    // İŞLEM KOMUTLARI
                case 'c':{ // Aktif Sekli Sil                                            {
                    Sekil* aktif_sekil_oncesi = liste->aktifSekliGetir();
                    if (!aktif_sekil_oncesi) {
                        std::cout << "Silinecek sekil yok.\n";
                        break;
                    }
                
                    bool ok = liste->aktifSekliSil();
                    if (!ok) {
                        std::cout << "Silme basarisiz. Liste durumu kontrol edin.\n";
                        break;
                    }
                
                    // Silmeden sonra eski aktif_sekil artık geçersiz — tekrar al
                    Sekil* aktif_sekil_sonrasi = liste->aktifSekliGetir();
                    if (!aktif_sekil_sonrasi) {
                        std::cout << "Sekil silindi. Listede baska sekil kalmadi.\n";
                        return; 
                    } else {
                        std::cout << "Secili sekil silindi. Yeni aktif sekil belirlendi.\n";
                        tuval->cizdir(liste);
                    }
                    break;
                }
                case 'g': // Listeye Dön (Ana Menü)
                    std::cout << "Ana listeye geri donuluyor...\n";
                    return;
                    break;
                default:
                    std::cout << "Gecersiz komut. Lutfen w, a, s, d, q, e, c, g harflerinden birini girin.\n";
                    break;        
        }        
    }
}   

void programCalistir() {
    rastgeleBaslat();
    Tuval tuval;
    CiftListe anaListe;
    
    char secim;
    std::cout << "Veri Yukleme Yontemini Secin:\n";
    std::cout << "Rastgele Olustur (r) veya Dosyadan Oku (d)? [r/d]: ";
    std::cin >> secim;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Tamponu temizle
    

    const char* dosyaAdi = "sekil_kayitlari.txt"; 

    if (secim == 'r') {
        std::cout << "Rastgele 20 ana dugum olusturuluyor...\n";
        anaListe.rastgeleDugumEkle(20);

        anaListe.dosyayaKaydet(dosyaAdi);
        std::cout << "Olusturulan rastgele veriler kaydedildi.\n";

    } else if (secim == 'd') {
        std::cout << "Veriler " << dosyaAdi << " dosyasindan okunuyor...\n";
        anaListe.dosyadanYukle(dosyaAdi); 
    } else {
        std::cout << "Gecersiz secim. Bos bir liste ile baslatiliyor.\n";
        // En az bir boş düğüm ekliyoruz aktif düğüm olsun diyw
        anaListe.dugumEkle(new SekilListesi());
    }

    bool exitProgram = false;

    char komut = ' ';

    while (!exitProgram) {
        tuval.temizle();
        SekilListesi* aktifSekilListesi = anaListe.aktifSekilleriGetir();

        int aktif_sira = anaListe.aktifDugumSirasiniGetir();
        int toplam_dugum = anaListe.dugumSayisiGetir(); 
        if (aktifSekilListesi) {
            tuval.cizdir(aktifSekilListesi);
            
            // Düğüm ve Şekil Bilgisi
            std::cout << "-------------------------------------------------------------\n";
            std::cout << "DUGUM: " << aktif_sira + 1 << " / " << toplam_dugum 
                      << " (" << aktifSekilListesi->sayacGetir() << " Sekil) Aktif\n";
        } else {
            tuval.goster();
            std::cout << "Ana Liste BOS. (a) Ekle veya (q) Cikis yapin.\n";
            std::cout << "-------------------------------------------------------------\n";
        }
        std::cout << "-------------------------------------------------------------\n";
        // Komut Menüsü
        std::cout << "(w) Sonraki | (s) Onceki | (f) Liste Yonet | (c) Sil | (q) Cikis\n";
        std::cout << "Komut girin: ";
        
        if (!(std::cin >> komut)) {
            temizCin();
            break;
        }
        temizCin();

        switch (komut) {
            case 'w':
                anaListe.sonrakiDugumeGec(); 
                std::cout << "Sonraki dugume gecildi.\n";
                break;
            case 's': 
                anaListe.oncekiDugumeGec(); 
                std::cout << "Onceki dugume gecildi.\n";
                break;
            case 'f': 
                if (aktifSekilListesi) {
                    std::cout << "Sekil Yonetimi alt menusune geciliyor...\n";
                    sekilYonetimi(aktifSekilListesi,&tuval); 
                } else {
                    std::cout << "Aktif dugum olmadigi icin sekil yonetimi yapilamaz.\n";
                }
                break;
            case 'c': { // Mevcut aktif ana düğümü sil
                CiftDugum* aktifDugum = anaListe.aktifDugumuGetir();
                if (!aktifDugum) break;

                delete aktifDugum->veri;  // SekilListesi destructor ile tüm şekilleri siler
                aktifDugum->veri = nullptr;

                anaListe.aktifDugumSil(); // Aktif düğüm listeden çıkarılır ve silinir
                aktifSekilListesi = anaListe.aktifSekilleriGetir();

                std::cout << "Aktif ana dugum ve icindeki tum sekiller silindi.\n";
                break;
            }
            case 'q': //Cikis
                anaListe.dosyayaKaydet(dosyaAdi);
                std::cout << "Tum degisiklikler dosyaya kaydedildi. Program sonlandiriliyor...\n";
                exitProgram = true; 
                break;
            default:
                std::cout << "Gecersiz komut. Lutfen w, s, f, c, q harflerinden birini girin.\n";
                break;
        }
    }
}

int main(){
    programCalistir();
    return 0;
}