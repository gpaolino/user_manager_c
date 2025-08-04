#include <stdio.h>
#include <string.h>
#include "user.h"

static User users[MAX_USERS];
static int user_count = 0;

void add_user(int id, const char *name) {
    if (user_count >= MAX_USERS) {
        printf("Errore: raggiunto numero massimo di utenti.\n");
        return;
    }

    users[user_count].id = id;
    strncpy(users[user_count].name, name, NAME_LENGTH - 1);
    users[user_count].name[NAME_LENGTH - 1] = '\0';
    user_count++;
    printf("Utente aggiunto con successo.\n");
}

User* find_user(int id) {
    for (int i = 0; i < user_count; ++i) {
        if (users[i].id == id) {
            return &users[i];
        }
    }
    return NULL;
}

void print_all_users(void) {
    printf("\n--- Elenco utenti ---\n");
    for (int i = 0; i < user_count; ++i) {
        printf("ID: %d, Nome: %s\n", users[i].id, users[i].name);
    }
}
