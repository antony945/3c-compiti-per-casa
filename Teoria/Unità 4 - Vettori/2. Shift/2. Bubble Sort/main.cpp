#include <iostream>

using namespace std;

int ottieniDimensione(void);
void caricamento(int v[], int n);
void indirizzo(int v[], int n);
void stampa(int v[], int n);

void selectionSort(int v[], int n);
void bubbleSort(int v[], int n);
void swap(int v[], int n, int f_pos, int s_pos);

int main(){
    int dimensione_array = 0;
    int vettore[dimensione_array];

    dimensione_array = ottieniDimensione();
    caricamento(vettore, dimensione_array);

    bubbleSort(vettore, dimensione_array);

    stampa(vettore, dimensione_array);

    return 0;
}

void swap(int v[], int n, int f_pos, int s_pos){
    if((f_pos < n) && (s_pos < n)){
        int comodo = v[f_pos];
        v[f_pos] = v[s_pos];
        v[s_pos] = comodo;
    }
}

void bubbleSort(int v[], int n){
    /* L'errore consisteva nel assegnare a k la variabile i, contenente la posizione PRIMA di essere scambiato
    del numero maggiore. Il problema � che dopo lo scambio il maggiore non sar� pi� nella posizione i,
    ma nella posizione immediatamente successiva e perci� a k, variabile tenente conto della posizione di i
    nei vari cicli del for (alla fine deve essere la posizione del maggiore degli elementi e si deve depositare
    alla fine del vettore prima dell'ultimo maggiore trovato), va assegnato i+1, ossia la posizione del maggiore
    DOPO lo scambio. */

    bool swapper = true;
    int k = n;
    while(swapper){
        int sup = k;
        swapper = false;

        for(int i=0; i<sup-1; i++){
            if(v[i] > v[i+1]){
                swap(v, n, i, i+1);
                swapper = true;
                k = i+1; /*NON si pu� mettere soltanto k=i perch� i � la posizione del numero maggiore PRIMA di
                           essere scambiato e dopo essere stato scambiato il maggiore avanza di una posizione percio k=i+1*/
            }
        }
    };
}

void selectionSort(int v[], int n){
    int comodo, j;

    for(int i=0; i<n-1; i++){
        int min = v[i];
        int pos;
        for(j=i+1; j<n; j++){
            if(v[j] < min){
                min = v[j];
                pos = j;
            }
        }
        comodo = v[i];
        v[i] = min;
        v[pos] = comodo;
    }
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

