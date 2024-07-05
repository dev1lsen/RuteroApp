#include <iostream>
#include <cstdlib> // Para system("clear") o system("CLS")

using namespace std;

// Variables globales para tiempos y retrasos en diferentes direcciones y horas pico
int tiempo_paradero1_ida = 5, tiempo_paradero2_ida = 7, tiempo_paradero3_ida = 3, tiempo_paradero4_ida = 10;
int tiempo_paradero1_vuelta = 6, tiempo_paradero2_vuelta = 8, tiempo_paradero3_vuelta = 4, tiempo_paradero4_vuelta = 11;
int retraso1_ida = 0, retraso2_ida = 0, retraso3_ida = 0, retraso4_ida = 0;
int retraso1_vuelta = 0, retraso2_vuelta = 0, retraso3_vuelta = 0, retraso4_vuelta = 0;
bool hora_pico = false;
void ajustarTiemposParaHoraPico();
void mostrarParaderos(int empresa);
int calcularTiempoDeViaje(int paradero_inicio, int paradero_destino, bool ida);
void mostrarEncabezado();
void limpiarPantalla();
void accionPasajero();
void accionDatero();
void accionConductor();


// Función principal
int main() {
    int opcion;

    do {
        limpiarPantalla();
        mostrarEncabezado();

        cout << "------------------------------------------------" << endl;
        cout << "|                 Menu Principal               |" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| 1. Pasajero                                  |" << endl;
        cout << "| 2. Conductor                                 |" << endl;
        cout << "| 3. Datero                                    |" << endl;
        cout << "| 4. Salir                                     |" << endl;
        cout << "| Seleccione una opcion:                       |" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> opcion;

        limpiarPantalla();
        mostrarEncabezado();

        switch (opcion) {
            case 1:
                accionPasajero();
                break;
            case 2:
                accionConductor();
                break;
            case 3:
                accionDatero();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
                break;
        }

        if (opcion != 4) {
            cout << "Presione cualquier tecla para continuar..." << endl;
            cin.ignore();
            cin.get();
        }

    } while (opcion != 4);

    return 0;
}

// Funciones para ajustar tiempos en horas pico
void ajustarTiemposParaHoraPico() {
    if (hora_pico) {
        tiempo_paradero1_ida += 20;
        tiempo_paradero2_ida += 20;
        tiempo_paradero3_ida += 20;
        tiempo_paradero4_ida += 20;
        tiempo_paradero1_vuelta += 20;
        tiempo_paradero2_vuelta += 20;
        tiempo_paradero3_vuelta += 20;
        tiempo_paradero4_vuelta += 20;
    }
}

// Función para mostrar paraderos según la empresa
void mostrarParaderos(int empresa) {
    switch (empresa) {
        case 1:
            cout << "| 1. Estacion de tren Miguel Grau\t\t|" << endl;
            cout << "| 2. Plaza Miguel Grau\t\t\t|" << endl;
            cout << "| 3. Tingo Maria                                    |" << endl;
            cout << "| 4. UNMSM (puerta 2)                               |" << endl;
            break;
        case 2:
            cout << "| 1. Estacion La Cultura                            |" << endl;
            cout << "| 2. Av. Brasil                                     |" << endl;
            cout << "| 3. Av. Sucre                                      |" << endl;
            cout << "| 4. UNMSM (puerta 2)                               |" << endl;
            break;
        case 3:
            cout << "| 1. Estacion de tren Grau                          |" << endl;
            cout << "| 2. Plaza Grau                                     |" << endl;
            cout << "| 3. Tingo Maria                                    |" << endl;
            cout << "| 4. UNMSM (puerta 2)                               |" << endl;
            break;
        case 4:
            cout << "| 1. Estacion de tren Grau                          |" << endl;
            cout << "| 2. Plaza Grau                                     |" << endl;
            cout << "| 3. UNMSM (puerta 2)                               |" << endl;
            cout << "| 4. Av Colonial                                    |" << endl;
            break;
    }
}

