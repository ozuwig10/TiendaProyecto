// Lathrell Wallace
// Gerald Porras
// Cristopher Garcia
// Proyecto Programacion 2 (Tienda de ropa)
// Universidad Nacional de Costa Rica
//
#include <iostream>
#include <string>

#include "MemoriaCliente.h"
#include "MemoriaProducto.h"
#include "MemoriaVenta.h"
#include "OperacionesTienda.h"
#include "MemoriaUsuario.h"
#include "Autenticacion.h"

using namespace std;

int main() {


    
    MemoriaUsuario mu;
    Autenticacion auth(&mu);

    if (!auth.login()) {
        return 0;
    }

    MemoriaCliente rc;
    MemoriaProducto rp;
    MemoriaVenta rv;

    OperacionesTienda op(&rc, &rp, &rv);

    int opcion;

    do {
        cout << "\n---- TIENDA DE ROPA ---- " << endl;
        cout << "1. Registrar cliente" << endl;
        cout << "2. Registrar producto" << endl;
        cout << "3. Ver productos" << endl;
        cout << "4. Realizar venta" << endl;
        cout << "5. Ver ventas" << endl;
        cout << "6. Registrar Usuario" << endl;
        cout << "7. Menu de eliminaciones" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "\n--- Registrar cliente ---" << endl;
            op.registrarCliente();
            break;

        case 2:
            cout << "\n--- Registrar producto ---" << endl;
            op.registrarProducto();
            break;

        case 3:
            cout << "\n--- Lista de productos ---" << endl;
            op.mostrarProductos();   
            break;

        case 4:
            cout << "\n--- Realizar venta ---" << endl;
            op.realizarVenta();
            break;

        case 5:
            cout << "\n--- Historial de ventas ---" << endl;
            op.mostrarVentas();     
            break;

        case 6:
            cout << "\n--- Registrar usuario ---" << endl;
            auth.registrarUsuario();
            break;

        case 7: {

            int opcionEliminar;

            cout << "\n--- ELIMINACIONES ---" << endl;
            cout << "1. Eliminar cliente" << endl;
            cout << "2. Eliminar producto" << endl;
            cout << "3. Eliminar venta" << endl;
            cout << "4. Eliminar usuario" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcionEliminar;

            if (opcionEliminar == 1) {
                op.eliminarCliente();
            }
            else if (opcionEliminar == 2) {
                op.eliminarProducto();
            }
            else if (opcionEliminar == 3) {
                op.eliminarVenta();
            }
            else if (opcionEliminar == 4) {
                auth.eliminarUsuario();
            }
            else {
                cout << "Opcion invalida\n";
            }

            break;
        }

        case 8:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "\nOpcion invalida, intente de nuevo." << endl;
        }

    } while (opcion != 8);

    return 0;
}


	// Este menu puede ser modificasdo para agregar o eliminar opciones dependiendo de las necesidades del proyecto.
    // Cada opción puede ser implementada con funciones específicas para manejar la lógica de la tienda de ropa, como registrar clientes, productos, realizar ventas y mostrar el historial de ventas.
   // Usuario inicial: admin
   // Contraseña: 1234

