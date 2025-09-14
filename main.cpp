#include <iostream>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <sstream>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

struct Transaccion {
    string fecha;
    string descripcion;
    double monto;
};

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

vector<Transaccion> cargarTransacciones(const string& archivo) {
    vector<Transaccion> transacciones;
    ifstream fin(archivo);
    string linea;
    while (getline(fin, linea)) {
        stringstream ss(linea);
        Transaccion t;
        getline(ss, t.fecha, ',');
        getline(ss, t.descripcion, ',');
        string montoStr;
        getline(ss, montoStr, ',');
        t.monto = stod(montoStr);
        transacciones.push_back(t);
    }
    return transacciones;
}

void analizarHistorial() {
    cout << "\n--- Historial de Transacciones (Simulado) ---\n";
    cout << "2024-06-01 | Pago proveedor | $1500.00\n";
    cout << "2024-06-02 | Compra insumos | $320.50\n";
    cout << "2024-06-03 | Transferencia interna | $5000.00\n";
    cout << "2024-06-04 | Reembolso | $120.00\n";
}

void detectarAnomalias() {
    cout << "\n--- Detección de Anomalías Financieras (Simulado) ---\n";
    cout << "Anomalía: 2024-06-03 | Transferencia interna | $5000.00 (Monto elevado)\n";
    cout << "No se detectaron otras anomalías.\n";
}

void verAuditoriasAnteriores() {
    cout << "\n--- Auditorías Anteriores ---\n";
    ifstream fin("auditorias.txt");
    string linea;
    if (!fin) {
        cout << "No hay auditorías previas.\n";
        return;
    }
    while (getline(fin, linea)) {
        cout << linea << '\n';
    }
}

void generarReporteAuditoria() {
    cout << "\n--- Generando Reporte de Auditoría ---\n";
    auto transacciones = cargarTransacciones("transacciones.txt");
    ofstream fout("auditorias.txt", ios::app);
    fout << "Reporte generado el: ";
    fout << chrono::system_clock::to_time_t(chrono::system_clock::now());
    fout << "\nTotal de transacciones: " << transacciones.size() << "\n";
    double total = 0;
    for (const auto& t : transacciones) total += t.monto;
    fout << "Monto total: $" << total << "\n--------------------------\n";
    fout.close();
    cout << "Reporte guardado en auditorias.txt\n";
}

void configuracionSistema() {
    cout << "\n--- Configuración del Sistema ---\n";
    cout << "(Funcionalidad simulada: cambiar umbral de anomalía)\n";
    cout << "Ingrese nuevo umbral: ";
    double nuevoUmbral;
    cin >> nuevoUmbral;
    ofstream fout("config.txt");
    fout << nuevoUmbral;
    fout.close();
    cout << "Umbral actualizado a $" << nuevoUmbral << "\n";
}

void mostrarCreditos() {
    cout << "\n--- Créditos ---\n";
    cout << "Desarrollado por ArcGabicho\n";
    cout << "GitHub: https://github.com/ArcGabicho\n";
}

int main() {
    mostrarBanner();

    int opcion = -1;

    while (opcion != 0) {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // limpiar buffer

        switch (opcion) {
            case 1:
                analizarHistorial();
                break;
            case 2:
                detectarAnomalias();
                break;
            case 3:
                verAuditoriasAnteriores();
                break;
            case 4:
                generarReporteAuditoria();
                break;
            case 5:
                configuracionSistema();
                break;
            case 6:
                mostrarCreditos();
                break;
            case 0:
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
        }
        if (opcion != 0) {
            cout << "\nPresione Enter para continuar...";
            cin.get();
            system(CLEAR);
            mostrarBanner();
        }
    }

    cout << "\nCerrando el Bot de Auditoria Interna...\n";
    return 0;
}