#ifndef AUTENTICACION_H
#define AUTENTICACION_H

#include <iostream>
#include "IRepoUsuario.h"

using namespace std;

class Autenticacion {
private:
    IRepoUsuario* repo;

public:
    Autenticacion(IRepoUsuario* r) {
        repo = r;
    }

    bool login() {
        string u, p;
        cout << "----- LOGIN -----\n";
        cout << "Usuario: "; cin >> u;
        cout << "Password: "; cin >> p;

        if (repo->autenticar(u, p)) {
            cout << "Acceso concedido\n";
            return true;
        }
        else {
            cout << "Credenciales incorrectas\n";
            return false;
        }
    }

    void registrarUsuario() {
        string u, p;
        cout << "----- REGISTRAR USUARIO -----\n";
        cout << "Nuevo usuario: "; cin >> u;
        cout << "Password: "; cin >> p;

        repo->registrar(Usuario(u, p));
        cout << "Usuario registrado correctamente\n";
    }
};

#endif
