
#include <stdlib.h>

#include "strings.h"

int str_len( string const* str ) { return str->len; }

char str_char( string const* str, int n ) { return str->chars[ n ]; }

string* str_alloc( int len )
{
    string* str = ( string* ) malloc( sizeof( string ) );

    if ( str != NULL ) {
        str->chars = ( char* ) malloc( len * sizeof( char ) );
        str->len = len;
    }

    return str;
}

void str_free( string* str )
{
    free( str->chars );
    free( str );
}
