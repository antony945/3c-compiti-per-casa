#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/* PROTOTIPI FUNZIONI */

void messaggioIniziale(void);

void messaggioFinale(bool vittoria, bool sconfitta);

void inizializza(unsigned char& missionari_dx,
                 unsigned char& missionari_sx,
                 unsigned char& cannibali_dx,
                 unsigned char& cannibali_sx,
                 unsigned char& missionari_barca,
                 unsigned char& cannibali_barca,
                 unsigned char& personaggi_dx,
                 unsigned char& personaggi_sx,
                 unsigned char& lato_barca,
                 bool& vittoria,
                 bool& sconfitta,
                 bool& gioco_terminato);

void disegnaConfigurazione(unsigned char missionari_sx,
                           unsigned char cannibali_sx,
                           unsigned char personaggi_sx,
                           unsigned char missionari_dx,
                           unsigned char cannibali_dx,
                           unsigned char missionari_barca,
                           unsigned char cannibali_barca,
                           unsigned char lato_barca);

void interazioneUtente(unsigned char& scelta_player, unsigned char& scelta_azione);

void eseguiAzione(unsigned char scelta_player,
                  unsigned char scelta_azione,
                  unsigned char &missionari_barca,
                  unsigned char &cannibali_barca,
                  unsigned char &lato_barca,
                  unsigned char &missionari_dx,
                  unsigned char &missionari_sx,
                  unsigned char &cannibali_dx,
                  unsigned char &cannibali_sx);

void muoviBarca(unsigned char scelta_azione,
                unsigned char &missionari_barca,
                unsigned char &cannibali_barca,
                unsigned char &lato_barca);

void muoviMissionario(unsigned char scelta_azione,
                      unsigned char& lato_barca,
                      unsigned char& missionari_dx,
                      unsigned char& missionari_barca,
                      unsigned char& cannibali_barca,
                      unsigned char& missionari_sx);

void muoviCannibale(unsigned char scelta_azione,
                    unsigned char& lato_barca,
                    unsigned char& cannibali_dx,
                    unsigned char& missionari_barca,
                    unsigned char& cannibali_barca,
                    unsigned char& cannibali_sx);

bool controllaVittoria(unsigned char missionari_sx, unsigned char cannibali_sx);

bool controllaSconfitta(unsigned char lato_barca,
                        unsigned char missionari_sx,
                        unsigned char cannibali_sx,
                        unsigned char missionari_dx,
                        unsigned char missionari_barca,
                        unsigned char cannibali_dx,
                        unsigned char cannibali_barca);


/* VARIABILI GLOBALI */

unsigned char scelta_player;

unsigned char scelta_azione;

bool vittoria, sconfitta, gioco_terminato;

int main(){
    unsigned char missionari_dx;
    unsigned char missionari_sx;
    unsigned char cannibali_dx;
    unsigned char cannibali_sx;
    unsigned char missionari_barca;
    unsigned char cannibali_barca;
    unsigned char personaggi_dx;
    unsigned char personaggi_sx;
    unsigned char lato_barca;

    inizializza(missionari_dx, missionari_sx, cannibali_dx, cannibali_sx, missionari_barca, cannibali_barca,
                personaggi_dx, personaggi_sx, lato_barca, vittoria, sconfitta, gioco_terminato);

    messaggioIniziale();

    while(!gioco_terminato){
        disegnaConfigurazione(missionari_sx, cannibali_sx, personaggi_sx, missionari_dx,
                              cannibali_dx, missionari_barca, cannibali_barca, lato_barca);

        interazioneUtente(scelta_player, scelta_azione);

        eseguiAzione(scelta_player, scelta_azione, missionari_barca, cannibali_barca,
                     lato_barca, missionari_dx, missionari_sx, cannibali_dx, cannibali_sx);

        controllaVittoria(vittoria, sconfitta);

        controllaSconfitta(lato_barca, missionari_sx, cannibali_sx, missionari_dx,
                           missionari_barca, cannibali_dx, cannibali_barca);
    }

    messaggioFinale(vittoria, sconfitta);

    system("PAUSE");
    return 0;

}

