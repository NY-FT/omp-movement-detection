#include <open.mp>
#include <motion>

main(){}

public OnGameModeInit()
{
    UsePlayerPedAnims();

    return 1;
}

public OnPlayerMotionStateChange(playerid, PLAYER_MOTION:newMotion, PLAYER_MOTION:oldMotion)
{
    switch (newMotion) {
        case PLAYER_MOTION_IDLE: {
            return ApplyAnimation(playerid, "PED", "IDLE_GANG1", 4.1, false, false, false, false, 1, SYNC_ALL);
        }
        case PLAYER_MOTION_WALK: {
            return ApplyAnimation(playerid, "PED", "WALK_GANG1", 4.1, true, true, true, true, 1, SYNC_ALL);
        }
        case PLAYER_MOTION_RUN: {
            return ApplyAnimation(playerid, "PED", "RUN_GANG1", 4.1, true, true, true, true, 1, SYNC_ALL);
        }
    }

    return 1;
}
