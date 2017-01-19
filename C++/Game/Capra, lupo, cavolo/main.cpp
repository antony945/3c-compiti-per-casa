#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>

using namespace std;

//*******************************************************************************************************************************
/* PROTOTIPI FUNZIONI */
/* Lista di tutte le funzioni che verranno richiamate all'interno del codice di gioco ('main'). */

void messaggioIniziale(void);
/* Stampa a video le regole del gioco. */

void messaggioFinale(void);
/* Stampa a video il messaggio che riceve l'utente dopo la fine del gioco.
   Varia a seconda del valore ritornato dalle funzioni 'controllaVittoria()' e 'controllaSconfitta()'. */

void inizializzaGioco(void);
/* Mostra il messaggio iniziale e inizializza tutte le variabili del gioco
   assegnando loro il valore desiderato prima che inizi il gioco. */

void transizioneBarca(void);
/* Stampa a video l'elemento grafico della barca che cambia sponda dopo ogni turno. */

void disegnaScenario(void);
/* Stampa a video lo scenario nel momento in cui viene richiamata
   a seconda del valore delle variabili utilizzate. */

bool interazioneUtente();
/* Permette all'utente di scegliere la mossa da compiere al fine di vincere il gioco.
   NON cambia valore delle variabili utilizzate, ma MEMORIZZA la scelta fatta.
   Restituisce false se presenti errori nella funzione. */

bool eseguiAzione();
/* CAMBIA il valore delle variabili a seconda delle scelte fatte nella funzione 'interazioneUtente'.
   Restituisce false se presenti errori nella funzione. */

bool controllaFine();
/* Controlla se, dopo aver applicato i cambiamenti imposti dall'utente alle variabili,
   il gioco è terminato. Può restituire 'TRUE' (terminato), o 'FALSE' (non terminato).
   Si compone del valore ritornato dalle funzione controllaVittoria() e controllaSconfitta(). */

bool controllaVittoria();
/* Controlla se, dopo aver applicato i cambiamenti imposti dall'utente alle variabili,
   l'utente ha VINTO il gioco. Può restituire 'TRUE' (vittoria), o 'FALSE' (non vittoria). */

bool controllaSconfitta();
/* Controlla se, dopo aver applicato i cambiamenti imposti dall'utente alle variabili,
   l'utente ha PERSO il gioco. Può restituire 'TRUE' (sconfitta), o 'FALSE' (non sconfitta). */

//*******************************************************************************************************************************
/* VARIABILI GLOBALI */
/* Lista di tutte le variabili dichiarate GLOBALMENTE che verranno usate nel codice di gioco.
   Sono coloro che potranno essere usate nel 'main' e all'interno di tutte le funzioni richiamate nel 'main'. */

bool end_game;
/* Variabile booleana che restituisce 'TRUE' se il gioco termina a causa di un cambiamento di
   scenario imposto dall'utente, altrimenti 'FALSE'. Il gioco finisce quando vittoria = TRUE o sconfitta = TRUE.
   Variabile utilizzata nel loop principale del gioco. */

bool capra_sx;
/* Variabile booleana indicante la posizione della CAPRA nello scenario.
   Assume 'TRUE' se la CAPRA è nella sponda sx, ovvero nella posizione dove il gioco richiede che sia, altrimenti 'FALSE'. */

bool lupo_sx;
/* Variabile booleana indicante la posizione del LUPO nello scenario.
   Assume 'TRUE' se il LUPO è nella sponda sx, ovvero nella posizione dove il gioco richiede che sia, altrimenti 'FALSE'. */

bool cavolo_sx;
/* Variabile booleana indicante la posizione del CAVOLO nello scenario.
   Assume 'TRUE' se il CAVOLO è nella sponda sx, ovvero nella posizione dove il gioco richiede che sia, altrimenti 'FALSE'. */

unsigned int scelta;
/* Variabile che memorizza la scelta effettuata in input dal giocatore su quale elemento far muovere da una sponda all'altra.
   (lo spostamento verrà stampato a video con l'ausilio della nuova funzione 'transizioneBarca()'
   Può assumere tre valori:
   - '1' per capra; la capra si sposterà sulla sponda opposta a seconda della sua posizione di partenza
                    (se si trova sulla sponda dx passerà sulla sponda sx, altrimenti passerà sulla sponda dx)
   - '2' per cavolo; vedi funzionamento capra
   - '3' per lupo; vedi funzionamento capra
   - '0' per barca; la barca si sposterà sulla sponda opposta senza trasportare nessuno dei
                                          personaggi sopracitati. */

