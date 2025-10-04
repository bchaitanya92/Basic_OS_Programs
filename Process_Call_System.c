#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, child_pid;
    int status;

    pid = fork();

    if (pid < 0) {

        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
    
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());

        execlp("ls", "ls", NULL);

        perror("execlp failed");
        exit(EXIT_FAILURE);
    } else {

        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        
        child_pid = wait(&status);

        if (child_pid == -1) {
            perror("wait failed");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process did not exit normally\n");
        }
    }

    return 0;
}

'''
Output:

braham@braham:~/Desktop/program$ gcc prg1.c -o prg1
braham@braham:~/Desktop/program$ ./prg1
Parent process: PID = 4203, Child PID = 4204
Child process: PID = 4204, PPID = 4203
prg1  prg1.c
Child process exited with status 0
'''