#ifndef SISTEMA_INGRESSOS_H
#define SISTEMA_INGRESSOS_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <ingresso.h>
#include <estruturas.h>
#include <buscas.h>

class SistemaIngressos
{
private:
    ListaEncadeada historicoCompras;
    FilaAcoes hitoricoAcoes;
    int proximoID;

    std::vector<Ingresso> vetorHistorico() {
        std::vector<Ingresso> listavetor;
        NodeLista* atual = historicoCompras.getInicio();
        while (atual != nullptr) {
            listavetor.push_back(atual->dado);
            atual = atual->proximo;
        }
        return listavetor;
    }
public:
    SistemaIngressos() : proximoID(1001) {}

    void comprarIngresso(std::string nome, std::string tipo, double preco) {
        Ingresso novoIngresso = {proximoID++, nome, tipo, preco};
        historicoCompras.Inserir(novoIngresso);
        hitoricoAcoes.enfileirar("Compra realizada - Cliente: " + nome + " | Tipo: " + tipo);
        std::cout << "\nID do ingresso gerado: " << novoIngresso.id << "\n";
    }

    void exibirHistoricoCompras() {
        hitoricoAcoes.enfileirar("Exibiu historico de compras");
        std::cout << "\n====Historico de Compras====\n";
        historicoCompras.exibir();
    }

    void exibirHistoricoAcoes() {
        hitoricoAcoes.enfileirar ("Exibiu historico acoes");
        std::cout << "\n====Historico Acoes====\n";
        hitoricoAcoes.exibir();
    }
    
    void testarExibirOrdenacao() {
        if (historicoCompras.getTamanho() == 0) {
            std::cout << "Sem dados para ordenar\n";
            return;
        }

        hitoricoAcoes.enfileirar("Executou comparacao de algoritimos de ordenacao");
        std::vector<Ingresso> dadosParaBubble = vetorHistorico();
        std::vector<Ingresso> dadosParaQuick = vetorHistorico();

        //Bubble
        auto inicio = std::chrono::high_resolution_clock::now();
        MotorBuscaOrdenacao::bubbleSort(dadosParaBubble);
        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> tempoBubble = fim - inicio;


        //Quick
        inicio = std::chrono::high_resolution_clock::now();
        MotorBuscaOrdenacao::quickSort(dadosParaQuick, 0, dadosParaQuick.size() -1); //Ordenar
        fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> tempoQuick = fim - inicio;

        std::cout << "\n====Ingressos Ordenados por ID====\n";
        for (const auto& ing: dadosParaQuick) {
            std::cout << "[ID: " << ing.id << " | " << ing.nomeCliente << " | " << ing.tipo << "]\n";
        }

        std::cout << "\n====Comparativo de Performance (Ordenacao)====\n";
        std::cout << "Tempo BubbleSort: " << tempoBubble.count() << "ns\n";
        std::cout << "Tempo QuickSort: " << tempoQuick.count() << "ns\n";
    }

    void buscarID(int idBuscado) {
        std::vector<Ingresso> dadosBusca = vetorHistorico();
        if (dadosBusca.empty()) {
            std::cout << "Nenhum ingresso cadastrado no sistema\n";
            return;
        }

        hitoricoAcoes.enfileirar("Busca realizada por ID");

        const int Repeticoes = 100000;
        int resSeq = -1;
        int resBin = -1;

        //Sequencial
        auto inicioSeq = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < Repeticoes; i++) {
            int idDinamico = idBuscado + (i % 2);
            resSeq = MotorBuscaOrdenacao::buscaSequencial(dadosBusca, idDinamico);
        }
        auto fimSeq = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> tempoSeq = fimSeq - inicioSeq;
        double tempoMedioSeq = tempoSeq.count()/Repeticoes;

        //Binaria
        MotorBuscaOrdenacao::quickSort(dadosBusca, 0, dadosBusca.size() - 1);
        auto inicioBin = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < Repeticoes; i++) {
            int idDinamico = idBuscado + (i % 2);
            resBin = MotorBuscaOrdenacao::buscaBinaria(dadosBusca, idDinamico);
        }
        auto fimBin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::nano> tempoBin = fimBin - inicioBin;
        double tempoMedioBin = tempoBin.count()/Repeticoes;

        int indiceExibir = MotorBuscaOrdenacao::buscaBinaria(dadosBusca, idBuscado);
        //Resultado
        if (indiceExibir != -1) {
            Ingresso achado = dadosBusca[indiceExibir];
            std::cout << "\nIngresso Encontrado\n";
            std::cout << "Cliente: " << achado.nomeCliente << "\nTipo: " << achado.tipo << "\nPreco (R$): " << achado.preco << "\n";
        }else {
            std::cout << "\nIngresso do ID " << idBuscado << " nao foi encontrado\n";
        }

        std::cout << std::fixed << std::setprecision(4);
        std::cout << "\n====Comparativo de Performance(Busca)====\n";
        std::cout << "Tempo Sequencial: " << tempoMedioSeq << "ns\n";
        std::cout << "Tempo Binaria: " << tempoMedioBin << "ns\n";
    }

    void gerarCarga (int quantidade) {
        for (int i = 0; i < quantidade; i++) {
            Ingresso novoIngresso = {proximoID + quantidade-i, "Cliente Anonimo", "Pista", 150.0};
            historicoCompras.Inserir(novoIngresso);
        }
        proximoID += (quantidade +1);
        hitoricoAcoes.enfileirar("Carga de clientes para teste gerada");
        std::cout << "\n" << quantidade << "Ingressos gerados aleatoriamente para teste de performance\n";
    }

    void removerID (int idBuscado) {
        bool removido = historicoCompras.removerID(idBuscado);

        if (removido) {
            hitoricoAcoes.enfileirar("Ingresso removido");
            std::cout << "\nIngresso com ID: " << idBuscado << " foi removido com sucesso\n";
        }else {
            hitoricoAcoes.enfileirar("Falha ao remover Ingresso");
            std::cout << "\nIngresso com ID: " << idBuscado << " nao foi encontrado\n";
        }
    }

};

#endif