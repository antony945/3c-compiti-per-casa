#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int N = 0, I = 0, CENT = 0, DEC = 0, UNI = 0;

    do{
        if (N<0 || N>=1000)
            cout << "IL NUMERO DEVE ESSERE POSITIVO!" << endl << endl;

        cout << "Immetti un numero positivo qualsiasi < 1000: ";
        cin >> N;
    }while(N<0 || N>=1000);

    for(; N>=100; N-=100){
        CENT++;
    }
    for(; N>=10; N-=10){
        DEC++;
    }

    cout << endl << "Le CENTINAIA sono: " << CENT;
    cout << endl << "Le DECINE sono: " << DEC;
    cout << endl << "Le UNITA' sono: " << N;
    cout << endl << endl;

    system("PAUSE");
    return 0;
}
