#include <open.mp>

#include "movement"

main(){}

public OnGameModeInit() {
    // important
    UsePlayerPedAnims();

    return 1;
}

public OnPlayerMovementStateChange(playerid, PLAYER_MOVEMENT:newMovement, PLAYER_MOVEMENT:oldMovement) {
    switch (newMovement) {
        case PLAYER_MOVEMENT_IDLE: {
            return ApplyAnimation(playerid, "PED", "IDLE_GANG1", 4.1, false, false, false, false, 1, SYNC_ALL);
        }
        case PLAYER_MOVEMENT_WALK: { // Keys `W-A-S-D`
            return ApplyAnimation(playerid, "PED", "WALK_GANG1", 4.1, true, true, true, true, 1, SYNC_ALL);
        }
        case PLAYER_MOVEMENT_RUN: { // Keys `W-A-S-D` + `SPACE`
            return ApplyAnimation(playerid, "PED", "RUN_GANG1", 4.1, true, true, true, true, 1, SYNC_ALL);
        }
    }

    return 1;
}