// Función para calcular el tiempo de viaje
int calcularTiempoDeViaje(int paradero_inicio, int paradero_destino, bool ida) {
    int tiempo_viaje = 0;

    if (ida) {
        for (int i = paradero_inicio; i < paradero_destino; ++i) {
            if (i == 1) {
                tiempo_viaje += tiempo_paradero1_ida + retraso1_ida;
            } else if (i == 2) {
                tiempo_viaje += tiempo_paradero2_ida + retraso2_ida;
            } else if (i == 3) {
                tiempo_viaje += tiempo_paradero3_ida + retraso3_ida;
            } else if (i == 4) {
                tiempo_viaje += tiempo_paradero4_ida + retraso4_ida;
            }
        }
    } else {
        for (int i = paradero_inicio - 1; i >= paradero_destino; --i) {
            if (i == 1) {
                tiempo_viaje += tiempo_paradero1_vuelta + retraso1_vuelta;
            } else if (i == 2) {
                tiempo_viaje += tiempo_paradero2_vuelta + retraso2_vuelta;
            } else if (i == 3) {
                tiempo_viaje += tiempo_paradero3_vuelta + retraso3_vuelta;
            } else if (i == 4) {
                tiempo_viaje += tiempo_paradero4_vuelta + retraso4_vuelta;
            }
        }
    }

    return tiempo_viaje;
}

// Función para mostrar encabezado
void mostrarEncabezado() {
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*              PROGRAMA RUTERO                 *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl;
}

// Función para limpiar la pantalla
void limpiarPantalla() {
    #if defined(_WIN32) || defined(_WIN64)
        system("CLS");
    #else
        system("clear");
    #endif
}

// Función para la acción del pasajero
void accionPasajero() {
    int paradero_usuario, paradero_destino;

    cout << "------------------------------------------------" << endl;
    cout << "|              Seleccion de Paraderos          |" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "| Ingrese su empresa de transporte:            |" << endl;
    cout << "| 1. Los chocolates                            |" << endl;
    cout << "| 2. La 40                                     |" << endl;
    cout << "| 3. La 50                                     |" << endl;
    cout << "| 4. La 71                                     |" << endl;
    cout << "| Seleccione una opcion:                       |" << endl;
    cout << "------------------------------------------------" << endl;
    int empresa;
    cin >> empresa;

    cout << "------------------------------------------------" << endl;
    cout << "| Seleccione su paradero actual:               |" << endl;
    mostrarParaderos(empresa);
    cout << "| Seleccione una opcion:                       |" << endl;
    cout << "------------------------------------------------" << endl;
    cin >> paradero_usuario;

    cout << "------------------------------------------------" << endl;
    cout << "| Seleccione su paradero de destino:           |" << endl;
    mostrarParaderos(empresa);
    cout << "| Seleccione una opcion:                       |" << endl;
    cout << "------------------------------------------------" << endl;
    cin >> paradero_destino;

    limpiarPantalla();
    mostrarEncabezado();

    bool direccion_ida = paradero_destino > paradero_usuario;
    int tiempo_viaje = calcularTiempoDeViaje(paradero_usuario, paradero_destino, direccion_ida);

    cout << "--------------------------------------------------------" << endl;
    cout << "| El tiempo de viaje sera de " << tiempo_viaje << " minutos. |" << endl;
    cout << "--------------------------------------------------------" << endl;
}

