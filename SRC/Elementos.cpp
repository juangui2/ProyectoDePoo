#include "Elementos.h"
#include "Zona.h"

AnimalHerido::AnimalHerido(const std::string& nombre)
    : ElementoInteractivo(nombre) {
    curado = false;
}

void AnimalHerido::interactuar(Explorador* explorador) {
    std::cout << ">>> " << getNombre() << std::endl;
    if (curado) {
        std::cout << "    El animal ya fue curado." << std::endl;
        return;
    }
    if (explorador->getEnergia() < 10) {
        std::cout << "    No tienes energia suficiente." << std::endl;
        return;
    }
    explorador->perderEnergia(10);
    explorador->aumentarPuntaje(20);
    curado = true;
    std::cout << "    Curaste al animal!" << std::endl;
}

std::string AnimalHerido::getTipo() const { return "Animal"; }
std::string AnimalHerido::getEfecto() const { return "-10 energia, +20 puntaje"; }
bool AnimalHerido::fueUsado() const { return curado; }

PlantaMedicinal::PlantaMedicinal(const std::string& nombre)
    : ElementoInteractivo(nombre) {
    recolectada = false;
}

void PlantaMedicinal::interactuar(Explorador* explorador) {
    std::cout << ">>> " << getNombre() << std::endl;
    if (recolectada) {
        std::cout << "    Esta planta ya fue recolectada." << std::endl;
        return;
    }
    explorador->recuperarEnergia(15);
    explorador->recolectar(this);
    recolectada = true;
}

std::string PlantaMedicinal::getTipo() const { return "Planta"; }
std::string PlantaMedicinal::getEfecto() const { return "+15 energia, va al inventario"; }
bool PlantaMedicinal::fueUsado() const { return recolectada; }

ResiduoContaminante::ResiduoContaminante(const std::string& nombre)
    : ElementoInteractivo(nombre) {
    limpiado = false;
}

void ResiduoContaminante::interactuar(Explorador* explorador) {
    std::cout << ">>> " << getNombre() << std::endl;
    if (limpiado) {
        std::cout << "    Este residuo ya fue limpiado." << std::endl;
        return;
    }
    if (explorador->getEnergia() < 20) {
        std::cout << "    No tienes energia suficiente." << std::endl;
        return;
    }
    explorador->perderEnergia(20);
    explorador->aumentarPuntaje(30);
    limpiado = true;
    std::cout << "    Residuo limpiado!" << std::endl;
}

std::string ResiduoContaminante::getTipo() const { return "Residuo"; }
std::string ResiduoContaminante::getEfecto() const { return "-20 energia, +30 puntaje"; }
bool ResiduoContaminante::fueUsado() const { return limpiado; }

EstacionEnergia::EstacionEnergia(const std::string& nombre, int carga)
    : ElementoInteractivo(nombre) {
    this->carga = carga;
}

void EstacionEnergia::interactuar(Explorador* explorador) {
    std::cout << ">>> " << getNombre() << std::endl;
    explorador->recuperarEnergia(carga);
    std::cout << "    Energia recargada." << std::endl;
}

std::string EstacionEnergia::getTipo() const { return "Estacion"; }
std::string EstacionEnergia::getEfecto() const { return "+" + std::to_string(carga) + " energia"; }
bool EstacionEnergia::fueUsado() const { return false; }

PortalDeRuta::PortalDeRuta(const std::string& nombre, Zona* destino)
    : ElementoInteractivo(nombre) {
    this->destino = destino;
}

void PortalDeRuta::interactuar(Explorador* explorador) {
    std::cout << ">>> " << getNombre() << std::endl;
    explorador->cambiarZona(destino);
}

std::string PortalDeRuta::getTipo() const { return "Portal"; }
std::string PortalDeRuta::getEfecto() const { return "Mueve a: " + destino->getNombre(); }
bool PortalDeRuta::fueUsado() const { return false; }

FuenteContaminada::FuenteContaminada(const std::string& nombre)
    : ElementoInteractivo(nombre) {
    restaurada = false;
    limpiezasPendientes = 2;
}

void FuenteContaminada::interactuar(Explorador* explorador) {
    std::cout << ">>> " << getNombre() << std::endl;
    if (restaurada) {
        std::cout << "    Esta fuente ya fue restaurada." << std::endl;
        return;
    }
    if (explorador->getEnergia() < 15) {
        std::cout << "    No tienes energia suficiente." << std::endl;
        return;
    }
    explorador->perderEnergia(15);
    limpiezasPendientes = limpiezasPendientes - 1;
    if (limpiezasPendientes <= 0) {
        restaurada = true;
        explorador->aumentarPuntaje(40);
        std::cout << "    Fuente restaurada completamente!" << std::endl;
    } else {
        std::cout << "    Limpieza parcial. Faltan " << limpiezasPendientes << " mas." << std::endl;
    }
}

std::string FuenteContaminada::getTipo() const { return "Fuente"; }
std::string FuenteContaminada::getEfecto() const { return "-15 energia x limpieza, +40 puntaje al restaurar"; }
bool FuenteContaminada::fueUsado() const { return restaurada; }

ObstaculoAmbiental::ObstaculoAmbiental(const std::string& nombre, int costo)
    : ElementoInteractivo(nombre) {
    superado = false;
    costoEnergia = costo;
}

void ObstaculoAmbiental::interactuar(Explorador* explorador) {
    std::cout << ">>> " << getNombre() << std::endl;
    if (superado) {
        std::cout << "    Este obstaculo ya fue superado." << std::endl;
        return;
    }
    if (explorador->getEnergia() < costoEnergia) {
        std::cout << "    No tienes energia suficiente." << std::endl;
        return;
    }
    explorador->perderEnergia(costoEnergia);
    explorador->aumentarPuntaje(15);
    superado = true;
    std::cout << "    Obstaculo superado!" << std::endl;
}

std::string ObstaculoAmbiental::getTipo() const { return "Obstaculo"; }
std::string ObstaculoAmbiental::getEfecto() const { return "-" + std::to_string(costoEnergia) + " energia, +15 puntaje"; }
bool ObstaculoAmbiental::fueUsado() const { return superado; }
