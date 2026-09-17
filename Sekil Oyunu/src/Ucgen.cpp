/**       
* @file             Ucgen
* @description      Ucgen Sınıfının metotları
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             16.11.2025
* @author           Asude Elif Karaağaç
*/ 


#include "Ucgen.hpp"
#include <cmath>

Ucgen::Ucgen(int x_koor, int y_koor, int z_deger,char karakter, int boyut)
{
    x = x_koor;
    y = y_koor;
    z = z_deger;
    cizimKarakteri = karakter;
    genislik = boyut;
    yukseklik = boyut;
}


void Ucgen::ciz(Tuval* tuval){
    
    int sekil_z = this->zGetir();
    int yaricap = yukseklik - 1;

    // Sol sınır kontrolü: tepe noktası minimum yarıçap kadar sağda olmalı
    int min_merkez_x = yaricap;
    int max_merkez_x = 80 - 1 - yaricap; // tuval genisligi - 1 - yaricap

    int merkez_x = x;
    if(merkez_x < min_merkez_x) merkez_x = min_merkez_x;
    if(merkez_x > max_merkez_x) merkez_x = max_merkez_x;

    int merkez_y = y;
    if(merkez_y < 0) merkez_y = 0;
    if(merkez_y + yukseklik > 25) merkez_y = 25 - yukseklik; // tuval yuksekligi

    for(int satir=0; satir < yukseklik; ++satir){
        int baslangic_x = merkez_x - satir;
        int bitis_x = merkez_x + satir;

        for(int sutun = baslangic_x; sutun <= bitis_x; ++sutun){
            int cizim_x = sutun;
            int cizim_y = merkez_y + satir;

            if(tuval->sinirdaMi(cizim_x, cizim_y)){
                tuval->karakterKoy(cizim_x, cizim_y, cizimKarakteri, sekil_z);
            }
        }
    }

}

void Ucgen::kaydet(std::ofstream& dosya) {
    dosya << "Ucgen " 
          << x << " " << y << " " 
          << z << " " << cizimKarakteri << " " 
          << genislik << std::endl; // Boyut bilgisini genislik olarak kaydettik
}

// Şekil tipini döndürme
const char* Ucgen::tipiGetir() const {
    return "Ucgen";
}

