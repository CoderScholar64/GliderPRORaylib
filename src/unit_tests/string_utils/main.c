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

static int PasStringConcatTest( StringPtr str1, StringPtr str2, StringPtr expected ) {
    Str255 destin;
    
    PasStringCopy(str1, destin);
    
    PasStringConcat(destin, str2);
    
    int compare = strcmp(destin, expected);
    
    if( compare != 0 ) {
        printf( "PasStringConcat Failed \"%s\" and \"%s\" did not combine to \"%s\" but \"%s\".\n", str1, str2, expected, destin );
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
    
    if( PasStringConcatTest( "Game", "Over", "GameOver" ) )
        return 1;
    
    if( PasStringConcatTest( "GameGame", "OverOverOver", "GameGameOverOverOver" ) )
        return 1;

    // GetLineOfText Tests

    // Empty tests
    {
        Str255 all_the_text[] = {
            "",
            "\x0D",
            "\x0D\x0D",
        };
        Str255 result;

        for(int case_index = 0; case_index < sizeof(all_the_text) / sizeof(all_the_text[0]); case_index++) {
            GetLineOfText(all_the_text[case_index], 0, result);

            int compare = strcmp(result, "");

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", 0, "", result);
                printf( "  Used format %i in empty test.\n", case_index);
                return 1;
            }

            // Overflow case
            GetLineOfText(all_the_text[case_index], 1, result);
            compare = strcmp(result, "");

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", 1, "", result);
                printf( "  Used format %i in empty test.\n", case_index);
                return 1;
            }

            // Underflow case
            GetLineOfText(all_the_text[case_index], -1, result);
            compare = strcmp(result, "");

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", -1, "", result);
                printf( "  Used format %i in empty test.\n", case_index);
                return 1;
            }
        }
    }

    // Single tests
    {
        Str255 formats[] = {
            "%s",
            "\x0D%s",
            "\x0D\x0D%s",
            "%s\x0D",
            "%s\x0D\x0D",
            "\x0D%s\x0D",
            "\x0D\x0D%s\x0D\x0D"
        };
        Str255 line = "Only one line";
        Str255 all_the_text;
        Str255 result;

        for(int case_index = 0; case_index < sizeof(formats) / sizeof(formats[0]); case_index++) {
            snprintf(all_the_text, sizeof(all_the_text) / sizeof(all_the_text[0]), formats[case_index], line);

            GetLineOfText(all_the_text, 0, result);
            int compare = strcmp(result, line);

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", 0, line, result);
                printf( "  Used format %i single test.\n", case_index);
                return 1;
            }

            // Overflow test
            GetLineOfText(all_the_text, 1, result);
            compare = strcmp(result, "");

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", 1, "", result);
                printf( "  Used format %i single test.\n", case_index);
                return 1;
            }

            // Underflow case
            GetLineOfText(all_the_text, -1, result);
            compare = strcmp(result, "");

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", -1, "", result);
                printf( "  Used format %i single test.\n", case_index);
                return 1;
            }
        }
    }

    // Triple tests
    {
        Str255 formats[] = {
            "%s\x0D%s\x0D%s",
            "\x0D%s\x0D%s\x0D%s",
            "%s\x0D\x0D\x0D%s\x0D%s",
            "%s\x0D\x0D\x0D%s\x0D%s\x0D\x0D"
        };
        Str255 lines[3] = {"What is at Line 0?", "Number 1!", "This is the second line?"};
        Str255 all_the_text;
        Str255 result;

        for(int case_index = 0; case_index < sizeof(formats) / sizeof(formats[0]); case_index++) {
            snprintf(all_the_text, sizeof(all_the_text) / sizeof(all_the_text[0]), formats[case_index], lines[0], lines[1], lines[2]);

            GetLineOfText(all_the_text, 0, result);
            int compare = strcmp(result, lines[0]);

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", 0, lines[0], result);
                printf( "  Used format %i.\n", case_index);
                return 1;
            }

            GetLineOfText(all_the_text, 1, result);
            compare = strcmp(result, lines[1]);

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", 1, lines[1], result);
                printf( "  Used format %i.\n", case_index);
                return 1;
            }

            GetLineOfText(all_the_text, 2, result);
            compare = strcmp(result, lines[2]);

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", 2, lines[2], result);
                printf( "  Used format %i.\n", case_index);
                return 1;
            }

            // Overflow case 1
            GetLineOfText(all_the_text, 4, result);
            compare = strcmp(result, "");

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", 4, "", result);
                printf( "  Used format %i.\n", case_index);
                return 1;
            }

            // Overflow case 2
            GetLineOfText(all_the_text, 5, result);
            compare = strcmp(result, "");

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", 5, "", result);
                printf( "  Used format %i.\n", case_index);
                return 1;
            }

            // Underflow case
            GetLineOfText(all_the_text, -1, result);
            compare = strcmp(result, "");

            if( compare != 0 ) {
                printf( "GetLineOfText Failed for line %i for text \"%s\" got \"%s\" instead.\n", -1, "", result);
                printf( "  Used format %i.\n", case_index);
                return 1;
            }
        }
    }
    return 0;
}
