//ES. 7 PAG.68

#include <iostream>
#include <math.h>

using namespace std;

void Coefficienti();
void ControlloCoefficienti();
void EquazionePrimo();
void StudioDelta();

double a, b, c, delta, x1, x2;

int main(){

    Coefficienti();

    if(a==0)
        ControlloCoefficienti();
    else
        StudioDelta();

    cout << endl << endl;
    return 0;
}

void Coefficienti(){
    bool ErroreInserimento = false;

    cout << "Eq.: ax^2 + bx + c = 0" << endl;
    do{
        if(ErroreInserimento)
            cout << endl << "I TERMINI DEVONO ESSERE >= 0!" << endl << endl;

        cout << "Inserisci il termine 'a' ( >= 0) dell'eq. di secondo grado: ";
        cin >> a;
        cout << "Inserisci il termine 'b' ( >= 0) dell'eq. di secondo grado: ";
        cin >> b;
        cout << "Inserisci il termine 'c' ( >= 0) dell'eq. di secondo grado: ";
        cin >> c;
        ErroreInserimento = (a<0 || b<0 || c<0);
    }while(ErroreInserimento);
}

void ControlloCoefficienti(){
    if(b==0){
        cout << endl << "Eq.: " << c << " = 0" << endl;

        if(c==0) //b=0 c=0
            cout << endl << "L'equazione data e' INDETERMINATA.";
        else //b=0 c>0
            cout << endl << "L'equazione data NON HA SOLUZIONI.";
    }else{
        if(c==0){ //b>0 c=0
            cout << endl << "Eq.: " << b << "x = 0" << endl;

            x1 = 0;
            cout << endl << "x1 = " << x1;
        }else{ //b>0 c>0
            EquazionePrimo();
        }
    }
}

void EquazionePrimo(){
    cout << endl << "Eq.: " << b << "x + " << c << " = 0" << endl;

    x1 = (-c)/b;
    cout << endl << "x1 = " << x1;
}

void StudioDelta(){
    cout << endl << "Eq.: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

    delta = (b*b)-(4*a*c);

    if(delta == 0){
        x1 = x2 = (-b)/(2*a);
        cout << endl << "x1 = x2 = " << x1;
    }else{
        if (delta < 0){
            cout << endl << "L'equazione data e' IMPOSSIBILE.";
        }else{
            x1 = (-b-sqrt(delta))/(2*a);
            x2 = (-b+sqrt(delta))/(2*a);
            cout << endl << "x1 = " << x1 << endl << "x2 = " << x2;
        }
    }
}
