#ifndef IREPOPRODUCTOS_H
#define IREPOPRODUCTOS_H

#include "Producto.h"

class IRepoProducto {
public:
    virtual void agregarProducto(Producto p) = 0;
    virtual Producto* buscarProducto(int id) = 0;
};

#endif