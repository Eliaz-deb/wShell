#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	// On crée un "tampon" (buffer) pour stocker ce que l'utilisateur va taper.
    // 1024 caractères, c'est largement assez pour une ligne de commande.
    char buffer[1024];
    
    printf("Welocome to the Wei Shell !\n");
    
    // la boucle infini : le shell ne s'arrete jamais tout seul.
    while(1){
		// 1. On affiche le prompt
        // On utilise printf, pas puts, pour ne pas avoir de retour à la ligne automatique
        printf("lwsh> ");
        
        // 2. On lit ce que l'utilisateur tape au clavier.
        // ⚠️ RÈGLE D'OR : On n'utilise PAS scanf() ici. 
        // scanf s'arrête au premier espace. Si tu tapes "ls -la", scanf ne lira que "ls".
        // fgets lit TOUTE la ligne, espaces compris, jusqu'à ce que tu appuies sur Entrée.
        fgets(buffer, sizeof(buffer), stdin);
        // 1. NETTOYAGE : On enlève le '\n' (saut de ligne) à la fin
        buffer[strcspn(buffer, "\n")] = 0;
        
        // Si l'utulisateur n'a rien tapé (juste entrée), on ne fait rien et on reboucle
        
        if(strlen(buffer) == 0) {
			continue;
			}
			// 2. PARSING : On découpe la phrase en mots
			// On crée un tableau de pointeurs pour stocker les mots (max 64 arguments, c'est large)
			char *args[64];
			int i = 0;
			// strtok est une fonction qui découpe une chaîne selon un séparateur (ici, l'espace " ")
			char *token = strtok(buffer, " ");
			while(token != NULL){
				args[i] = token;
				i++;			
				token = strtok(NULL, " "); // On cherche le mot suivant
			}
				args[i] = NULL;
				pid_t pid = fork();
				if(pid == 0){
					execvp(args[0], args);
					 // SI ON ARRIVE ICI CEST QUE LA COMMANDE A ECHOUER
					 perror("wSH : commande introuvable");
					 exit(1);	
		} 		else if (pid > 0){
					// Le parent attend que l'enfant ai fini son travail
					wait(NULL);
				} else {
					// erreur de fork
					perror("wSH : erreur de fork");
					
					}


			}
		}


