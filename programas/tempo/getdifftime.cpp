/* difftime example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <iostream>

using namespace std;

int main ()
{
  time_t now;
  struct tm newyear;
  double seconds;

	int ano, mes, dia;

	cout << "Digite ano, mes, dia" << endl;
	cin >> ano;
	cin >> mes;
	cin >> dia;

  time(&now);  /* get current time; same as: now = time(NULL)  */

  newyear = *localtime(&now);

  newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
  newyear.tm_mon = mes-1;  newyear.tm_mday = dia; newyear.tm_year = ano-1900;

  seconds = difftime(now,mktime(&newyear));

  printf ("%.f seconds since birth.\n", seconds);

  return 0;
}
