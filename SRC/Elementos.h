#ifndef ELEMENTOS_H
#define ELEMENTOS_H

#include "ElementoInteractivo.h"
#include "Explorador.h"

class Zona;

class AnimalHerido : public ElementoInteractivo {
private:
    bool curado;
public:
    AnimalHerido(const std::string& nombre);
    void interactuar(Explorador* explorador) override;
    std::string getTipo() const override;
    std::string getEfecto() const override;
    bool fueUsado() const override;
};

class PlantaMedicinal : public ElementoInteractivo {
private:
    bool recolectada;
public:
    PlantaMedicinal(const std::string& nombre);
    void interactuar(Explorador* explorador) override;
    std::string getTipo() const override;
    std::string getEfecto() const override;
    bool fueUsado() const override;
};

class ResiduoContaminante : public ElementoInteractivo {
private:
    bool limpiado;
public:
    ResiduoContaminante(const std::string& nombre);
    void interactuar(Explorador* explorador) override;
    std::string getTipo() const override;
    std::string getEfecto() const override;
    bool fueUsado() const override;
};

class EstacionEnergia : public ElementoInteractivo {
private:
    int carga;
public:
    EstacionEnergia(const std::string& nombre, int carga);
    void interactuar(Explorador* explorador) override;
    std::string getTipo() const override;
    std::string getEfecto() const override;
    bool fueUsado() const override;
};

class PortalDeRuta : public ElementoInteractivo {
private:
    Zona* destino;
public:
    PortalDeRuta(const std::string& nombre, Zona* destino);
    void interactuar(Explorador* explorador) override;
    std::string getTipo() const override;
    std::string getEfecto() const override;
    bool fueUsado() const override;
};


class FuenteContaminada : public ElementoInteractivo {
private:
    bool restaurada;
    int limpiezasPendientes;
public:
    FuenteContaminada(const std::string& nombre);
    void interactuar(Explorador* explorador) override;
    std::string getTipo() const override;
    std::string getEfecto() const override;
    bool fueUsado() const override;
};


class ObstaculoAmbiental : public ElementoInteractivo {
private:
    bool superado;
    int costoEnergia;
public:
    ObstaculoAmbiental(const std::string& nombre, int costoEnergia);
    void interactuar(Explorador* explorador) override;
    std::string getTipo() const override;
    std::string getEfecto() const override;
    bool fueUsado() const override;
};

#endif
