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
        printf("\n1. Add new user\n2. Find user\n3. Show all\n0. Exit\nChoose: ");
        if (scanf("%d", &scelta) != 1) {
            clear_input_buffer();
            printf("Invalid input.\n");
            continue;
        }
        clear_input_buffer();

        switch (scelta) {
            case 1:
                printf("Insert ID: ");
                scanf("%d", &id);
                clear_input_buffer();
                printf("Insert name: ");
                fgets(nome, NAME_LENGTH, stdin);
                trim_newline(nome);
                add_user(id, nome);
                break;
            case 2:
                printf("Enter the ID to search: ");
                scanf("%d", &id);
                clear_input_buffer();
                User* u = find_user(id);
                if (u)
                    printf("User found: %s\n", u->name);
                else
                    printf("User not found.\n");
                break;
            case 3:
                print_all_users();
                break;
            case 0:
                printf("Exit...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (scelta != 0);

    return 0;
}
