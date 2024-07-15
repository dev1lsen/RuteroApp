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
using namespace std;
int continuar_ejecucion();
int mostrar_seleccionar_sentido ();
int mostrar_menu_usuario();
int mostrar_equipo();
int validar_seleccion(int a, int b, int c);
int actualizar_retraso_reportado(int empresa, int paradero, int sentido, 
                                int retraso1_dir1, int retraso1_dir2,
                                int retraso2_dir1, int retraso2_dir2,
                                int retraso3_dir1, int retraso3_dir2,
                                int retraso4_dir1, int retraso4_dir2);
int hora_actual();
int accion_pasajero(int tiempo_actual,int retraso1_dir1,int retraso1_dir2,int retraso2_dir1,int retraso2_dir2,int retraso3_dir1,int retraso3_dir2,int retraso4_dir1,int retraso4_dir2);
int accion_conductor(int tiempo_actual, 
                int retraso1_dir1, int retraso2_dir1, int retraso3_dir1, int retraso4_dir1, int retraso1_dir2, int retraso2_dir2, int retraso3_dir2, int retraso4_dir2, 
                int tiempo_paradero_1_2_1, int tiempo_paradero_2_3_1, int tiempo_paradero_3_4_1 , int tiempo_paradero_4_5_1,int tiempo_paradero_1_2_2, int tiempo_paradero_2_3_2, int tiempo_paradero_3_4_2 , int tiempo_paradero_4_5_2, 
                int tiempo_paradero_1_2_3, int tiempo_paradero_2_3_3, int tiempo_paradero_3_4_3, int tiempo_paradero_4_5_3, int tiempo_paradero_1_2_4, int tiempo_paradero_2_3_4, int tiempo_paradero_3_4_4, int tiempo_paradero_4_5_4, 
                int tiempo_paradero_2_1_1, int tiempo_paradero_3_2_1, int tiempo_paradero_4_3_1, int tiempo_paradero_5_4_1, int tiempo_paradero_2_1_2, int tiempo_paradero_3_2_2, int tiempo_paradero_4_3_2, int tiempo_paradero_5_4_2, 
                int tiempo_paradero_2_1_3, int tiempo_paradero_3_2_3, int tiempo_paradero_4_3_3, int tiempo_paradero_5_4_3,int tiempo_paradero_2_1_4, int tiempo_paradero_3_2_4, int tiempo_paradero_4_3_4, int tiempo_paradero_5_4_4);

int accion_datero(int retraso1_dir1, int retraso1_dir2,int retraso2_dir1,int retraso2_dir2,int retraso3_dir1,int  retraso3_dir2,int retraso4_dir1,int retraso4_dir2);
int mostrar_lista_empresas();
int mostrar_seleccionar_paradero_inicial_usuario (int empresa);
int mostrar_seleccionar_paradero_destino_usuario (int empresa, int paradero_inicial);
int reporte_buses_pasajero(int paradero_inicial, int paradero_final, int tiempo_actual, int retraso1_dir1, int retraso2_dir1, int retraso3_dir1, int retraso4_dir1, int retraso1_dir2, int retraso2_dir2, int retraso3_dir2, int retraso4_dir2);
long double reporte_conductor(int empresa,int paradero_inicial,int paradero_final, int tiempo_actual, 
                int retraso1_dir1, int retraso2_dir1, int retraso3_dir1, int retraso4_dir1, int retraso1_dir2, int retraso2_dir2, int retraso3_dir2, int retraso4_dir2, 
                int tiempo_paradero_1_2_1, int tiempo_paradero_2_3_1, int tiempo_paradero_3_4_1 , int tiempo_paradero_4_5_1,int tiempo_paradero_1_2_2, int tiempo_paradero_2_3_2, int tiempo_paradero_3_4_2 , int tiempo_paradero_4_5_2, 
                int tiempo_paradero_1_2_3, int tiempo_paradero_2_3_3, int tiempo_paradero_3_4_3, int tiempo_paradero_4_5_3, int tiempo_paradero_1_2_4, int tiempo_paradero_2_3_4, int tiempo_paradero_3_4_4, int tiempo_paradero_4_5_4, 
                int tiempo_paradero_2_1_1, int tiempo_paradero_3_2_1, int tiempo_paradero_4_3_1, int tiempo_paradero_5_4_1, int tiempo_paradero_2_1_2, int tiempo_paradero_3_2_2, int tiempo_paradero_4_3_2, int tiempo_paradero_5_4_2, 
                int tiempo_paradero_2_1_3, int tiempo_paradero_3_2_3, int tiempo_paradero_4_3_3, int tiempo_paradero_5_4_3,int tiempo_paradero_2_1_4, int tiempo_paradero_3_2_4, int tiempo_paradero_4_3_4, int tiempo_paradero_5_4_4);  
