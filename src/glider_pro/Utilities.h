//============================================================================
//----------------------------------------------------------------------------
//                                Utilities.c
//----------------------------------------------------------------------------
//============================================================================

#ifndef GPRO_UTILITIES_H
#define GPRO_UTILITIES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <QDOffscreen.h>

OSErr CreateOffScreenGWorld (GWorldPtr *theGWorld, Rect *bounds, short depth);

#ifdef __cplusplus
}
#endif

#endif // GPRO_UTILITIES_H
