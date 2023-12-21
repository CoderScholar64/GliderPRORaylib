//============================================================================
//----------------------------------------------------------------------------
//                                  Marquee.h
//----------------------------------------------------------------------------
//============================================================================

#ifndef GPRO_MARQUEE_H
#define GPRO_MARQUEE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <Quickdraw.h>
typedef struct
{
    Pattern     pats[kNumMarqueePats];
    Rect        bounds, handle;
    short       index, direction, dist;
    Boolean     active, paused, handled;
} marquee;
extern marquee      theMarquee;

#ifdef __cplusplus
}
#endif

#endif // GPRO_MARQUEE_H