// Función para la acción del datero
void accionDatero() {
    int empresa, paradero_usuario, opcion_datero, accion_datero, retraso;

    cout << "------------------------------------------------" << endl;
    cout << "|              Reporte del datero              |" << endl;
    cout << "------------------------------------------------" << endl;

    cout << "| Seleccionando empresa de transporte para reportar el trafico  |" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "| Seleccione la empresa de buses:                               |" << endl;
    cout << "| 1. Los chocolates                                             |" << endl;
    cout << "| 2. La 40                                                      |" << endl;
    cout << "| 3. La 50                                                      |" << endl;
    cout << "| 4. La 71                                                      |" << endl;
    cout << "| Seleccione una opcion:                                        |" <<endl;
    cin >> empresa;

    cout << "-----------------------------------------------------" << endl;
    cout << "| Seleccione el numero de paradero a reportar:      |" << endl;
    mostrarParaderos(empresa);
    cout << "| Seleccione una opcion:                            |" << endl;
    cout << "-----------------------------------------------------" << endl;
    cin >> paradero_usuario;

    cout << "-----------------------------------------------------------------------" << endl;
    cout << "| Seleccione la direccion en la que va el bus que se esta retrasando:  |" << endl;
    cout << "| 1. Ida (del paradero 1 al 4)                                         |" << endl;
    cout << "| 2. Vuelta (del paradero 4 al 1)                                      |" << endl;
    cout << "| Seleccione una opcion:                                               |" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cin >> opcion_datero;

    cout << "--------------------------------------------------" << endl;
    cout << "| Seleccione la acción:                          |" << endl;
    cout << "| 1. Reportar retraso                            |" << endl;
    cout << "| 2. Restablecer retraso                         |" << endl;
    cout << "| Seleccione una opcion:                         |" << endl;
    cout << "--------------------------------------------------" << endl;
    cin >> accion_datero;

    if (accion_datero == 1) {
        cout << "--------------------------------------------------" << endl;
        cout << "| Ingrese el retraso en minutos:                 |" << endl;
        cout << "--------------------------------------------------" << endl;
        cin >> retraso;

        if (opcion_datero == 1) {
            if (paradero_usuario == 1) retraso1_ida = retraso;
            else if (paradero_usuario == 2) retraso2_ida = retraso;
            else if (paradero_usuario == 3) retraso3_ida = retraso;
            else if (paradero_usuario == 4) retraso4_ida = retraso;
        } else if (opcion_datero == 2) {
            if (paradero_usuario == 1) retraso1_vuelta = retraso;
            else if (paradero_usuario == 2) retraso2_vuelta = retraso;
            else if (paradero_usuario == 3) retraso3_vuelta = retraso;
            else if (paradero_usuario == 4) retraso4_vuelta = retraso;
        }
    } else if (accion_datero == 2) {
        if (opcion_datero == 1) {
            if (paradero_usuario == 1) retraso1_ida = 0;
            else if (paradero_usuario == 2) retraso2_ida = 0;
            else if (paradero_usuario == 3) retraso3_ida = 0;
            else if (paradero_usuario == 4) retraso4_ida = 0;
        } else if (opcion_datero == 2) {
            if (paradero_usuario == 1) retraso1_vuelta = 0;
            else if (paradero_usuario == 2) retraso2_vuelta = 0;
            else if (paradero_usuario == 3) retraso3_vuelta = 0;
            else if (paradero_usuario == 4) retraso4_vuelta = 0;
        }
    }

    limpiarPantalla();
    mostrarEncabezado();

    cout << "----------------------------------------------------" << endl;
    cout << "| Se ha actualizado el reporte de retrasos         |" << endl;
    cout << "----------------------------------------------------" << endl;
}

// Función para la acción del conductor
void accionConductor() {
    char respuesta;
    cout << "------------------------------------------------" << endl;
    cout << "|           Reporte del Conductor              |" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "| Desea indicar que esta en hora pico? (S/N):  |" << endl;
    cout << "------------------------------------------------" << endl;
    cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's') {
        hora_pico = true;
        ajustarTiemposParaHoraPico();
    } else {
        hora_pico = false;
    }

    limpiarPantalla();
    mostrarEncabezado();

    cout << "------------------------------------------------" << endl;
    cout << "| Se ha actualizado el estado de hora pico.     |" << endl;
    cout << "------------------------------------------------" << endl;
}
