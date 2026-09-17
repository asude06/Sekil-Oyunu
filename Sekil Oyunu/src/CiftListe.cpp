/**       
* @file             CiftListe
* @description      CiftListe metotları, düğüm işlem fonksiyonları
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             15.11.2025
* @author           Asude Elif Karaağaç
*/ 


#include "CiftListe.hpp"
#include <iostream>
#include <fstream> //dosya işlemleri
#include <cstdlib> // Rastgelelik için
#include <sstream>

#include "Dikdortgen.hpp"
#include "Ucgen.hpp"
#include "Yildiz.hpp"

CiftListe::CiftListe(){
    ilk = 0;
    son = 0;
    aktif = 0;
    dugumSayisi = 0;
}

CiftListe::~CiftListe(){
    
    CiftDugum* gec = ilk;
    while (gec != nullptr) {
        CiftDugum* sonraki = gec->sonraki;

        // SekilListesi ve içindeki Sekil nesnelerini siler
        if (gec->veri) {
            delete gec->veri;  
            gec->veri = nullptr;
        }
        delete gec;
        gec = sonraki;
    }
    ilk = nullptr;
    aktif = nullptr;
    dugumSayisi = 0;
}

void CiftListe::dugumEkle(SekilListesi* yeniListe){
    CiftDugum* yeniDugum = new CiftDugum(yeniListe); // ynei dugumun verisi yeniListeden geliyor

    yeniDugum->sonraki = 0;
    yeniDugum->onceki = 0;

    if(ilk == 0){
        ilk = yeniDugum;
        son = yeniDugum;
        aktif = yeniDugum;
    }
    else{       
        son->sonraki = yeniDugum; 
        yeniDugum->onceki = son; 
        son = yeniDugum; 
    }
    dugumSayisi++;

    if(yeniListe)
        yeniListe->setSahipCiftListe(this);
}

void CiftListe::sonrakiDugumeGec(){
    if(aktif==0){
        std::cout << "Liste bos, gezinme yapilamiyor.\n";
        return;
    }
    if(aktif->sonraki!=0){
        aktif = aktif->sonraki;
    }
    else{
        aktif = ilk;
    }
    std::cout << "Aktif dugum sonraki konuma tasindi.\n";
}

void CiftListe::oncekiDugumeGec(){
    if(aktif==0){
        std::cout << "Liste bos, gezinme yapilamiyor.\n";
        return;
    }

    if(aktif->onceki != 0){
        aktif = aktif->onceki;
    }
    else{
        CiftDugum* gec = ilk;
        
        while(gec -> sonraki != 0){
            gec = gec->sonraki;
        }
        aktif = gec;
    }
    std::cout << "Aktif dugum onceki konuma tasindi.\n";
}

SekilListesi* CiftListe::aktifSekilleriGetir() const {
    if (aktif) {
        return aktif->veri;
    }
    return 0;
}

bool CiftListe::aktifDugumSil() {
    if (!aktif) return false;

    CiftDugum* silinecek = aktif;

    // Aktif işaretçi güncelle
    if (aktif->sonraki)
        aktif = aktif->sonraki;
    else
        aktif = aktif->onceki;

    // Düğümü listeden çıkardık
    if (silinecek->onceki) silinecek->onceki->sonraki = silinecek->sonraki;
    else ilk = silinecek->sonraki;

    if (silinecek->sonraki) silinecek->sonraki->onceki = silinecek->onceki;
    else son = silinecek->onceki;

    delete silinecek;
    dugumSayisi--;

    return true;
}

char rastgeleKarakter(){
                static const char havuz[] = { '#', '@', '*', '+', 'X', '%', '&', '$', 'O' };
                int boyut = sizeof(havuz) / sizeof(havuz[0]);
                return havuz[ std::rand() % boyut ];
}

