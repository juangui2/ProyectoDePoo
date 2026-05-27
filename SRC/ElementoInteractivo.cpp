#include "ElementoInteractivo.h"

ElementoInteractivo::ElementoInteractivo(const std::string& nombre) {
    this->nombre = nombre;
}

ElementoInteractivo::~ElementoInteractivo() {}

std::string ElementoInteractivo::getNombre() const {
    return nombre;
}
