/**       
* @file             Dikdortgen
* @description      Dikdortgen Sınıfının metotları
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             16.11.2025
* @author           Asude Elif Karaağaç
*/ 

#include "Dikdortgen.hpp"
#include "Sekil.hpp"
#include "SekilListesi.hpp"

Dikdortgen::Dikdortgen(int x_koor, int y_koor, int z_deger,char karakter, int g, int yk){
    // Taban sınıf üyeleri burada atanır
    x = x_koor;
    y = y_koor;
    z = z_deger;
    cizimKarakteri = karakter;
    genislik = g;
    yukseklik = yk;
}

void Dikdortgen::ciz(Tuval* tuval){
    int sekil_z = this->zGetir();

    for(int satir = 0; satir < yukseklik; satir++){ // sıfırdan başladığı iin önce arttırır sonra kullanır
        for(int sutun=0; sutun < genislik; sutun++){
            int cizim_x = x + sutun;
            int cizim_y = y + satir;

            if(tuval->sinirdaMi(cizim_x,cizim_y)){
                tuval->karakterKoy(cizim_x, cizim_y, cizimKarakteri, sekil_z);
            }
        }
    }
}

void Dikdortgen::kaydet(std::ofstream& dosya) {
    dosya << "Dikdortgen " 
          << x << " " << y << " " 
          << z << " " << cizimKarakteri << " " 
          << genislik << " " << yukseklik << std::endl;
}

const char* Dikdortgen::tipiGetir() const {
    return "Dikdortgen";
}