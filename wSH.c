#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char buffer[1024];

    printf("Welocome to the Wei Shell !\n");

    while (1) {
        printf("lwsh> ");

        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        if (strlen(buffer) == 0) {
            continue;
        }

        char *args[64];
        int i = 0;
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("wSH : commande introuvable");
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("wSH : erreur de fork");
        }
    }
}
