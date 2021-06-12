#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "ordenation.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    clock_t t;

    unsigned seed = time(0);
    srand(seed);

    int dataAmount = 1000;

    vector<int> nums;

    for(int i = 0; i<dataAmount; i++){
        nums.push_back(1+rand()%dataAmount);
    }

    cout << "VETOR GERADO: " << endl;
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i] << endl;
    }
    cout << endl;


    cout << "Executando..." << endl;
    t = clock();
    MergeSort(nums);
    t = clock() - t;

    cout << "DONE" << endl;
    cout << "Tempo de execução: " << (float)t/CLOCKS_PER_SEC << " segundos" << endl;
    cout << "Numero de elementos ordenados: " << dataAmount << endl;

    cout << endl;

    cout << "VETOR ORDENADO: " << endl;
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i] << endl;
    }


    return a.exec();
}
