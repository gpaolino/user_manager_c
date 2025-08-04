#ifndef USER_H
#define USER_H

#define MAX_USERS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} User;

void add_user(int id, const char *name);
User* find_user(int id);
void print_all_users(void);

#endif
