#ifndef GPRO_TYPES_H
#define GPRO_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t UInt32;
typedef  int32_t SInt32;
typedef  int16_t UInt16;
typedef  int16_t SInt16;
typedef  uint8_t UInt8;
typedef   int8_t SInt8;
typedef    UInt8 Byte;
typedef    SInt8 SignedByte;
typedef     Byte Boolean;

typedef struct
{
    SInt16 x;
    SInt16 y;
    SInt16 w;
    SInt16 h;
} Rect;

typedef struct
{
    SInt16 x;
    SInt16 y;
} Point;

typedef char  Str255[256];
typedef char  Str32[33];
typedef char  Str31[32];
typedef char  Str27[28];
typedef char  Str15[16];
typedef char* StringPtr;

typedef int OSErr; // For now OSError can stay.
typedef void* Ptr;

// Everything after this is are nothing.
typedef struct
{
    Byte nothing[70]; // The documentation does not describe this, so I am going to remove this.
} FSSpec;

typedef void* CGrafPtr;
typedef void* EventRecord;
typedef void* Handle;
typedef void* RgnHandle;
typedef void* WindowPtr;

#ifdef __cplusplus
}
#endif

#endif // GPRO_TYPES_H
