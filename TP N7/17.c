#include <assert.h>
#include <stdio.h>
#include <string.h>

// Le cambiamos el nombre para que no haya conflictos con la biblioteca estandar
char * strCat( char *s, const char *t);

int main(void){

    char ga[10]="ga";
    char to[]="to";
    char empty[10]="";

    assert(!strcmp("", strCat(empty, empty)));
    assert(!strcmp("gato", strCat(ga, to)));
    assert(!strcmp("gato", strCat(ga, empty)));
    assert(!strcmp("gatoto", strCat(ga, to)));
    assert(!strcmp("gatoto", strCat(empty, ga)));

    puts("OK!");
    return 0;
}

char * strCat(char* s, const char* t) {
    char* s_return = s;
    while ( *s != '\0' ) {
        s++;
    }

    while ( *t != '\0' ) {
        *s++ = *t++;
    }
    *s = '\0';
    return s_return;
}