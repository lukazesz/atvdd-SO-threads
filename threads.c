// Biblioteca padrão de entrada e saída.
#include <stdio.h> 

// Biblioteca padrão (exit, etc.).
#include <stdlib.h>     

// Biblioteca necessária para usar threads em C.
#include <pthread.h>    

// Usada para a função sleep().
#include <unistd.h>     

// Função que vai ser executada pela primeira thread.
void* tarefa1(void* arg) {
    for (int i = 0; i < 10; i++) {      
        if (i % 2 == 0) {               
            printf("Thread 1 (pares): %d\n", i);
            sleep(1);                  
        }
    }

    // Encerrando a thread.
    pthread_exit(NULL); 
}

// Função que vai ser executada pela segunda thread.
void* tarefa2(void* arg) {
    for (int i = 0; i < 10; i++) {      
        if (i % 2 != 0) {               
            printf("Thread 2 (ímpares): %d\n", i);
            sleep(1);                   
        }
    }

    // Encerrando a thread.
    pthread_exit(NULL);  
}

int main() {

    // Declarando duas variáveis do tipo pthread_t (identificadores das threads
    pthread_t thread1, thread2; )

    
    // Criação da primeira thread.
    // pthread_create(criador, atributos, função, argumento).
    // Neste caso, passamos NULL para atributos e argumento, pois não precisamos deles.
    if (pthread_create(&thread1, NULL, tarefa1, NULL)) {
        fprintf(stderr, "Erro ao criar a thread 1\n");
        return 1;
    }

    // Criação da segunda thread.
    if (pthread_create(&thread2, NULL, tarefa2, NULL)) {
        fprintf(stderr, "Erro ao criar a thread 2\n");
        return 1;
    }

    
    // Aguarda as duas threads terminarem antes de encerrar o programa.
    // pthread_join(thread, retorno).
    // O programa principal "espera" cada thread terminar sua execução.
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Quando ambas terminam.
    printf("As duas threads terminaram a execução.\n");

    return 0;
}
