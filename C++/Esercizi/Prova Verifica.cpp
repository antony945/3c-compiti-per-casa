#include <iostream>

using namespace std;

int inverti_1(int numero){
    int c = 0;
    int d = 0;
    int u = 0;

    if(numero/100 >= 0){
        c = numero/100;
        numero = numero%100;
    }

    if(numero/10 >= 0){
        d = numero/10;
        numero = numero%10;
    }

    u = numero;

    int x;
    x = u;
    u = c;
    c = x;

    int finale = (c*100)+(d*10)+u;

    return finale;
}

void inverti_2(int& numero){
    int c = 0;
    int d = 0;
    int u = 0;

    if(numero/100 >= 0){
        c = numero/100;
        numero = numero%100;
    }

    if(numero/10 >= 0){
        d = numero/10;
        numero = numero%10;
    }

    u = numero;

    int x;
    x = u;
    u = c;
    c = x;

    numero = (c*100)+(d*10)+u;
}

int main(){
    int numero, inverso;

    cout << "Inserisci numero da 0 a 999: ";
    cin >> numero;

    inverso = inverti_1(numero);

    cout << "Numero a cifre invertite: " << inverso << endl;

    inverti_2(inverso);

    cout << "Numero originale: " << inverso << endl;

    return 0;
}


