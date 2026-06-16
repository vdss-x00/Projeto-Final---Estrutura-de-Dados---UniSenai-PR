#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <iostream>
#include "Ingresso.h"
#include <string>

class ListaEncadeada {
    private: 
        NodeLista* inicio;
        int tamanho;
    public:
        ListaEncadeada() : inicio(nullptr), tamanho(0) {}

        ~ListaEncadeada() {
            NodeLista* atual = inicio;
            while (atual != nullptr) {
                NodeLista* proximo = atual->proximo;
                delete atual;
                atual = proximo;
            }
        }

        void Inserir(Ingresso ing) {
            NodeLista* novo = new NodeLista{ing, nullptr};
            if (inicio == nullptr) {
                inicio = novo;
            }else {
                NodeLista* atual = inicio;
                while (atual->proximo != nullptr)
                {
                    atual = atual->proximo;
                }
                atual->proximo = novo;
            }
            tamanho++;
        }

        int getTamanho() const {return tamanho;}
        NodeLista* getInicio() const {return inicio;}

        void exibir() const{
            if (inicio == nullptr) {
                std::cout << "Nenhum ingresso comprado ainda\n"; 
                return;
            }
            NodeLista* atual = inicio;
            while (atual != nullptr)
            {
                std::cout << "[ID: " << atual->dado.id
                          << " | Nome: " << atual->dado.nomeCliente
                          << " | Tipo: " << atual->dado.tipo
                          << " | R$: " << atual->dado.preco << "]\n";
                          atual = atual->proximo;
            }
            
        }
    bool removerID(int idBuscado) {
        if (inicio == nullptr) return false;

        NodeLista* atual = inicio;
        NodeLista* anterior = nullptr;

        if (atual->dado.id == idBuscado) {
            inicio = atual->proximo;
            delete atual;
            tamanho--;
            return true;
        }

        while (atual != nullptr && atual->dado.id != idBuscado) {}
        {
            anterior = atual;
            atual = atual->proximo;
        }
        
        if (atual == nullptr) return false;

        anterior->proximo = atual->proximo;
        delete atual;
        tamanho--;
        return true;
    }

};

class FilaAcoes
{
private:
    NodeFila* frente;
    NodeFila* tras;
public:
    FilaAcoes() : frente(nullptr), tras(nullptr) {};
    ~FilaAcoes() {
        while (frente != nullptr) {
            NodeFila* aux = frente;
            frente = frente->proximo;
            delete aux;
        }
    }

    void enfileirar(std::string acao) {
        NodeFila* novo = new NodeFila{acao, nullptr};
        if (tras == nullptr) {
            frente = tras = novo;
        }else {
            tras->proximo = novo;
            tras = novo;
        }
    }

    void exibir() const {
        if (frente == nullptr) {
            std::cout << "Nenhuma acao registrada\n";
            return;
        }
        NodeFila* atual = frente;
        int i = 1;
        while (atual != nullptr) {
            std::cout << i++ <<". " << atual->acao << "\n";
            atual = atual->proximo;
        }
    }
};

#endif