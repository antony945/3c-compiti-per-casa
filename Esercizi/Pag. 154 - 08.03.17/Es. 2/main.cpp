//Es. 2 Pag. 154

#include <iostream>
#include <stdlib.h>
#define MAX 10

using namespace std;

int main(){
    int arrayNumeri[MAX], dato, max;
    unsigned int i, num = 0, posizMax;

    arrayNumeri[0] = 0;

    cout << "Inserire i valori (0 per terminare): \n";
    cin >> dato;

    while((dato != 0) && (num < MAX)){
        arrayNumeri[num] = dato;
        num++;
        if(num < MAX){
            cin >> dato;
        }
    }

    max = arrayNumeri[0];
    posizMax = 0;
    for(i=1; i<num; i++){
        if(arrayNumeri[i] > max){
            max = arrayNumeri[i];
            posizMax = i;
        }
    }

    cout << "\nMax: " << max << ", posizione: " << posizMax << endl;

    cout << endl;
    system("PAUSE");
    return 0;
}

