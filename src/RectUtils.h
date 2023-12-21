//============================================================================
//----------------------------------------------------------------------------
//                                 RectUtils.h
//----------------------------------------------------------------------------
//============================================================================

#ifndef GPRO_RECT_UTILS_H
#define GPRO_RECT_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <Quickdraw.h>

void FrameWHRect (short, short, short, short);
void NormalizeRect (Rect *);
void ZeroRectCorner (Rect *);
void CenterRectOnPoint (Rect *, Point);
short HalfRectWide (Rect *);
short HalfRectTall (Rect *);
short RectWide (Rect *);
short RectTall (Rect *);
void GlobalToLocalRect (Rect *);
void LocalToGlobalRect (Rect *);
void CenterRectInRect (Rect *, Rect *);
void HOffsetRect (Rect *, short);
void VOffsetRect (Rect *, short);
Boolean IsRectLeftOfRect (Rect *, Rect *);
void QOffsetRect (Rect *, short, short);
void QSetRect (Rect *, short, short, short, short);
Boolean ForceRectInRect (Rect *, Rect *);
void QUnionSimilarRect (Rect *, Rect *, Rect *);
void FrameRectSansCorners (Rect *);
void SetEraseRect (short, short, short, short);

#ifdef __cplusplus
}
#endif

#endif // GPRO_RECT_UTILS_H
