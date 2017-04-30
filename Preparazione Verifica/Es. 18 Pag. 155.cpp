#include <iostream>

using namespace std;

int main(){
    int dim;
    cout << "Inserisci dimensione: ";
    cin >> dim;

    int v[dim];

    for(int i=0; i<dim; i++){
        int num;
        cout << "v[" << i << "] = ";
        cin >> num;
        v[i] = num;
    }

    int maggiore = 0;
    int minore = v[1];
    int pos1 = 0;
    int pos2 = 0;

    for(int i=0; i<dim; i++){
        if((v[i]%2)!=0){
            if(v[i] > maggiore){
                maggiore = v[i];
                pos1 = i;
            }

            if(v[i] < minore){
                minore = v[i];
                pos2 = i;
            }
        }
    }


    cout << maggiore << endl;
    cout << pos1 << endl;
    cout << minore << endl;
    cout << pos2 << endl;

    return 0;
}
