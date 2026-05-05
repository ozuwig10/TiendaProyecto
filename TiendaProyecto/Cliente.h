#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente {
private:
    int id;
    string nombre;
    string telefono;

public:
    Cliente(int id, string nombre, string telefono)
        : id(id), nombre(nombre), telefono(telefono) {
    }

    int getId() { return id; }
    string getNombre() { return nombre; }
};

#endif