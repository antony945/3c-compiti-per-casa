#include <iostream>
#include <stdlib.h>

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

void interazioneUtente(void);
/* Permette all'utente di scegliere la mossa da compiere al fine di vincere il gioco.
   NON cambia valore delle variabili utilizzate, ma MEMORIZZA la scelta fatta. */

void eseguiAzione(void);
/* CAMBIA il valore delle variabili a seconda delle scelte fatte nella funzione 'interazioneUtente'. */

bool controllaFine();
/* Controlla se, dopo aver applicato i cambiamenti imposti dall'utente alle variabili,
   il gioco � terminato. Pu� restituire 'TRUE' (terminato), o 'FALSE' (non terminato).
   Si compone del valore ritornato dalle funzione controllaVittoria() e controllaSconfitta(). */

bool controllaVittoria();
/* Controlla se, dopo aver applicato i cambiamenti imposti dall'utente alle variabili,
   l'utente ha VINTO il gioco. Pu� restituire 'TRUE' (vittoria), o 'FALSE' (non vittoria). */

bool controllaSconfitta();
/* Controlla se, dopo aver applicato i cambiamenti imposti dall'utente alle variabili,
   l'utente ha PERSO il gioco. Pu� restituire 'TRUE' (sconfitta), o 'FALSE' (non sconfitta). */

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
   Assume 'TRUE' se la CAPRA � nella sponda sx, ovvero nella posizione dove il gioco richiede che sia, altrimenti 'FALSE'. */

bool lupo_sx;
/* Variabile booleana indicante la posizione del LUPO nello scenario.
   Assume 'TRUE' se il LUPO � nella sponda sx, ovvero nella posizione dove il gioco richiede che sia, altrimenti 'FALSE'. */

bool cavolo_sx;
/* Variabile booleana indicante la posizione del CAVOLO nello scenario.
   Assume 'TRUE' se il CAVOLO � nella sponda sx, ovvero nella posizione dove il gioco richiede che sia, altrimenti 'FALSE'. */

unsigned char scelta;
/* Variabile che memorizza la scelta effettuata in input dal giocatore su quale elemento far muovere da una sponda all'altra.
   (lo spostamento verr� stampato a video con l'ausilio della nuova funzione 'transizioneBarca()'
   Pu� assumere tre valori:
   - '1' per capra; la capra si sposter� sulla sponda opposta a seconda della sua posizione di partenza
                    (se si trova sulla sponda dx passer� sulla sponda sx, altrimenti passer� sulla sponda dx)
   - '2' per cavolo; vedi funzionamento capra
   - '3' per lupo; vedi funzionamento capra
   - Qualsiasi altro carattere per barca; la barca si sposter� sulla sponda opposta senza trasportare nessuno dei
                                          personaggi sopracitati. */

unsigned int mosse;
/* Variabile che memorizza il numero di mosse effettuate dall'utente durante il corso del gioco.
   Utilizzata come contatore del ciclo for in quanto se numero mosse dispari, barca a dx, altrimenti barca a sx. */

//*******************************************************************************************************************************
/* CODICE PROGRAMMA */

int main(){

    messaggioIniziale();
    inizializzaGioco();

    for(mosse = 1; !end_game;){
        disegnaScenario();

        if(controllaFine()){
            end_game = controllaVittoria() || controllaSconfitta();
            continue;
        }

        interazioneUtente();
        eseguiAzione();
        transizioneBarca();
    }

    messaggioFinale();

    cout << endl;
    system("PAUSE");
    return 0;
}

void messaggioIniziale(){ //IMPLEMENTATA
    cout << " ____________________ BENVENUTO AL GIOCO CAPRA-CAVOLO-LUPO ____________________" << endl;

    cout << endl;
    cout << "\t\t\t\t  SCOPO DEL GIOCO"<< endl;
    cout << "   Aiuta un contadino a portare da una parte all'altra del fiume i suoi averi:" << endl;
    cout << "                       Una capra, un cavolo e un lupo " << endl;
    cout << "            Per attraversare il fiume hai a disposizione una barca" << endl;
    cout << "    Ma la barca puo' portare solo una cosa alla volta oltre che al contadino" << endl;
    cout << endl;

    cout << "\t\t\t\t    ATTENZIONE!" << endl;
    cout << "        - Se lasci da soli capra e cavolo, la capra si mangia il cavolo " << endl;
    cout << "     - Analogamenete se lasci da soli lupo e capra il lupo si pappa la capra..." << endl;
    cout << "\t\t\t      Come fare? Buona fortuna!!!" << endl;
    cout << endl;
    cout << "________________________________________________________________________________";

    cout << "\n\n \t\t\t";
    system("PAUSE");
}

