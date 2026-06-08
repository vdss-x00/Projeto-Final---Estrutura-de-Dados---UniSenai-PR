#include "../headers/estruturas.hpp"
#include <iostream>

Estruturas::Fila::Fila(){}

Estruturas::Fila::~Fila(){
    while(!filaVazia()){
        dequeue();
    }
}

void Estruturas::Fila::enqueue(int vlr){
    No* novo = new No();
    novo->dado = vlr;
    novo->prox = nullptr;

    std::cout << novo->dado;

    if (fim == nullptr){
        inicio = fim = novo;
    }else{
        fim->prox = novo;
        fim = novo;
    }
}

bool Estruturas::Fila::filaVazia(){
    return inicio == nullptr;
}

void Estruturas::Fila::showQueue(){
    if (filaVazia()){
        std::cout << "Fila vazia." << std::endl;
        return;
    }

    No* atual = inicio;


    std::cout << "Fila: ";

    while (atual != nullptr){
        std::cout << atual->dado << " ";
        atual = atual->prox;
    }

    std::cout << std::endl;
}


int Estruturas::Fila::peek(){
    if (filaVazia()){
        std::cout << "Fila vazia." << std::endl;
        return -1;
    }
    return inicio->dado;
}

int Estruturas::Fila::dequeue(){
    if (inicio != nullptr){
        struct No *aux = inicio;
        int vlr = aux->dado;
        inicio = aux->prox;

        if (inicio == nullptr){
            fim = nullptr;
        }

        delete aux;
        return vlr;
    }
    else{
        std::cout << "ERRO. Fila vazia." << std::endl;
        return -1;
    }
}




