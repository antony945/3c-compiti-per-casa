//Es. 3 Pag. 154

#include <iostream>
#include <stdlib.h>

using namespace std;

int dimensioneArray(int v[]);
void caricamentoArray(int v[], int limite);
void stampaInversa(int v[], int limite);


int main(){
    int N = 0;
    int V[N];

    N = dimensioneArray(V);
    caricamentoArray(V, N);
    stampaInversa(V, N);

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

void stampaInversa(int v[], int limite){
    cout << "\nSTAMPA INVERSA";

    for(int i=limite-1; i>=0; i--){
        cout << "\n- [" << i << "] = " << v[i];
    }

    cout << endl;
}
