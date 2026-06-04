#pragma once

namespace Buscas
{

    int linear(int v[], int n, int x){
        for (int i = 0; i < n; i++){
            if (v[i] == x)
                return i;
        }
        return -1;
    }

    int binaria(int v[], int n, int x){
        int inicio = 0, fim = n - 1;
        while (inicio <= fim){
            int meio = (inicio + fim) / 2;
            if (v[meio] == x)
                return meio;
            else if (x < v[meio])
                fim = meio - 1;
            else
                inicio = meio + 1;
        }
        return -1;
    }

}