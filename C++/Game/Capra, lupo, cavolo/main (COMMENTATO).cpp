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
/* Stampa a video l'elemento grafico della barca che cambia sponda dopo ogni turno.
   RICORDA! Quando CONTATORE = 1, NON deve essere richiamata. */

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

bool capra_sponda;
/* Variabile booleana indicante la posizione della CAPRA nello scenario.
   Assume 'TRUE' se la CAPRA è nella sponda sx, ovvero nella posizione dove il gioco richiede che sia, altrimenti 'FALSE'. */

bool lupo_sponda;
/* Variabile booleana indicante la posizione del LUPO nello scenario.
   Assume 'TRUE' se il LUPO è nella sponda sx, ovvero nella posizione dove il gioco richiede che sia, altrimenti 'FALSE'. */

bool cavolo_sponda;
/* Variabile booleana indicante la posizione del CAVOLO nello scenario.
   Assume 'TRUE' se il CAVOLO è nella sponda sx, ovvero nella posizione dove il gioco richiede che sia, altrimenti 'FALSE'. */

char scelta;
/* Variabile che memorizza la scelta effettuata in input dal giocatore su quale elemento far muovere da una sponda all'altra.
   (lo spostamento verrà stampato a video con l'ausilio della nuova funzione 'transizioneBarca()'
   Può assumere tre valori:
   - 'G' o 'g' per capra; la capra si spostesa sulla sponda opposta a seconda della sua posizione di partenza
                          (se si trova sulla sponda dx passerà sulla sponda sx, altrimenti passerà sulla sponda dx)
   - 'L' o 'l' per lupo; vedi funzionamento capra
   - 'C' o 'c'per cavolo; vedi funzionamento capra */

//*******************************************************************************************************************************
/* CODICE PROGRAMMA */

int main(){
    //Stampa a video scopo e regole del gioco
    messaggioIniziale();

    //Inizializza le variabili del gioco
    inizializzaGioco();

    // Ciclo principale del gioco, il gioco non termina finchè end_game diventa TRUE
    // Viene utilizzato un contatore per memorizzare il numero di mosse effettuate dall'utente
    for(int mosse = 1; end_game; mosse++){
        //Visualizza lo spostamento degli elementi da una sponda all'altra.
        transizioneBarca();

        //Disegna a video lo scenario attuale
        disegnaScenario();

        //Controlla se il gioco è terminato o meno
        if(controllaFine()){
            continue;
        }

        //Chiede in input la scelta dell'utente su quale elemento muovere
        interazioneUtente();

        //Rende effettive le modifiche alle variabili indicate dalla scelta dell'utente
        eseguiAzione();
    }

    //Visualizza il messaggio finale a seconda dell'esito del gioco
    messaggioFinale();

    //Chiude il programma
    system("PAUSE");
    return 0;
}

void messaggioIniziale(){
}

void messaggioFinale(){
}

void inizializzaGioco(){
}

void transizioneBarca(){
}

void disegnaScenario(){
}

void interazioneUtente(){
}

void eseguiAzione(){
}

bool controllaFine(){ //IMPLEMENTATA
    //Dichiara variabile contenente il valore della funzione
    bool controlla_fine = FALSE;

    //Controllo della fine del gioco
    if(controllaVittoria() || controllaSconfitta())
        //Assegna alla variabile locale della funzione valore 'TRUE'
        controlla_fine = TRUE;

    //Ritorna il valore contenuto nella variabile 'controlla_fine'. Se 'TRUE', gioco terminato, altrimenti gioco ancora in corso
    return controlla_fine;
}

bool controllaVittoria(){
}

bool controllaSconfitta(){
}
