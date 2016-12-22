#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/* FUNZIONI */

void inizializza();
void interazioneUtente();
void disegnaConfigurazione();
void eseguiAzione();
void messaggioFinale();

/* VARIABILI GLOBALI */

unsigned char missionari_dx, missionari_sx;
unsigned char cannibali_dx, cannibali_sx;
unsigned char missionari_barca, cannibali_barca;
unsigned char personaggi_dx, personaggi_sx;
unsigned char personaggi_barca;
unsigned char lato_barca;
unsigned char scelta_player, scelta_azione;
bool gioco_terminato;
bool vittoria, sconfitta;

int main(){

    inizializza();

    while(!gioco_terminato){
        disegnaConfigurazione();
        interazioneUtente();
        eseguiAzione();
    }

    messaggioFinale();

    system("PAUSE");
    return 0;

}

void inizializza(void){
    gioco_terminato = false;
    vittoria, sconfitta = false;

    missionari_dx = 3;
    missionari_sx = 0;
    cannibali_dx = 3;
    cannibali_sx = 0;
    missionari_barca = 0;
    cannibali_barca = 0;
    personaggi_dx = missionari_dx + cannibali_dx;
    personaggi_sx = missionari_sx + cannibali_sx;
    personaggi_barca = missionari_barca + cannibali_barca;
    lato_barca = 'd';
}

void disegnaConfigurazione(void){
	system("CLS");
	cout << "---------------------------| MISSIONARI e CANNIBALI |--------------------------- \n\n";

    cout << "\t\t ";

    int i = 1;
    while(i <= missionari_sx){
        cout << "M";
        cout << " ";
        i++;
    }

    i = 1;
    while(i <= cannibali_sx){
        cout << "C";
        cout << " ";
        i++;
    }

    if (personaggi_sx)
        cout << "\t\t\t\t\t\t    ";
    else
        cout << "\t\t\t   ";

    cout << "\t    ";

    i = 1;
    while(i <= missionari_dx){
        cout << "M";
        cout << " ";
        i++;
    }

    i = 1;
    while(i <= cannibali_dx){
        cout << "C";
        cout << " ";
        i++;
    }

    cout << "\n";

    char posto_sx = '_', posto_dx = '_';

    switch(missionari_barca){ //ASSEGNAZIONE POSTI BARCA
            case(1):
                posto_sx = 'M';

                switch(cannibali_barca){
                    case(1):
                        posto_dx = 'C';
                        break;
                }

                break;

            case(2):
                posto_sx = 'M', posto_dx = 'M';
                break;

            default:
                switch(cannibali_barca){
                    case(1):
                        posto_dx = 'C';
                        break;

                    case(2):
                        posto_sx = 'C', posto_dx = 'C';
                        break;
                }
        }

    if(lato_barca == 'd'){ //DISEGNO LATO BARCA
        cout << "\t\t-------------|                 |> |------------- \n";
        cout << "\t\t             |_______________(" << posto_sx << "|" << posto_dx << ")|\n";

    }else{
        cout << "\t\t-------------|  |>                |------------- \n";
        cout << "\t\t             |(" << posto_sx << "|" << posto_dx << ")_______________|\n";
    }

}

void interazioneUtente(void){
    bool errore_inserimento = false;

    do{
        if(errore_inserimento){
            cout << endl << "VALORE NON ACCETTABILE! \n";
            cout << "Inserire SOLAMENTE 'B' o 'M' o 'C'. \n";
        }

        cout << endl << "--------------------------------------------------------------------------------";
        cout << endl << "Digita il carattere corrispondente al tipo di elemento che vuoi muovere: \n";
        cout << endl;
        cout << "- [B] 'Barca' \n";
        cout << "- [M] 'Missionario' \n";
        cout << "- [C] 'Cannibale' \n";
        cout << endl << "Scelta: ";
        cin >> scelta_player;

        errore_inserimento = (scelta_player != 'B' && scelta_player != 'M' && scelta_player != 'C');

    }while(errore_inserimento);

    cout << endl << "--------------------------------------------------------------------------------";
    cout << endl << "Hai scelto: ";

    switch(scelta_player){
    case('B'):
        errore_inserimento = false;

        cout << "BARCA \n";

        do{
            if(errore_inserimento){
                cout << endl << "VALORE NON ACCETTABILE! \n";
                cout << "Inserire SOLAMENTE 'G' o 'S'. \n";
                cout << endl << "--------------------------------------------------------------------------------";
            }

            cout << endl << "Digita il carattere corrispondente al tipo di azione che vuoi compiere: \n";
            cout << endl;
            cout << "- [G] 'Fai partire la barca verso la riva opposta' \n";
            cout << "- [S] \\Torna alla schermata di selezione personaggio \n";
            cout << endl << "Scelta: ";
            cin >> scelta_azione;

            errore_inserimento = (scelta_azione != 'G' && scelta_azione != 'S');

        }while(errore_inserimento);

        break;

    case('M'):
        errore_inserimento = false;

        cout << "MISSIONARIO \n";

        do{
            if(errore_inserimento){
                cout << endl << "VALORE NON ACCETTABILE! \n";
                cout << "Inserire SOLAMENTE 'U' o 'D' o 'S'. \n";
                cout << endl << "--------------------------------------------------------------------------------";
            }

            cout << endl << "Digita il carattere corrispondente al tipo di azione che vuoi compiere: \n";
            cout << endl;
            cout << "- [U] 'Sali sulla barca' \n";
            cout << "- [D] 'Scendi dalla barca' \n";
            cout << "- [S] \\Torna alla schermata di selezione personaggio \n";
            cout << endl << "Scelta: ";
            cin >> scelta_azione;

            errore_inserimento = (scelta_azione != 'U' && scelta_azione != 'D' && scelta_azione != 'S');

        }while(errore_inserimento);

        break;

    case('C'):
        errore_inserimento = false;

        cout << "CANNIBALE \n";

        do{
            if(errore_inserimento){
                cout << endl << "VALORE NON ACCETTABILE! \n";
                cout << "Inserire SOLAMENTE 'U' o 'D' o 'S'. \n";
                cout << endl << "--------------------------------------------------------------------------------";
            }

            cout << endl << "Digita il carattere corrispondente al tipo di azione che vuoi compiere: \n";
            cout << endl;
            cout << "- [U] 'Sali sulla barca' \n";
            cout << "- [D] 'Scendi dalla barca' \n";
            cout << "- [S] \\Torna alla schermata di selezione personaggio \n";
            cout << endl << "Scelta: ";
            cin >> scelta_azione;

            errore_inserimento = (scelta_azione != 'U' && scelta_azione != 'D' && scelta_azione != 'S');

        }while(errore_inserimento);

        break;
    }
}

