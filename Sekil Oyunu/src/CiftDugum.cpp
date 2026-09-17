/**       
* @file             CiftDugum
* @description      CiftDugum kurucusu ve yok edicisi
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             11.11.2025
* @author           Asude Elif Karaağaç
*/ 

#include "CiftDugum.hpp"
#include "SekilListesi.hpp"

CiftDugum::CiftDugum(SekilListesi* listeVerisi) {
    veri = listeVerisi;
    onceki = nullptr;
    sonraki = nullptr;
}

CiftDugum::~CiftDugum(){
    if(veri != nullptr){
        delete veri;
        veri = nullptr;
    }
}