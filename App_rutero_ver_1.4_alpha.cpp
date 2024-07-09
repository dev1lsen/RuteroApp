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

#include <iostream>
using namespace std;
// se usa el void por que solo se va a imprimir
void mostrar_equipo(){
    cout << "----------------------------------------------------" << endl;
    cout << "|                       UNMSM                      |" << endl;
    cout << "|               Bienvenido a Rutero                |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|        Desarrollado por Grupo 8 - Seccion 6      |" << endl; 
    cout << "----------------------------------------------------" << endl;
    cout << "|  Mamani Huamani Sebastian Eduardo    24170144    |" << endl;
    cout << "|  Quispe Alarcon Samanta Fernanda     24170192    |" <<endl;
    cout << "|  Rafael Vilca Victor Raul            24170102    |" <<endl;
    cout << "|  Fernandez Huaman Melani Araceli     23170250    |" <<endl;
	cout << "|  Crinel Stalin Atero Lopez           23170279    |" <<endl;
    cout << "----------------------------------------------------" << endl;
}
void mostrar_menu_usuario(){
        cout << "--------------------------------------------" << endl;
        cout << "|           Seleccionar Usuario           |" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "| 1. Pasajero                             |" << endl;
        cout << "| 2. Conductor                            |" << endl;
        cout << "| 3. Datero                               |" << endl;
        cout << "| 4. Salir del programa                   |" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "| Ingrese el tipo de usuario para usar el |" << endl; 
        cout << "| programa(ingrese un numero del 1 al 4): |" <<endl;
        cout << "-------------------------------------------" << endl;
}
int validar_seleccion(int a, int b, int c){
    // ¿esta la seleccion entero "a" dentro del intervalo [entero "b"; entero "c"]?
    // funcion que validara si el numero entero "a" se encuentra entre los enteros "b" y "c"
    int valor;
    if(a<=c && a>=b){
        valor=1;
        cout << "-------------------------------------------" << endl;
        cout << "| Opcion seleccionada correctamente       |" << endl;
        cout << "-------------------------------------------" << endl;
    }
    else{
        valor=0;
        cout << "-------------------------------------------" << endl;
        cout<< "| Seleccion fuera de rango                 |" << endl;
        cout << "-------------------------------------------" << endl;
    }
    return valor;
}
int main() {
    int hora, minutos, tiempo_actual, empresa, usuario, paradero_usuario, paradero_destino, opcion_datero, accion_datero, pausa;
    int retraso1_dir1 = 0, retraso1_dir2 = 0;
    int retraso2_dir1 = 0, retraso2_dir2 = 0;
    int retraso3_dir1 = 0, retraso3_dir2 = 0;
    int retraso4_dir1 = 0, retraso4_dir2 = 0;
    //menu inicial de seleccion de usuario
    while (true) {
        cout << "--------------------------------------------" << endl;
        cout << "|           Seleccionar Usuario           |" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "| 1. Pasajero                             |" << endl;
        cout << "| 2. Conductor                            |" << endl;
        cout << "| 3. Datero                               |" << endl;
        cout << "| 4. Salir del programa                   |" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "| Ingrese el tipo de usuario que desea elegir para usar el programa (1-4): |" <<endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cin >> usuario;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    // validando numero de usuario

        if (usuario < 1 || usuario > 4) {
            cout << "--------------------------------------------" << endl;
            cout << "|       Error en seleccionar usuario       |" << endl;
            cout << "--------------------------------------------" << endl;
            cout << "|Opcion no valida. Intentelo de nuevo.     |" << endl;
            cout << "--------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            continue;
        }

        if (usuario == 4) {
            cout << "---------------------------------------------" << endl;
            cout << "|         ¡GRACIAS POR USAR RUTERO!         |" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "| Saliendo del programa.                    |" << endl;
            cout << "---------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        }
        // Mostrando ventana de establecer hora de acuerdo al usuario seleccionado
        switch (usuario)
        {
            // para el pasajero
        case 1: 
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "|                              Establecer hora                             |" << endl;
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "| Para poder calcular el tiempo que va a esperar el bus:                   |" <<endl;
            cout << "| Ingrese la hora actual en formato HH (horas) y MM (minutos):             |" <<endl;
            cout << "----------------------------------------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
            //para el conductor
        case 2:
            cout << "----------------------------------------------------------------------------" << endl;
            cout << "|                              Establecer hora                             |" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "| Para poder calcular el tiempo de viaje al paradero a consultar:          |" <<endl;
            cout << "| Ingrese la hora actual en formato HH (horas) y MM (minutos):             |" <<endl; 
            cout << "----------------------------------------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
            //para el datero (persona que reporta el estado del tráfico en los paraderos)
        case 3:
            cout << "|                                Establecer hora                                |" << endl;
            cout << "---------------------------------------------------------------------------------" << endl;
            cout << "| Para poder reportar el estado de los restrasos de los buses en los paraderos: |" <<endl;
            cout << "| Ingrese la hora actual en formato HH (0 a 24 horas) y MM (minutos):           |" <<endl;    
            cout << "---------------------------------------------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
                               
        default:
            break;
        }
        
        cin >> hora >> minutos;
        // validando la hora
        if (hora < 0 || hora > 23 || minutos < 0 || minutos > 59) {
            cout << "---------------------------------------------------" << endl;
            cout << "|           Error al establecer la hora            |" << endl;
            cout << "---------------------------------------------------" << endl;
            cout << "| Hora no valida. Intentelo de nuevo.              |" <<endl;   
            cout << "----------------------------------------------------" << endl; 
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "" << endl;
            continue;
        }
        // transformacion de la hora en minutos (1h<>60 minutos) y se suma los minutos para tener el tiempo 
        // transcurridos en el día en minutos para facilitar los cálculos
        tiempo_actual = hora * 60 + minutos;
        
        // Se muestra el menu de seleccion de la empresa con la que se quiere trabajar
        cout << "------------------------------------------------------" << endl;
        cout << "|         Seleccionando empresa de transporte        |" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "| Seleccione la empresa de buses:                    |" << endl;
        cout << "| 1. Los chocolates                                  |" << endl;
        cout << "| 2. La 40                                           |" << endl;
        cout << "| 3. La 50                                           |" << endl;
        cout << "| 4. La 71                                           |" << endl;
        cout << "| Seleccione una opcion:                             |" <<endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        // Se lee el valor ingresado
        cin >> empresa;
        // Se valida el valor ingresado para seleccionar la empresa
        if (empresa < 1 || empresa > 4) {
            cout << "-----------------------------------------------------" << endl;
            cout << "|           Error al seleccionar empresa            |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Opcion no valida. Intentelo de nuevo.             |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            continue;
        }
        switch (empresa)
        {
        case 1:
            cout << "-----------------------------------------------------" << endl;
            cout << "|     Seleccionando paradero de Los chocolates      |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Seleccione el número de paradero inicial:         |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| 1. Estacion de tren Miguel Grau                   |" << endl;
            cout << "| 2. Plaza Miguel Grau                              |" << endl;
            cout << "| 3. Tingo Maria                                    |" << endl;
            cout << "| 4. UNMSM (puerta 2)                               |" << endl;
            cout << "| Seleccione una opcion:                            |" << endl;
            cin >> paradero_usuario;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 2:
            cout << "-----------------------------------------------------" << endl;
            cout << "|        Seleccionando paradero de La 40            |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Seleccione el numero de paradero inicial:         |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| 1. Estacion La Cultura                            |" << endl;
            cout << "| 2. Av. Brasil                                     |" << endl;
            cout << "| 3. Av. Sucre                                      |" << endl;
            cout << "| 4. UNMSM (puerta 2)                               |" << endl;
            cout << "| Seleccione una opcion:                            |" << endl;
            cin >> paradero_usuario;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 3:
            cout << "-----------------------------------------------------" << endl;
            cout << "|        Seleccionando paradero de La 50            |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Seleccione el numero de paradero inicial:         |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| 1. Estacion de tren Grau                          |" << endl;
            cout << "| 2. Plaza Grau                                     |" << endl;
            cout << "| 3. Tingo Maria                                    |" << endl;
            cout << "| 4. UNMSM (puerta 2)                               |" << endl;
            cout << "| Seleccione una opcion:                            |" << endl;
            cin >> paradero_usuario;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 4:
            cout << "-----------------------------------------------------" << endl;
            cout << "|        Seleccionando paradero de La 71            |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Seleccione el numero de paradero inicial:         |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| 1. Estacion de tren Grau                          |" << endl;
            cout << "| 2. Plaza Grau                                     |" << endl;
            cout << "| 3. UNMSM (puerta 2)                               |" << endl;
            cout << "| 4. Av Colonial                                    |" << endl;
            cout << "| Seleccione una opcion:                            |" << endl;
            cin >> paradero_usuario;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        }
        if (paradero_usuario < 1 || paradero_usuario > 4) {
            cout << "-----------------------------------------------------" << endl;
            cout << "|           Error al seleccionar paradero           |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Paradero no valido. Intentelo de nuevo.           |" << endl;
            cout << "-----------------------------------------------------" << endl;
            continue;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }
        switch (empresa)
        {
        case 1:
            cout << "-----------------------------------------------------" << endl;
            cout << "|     Seleccionando paradero de Los chocolates      |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Seleccione el numero de paradero destino:         |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| 1. Estacion de tren Miguel Grau                   |" << endl;
            cout << "| 2. Plaza Miguel Grau                              |" << endl;
            cout << "| 3. Tingo Maria                                    |" << endl;
            cout << "| 4. UNMSM (puerta 2)                               |" << endl;
            cout << "| Seleccione una opcion:                            |" << endl;
            cin >> paradero_destino;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 2:
            cout << "-----------------------------------------------------" << endl;
            cout << "|        Seleccionando paradero de La 40            |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Seleccione el numero de paradero destino:         |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| 1. Estacion La Cultura                            |" << endl;
            cout << "| 2. Av. Brasil                                     |" << endl;
            cout << "| 3. Av. Sucre                                      |" << endl;
            cout << "| 4. UNMSM (puerta 2)                               |" << endl;
            cout << "| Seleccione una opcion:                            |" << endl;
            cin >> paradero_destino;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 3:
            cout << "-----------------------------------------------------" << endl;
            cout << "|        Seleccionando paradero de La 50            |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Seleccione el número de paradero destino:         |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| 1. Estacion de tren Grau                          |" << endl;
            cout << "| 2. Plaza Grau                                     |" << endl;
            cout << "| 3. Tingo Maria                                    |" << endl;
            cout << "| 4. UNMSM (puerta 2)                               |" << endl;
            cout << "| Seleccione una opcion:                            |" << endl;
            cin >> paradero_destino;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        case 4:
            cout << "-----------------------------------------------------" << endl;
            cout << "|        Seleccionando paradero de La 71            |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Seleccione el numero de paradero destino:         |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| 1. Estacion de tren Grau                          |" << endl;
            cout << "| 2. Plaza Grau                                     |" << endl;
            cout << "| 3. UNMSM (puerta 2)                               |" << endl;
            cout << "| 4. Av Colonial                                    |" << endl;
            cout << "| Seleccione una opcion:                            |" << endl;
            cin >> paradero_destino;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            break;
        }
    
        if (paradero_destino < 1 || paradero_destino > 4) {
            cout << "-----------------------------------------------------" << endl;
            cout << "|           Error al seleccionar paradero           |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Paradero no valido. Inténtelo de nuevo.           |" << endl;
            cout << "-----------------------------------------------------" << endl;
            continue;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }

        int direccion = paradero_destino - paradero_usuario; // Positiva para ida, negativa para vuelta

        int tiempo_paradero1 = 0, tiempo_paradero2 = 0, tiempo_paradero3 = 0, tiempo_paradero4 = 0;

        if (empresa == 1) {
            tiempo_paradero1 = 20 + retraso1_dir1;
            tiempo_paradero2 = 20 + retraso2_dir1;
            tiempo_paradero3 = 25 + retraso3_dir1;
            tiempo_paradero4 = 30 + retraso4_dir1;
        } else if (empresa == 2) {
            tiempo_paradero1 = 15 + retraso1_dir1;
            tiempo_paradero2 = 25 + retraso2_dir1;
            tiempo_paradero3 = 25 + retraso3_dir1;
            tiempo_paradero4 = 20 + retraso4_dir1;
        } else if (empresa == 3) {
            tiempo_paradero1 = 15 + retraso1_dir1;
            tiempo_paradero2 = 20 + retraso2_dir1;
            tiempo_paradero3 = 30 + retraso3_dir1;
            tiempo_paradero4 = 20 + retraso4_dir1;
        } else if (empresa == 4) {
            tiempo_paradero1 = 30 + retraso1_dir1;
            tiempo_paradero2 = 15 + retraso2_dir1;
            tiempo_paradero3 = 25 + retraso3_dir1;
            tiempo_paradero4 = 25 + retraso4_dir1;
        }

        if ((hora >= 6 && minutos >= 30 && hora <= 8) ||
            (hora >= 14 && hora <= 16) ||
            (hora >= 18 && hora <= 21)) {
            tiempo_paradero1 += 15;
            tiempo_paradero2 += 15;
            tiempo_paradero3 += 15;
            tiempo_paradero4 += 15;
        }

        if (usuario == 1) {
            cout << "------------------------------------------------" << endl;
            cout << "|         Reporte de buses al pasajero         |" << endl;
            cout << "------------------------------------------------" << endl;

            if (hora < 5 || hora >= 23) {
                cout << "| No hay buses en circulacion en este horario. | " << endl;
                cout << "------------------------------------------------" << endl;
                continue;
            }

            int proximo_bus = 5 * 60; // El primer bus sale a las 05:00 AM
            int retraso_acumulado = 0;

            // Calcular el próximo bus
            while (proximo_bus <= tiempo_actual) {
                if (direccion > 0) {
                    retraso_acumulado += (retraso1_dir1 + retraso2_dir1 + retraso3_dir1 + retraso4_dir1) / 4;
                } else {
                    retraso_acumulado += (retraso1_dir2 + retraso2_dir2 + retraso3_dir2 + retraso4_dir2) / 4;
                }
                proximo_bus += 8 + retraso_acumulado;
            }

            int segundo_bus = proximo_bus + 8 + (direccion > 0 ? (retraso1_dir1 + retraso2_dir1 + retraso3_dir1 + retraso4_dir1) / 4 : (retraso1_dir2 + retraso2_dir2 + retraso3_dir2 + retraso4_dir2) / 4);

            cout << "--------------------------------------------------------" << endl;
            cout << "| El proximo bus llegara en " << proximo_bus - tiempo_actual << " minutos. |" << endl;
            cout << "| El segundo bus llegara en " << segundo_bus - tiempo_actual << " minutos. |" << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }

        if (usuario == 2) {
            cout << "------------------------------------------------" << endl;
            cout << "|              Reporte al conductor            |" << endl;
            cout << "------------------------------------------------" << endl;

            int tiempo_viaje = 0;

            if (direccion > 0) {
                for (int i = paradero_usuario; i < paradero_destino; ++i) {
                    if (i == 1) {
                        tiempo_viaje += tiempo_paradero1;
                    } else if (i == 2) {
                        tiempo_viaje += tiempo_paradero2;
                    } else if (i == 3) {
                        tiempo_viaje += tiempo_paradero3;
                    } else if (i == 4) {
                        tiempo_viaje += tiempo_paradero4;
                    }
                }
            } else {
                for (int i = paradero_usuario - 1; i >= paradero_destino; --i) {
                    if (i == 1) {
                        tiempo_viaje += tiempo_paradero1;
                    } else if (i == 2) {
                        tiempo_viaje += tiempo_paradero2;
                    } else if (i == 3) {
                        tiempo_viaje += tiempo_paradero3;
                    } else if (i == 4) {
                        tiempo_viaje += tiempo_paradero4;
                    }
                }
            }
            cout << "--------------------------------------------------------" << endl;
            cout << "| El tiempo de viaje sera de " << tiempo_viaje << " minutos. |" << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }

        if (usuario == 3) {
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
            // Se lee el valor ingresado
            cin >> empresa;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            // Se valida el valor ingresado para seleccionar la empresa
            if (empresa < 1 || empresa > 4) {
                cout << "-----------------------------------------------------------------" << endl;
                cout << "|                 Error al seleccionar empresa                  |" << endl;
                cout << "-----------------------------------------------------------------" << endl;
                cout << "| Opcion no valida. Intentelo de nuevo.                         |" << endl;
                cout << "-----------------------------------------------------------------" << endl;
                continue;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
            }
            switch (empresa)
            {
            case 1:
                cout << "-----------------------------------------------------" << endl;
                cout << "|     Seleccionando paradero de Los chocolates      |" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "| Seleccione el numero de paradero a reportar:      |" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "| 1. Estacion de tren Miguel Grau                   |" << endl;
                cout << "| 2. Plaza Miguel Grau                              |" << endl;
                cout << "| 3. Tingo Maria                                    |" << endl;
                cout << "| 4. UNMSM (puerta 2)                               |" << endl;
                cout << "| Seleccione una opcion:                            |" << endl;
                cin >> paradero_usuario;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                break;
            case 2:
                cout << "-----------------------------------------------------" << endl;
                cout << "|        Seleccionando paradero de La 40            |" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "| Seleccione el numero de paradero a reportar:      |" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "| 1. Estacion La Cultura                            |" << endl;
                cout << "| 2. Av. Brasil                                     |" << endl;
                cout << "| 3. Av. Sucre                                      |" << endl;
                cout << "| 4. UNMSM (puerta 2)                               |" << endl;
                cout << "| Seleccione una opcion:                            |" << endl;
                cin >> paradero_usuario;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                break;
            case 3:
                cout << "-----------------------------------------------------" << endl;
                cout << "|        Seleccionando paradero de La 50            |" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "| Seleccione el numero de paradero a reportar:      |" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "| 1. Estacion de tren Grau                          |" << endl;
                cout << "| 2. Plaza Grau                                     |" << endl;
                cout << "| 3. Tingo Maria                                    |" << endl;
                cout << "| 4. UNMSM (puerta 2)                               |" << endl;
                cout << "| Seleccione una opcion:                            |" << endl;
                cin >> paradero_usuario;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                break;
            case 4:
                cout << "-----------------------------------------------------" << endl;
                cout << "|        Seleccionando paradero de La 71            |" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "| Seleccione el numero de paradero a reportar:      |" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "| 1. Estacion de tren Grau                          |" << endl;
                cout << "| 2. Plaza Grau                                     |" << endl;
                cout << "| 3. UNMSM (puerta 2)                               |" << endl;
                cout << "| 4. Av Colonial                                    |" << endl;
                cout << "| Seleccione una opcion:                            |" << endl;
                cin >> paradero_usuario;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                break;
            }
            if (paradero_usuario < 1 || paradero_usuario > 4) {
            cout << "-----------------------------------------------------" << endl;
            cout << "|           Error al seleccionar paradero           |" << endl;
            cout << "-----------------------------------------------------" << endl;
            cout << "| Paradero no valido. Intentelo de nuevo.           |" << endl;
            cout << "-----------------------------------------------------" << endl;
            continue;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            }
            cout << "-----------------------------------------------------------------------" << endl;
            cout << "|   Seleccionando direccion de la ruta de la empresa de transporte    |" << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cout << "| Seleccione la direccion en la que va el bus que se esta retrasando: |" << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cout << "| 1. Ida     (del paradero 1 al 4)                                    |" << endl;
            cout << "| 2. Vuelta  (del paradero 4 al 1)                                    |" << endl;
            cout << "| Seleccione una opción:                                              |" << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cin >> opcion_datero;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            if (opcion_datero < 1 || opcion_datero > 2) {
                cout << "------------------------------------------------------------------" << endl;
                cout << "|    Error seleccionando la direccion de la ruta de la empresa   |" << endl;
                cout << "------------------------------------------------------------------" << endl;
                cout << "| Opción no valida. Intentelo de nuevo.                          |" << endl;
                cout << "------------------------------------------------------------------" << endl;
                continue;
            }
            cout << "--------------------------------------------------" << endl;
            cout << "|   Seleccionar tipo de reporte en el paradero   |" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "| Seleccione la acción:                          |" << endl;
            cout << "| 1. Reportar retraso                            |" << endl;
            cout << "| 2. Restablecer retraso                         |" << endl;
            cout << "| Seleccione una opcion:                         |" << endl;
            cout << "--------------------------------------------------" << endl;
            cin >> accion_datero;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            if (accion_datero == 1) {
                int retraso;
                cout << "--------------------------------------------------" << endl;
                cout << "|   Añadiendo retraso al paradero seleccionado   |" << endl;
                cout << "--------------------------------------------------" << endl; 
                cout << "| Ingrese el retraso en minutos:                 |" << endl;
                cout << "--------------------------------------------------" << endl; 
                cin >> retraso;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;

                if (opcion_datero == 1) {
                    if (paradero_usuario == 1) {
                        retraso1_dir1 += retraso;
                    } else if (paradero_usuario == 2) {
                        retraso2_dir1 += retraso;
                    } else if (paradero_usuario == 3) {
                        retraso3_dir1 += retraso;
                    } else if (paradero_usuario == 4) {
                        retraso4_dir1 += retraso;
                    }
                } else if (opcion_datero == 2) {
                    if (paradero_usuario == 1) {
                        retraso1_dir2 += retraso;
                    } else if (paradero_usuario == 2) {
                        retraso2_dir2 += retraso;
                    } else if (paradero_usuario == 3) {
                        retraso3_dir2 += retraso;
                    } else if (paradero_usuario == 4) {
                        retraso4_dir2 += retraso;
                    }
                }
                cout << "---------------------------------------" << endl;
                cout << "|           Reporte del datero        |" << endl;
                cout << "---------------------------------------" << endl;
                cout << "| Retraso reportado exitosamente.     |" << endl;
                cout << "---------------------------------------" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
            } else if (accion_datero == 2) {
                if (opcion_datero == 1) {
                    if (paradero_usuario == 1) {
                        retraso1_dir1 = 0;
                    } else if (paradero_usuario == 2) {
                        retraso2_dir1 = 0;
                    } else if (paradero_usuario == 3) {
                        retraso3_dir1 = 0;
                    } else if (paradero_usuario == 4) {
                        retraso4_dir1 = 0;
                    }
                } else if (opcion_datero == 2) {
                    if (paradero_usuario == 1) {
                        retraso1_dir2 = 0;
                    } else if (paradero_usuario == 2) {
                        retraso2_dir2 = 0;
                    } else if (paradero_usuario == 3) {
                        retraso3_dir2 = 0;
                    } else if (paradero_usuario == 4) {
                        retraso4_dir2 = 0;
                    }
                }
                cout << "-----------------------------------------" << endl;
                cout << "|           Reporte del datero          |" << endl;
                cout << "-----------------------------------------" << endl;
                cout << "| Retraso restablecido a 0 exitosamente.| " << endl;
                cout << "-----------------------------------------" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
            } else {
                cout << "|      Error al seleccionar accion      |" << endl;
                cout << "-----------------------------------------" << endl;
                cout << "| Accion no valida. Intentelo de nuevo.  |" << endl;
                cout << "-----------------------------------------" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                continue;
            }
            


        }
        cout << "-----------------------------------------" << endl;
        cout << " Presione cualquier tecla para continuar" <<endl;
        cout << "-----------------------------------------" << endl;
            cin >>pausa;
            if (pausa==0) continue;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
    }

    return 0;
}
