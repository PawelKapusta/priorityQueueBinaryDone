#include <iostream>
#include <fstream>
#include <chrono>
#include "Heap.h"
int main() {

    Heap heap;

    srand(time(NULL));
    int n=100000000;
    ofstream zapis;
    for (int j = 0; j < n; ++j) {
        heap.push(j);
    }

    zapis.open("/home/sony/CLionProjects/AISD2/Zadanie3B/daneDelete.txt",ios::out | ios::app);

    double totalTime=0;
    if (zapis.good()) {
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j < n ; j++) {
            heap.pop();
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        totalTime = elapsed.count();
    }
    zapis << n  << " " << totalTime << endl;

    //zapis << "e" << endl;
    zapis.flush();
    zapis.close();





    return 0;
}
