#include <iostream>
#include <stdlib.h>

using namespace std;

int main (){
    int N = 0, divisore;

    cout << "Immetti un numero positivo qualsiasi: ";
    cin >> N;
    cout << endl;

    divisore=N-1;

    if (N != 1){
        while(N % divisore != 0){
            divisore-=1;
        }
        if (divisore != 1)
            cout << "Il numero " << N << " NON e' un numero PRIMO.";
        else
            cout << "Il numero " << N << " e' un numero PRIMO.";
    }else{
        cout << "Il numero " << N << " e' un numero PRIMO.";
    }

    cout << endl << endl;

    system("PAUSE");
    return 0;
}
