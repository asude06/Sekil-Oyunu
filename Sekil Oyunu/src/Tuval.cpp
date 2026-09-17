/**       
* @file             Tuval
* @description      İşlemleri ekrana yazdırma, konsol ekranına oluşturma
* @course           Birinci Öğretim, 1A grubu 
* @assignment       1.Ödev
* @date             11.11.2025
* @author           Asude Elif Karaağaç
*/ 

#include "Tuval.hpp"
#include "SekilListesi.hpp"
#include "Sekil.hpp"
#include <iostream>
#include <algorithm>

Tuval::Tuval() {
    // Nesne oluşturulurken tuvali temizler
    temizle();
}

void Tuval::temizle(){
    for(int i=0; i<SATIR; i++){
        for(int j=0; j<SUTUN; j++){
            ekran[i][j] = ' ';      // tuvali boşluklarla dolduracak
            z_buffer[i][j] = -1;
        }
    }
}

void Tuval::karakterKoy(int x, int y, char karakter, int z_degeri){
    // sınır içinde olduğumuzu hep kontrol etmeliyiz
    if(sinirdaMi(x,y)){
        if (z_degeri >= z_buffer[y][x]) { 
            ekran[y][x] = karakter;
            z_buffer[y][x] = z_degeri; // Önceliği kaydet
        }
    }
}

bool Tuval::sinirdaMi(int x, int y) const{
    if(y < 0 || y >= SATIR){ 
        return false;
    }

    if(x < 0 || x >= SUTUN){
        return false;
    }
    return true;
}

void Tuval::goster() const{
    system("CLS");

    //ust
    std::cout << "+";
    for (int j = 0; j < SUTUN; j++) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    //icerik
    for (int i = 0; i < SATIR; i++) {
        std::cout << "|"; // Sol sınır
        for (int j = 0; j < SUTUN; j++) {
            std::cout << ekran[i][j];
        }
        std::cout << "|" << std::endl; // Sağ sınır
    }

    //alt
    std::cout << "+";
    for (int j = 0; j < SUTUN; j++) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
}

void Tuval::cizdir(SekilListesi* liste){

    if (!liste) return;

    liste->siralaZDegerineGore();

    temizle();

    // Listeyi aktif pointer değiştirmeden dolaşmak için geçici pointer
    TekDugum* temp = liste->basDugumuGetir(); 
    while (temp != nullptr) {
        Sekil* s = temp->veri;
        if (s) s->ciz(this);
        temp = temp->sonraki;
    }

    goster();
}