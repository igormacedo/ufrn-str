
#include <iostream> // para: cout
#include <time.h>   // para: time()
#include <unistd.h>
#include <stdlib.h>



using std::cout;
using std::cin;


int main ( )
{

  time_t tempo_real;
  time_t tempo_antes, tempo_depois;
  
  int numero;

  tempo_real = time( (time_t *) 0);  // apontando o ponteiro para null.
  cout << "Já se passaram  " << tempo_real << " segundos desde 0:00:00 de 01/01/1970 " << '\n';
  // printf(" Com printf: %ld \n", tempo_real);
    tempo_antes = time( (time_t *) 0);
    for(int i=0; i< 10000000; i++)for(int k=0; k<1000;k++);
    sleep(2);
    tempo_depois = time ( (time_t *) 0);
    
  tempo_real = time( (time_t *) 0);  // apontando o ponteiro para null.
  cout << "Já se passaram  " << tempo_real << " segundos desde 0:00:00 de 01/01/1970 " << '\n';
  cout << "Tempo do for: "<< tempo_depois - tempo_antes << "\n";
    
    

  exit(0);
}

