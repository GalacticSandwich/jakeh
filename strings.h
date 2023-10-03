
#ifndef STRINGS_H
#define STRINGS_H

typedef struct {
    int len;
    char* chars;
} string;

int str_len( string const* str );

char str_char( string const* str, int n );

string* str_alloc( int len );

// string* str_allocl( char const* lit );

// void str_nalloc( string* str, int nlen );

// void str_nallocl( string* str, char const* lit );

// void str_concat( string* dest, string const* src );

// void str_concatl( string* str, char const* lit );

void str_free( string* str );

#endif
