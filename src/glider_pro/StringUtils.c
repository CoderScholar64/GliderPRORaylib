
//============================================================================
//----------------------------------------------------------------------------
//                                StringUtils.c
//----------------------------------------------------------------------------
//============================================================================
// #include <TextUtils.h>

#include "Externs.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

//==============================================================  Functions
//--------------------------------------------------------------  ToUpperCase
// This is to convert an ASCII string to upper case.
StringPtr ToUpperCase(StringPtr convert)
{
    for( StringPtr cur = convert; *cur != '\0'; cur++ ) {
        *cur = toupper(*cur);
    }
    return convert;
}

//==============================================================  Functions
//--------------------------------------------------------------  PasStringCopy
// Given a source string and storage for a second, this function
// copies from one to the other. It was recreated for C style strings.
void PasStringCopy (StringPtr src, StringPtr dst)
{
    // TODO Depreciate this function. Replace with strncpy not strcpy.
    strcpy( dst, src );
}

//--------------------------------------------------------------  WhichStringFirst
// This is a sorting function that handles two Pascal strings.  It
// will return a 1 to indicate the 1st string is "greater", a 2 to
// indicate the 2nd was greater and a 0 to indicate that the strings
// are equal. It was recreated for C style strings.
short WhichStringFirst (StringPtr p1, StringPtr p2)
{
    // TODO Replace this with a better/faster implementation.
    Str255 str1;
    Str255 str2;
    
    strncpy(str1, p1, sizeof(Str255) / sizeof(p1[0]));
    ToUpperCase(str1);
    strncpy(str2, p2, sizeof(Str255) / sizeof(p2[0]));
    ToUpperCase(str2);
    
    const int comparison = strncmp(str1, str2, sizeof(Str255) / sizeof(p1[0]));
    
    if( comparison == 0 )
        return 0;
    else if( comparison > 0 )
        return 1;
    else
        return 2;
}

//--------------------------------------------------------------  PasStringCopyNum
// This function copies a specified number of characters from one
// *C* string to another. It was recreated for C style strings.
void PasStringCopyNum (StringPtr src, StringPtr dst, short charsToCopy)
{
    // TODO Depreciate this function.
    strncpy( dst, src, charsToCopy );
}

//--------------------------------------------------------------  PasStringConcat
// This function concatenates the second Pascal string to the end of
// the first Pascal string.
void PasStringConcat (StringPtr p1, StringPtr p2)
{
    snprintf( p1, sizeof(Str255) / sizeof(p1[0]), "%s%s", p1, p2 );
}

//--------------------------------------------------------------  GetLineOfText
// This function walks through a source string and looks for an
// entire line of text.  A "line" of text is assumed to be bounded
// by carriage returns.  The index variable indicates which line
// is sought.
void GetLineOfText (StringPtr srcStr, short index, StringPtr textLine)
{
    static const char RETURN_KEY_STR[] = {kReturnKeyASCII, '\0'};
    
    char * lastPtr = srcStr;
    char * currentPtr = srcStr;
    short current_index = 0;
    
    PasStringCopy("", textLine); // kReturnKeyASCII
    
    if(srcStr[0] == '\0')
        return;
    
    do {
        lastPtr = currentPtr;
        currentPtr = strpbrk( currentPtr, RETURN_KEY_STR );
        
        current_index++;
        
        if(currentPtr == NULL)
            break;
        
        currentPtr++;
    } while(current_index - 1 < index);
    
    if(current_index - 1 == index) {
        strncpy(textLine, lastPtr, currentPtr - lastPtr);
        textLine[currentPtr - lastPtr] = '\0';
    }
}
//--------------------------------------------------------------  WrapText
// Given a string and the maximum number of characters to put on
// one line, this function goes through and inserts carriage returns
// in order to ensure that no line of text exceeds maxChars.
void WrapText (StringPtr string255, short maxChars)
{
    Str255 pageMemory;
    StringPtr pageMemPtr = pageMemory;
    StringPtr string255Ptr = string255;
    short spacePos;
    bool notFinished = true;
    
    memset(pageMemory, 0, sizeof(Str255));
    
    while( notFinished ) {
        spacePos = 0;
        
        // If hit the kReturnKeyASCII cancel?, If hit kSpaceBarASCII then record it.
        for(short i = 0; i < maxChars; i++) {
            if(string255Ptr[i] == '\0') {
                notFinished = false;
                strncpy(pageMemPtr, string255Ptr, i);
                break;
            }
            else if(string255Ptr[i] == kReturnKeyASCII) {
                spacePos = -1;
                strncpy(pageMemPtr, string255Ptr, i);
                pageMemPtr += i;
                string255Ptr += i;
                break;
            }
            else if(string255Ptr[i] == kSpaceBarASCII)
                spacePos = i;
        }
        
        if( !notFinished && spacePos != -1 ) {
            if(spacePos == 0) {
                strncpy(pageMemPtr, string255Ptr, maxChars);
                pageMemPtr[maxChars] = kReturnKeyASCII;
                pageMemPtr += maxChars;
                string255Ptr += maxChars;
            }
            else {
                strncpy(pageMemPtr, string255Ptr, spacePos);
                pageMemPtr[spacePos] = kReturnKeyASCII;
                pageMemPtr += spacePos;
                string255Ptr += spacePos;
            }
        }
    }
    memcpy(string255, pageMemory, sizeof(Str255) / sizeof(pageMemory[0]));
}