void CiftListe::rastgeleDugumEkle(int adet){
    for(int i=0; i<adet; ++i){
        SekilListesi* yeniListe = new SekilListesi();
        yeniListe->setSahipCiftListe(this);
        
        int sekilAdedi = (std::rand() % 6) + 2; // 2 ile 7 arası

        for(int j=0; j < sekilAdedi; ++j){
            int tip = std::rand() % 3; // 0: Dikdortgen, 1: Ucgen, 2: Yildiz
            int z = std::rand() % 100; // Öncelik
            char kar = rastgeleKarakter();

            Sekil* yeniSekil;

            if (tip == 0) { // Dikdörtgen
                int genislik = std::rand() % 10 + 3;
                int yukseklik = std::rand() % 5 + 2;
                int x = std::rand() % (80 - genislik); // sağ sınır
                int y = std::rand() % (25 - yukseklik); // alt sınır
                yeniSekil = new Dikdortgen(x, y, z, kar, genislik, yukseklik);
            } 
            else if(tip==1){ // Üçgen
                int boyut = std::rand() % 8 + 3;
                int x = std::rand() % (80 - boyut); // taban taşmasın
                int y = std::rand() % (25 - boyut); // alt sınır
                yeniSekil = new Ucgen(x, y, z, kar, boyut);
            } 
            else{ // Yıldız
                int boyut = std::rand() % 8 + 3;
                int yaricap = boyut / 2;
                int x = yaricap + std::rand() % (80 - boyut); // sol ve sağ sınır
                int y = yaricap + std::rand() % (25 - boyut); // üst ve alt sınır
                yeniSekil = new Yildiz(x, y, z, kar, boyut);
            }

            yeniListe->ekle(yeniSekil);
        }
        dugumEkle(yeniListe);
    }
}

void CiftListe::dosyayaKaydet(const char* dosyaAdi) const {
    std::ofstream dosya(dosyaAdi);
    if(!dosya.is_open()){
        std::cerr << "HATA: Dosya acilamadi: " << dosyaAdi << std::endl;
        return;
    }

    CiftDugum* gec = ilk;
    while(gec!=0){
        dosya << "---YENI_DUGUM---\n";
        gec->veri->listeyiKaydet(dosya);
        gec = gec->sonraki;
    }
    dosya.close();
    std::cout << "Tum veriler " << dosyaAdi << " dosyasina basariyla kaydedildi.\n";
}

void CiftListe::dosyadanYukle(const char* dosyaAdi){
    std::ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        std::cout << "Dosya acilamadi!\n";
        return;
    }

    std::string satir;
    SekilListesi* yeniListe = nullptr;

    while (std::getline(dosya, satir)) {
        if (satir == "---YENI_DUGUM---") {
            if (yeniListe && yeniListe->sayacGetir() > 0)
                dugumEkle(yeniListe);
            yeniListe = new SekilListesi();
        } else {
            std::istringstream ss(satir);
            std::string tip;
            ss >> tip;

            if (tip == "Dikdortgen") {
                int x, y, z, g, yk;
                char kar;
                ss >> x >> y >> z >> kar >> g >> yk;
                Sekil* s = new Dikdortgen(x, y, z, kar, g, yk);
                yeniListe->ekle(s);
            } 
            else if (tip == "Ucgen") {
                int x, y, z, boyut;
                char kar;
                ss >> x >> y >> z >> kar >> boyut;
                Sekil* s = new Ucgen(x, y, z, kar, boyut);
                yeniListe->ekle(s);
            } 
            else if (tip == "Yildiz") {
                int x, y, z, boyut;
                char kar;
                ss >> x >> y >> z >> kar >> boyut;
                Sekil* s = new Yildiz(x, y, z, kar, boyut);
                yeniListe->ekle(s);
            }
        }
    }

    if (yeniListe && yeniListe->sayacGetir() > 0)
        dugumEkle(yeniListe);

    dosya.close();
}



// Aktif düğümün listedeki 0 tabanlı sırasını bulur.
int CiftListe::aktifDugumSirasiniGetir() const {
    if (aktif == nullptr) {
        return -1; // Liste boş
    }
    
    int sayac = 0;
    CiftDugum* mevcut = ilk;
    
    while (mevcut != nullptr) {
        if (mevcut == aktif) {
            return sayac; // Aktif düğüm bulundu, sırayı döndür
        }
        mevcut = mevcut->sonraki;
        sayac++;
    }
    
    // Aktif düğüm listeye ait değilse 
    return -1; 
}

int CiftListe::dugumSayisiGetir() const { 
        return dugumSayisi; 
}

void CiftListe::dugumSil(SekilListesi* liste) {
    CiftDugum* gec = ilk;

    while (gec) {
        if (gec->veri == liste) {
            // Düğümü listeden çıkar
            if (gec->onceki) gec->onceki->sonraki = gec->sonraki;
            else ilk = gec->sonraki;

            if (gec->sonraki) gec->sonraki->onceki = gec->onceki;
            else son = gec->onceki;

            if (aktif == gec) aktif = gec->sonraki ? gec->sonraki : gec->onceki;

            delete gec;
            dugumSayisi--;
            return; 
        }
        gec = gec->sonraki;
    }
}

CiftDugum* CiftListe::aktifDugumuGetir() const{
    return aktif;
}