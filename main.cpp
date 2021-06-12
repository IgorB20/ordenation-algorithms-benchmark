#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "ordenation.h"
#include <string>

using namespace std;


string getAlgorithmName(int code){
    switch (code) {
    case 1:
        return "Bubble Sort";
        break;
    case 2:
        return "Selection Sort";
        break;
    case 3:
        return "Insertion Sort";
        break;
    case 4:
        return "Quick Sort";
        break;
    case 5:
        return "Merge Sort";
        break;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    clock_t t;

    unsigned seed = time(0);
    srand(seed);

    int dataAmount;
    int algorithm;

    cout << "Informe a quantidade de elementos a serem ordenados: " << endl;
    cin >> dataAmount;

    cout << "Escolha o algoritmo de ordenação a ser utilizado: " << endl;
    cout << "1 - Bubble sort" << endl;
    cout << "2 - Selection sort" << endl;
    cout << "3 - Insertion sort" << endl;
    cout << "4 - Quick sort" << endl;
    cout << "5 - Merge sort" << endl;
    cin >> algorithm;

    cout << "Gerando vetor com numeros aleatorios..." << endl;
    vector<int> nums;
    for(int i = 0; i<dataAmount; i++){
        nums.push_back(1+rand()%dataAmount);
    }

    cout << endl;
    cout << "Executando " << getAlgorithmName(algorithm) << " ..." << endl;
    cout << endl;

    t = clock();

    switch (algorithm) {
    case 1:
        bubbleSort(nums);
        break;
    case 2:
        selectionSort(nums);
        break;
    case 3:
        insertionSort(nums);
        break;
    case 4:
        quickSort(nums, 0, nums.size());
        break;
    case 5:
        MergeSort(nums);
        break;
    }

    t = clock() - t;

    cout << "DONE" << endl;
    cout << "Tempo de execução: " << (float)t/CLOCKS_PER_SEC << " segundos" << endl;
    cout << "Numero de elementos ordenados: " << dataAmount << endl;
    cout << "Algoritmo: " << getAlgorithmName(algorithm) << endl;

    cout << endl;


    /*
    cout << "VETOR ORDENADO: " << endl;
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i] << endl;
    }*/


    /*
    cout << "VETOR GERADO: " << endl;
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i] << endl;
    }
    cout << endl;
*/

    return a.exec();
}
