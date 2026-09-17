#ifndef TEKDUGUM_HPP
#define TEKDUGUM_HPP

#include "Sekil.hpp"

class Sekil;

class TekDugum{
    public:
        Sekil* veri;  //Polimorfizm için Sekil türünden bir işaretçi
        TekDugum* sonraki;

        TekDugum(Sekil* sekilVerisi);

        ~TekDugum();
};
#endif