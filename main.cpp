/**Não recomendo colocar o "using namespace std" aqui, pq pode dar conflito 
com os arquivos header (.hpp). Mas enfim, vamo desenvolver mais pra dps ver mais sobre isso. - Vitor*/

#include <iostream>
#include "./headers/estruturas.hpp"
#include "./headers/buscas.hpp"
#include "./headers/ordenacoes.hpp"

void sistemaLoja(){
//código vai aqui
}

void sistemaIngresso(){
//código vai aqui
}


int main(){

    int seletor;

    do{
        std::cout << "Selecione o sistema que deseja acessar: " << std::endl;
        std::cout << "1 - Sistema de Loja" << std::endl;
        std::cout << "2 - Sistema de Ingresso" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cin >> seletor;

        switch (seletor)
        {
        case 1:
            sistemaLoja();
            break;
        
        case 2:
            sistemaIngresso();
            break;

        case 0:
            std::cout << "Saindo do programa..." << std::endl;
            break;

        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
            break;
        }

    }while(seletor != 0);
    
    return 0;
}