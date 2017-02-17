#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/* Scrivi un algoritmo che, sfruttando le funzioni, permetta di calcolare l'area di un cerchio o di un quadrato.
   L'utente inserisce un numero, dichiarando se si tratta del raggio di un cerchio o del lato di un quadrato.
   Se l'utente inserisce un numero negativo viene visualizzato un errore, altrimenti il sistema calcola l'area
   in modo appropriato. */

void inizializza();
bool richiestaValore();
void controlloScelta();
double areaCerchio();
double areaQuadrato();

double num;
string tipo_dato;


int main(){
    inizializza();

    if(richiestaValore()){
        controlloScelta();
    }

    return 0;
}

void inizializza(){
    double num = 0;
    string tipo_dato("");
}

bool richiestaValore(){
    bool success = true;

    cout << "Inserisci un valore numerico POSITIVO: ";
    cin >> num;

    if(num<0){
        success = !success;
        cout << endl;
        cerr << "SCELTA SBAGLIATA!\n Inserire solamente numeri positivi. \n";
    }

    cout << endl;
    cout << "Che tipo di dato indica il valore? (Scrivi la parola tra gli apici) \n";
    cout << endl;
    cout << "- Raggio di un cerchio ('raggio') \n";
    cout << "- Lato di un quadrato ('lato') \n";
    cout << endl;
    cout << "Scelta: ";
    cin >> tipo_dato;

    if(tipo_dato != "raggio" && tipo_dato != "lato"){
        success = !success;
        cout << endl;
        cerr << "SCELTA SBAGLIATA!\n Inserire solamente 'lato' o 'raggio'. \n";
    }

    return success;
}

void controlloScelta(){
    if(tipo_dato == "raggio")
        cout << endl << "L'area del cerchio e' " << areaCerchio() << ". \n";
    else
        cout << endl << "L'area del quadrato e' " << areaQuadrato() << ". \n";
}

double areaCerchio(){

}

double areaQuadrato(){

}