int main() {
    int ejecucion=1;
    int tiempo_actual, usuario;
    int retraso1_dir1 = 0, retraso1_dir2 = 0;
    int retraso2_dir1 = 0, retraso2_dir2 = 0;
    int retraso3_dir1 = 0, retraso3_dir2 = 0;
    int retraso4_dir1 = 0, retraso4_dir2 = 0;
    int tiempo_paradero_1_2_1 = 0, tiempo_paradero_2_3_1 = 0, tiempo_paradero_3_4_1 = 0, tiempo_paradero_4_5_1 = 0;
    int tiempo_paradero_1_2_2 = 0, tiempo_paradero_2_3_2 = 0, tiempo_paradero_3_4_2 = 0, tiempo_paradero_4_5_2 = 0;
    int tiempo_paradero_1_2_3 = 0, tiempo_paradero_2_3_3 = 0, tiempo_paradero_3_4_3 = 0, tiempo_paradero_4_5_3 = 0;
    int tiempo_paradero_1_2_4 = 0, tiempo_paradero_2_3_4 = 0, tiempo_paradero_3_4_4 = 0, tiempo_paradero_4_5_4 = 0;
    int tiempo_paradero_2_1_1 = 0, tiempo_paradero_3_2_1 = 0, tiempo_paradero_4_3_1 = 0, tiempo_paradero_5_4_1 = 0;
    int tiempo_paradero_2_1_2 = 0, tiempo_paradero_3_2_2 = 0, tiempo_paradero_4_3_2 = 0, tiempo_paradero_5_4_2 = 0;
    int tiempo_paradero_2_1_3 = 0, tiempo_paradero_3_2_3 = 0, tiempo_paradero_4_3_3 = 0, tiempo_paradero_5_4_3 = 0;
    int tiempo_paradero_2_1_4 = 0, tiempo_paradero_3_2_4 = 0, tiempo_paradero_4_3_4 = 0, tiempo_paradero_5_4_4 = 0;


    // mostrar equipo
    mostrar_equipo();
    //menu inicial de seleccion de usuario
    while (ejecucion) {
        int opcion=0;
        do{
            //Mostrar menu de seleccion de usuario
            mostrar_menu_usuario();
            //Lectura de seleccion de usuario
            cin >> usuario;

            // AÑADIR FUNCION DE SALTO AQUI  

            // Validamos la seleccion dentro del rango de la lista mostrada
            opcion=validar_seleccion(usuario, 1, 4);

        }while(opcion!=1);
     
        //Obtenemos la hora actual en minutos transcurridos
        

        //Iniciamos las acciones de acuerdo al usuario o si sale del programa
        switch (usuario)
        {
        case 1:
            tiempo_actual=hora_actual();
            accion_pasajero(tiempo_actual,retraso1_dir1,retraso1_dir2,retraso2_dir1,retraso2_dir2,retraso3_dir1,retraso3_dir2,retraso4_dir1,retraso4_dir2);
            ejecucion=continuar_ejecucion();
            break;
        case 2:
            tiempo_actual=hora_actual();
            accion_conductor(tiempo_actual, 
                retraso1_dir1,  retraso2_dir1,  retraso3_dir1,  retraso4_dir1,  retraso1_dir2,  retraso2_dir2,  retraso3_dir2,  retraso4_dir2, 
                tiempo_paradero_1_2_1, tiempo_paradero_2_3_1, tiempo_paradero_3_4_1 , tiempo_paradero_4_5_1, tiempo_paradero_1_2_2,  tiempo_paradero_2_3_2,  tiempo_paradero_3_4_2 ,  tiempo_paradero_4_5_2, 
                tiempo_paradero_1_2_3, tiempo_paradero_2_3_3, tiempo_paradero_3_4_3, tiempo_paradero_4_5_3,  tiempo_paradero_1_2_4,  tiempo_paradero_2_3_4,  tiempo_paradero_3_4_4,  tiempo_paradero_4_5_4, 
                tiempo_paradero_2_1_1, tiempo_paradero_3_2_1, tiempo_paradero_4_3_1, tiempo_paradero_5_4_1,  tiempo_paradero_2_1_2,  tiempo_paradero_3_2_2,  tiempo_paradero_4_3_2,  tiempo_paradero_5_4_2, 
                tiempo_paradero_2_1_3, tiempo_paradero_3_2_3, tiempo_paradero_4_3_3,  tiempo_paradero_5_4_3, tiempo_paradero_2_1_4,  tiempo_paradero_3_2_4,  tiempo_paradero_4_3_4,  tiempo_paradero_5_4_4);
            ejecucion=continuar_ejecucion();
            break;
        case 3:
            tiempo_actual=hora_actual();
            accion_datero(retraso1_dir1,  retraso1_dir2, retraso2_dir1, retraso2_dir2, retraso3_dir1,  retraso3_dir2, retraso4_dir1, retraso4_dir2);
            ejecucion=continuar_ejecucion();
            break;
        case 4:
            cout << "---------------------------------------------" << endl;
            cout << "|         ¡GRACIAS POR USAR RUTERO!         |" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "| Saliendo del programa.                    |" << endl;
            cout << "---------------------------------------------" << endl;
            ejecucion=0;
            break;
        }
    }
}

