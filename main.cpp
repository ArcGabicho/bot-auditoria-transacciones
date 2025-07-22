#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

void mostrarBanner() {
    system(CLEAR);
    cout << R"(
     _           _ _             _ _               _
    | |__   __ _| (_) ___  _ __ (_) |__   ___  ___| |_ ___  _ __
    | '_ \ / _` | | |/ _ \| '_ \| | '_ \ / _ \/ __| __/ _ \| '__|
    | | | | (_| | | | (_) | | | | | |_) |  __/ (__| || (_) | |
    |_| |_|\__,_|_|_|\___/|_| |_|_|_.__/ \___|\___|\__\___/|_|

           BOT DE AUDITORIA INTERNA DE TRANSACCIONES
================================================================
)";
    this_thread::sleep_for(chrono::seconds(2));
}

void mostrarMenu() {
    cout << R"(
------------------------ MENU PRINCIPAL ------------------------

1. Analizar historial de transacciones
2. Detectar anomalias financieras
3. Ver auditorias anteriores
4. Generar reporte de auditoria
5. Configuracion del sistema
6. Creditos
0. Salir

----------------------------------------------------------------
Ingrese una opcion: )";
}

int main() {
    mostrarBanner();

    int opcion = -1;

    while (opcion != 0) {
        mostrarMenu();
        cin >> opcion;

        if (opcion < 0 || opcion > 6) {
            cout << "\nOpcion invalida. Intente nuevamente.\n";
        } else if (opcion != 0) {
            cout << "\nFuncionalidad aún no implementada. Presione Enter para continuar...\n";
            cin.ignore(); // limpiar buffer
            cin.get();    // esperar Enter
            system(CLEAR);
            mostrarBanner();
        }
    }

    cout << "\nCerrando el Bot de Auditoria Interna...\n";
    return 0;
}