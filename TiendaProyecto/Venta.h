#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include "Cliente.h"
#include "Producto.h"
using namespace std;

class Venta {
private:
    int idVenta;
    Cliente cliente;
    vector<pair<Producto, int>> productos;

public:
    Venta(int idVenta, Cliente cliente)
        : idVenta(idVenta), cliente(cliente) {
    }

    void agregarProducto(Producto p, int cantidad) {
        productos.push_back({ p, cantidad });
    }

    double calcularTotal() {
        double total = 0;
        for (auto& item : productos) {
            total += item.first.getPrecio() * item.second;
        }
        return total;
    }
};

#endif

