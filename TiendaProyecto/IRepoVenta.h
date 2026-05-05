#ifndef IREPOVENTAS_H
#define IREPOVENTAS_H

#include "Venta.h"

class IRepoVenta {
public:
    virtual void agregarVenta(Venta v) = 0;
};

#endif
