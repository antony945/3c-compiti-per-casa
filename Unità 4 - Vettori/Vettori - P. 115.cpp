#include <iostream>

using namespace std;

int ottieniDimensione(void);
void caricamento(int v[], int n);
void indirizzo(int v[], int n);
void stampa(int v[], int n);
int somma(int v[], int n);

int main(){
    int vettore[10];
    int dimensione_array;

    dimensione_array = ottieniDimensione();
    caricamento(vettore, dimensione_array);
    indirizzo(vettore, dimensione_array);
    stampa(vettore, dimensione_array);

    cout << endl << "Somma dei " << dimensione_array << " elementi: " << somma(vettore, dimensione_array) << endl;

    return 0;
}

int ottieniDimensione(){
    int n;

    do{
        cout << "Inserisci il numero di elementi di cui vuoi sia composto l'array: ";
        cin >> n;

        if(n<=0 || n>10){
            cout << endl;
            cout << "La dimensione deve essere compresa tra 1 e 10!" << endl;
        }
    }while(n<=0 || n>10);

    return n;
}

void caricamento(int v[], int n){
    int elemento;

    for(int i=0; i<n; i++){
        cout << "- Vettore[" << i << "]: ";
        cin >> elemento;

        v[i] = elemento;
    }
}

void indirizzo(int v[], int n){
    cout << endl << "Indirizzi: " << endl;
    for(int i = 0; i < n; i++){
        cout << endl << "- Vettore[" << i << "]: " << v+i << endl;
    }
}

void stampa(int v[], int n){
    cout << endl << "Il vettore e' composto da: ";
    cout << endl;
    for(int i=0; i<10; i++){
        cout << " - [" << i+1 << "] = " << v[i] << " ";
        cout << endl;
    }
}

int somma(int v[], int n){
    int somma = 0;

    for(int i=0; i<n; i++){
        somma+=v[i];
    }

    return somma;
}
