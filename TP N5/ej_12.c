#include <stdio.h>
#include <ctype.h>
#include "getnum.h"

int main(void) {
  int n,c;

  /* al salir del ciclo n debe ser un número par mayor que cero */
  do
    n=getint("");
  while(n <= 0 || n % 2 != 0 );
  /* while(!(n > 0 && n % 2 == 0));  otra forma de hacerlo */

      
  /* este ciclo debe incluir la lectura de caracteres y se debe ejecutar mientras no se 
  * llegue a fin de archivo y los caracteres sean dígitos o minúsculas */
  while ((c=getchar())!=EOF && (isdigit(c) || islower(c)))
  putchar(c);

	return 0;
}