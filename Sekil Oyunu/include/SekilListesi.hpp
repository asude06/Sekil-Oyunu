#ifndef SEKILLISTESI_HPP
#define SEKILLISTESI_HPP

#include <iostream>
#include <fstream>
#include "TekDugum.hpp" 
#include "Tuval.hpp"

class Tuval;
class Sekil;
class TekDugum;
class CiftListe;

class SekilListesi{
    private:
        TekDugum* ilk;
        int elemanSayisi;

        void swap(TekDugum* d1, TekDugum* d2); // yardımcı sıralama metodu

        TekDugum* aktifSekilGostericisi;

        CiftListe* sahipCiftListe;


    public:
        SekilListesi();
        ~SekilListesi();

        void ekle(Sekil* yeniSekil); // yeni şekli sona ekler
        void sil(int index);

        Sekil* sekilGetir(int index) const;

        void tumSekilleriCiz(Tuval* tuval);
        void siralaZDegerineGore();
        void listeyiKaydet(std::ofstream& dosya) const;

        int sayacGetir() const;

        void ilkSekleGec(); // Listeye ilk girildiğinde veya Q/E ile döngü tamamlandığında
        void sonrakiSekleGec();
        void oncekiSekleGec();
        
        // İşlem (C, W, A, S, D komutları)
        Sekil* aktifSekliGetir() const; // Şu an seçili olan şeklin pointer'ını döndürür
        bool aktifSekliSil();

        TekDugum* basDugumuGetir() const;
        TekDugum* aktifDugumuGetir() const;

        void setSahipCiftListe(CiftListe* liste);
};
#endif