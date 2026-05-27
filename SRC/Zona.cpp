#include "Zona.h"
#include "ElementoInteractivo.h"
#include "Explorador.h"

Zona::Zona(const std::string& nombre) {
    this->nombre = nombre;
}

Zona::~Zona() {
    for (int i = 0; i < (int)elementos.size(); i++) {
        delete elementos[i];
    }
}

void Zona::agregarElemento(ElementoInteractivo* elemento) {
    elementos.push_back(elemento);
}

void Zona::mostrarElementos() const {
    bool hayDisponibles = false;
    for (int i = 0; i < (int)elementos.size(); i++) {
        if (!elementos[i]->fueUsado()) {
            std::cout << "  - " << elementos[i]->getNombre()
                      << " [" << elementos[i]->getTipo() << "]"
                      << " -> " << elementos[i]->getEfecto() << std::endl;
            hayDisponibles = true;
        }
    }
    if (!hayDisponibles) {
        std::cout << "  (no hay elementos disponibles)" << std::endl;
    }
}

void Zona::interactuar(int indice, Explorador* explorador) {
    if (indice < 0 || indice >= (int)elementos.size()) {
        std::cout << "  Indice fuera de rango." << std::endl;
        return;
    }
    elementos[indice]->interactuar(explorador);
}

void Zona::interactuar(const std::string& nombreElemento, Explorador* explorador) {
    for (int i = 0; i < (int)elementos.size(); i++) {
        if (elementos[i]->getNombre() == nombreElemento) {
            elementos[i]->interactuar(explorador);
            return;
        }
    }
    std::cout << "  Elemento no encontrado: " << nombreElemento << std::endl;
}

std::string Zona::getNombre() const {
    return nombre;
}

void Zona::mostrarInfo() const {
    int disponibles = 0;
    for (int i = 0; i < (int)elementos.size(); i++) {
        if (!elementos[i]->fueUsado()) disponibles++;
    }
    std::cout << "[Zona] " << nombre
              << " | disponibles: " << disponibles
              << "/" << elementos.size() << std::endl;
}

bool Zona::tieneResiduosSinLimpiar() const {
    for (int i = 0; i < (int)elementos.size(); i++) {
        if (elementos[i]->getTipo() == "Residuo" && !elementos[i]->fueUsado()) {
            return true;
        }
    }
    return false;
}

bool Zona::tieneFuentesSinRestaurar() const {
    for (int i = 0; i < (int)elementos.size(); i++) {
        if (elementos[i]->getTipo() == "Fuente" && !elementos[i]->fueUsado()) {
            return true;
        }
    }
    return false;
}
