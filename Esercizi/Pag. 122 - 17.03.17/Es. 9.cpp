#include <iostream>
#include <stdlib.h>

using namespace std;
void caricaVettore(int Vet[]);
void ComponiVet3(int Vet1[], int Vet2[], int Vet3[], int N);

int main(){
    int Vettore1[50];
    caricaVettore(Vettore1);

    int Vettore2[50];
    caricaVettore(Vettore2);

    int Vettore3[50];

    int N = 30;

    ComponiVet3(Vettore1, Vettore2, Vettore3, N);

    for(int i=0; i<N; i++)
        cout << Vettore3[i] << endl;

    cout << endl;
    system("PAUSE");
    return 0;
}

void caricaVettore(int Vet[]){
    int p = 3;

    for(int i = 0; i<50; i++){
        Vet[i] = p;
        p+=3;
    }
}


void ComponiVet3(int Vet1[], int Vet2[], int Vet3[], int N){
    int I = 0;
    int resto;

    while(I<=N){
        resto = I%2;

        if(resto == 0)
            Vet3[I] = Vet1[I];
        else
            Vet3[I] = Vet2[I]*3;

        I++;
    }
}
