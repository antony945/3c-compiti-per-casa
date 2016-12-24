//Franzoso Antonio 3C Capra, Lupo, Cavolo

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
   Varia a seconda del valore delle variabili booleane 'vittoria' e 'sconfitta'. */

void inizializzaGioco(void);
/* Mostra il messaggio iniziale e inizializza tutte le variabili del gioco
   assegnando loro il valore desiderato prima che inizi il gioco. */

void disegnaScenario(void);
/* Stampa a video lo scenario nel momento in cui viene richiamata
   a seconda del valore delle variabili utilizzate. */

void interazioneUtente(void);
/* Permette all'utente di scegliere la mossa da compiere al fine di vincere il gioco.
   NON cambia valore delle variabili utilizzate, ma MEMORIZZA la scelta fatta. */

void eseguiAzione(void);
/* CAMBIA il valore delle variabili a seconda delle scelte fatte nella funzione 'interazioneUtente'. */

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

bool vittoria;
/* Variabile booleana che restituisce 'TRUE' se l'utente VINCE il gioco attraverso le azioni
   compiute, altrimenti 'FALSE'. Si ha vittoria quando controllaVittoria() restituisce 'TRUE'. */

bool sconfitta;
/* Variabile booleana che restituisce 'TRUE' se l'utente PERDE il gioco attraverso le azioni
   compiute, altrimenti 'FALSE'. Si ha sconfitta quando controllaSconfitta() restituisce 'TRUE'. */

bool end_game;
/* Variabile booleana che restituisce 'TRUE' se il gioco termina a causa di un cambiamento di
   scenario imposto dall'utente, altrimenti 'FALSE'. Il gioco finisce quando vittoria = TRUE o sconfitta = TRUE.
   Variabile utilizzata nel loop principale del gioco. */

bool capra_dx; //Assume 'TRUE' se è presente una capra nella sponda dx, altrimenti 'FALSE'
bool capra_sx; //Assume 'TRUE' se è presente una capra nella sponda sx, altrimenti 'FALSE'
bool capra_barca; //Assume 'TRUE' se è presente una capra nella barca, altrimenti 'FALSE'
/* Variabili booleane rappresentanti le capre presenti nello scenario. Assumono valore 'TRUE' se ci sono nella determinata
   sponda o barca espressa dal nome, altrimenti 'FALSE' se non ci sono nella determinata sponda o barca espressa dal nome.
   Se una delle tre variabili assume 'TRUE', è necessario che le altre assumano 'FALSE'. */

bool lupo_dx; //Assume 'TRUE' se è presente un lupo nella sponda dx, altrimenti 'FALSE'
bool lupo_sx; //Assume 'TRUE' se è presente un lupo nella sponda sx, altrimenti 'FALSE'
bool lupo_barca; //Assume 'TRUE' se è presente un lupo nella barca, altrimenti 'FALSE'
/* Variabili booleane rappresentanti i lupi presenti nello scenario. Assumono valore 'TRUE' se ci sono nella determinata
   sponda o barca espressa dal nome, altrimenti 'FALSE' se non ci sono nella determinata sponda o barca espressa dal nome.
   Se una delle tre variabili assume 'TRUE', è necessario che le altre assumano 'FALSE'. */

bool cavolo_dx; //Assume 'TRUE' se è presente un cavolo nella sponda dx, altrimenti 'FALSE'
bool cavolo_sx; //Assume 'TRUE' se è presente un cavolo nella sponda sx, altrimenti 'FALSE'
bool cavolo_barca; //Assume 'TRUE' se è presente un cavolo nella barca, altrimenti 'FALSE'
/* Variabili booleane rappresentanti i cavoli presenti nello scenario. Assumono valore 'TRUE' se ci sono nella determinata
   sponda o barca espressa dal nome, altrimenti 'FALSE' se non ci sono nella determinata sponda o barca espressa dal nome.
   Se una delle tre variabili assume 'TRUE', è necessario che le altre assumano 'FALSE'. */

char lato_barca;
/* Variabile che assume solamente due valori:
   - 'd' se la barca è attraccata alla sponda dx
   - 's' se la barca è attraccata alla sponda sx */

char scelta_elemento;
/* Variabile che memorizza la scelta effettuata in input dal giocatore su quale elemento far muovere.
   Può assumere quattro valori:
   - 'G' o 'g' per capra; la capra salirà o scenderà dalla barca a seconda della sua posizione
                          (se si trova su una sponda salirà, altrimenti scenderà dalla barca)
   - 'L' o 'l' per lupo; vedi funzionamento capra
   - 'C' o 'c'per cavolo; vedi funzionamento capra
   - 'B' o 'b' per barca; la barca partirà dalla sponda nella quale si trova, arrivando a quella opposta */

//*******************************************************************************************************************************
/* CODICE PROGRAMMA */

int main(){
    inizializzaGioco();

    while(!end_game){
        disegnaScenario();
        interazioneUtente();
        eseguiAzione();
        controllaVittoria();
        controllaSconfitta()
    }

    messaggioFinale();

    system("PAUSE");
    return 0;
}

messaggioIniziale(){
}

messaggioFinale(){
}

inizializzaGioco(){
}

disegnaScenario(){
}

interazioneUtente(){
}

eseguiAzione(){
}

controllaVittoria(){
}

controllaSconfitta(){
}
