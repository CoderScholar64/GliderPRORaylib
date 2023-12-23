#include "Externs.h"

#include <stdio.h>
#include <string.h>

static int PasStringCopyTest( const char *const name, StringPtr source, int blurt ) {
    Str255 destin = "";
    
    PasStringCopy( source, destin );
    
    int compare = strcmp(source, destin);
    
    if( compare != 0 ) {
        if( (blurt & 1) != 0 )
            printf( "\"%s\" failed with %i and %s.\n", name, compare, destin );
        return 1;
    }
    if( (blurt & 2) != 0 )
        printf( "\"%s\" succeeded with %i.\n", name, compare );
    return 0;
}

static int WhichStringFirstTest( StringPtr str1, StringPtr str2, int expected ) {
    short compare = WhichStringFirst(str1, str2);
    
    if( compare != expected ) {
        printf( "WhichStringFirst Failed \"%s\" and \"%s\" failed with %i. Expected %i\n", str1, str2, compare, expected );
        return 1;
    }
    return 0;
}

static int PasStringCopyNumTest( StringPtr source, short dst_limit, StringPtr expected ) {
    Str255 destin = "";
    
    PasStringCopyNum( source, destin, dst_limit );
    
    int compare = strcmp(destin, expected);
    
    if( compare != 0 ) {
        printf( "\"%s\" copy with limit %i did not match \"%s\" but is instead \"%s\".\n", source, dst_limit, expected, destin );
        return 1;
    }
    
    return 0;
}

int main() {
    if( PasStringCopyTest("PasStringCopy case 1", "Random Phrase", 1) )
        return 1;
    
    if( PasStringCopyTest("PasStringCopy case 2", "R", 1) )
        return 1;
    
    if( PasStringCopyTest("PasStringCopy case 3", "", 1) )
        return 1;
    
    // The buffer PasStringCopyTest. Checks for same size case.
    {
        char buffer[256];
        
        memset( buffer, 'A', sizeof(buffer) );
        buffer[255] = '\0';
        
        if( PasStringCopyTest("PasStringCopy case 4", buffer, 1) )
            return 1;
    }
    
    // The buffer PasStringCopyTest. Checks for overflow case
    {
        char buffer[512];
        
        memset( buffer, 'A', sizeof(buffer) );
        buffer[511] = '\0';
        
        if( !PasStringCopyTest("PasStringCopy case 5", buffer, 2) )
            return 1;
    }
    
    if( WhichStringFirstTest("", "", 0) )
        return 1;
    
    if( WhichStringFirstTest("A", "", 1) )
        return 1;
    
    if( WhichStringFirstTest("", "A", 2) )
        return 1;
    
    if( WhichStringFirstTest("A", "A", 0) )
        return 1;
    
    if( WhichStringFirstTest("A", "B", 2) )
        return 1;
    
    if( WhichStringFirstTest("B", "A", 1) )
        return 1;
    
    if( WhichStringFirstTest("CASE", "case", 0) )
        return 1;
    
    if( WhichStringFirstTest("CASE", "cas", 1) )
        return 1;
    
    if( PasStringCopyNumTest( "Overflow", 4, "Over" ) )
        return 1;
    
    if( PasStringCopyNumTest( "Ov", 4, "Ov" ) )
        return 1;
    
    if( PasStringCopyNumTest( "Over", 4, "Over" ) )
        return 1;
    
    return 0;
}
