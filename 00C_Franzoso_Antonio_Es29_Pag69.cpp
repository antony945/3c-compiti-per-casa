#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int N;

    do{
        if (N<0)
            cout << "LA QUANTITA' DEVE ESSERE POSITIVA!" << endl << endl;

        cout << "Immetti la quantita' di numeri da inserire: ";
        cin >> N;
    }while(N<0);

    cout << endl;

    int I = 1;
    double num, MIN = 0, MAX = 0, MEDIA = 0, somma;

    while(I<=N){
        cout << "Immetti il valore n." << I <<": ";
        cin >> num;

        if (I == 1)
            MIN = num;
        else
            if (num < MIN)
                MIN = num;

        if (num > MAX)
            MAX = num;

        somma+=num;
        MEDIA = somma/I;
        I++;
    }

    cout << endl << "Il numero MINORE inserito e': " << MIN;
    cout << endl << "Il numero MAGGIORE inserito e': " << MAX;
    cout << endl << "La MEDIA tra i valori inseriti e': " << MEDIA;
    cout << endl << endl;

    system("PAUSE");
    return 0;
}
