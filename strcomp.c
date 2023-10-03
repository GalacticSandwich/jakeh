
#include <stdio.h>

#include "strcomp.h"

string* str_readln(void)
{
    string* str = ( string* ) malloc( sizeof( string ) );

    if ( str != NULL ) {
        char c; int i = 0;
        str->chars = ( char* ) malloc( ( i + 1 ) * sizeof( char ) );

        while ( ( c = getchar() ) != '\n' ) {
            str->chars = ( char* ) realloc( str->chars, ( i + 1 ) * sizeof( char ) );
            str->chars[ i++ ] = c;
        }

        str->len = i;
    }

    return str;
}
