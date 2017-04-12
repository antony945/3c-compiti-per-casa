#include <iostream>

using namespace std;

bool test(int a[], int b[]);

int main(){
    int vet1[10] = {5, 8, 1, 10, 6, 3, 27, 5, 9, 1};
    int vet2[10] = {5, 8, 1, 10, 6, 3, 27, 5, 9, 1};

    if(test(vet1, vet2))
        cout << "I due array sono uguali.";
    else
        cout << "I due array sono diversi.";

    return 0;
}

bool test(int a[], int b[]){
    bool same = true;
    int n; //contatore del ciclo

    for(n=0; n<10; n++){
        if(a[n] == b[n]){
            same = true;
        }else{
            same = false;
            return same;
        }
    }

    return same;
}
