#ifndef ECOMISION_H
#define ECOMISION_H

#include "Reserva.h"
#include "Explorador.h"

class EcoMision {
private:
    Reserva reserva;
    Explorador explorador;
    bool activo;
    void prepararReserva();
    void mostrarBienvenida();
    void turno();
    void mostrarMenuZona() const;
    void procesarOpcion(const std::string& opcion);
    void verificarFinJuego();
    bool hayVictoria() const;
    void mostrarPantallaFinal(bool victoria) const;

public:
    EcoMision();
    void iniciar();

};

#endif
