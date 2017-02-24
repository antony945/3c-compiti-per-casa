#include <iostream>

using namespace std;

void Indovina(int);

int main(){
    int X, Y, K;

    X = 2;
    Y = 4;
    K = 2;

    cout << "X GLOBALE: " << X << endl;
    cout << "Y GLOBALE: " << Y << endl;
    cout << "K GLOBALE: " << K << endl;

    Indovina(K);

    cout << "X GLOBALE: " << X << endl;

    return 0;
}

void Indovina(int W){
    int X, I;

    X = 80;

    for(I=1; I<W; I++){
        X+=10;
        cout << "X LOCALE: " << X << endl;
    }
}
