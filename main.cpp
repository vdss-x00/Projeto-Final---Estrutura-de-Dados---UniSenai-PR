#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include "./headers/estruturas.hpp"
#include "./headers/buscas.hpp"
#include "./headers/ordenacoes.hpp"



void sistemaIngresso(){

    Estruturas::ListaEncadeada listaEncadeada;

    int opcao;
    std::vector<Estruturas::Ingresso> lista = {
        {"Bruno", 859.99, "VIP"},
        {"Paulo", 689.99, "Pista"},
        {"Camila", 689.99, "Pista"},
        {"Maria", 729.99, "Mezanino"}
    };

    while (true){
        std::cout << "\n1 - Comprar Ingresso\n"
                     "2 - Cancelar Compra\n"
                     "3 - Mostrar Pedido\n"
                     "0 - Voltar\n"
                     "Opcao: ";

        std::cin >> opcao;

        if (opcao == 0){
            std::cout << "\n";
            return;
        }

        if (opcao == 1){
            Estruturas::Ingresso novoIngresso;
            int tipoOpcao;

            std::cout << "Digite o nome do comprador: ";
            std::getline(std::cin >> std::ws, novoIngresso.nomeCliente);

            std::cout << "\nEscolha o tipo do ingresso:\n"
                         "1 - VIP (R$: 859,99)\n"
                         "2 - Mezanino (R$: 729,99)\n"
                         "3 - Pista (R$: 689,99)\n"
                         "Opcao: ";
            std::cin >> tipoOpcao;

            switch (tipoOpcao){
            case 1:
                novoIngresso.tipo = "VIP";
                novoIngresso.preco = 859.99;
                break;
            case 2:
                novoIngresso.tipo = "Mezanino";
                novoIngresso.preco = 729.99;
                break;
            case 3:
                novoIngresso.tipo = "Pista";
                novoIngresso.preco = 689.99;
                break;
            default:
                std::cout << "\nTipo de ingresso invalido. Cadastro cancelado." << std::endl;
                continue;
            }

            lista.push_back(novoIngresso);
            std::cout << "\nIngresso cadastrado com sucesso." << std::endl;
        }

        if (opcao == 2){

        }

        if (opcao == 3){
            std::string buscarNome;
            std::cout << "\nInsira os dodos do pedido que deseja procurar:\n"
                         "Nome cadastrado no ingresso: ";
            std::getline(std::cin >> std::ws, buscarNome);

            bool encontrado = false;

            for (const Estruturas::Ingresso& item : lista){
                if (item.nomeCliente == buscarNome){
                    std::cout << "\nIngresso encontrado:" << std::endl;
                    std::cout << "Nome: " << item.nomeCliente << std::endl;
                    std::cout << "Preco: R$ " << item.preco << std::endl;
                    std::cout << "Tipo: " << item.tipo << std::endl;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado){
                std::cout << "\nCliente nao encontrado na lista." << std::endl;
            }

        }
    }
}



int main(){

    int seletor;

    do{
        std::cout << "1 - Sistema de Ingresso" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cin >> seletor;

        switch (seletor)
        {
        case 1:
            sistemaIngresso();
            break;

        case 0:
            std::cout << "Saindo do programa..." << std::endl;
            break;

        default:
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
            break;
        }

    }while(seletor != 0);
    
    return 0;
}
