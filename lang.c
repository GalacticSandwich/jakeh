
#include <stdlib.h>

#include "lang.h"

char const* langName( lang_t lid )
{
    switch ( lid ) {
        case L_CLANG:
            return "C";
        case L_JAVA:
            return "Java";
        default:
            return NULL;
    }
}

char const* langExt( lang_t lid )
{
    switch ( lid ) {
        case L_CLANG:
            return ".c";
        case L_JAVA:
            return ".java";
        default:
            return NULL;
    }
}

char const* langHExt( lang_t lid )
{
    switch ( lid ) {
        case L_CLANG:
            return ".h";
        default:
            return NULL;
    }
}
