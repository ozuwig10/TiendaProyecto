#ifndef MEMORIAVENTA_H
#define MEMORIAVENTA_H

#include <vector>
#include "IRepoVenta.h"
using namespace std;

class MemoriaVenta : public IRepoVenta {
private:
    vector<Venta> ventas;

public:
    void agregarVenta(Venta v) override {
        ventas.push_back(v);
    }

    vector<Venta>& getVentas() {
        return ventas;
    }
};

#endif