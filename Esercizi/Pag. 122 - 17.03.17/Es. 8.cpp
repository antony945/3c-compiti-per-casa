#include <iostream>
#include <stdlib.h>

using namespace std;

void Sorpresa(char Lettere[]){
    for(int I=2; I<=8; I+=2)
        cout << Lettere[I];
}

int main(){
    char Lettere[10] = {'S', 'C', 'T', 'I', 'O', 'A', 'N', 'O', 'X', 'H'};
    Sorpresa(Lettere);

    cout << endl;
    system("PAUSE");
    return 0;
}