int mostrar_equipo(){
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
    return 0;
}
int mostrar_menu_usuario(){
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
        return 0;
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
int hora_actual(){
    int HH, MM;
    while (1)
    {
        cout << "-------------------------------------------" << endl;
        cout << "|            Establecer hora              |" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "| Ingrese la hora actual (HH MM):         |" <<endl;
        cout << "-------------------------------------------" << endl;
        cin >> HH >> MM;
        if(HH < 0 || HH > 23 || MM < 0 || MM > 59) {
            cout << "----------------------------------------------------" << endl;
            cout << "|           Error al establecer la hora            |" << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "| Hora no valida. Intentelo de nuevo.              |" << endl;   
            cout << "----------------------------------------------------" << endl;
            continue;
        }
        break;
    }
        // transformacion de la hora en minutos (1h<>60 minutos) y se suma los minutos para tener el tiempo 
        // transcurridos en el día en minutos para facilitar los cálculos
    int hora_actual = HH * 60 + MM;
    return hora_actual;
}

int accion_pasajero(int tiempo_actual,int retraso1_dir1,int retraso1_dir2,int retraso2_dir1,int retraso2_dir2,int retraso3_dir1,int retraso3_dir2,int retraso4_dir1,int retraso4_dir2){
    int empresa_pasajero = mostrar_lista_empresas();
    int paradero_inicial = mostrar_seleccionar_paradero_inicial_usuario(empresa_pasajero);
    int paradero_final = mostrar_seleccionar_paradero_destino_usuario(empresa_pasajero,paradero_inicial);
    reporte_buses_pasajero(paradero_inicial, paradero_final, tiempo_actual, retraso1_dir1, retraso2_dir1, retraso3_dir1, retraso4_dir1, retraso1_dir2, retraso2_dir2, retraso3_dir2, retraso4_dir2);
    return 0;
}

int accion_conductor(int tiempo_actual, 
                int retraso1_dir1, int retraso2_dir1, int retraso3_dir1, int retraso4_dir1, int retraso1_dir2, int retraso2_dir2, int retraso3_dir2, int retraso4_dir2, 
                int tiempo_paradero_1_2_1, int tiempo_paradero_2_3_1, int tiempo_paradero_3_4_1 , int tiempo_paradero_4_5_1,int tiempo_paradero_1_2_2, int tiempo_paradero_2_3_2, int tiempo_paradero_3_4_2 , int tiempo_paradero_4_5_2, 
                int tiempo_paradero_1_2_3, int tiempo_paradero_2_3_3, int tiempo_paradero_3_4_3, int tiempo_paradero_4_5_3, int tiempo_paradero_1_2_4, int tiempo_paradero_2_3_4, int tiempo_paradero_3_4_4, int tiempo_paradero_4_5_4, 
                int tiempo_paradero_2_1_1, int tiempo_paradero_3_2_1, int tiempo_paradero_4_3_1, int tiempo_paradero_5_4_1, int tiempo_paradero_2_1_2, int tiempo_paradero_3_2_2, int tiempo_paradero_4_3_2, int tiempo_paradero_5_4_2, 
                int tiempo_paradero_2_1_3, int tiempo_paradero_3_2_3, int tiempo_paradero_4_3_3, int tiempo_paradero_5_4_3,int tiempo_paradero_2_1_4, int tiempo_paradero_3_2_4, int tiempo_paradero_4_3_4, int tiempo_paradero_5_4_4)
{
    int empresa_conductor = mostrar_lista_empresas();
    int paradero_inicial = mostrar_seleccionar_paradero_inicial_usuario(empresa_conductor);
    int paradero_final = mostrar_seleccionar_paradero_destino_usuario(empresa_conductor,paradero_inicial);
    reporte_conductor(empresa_conductor,paradero_inicial,paradero_final,tiempo_actual, 
                retraso1_dir1,  retraso2_dir1,  retraso3_dir1,  retraso4_dir1,  retraso1_dir2,  retraso2_dir2,  retraso3_dir2,  retraso4_dir2, 
                tiempo_paradero_1_2_1, tiempo_paradero_2_3_1, tiempo_paradero_3_4_1 , tiempo_paradero_4_5_1, tiempo_paradero_1_2_2,  tiempo_paradero_2_3_2,  tiempo_paradero_3_4_2 ,  tiempo_paradero_4_5_2, 
                tiempo_paradero_1_2_3, tiempo_paradero_2_3_3, tiempo_paradero_3_4_3, tiempo_paradero_4_5_3,  tiempo_paradero_1_2_4,  tiempo_paradero_2_3_4,  tiempo_paradero_3_4_4,  tiempo_paradero_4_5_4, 
                tiempo_paradero_2_1_1, tiempo_paradero_3_2_1, tiempo_paradero_4_3_1, tiempo_paradero_5_4_1,  tiempo_paradero_2_1_2,  tiempo_paradero_3_2_2,  tiempo_paradero_4_3_2,  tiempo_paradero_5_4_2, 
                tiempo_paradero_2_1_3, tiempo_paradero_3_2_3, tiempo_paradero_4_3_3,  tiempo_paradero_5_4_3, tiempo_paradero_2_1_4,  tiempo_paradero_3_2_4,  tiempo_paradero_4_3_4,  tiempo_paradero_5_4_4);
    return 0;
}
int accion_datero(
                int retraso1_dir1, int retraso1_dir2,
                int retraso2_dir1, int retraso2_dir2,
                int retraso3_dir1, int retraso3_dir2,
                int retraso4_dir1, int retraso4_dir2){
    int empresa_datero = mostrar_lista_empresas();
    int paradero_reporte = mostrar_seleccionar_paradero_inicial_usuario(empresa_datero);
    int sentido = mostrar_seleccionar_sentido ();
    actualizar_retraso_reportado(empresa_datero,paradero_reporte, sentido, 
                                retraso1_dir1, retraso1_dir2,
                                retraso2_dir1, retraso2_dir2,
                                retraso3_dir1, retraso3_dir2,
                                retraso4_dir1, retraso4_dir2);


    return 0;
}

int mostrar_lista_empresas(){
// Se muestra el menu de seleccion de la empresa con la que se quiere trabajar
    int empresa, opcion;
    do{
        cout << "----------------------------------------------------" << endl;
        cout << "|         Seleccionando empresa de transporte      |" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "| Seleccione la empresa de buses:                  |" << endl;
        cout << "| 1. Los chocolates                                |" << endl;
        cout << "| 2. La 40                                         |" << endl;
        cout << "| 3. La 50                                         |" << endl;
        cout << "| 4. La 71                                         |" << endl;
        cout << "| Seleccione una opcion:                           |" << endl;
        cout << "----------------------------------------------------" << endl;

        // Se lee el valor ingresado
        cin >> empresa;
        // Se valida la seleccion de la empresa
        opcion = validar_seleccion(empresa,1,4);
    }while(opcion!=1);
    return empresa;   
}

int mostrar_seleccionar_paradero_inicial_usuario (int empresa){
    int paradero_inicial, opcion;
    do{
        switch (empresa){
            case 1:
                cout << "----------------------------------------------------" << endl;
                cout << "|     Seleccionando paradero de Los chocolates     |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| Seleccione el paradero inicial (1-5):            |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| 1. Estacion de tren Miguel Grau                  |" << endl;
                cout << "| 2. Plaza Miguel Grau                             |" << endl;
                cout << "| 3. Tingo Maria                                   |" << endl;
                cout << "| 4. UNMSM (puerta 2)                              |" << endl;
                cout << "| Seleccione una opcion:                           |" << endl;
                cout << "----------------------------------------------------" << endl;
                break;
            case 2:
                cout << "----------------------------------------------------" << endl;
                cout << "|        Seleccionando paradero de La 40           |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| Seleccione el paradero inicial (1-5):            |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| 1. Estacion La Cultura                           |" << endl;
                cout << "| 2. Av. Brasil                                    |" << endl;
                cout << "| 3. Av. Sucre                                     |" << endl;
                cout << "| 4. UNMSM (puerta 2)                              |" << endl;
                cout << "| Seleccione una opcion:                           |" << endl;
                cout << "----------------------------------------------------" << endl;
                break;
            case 3:
                cout << "----------------------------------------------------" << endl;
                cout << "|        Seleccionando paradero de La 50           |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| Seleccione el paradero inicial (1-5):            |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| 1. Estacion de tren Grau                         |" << endl;
                cout << "| 2. Plaza Grau                                    |" << endl;
                cout << "| 3. Tingo Maria                                   |" << endl;
                cout << "| 4. UNMSM (puerta 2)                              |" << endl;
                cout << "| Seleccione una opcion:                           |" << endl;
                cout << "----------------------------------------------------" << endl;
                break;
            case 4:
                cout << "----------------------------------------------------" << endl;
                cout << "|        Seleccionando paradero de La 71           |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| Seleccione el paradero inicial (1-5):            |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| 1. Estacion de tren Grau                         |" << endl;
                cout << "| 2. Plaza Grau                                    |" << endl;
                cout << "| 3. UNMSM (puerta 2)                              |" << endl;
                cout << "| 4. Av Colonial                                   |" << endl;
                cout << "| Seleccione una opcion:                           |" << endl;
                cout << "----------------------------------------------------" << endl;
                break;
        }
        cin>>paradero_inicial;
        opcion=validar_seleccion(paradero_inicial, 1, 5);
    }while(opcion!=1);
    return paradero_inicial;        
}

int mostrar_seleccionar_paradero_destino_usuario (int empresa, int paradero_inicial){
    int paradero_final, opcion;
    do{
        switch (empresa){
            case 1:
                cout << "----------------------------------------------------" << endl;
                cout << "|     Seleccionando paradero de Los chocolates     |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| Seleccione el paradero de destino (1-5):         |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| 1. Estacion de tren Miguel Grau                  |" << endl;
                cout << "| 2. Plaza Miguel Grau                             |" << endl;
                cout << "| 3. Tingo Maria                                   |" << endl;
                cout << "| 4. UNMSM (puerta 2)                              |" << endl;
                cout << "| Seleccione una opcion:                           |" << endl;
                cout << "----------------------------------------------------" << endl;
                break;
            case 2:
                cout << "----------------------------------------------------" << endl;
                cout << "|        Seleccionando paradero de La 40           |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| Seleccione el paradero de destino (1-5):         |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| 1. Estacion La Cultura                           |" << endl;
                cout << "| 2. Av. Brasil                                    |" << endl;
                cout << "| 3. Av. Sucre                                     |" << endl;
                cout << "| 4. UNMSM (puerta 2)                              |" << endl;
                cout << "| Seleccione una opcion:                           |" << endl;
                cout << "----------------------------------------------------" << endl;
                break;
            case 3:
                cout << "----------------------------------------------------" << endl;
                cout << "|        Seleccionando paradero de La 50           |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| Seleccione el paradero de destino (1-5):         |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| 1. Estacion de tren Grau                         |" << endl;
                cout << "| 2. Plaza Grau                                    |" << endl;
                cout << "| 3. Tingo Maria                                   |" << endl;
                cout << "| 4. UNMSM (puerta 2)                              |" << endl;
                cout << "| Seleccione una opcion:                           |" << endl;
                cout << "----------------------------------------------------" << endl;
                break;
            case 4:
                cout << "----------------------------------------------------" << endl;
                cout << "|        Seleccionando paradero de La 71           |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| Seleccione el paradero de destino (1-5):         |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "| 1. Estacion de tren Grau                         |" << endl;
                cout << "| 2. Plaza Grau                                    |" << endl;
                cout << "| 3. UNMSM (puerta 2)                              |" << endl;
                cout << "| 4. Av Colonial                                   |" << endl;
                cout << "| Seleccione una opcion:                           |" << endl;
                cout << "----------------------------------------------------" << endl;
                break;
        }
        cin>>paradero_final;
        opcion=validar_seleccion(paradero_final, 1, 5);
        if(paradero_final==paradero_inicial){
            cout << "----------------------------------------------------" << endl;
            cout << "|    Error al seleccionar paradero de destino      |" << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "| Paradero final es igual al paradero inicial.     |" << endl;
            cout << "----------------------------------------------------" << endl;
            opcion=0;
        }
    }while(opcion!=1);
    return paradero_final;
}

int reporte_buses_pasajero(int paradero_inicial, int paradero_final, int tiempo_actual, int retraso1_dir1, int retraso2_dir1, int retraso3_dir1, int retraso4_dir1, int retraso1_dir2, int retraso2_dir2, int retraso3_dir2, int retraso4_dir2){
    cout << "----------------------------------------------------" << endl;
    cout << "|           Reporte de buses al pasajero           |" << endl;
    cout << "----------------------------------------------------" << endl;
    if(tiempo_actual < 300 || tiempo_actual >= 1410){
        cout << "----------------------------------------------------" << endl;
        cout << "| No hay buses en circulacion en este horario.     |" << endl;
        cout << "----------------------------------------------------" << endl;
    }
    else{
        int proximo_bus = 5 * 60; // primer bus a 05:00 AM
        int retraso_acumulado = 0;
        int direccion=paradero_final-paradero_inicial;
        while (proximo_bus <= tiempo_actual) {
                if (direccion > 0) {
                    retraso_acumulado += (retraso1_dir1 + retraso2_dir1 + retraso3_dir1 + retraso4_dir1) / 4;
                } else {
                    retraso_acumulado += (retraso1_dir2 + retraso2_dir2 + retraso3_dir2 + retraso4_dir2) / 4;
                }
                proximo_bus += 8 + retraso_acumulado;
            }
        int segundo_bus = proximo_bus + 8 + (direccion > 0 ? (retraso1_dir1 + retraso2_dir1 + retraso3_dir1 + retraso4_dir1) / 4 : (retraso1_dir2 + retraso2_dir2 + retraso3_dir2 + retraso4_dir2) / 4);
        cout << "----------------------------------------------------" << endl;
        cout << "| El proximo bus llegara en " << proximo_bus - tiempo_actual << " minutos. |" << endl;
        cout << "| El segundo bus llegara en " << segundo_bus - tiempo_actual << " minutos. |" << endl;
        cout << "----------------------------------------------------" << endl;
    }
    return 0;
}
long double reporte_conductor(int empresa,int paradero_inicial,int paradero_final, int tiempo_actual, 
                int retraso1_dir1, int retraso2_dir1, int retraso3_dir1, int retraso4_dir1, int retraso1_dir2, int retraso2_dir2, int retraso3_dir2, int retraso4_dir2, 
                int tiempo_paradero_1_2_1, int tiempo_paradero_2_3_1, int tiempo_paradero_3_4_1 , int tiempo_paradero_4_5_1,int tiempo_paradero_1_2_2, int tiempo_paradero_2_3_2, int tiempo_paradero_3_4_2 , int tiempo_paradero_4_5_2, 
                int tiempo_paradero_1_2_3, int tiempo_paradero_2_3_3, int tiempo_paradero_3_4_3, int tiempo_paradero_4_5_3, int tiempo_paradero_1_2_4, int tiempo_paradero_2_3_4, int tiempo_paradero_3_4_4, int tiempo_paradero_4_5_4, 
                int tiempo_paradero_2_1_1, int tiempo_paradero_3_2_1, int tiempo_paradero_4_3_1, int tiempo_paradero_5_4_1, int tiempo_paradero_2_1_2, int tiempo_paradero_3_2_2, int tiempo_paradero_4_3_2, int tiempo_paradero_5_4_2, 
                int tiempo_paradero_2_1_3, int tiempo_paradero_3_2_3, int tiempo_paradero_4_3_3, int tiempo_paradero_5_4_3,int tiempo_paradero_2_1_4, int tiempo_paradero_3_2_4, int tiempo_paradero_4_3_4, int tiempo_paradero_5_4_4){
    int tiempo_viaje = 0;
    int direccion = paradero_final-paradero_inicial;
        if(direccion>0){
            if (empresa == 1) {
                tiempo_paradero_1_2_1 = 20 + retraso1_dir1;
                tiempo_paradero_2_3_1 = 20 + retraso2_dir1;
                tiempo_paradero_3_4_1 = 25 + retraso3_dir1;
                tiempo_paradero_4_5_1 = 30 + retraso4_dir1;
            } else if (empresa == 2) {
                tiempo_paradero_1_2_2 = 15 + retraso1_dir1;
                tiempo_paradero_2_3_2 = 25 + retraso2_dir1;
                tiempo_paradero_3_4_2 = 25 + retraso3_dir1;
                tiempo_paradero_4_5_2 = 20 + retraso4_dir1;
            } else if (empresa == 3) {
                tiempo_paradero_1_2_3 = 15 + retraso1_dir1;
                tiempo_paradero_2_3_3 = 20 + retraso2_dir1;
                tiempo_paradero_3_4_3 = 30 + retraso3_dir1;
                tiempo_paradero_4_5_3 = 20 + retraso4_dir1;
            } else if (empresa == 4) {
                tiempo_paradero_1_2_4 = 30 + retraso1_dir1;
                tiempo_paradero_2_3_4 = 15 + retraso2_dir1;
                tiempo_paradero_3_4_4 = 25 + retraso3_dir1;
                tiempo_paradero_4_5_4 = 25 + retraso4_dir1;
            }

        }
        else{
            if (empresa == 1) {
                tiempo_paradero_2_1_1 = 20 + retraso1_dir2;
                tiempo_paradero_3_2_1 = 20 + retraso2_dir2;
                tiempo_paradero_4_3_1 = 25 + retraso3_dir2;
                tiempo_paradero_5_4_1 = 30 + retraso4_dir2;
            } else if (empresa == 2) {
                tiempo_paradero_2_1_2 = 15 + retraso1_dir2;
                tiempo_paradero_3_2_2 = 25 + retraso2_dir2;
                tiempo_paradero_4_3_2 = 25 + retraso3_dir2;
                tiempo_paradero_5_4_2 = 20 + retraso4_dir2;
            } else if (empresa == 3) {
                tiempo_paradero_2_1_3 = 15 + retraso1_dir2;
                tiempo_paradero_3_2_3 = 20 + retraso2_dir2;
                tiempo_paradero_4_3_3 = 30 + retraso3_dir2;
                tiempo_paradero_5_4_3 = 20 + retraso4_dir2;
            } else if (empresa == 4) {
                tiempo_paradero_2_1_4 = 30 + retraso1_dir2;
                tiempo_paradero_3_2_4 = 15 + retraso2_dir2;
                tiempo_paradero_4_3_4 = 25 + retraso3_dir2;
                tiempo_paradero_5_4_4 = 25 + retraso4_dir2;
            }

        }    
        if ((tiempo_actual >= 360 && tiempo_actual <= 510) ||
            (tiempo_actual >= 840 && tiempo_actual <= 960) ||
            (tiempo_actual >= 1080 && tiempo_actual <= 1260)) {
            tiempo_paradero_2_1_1 += 15;
            tiempo_paradero_3_2_1 += 15;
            tiempo_paradero_4_3_1 += 15;
            tiempo_paradero_5_4_1 += 15;
            tiempo_paradero_2_1_2 += 15;
            tiempo_paradero_3_2_2 += 15;
            tiempo_paradero_4_3_2 += 15;
            tiempo_paradero_5_4_2 += 15;
            tiempo_paradero_2_1_3 += 15;
            tiempo_paradero_3_2_3 += 15;
            tiempo_paradero_4_3_3 += 15;
            tiempo_paradero_5_4_3 += 15;
            tiempo_paradero_2_1_4 += 15;
            tiempo_paradero_3_2_4 += 15;
            tiempo_paradero_4_3_4 += 15;
            tiempo_paradero_5_4_4 += 15;
        }
    if(empresa==1){    
        if (direccion > 0) {
            for (int i = paradero_inicial; i < paradero_final; ++i) {
                if (i == 1) {
                    tiempo_viaje += tiempo_paradero_1_2_1;
                } else if (i == 2) {
                    tiempo_viaje += tiempo_paradero_2_3_1;
                } else if (i == 3) {
                    tiempo_viaje += tiempo_paradero_3_4_1;
                } else if (i == 4) {
                    tiempo_viaje += tiempo_paradero_4_5_1;
                    
                }
            }
        } 
        else {
            for (int i = paradero_inicial - 1; i >= paradero_final; --i) {
                if (i == 1) {
                    tiempo_viaje += tiempo_paradero_2_1_1;
                } else if (i == 2) {
                    tiempo_viaje += tiempo_paradero_3_2_1;
                } else if (i == 3) {
                    tiempo_viaje += tiempo_paradero_4_3_1;
                } else if (i == 4) {
                    tiempo_viaje += tiempo_paradero_5_4_1;
                }
            }
        }
    }
    if(empresa==2){    
        if (direccion > 0) {
            for (int i = paradero_inicial; i < paradero_final; ++i) {
                if (i == 1) {
                    tiempo_viaje += tiempo_paradero_1_2_2;
                } else if (i == 2) {
                    tiempo_viaje += tiempo_paradero_2_3_2;
                } else if (i == 3) {
                    tiempo_viaje += tiempo_paradero_3_4_2;
                } else if (i == 4) {
                    tiempo_viaje += tiempo_paradero_4_5_2;
                    
                }
            }
        } 
        else {
            for (int i = paradero_inicial - 1; i >= paradero_final; --i) {
                if (i == 1) {
                    tiempo_viaje += tiempo_paradero_2_1_2;
                } else if (i == 2) {
                    tiempo_viaje += tiempo_paradero_3_2_2;
                } else if (i == 3) {
                    tiempo_viaje += tiempo_paradero_4_3_2;
                } else if (i == 4) {
                    tiempo_viaje += tiempo_paradero_5_4_2;
                }
            }
        }
    }
    if(empresa==3){    
        if (direccion > 0) {
            for (int i = paradero_inicial; i < paradero_final; ++i) {
                if (i == 1) {
                    tiempo_viaje += tiempo_paradero_1_2_3;
                } else if (i == 2) {
                    tiempo_viaje += tiempo_paradero_2_3_3;
                } else if (i == 3) {
                    tiempo_viaje += tiempo_paradero_3_4_3;
                } else if (i == 4) {
                    tiempo_viaje += tiempo_paradero_4_5_3;
                    
                }
            }
        } 
        else {
            for (int i = paradero_inicial - 1; i >= paradero_final; --i) {
                if (i == 1) {
                    tiempo_viaje += tiempo_paradero_2_1_3;
                } else if (i == 2) {
                    tiempo_viaje += tiempo_paradero_3_2_3;
                } else if (i == 3) {
                    tiempo_viaje += tiempo_paradero_4_3_3;
                } else if (i == 4) {
                    tiempo_viaje += tiempo_paradero_5_4_3;
                }
            }
        }
    }
    if(empresa==4){    
        if (direccion > 0) {
            for (int i = paradero_inicial; i < paradero_final; ++i) {
                if (i == 1) {
                    tiempo_viaje += tiempo_paradero_1_2_4;
                } else if (i == 2) {
                    tiempo_viaje += tiempo_paradero_2_3_4;
                } else if (i == 3) {
                    tiempo_viaje += tiempo_paradero_3_4_4;
                } else if (i == 4) {
                    tiempo_viaje += tiempo_paradero_4_5_4;
                    
                }
            }
        } 
        else {
            for (int i = paradero_inicial - 1; i >= paradero_final; --i) {
                if (i == 1) {
                    tiempo_viaje += tiempo_paradero_2_1_4;
                } else if (i == 2) {
                    tiempo_viaje += tiempo_paradero_3_2_4;
                } else if (i == 3) {
                    tiempo_viaje += tiempo_paradero_4_3_4;
                } else if (i == 4) {
                    tiempo_viaje += tiempo_paradero_5_4_4;
                }
            }
        }
    }
    cout << "----------------------------------------------------" << endl;
    cout << "| El tiempo de viaje sera de " << tiempo_viaje << " minutos. |" << endl;
    cout << "----------------------------------------------------" << endl;
    return 0;
}
int continuar_ejecucion(){
    int continuar, opcion;
    do{
        cout << "---------------------------------------------" << endl;
        cout << "|    ¿Desea continuar usando Rutero?        |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 1. Si                                     |" << endl;
        cout << "| 2. No                                     |" << endl;
        cout << "---------------------------------------------" << endl;
        cin >> continuar;
        opcion=validar_seleccion(continuar,1,2);
    }while(opcion!=1);
    if(opcion == 0){
        cout << "---------------------------------------------" << endl;
        cout << "|         ¡GRACIAS POR USAR RUTERO!         |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| Saliendo del programa.                    |" << endl;
        cout << "---------------------------------------------" << endl;
        continuar = 0;
    }
    else
    {
        continuar = 1;
    }
    return continuar;
}

int reporte_datero()
{
    cout << "---------------------------------------------" << endl;
    cout << "|             Reporte del datero            |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| Reporte exitoso                           |" << endl;
    cout << "---------------------------------------------" << endl;
    return 0;
}

int mostrar_seleccionar_sentido (){
    int sentido, opcion;
    do{
        cout << "---------------------------------------------" << endl;
        cout << "| Sentido que desea reportar:               |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 1. Hacia Estacion de Tren                 |" << endl;
        cout << "| 2. Hacia UNMSM                            |" << endl;
        cout << "---------------------------------------------" << endl;
        cin >> sentido;
        opcion = validar_seleccion(sentido,1,2);
    }while(opcion!=1);    
    return sentido;
}
int actualizar_retraso_reportado(int empresa, int paradero, int sentido, 
                                int retraso1_dir1, int retraso1_dir2,
                                int retraso2_dir1, int retraso2_dir2,
                                int retraso3_dir1, int retraso3_dir2,
                                int retraso4_dir1, int retraso4_dir2)
{
    int accion, opcion;
    do{
        cout << "---------------------------------------------" << endl;
        cout << "| Seleccione accion:                        |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 1. Reportar retraso                       |" << endl;
        cout << "| 2. Reestablecer retraso                   |" << endl;
        cout << "---------------------------------------------" << endl;
        cin >> accion;
        opcion=validar_seleccion(accion,1,2);
    }while(opcion!=1);
    int retraso;
    switch(accion){
        case 1:
            int opcion_retraso;
            do{
                cout << "---------------------------------------------" << endl;
                cout << "| Indique retraso del paradero y sentido que|" << endl;
                cout << "| a seleccionado en minutos:                |" << endl;
                cout << "---------------------------------------------" << endl;
                cin >> retraso;
                opcion_retraso=validar_seleccion(retraso,1,120);
            }while(opcion_retraso!=1);
            if(sentido>0){
                if (paradero == 1) {
                    retraso1_dir1 += retraso;
                } else if (paradero == 2) {
                    retraso2_dir1 += retraso;
                } else if (paradero == 3) {
                    retraso3_dir1 += retraso;
                } else if (paradero == 4) {
                    retraso4_dir1 += retraso;
            }
            else{
                if (paradero == 1) {
                    retraso1_dir2 += retraso;
                } else if (paradero == 2) {
                    retraso2_dir2 += retraso;
                } else if (paradero == 3) {
                    retraso3_dir2 += retraso;
                } else if (paradero == 4) {
                    retraso4_dir2 += retraso;
            }
            break;
        case 2:
            if (paradero == 1) {
                    retraso1_dir1 = 0 ;
                } else if (paradero == 2) {
                    retraso2_dir1 = 0 ;
                } else if (paradero == 3) {
                    retraso3_dir1 = 0;
                } else if (paradero == 4) {
                    retraso4_dir1 = 0;
            }
            else{
                if (paradero == 1) {
                    retraso1_dir2 = 0;
                } else if (paradero == 2) {
                    retraso2_dir2 = 0;
                } else if (paradero == 3) {
                    retraso3_dir2 = 0;
                } else if (paradero == 4) {
                    retraso4_dir2 = 0;
            }
            break;
            }
        }
    }
}
return 0;
}
