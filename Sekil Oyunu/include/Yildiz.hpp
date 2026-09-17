#ifndef YILDIZ_HPP
#define YILDIZ_HPP

#include "Sekil.hpp"
#include "Tuval.hpp"

class Yildiz: public Sekil{
    public:
        Yildiz(int x_koor, int y_koor, int z_deger, char karakter, int boyut); // yapıcı boyut ayarlar

        virtual ~Yildiz() = default;

        //implementler
        void ciz(Tuval* tuval) override;
        void kaydet(std::ofstream& dosya) override;
        const char* tipiGetir() const override;

        void tasi(int yeni_x, int yeni_y);
        
};

#endif