#ifndef ORDENATION_H
#define ORDENATION_H
#include <vector>

using namespace std;

void bubbleSort(vector<int> &vetor);

void selectionSort(vector<int> &vetor);

void insertionSort(vector<int> &vetor);

void quickSort(vector<int> &vetor, int began, int end);

void merge(vector<int> *saida, vector<int> *auxiliar, int inicio, int meio, int fim);

void mergeSort(vector<int> *saida, vector<int> *auxiliar, int inicio, int fim);

void mergeSort(vector<int> *vetor);

#endif // ORDENATION_H
