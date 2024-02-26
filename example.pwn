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
            SendClientMessage(playerid, -1, "Keys `KEY_NONE` Idle");
            ApplyAnimation(playerid, "PED", "IDLE_GANG1", 4.1, false, false, false, false, 1, SYNC_ALL);
        }

        case PLAYER_MOVEMENT_NORMAL: {
            SendClientMessage(playerid, -1, "Keys `W-A-S-D`");
        }

        case PLAYER_MOVEMENT_WALK: {
            SendClientMessage(playerid, -1, "Keys `W-A-S-D` + `LALT`");
            ApplyAnimation(playerid, "PED", "WALK_GANG1", 4.1, true, true, true, true, 1, SYNC_ALL);
        }

        case PLAYER_MOVEMENT_RUN: {
            SendClientMessage(playerid, -1, "Keys `W-A-S-D` + `SPACE`");
            ApplyAnimation(playerid, "PED", "RUN_GANG1", 4.1, true, true, true, true, 1, SYNC_ALL);
        }
    }

    return 1;
}