bool controllaVittoria(unsigned char missionari_sx, unsigned char cannibali_sx){
    bool controlla_vittoria = false;

    controlla_vittoria = ((missionari_sx+cannibali_sx) == 6);

    return controlla_vittoria;
}

bool controllaSconfitta(unsigned char lato_barca,
                        unsigned char missionari_sx,
                        unsigned char cannibali_sx,
                        unsigned char missionari_dx,
                        unsigned char missionari_barca,
                        unsigned char cannibali_dx,
                        unsigned char cannibali_barca){
    bool controlla_sconfitta = false;

    if (lato_barca == 'd'){ //LATO BARCA DESTRA
        if (missionari_dx == 0) //MISSIONARI DX = 0
            controlla_sconfitta = (missionari_sx < cannibali_sx);
        else{ //MISSIONARI DX != 0
            if (missionari_sx == 0) //MISSIONARI SX = 0
               controlla_sconfitta = ((missionari_dx+missionari_barca) < (cannibali_dx+cannibali_barca));
            else //MISSIONARI SX != 0
                controlla_sconfitta = (((missionari_dx+missionari_barca) < (cannibali_dx+cannibali_barca)) || (missionari_sx < cannibali_sx));
        }
    }else{ //LATO BARCA SINISTRA
        if (missionari_sx == 0) //MISSIONARI SX = 0
            controlla_sconfitta = (missionari_dx < cannibali_dx);
        else{ //MISSIONARI SX != 0
            if (missionari_dx == 0) //MISSIONARI DX = 0
                controlla_sconfitta = ((missionari_sx+missionari_barca) < (cannibali_sx+cannibali_barca));
            else //MISSIONARI DX != 0
                controlla_sconfitta = ((missionari_dx < cannibali_dx) || ((missionari_sx+missionari_barca) < (cannibali_sx+cannibali_barca)));
        }
    }

    return controlla_sconfitta;
}

void messaggioIniziale(){
    cout << "---------------------------| MISSIONARI e CANNIBALI |--------------------------- \n";
    cout << "SCOPO DEL GIOCO: \n";
    cout << "Porta TUTTI i missionari e i cannibali dall'altra sponda. \n\n";
    cout << "REGOLE: \n";
    cout << "1. Se i missionari sono MENO dei cannibali in una sponda, vengono mangiati. \n";
    cout << "2. La barca puo' traghettare AL PIU' DUE personaggi. \n";
    cout << "3. La barca si muove SOLAMENTE con ALMENO UN personaggio al suo interno. \n";
    cout << "\nIn bocca al lupo! \n\n";
    system("PAUSE");
}

void messaggioFinale(bool vittoria, bool sconfitta){
    if (vittoria)
        cout << "\n\n\t\t\t CONGRATULAZIONI! HAI VINTO IL GIOCO.\n\n";
    if (sconfitta)
        cout << "\n\n\t\t\t MI DISPIACE! HAI PERSO IL GIOCO.\n\n";
}

void inizializza(unsigned char& missionari_dx,
                 unsigned char& missionari_sx,
                 unsigned char& cannibali_dx,
                 unsigned char& cannibali_sx,
                 unsigned char& missionari_barca,
                 unsigned char& cannibali_barca,
                 unsigned char& personaggi_dx,
                 unsigned char& personaggi_sx,
                 unsigned char& lato_barca,
                 bool& vittoria,
                 bool& sconfitta,
                 bool& gioco_terminato){
    missionari_dx = 3;
    missionari_sx = 0;
    cannibali_dx = 3;
    cannibali_sx = 0;
    missionari_barca = 0;
    cannibali_barca = 0;
    personaggi_dx = missionari_dx + cannibali_dx;
    personaggi_sx = missionari_sx + cannibali_sx;
    lato_barca = 'd';

    vittoria = controllaVittoria(missionari_sx, cannibali_sx);

    sconfitta = controllaSconfitta(lato_barca, missionari_sx, cannibali_sx, missionari_dx,
                                   missionari_barca, cannibali_dx, cannibali_barca);

    gioco_terminato = (vittoria || sconfitta);
}

