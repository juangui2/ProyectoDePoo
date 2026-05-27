#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <vector>
#include <iostream>

class ElementoInteractivo;
class Explorador;

class Zona {
private:
    std::string nombre;
    std::vector<ElementoInteractivo*> elementos;

public:
    Zona(const std::string& nombre);
    ~Zona();

    void agregarElemento(ElementoInteractivo* elemento);
    void mostrarElementos() const;

    void interactuar(int indice, Explorador* explorador);
    void interactuar(const std::string& nombreElemento, Explorador* explorador);

    std::string getNombre() const;
    void mostrarInfo() const;

    bool tieneResiduosSinLimpiar() const;
    bool tieneFuentesSinRestaurar() const;
};

#endif
