#include <iostream>
#define CIFRE_TOTALI 3

using namespace std;

void valori(int num, int cifra[], int x){
    for(x=0; x<CIFRE_TOTALI; x++){
        cifra[x] = num%((x+1)*10);
        valori(num, cifra, (x+1)*10);
    }
}

int main(){
    int cifra[CIFRE_TOTALI];
    int numero;
    int x;

    cout << "Inserisci numero: ";
    cin >> numero;

    valori(numero, cifra, x);

    cout << endl;
    cout << "Il numero al contrario e' ";

    for(int i = 0; i<CIFRE_TOTALI; i++){
        cout << cifra[i];
    }

    cout << endl;
    return 0;
}


