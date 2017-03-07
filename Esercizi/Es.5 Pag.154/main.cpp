//Es. 5 Pag. 154

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int dimensioneArray(int v[]);
void caricamentoArray(int v[], int limite);
int sommaQuadratiDispari(int v[], int limite);

int main(){
    int N = 0;
    int V[N];

    N = dimensioneArray(V);
    caricamentoArray(V, N);

    cout << endl;
    cout << "Radice della somma dei quadrati di numeri in indice dispari: " << sqrt(sommaQuadratiDispari(V, N));

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

int sommaQuadratiDispari(int v[], int limite){
    int quadrati_dispari = 0;

    for(int i=0; i<limite; i++){
        if(i%2 != 0)
            quadrati_dispari+=pow(v[i], 2); //quadrati_dispari = quadrati_dispari + (numero_dispari)^2
    }

    return quadrati_dispari;
}
