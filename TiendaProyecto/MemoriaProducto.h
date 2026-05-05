#ifndef MEMORIAPRODUCTO_H
#define MEMORIAPRODUCTO_H

#include <vector>
#include "IRepoProducto.h"
using namespace std;

class MemoriaProducto : public IRepoProducto {
private:
    vector<Producto> productos;

public:
public:
    
    MemoriaProducto() {
        productos.push_back(Producto(1, "Pantalon", 15000, 10));
        productos.push_back(Producto(2, "Blusa", 10000, 15));
        productos.push_back(Producto(3, "Camisa", 10000, 12));
        productos.push_back(Producto(4, "Falda", 12000, 8));
        productos.push_back(Producto(5, "Vestido", 20000, 6));
        productos.push_back(Producto(6, "RopaInterior", 8000, 20));
    }

    void agregarProducto(Producto p) override {
        productos.push_back(p);
    }

    Producto* buscarProducto(int id) override {
        for (auto& p : productos) {
            if (p.getId() == id)
                return &p;
        }
        return nullptr;
    }

    vector<Producto>& getProductos() {
        return productos;
    }
};

#endif