unsigned int turni;
/* Variabile che memorizza il numero di mosse effettuate dall'utente durante il corso del gioco.
   Utilizzata come contatore del ciclo for in quanto se numero mosse dispari, barca a dx, altrimenti barca a sx. */

//*******************************************************************************************************************************
/* CODICE PROGRAMMA */

int main(){

    messaggioIniziale();
    inizializzaGioco();

    for(turni = 1; !end_game;){
        disegnaScenario();

        if(controllaFine()){
            end_game = controllaVittoria() || controllaSconfitta();
            continue;
        }

        if(interazioneUtente() && eseguiAzione()){
            transizioneBarca();
            turni++;
        }
    }

    messaggioFinale();

    cout << endl;
    system("PAUSE");
    return 0;
}

bool controllaFine(){ //IMPLEMENTATA
    bool controlla_fine = false;

    if(controllaVittoria() || controllaSconfitta())
        controlla_fine = true;

    return controlla_fine; // restituisce alla funzione il valore di controlla_fine
}

bool controllaVittoria(){ //IMPLEMENTATA
    bool controlla_vittoria = false;
    if (capra_sx && lupo_sx && cavolo_sx)
        controlla_vittoria = true;

    return controlla_vittoria; // restituisce alla funzione il valore di controlla_vittoria
}

bool controllaSconfitta(){ //IMPLEMENTATA
    bool controlla_sconfitta = false;
    if (capra_sx && cavolo_sx && !lupo_sx && turni%2!=0)
        controlla_sconfitta = true;
    if (capra_sx && !cavolo_sx && lupo_sx && turni%2!=0)
        controlla_sconfitta =true;
    if (!capra_sx && !cavolo_sx && lupo_sx && turni%2==0)
        controlla_sconfitta = true;
    if (!capra_sx && cavolo_sx && !lupo_sx && turni%2==0)
        controlla_sconfitta =true;

    return controlla_sconfitta; // restituisce alla funzione il valore di controlla_sconfitta
}

void messaggioIniziale(){ //IMPLEMENTATA
    cout << endl;
    cout << " ____________________ BENVENUTO AL GIOCO CAPRA-CAVOLO-LUPO ____________________" << endl;

    cout << endl;
    cout << "\t\t\t\t  SCOPO DEL GIOCO"<< endl;
    cout << "   Aiuta un contadino a portare da una parte all'altra del fiume i suoi averi:" << endl;
    cout << "                       Una capra, un cavolo e un lupo " << endl;
    cout << "            Per attraversare il fiume hai a disposizione una barca" << endl;
    cout << "    Ma la barca puo' portare solo una cosa alla volta oltre che al contadino" << endl;
    cout << endl;
    cout << "\t\t\t\t  ATTENZIONE!" << endl;
    cout << "        Se lasci da soli capra e cavolo, la capra si mangia il cavolo " << endl;
    cout << "   Allo stesso modo se lasci da soli lupo e capra il lupo si pappa la capra..." << endl;
    cout << endl;
    cout << "\t\t\t      Come fare? Buona fortuna!!!" << endl;
    cout << endl;
    cout << "________________________________________________________________________________";

    cout << "\n\n \t\t\t";
    system("PAUSE");
}

void messaggioFinale(){ //IMPLEMENTATA
    if (controllaVittoria())
        cout << "\n\n\t CONGRATULAZIONI! HAI VINTO IL GIOCO. \n\n";
    if (controllaSconfitta())
        cout << "\n\n\t MI DISPIACE! HAI PERSO IL GIOCO. \n\n";
}

void inizializzaGioco(){ //IMPLEMENTATA
    end_game = false;
    capra_sx = false;
    cavolo_sx = false;
    lupo_sx = false;
}

void disegnaScenario(){ //IMPLEMENTATA
    system("CLS");

    if (lupo_sx)                    //Personaggi a sinistra
        cout << " lup";
    else
        cout << "    ";


    if (capra_sx)
        cout << " cap";
    else
        cout << "    ";


    if (cavolo_sx)
        cout << " cav ";
    else
        cout << "     ";


    cout <<"                      ";    //Spazio tra le due sponde



    if (!lupo_sx)                       //personaggi a destra
        cout << " lup";
    else
        cout << "    ";


    if (!capra_sx)
        cout << " cap";
    else
        cout << "    ";


    if (!cavolo_sx)
        cout << " cav ";
    else
        cout << "     ";

    if (turni%2 == 0){
        cout << endl;
        cout << "-------------_(___)________________-------------" << endl;     //base caso in cui sia un turno dispari barca a sinistra
    } else {
        cout << endl;
        cout << "-------------________________(___)_-------------" << endl;     //base caso in cui sia un turno pari barca a destra
    }

}

