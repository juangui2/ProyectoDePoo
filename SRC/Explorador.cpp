#include "Explorador.h"
#include "Zona.h"
#include "ElementoInteractivo.h"

Explorador::Explorador(const std::string& nombre) {
    this->nombre = nombre;
    this->energia = 100;
    this->puntaje = 0;
    this->zonaActual = nullptr;
}

void Explorador::perderEnergia(int cantidad) {
    energia = energia - cantidad;
    if (energia < 0) energia = 0;
    std::cout << "  Energia actual: " << energia << std::endl;
}

void Explorador::recuperarEnergia(int cantidad) {
    energia = energia + cantidad;
    std::cout << "  Energia actual: " << energia << std::endl;
}

void Explorador::aumentarPuntaje(int puntos) {
    puntaje = puntaje + puntos;
    std::cout << "  Puntaje actual: " << puntaje << std::endl;
}

void Explorador::cambiarZona(Zona* zona) {
    zonaActual = zona;
    std::cout << "  Te mueves a: " << zona->getNombre() << std::endl;
}

void Explorador::recolectar(ElementoInteractivo* elemento) {
    inventario.push_back(elemento);
    std::cout << "  Recolectaste: " << elemento->getNombre() << std::endl;
}

std::string Explorador::getNombre() const { return nombre; }
int Explorador::getEnergia() const { return energia; }
int Explorador::getPuntaje() const { return puntaje; }
Zona* Explorador::getZonaActual() const { return zonaActual; }

void Explorador::mostrarEstado() const {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Explorador: " << nombre << std::endl;
    std::cout << "Energia   : " << energia << std::endl;
    std::cout << "Puntaje   : " << puntaje << std::endl;
    if (zonaActual != nullptr) {
        std::cout << "Zona      : " << zonaActual->getNombre() << std::endl;
    }
    std::cout << "Inventario: ";
    if (inventario.empty()) {
        std::cout << "(vacio)" << std::endl;
    } else {
        std::cout << std::endl;
        for (int i = 0; i < (int)inventario.size(); i++) {
            std::cout << "  - " << inventario[i]->getNombre() << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}

