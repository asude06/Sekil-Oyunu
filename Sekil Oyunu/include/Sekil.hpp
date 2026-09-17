#ifndef SEKIL_HPP
#define SEKIL_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "Tuval.hpp"
class Tuval;

class Sekil{
    protected:
        int x, y; // koordinatlar
        int z; // öncelik
        char cizimKarakteri; //şeklin cizimindeki karakter
        int genislik;
        int yukseklik;
        
    public:
        Sekil();
        Sekil(int x_koor, int y_koor, int z_deger, char karakter, int g, int yk);
       
        virtual ~Sekil() = default; // polimorfik için sanal olmalı 

        virtual void ciz(Tuval* tuval) = 0; 
        virtual void kaydet(std::ofstream& dosya) = 0; 
        virtual const char* tipiGetir() const = 0; // seklin tipini döndürür

        virtual void tasi(int yeni_x, int yeni_y);
        void zDegeriniAta(int yeni_z);

        int zGetir() const;
        int xGetir() const;
        int yGetir() const;

    

};

#endif