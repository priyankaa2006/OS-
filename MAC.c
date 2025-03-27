
#include <stdio.h>

// Define security levels
#define LOW 1
#define MEDIUM 2
#define HIGH 3

// Structure for User
typedef struct {
    char name[20];
    int level;
} User;

// Structure for File
typedef struct {
    char name[20];
    int level;
} File;

// Function to check access control
int canAccess(User user, File file) {
    return user.level >= file.level;  // User can access only if their level is >= file level
}

int main() {
    // Define users
    User user1 = {"Alice", MEDIUM};
    User user2 = {"Bob", LOW};

    // Define files
    File file1 = {"Confidential.txt", HIGH};
    File file2 = {"Public.txt", LOW};

    // Check access
    printf("%s access to %s: %s\n", user1.name, file1.name, canAccess(user1, file1) ? "Allowed" : "Denied");
    printf("%s access to %s: %s\n", user2.name, file2.name, canAccess(user2, file2) ? "Allowed" : "Denied");

    return 0;
}
//Alice access to Confidential.txt: Denied
//Bob access to Public.txt: Allowed
