#include "GliderTypes.h"

#include <stdio.h>

typedef struct {
    Str255 hello;
    Str255 other;
} StorageTest;

static int is_false( int answer, int expected, const char *const name ) {
    if( answer != expected ) {
        printf( "Problem with %s expected %i but got %i.\n", name, expected, answer );
        return 1;
    }
    return 0;
}

int main() {
    {
        Str255 value;

        if( is_false( sizeof(StorageTest), 512, "sizeof(StorageTest)" ) )
            return 1;

        if( is_false( sizeof(Str255), 256, "sizeof(Str255)" ) )
            return 1;

        if( is_false( sizeof(value[0]), 1, "sizeof(Str255[0])" ) )
            return 1;

        if( is_false( sizeof(&value), sizeof(char*), "sizeof(&Str255)" ) )
            return 1;
    }

    if( is_false( sizeof(Rect), 8, "sizeof(Rect)" ) )
        return 1;

    if( is_false( sizeof(Point), 4, "sizeof(Point)" ) )
        return 1;

    return 0;
}
