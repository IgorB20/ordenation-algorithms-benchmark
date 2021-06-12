#ifndef ORDENATION_H
#define ORDENATION_H
#include <vector>

using namespace std;

void bubbleSort(vector<int> &vetor);

void selectionSort(vector<int> &vetor);

void insertionSort(vector<int> &vetor);

void quickSort(vector<int> &vetor, int began, int end);

void merge(vector<int> &vetor, int ini, int meio, int fim, int vetAux[]);
void MergeSort(vector<int> &vetor, int inicio, int fim, int vetorAux[]) ;
void MergeSort(vector<int> &vetor);
#endif // ORDENATION_H
