#ifndef DIKDORTGEN_HPP
#define DIKDORTGEN_HPP
#include "Sekil.hpp"
#include "Tuval.hpp"

class Dikdortgen: public Sekil{ // sanal sekil sınıfındaki özellikleri al
    public:
    Dikdortgen(int x_koor, int y_koor, int z_deger, char karakter, int g, int yk); //taban sınıfın yapıcısı kullanılır
    
    virtual ~Dikdortgen() = default;

    void ciz(Tuval* tuval) override;
    void kaydet(std::ofstream& dosya) override;
    const char* tipiGetir() const override;

};

#endif