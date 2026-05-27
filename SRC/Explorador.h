#ifndef EXPLORADOR_H
#define EXPLORADOR_H

#include <string>
#include <vector>
#include <iostream>

class Zona;
class ElementoInteractivo;

class Explorador {
private:
    std::string nombre;
    int energia;
    int puntaje;
    Zona* zonaActual;
    std::vector<ElementoInteractivo*> inventario;

public:
    Explorador(const std::string& nombre);

    void perderEnergia(int cantidad);
    void recuperarEnergia(int cantidad);
    void aumentarPuntaje(int puntos);
    void cambiarZona(Zona* zona);
    void recolectar(ElementoInteractivo* elemento);

    std::string getNombre() const;
    int getEnergia() const;
    int getPuntaje() const;
    Zona* getZonaActual() const;

    void mostrarEstado() const;
};

#endif
