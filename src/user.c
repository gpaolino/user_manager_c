#include <stdio.h>
#include <string.h>
#include "user.h"

static User users[MAX_USERS];
static int user_count = 0;

void add_user(int id, const char *name) {
    if (user_count >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    users[user_count].id = id;
    strncpy(users[user_count].name, name, NAME_LENGTH - 1);
    users[user_count].name[NAME_LENGTH - 1] = '\0';
    user_count++;
    printf("User added successfully.\n");
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
    printf("\n--- User list ---\n");
    for (int i = 0; i < user_count; ++i) {
        printf("ID: %d, Name: %s\n", users[i].id, users[i].name);
    }
}
