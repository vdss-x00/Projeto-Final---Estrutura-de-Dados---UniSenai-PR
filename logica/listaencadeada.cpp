#include "../headers/estruturas.hpp"
#include <iostream>

Estruturas::ListaEncadeada::ListaEncadeada(){
    HEAD = nullptr;
}

Estruturas::ListaEncadeada::~ListaEncadeada(){
    liberarLista();
}

void Estruturas::ListaEncadeada::inserirNoInicio(int valor){
    Node* novoNode = new Node(valor);
    novoNode->proximo = HEAD;
    HEAD = novoNode;
    std::cout << "Elemento " << valor << " inserido no início." << std::endl;
}

void Estruturas::ListaEncadeada::inserirNoFinal(int valor){
    Node* novoNode = new Node(valor);
    
    if (HEAD == nullptr) {
        HEAD = novoNode;
    } else {
        Node* atual = HEAD;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novoNode;
    }
    std::cout << "Elemento " << valor << " inserido no final." << std::endl;
}

void Estruturas::ListaEncadeada::inserirAposValor(int valorProcurado, int novoValor){
    Node* atual = HEAD;
    
    while (atual != nullptr && atual->valor != valorProcurado) {
        atual = atual->proximo;
    }
    
    if (atual == nullptr) {
        std::cout << "Valor " << valorProcurado << " não encontrado na lista." << std::endl;
    } else {
        Node* novoNode = new Node(novoValor);
        novoNode->proximo = atual->proximo;
        atual->proximo = novoNode;
        std::cout << "Elemento " << novoValor << " inserido após " << valorProcurado << "." << std::endl;
    }
}

void Estruturas::ListaEncadeada::removerElemento(int valor){
    if (HEAD == nullptr) {
        std::cout << "Lista vazia. Nada a remover." << std::endl;
        return;
    }
    
    
    if (HEAD->valor == valor) {
        Node* temp = HEAD;
        HEAD = HEAD->proximo;
        delete temp;
        std::cout << "Elemento " << valor << " removido." << std::endl;
        return;
    }
    
   
    Node* atual = HEAD;
    while (atual->proximo != nullptr && atual->proximo->valor != valor) {
        atual = atual->proximo;
    }
    
    if (atual->proximo == nullptr) {
        std::cout << "Elemento " << valor << " não encontrado na lista." << std::endl;
    } else {
        Node* temp = atual->proximo;
        atual->proximo = temp->proximo;
        delete temp;
        std::cout << "Elemento " << valor << " removido." << std::endl;
    }
}

void Estruturas::ListaEncadeada::exibirLista(){
    if (HEAD == nullptr) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }
    
    std::cout << "Elementos da lista: ";
    Node* atual = HEAD;
    while (atual != nullptr) {
        std::cout << atual->valor << " -> ";
        atual = atual->proximo;
    }
    std::cout << "NULL" << std::endl;
}

void Estruturas::ListaEncadeada::liberarLista(){
    while (HEAD != nullptr) {
        Node* temp = HEAD;
        HEAD = HEAD->proximo;
        delete temp;
    }

    HEAD = nullptr;
}

