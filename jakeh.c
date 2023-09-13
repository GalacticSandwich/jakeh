/**
    @file jakeh.c
    @author Aaron N. (GalacticSandwich)

    ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lang.h"

#define F_PRINTING 1

#define MAX_FNAME_LEN 96
#define MAX_FEXT_LEN 7
#define LANG_ARGLEN 4
#define LANG_CLANG_NAMELEN 1
#define LANG_JAVA_NAMELEN 4

static void usage()
{
    fprintf( stderr, "usage: jakeh <flags> <file>\n" );
}

static FILE* openFile( char* name, lang_t lid ) {
    int fnl = MAX_FNAME_LEN + MAX_FEXT_LEN + 1;

    char fname[ fnl ];
    strncpy( fname, name, fnl );
    strcat( fname, langExt( lid ) );

    FILE* file = fopen( fname, "w" );

    return file;
}

static void parseCommand( int numArgs, char** argArr, lang_t* currLang )
{
    // grab a copy of the argument vector to move forward
    // as flags are parsed
    char** mArgArr = argArr + 1;
    numArgs--;

    if ( numArgs == 0 ) {
        usage();
        exit( EXIT_FAILURE );
    }

    while ( numArgs > 0 ) {
        if ( !strncmp( "-lang", mArgArr[ 0 ], LANG_ARGLEN + 1 ) ) {
            if ( !strncmp( "=java", mArgArr[ 0 ] + LANG_ARGLEN + 1, LANG_JAVA_NAMELEN + 1 ) )
                *currLang = L_JAVA;
            else if ( !strncmp( "=c", mArgArr[ 0 ] + LANG_ARGLEN + 1, LANG_CLANG_NAMELEN + 1 ) )
                *currLang = L_CLANG;

            if ( F_PRINTING )
                printf( "[jakeh] Language selected: %s\n", langName( *currLang ) );
        }
        else {
            FILE* file = openFile( mArgArr[ 0 ], *currLang );

            if ( F_PRINTING )
                printf( "[jakeh] File created: %s%s\n", mArgArr[ 0 ], langExt( *currLang ) );

            fclose( file );
        }

        numArgs--;
        mArgArr++;
    }
}

int main( int argc, char** argv ) 
{
    lang_t lang = L_NULL;

    parseCommand( argc, argv, &lang );

    return EXIT_SUCCESS;
}
