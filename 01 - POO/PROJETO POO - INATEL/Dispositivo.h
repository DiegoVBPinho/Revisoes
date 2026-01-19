#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H
#include <string>

class Dispositivo {
protected:
    std::string ip;
    std::string nome;
public:
    Dispositivo(std::string n, std::string i) : nome(n), ip(i) {}
    virtual void verificarStatus() = 0; // Requisito 4: Polimorfismo
    virtual ~Dispositivo() {}
};
#endif