void messaggioFinale(){ //IMPLEMENTATA
    /* Se l'utente vince il gioco, stampa messaggio di vittoria del gioco. Se perde, stampa messaggio di sconfitta. */
    if (controllaVittoria())
        cout << "\n\n\t\t\t CONGRATULAZIONI! HAI VINTO IL GIOCO.\n\n";
    if (controllaSconfitta())
        cout << "\n\n\t\t\t MI DISPIACE! HAI PERSO IL GIOCO.\n\n";
}

void inizializzaGioco(){ //IMPLEMENTATA
    end_game = false;
    capra_sx = false;
    cavolo_sx = false;
    lupo_sx = false;
}

void transizioneBarca(){
}

void disegnaScenario(){ //IMPLEMENTATA
    system("CLS");

    if (lupo_sx)
        cout << " lup";
    else
        cout << "    ";


    if (capra_sx)                   //Personaggi a sinistra
        cout << " cap";
    else
        cout << "    ";


    if (cavolo_sx)
        cout << " cav ";
    else
        cout << "     ";


    cout <<"                      " << endl;    //Spazio tra le due sponde



    if (!lupo_sx)
        cout << " lup";
    else
        cout << "    ";


    if (!capra_sx)
        cout << " cap";                         //personaggi a destra
    else
        cout << "    ";


    if (!cavolo_sx)
        cout << " cav ";
    else
        cout << "     ";

    if (i%2 == 1){
        cout << "-------------_(___)________________-------------" << endl;     //base caso in cui sia un turno dispari barca a sinistra
    } else {
        cout << "-------------________________(___)_-------------" << endl;     //base caso in cui sia un turno pari barca a destra
    }
}

void interazioneUtente(){
}

void eseguiAzione(){ //IMPLEMENTATA
    switch(scelta){
    case 1: //CAPRA
        if(mosse%2 != 0){ //BARCA SPONDA DX
            if(!capra_sx){ //CAPRA SPONDA DX
                capra_sx = true;
                mosse++;
            }else{ //CAPRA SPONDA SX
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a destra, mentre la capra sulla sponda opposta. Riprovare.";
            }
        }else{ //BARCA SPONDA SX
            if(capra_sx){ //CAPRA SPONDA SX
                capra_sx = false;
                mosse++;
            }else{ //CAPRA SPONDA DX
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a sinistra, mentre la capra sulla sponda opposta. Riprovare.";
            }
        }

        break;

    case 2: //CAVOLO
        if(mosse%2 != 0){ //BARCA SPONDA DX
            if(!cavolo_sx){ //CAVOLO SPONDA DX
                cavolo_sx = true;
                mosse++;
            }else{ //CAVOLO SPONDA SX
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a destra, mentre il cavolo sulla sponda opposta. Riprovare.";
            }
        }else{ //BARCA SPONDA SX
            if(cavolo_sx){ //CAVOLO SPONDA SX
                cavolo_sx = false;
                mosse++;
            }else{ //CAVOLO SPONDA DX
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a sinistra, mentre il cavolo sulla sponda opposta. Riprovare.";
            }
        }

        break;

    case 3: //LUPO
        if(mosse%2 != 0){ //BARCA SPONDA DX
            if(!lupo_sx){ //LUPO SPONDA DX
                lupo_sx = true;
                mosse++;
            }else{ //LUPO SPONDA SX
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a destra, mentre la capra sulla sponda opposta. Riprovare.";
            }
        }else{ //BARCA SPONDA SX
            if(lupo_sx){ //LUPO SPONDA SX
                lupo_sx = false;
                mosse++;
            }else{ //LUPO SPONDA DX
                cout << "IMPOSSIBILE MUOVERE ELEMENTO! \n";
                cout << "La barca si trova a sinistra, mentre il lupo sulla sponda opposta. Riprovare.";
            }
        }

        break;

    default: //BARCA CON SOLO CONTADINO
        mosse++;
    }
}

bool controllaFine(){ //IMPLEMENTATA
    bool controlla_fine = false;

    if(controllaVittoria() || controllaSconfitta())
        controlla_fine = true;

    return controlla_fine;
}

bool controllaVittoria(){ //IMPLEMENTATA
    bool controlla_vittoria = false;

    if(capra_sx && cavolo_sx && lupo_sx)
        controlla_vittoria = true;

    return controlla_vittoria;
}

bool controllaSconfitta(){ //IMPLEMENTATA
    bool controlla_sconfitta = false;

    if((capra_sx && cavolo_sx && !lupo_sx && (mosse%2 != 0)) || (!capra_sx && !cavolo_sx && lupo_sx && (mosse%2 == 0))){
        cout << "Hai lasciato la capra con il cavolo da soli nella stessa sponda! \n";
        controlla_sconfitta = true;
    }

    if((capra_sx && lupo_sx && !cavolo_sx && (mosse%2 != 0)) || (!capra_sx && !lupo_sx && cavolo_sx && (mosse%2 == 0))){
        cout << "Hai lasciato la capra con il lupo da soli nella stessa sponda! \n";
        controlla_sconfitta = true;
    }

    return controlla_sconfitta;
}
