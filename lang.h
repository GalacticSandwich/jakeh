
typedef enum {
    L_NULL,
    L_CLANG,
    L_JAVA
} lang_t;

char const* langName( lang_t lid );

char const* langExt( lang_t lid );

char const* langHExt( lang_t lid );
