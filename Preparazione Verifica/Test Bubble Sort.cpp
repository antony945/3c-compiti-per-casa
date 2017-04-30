#include <iostream>

using namespace std;

int main(){
    int dim = 6;
    int v[dim] = {5, 8, 1, 1, 48, 3};

    int k = dim;

    bool swap = false;

    do{
        int sup = k;

        for(int i=0; i<sup-1; i++){
            if(v[i] > v[i+1]){
                int comodo = v[+1];
                v[i+1] = v[i];
                v[i] = comodo;
                swap = true;
                k = i+1;
            }
        }
    }while(swap);


    for(int i=0; i<dim; i++)
        cout << v[i] << endl;


    return 0;
}
