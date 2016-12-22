#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main (){
    unsigned int n, d_min;
    bool primo = true;

    cout << "Immetti un numero POSITIVO qualsiasi: ";
    cin >> n;
    unsigned int limite_max = (int)sqrt(n);

    for (d_min = 2; d_min <= limite_max && primo; d_min++)
        primo = (n%d_min != 0);

    cout << endl;

    if (!primo)
        cout << "Il numero " << n << " NON e' un numero PRIMO.";
    else
        cout << "Il numero " << n << " e' un numero PRIMO.";

    cout << endl << endl;

    system("PAUSE");
    return 0;
}
