#include <iostream>

using namespace std;

void loadArray(int v[], int n);
bool testSum(int v[], int n);

int main(){
    int dim = 4;
    int vet[dim];

    loadArray(vet, dim);

    if(testSum(vet, dim))
        cout << "Vero.";
    else
        cout << "Falso.";

    return 0;
}

bool testSum(int v[], int n){
    bool test = false;

    int sum;
    cout << "Sum: ";
    cin >> sum;

    int i = 0;
    int j = n-1;
    while(v[i] + v[j] != sum){
        if((v[i]+v[j]) > sum)
                j--;
        else if((v[i]+v[j]) < sum)
            i++;
        else
            test = true;
    }

    return test;
}

void loadArray(int v[], int n){
    int num;

    for(int i=0; i<n; i++){
        cout << "vet[" << i << "] = ";
        cin >> num;
        v[i] = num;
    }
}
