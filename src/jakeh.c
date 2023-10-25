
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "cmdstring.h"

#define CURRWD_MAXL 2048
#define CURROBJN_MAXL 256

static void eval( char** cmd ) {

}

int main( int argc, char** argv ) {
	// the current command
	char* ccom;
	// the current working directory
	char cwd[ CURRWD_MAXL ];
	// the name of the current object
	char cobjn[ CURROBJN_MAXL ];
	// running flag
	bool running = true;

	while ( running ) {
		char** cmd = cmd_getargv();
		eval( cmd );
	}

	return 0;
}

