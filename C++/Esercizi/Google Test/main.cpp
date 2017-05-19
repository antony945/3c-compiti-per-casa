#include <iostream>
#include "../../Header/array.h"

using namespace std;

bool testSum(int v[], int n);

int main(){
    int dim = 4;
    int vet[dim];

    caricamento(vet, dim);

    if(testSum(vet, dim))
        cout << "Vero.";
    else
        cout << "Falso.";

    cout << endl;

    return 0;
}

bool testSum(int v[], int n){
    int sum;
    cout << "Sum: ";
    cin >> sum;

    bubbleSort(v, n);

    int i=0;
    int j=n-1;

    do{
        if(v[i]+v[j] > sum)
            j--;
        if(v[i]+v[j] < sum)
            i++;
        if(v[i]+v[j] == sum)
            return true;
    }while(i!=j);

    return false;
}
