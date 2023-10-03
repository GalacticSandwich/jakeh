/**
    @file jakeh.c
    @author Aaron N. (GalacticSandwich)

    ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "strings.h"
#include "strcomp.h"

#define L_PATH_MAX 2048

int main( int argc, char** argv )
{
    // current working directory
    char cwd[ L_PATH_MAX ];

    // current command
    string* ccmd;
    // current working object name
    string* cwon;

    // running flag
    int running = 1;

    while ( running ) {
        if ( getcwd( cwd, sizeof( cwd ) ) != NULL ) {
            printf( "[jakeh] " );
            ccmd = str_readln();
        }
        else {
            perror( "[jakeh] error: Could not fetch current directory\n" );
            exit( EXIT_FAILURE );
        }
    }

    return EXIT_SUCCESS;
}