bool interazioneUtente(){ //IMPLEMENTATA
    /* Interazone con l'utente a cui si pone una domanda a cui deve rispondere tramite tastiera quale personaggio
    (capra, cavolo, lupo e barca!) vuole muovere selezionando tra un elenco*/

    bool success = true;

    cout << endl;
    cout << "Quale personaggio vuoi muovere? \n";
    cout << "Digita il numero corrispondente alla scelta: \n" << endl;
    cout << "0) Barca \n";
    cout << "1) Capra \n";
    cout << "2) Cavolo \n";
    cout << "3) Lupo \n";
    cout << endl;
    cout << "Scelta: ";
    cin >> scelta;

    if(scelta != 0 && scelta != 1 && scelta != 2 && scelta != 3){
        cout << endl;
        cout << "IL NUMERO DIGITATO NON E' TRA QUELLI SELEZIONABII! \n";
        cout << "Digitare solamente '0', '1', '2' o '3'. \n" << endl;

        success = false;
        system("PAUSE");
    }

    return success;
}

bool eseguiAzione(){ //IMPLEMENTATA
    bool success = true;

    switch(scelta){
    case 1: //CAPRA
        if(turni%2 != 0){ //BARCA SPONDA DX
            if(!capra_sx){ //CAPRA SPONDA DX
                capra_sx = true;
            }else{ //CAPRA SPONDA SX
                cout << endl;
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a destra, mentre la capra sulla sponda opposta. Riprovare. \n" << endl;

                success = false;
                system ("PAUSE");
            }
        }else{ //BARCA SPONDA SX
            if(capra_sx){ //CAPRA SPONDA SX
                capra_sx = false;
            }else{ //CAPRA SPONDA DX
                cout << endl;
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a sinistra, mentre la capra sulla sponda opposta. Riprovare. \n" << endl;

                success = false;
                system ("PAUSE");
            }
        }

        break;

    case 2: //CAVOLO
        if(turni%2 != 0){ //BARCA SPONDA DX
            if(!cavolo_sx){ //CAVOLO SPONDA DX
                cavolo_sx = true;
            }else{ //CAVOLO SPONDA SX
                cout << endl;
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a destra, mentre il cavolo sulla sponda opposta. Riprovare. \n" << endl;

                success = false;
                system ("PAUSE");
            }
        }else{ //BARCA SPONDA SX
            if(cavolo_sx){ //CAVOLO SPONDA SX
                cavolo_sx = false;
            }else{ //CAVOLO SPONDA DX
                cout << endl;
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a sinistra, mentre il cavolo sulla sponda opposta. Riprovare. \n" << endl;

                success = false;
                system ("PAUSE");
            }
        }

        break;

    case 3: //LUPO
        if(turni%2 != 0){ //BARCA SPONDA DX
            if(!lupo_sx){ //LUPO SPONDA DX
                lupo_sx = true;
            }else{ //LUPO SPONDA SX
                cout << endl;
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a destra, mentre la capra sulla sponda opposta. Riprovare. \n" << endl;

                success = false;
                system ("PAUSE");
            }
        }else{ //BARCA SPONDA SX
            if(lupo_sx){ //LUPO SPONDA SX
                lupo_sx = false;
            }else{ //LUPO SPONDA DX
                cout << endl;
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a sinistra, mentre il lupo sulla sponda opposta. Riprovare. \n" << endl;

                success = false;
                system ("PAUSE");
            }
        }

        break;
    }

    return success;
}

