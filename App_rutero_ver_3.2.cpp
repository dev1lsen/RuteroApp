/* 
Código fuente de App Rutero
Lenguaje de codificación: C++
Desarrollo, diseño y programación: Equipo Rutero
Universidad Nacional Mayor de San Marcos - Facultad de Ingeniería Industrial
Curso: Computación y programación
Ciclo: 2024-I
Subido por: Sebastian Mamani
*/

#include <iostream>
#include <cstdlib>
#include <sstream> // Para std::istringstream
#include <iomanip> // Para std::get_time

using namespace std;

// Variables globales para tiempos y retrasos en diferentes direcciones y horas pico
int tiempo_paradero1_ida = 5, tiempo_paradero2_ida = 7, tiempo_paradero3_ida = 3, tiempo_paradero4_ida = 10;
int tiempo_paradero1_vuelta = 6, tiempo_paradero2_vuelta = 8, tiempo_paradero3_vuelta = 4, tiempo_paradero4_vuelta = 11;
int retraso1_ida = 0, retraso2_ida = 0, retraso3_ida = 0, retraso4_ida = 0;
int retraso1_vuelta = 0, retraso2_vuelta = 0, retraso3_vuelta = 0, retraso4_vuelta = 0;
bool hora_pico = false;

// Función para validar la hora en formato HH:MM
bool validarHora(const string& hora) {
    istringstream ss(hora);
    int hh, mm;
    char delim;
    
    if (!(ss >> hh >> delim >> mm) || delim != ':' || hh < 0 || hh >= 24 || mm < 0 || mm >= 60) {
        return false;
    }

    return true;
}

// Función principal
int main() {
    int opcion;

    do {
        limpiarPantalla();
        mostrarEncabezado();
        mostrarMenuPrincipal();
        opcion = seleccionarOpcion(1, 4);

        if (opcion != 4) {
            string hora = obtenerHora();
            verificarHoraPico(hora);
            ajustarTiemposParaHoraPico();
        }

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
                cout << "Saliendo del sistema..." << endl;
                break;
        }

        if (opcion != 4) {
            cout << "Presione cualquier tecla para volver al menu principal..." << endl;
            cin.ignore().get();
        }

    } while (opcion != 4);

    return 0;
}

// Función para ajustar tiempos en horas pico
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
    cout << "*                 RUTERO APP                   *" << endl;
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

// Función para obtener la hora en formato HH:MM
string obtenerHora() {
    string hora;
    do {
        cout << "------------------------------------------------" << endl;
        cout << "| Ingrese la hora actual (formato 24h HH:MM):   |" << endl;
        cout << "| (Por ejemplo, para 7:30 PM ingrese 19:30):    |" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> hora;
    } while (!validarHora(hora));

    return hora;
}

// Función para verificar si es hora pico
void verificarHoraPico(const string& hora) {
    int hh = stoi(hora.substr(0, 2));
    if ((hh >= 7 && hh < 10) || (hh >= 17 && hh < 20)) {
        hora_pico = true;
    } else {
        hora_pico = false;
    }
}

// Función para la acción del pasajero
void accionPasajero() {
    int paradero_usuario, paradero_destino;

    string hora = obtenerHora();
    verificarHoraPico(hora);

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

    string hora = obtenerHora();
    verificarHoraPico(hora);

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
        cout << "------------------------------------------------" << endl;
        cout << "| Ingrese el tiempo de retraso en minutos:      |" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> retraso;

        if (opcion_datero == 1) {
            if (paradero_usuario == 1) retraso1_ida = retraso;
            else if (paradero_usuario == 2) retraso2_ida = retraso;
            else if (paradero_usuario == 3) retraso3_ida = retraso;
            else if (paradero_usuario == 4) retraso4_ida = retraso;
        } else {
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
        } else {
            if (paradero_usuario == 1) retraso1_vuelta = 0;
            else if (paradero_usuario == 2) retraso2_vuelta = 0;
            else if (paradero_usuario == 3) retraso3_vuelta = 0;
            else if (paradero_usuario == 4) retraso4_vuelta = 0;
        }
    }

    limpiarPantalla();
    mostrarEncabezado();

    cout << "---------------------------------------------" << endl;
    cout << "| Accion realizada correctamente.           |" << endl;
    cout << "---------------------------------------------" << endl;
}

// Función para la acción del conductor
void accionConductor() {
    string hora = obtenerHora();
    verificarHoraPico(hora);

    limpiarPantalla();
    mostrarEncabezado();

    cout << "------------------------------------------------" << endl;
    cout << "| La hora ha sido registrada correctamente.    |" << endl;
    cout << "------------------------------------------------" << endl;
}

// Función para mostrar el menú principal
void mostrarMenuPrincipal() {
    cout << "------------------------------------------------" << endl;
    cout << "|     Bienvenido al sistema de rutero          |" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "| Seleccione su tipo de usuario:               |" << endl;
    cout << "| 1. Pasajero                                  |" << endl;
    cout << "| 2. Conductor                                 |" << endl;
    cout << "| 3. Datero                                    |" << endl;
    cout << "| 4. Salir                                     |" << endl;
    cout << "------------------------------------------------" << endl;
}

int seleccionarOpcion(int min, int max) {
    int opcion;
    do {
        cout << "Seleccione una opcion (" << min << "-" << max << "): ";
        cin >> opcion;
    } while (opcion < min || opcion > max);
    return opcion;
}
