#pragma once

namespace Ordenacoes{

    class BubbleSort{
    public:
        static void ordena(int v[], int n){
            for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < n - 1 - i; j++){
                    if (v[j] > v[j + 1]){
                        int aux = v[j];
                        v[j] = v[j + 1];
                        v[j + 1] = aux;
                    }
                }
            }
        }
    };

    class QuickSort{
    private:
        static int particiona(int v[], int inicio, int fim){
            int pivo = v[fim];
            int i = inicio - 1;
            for (int j = inicio; j < fim; j++){
                if (v[j] <= pivo){
                    i++;
                    int aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
            int aux = v[i + 1];
            v[i + 1] = v[fim];
            v[fim] = aux;
            return i + 1;
        }

    public:
        static void ordena(int v[], int inicio, int fim){
            if (inicio < fim){
                int p = particiona(v, inicio, fim);
                ordena(v, inicio, p - 1);
                ordena(v, p + 1, fim);
            }
        }
    };
}