#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid == 0) {
        // Child process
        printf("Child process with PID %d exiting...\n", getpid());
        exit(0);
    } else if (child_pid > 0) {
        // Parent process
        printf("Parent process with PID %d waiting...\n", getpid());

        // Don't wait for the child process to terminate (create zombie)
        sleep(5);  // Sleep for a few seconds to allow child to exit

        // Execute ps command to verify child process state
        system("ps -e -o pid,ppid,stat,cmd");
    } else {
        // Fork failed
        perror("fork");
        exit(1);
    }

    return 0;
}
