#pragma once

namespace Estruturas{

    class ListaEncadeada{
    private:
        struct Node{
            int valor;
            Node *proximo;

            Node(int v){
                valor = v;
                proximo = nullptr;
            }

        };

        Node* HEAD;

    public:
        ListaEncadeada();
        ~ListaEncadeada();

        void inserirNoInicio(int valor);
        void inserirNoFinal(int valor);
        void inserirAposValor(int valorProcurado, int novoValor);
        void removerElemento(int valor);
        void exibirLista();
        void liberarLista();
    };

    class Fila{
    private:
        struct No{
            int dado;
            No *prox;
        };

        No *inicio = nullptr;
        No *fim = nullptr;

    public:
        Fila();
        ~Fila();

        void enqueue(int vlr);
        bool filaVazia();
        void showQueue();
        int peek();
        int dequeue();
    };
}