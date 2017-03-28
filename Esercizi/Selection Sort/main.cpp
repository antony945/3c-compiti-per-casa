#include <iostream>

using namespace std;

int ottieniDimensione(void);
void caricamento(int v[], int n);
void indirizzo(int v[], int n);
void stampa(int v[], int n);
int somma(int v[], int n);

void selectionSort(int v[], int n);

int main(){
    int dimensione_array = 0;
    int vettore[dimensione_array];

    dimensione_array = ottieniDimensione();
    caricamento(vettore, dimensione_array);

    selectionSort(vettore, dimensione_array);

    stampa(vettore, dimensione_array);

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
    for(int i=0; i<n; i++){
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

void selectionSort(int v[], int n){
    int comodo;

    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[min]){
                min = j;
            }
        }

        comodo = v[min];
        v[min] = v[i];
        v[i] = comodo;
    }
}