void eseguiAzione(void){
    switch (scelta_player){
        case('B'):
            if (scelta_azione == 'G'){
                    if (lato_barca == 'd')
                        lato_barca = 's';
                    else if (lato_barca == 's')
                        lato_barca = 'd';
                }/* else{
                cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca puo' partire SOLAMENTE con almeno UN personaggio all'interno. \n";
                cout << endl;
                system("PAUSE");
                } */
            break;

        case('M'):
            if (scelta_azione == 'U'){ //SALI SULLA BARCA
                if (lato_barca == 'd'){ //LATO BARCA = DESTRA
                    switch (missionari_dx){
                        /* case(0):
                            cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                            cout << "Non c'e' NESSUN missionario sulla riva dx da far SALIRE sulla barca. \n";
                            cout << endl;
                            system("PAUSE");
                            break; */

                        default:
                            missionari_dx--;
                            missionari_barca++;
                            break;
                    }
                }else{ //LATO BARCA = SINISTRA
                    switch (missionari_sx){
                        /* case(0):
                            cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                            cout << "Non c'e' NESSUN missionario sulla riva sx da far SALIRE sulla barca. \n";
                            cout << endl;
                            system("PAUSE");
                            break; */

                        default:
                            missionari_sx--;
                            missionari_barca++;
                            break;
                    }
                }
            }

            if (scelta_azione == 'D'){ //SCENDI DALLA BARCA
                if (lato_barca == 'd'){ //LATO BARCA = DESTRA
                    switch (missionari_barca){
                        /* case(0):
                            cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                            cout << "Non c'e' NESSUN missionario sulla barca da far SCENDERE sulla riva dx. \n";
                            cout << endl;
                            system("PAUSE");
                            break; */
                        default:
                            missionari_barca--;
                            missionari_dx++;
                            break;
                    }
                }else{ //LATO BARCA = SINISTRA
                    switch (missionari_barca){
                        /* case(0):
                            cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                            cout << "Non c'e' NESSUN missionario sulla barca da far SCENDERE sulla riva sx. \n";
                            cout << endl;
                            system("PAUSE");
                            break; */

                        default:
                            missionari_barca--;
                            missionari_sx++;
                            break;
                    }
                }
            }
            break;

        case('C'):
            if (scelta_azione == 'U'){ //SALI SULLA BARCA
                if (lato_barca == 'd'){ //LATO BARCA = DESTRA
                    switch (cannibali_dx){
                        /* case(0):
                            cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                            cout << "Non c'e' NESSUN cannibale sulla riva dx da far SALIRE sulla barca. \n";
                            cout << endl;
                            system("PAUSE");
                            break; */

                        default:
                            cannibali_dx--;
                            cannibali_barca++;
                            break;
                    }
                }else{ //LATO BARCA = SINISTRA
                    switch (cannibali_sx){
                        /* case(0):
                            cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                            cout << "Non c'e' NESSUN cannibale sulla riva sx da far SALIRE sulla barca. \n";
                            cout << endl;
                            system("PAUSE");
                            break; */

                        default:
                            cannibali_sx--;
                            cannibali_barca++;
                            break;
                    }
                }
            }

            if (scelta_azione == 'D'){ //SCENDI DALLA BARCA
                if (lato_barca == 'd'){ //LATO BARCA = DESTRA
                    switch (cannibali_barca){
                        /* case(0):
                            cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                            cout << "Non c'e' NESSUN cannibale sulla barca da far SCENDERE sulla riva dx. \n";
                            cout << endl;
                            system("PAUSE");
                            break; */

                        default:
                            cannibali_barca--;
                            cannibali_dx++;
                            break;
                    }
                }else{ //LATO BARCA = SINISTRA
                    switch (cannibali_barca){
                        /* case(0):
                            cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                            cout << "Non c'e' NESSUN cannibale sulla barca da far SCENDERE sulla riva dx. \n";
                            cout << endl;
                            system("PAUSE");
                            break; */

                        default:
                            cannibali_barca--;
                            cannibali_sx++;
                            break;
                    }
                }
            }
            break;
    }
}

void messaggioFinale(void){

}

