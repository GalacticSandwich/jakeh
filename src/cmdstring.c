
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmdstring.h"

static char* cmd_getl() {
	char c; int i = 0;
	char* str = ( char* ) malloc( sizeof( char ) );

	while ( ( c = getchar() ) != '\n' ) {
		str[ i++ ] = c;
		str = ( char* ) realloc( str, ( i + 1 ) * sizeof( char ) );
	}

	str[ i ] = '\0';

	return str;
}

char** cmd_getargv() {
	char* str = cmd_getl();
	char** argv = ( char** ) malloc( sizeof( char* ) );

	int i, b, as, size = 0;
	while ( str[ i ] ) {
		if ( str[ i ] == ' ' ) {
			char* cs = ( char * ) malloc( size * sizeof( char ) );
			strncpy( cs, str + b, size );

			argv[ as++ ] = cs;

			b = size + 1;
			size = 0;
		}
		else size++;

		i++;
	}

	char* cs = ( char * ) malloc( size * sizeof( char ) );
	strncpy( cs, str + b, size );
	argv[ as++ ] = cs;
	argv[ as ] = NULL;

	free( str );

	return argv;
}

