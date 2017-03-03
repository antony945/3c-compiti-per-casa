#include <iostream>
#include <stdlib.h>

using namespace std;
int ottienidimensione(void);
void stampa(char vet[], int dim);

int main(){
    char v[10];        // dichiarazione di un vettore di 10 interi
    int numelementi;  // numero di elementio dell'array v
    numelementi=ottienidimensione();
    for (int i=0; i < numelementi; i++) {
        cout << "Inserisci il " << i+1 << " elemento: ";
        cin >> v[i];
    }
    cout << "Ecco l'indirizzo di partenza dell' array : " << v << endl;
    stampa(v, numelementi);
    system("PAUSE");
    return 0;
}

int ottienidimensione(){
    int dim;
    do {
        cout << "Inserisci il numero di elementi: ";
        cin >> dim;
    } while (dim <= 0 || dim > 10);
    return dim;
}

void stampa(char vet[], int dim){
    for (int i=0; i < dim; i++) {
        cout << "Ecco il " << i+1 << " elemento: " << vet[i] << endl;
    }
}
