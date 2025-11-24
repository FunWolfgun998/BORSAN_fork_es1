#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        pid_t figlio = fork();
        if (figlio == 0) {
            wait(NULL);
            printf("Il figlio n.%d \n", i);
            printf("Il mio PID %d\n", getpid());
            printf("Il PID papino %d\n", getppid());
            exit(-1);
        }
    }

    return 0;
}