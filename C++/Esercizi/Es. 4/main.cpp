/*  ES. 4, PAG. 108 */

#include <iostream>
#include <stdlib.h>

using namespace std;

void chiediValore(int);

int main(){
    int valore;

    chiediValore(valore);
    //stampaAsterischi();

    return 0;
}

void chiediValore(int a){
    bool errore = false;
    do{
        if(errore){
            cout << "ERRORE!";
        }
        cout << "Inserisci un valore minore o uguale di 10: ";
        cin >> a;
        errore = (a>10);
    }while(errore);
}