void disegnaConfigurazione(unsigned char missionari_sx,
                           unsigned char cannibali_sx,
                           unsigned char personaggi_sx,
                           unsigned char missionari_dx,
                           unsigned char cannibali_dx,
                           unsigned char missionari_barca,
                           unsigned char cannibali_barca,
                           unsigned char lato_barca){
	system("CLS");
	cout << "---------------------------| MISSIONARI e CANNIBALI |--------------------------- \n\n";

    cout << "\t\t ";
    for (int i = 1; i <= missionari_sx; i++){
        cout << "M";
        cout << " ";
    }
    for (int i = 1; i <= cannibali_sx; i++){
        cout << "C";
        cout << " ";
    }

    if (personaggi_sx)
        cout << "\t\t\t\t\t\t    ";
    else
        cout << "\t\t\t   ";

    cout << "\t    ";

    for (int i = 1; i <= missionari_dx; i++){
        cout << "M";
        cout << " ";
    }
    for (int i = 1; i <= cannibali_dx; i++){
        cout << "C";
        cout << " ";
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

void interazioneUtente(unsigned char& scelta_player, unsigned char& scelta_azione){
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

void eseguiAzione(unsigned char scelta_player,
                  unsigned char scelta_azione,
                  unsigned char& missionari_barca,
                  unsigned char& cannibali_barca,
                  unsigned char& lato_barca,
                  unsigned char& missionari_dx,
                  unsigned char& missionari_sx,
                  unsigned char& cannibali_dx,
                  unsigned char& cannibali_sx){
    switch (scelta_player){
        case('B'):
            muoviBarca(scelta_azione, missionari_barca, cannibali_barca, lato_barca);
            break;

        case('M'):
            muoviMissionario(scelta_azione, lato_barca, missionari_dx, missionari_barca, cannibali_barca, missionari_sx);
            break;

        case('C'):
            muoviCannibale(scelta_azione, lato_barca, cannibali_dx, missionari_barca, cannibali_barca, cannibali_sx);
            break;
    }
}

void muoviBarca(unsigned char scelta_azione,
                unsigned char& missionari_barca,
                unsigned char& cannibali_barca,
                unsigned char& lato_barca){
    if (scelta_azione == 'G'){
        if (missionari_barca == 0 && cannibali_barca == 0){
            cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
            cout << "La barca puo' partire SOLAMENTE con almeno UN personaggio all'interno. \n";
            cout << endl << "-------------------------------------------------------------------------------- \n";
            system("PAUSE");
        }else{
            if (lato_barca == 'd')
                lato_barca = 's';
            else if (lato_barca == 's')
                lato_barca = 'd';
        }
    }
}

void muoviMissionario(unsigned char scelta_azione,
                      unsigned char& lato_barca,
                      unsigned char& missionari_dx,
                      unsigned char& missionari_barca,
                      unsigned char& cannibali_barca,
                      unsigned char& missionari_sx){
    if (scelta_azione == 'U'){ //SALI SULLA BARCA
        if (lato_barca == 'd'){ //LATO BARCA = DESTRA
            if (missionari_dx != 0){
                if ((missionari_barca+cannibali_barca) < 2){
                    missionari_dx--;
                    missionari_barca++;
                }else{
                    cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                    cout << "NON c'e' piu' posto sulla barca per far salire un altro MISSIONARIO. \n";
                    cout << endl << "-------------------------------------------------------------------------------- \n";
                    system("PAUSE");
                }
            }else{
                cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "Non c'e' NESSUN missionario sulla riva dx da far SALIRE sulla barca. \n";
                cout << endl << "-------------------------------------------------------------------------------- \n";
                system("PAUSE");
            }
        }else{ //LATO BARCA = SINISTRA
            if (missionari_sx != 0){
                if ((missionari_barca+cannibali_barca) < 2){
                    missionari_sx--;
                    missionari_barca++;
                }else{
                    cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                    cout << "NON c'e' piu' posto sulla barca per far salire un altro MISSIONARIO. \n";
                    cout << endl << "-------------------------------------------------------------------------------- \n";
                    system("PAUSE");
                }
            }else{
                cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "Non c'e' NESSUN missionario sulla riva sx da far SALIRE sulla barca. \n";
                cout << endl << "-------------------------------------------------------------------------------- \n";
                system("PAUSE");
            }
        }
    }

    if (scelta_azione == 'D'){ //SCENDI DALLA BARCA
        if (lato_barca == 'd'){ //LATO BARCA = DESTRA
            if (missionari_barca != 0){
                missionari_barca--;
                missionari_dx++;
            }else{
                cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "Non c'e' NESSUN missionario sulla barca da far SCENDERE sulla riva dx. \n";
                cout << endl << "-------------------------------------------------------------------------------- \n";
                system("PAUSE");
            }
        }else{ //LATO BARCA = SINISTRA
            if (missionari_barca != 0){
                missionari_barca--;
                missionari_sx++;
            }else{
                cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "Non c'e' NESSUN missionario sulla barca da far SCENDERE sulla riva sx. \n";
                cout << endl << "-------------------------------------------------------------------------------- \n";
                system("PAUSE");
            }
        }
    }
}

void muoviCannibale(unsigned char scelta_azione,
                    unsigned char& lato_barca,
                    unsigned char& cannibali_dx,
                    unsigned char& missionari_barca,
                    unsigned char& cannibali_barca,
                    unsigned char& cannibali_sx){
    if (scelta_azione == 'U'){ //SALI SULLA BARCA
        if (lato_barca == 'd'){ //LATO BARCA = DESTRA
            if (cannibali_dx != 0){
                if ((missionari_barca+cannibali_barca) < 2){
                    cannibali_dx--;
                    cannibali_barca++;
                }else{
                    cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                    cout << "NON c'e' piu' posto sulla barca per far salire un altro CANNIBALE. \n";
                    cout << endl << "-------------------------------------------------------------------------------- \n";
                    system("PAUSE");
                }
            }else{
                cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "Non c'e' NESSUN cannibale sulla riva dx da far SALIRE sulla barca. \n";
                cout << endl << "-------------------------------------------------------------------------------- \n";
                system("PAUSE");
            }
        }else{ //LATO BARCA = SINISTRA
            if (cannibali_sx != 0){
                if ((missionari_barca+cannibali_barca) < 2){
                    cannibali_sx--;
                    cannibali_barca++;
                }else{
                    cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                    cout << "NON c'e' piu' posto sulla barca per far salire un altro CANNIBALE. \n";
                    cout << endl << "-------------------------------------------------------------------------------- \n";
                    system("PAUSE");
                }
            }else{
                cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "Non c'e' NESSUN cannibale sulla riva sx da far SALIRE sulla barca. \n";
                cout << endl << "-------------------------------------------------------------------------------- \n";
                system("PAUSE");
            }
        }
    }

    if (scelta_azione == 'D'){ //SCENDI DALLA BARCA
        if (lato_barca == 'd'){ //LATO BARCA = DESTRA
            if (cannibali_barca != 0){
                cannibali_barca--;
                cannibali_dx++;
            }else{
                cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "Non c'e' NESSUN cannibale sulla barca da far SCENDERE sulla riva dx. \n";
                cout << endl << "-------------------------------------------------------------------------------- \n";
                system("PAUSE");
            }
        }else{ //LATO BARCA = SINISTRA
            if (cannibali_barca != 0){
                cannibali_barca--;
                cannibali_sx++;
            }else{
                cout << endl << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "Non c'e' NESSUN cannibale sulla barca da far SCENDERE sulla riva sx. \n";
                cout << endl << "-------------------------------------------------------------------------------- \n";
                system("PAUSE");
            }
        }
    }
}
