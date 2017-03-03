#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){
    int scelta;
    double base, altezza, perimetro, area, diagonale;
    bool errore_inserimento = false;

    cout << "Immetti base: ";
    cin >> base;
    cout << "Immetti altezza: ";
    cin >> altezza;

    do{
        if (errore_inserimento)
            cout << endl << "INSERIRE SOLAMENTE '1', '2' o '3'!" << endl;

        cout << endl << "Digita il numero corrispondente all'elemento che vuoi calcolare." << endl;
        cout << "[1] 'AREA'" << endl;
        cout << "[2] 'PERIMETRO'" << endl;
        cout << "[3] 'DIAGONALE'" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        errore_inserimento = (scelta != 1 && scelta != 2 && scelta != 3);
    }while(errore_inserimento);

    switch (scelta){
        case 1:
            area = base*altezza;
            cout << endl << "L'area e': " << area;
            break;

        case 2:
            perimetro = base+altezza;
            cout << endl << "Il perimetro e': " << perimetro;
            break;

        case 3:
            diagonale = sqrt(base*base + altezza*altezza);
            cout << endl << "La diagonale e': " << diagonale;
            break;
    }

    cout << endl << endl;

    system("PAUSE");
    return 0;
}
