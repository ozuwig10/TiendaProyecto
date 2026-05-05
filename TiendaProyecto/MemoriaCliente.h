#ifndef MEMORIACLIENTE_H
#define MEMORIACLIENTE_H

#include <vector>
#include "IRepoClientes.h"
using namespace std;

class MemoriaCliente : public IRepoClientes {
private:
    vector<Cliente> clientes;

public:
    void agregarCliente(Cliente c) override {
        clientes.push_back(c);
    }

    Cliente* buscarCliente(int id) override {
        for (auto& c : clientes) {
            if (c.getId() == id)
                return &c;
        }
        return nullptr;
    }
};

#endif