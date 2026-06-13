#pragma once
#include <string>

namespace Estruturas
{

    struct Ingresso
    {
        std::string nomeCliente;
        double preco;
        std::string tipo; // VIP, Pista, Mesanino
    };

    class ListaEncadeada
    {
    private:
        struct Node
        {
            Ingresso valor;
            Node *proximo;

            Node(Ingresso v)
            {
                valor = v;
                proximo = nullptr;
            }
        };

        Node *HEAD;

    public:
        ListaEncadeada();
        ~ListaEncadeada();

        void inserirNoInicio(Ingresso valor);
        void inserirNoFinal(Ingresso valor);
        void inserirAposValor(Ingresso valorProcurado, Ingresso novoValor);
        void removerElemento(Ingresso valor);
        void exibirLista();
        void liberarLista();
    };

    class Fila
    {
    private:
        struct No
        {
            Ingresso dado;
            No *prox;
        };

        No *inicio = nullptr;
        No *fim = nullptr;

    public:
        Fila();
        ~Fila();

        void enqueue(Ingresso vlr);
        bool filaVazia();
        void showQueue();
        Ingresso peek();
        Ingresso dequeue();
    };
}