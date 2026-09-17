/**       
* @file             Yildiz
* @description      Yildiz Sınıfının metotları
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             16.11.2025
* @author           Asude Elif Karaağaç
*/ 

#include "Yildiz.hpp"
#include <cstdlib>
#include <cmath>

Yildiz::Yildiz(int x_koor, int y_koor, int z_deger,char karakter, int boyut)
{
    x = x_koor;
    y = y_koor;
    z = z_deger;
    cizimKarakteri = karakter;
    genislik = boyut;
    yukseklik = boyut;

    if (genislik % 2 == 0) {
        genislik++;
        yukseklik++;
    }
}


void Yildiz::ciz(Tuval* tuval){
    int merkez_x = x;
    int merkez_y = y;
    int yari_boyut = genislik / 2;
    int sekil_z = this->zGetir();

    for(int satir = -yari_boyut; satir <= yari_boyut; ++satir){
        int satir_genisligi = yari_boyut - std::abs(satir); // üstten alt satıra daralan genişlik
        for(int sutun = -satir_genisligi; sutun <= satir_genisligi; ++sutun){
            int cizim_x = merkez_x + sutun; 
            int cizim_y = merkez_y + satir;

            if(tuval->sinirdaMi(cizim_x, cizim_y)) {
                tuval->karakterKoy(cizim_x, cizim_y, cizimKarakteri, sekil_z);
            }
        }
    }
}

void Yildiz::tasi(int yeni_x, int yeni_y){
    const int TUVAL_GENISLIK = 80;
    const int TUVAL_YUKSEKLIK = 25;
    int yari_boyut = genislik / 2;

    // X koordinatını sınırla
    if (yeni_x - yari_boyut < 0) {
        x = yari_boyut; // sola yasla
    } else if (yeni_x + yari_boyut >= TUVAL_GENISLIK) {
        x = TUVAL_GENISLIK - 1 - yari_boyut; // sağa yasla
    } else {
        x = yeni_x;
    }

    // Y koordinatını sınırla
    if (yeni_y - yari_boyut < 0) {
        y = yari_boyut; // üste yasla
    } else if (yeni_y + yari_boyut >= TUVAL_YUKSEKLIK) {
        y = TUVAL_YUKSEKLIK - 1 - yari_boyut; // alta yasla
    } else {
        y = yeni_y;
    }
}


void Yildiz::kaydet(std::ofstream& dosya) {
    dosya << "Yildiz " 
          << x << " " << y << " " 
          << z << " " << cizimKarakteri << " " 
          << genislik << std::endl; 
}

// Şekil tipini döndürme
const char* Yildiz::tipiGetir() const {
    return "Yildiz";
}