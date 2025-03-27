
#include <stdio.h>
#include <string.h>

#define MAX_USERS 3

// Structure to store user-role mapping
typedef struct {
    char username[20];
    char role[20];
} User;

// Predefined roles and their permissions
void checkPermission(char role[]) {
    if (strcmp(role, "admin") == 0)
        printf("Permissions: Read, Write, Execute\n");
    else if (strcmp(role, "editor") == 0)
        printf("Permissions: Read, Write\n");
    else if (strcmp(role, "viewer") == 0)
        printf("Permissions: Read only\n");
    else
        printf("Invalid role!\n");
}

int main() {
    User users[MAX_USERS] = {
        {"Alice", "admin"},
        {"Bob", "editor"},
        {"Charlie", "viewer"}
    };

    char username[20];
    printf("Enter username: ");
    scanf("%s", username);

    // Find user and display permissions
    int found = 0;
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User: %s, Role: %s\n", users[i].username, users[i].role);
            checkPermission(users[i].role);
            found = 1;
            break;
        }
    }

    if (!found) printf("User not found!\n");

    return 0;
}
//Enter username: Alice
//User: Alice, Role: admin
//Permissions: Read, Write, Execute
