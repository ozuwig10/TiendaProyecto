#ifndef MEMORIAUSUARIO_H
#define MEMORIAUSUARIO_H
#include <iostream>
#include <vector>
#include "IRepoUsuario.h"

using namespace std;

class MemoriaUsuario : public IRepoUsuario {
private:
    vector<Usuario> usuarios;

public:
    // 🔹 Usuario inicial (dueño)
    MemoriaUsuario() {
        usuarios.push_back(Usuario("admin", "1234"));
    }

    void registrar(Usuario u) override {
        usuarios.push_back(u);
    }

    bool autenticar(string user, string pass) override {
        for (auto& u : usuarios) {
            if (u.getUsername() == user && u.getPassword() == pass)
                return true;
        }
        return false;
    }

    bool eliminarUsuario(string user) override {

        if (user == "admin") {
            cout << "No se puede eliminar el admin principal\n";
            return false;
        }

        for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
            if (it->getUsername() == user) {
                usuarios.erase(it);
                return true;
            }
        }
        return false;
	}
};

#endif

