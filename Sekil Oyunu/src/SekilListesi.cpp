/**       
* @file             Sekil Listesi
* @description      SekilListesi metotları, Tüm sekilleri tutacak, sekillerin işlem fonksiyonları
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             15.11.2025
* @author           Asude Elif Karaağaç
*/ 

#include "SekilListesi.hpp"
#include <iomanip>

#include "Dikdortgen.hpp"
#include "Yildiz.hpp"
#include "Ucgen.hpp"
#include "CiftListe.hpp"

class CiftListe;

SekilListesi::SekilListesi() {
    ilk = nullptr;
    elemanSayisi = 0;
    aktifSekilGostericisi = nullptr;
    sahipCiftListe = nullptr;
}

SekilListesi::~SekilListesi(){
    TekDugum* gec = ilk;
    
    while(gec){
        TekDugum* silinecek = gec;
        gec= gec->sonraki;

        if(silinecek->veri){
            delete silinecek->veri;
            silinecek->veri = nullptr;
        }
        
        delete silinecek;
    }
    ilk = nullptr;
    aktifSekilGostericisi = nullptr;
}

void SekilListesi::ekle(Sekil* yeniSekil){
    TekDugum* yeniDugum = new TekDugum(yeniSekil);
    
    if(!ilk){
        ilk = yeniDugum;
        
    }
    else{
        TekDugum* gec = ilk;
        while (gec->sonraki != 0){
            gec=gec->sonraki;
        }
        gec->sonraki = yeniDugum;
    }
    elemanSayisi++;
}

Sekil* SekilListesi::sekilGetir(int index) const {
    if(index < 0 || index >= elemanSayisi){
        return 0;
    }
    TekDugum* gec = ilk;
    for(int i=0; i<index; ++i){
        gec = gec->sonraki;
    }
    return gec->veri;
}

void SekilListesi::swap(TekDugum* d1, TekDugum* d2){ // dugumlerdeki veri işaretçilerini değişme
    Sekil* temp = d1->veri;
    d1->veri = d2->veri;
    d2->veri = temp;
}

void SekilListesi::siralaZDegerineGore(){
    if(elemanSayisi < 2) return;

    bool degisiklikYapildi;
    TekDugum *ptr1;

    do{
        degisiklikYapildi = false;
        ptr1 = ilk;

        while(ptr1->sonraki){
            if (ptr1->veri->zGetir() < ptr1->sonraki->veri->zGetir()) {
                swap(ptr1, ptr1->sonraki);
                degisiklikYapildi = true;
            }
            ptr1 = ptr1->sonraki;
        }
    }while (degisiklikYapildi);
}

void SekilListesi::tumSekilleriCiz(Tuval* tuval) {
    siralaZDegerineGore();
    TekDugum* gec = ilk;
    while (gec) {
        gec->veri->ciz(tuval); 
        gec = gec->sonraki;
    }
}

void SekilListesi::listeyiKaydet(std::ofstream& dosya) const {
    TekDugum* gec = ilk;
    while (gec) {
        gec->veri->kaydet(dosya); 
        gec = gec->sonraki;
    }
}

int SekilListesi::sayacGetir() const {
    return elemanSayisi;
}

void SekilListesi::sil(int index){
    if (index < 0 || index >= elemanSayisi || !ilk) return;

    TekDugum* silinecek;

    if(index==0){
        silinecek = ilk;
        ilk = ilk->sonraki;
    }
    else{
        TekDugum* onceki = ilk;
        for(int i=0; i < index-1 ; ++i){
            onceki = onceki->sonraki;
        }
        silinecek = onceki->sonraki;
        onceki->sonraki = silinecek->sonraki;
    }
    delete silinecek->veri; 
    delete silinecek;
    elemanSayisi--;

    if (elemanSayisi == 0)
        aktifSekilGostericisi = nullptr;
}

//seçili Sekil pointer'ını döndürür 
Sekil* SekilListesi::aktifSekliGetir() const {
    if (aktifSekilGostericisi != nullptr) {
        return aktifSekilGostericisi->veri;
    }
    return nullptr; 
}

void SekilListesi::sonrakiSekleGec() {
    if (aktifSekilGostericisi == nullptr) {
        aktifSekilGostericisi = ilk;
        return;
    }

    if (aktifSekilGostericisi->sonraki != nullptr) {
        aktifSekilGostericisi = aktifSekilGostericisi->sonraki;
    } else {
        aktifSekilGostericisi = ilk;
    }
}

void SekilListesi::oncekiSekleGec() {
    if (aktifSekilGostericisi == nullptr || elemanSayisi < 2) {
        aktifSekilGostericisi = ilk; 
        return;
    }

    if (aktifSekilGostericisi == ilk) {
        TekDugum* temp = ilk;
        while (temp->sonraki != nullptr) {
            temp = temp->sonraki;
        }
        aktifSekilGostericisi = temp;
        return;
    }

    // aktif düğümden bir önceki düğümü bul
    TekDugum* onceki = ilk;
    while (onceki->sonraki != nullptr && onceki->sonraki != aktifSekilGostericisi) {
        onceki = onceki->sonraki;
    }
    aktifSekilGostericisi = onceki;
}

bool SekilListesi::aktifSekliSil() {

    if (!ilk || !aktifSekilGostericisi)
        return false;

    TekDugum* silinecek = aktifSekilGostericisi;

    TekDugum* arama = ilk;
    bool bulundu = false;
    while (arama) {
        if (arama == silinecek) { bulundu = true; break; }
        arama = arama->sonraki;
    }
    if (!bulundu) {
        return false;
    }

    TekDugum* onceki = nullptr;
    if (silinecek != ilk) {
        TekDugum* temp = ilk;
        while (temp && temp->sonraki != silinecek) {
            temp = temp->sonraki;
        }
        onceki = temp; 
    }

    // Yeni aktif düğümü kararlaştır 
    TekDugum* yeniAktif = nullptr;
    if (silinecek->sonraki) {
        yeniAktif = silinecek->sonraki;
    } else if (onceki) {
        yeniAktif = onceki;
    } else {
        yeniAktif = nullptr; 
    }

    // bağlantıları güncelle
    if (silinecek == ilk) {
        ilk = silinecek->sonraki;
    } else if (onceki) {
        onceki->sonraki = silinecek->sonraki;
    }

    if (silinecek->veri) {
        delete silinecek->veri;
        silinecek->veri = nullptr;
    }
    delete silinecek;

    elemanSayisi = std::max(0, elemanSayisi - 1);
    aktifSekilGostericisi = yeniAktif;

    if (elemanSayisi == 0 && sahipCiftListe) {
        sahipCiftListe->dugumSil(this);
        return true; // Liste silindi
    }

    return true;
}


void SekilListesi::ilkSekleGec() {
    aktifSekilGostericisi = ilk;
}

TekDugum* SekilListesi::basDugumuGetir() const { 
    return ilk; 
}
TekDugum* SekilListesi::aktifDugumuGetir() const {
    return aktifSekilGostericisi;
}

// Sahip CiftListe'yi ayarlamak için
void SekilListesi::setSahipCiftListe(CiftListe* liste) { 
    sahipCiftListe = liste; 
}