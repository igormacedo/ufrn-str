/*
 *  gmtime.cpp
 *  
 *
 *  Created by Luiz Affonso Guedes on 22/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

// UFRN-CT-DCA
// Manipulação de tempo em c,c++
// Programa: programa que manipula a struct tm

#include <iostream> //cout
#include <time.h>   //para: gmtime()
using namespace std;

int  main ( ){
	// um ponteiro para a estrutura tm
	struct tm *tm_ptr;
	struct tm *tm_ptr_local;  
	// variável para armazenar o tempo em segundos
	time_t  tempo_valor;
	time_t  tempo_valor_local;
	// armazenar o tempo
	time(&tempo_valor);
	time(&tempo_valor_local);
	// obtendo a esttutura
	
    
    	tm_ptr = gmtime(&tempo_valor);
	tm_ptr_local = localtime(&tempo_valor_local);

	
	cout << "Instante atual Local: " << tm_ptr_local->tm_mday << "/" << tm_ptr_local->tm_mon+1 << "/" << tm_ptr_local->tm_year+1900 << "\t" << tm_ptr_local->tm_hour << ":" << tm_ptr_local->tm_min << ":" << tm_ptr_local->tm_sec << "\n";

	cout << "Instante atual: " << tm_ptr->tm_mday << "/" << tm_ptr->tm_mon+1 << "/" << tm_ptr->tm_year+1900 << "\t" << tm_ptr->tm_hour << ":" << tm_ptr->tm_min << ":" << tm_ptr->tm_sec << "\n";
}

