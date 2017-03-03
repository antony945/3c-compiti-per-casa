#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int X, num; //numeri
    int N; //numero di ripetizioni del ciclo
    int i = 1, i_MAX = 0, i_MIN = 0, i_UGUALE = 0;

    do{
        if (X<0)
            cout << "I NUMERI DEVONO ESSERE POSITIVI!" << endl << endl;

        cout << "Immetti un numero POSITIVO qualsiasi: ";
        cin >> X;
    }while(X<0);

    do{
        if (N<0)
            cout << "I NUMERI DEVONO ESSERE POSITIVI!" << endl << endl;

        cout << "Immetti la quantita' di numeri da confrontare con " << X << ": ";
        cin >> N;
    }while(N<0);

    cout << endl;

    while(i<=N){
        do{
            if (num<0)
            cout << "I NUMERI DEVONO ESSERE POSITIVI!" << endl << endl;

            cout << "Immetti il valore n." << i <<": ";
            cin >> num;
        }while(num<0);

        if (num < X)
            i_MIN++;
        else
            if (num == X)
                i_UGUALE++;
            else
                if (num > X)
                    i_MAX++;

        i++;
    }

    cout << endl << "I numeri MINORI di " << X << " sono: " << i_MIN;
    cout << endl << "I numeri UGUALI ad " << X << " sono: " << i_UGUALE;
    cout << endl << "I numeri MAGGIORI di " << X << " sono: " << i_MAX;
    cout << endl << endl;

    system("PAUSE");
    return 0;
}
