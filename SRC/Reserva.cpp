#include "Reserva.h"

Reserva::~Reserva() {
    for (int i = 0; i < (int)codigos.size(); i++) {
        delete zonas[codigos[i]];
    }
}

void Reserva::agregarZona(const std::string& codigo, Zona* zona) {
    zonas[codigo] = zona;
    codigos.push_back(codigo);
}

Zona* Reserva::buscarZona(const std::string& codigo) const {
    if (zonas.count(codigo) > 0) {
        return zonas.at(codigo);
    }
    return nullptr;
}

void Reserva::mostrarZonas() const {
    std::cout << "=== Zonas de la reserva ===" << std::endl;
    for (int i = 0; i < (int)codigos.size(); i++) {
        std::cout << "  [" << codigos[i] << "] ";
        zonas.at(codigos[i])->mostrarInfo();
    }
}

const std::vector<std::string>& Reserva::getCodigos() const {
    return codigos;
}
