#include "EcoMision.h"
#include "Elementos.h"
#include <iostream>
#include <string>

EcoMision::EcoMision() : explorador("Explorador") {
    activo = true;
}

void EcoMision::iniciar() {
    mostrarBienvenida();
    prepararReserva();

    while (activo) {
        turno();
    }
}

void EcoMision::mostrarBienvenida() {
    std::cout << "====================================" << std::endl;
    std::cout << "          ECOMISION                 " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Ingresa tu nombre: ";
    std::string nombre;
    std::cin >> nombre;
    explorador = Explorador(nombre);
    std::cout << std::endl;
    std::cout << "Bienvenido " << nombre << "!" << std::endl;
    std::cout << "Meta: limpiar todos los residuos" << std::endl;
    std::cout << "      y restaurar todas las fuentes." << std::endl;
    std::cout << std::endl;
    std::cout << "Comandos:" << std::endl;
    std::cout << "  <nombre>  -> interactuar con elemento" << std::endl;
    std::cout << "  estado    -> ver tu estado" << std::endl;
    std::cout << "  zonas     -> ver la reserva" << std::endl;
    std::cout << "  salir     -> terminar" << std::endl;
    std::cout << "====================================" << std::endl;
}

void EcoMision::prepararReserva() {
    Zona* bosque  = new Zona("Bosque");
    Zona* rio     = new Zona("Rio");
    Zona* centro  = new Zona("Centro");
    Zona* vivero  = new Zona("Vivero");
    Zona* sendero = new Zona("Sendero");
    Zona* lab     = new Zona("Laboratorio");

    bosque->agregarElemento(new AnimalHerido("Venado"));
    bosque->agregarElemento(new PlantaMedicinal("Orquidea"));
    bosque->agregarElemento(new ObstaculoAmbiental("ArbolCaido", 15));
    bosque->agregarElemento(new PortalDeRuta("PortalAlRio", rio));

    rio->agregarElemento(new ResiduoContaminante("Plastico"));
    rio->agregarElemento(new ResiduoContaminante("Aceite"));
    rio->agregarElemento(new FuenteContaminada("FuenteDelRio"));
    rio->agregarElemento(new PortalDeRuta("PortalAlCentro", centro));

    centro->agregarElemento(new AnimalHerido("Tortuga"));
    centro->agregarElemento(new AnimalHerido("Aguila"));
    centro->agregarElemento(new EstacionEnergia("EstacionSolar", 25));
    centro->agregarElemento(new PortalDeRuta("PortalAlVivero", vivero));

    vivero->agregarElemento(new PlantaMedicinal("Guayabo"));
    vivero->agregarElemento(new PlantaMedicinal("Helecho"));
    vivero->agregarElemento(new EstacionEnergia("EstacionHidrica", 20));
    vivero->agregarElemento(new PortalDeRuta("PortalAlSendero", sendero));

    sendero->agregarElemento(new ObstaculoAmbiental("Deslizamiento", 25));
    sendero->agregarElemento(new ResiduoContaminante("Basura"));
    sendero->agregarElemento(new EstacionEnergia("Refugio", 30));
    sendero->agregarElemento(new PortalDeRuta("PortalAlLab", lab));

    lab->agregarElemento(new PlantaMedicinal("MuestraFlora"));
    lab->agregarElemento(new FuenteContaminada("Deposito"));
    lab->agregarElemento(new EstacionEnergia("Generador", 35));

    reserva.agregarZona("bosque",      bosque);
    reserva.agregarZona("rio",         rio);
    reserva.agregarZona("centro",      centro);
    reserva.agregarZona("vivero",      vivero);
    reserva.agregarZona("sendero",     sendero);
    reserva.agregarZona("laboratorio", lab);

    explorador.cambiarZona(bosque);
}

void EcoMision::turno() {
    mostrarMenuZona();
    std::cout << std::endl << "Que hacer? > ";
    std::string opcion;
    std::cin >> opcion;
    procesarOpcion(opcion);
    verificarFinJuego();
}

void EcoMision::mostrarMenuZona() const {
    Zona* zona = explorador.getZonaActual();
    std::cout << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Zona   : " << zona->getNombre() << std::endl;
    std::cout << "Energia: " << explorador.getEnergia()
              << "  Puntaje: " << explorador.getPuntaje() << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "salir     -> terminar" << std::endl;
    zona->mostrarElementos();
}

void EcoMision::procesarOpcion(const std::string& opcion) {
    if (opcion == "estado") {
        explorador.mostrarEstado();
        return;
    }
    if (opcion == "zonas") {
        reserva.mostrarZonas();
        return;
    }

    if (opcion.empty()) {
        std::cout << "  Comando invalido." << std::endl;
        return;
    }

    if (opcion == "salir") {
        std::cout << "  Saliendo del juego..." << std::endl;
        activo = false;
        return;
    }

    bool esNumero = true;
    int numeroConvertido = 0;

    for (int i = 0; i < (int)opcion.length(); i++) {
        char c = opcion[i];
        if (c < '0' || c > '9') {
            esNumero = false;
            break;
        }
        numeroConvertido = (numeroConvertido * 10) + (c - '0');
    }

    if (esNumero) {
        explorador.getZonaActual()->interactuar(numeroConvertido, &explorador);
    } else {
        explorador.getZonaActual()->interactuar(opcion, &explorador);
    }
}

void EcoMision::verificarFinJuego() {
    if (explorador.getEnergia() <= 0) {
        std::cout << "  Sin energia. Fin del juego." << std::endl;
        activo = false;
        mostrarPantallaFinal(false);
        return;
    }
    if (hayVictoria()) {
        std::cout << std::endl << "MISION CUMPLIDA! La reserva esta limpia." << std::endl;
        activo = false;
        mostrarPantallaFinal(true);
    }
}

bool EcoMision::hayVictoria() const {
    const std::vector<std::string>& codigos = reserva.getCodigos();
    for (int i = 0; i < (int)codigos.size(); i++) {
        Zona* zona = reserva.buscarZona(codigos[i]);
        if (zona->tieneResiduosSinLimpiar()) return false;
        if (zona->tieneFuentesSinRestaurar()) return false;
    }
    return true;
}

void EcoMision::mostrarPantallaFinal(bool victoria) const {
    std::cout << std::endl;
    std::cout << "====================================" << std::endl;
    if (victoria) {
        std::cout << "  VICTORIA!" << std::endl;
    } else {
        std::cout << "  FIN DEl JUEGO" << std::endl;
    }
    std::cout << "====================================" << std::endl;
    explorador.mostrarEstado();
    std::cout << std::endl;
    reserva.mostrarZonas();
    std::cout << "====================================" << std::endl;
}
