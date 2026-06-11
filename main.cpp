/**Não recomendo colocar o "using namespace std" aqui, pq pode dar conflito 
com os arquivos header (.hpp). Mas enfim, vamo desenvolver mais pra dps ver mais sobre isso. - Vitor*/
#include <string>
#include <iostream>
#include "./headers/estruturas.hpp"
#include "./headers/buscas.hpp"
#include "./headers/ordenacoes.hpp"

void sistemaIngresso(){
    int opcao;
    while (true){
        std::cout << "\n1 - Comprar Ingresso\n"
                     "2 - Cancelar Compra\n"
                     "3 - Mostrar Pedido\n"
                     "4 - Voltar\n"
                     "Opcao: ";

        std::cin >> opcao;

        if (opcao == 4){
            std::cout << "\n";
            return;
        }
        if (opcao == 3){
            std::cout << "\nInsira os dodos do pedido que deseja procurar:\n"
                         "Nome cadastrado no ingresso: ";
        }
        if (opcao == 2){

        }
        if (opcao == 1){
            std::cout << "\nEscolha o tipo do ingresso: \n"
                         "1 - VIP (R$: 859,99)\n"
                         "2 - Mezanino (R$: 729,99)\n"
                         "3 - Pista (R$: 689,99)\n"
                         "4 - Voltar\n"
                         "Opcao: ";
            std::cin >> opcao;
        }
    }
}

struct Cliente
{
    std::string nomeCliente;
    double preco;
    std::string tipo; //VIP, Pista, Mesanino
};



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
