#ifndef BUSCA_H
#define BUSCA_H

#include <vector>
#include <utility>
#include "ingresso.h"

class MotorBuscaOrdenacao {
private:
    static int particionar(std::vector<Ingresso>& vec, int baixo, int alto) {
        int pivo = vec[alto].id;
        int i = (baixo - 1);
        for (int j = baixo; j <= alto - 1; j++) {
            if (vec[j].id < pivo) {
                i++;
                std::swap(vec[i], vec[j]);
            }
        }
        std::swap(vec[i + 1], vec[alto]);
        return (i + 1);
    }

public:
    static void bubbleSort(std::vector<Ingresso>& vec) {
        int n = vec.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (vec[j].id > vec[j + 1].id) {
                    std::swap(vec[j], vec[j + 1]);
                }
            }
        }
    }

    static void quickSort(std::vector<Ingresso>& vec, int baixo, int alto) {
        if (baixo < alto) {
            int pi = particionar(vec, baixo, alto);
            quickSort(vec, baixo, pi - 1);
            quickSort(vec, pi + 1, alto);
        }
    }

    static int buscaSequencial(const std::vector<Ingresso>& vec, int idBuscado) {
        for (size_t i = 0; i < vec.size(); i++) {
            if (vec[i].id == idBuscado) {
                return i;
            }
        }
        return -1;
    }

    static int buscaBinaria(const std::vector<Ingresso>& vec, int idBuscado) {
        int esquerda = 0;
        int direita = vec.size() - 1;
        while (esquerda <= direita) {
            int meio = esquerda + (direita - esquerda) / 2;
            if (vec[meio].id == idBuscado) return meio;
            if (vec[meio].id < idBuscado) esquerda = meio + 1;
            else direita = meio - 1;
        }
        return -1;
    }
};

#endif