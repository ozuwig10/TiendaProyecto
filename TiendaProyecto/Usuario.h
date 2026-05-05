#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
private:
    string username;
    string password;

public:
    Usuario(string u, string p) : username(u), password(p) {}

    string getUsername() { return username; }
    string getPassword() { return password; }
};

#endif
