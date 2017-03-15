//Es. 1 Pag. 154

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int i, j;
    int array[100];

    for(i=0;i<100;i++){
        array[i] = 1;
    }

    for(i=2;i<100;i++){
        if(array[i] == 1){
            for(j=2;j<(100/i)+1;j++)
                array[i*j] = 0;
        }
    }

    cout << "\n Numeri primi <100 \n";

    for(i=1;i<100;i++){
        if(array[i] == 1)
            cout <<  "\t" << i;
    }

    system("PAUSE");
    return 0;
}
