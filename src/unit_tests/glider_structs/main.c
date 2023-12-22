#include "GliderStructs.h"

#include <stdio.h>

static int is_false( int answer, int expected, const char *const name ) {
    if( answer != expected ) {
        printf( "Problem with %s expected %i but got %i.\n", name, expected, answer );
        return 1;
    }
    return 0;
}

int main() {
    if( is_false( sizeof(blowerType), 10, "sizeof(blowerType)" ) )
        return 1;

    if( is_false( sizeof(furnitureType), 10, "sizeof(furnitureType)" ) )
        return 1;

    if( is_false( sizeof(bonusType), 10, "sizeof(bonusType)" ) )
        return 1;

    if( is_false( sizeof(transportType), 10, "sizeof(transportType)" ) )
        return 1;

    if( is_false( sizeof(switchType), 10, "sizeof(switchType)" ) )
        return 1;

    if( is_false( sizeof(lightType), 10, "sizeof(lightType)" ) )
        return 1;

    if( is_false( sizeof(applianceType), 10, "sizeof(applianceType)" ) )
        return 1;

    if( is_false( sizeof(enemyType), 10, "sizeof(enemyType)" ) )
        return 1;

    if( is_false( sizeof(clutterType), 10, "sizeof(clutterType)" ) )
        return 1;

    if( is_false( sizeof(objectType), 12, "sizeof(objectType)" ) )
        return 1;

    if( is_false( sizeof(scoresType), 292, "sizeof(scoresType)" ) )
        return 1;

    if( is_false( sizeof(gameType), 40, "sizeof(gameType)" ) )
        return 1;

    if( is_false( sizeof(savedRoom), 292, "sizeof(savedRoom)" ) )
        return 1;

    // TODO Figure out game2Type

    if( is_false( sizeof(roomType), 348, "sizeof(roomType)" ) )
        return 1;

    if( is_false( sizeof(houseType), 866, "sizeof(houseType)" ) )
        return 1;

    if( is_false( sizeof(game2Type), 114, "sizeof(game2Type)" ) )
        return 1;
    return 0;
}
