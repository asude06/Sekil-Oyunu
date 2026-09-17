#ifndef UCGEN_HPP
#define UCGEN_HPP

#include "Sekil.hpp"
#include "Tuval.hpp"

class Ucgen : public Sekil{
    public:
        Ucgen(int x_koor, int y_koor, int z_deger, char karakter, int boyut); // x merkez, y tepe ,, taban sınıfın yapıcısınna gider parametrelerini ve boyutları ordan alır

        virtual ~Ucgen() = default;

        void ciz(Tuval* tuval) override; // Sekil sınıfından implementasyonlar
        void kaydet(std::ofstream& dosya) override;
        const char* tipiGetir() const override;
};

#endif