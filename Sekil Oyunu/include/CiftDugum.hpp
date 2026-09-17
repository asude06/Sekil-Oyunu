#ifndef CIFTDUGUM_HPP
#define CIFTDUGUM_HPP

#include "SekilListesi.hpp"

class CiftDugum{
    public:
        SekilListesi* veri; // ana dügümümüzün verisi sekil listeleri
        CiftDugum* sonraki;
        CiftDugum* onceki;
        
        CiftDugum(SekilListesi* listeVerisi);
        ~CiftDugum();
};


#endif