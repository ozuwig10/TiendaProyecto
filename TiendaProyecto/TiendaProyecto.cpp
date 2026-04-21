// Lathrell Wallace
// Gerald Porras
// Cristopher Garcia
// Proyecto Programacion 2 (Tienda de ropa)
// Universidad Nacional de Costa Rica
//

#include <iostream>
#include <string>
using namespace std;
    int main() {

        int opcion;

        do {
            cout << "\n---- TIENDA DE ROPA ---- " << endl;
            cout << "1. Registrar cliente" << endl;
            cout << "2. Registrar producto" << endl;
            cout << "3. Ver productos" << endl;
            cout << "4. Realizar venta" << endl;
            cout << "5. Ver ventas" << endl;
            cout << "6. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 1:
                cout << "\n--- Registrar cliente ---" << endl;
                // Aquí iría la función para registrar cliente
                // Ejemplo: registrarCliente();
                break;

            case 2:
                cout << "\n--- Registrar producto ---" << endl;
                // Aquí iría la función para registrar productos
                // Ejemplo: registrarProducto();
                break;

            case 3:
                cout << "\n--- Lista de productos ---" << endl;
                // Aquí iría la función para mostrar productos
                // Ejemplo: mostrarProductos();
                break;

            case 4:
                cout << "\n--- Realizar venta ---" << endl;
                // Aquí iría la función para hacer una venta
                // Ejemplo: realizarVenta();
                break;

            case 5:
                cout << "\n--- Historial de ventas ---" << endl;
                // Aquí iría la función para mostrar ventas
                // Ejemplo: mostrarVentas();
                break;

            case 6:
                cout << "\nSaliendo del sistema..." << endl;
                break;

            default:
                cout << "\nOpcion invalida, intente de nuevo." << endl;
            }

        } while (opcion != 6);

        return 0;
    }



	// Este menu puede ser modificasdo para agregar o eliminar opciones dependiendo de las necesidades del proyecto.
    // Cada opción puede ser implementada con funciones específicas para manejar la lógica de la tienda de ropa, como registrar clientes, productos, realizar ventas y mostrar el historial de ventas.


