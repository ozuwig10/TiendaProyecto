#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto {
private:
    int id;
    string nombre;
    double precio;
    int stock;

public:
    Producto(int id, string nombre, double precio, int stock)
        : id(id), nombre(nombre), precio(precio), stock(stock) {
    }

    int getId() { return id; }
    double getPrecio() { return precio; }
    int getStock() { return stock; }

    void reducirStock(int cantidad) {
        stock -= cantidad;
    }
    void aplicarDescuento(double porcentaje) {
        precio -= precio * (porcentaje / 100.0);
    }
};

#endif
