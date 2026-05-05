#ifndef IREPOUSUARIO_H
#define IREPOUSUARIO_H

#include "Usuario.h"

class IRepoUsuario {
public:
    virtual void registrar(Usuario u) = 0;
    virtual bool autenticar(string user, string pass) = 0;
};

#endif
