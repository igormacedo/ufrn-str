#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (){
	printf("Inicio do programa Monitor\n");
	
    while(1) {
        //system("pstree -a| grep fork");
        system("ps -af| grep fork");
        sleep(1);
        system("clear");
    }
	exit (0);
}


