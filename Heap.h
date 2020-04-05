
#ifndef HEAP_SORT_HEAP_H
#define HEAP_SORT_HEAP_H
#define SIZE 100000000
using namespace std;

class Heap{
private:
    int sizeArray=0;
    int *array = new int[SIZE];
    unsigned long counter=0;
    void heapifyRecursion(int i){
    int max=i;
    if(2 * i + 1 < sizeArray && array[2 * i + 1] > array[max]){
        counter++;
        max=2*i+1;
    }
    if(2*i+2<sizeArray && array[2*i+2] > array[max]){
        counter++;
        max=2*i+2;
    }
    if(max!=i){
        counter++;
        swap(array[max],array[i]);
        heapifyRecursion(max);
    }
    }

public:

    void build(int a[] , int n){

        for(int i=0;i<n;++i){
            array[i]=a[i];
        }
        sizeArray=n;
        for(int i = sizeArray / 2 - 1 ; i >= 0 ; --i ){
            heapifyRecursion(i);
        }

    }
    void push(int x){
        if(sizeArray==SIZE){
            cout << "Heap is FULL" << endl;
        }else{
            int indexOfChild=sizeArray;
            array[indexOfChild]=x;
            while(indexOfChild > 0 && array[indexOfChild] > array[indexOfChild / 2]){
                swap(array[indexOfChild], array[indexOfChild / 2]);
                indexOfChild= indexOfChild / 2;
            }
            ++sizeArray;
        }
    }           // Wstawia element do kopca
    int pop() {
        if (isEmpty()) {
            cout << "Heap is EMPTY" << endl;
        } else {
            int last = array[sizeArray - 1], indexOfChild = 1, indexOfParent = 0;
            int max = array[0];
            while (indexOfChild < sizeArray - 1) {
                if (indexOfChild + 1 < sizeArray - 1 && array[indexOfChild + 1] > array[indexOfChild]) {
                    ++indexOfChild;
                }
                if (array[indexOfChild] <= last) {
                    break;
                }
                array[indexOfParent] = array[indexOfChild];
                indexOfParent = indexOfChild;
                indexOfChild = (int) 2 * indexOfChild + 1;
            }
            array[indexOfParent] = last;
            --sizeArray;
            return max;
        }
    }                  // Usuwa element z kopca
    int& top(){
        if(isEmpty()){
            cout<< "Heap is EMPTY" << endl;
        }else {
            return array[0];
        }
    }                 // Zwraca referncję do ostatniego elementu
    int size(){
        return sizeArray;
    }                 // Zwraca liczbę elementów w kopcu
    bool isEmpty(){
        return sizeArray==0;
    }               // Sprawdza czy kopiec jest pusty
    bool check(){
        for(int i=sizeArray-1;i>=1;--i){
            int indexOfParent=(i-1)/2;
            if(array[indexOfParent]<array[i]){
                return false;
            }
        }
        cout << "true" << endl;
        return true;
    }               // Sprawdza czy właściwość kopca jest zachowana
    void sort(int array[],int size){
        build(array,size);
       // sizeArray=size;

        for(int i=sizeArray-1; i >= 0; --i){
            swap(array[0],array[i]);
            --sizeArray;
            heapifyRecursion(0);
        }
        cout << "Counter: "  << counter << endl;
    }
    void printHeap(){
        for (int i = 0; i <sizeArray ; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    void printHeapAfterBuild(int n){
        for (int i = 0; i <n ; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    void genRandom(int n){
        srand(time(NULL));
        for(int i=0;i<n;++i){
           array[i]=rand()%9999+1;
           ++sizeArray;
        }
    }
    void genSorted(int n){
        for(int i =1; i<=n;++i){
            array[i]= 2 * i;
            ++sizeArray;
        }
    }
    void genReverse(int n){
        for (int i = n-1;i >= 0;--i) {
            array[i] = 2 * i +1;
            ++sizeArray;
        }
    }
    void genSortedFirst(int n){
        srand(time(NULL));
        array[0]=rand()%9999+1;
        ++sizeArray;
        for (int i = 1; i < n; ++i) {
            array[i] = 2 * i +1;
            ++sizeArray;
        }
    }
    void genSortedLast(int n){
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            array[i] = 2 * i +1;
            ++sizeArray;
        }
        array[n-1]= rand()%9999999+1;
        ++sizeArray;
    }
};
#endif //HEAP_SORT_HEAP_H
