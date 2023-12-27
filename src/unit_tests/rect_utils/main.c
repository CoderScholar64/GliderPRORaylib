#include "RectUtils.h"

#include <stddef.h>
#include <stdio.h>

static int is_rect_equal( Rect *r0, Rect *r1, int bitfield ) {
    if( r0 == r1 ) {
        // Comparing both pointers would lead to a tautology problem.
        printf( "Okay in order for this to work you do not compare the same rect to eachother.\n");
        return 0;
    }
    if( r0 == NULL ) {
        if( (bitfield & 1) != 0 )
            printf( "Null is not allowed for r0!\n");
        return 0;
    }
    if( r1 == NULL ) {
        if( (bitfield & 1) != 0 )
            printf( "Null is not allowed for r1!\n");
        return 0;
    }
    
    int result = 1;
    
    if( r0->top != r1->top ) {
        if( (bitfield & 1) != 0 )
            printf( "r0->top != r1->top; r0->top = %i and r1->top = %i\n", r0->top, r1->top );
        result = 0;
    }
    if( r0->bottom != r1->bottom ) {
        if( (bitfield & 1) != 0 )
            printf( "r0->bottom != r1->bottom; r0->bottom = %i and r1->bottom = %i\n", r0->bottom, r1->bottom );
        result = 0;
    }
    if( r0->right != r1->right ) {
        if( (bitfield & 1) != 0 )
            printf( "r0->right != r1->right; r0->right = %i and r1->right = %i\n", r0->right, r1->right );
        result = 0;
    }
    if( r0->left != r1->left ) {
        if( (bitfield & 1) != 0 )
            printf( "r0->left != r1->left; r0->left = %i and r1->left = %i\n", r0->left, r1->left );
        result = 0;
    }
    
    if( result && (bitfield & 2) != 0 ) {
        printf( "The results are equal\n" );
    }
    
    return result;
}

int main() {
    // void NormalizeRect (Rect *theRect)
    
    {
        Rect normal_rect;
        
        normal_rect.top = 10;
        normal_rect.bottom = 40;
        normal_rect.left = 9;
        normal_rect.right = 80;
        
        Rect unnormal_rect;
        
        unnormal_rect.top    = normal_rect.bottom;
        unnormal_rect.bottom = normal_rect.top;
        unnormal_rect.left   = normal_rect.right;
        unnormal_rect.right  = normal_rect.left;
        
        NormalizeRect( &unnormal_rect );
        
        if( !is_rect_equal(&normal_rect, &unnormal_rect, 1) ) {
            printf( "Logical failure for NormalizeRect!\n");
            return 1;
        }
        
        Rect right_rect;
        
        right_rect.top    = normal_rect.top;
        right_rect.bottom = normal_rect.bottom;
        right_rect.left   = normal_rect.right;
        right_rect.right  = normal_rect.left;
        
        NormalizeRect( &right_rect );
        
        if( !is_rect_equal(&normal_rect, &right_rect, 1) ) {
            printf( "Logical failure for NormalizeRect Right side Problem!\n");
            return 1;
        }
        
        Rect top_rect;
        
        top_rect.top    = normal_rect.bottom;
        top_rect.bottom = normal_rect.top;
        top_rect.left   = normal_rect.left;
        top_rect.right  = normal_rect.right;
        
        NormalizeRect( &top_rect );
        
        if( !is_rect_equal(&normal_rect, &top_rect, 1) ) {
            printf( "Logical failure for NormalizeRect Top side Problem!\n");
            return 1;
        }
    }
    
    return 0;
}