void transizioneBarca(){ //IMPLEMENTATA
    string barca("(___)");

    string spazio_lupo_sx("    ");
    string spazio_capra_sx("    ");
    string spazio_cavolo_sx("     ");

    string spazio_lupo_dx("    ");
    string spazio_capra_dx("    ");
    string spazio_cavolo_dx("     ");

    switch(scelta){
    case 0: //BARCA VUOTA
        //Personaggi a sinistra
        if (lupo_sx)
            spazio_lupo_sx = " lup";

        if (capra_sx)
            spazio_capra_sx = " cap";

        if (cavolo_sx)
            spazio_cavolo_sx = " cav ";

        //Personaggi a destra
        if (!lupo_sx)
            spazio_lupo_dx = " lup";

        if (!capra_sx)
            spazio_capra_dx = " cap";

        if (!cavolo_sx)
            spazio_cavolo_dx = " cav ";

        break;

    case 1: //CAPRA
        //Personaggi a sinistra
        if (lupo_sx)
            spazio_lupo_sx = " lup";

        if (cavolo_sx)
            spazio_cavolo_sx = " cav ";

        //Personaggi a destra
        if (!lupo_sx)
            spazio_lupo_dx = " lup";

        if (!cavolo_sx)
            spazio_cavolo_dx = " cav ";

        barca = "(cap)";
        break;

    case 2: //CAVOLO
        //Personaggi a sinistra
        if (lupo_sx)
            spazio_lupo_sx = " lup";

        if (capra_sx)
            spazio_capra_sx = " cap";

        //Personaggi a destra
        if (!lupo_sx)
            spazio_lupo_dx = " lup";

        if (!capra_sx)
            spazio_capra_dx = " cap";

        barca = "(cav)";
        break;

    case 3: //LUPO
        //Personaggi a sinistra
        if (capra_sx)
            spazio_capra_sx = " cap";

        if (cavolo_sx)
            spazio_cavolo_sx = " cav ";

        //Personaggi a destra
        if (!capra_sx)
            spazio_capra_dx = " cap";

        if (!cavolo_sx)
            spazio_cavolo_dx = " cav ";

        barca = "(lup)";
        break;
    }

    if(turni%2 != 0){ //BARCA DA DESTRA A SINISTRA
        system("CLS");
        cout << spazio_lupo_sx << spazio_capra_sx << spazio_cavolo_sx; //Spazio personaggi sx
        cout << "                      "; //Spazio tra le due sponde
        cout << spazio_lupo_dx << spazio_capra_dx << spazio_cavolo_dx; //Spazio personaggi sx
        cout << endl;
        cout << "-------------________________" << barca << "_-------------" << endl;
        Sleep(300);

        system("CLS");
        cout << spazio_lupo_sx << spazio_capra_sx << spazio_cavolo_sx; //Spazio personaggi sx
        cout << "                      "; //Spazio tra le due sponde
        cout << spazio_lupo_dx << spazio_capra_dx << spazio_cavolo_dx; //Spazio personaggi sx
        cout << endl;
        cout << "-------------_________" << barca << "________-------------" << endl;
        Sleep(300);

        system("CLS");
        cout << spazio_lupo_sx << spazio_capra_sx << spazio_cavolo_sx; //Spazio personaggi sx
        cout << "                      "; //Spazio tra le due sponde
        cout << spazio_lupo_dx << spazio_capra_dx << spazio_cavolo_dx; //Spazio personaggi sx
        cout << endl;
        cout << "-------------_" << barca << "________________-------------" << endl;
        Sleep(300);
    }else{ //BARCA DA SINISTRA A DESTRA
        system("CLS");
        cout << spazio_lupo_sx << spazio_capra_sx << spazio_cavolo_sx; //Spazio personaggi sx
        cout << "                      "; //Spazio tra le due sponde
        cout << spazio_lupo_dx << spazio_capra_dx << spazio_cavolo_dx; //Spazio personaggi sx
        cout << endl;
        cout << "-------------_" << barca << "________________-------------" << endl;
        Sleep(300);

        system("CLS");
        cout << spazio_lupo_sx << spazio_capra_sx << spazio_cavolo_sx; //Spazio personaggi sx
        cout << "                      "; //Spazio tra le due sponde
        cout << spazio_lupo_dx << spazio_capra_dx << spazio_cavolo_dx; //Spazio personaggi sx
        cout << endl;
        cout << "-------------_________" << barca << "________-------------" << endl;
        Sleep(300);

        system("CLS");
        cout << spazio_lupo_sx << spazio_capra_sx << spazio_cavolo_sx; //Spazio personaggi sx
        cout << "                      "; //Spazio tra le due sponde
        cout << spazio_lupo_dx << spazio_capra_dx << spazio_cavolo_dx; //Spazio personaggi sx
        cout << endl;
        cout << "-------------________________" << barca << "_-------------" << endl;
        Sleep(300);
    }
}