//--------------------------------------------------------------  GetFirstWordOfString
// Walks a string looking for a space (denoting first word of string).
void GetFirstWordOfString (StringPtr stringIn, StringPtr stringOut)
{
    int in = 0;
    
    PasStringCopy("", stringOut); // Clear stringOut
    
    // Skip space. Cancel if null is found.
    for(; stringIn[in] == kSpaceBarASCII; in++) {
        if(stringIn[in] != '\0')
            return; // A string consiting of spaces has no first word.
    }
    
    // Read Word to Stringout until either space or null.
    for(int out = 0;
        stringIn[in] != kSpaceBarASCII && stringIn[in] != '\0' &&
        out < sizeof(Str255) / sizeof(stringIn[0]);
        out++, in++)
    {
        stringOut[out] = stringIn[in];
    }
}
//--------------------------------------------------------------  CollapseStringToWidth
// Given a string and a maximum width (in pixels), this function…
// calculates how wide the text would be drawn with the current…
// font.  If the text would exceed our width limit, characters…
// are dropped off the end of the string and "…" appended.
void CollapseStringToWidth (StringPtr theStr, short wide)
{
    /* TODO Rewrite behavior for file and font handling.
    short       dotsWide;
    Boolean     tooWide;
    
    dotsWide = StringWidth(".");
    tooWide = StringWidth(theStr) > wide;
    while (tooWide)
    {
        theStr[0]--;
        tooWide = ((StringWidth(theStr) + dotsWide) > wide);
        if (!tooWide)
            PasStringConcat(theStr, ".");
    }
     */
    PasStringCopy("Missing CollapseStringToWidth", theStr);
}
//--------------------------------------------------------------  GetChooserName
// This function extracts the user name stored away by the Chooser.
void GetChooserName (StringPtr thisName)
{
    /* TODO Rewrite behavior for file and font handling.
    #define     kChooserStringID    -16096
    Handle      theNameHandle;
    Byte        oldState;
    
    theNameHandle = (Handle)GetString(kChooserStringID);
    if (theNameHandle != nil) {
        oldState = HGetState(theNameHandle);
        HLock(theNameHandle);
        PasStringCopy((StringPtr)*theNameHandle, thisName);
        HSetState(theNameHandle, oldState);
        }
    else
        thisName[0] = 0;
     */
    PasStringCopy("Missing GetChooserName", thisName);
}
//--------------------------------------------------------------  GetLocalizedString
StringPtr GetLocalizedString (short index, StringPtr theString)
{
    /* TODO Rewrite behavior for file and font handling.
    #define     kLocalizedStringsID     150
    
    GetIndString(theString, kLocalizedStringsID, index);
    return (theString);
     */
    PasStringCopy("Missing GetLocalizedString", theString);
    return theString;
}
