


// UFRN-CT-DCA
// Disciplina: Sistemas de Tempo Real
// Programa: tempomicro.cpp




#include <stdio.h>
#include <sys/time.h>
#include <unistd.h> // para: sleep()

int main() {
    int i, j;
    struct timeval tempo_inicial, tempo_final;
    int long tempo_de_hoje, tmili;

    gettimeofday(&tempo_inicial, NULL);  // inicio é uma struct com dois campos:tv_sec e tv_usec.
    
    tempo_de_hoje = (int long) (1000 * (tempo_inicial.tv_sec) + (tempo_inicial.tv_usec) / 1000); // para transformar em milissegundos
    
    printf("tempo decorrido hoje até agora: %ld milissegundos\n", tempo_de_hoje);
    
     /* Substitua o for a seguir pelo trecho de código
       cujo tempo de execução deverá ser medido. */
    
    for (j = 0; j < 2; j ++)
        for (i = 0; i < 1387634340; i ++);
    sleep(1);
    gettimeofday(&tempo_final, NULL);
    tmili = (int long) (1000 * (tempo_final.tv_sec - tempo_inicial.tv_sec) + (tempo_final.tv_usec - tempo_inicial.tv_usec) / 1000); // para transformar em milissegundos

    printf("tempo decorrido: %ld milissegundos\n", tmili);
    return (0);
}
