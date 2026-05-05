#ifndef OPERACIONESTIENDA_H
#define OPERACIONESTIENDA_H

#include <iostream>
#include "IRepoClientes.h"
#include "IRepoProducto.h"
#include "IRepoVenta.h"
#include "MemoriaProducto.h"
#include "MemoriaVenta.h"
using namespace std;

class OperacionesTienda {
private:
    IRepoClientes* repoClientes;
    IRepoProducto* repoProductos;
    IRepoVenta* repoVentas;

public:
    OperacionesTienda(IRepoClientes* rc,
        IRepoProducto* rp,
        IRepoVenta* rv) {
        repoClientes = rc;
        repoProductos = rp;
        repoVentas = rv;
    }

    void registrarCliente() {
        int id;
        string nombre, telefono;

        cout << "ID: "; cin >> id;
        cout << "Nombre: "; cin >> nombre;
        cout << "Telefono: "; cin >> telefono;

        repoClientes->agregarCliente(Cliente(id, nombre, telefono));
    }

    void registrarProducto() {
        int id, stock;
        string nombre;
        double precio;

        cout << "ID: "; cin >> id;
        cout << "Nombre: "; cin >> nombre;
        cout << "Precio: "; cin >> precio;
        cout << "Stock: "; cin >> stock;

        repoProductos->agregarProducto(Producto(id, nombre, precio, stock));
    }

    void realizarVenta() {
        int idCliente;
        cout << "ID cliente: ";
        cin >> idCliente;

        Cliente* cliente = repoClientes->buscarCliente(idCliente);

        if (!cliente) {
            cout << "Cliente no existe\n";
            return;
        }

        Venta venta(1, *cliente);

        char continuar;
        do {
            int idProducto, cantidad = 0;

            cout << "ID producto: ";
            cin >> idProducto;

            Producto* producto = repoProductos->buscarProducto(idProducto);

            if (producto->getStock() >= cantidad) {

                Producto productoVenta = *producto; 

                char aplicar;
                cout << "Aplicar descuento a este producto? (s/n): ";
                cin >> aplicar;

                if (aplicar == 's') {
                    double descuento;
                    cout << "Ingrese porcentaje de descuento: ";
                    cin >> descuento;

                    if (descuento >= 0 && descuento <= 100) {
                        productoVenta.aplicarDescuento(descuento);
                    }
                    else {
                        cout << "Descuento invalido, no se aplicara\n";
                    }
                }

                producto->reducirStock(cantidad);
                venta.agregarProducto(productoVenta, cantidad);

            }
            else {
                cout << "Stock insuficiente\n";
            }
            

            cout << "Agregar otro producto? (s/n): ";
            cin >> continuar;

        } while (continuar == 's');

        cout << "Total: " << venta.calcularTotal() << endl;

        repoVentas->agregarVenta(venta);
    }

    void mostrarProductos() {
        cout << "\n--- Productos registrados ---\n";

        

        MemoriaProducto* memoria = dynamic_cast<MemoriaProducto*>(repoProductos);

        if (memoria == nullptr) {
            cout << "No se pueden mostrar productos\n";
            return;
        }

        auto lista = memoria->getProductos();

        for (auto& p : lista) {
            cout << "ID: " << p.getId()
                << " | Precio: " << p.getPrecio()
                << " | Stock: " << p.getStock() << endl;
        }
    }

    void mostrarVentas() {
        cout << "\n--- Ventas realizadas ---\n";

        MemoriaVenta* memoria = dynamic_cast<MemoriaVenta*>(repoVentas);

        if (memoria == nullptr) {
            cout << "No se pueden mostrar ventas\n";
            return;
        }

        auto lista = memoria->getVentas();

        int i = 1;
        for (auto& v : lista) {
            cout << "Venta #" << i++
                << " | Total: " << v.calcularTotal() << endl;
        }
    }


};

#endif