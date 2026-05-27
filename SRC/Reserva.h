#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "Zona.h"

class Reserva {
private:
    std::unordered_map<std::string, Zona*> zonas;
    std::vector<std::string> codigos;

public:
    ~Reserva();

    void agregarZona(const std::string& codigo, Zona* zona);
    Zona* buscarZona(const std::string& codigo) const;
    void mostrarZonas() const;

    const std::vector<std::string>& getCodigos() const;
};

#endif
