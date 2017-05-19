//Es.25 Pag.69, Franzoso Antonio, 3C

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
    int NUMcitta;
    string NOMEcitta, MAXfredda, MAXcalda;
    float tMAX, tMIN, tCALDA, tFREDDA;

    cout << "Immetti quantita' citta' di cui vuoi inserire le temperature: ";
    cin >> NUMcitta;

    for(int I=0; I<NUMcitta; I++){
        cout << endl << "Nome citta' n. " << ++I << ": ";
        cin >> NOMEcitta;
        cout << endl << "Temperatura Min: ";
        cin >> tMIN;
        cout << endl << "Temperatura Max: ";
        cin >> tMAX;

        if(I==0){
            tFREDDA = tMIN;
            tCALDA = tMAX;
        }else{
            if (tMIN < tFREDDA){
                tFREDDA = tMIN;
                MAXfredda = NOMEcitta;
            }

            if (tMAX > tCALDA){
                tCALDA = tMAX;
                MAXcalda = NOMEcitta;
            }
        }
    }

    cout << endl << "La citta con la temperatura piu' fredda e' " << MAXfredda;
    cout << endl << "La citta con la temperatura piu' calda e' " << MAXcalda;
    cout << endl;
    system("PAUSE");
    return 0;
}
