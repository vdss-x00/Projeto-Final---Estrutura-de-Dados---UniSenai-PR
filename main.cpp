#include <iostream>
#include <string>
#include "SistemaIngressos.h"

int main(){

    int seletor = 0;
    SistemaIngressos sistema;
    int opcao;

    do{ 
        std::cout << "\n====Menu====\n";
        std::cout << "1 - Comprar Ingresso" << std::endl;
        std::cout << "2 - Remover Ingresso por ID" << std::endl;
        std::cout << "3 - Ver historico de compras" << std::endl;
        std::cout << "4 - Ordenar Ingressos por ID (Bubble vs Quick)" << std::endl;
        std::cout << "5 - Buscar Ingressos por ID (Sequencial vs Binaria)" << std::endl;
        std::cout << "6 - Ver Historico de Acoes" << std::endl;
        std::cout << "7 - Gerar Carga de Teste" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Opcao: ";
        std::cin >> seletor;
        std::cout << "\n";

        switch (seletor)
        {
        case 1: {
            std::string nome;
            std::string tipo;
            double preco;
            std::cin.ignore();
            std::cout << "Nome do Cliente: ";
            std::getline(std::cin, nome);

            std::cout << "\nTipo de Ingresso\n"
                         "1 - VIP (R$: 350.0)\n"
                         "2 - Mezanino (R$: 280.0)\n"
                         "3 - Pista (R$: 150.0)\n"
                         "Opcao: ";
            std::cin >> opcao;
            std::cout << "\n";

            if (opcao == 1) {
                tipo = "VIP";
                preco = 350.0;
                sistema.comprarIngresso(nome, tipo, preco);
                break;
            }

            if (opcao == 2) {
                tipo = "Mezanino";
                preco = 280.0;
                sistema.comprarIngresso(nome, tipo,preco);
                break;
            }

            if (opcao == 3) {
                tipo = "Pista";
                preco = 150.0;
                sistema.comprarIngresso(nome,tipo,preco);
            }
            
            break;
        }

        case 2:
            int idRemover;
            std::cout << "Digite o ID do ingresso que deseja remover: ";
            std::cin >> idRemover;
            sistema.removerID(idRemover);
            break;

        case 3:
            sistema.exibirHistoricoCompras();
            break;

        case 4:
            sistema.testarExibirOrdenacao();
            break;

        case 5:
            int idBuscar;
            std::cout << "Digite o ID do ingresso que deseja buscar: ";
            std::cin >> idBuscar;
            sistema.buscarID(idBuscar);
            break;

        case 6:
            sistema.exibirHistoricoAcoes();
            break;
        
        case 7: 
            int qnt;
            std::cout << "Quantos ingressos desordenados deseja gerar para o teste: ";
            std::cin >> qnt;
            sistema.gerarCarga(qnt);
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
