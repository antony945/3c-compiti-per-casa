# v. 2.0

## Aggiunta funzione eseguiAzione + altro

Completata funzione eseguiAzione() con messaggi di errore.

Prova di una modifica delle condizioni del ciclo for per correggere un
errore logico:
* Eliminato incremento mosse dal ciclo in quanto la variabile delle
mosse aumenta anche nel caso in cui l'utente effettua una mossa non
permessa dal gioco, visualizzando il messaggio di errore e di fatto non
compiendo alcun movimento dei personaggi del gioco.
* Per questo, inserito incremento variabile mosse solamente nei casi in
cui l'utente effettui azioni permesse dal gioco e che determinino quindi
una differenza dello scenario del gioco.
* (Dichiarata variabile mosse come globale e unsigned int).

----------------------------------------------------------------------------

# v. 3.0

## Completato codice gioco

* Completato il codice essenziale del gioco. Ora manca la revisione dell'aspetto
grafico di esso.
* Modificato tipo variabili interazioneUtente ed eseguiAzione da void a bool.
* Aggiunta libreria <windows.h> per poter usare funzione _sleep_ in transizioneBarca.