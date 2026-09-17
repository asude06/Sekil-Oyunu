/**       
* @file             TekDugum
* @description      TekDugum kurucusu ve yok edicisi
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             11.11.2025
* @author           Asude Elif Karaağaç
*/ 


#include "TekDugum.hpp"
#include "Sekil.hpp"

TekDugum::TekDugum(Sekil* sekilVerisi) {
    veri = sekilVerisi;
    sonraki = nullptr;
}


TekDugum::~TekDugum() {
    if (veri != nullptr) {
        delete veri; // Sekil nesnesini siler
        veri = nullptr;
    }
}