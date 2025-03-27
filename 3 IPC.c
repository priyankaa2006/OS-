#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];  // File descriptors for the pipe
    char message[] = "Hello from parent!";
    char buffer[50];

    if (pipe(fd) == -1) {  // Create a pipe
        printf("Pipe failed!\n");
        return 1;
    }

    if (fork() == 0) {  // Child process
        close(fd[1]);  // Close write end
        read(fd[0], buffer, sizeof(buffer));  // Read from pipe
        printf("Child received: %s\n", buffer);
        close(fd[0]);  // Close read end
    } else {  // Parent process
        close(fd[0]);  // Close read end
        write(fd[1], message, sizeof(message));  // Write to pipe
        close(fd[1]);  // Close write end
    }

    return 0;
}

/*
Child received: Hello from parent!
*/
