#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Using "" it will search for the files to include in the same directory of the file to compile.
 * Ususally this syntax is used to include header files defined by the programmer.
 */
#include "user.h"
#include "utils.h"

int main(void) {
    int scelta;
    char nome[NAME_LENGTH];
    int id;

    // Main menu loop
    do {
        printf("\n1. Aggiungi utente\n2. Cerca utente\n3. Visualizza tutti\n0. Esci\nScelta: ");
        if (scanf("%d", &scelta) != 1) {
            clear_input_buffer();
            printf("Input non valido.\n");
            continue;
        }
        clear_input_buffer();

        switch (scelta) {
            case 1:
                printf("Inserisci ID: ");
                scanf("%d", &id);
                clear_input_buffer();
                printf("Inserisci nome: ");
                fgets(nome, NAME_LENGTH, stdin);
                trim_newline(nome);
                add_user(id, nome);
                break;
            case 2:
                printf("Inserisci ID da cercare: ");
                scanf("%d", &id);
                clear_input_buffer();
                User* u = find_user(id);
                if (u)
                    printf("Utente trovato: %s\n", u->name);
                else
                    printf("Utente non trovato.\n");
                break;
            case 3:
                print_all_users();
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida.\n");
        }
    } while (scelta != 0);

    return 0;
}
