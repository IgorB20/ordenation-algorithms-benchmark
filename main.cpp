#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

void bubbleSort(vector<int> &nums, int size){
    bool swap;

    do{
        swap = false;
        for(int i = 0; i < size-1; i++){
            if(nums[i] > nums[i+1]){
                swap = true;
                int aux = nums[i + 1];
                nums[i + 1] = nums[i];
                nums[i] = aux;
            }
        }

    }while(swap);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    clock_t t;

    unsigned seed = time(0);
    srand(seed);

    int dataAmount = 30000;

    vector<int> nums;

    for(int i = 0; i<dataAmount; i++){
        nums.push_back(1+rand()%dataAmount);
    }
/*
    cout << "VETOR GERADO: " << endl;
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i] << endl;
    }*/
    cout << "Executando bubble sort..." << endl;
    t = clock();
    bubbleSort(nums, nums.size());
    t = clock() - t;
    cout << "DONE" << endl;
    cout << "Tempo de execução: " << (float)t/CLOCKS_PER_SEC << " segundos" << endl;
    cout << "Numero de elementos ordenados: " << dataAmount << endl;

    //cout << "VETOR ORDENADO: " << endl;
    //for(int i = 0; i<nums.size(); i++){
        //cout << nums[i] << endl;
    //}


    return a.exec();
}
