# Lezione 4
***
Tipi di variabili | Utilizzo
----------------|-----------------
SDL_Window|Creare la finestra fisica in cui si lavorerà
SDL_Surface|Crea una superficie di lavoro

***
## Funzioni utilizzate
Funzioni|Input|Utilizzo
:--------------:|:-----------:|-------------
SDL_Init|SDL_INIT_VIDEO|Inizializza SDL; se ritorna un valore negativo c'è stato un errore nell'inizializzazione.
SDL_GetError|/|Ritorna l'errore dovuto alla non conclusione di una funzione.
SDL_CreateWindow|"Titolo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Larghezza finestra, Altezza finestra, SDL_WINDOW_SHOWN|Genera la finestra su cui sarà possibile operare.
SDL_GetWindowSurface|Variabile SDL_Window|Ritorna l'immagine contenuta nella finestra.
SDL_LoadBMP|"Percorso immagine"|Carica all'interno di una variabile SDL_Surface un'immagine .bmp .
SDL_FreeSurface|Variabile SDL_Surface|Libera la memoria allocata a quella variabile, ripulendo la finestra.
SDL_DestroyWindow|Variabile SDL_Window|Distrugge la finestra data in input.
SDL_Quit|/|Esce dal sottositema SDL.
SDL_BlitSurface|Variabile SDL_Surface sorgente, NULL, Variabile SDl_Surface di destinazione, NULL|Sovrappone la superficie sorgente a quella di destinazione.
SDl_UpdateWindowSurface|Variabile SDL_Window|Mostra sullo schermo l'attuale back buffer.
SDL_Delay|Tempo espresso in ms|Attende il periodo di tempo dato in input prima di proseguire.

***

### Da ricordare
* Includere la libreria c++ **<string>** per visualizzare il contenuto della funzione _SDL_GetError_.
* Definire come **costanti** implicite o esplicite la lunghezza (_WIDTH_) e l'altezza (_HEIGHT_) della finestra.
* Utilizzare le funzioni *SDL_FreeSurface, SDL_DestroyWindow e SDL_Quit* per liberare la memoria e chiudere il programma.
* Inizializzare tutti i puntatori come __NULL__.
* All'interno del secondo ciclo studiare tutti i casi possibili di eventi di tipo _KEYDOWN_ attraverso questo blocco di codice (_event_ è la variabile SDL_Event, _gCurrentSurface_ è la superficie che mostra l'immagine corrente e _gKeyPressSurfaces_ è il nome dato all'enumerazione):
```c++
    switch(event.sym.keysym.sym){
    case SDLK_UP:
		gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
		break;
    case ...:
        break;
	default:
		gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
		break;
}
```
***

Sintesi elaborata da Franzoso Antonio

Ref: [Lezione 4](http://lazyfoo.net/tutorials/SDL/04_key_presses/index.php)

*__N.b. la sintesi è elaborata solo in base alle informazioni contenute all'interno della lezione 4__*
