#ifndef IREPOCLIENTES_H
#define IREPOCLIENTES_H

#include "Cliente.h"

class IRepoClientes {
public:
    virtual void agregarCliente(Cliente c) = 0;
    virtual Cliente* buscarCliente(int id) = 0;
};

#endif
