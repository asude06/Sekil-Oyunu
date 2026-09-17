#ifndef CIFTLISTE_HPP
#define CIFTLISTE_HPP

#include "CiftDugum.hpp"
#include "SekilListesi.hpp"

class CiftDugum;

class CiftListe{
    private:
        CiftDugum* ilk;
        CiftDugum* son;
        CiftDugum* aktif;
        int dugumSayisi;
    public:
        CiftListe();
        ~CiftListe();

        void dugumEkle(SekilListesi* yeniListe);
        bool aktifDugumSil();

        void sonrakiDugumeGec();
        void oncekiDugumeGec();
        SekilListesi* aktifSekilleriGetir() const; // aktif düğümdeki sekil listesini getirir

        void dosyayaKaydet(const char* dosyaAdi) const;
        void dosyadanYukle(const char* dosyaAdi);

        void rastgeleDugumEkle(int adet); //başlangıçta 20 dugum oluşturmak için kullanıyoruz
        
        int aktifDugumSirasiniGetir() const;
        int dugumSayisiGetir() const;
        
        void dugumSil(SekilListesi* liste);

        CiftDugum* aktifDugumuGetir() const;
};

#endif