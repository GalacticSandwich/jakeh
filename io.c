/**
    @file io.c
    @author GalacticSandwich

    ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int spaceToNulls( char* str )
{
    int count = 0;
    int len = strlen( str );

    for ( int i = 0; i < len; i++ )
        switch ( str[ i ] ) {
            case ' ':
            case '\t':
                str[ i ] = '\0';
                count++;
                break;
            default:
                break;
        }
    
    return count + 1;
}

char* input( char const* outs )
{
    printf( "%s", outs );
    
    int i = 0;
    char* ins = ( char* ) malloc( sizeof( char ) );

    while ( ( char c = getchar() ) != '\n' ) {
        ins[ i++ ] = c;
        ins = ( char* ) realloc( ins, i * sizeof( char ) );
    }

    ins[ i ] = '\0';

    return ins;
}

void parseCommand( char* str, char* args[] )
{
    
}