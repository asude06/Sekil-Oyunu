#ifndef TUVAL_HPP
#define TUVAL_HPP

#include <iostream>
#include "SekilListesi.hpp"

class SekilListesi;
class Sekil;

class Tuval{
    private:
        static const int SATIR = 25;
        static const int SUTUN = 80;
        
        int z_buffer[SATIR][SUTUN];
        char ekran[SATIR][SUTUN];

    public:

        Tuval();  // kurucusu
        void temizle();
        void goster() const;
        void karakterKoy(int x, int y, char karakter, int z_degeri);  //Bu Sekil::ciz() de kullanılacak 
        bool sinirdaMi(int x, int y) const;
        void cizdir(SekilListesi* liste);

        
};
#endif