#include "ordenation.h"
#include <iostream>

//Implementado pelo autor
void bubbleSort(vector<int> &vetor){
    bool swap;

    do{
        swap = false;
        for(int i = 0; i < vetor.size()-1; i++){
            if(vetor[i] > vetor[i+1]){
                swap = true;
                int aux = vetor[i + 1];
                vetor[i + 1] = vetor[i];
                vetor[i] = aux;
            }
        }

    }while(swap);

}

//código retirado do link: https://pt.wikipedia.org/wiki/Selection_sort
void selectionSort(vector<int> &vetor) {
    for (int indice = 0; indice < vetor.size(); ++indice) {
        int indiceMenor = indice;
        for (int indiceSeguinte = indice+1; indiceSeguinte < vetor.size(); ++indiceSeguinte) {
            if (vetor[indiceSeguinte] < vetor[indiceMenor]) {
                indiceMenor = indiceSeguinte;
            }
        }
        int aux = vetor[indice];
        vetor[indice] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }
}

//código retirado do link: https://pt.wikipedia.org/wiki/Insertion_sort
void insertionSort(vector<int> &vetor){
    for (int i = 1; i < vetor.size(); i++) {
        int escolhido = vetor[i];
        int j = i - 1;

        while ((j >= 0) && (vetor[j] > escolhido)) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = escolhido;
    }
}


//código retirado do link: https://pt.wikipedia.org/wiki/Quicksort
void quickSort(vector<int> &vetor, int began, int end)
{
    int i, j, pivo, aux;
    i = began;
    j = end-1;
    pivo = vetor[(began + end) / 2];
    while(i <= j)
    {
        while(vetor[i] < pivo && i < end)
        {
            i++;
        }
        while(vetor[j] > pivo && j > began)
        {
            j--;
        }
        if(i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if(j > began)
        quickSort(vetor, began, j+1);
    if(i < end)
        quickSort(vetor, i, end);
}

//código retirado do link: https://pt.wikipedia.org/wiki/Merge_sort
void merge(vector<int> &vetor, int ini, int meio, int fim, int vetAux[]) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) and ((dir >= fim) or (vetor[esq] < vetor[dir]))) {
            vetAux[i] = vetor[esq];
            ++esq;
        }
        else {
            vetAux[i] = vetor[dir];
            ++dir;
        }
    }
    //copiando o vetor de volta
    for (int i = ini; i < fim; ++i) {
        vetor[i] = vetAux[i];
    }
}

void MergeSort(vector<int> &vetor, int inicio, int fim, int vetorAux[]) {
    if ((fim - inicio) < 2) return;

    int meio = ((inicio + fim)/2);
    MergeSort(vetor, inicio, meio, vetorAux);
    MergeSort(vetor, meio, fim, vetorAux);
    merge(vetor, inicio, meio, fim, vetorAux);
}

void MergeSort(vector<int> &vetor) { //função que o usuario realmente chama
    //criando vetor auxiliar
    int vetorAux[vetor.size()];
    MergeSort(vetor, 0, vetor.size(), vetorAux);
}

