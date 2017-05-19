#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    int ris, X, Y, N = (rand()%49)+2;

    cout << "Inserisci X positivo: ";
    cin >> X;
    cout << "Inserisci Y positivo: ";
    cin >> Y;

    cout << "N = " << N << endl;
    ris = X+N*Y;

    cout << endl << "X+N*Y = " << ris;
    cout << endl;

    system("PAUSE");
    return 0;
}
