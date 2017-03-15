//Es. 4 Pag. 154

#include <iostream>
#include <stdlib.h>

using namespace std;

int dimensioneArray(int v[]);
void caricamentoArray(int v[], int limite);
void operazioniArray(int v[], int limite, int& prodotto, int& somma);

int main(){
    int N = 0;
    int V[N];
    int P, S;

    N = dimensioneArray(V);
    caricamentoArray(V, N);

    operazioniArray(V, N, P, S);

    cout << endl;
    cout << "Prodotto posizioni pari: " << P << endl;
    cout << "Somma posizioni dispari: " << S << endl;

    cout << endl;
    system("PAUSE");
    return 0;
}

int dimensioneArray(int v[]){
    int limite = 0;

    do{
        if(limite<0 || limite>10)
            cout << "\nERRORE! Il limite dell'array deve essere compreso tra 0 e 10. \n\n";
        cout << "Inserisci limite massimo dell'array (<=10): ";
        cin >> limite;
    }while(limite<0 || limite>10);

    return limite;
}

void caricamentoArray(int v[], int limite){
    int num;

    cout << "\nCARICAMENTO\n";

    for(int i=0; i<limite; i++){
        cout << "- [" << i << "] = ";
        cin >> num;

        v[i] = num;
    }
}

void operazioniArray(int v[], int limite, int& prodotto, int& somma){
    prodotto = 1;
    somma = 0;

    for(int i=0; i<limite; i++){
        if(i%2 == 0)
            prodotto*=v[i];
        else
            somma+=v[i];
    }
}
