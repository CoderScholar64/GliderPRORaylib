#include "src/GliderTypes.h"
#include <stdio.h>

int main() {
    Str255 hello, what;

    snprintf( hello, 256, "What is that noise?" );
    snprintf( what, 256, "The text is %s %i\n", hello, sizeof(Str255) );

    printf( "%s", what );

    return 0;
}
