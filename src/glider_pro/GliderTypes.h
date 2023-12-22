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

typedef char Str255[256];
typedef char Str32[33];
typedef char Str31[32];
typedef char Str27[28];
typedef char Str15[16];

typedef struct
{
    Byte nothing[70];
} FSSpec;

#ifdef __cplusplus
}
#endif

#endif // GPRO_TYPES_H
