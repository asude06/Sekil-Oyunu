/**       
* @file             Sekil
* @description      Sekil sınıfının metotları 
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             15.11.2025
* @author           Asude Elif Karaağaç
*/ 

#include "Sekil.hpp"

Sekil::Sekil() {
    x = 0;
    y = 0;
    z = 0;
    cizimKarakteri = '*';   // varsayılan karakter
    genislik = 1;
    yukseklik = 1;
}

Sekil::Sekil(int x_koor,int y_koor, int z_deger, char karakter, int g, int yk) 
:x(x_koor), y(y_koor), z(z_deger), cizimKarakteri(karakter), genislik(g), yukseklik(yk){}

void Sekil::tasi(int yeni_x, int yeni_y){
    
    const int TUVAL_GENISLIK = 80;
    const int TUVAL_YUKSEKLIK = 25;

    // X koordinatını sınırla
    if (yeni_x < 0) {
        x = 0; // sol sınır
    } else if (yeni_x + genislik > TUVAL_GENISLIK) {
        x = TUVAL_GENISLIK - genislik; // sağ sınır
        if (x < 0) x = 0; // şekil tuvali aşıyorsa sola yasla
    } else {
        x = yeni_x;
    }

    // Y koordinatını sınırla
    if (yeni_y < 0) {
        y = 0; // üst sınır
    } else if (yeni_y + yukseklik > TUVAL_YUKSEKLIK) {
        y = TUVAL_YUKSEKLIK - yukseklik; // alt sınır
        if (y < 0) y = 0; // şekil tuvali aşıyorsa üste yasla
    } else {
        y = yeni_y;
    }
}

void Sekil::zDegeriniAta(int yeni_z){
    z = yeni_z;
}

int Sekil::zGetir() const{
    return z;
}

int Sekil::xGetir() const{
    return x;
}

int Sekil::yGetir() const{
    return y;
}

