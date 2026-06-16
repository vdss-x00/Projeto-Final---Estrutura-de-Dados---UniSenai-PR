#ifndef INGRESSO_H
#define INGRESSO_H

#include <string>

struct Ingresso {
    int id;
    std::string nomeCliente;
    std::string tipo;
    double preco;
};

struct NodeLista {
    Ingresso dado;
    NodeLista* proximo;
};


struct NodeFila
{
    std::string acao;
    NodeFila* proximo;
};

#endif