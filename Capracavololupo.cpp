#include <iostream>
#include <stdlib.h>

using namespace std;

//*******************************************************************************************************************************
/* PROTOTIPI FUNZIONI */
/* Lista di tutte le funzioni che verranno richiamate all'interno del codice di gioco ('main'). */


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

bool controllaVittoria(); //SE FALSE ALLORA è = A CONTROLLASCONFITTA
/* Controlla se, dopo aver applicato i cambiamenti imposti dall'utente alle variabili,
   l'utente ha VINTO il gioco. Può restituire 'TRUE' (vittoria), o 'FALSE' (non vittoria). */

bool controllaSconfitta();


//*******************************************************************************************************************************
/* VARIABILI GLOBALI */
/* Lista di tutte le variabili dichiarate GLOBALMENTE che verranno usate nel codice di gioco.
   Sono coloro che potranno essere usate nel 'main' e all'interno di tutte le funzioni richiamate nel 'main'. */

bool vittoria;
/* Variabile booleana che restituisce 'TRUE' se l'utente VINCE il gioco attraverso le azioni
   compiute, altrimenti 'FALSE' implica sconfitta. Si ha vittoria quando controllaVittoria() restituisce 'TRUE'. */



bool sconfitta;



bool end_game;
/* Variabile booleana che restituisce 'TRUE' se il gioco termina a causa di un cambiamento di
   scenario imposto dall'utente, altrimenti 'FALSE'. Il gioco finisce quando vittoria = TRUE o sconfitta = TRUE.
   Variabile utilizzata nel loop principale del gioco. */

bool capra_sx // se assume valore TRUE è a sinistra, altrimenti è a Destra
/* Variabili booleane rappresentanti le capre presenti nello scenario. Assumono valore 'TRUE' se ci sono nella determinata
   sponda o barca espressa dal nome, altrimenti 'FALSE' se non ci sono nella determinata sponda o barca espressa dal nome.
   Se una delle tre variabili assume 'TRUE', è necessario che le altre assumano 'FALSE'. */

bool lupo_sx // se assume valore TRUE è a sinistra, altrimenti è a Destra
/* Variabili booleane rappresentanti i lupi presenti nello scenario. Assumono valore 'TRUE' se ci sono nella determinata
   sponda o barca espressa dal nome, altrimenti 'FALSE' se non ci sono nella determinata sponda o barca espressa dal nome.
   Se una delle tre variabili assume 'TRUE', è necessario che le altre assumano 'FALSE'. */

bool cavolo_sx // se assume valore TRUE è a sinistra, altrimenti è a Destra
/* Variabili booleane rappresentanti i cavoli presenti nello scenario. Assumono valore 'TRUE' se ci sono nella determinata
   sponda o barca espressa dal nome, altrimenti 'FALSE' se non ci sono nella determinata sponda o barca espressa dal nome.
   Se una delle tre variabili assume 'TRUE', è necessario che le altre assumano 'FALSE'. */



/*Ho tolto completamente la barca, intendo utilizzarla solo come espediente grafico, ogni turno i personaggi si muovono da
 una spponda all'altra e compaiono sulla barca attraverso il sitema di variabili posto_dx e posto_sx utilizzato in missionari e cannibali */



char scelta_elemento;
/* Variabile che memorizza la scelta effettuata in input dal giocatore su quale elemento far muovere.
   Può assumere quattro valori:
   - 'G' o 'g' per capra; la capra salirà o scenderà dalla barca a seconda della sua posizione
                          (se si trova su una sponda salirà, altrimenti scenderà dalla barca)
   - 'L' o 'l' per lupo; vedi funzionamento capra
   - 'C' o 'c'per cavolo; vedi funzionamento capra
   *****BARCA RIMOSSA*****  */

//*******************************************************************************************************************************
/* CODICE PROGRAMMA */

int main(){
    inizializzaGioco();

    for(int i = 1; !end_game; i++){
        disegnaScenario();
        interazioneUtente();
        eseguiAzione();
        controllaVittoria();
        controllaSconfitta();
    }

    messaggioFinale();

    system("PAUSE");
    return 0;
}


void messaggioFinale(){
}

void inizializzaGioco(){
    end_game = false;
    capra_sx = false;
    lupo_sx = false;
    cavolo_sx = false;
    cout << "" << endl << endl; //centrato con cornice: Benvenuti aal gioco della capra, cavolo e lupo
    cout << "Scopo del gioco: " << endl;
    cout << "Il gioco consiste nell'aiutare un ipotetico contadino a trasportare la capra, il cavolo e il lupo dalla sponda sinistra del fiume alla sponda destra." << endl << endl;
    cout << "Regolamento: " << endl;
    cout << "Ogni turno si può muovere la barca con massimo un personaggip tra quelli sopracitati." << endl << endl;
    cout << "Gameover: " << endl;
    cout << "Il gioco può terminare in due modi: vittoria o sconfitta. La sconfitta si verifica quando su una stessa sponda sono presenti due personaggi che potrebbero mangiarsi (lupo-capra o capra-cavolo). Il gioco termina con una vittoria invece quando si riesce a spostare tutti e tre i personaggi dalla sponda destra alla sponda sinistra senza incappare in una delle situazioni di sconfitta descritte precedentemente" << endl << endl;
    cout << "" << endl << endl; //centrato con cornice: buona fortuna
}

void disegnaScenario(){
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

    if (i%2 == 0){
        cout << "-------------_(___)________________-------------" << endl;     //base caso in cui sia un turno dispari barca a sinistra
    } else {
        cout << "-------------________________(___)_-------------" << endl;     //base caso in cui sia un turno pari barca a destra
    }
}

void interazioneUtente(){
}

void eseguiAzione(){
}

bool controllaVittoria(){
}

bool controllaSconfitta(){
}
