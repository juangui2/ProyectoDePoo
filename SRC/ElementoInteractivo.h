#ifndef ELEMENTO_INTERACTIVO_H
#define ELEMENTO_INTERACTIVO_H

#include <string>
#include <iostream>

class Explorador;

class ElementoInteractivo {
private:
    std::string nombre;

public:
    ElementoInteractivo(const std::string& nombre);
    virtual ~ElementoInteractivo();

    virtual void interactuar(Explorador* explorador) = 0;
    virtual std::string getTipo() const = 0;
    virtual std::string getEfecto() const = 0;
    virtual bool fueUsado() const = 0;

    std::string getNombre() const;
};

#endif
