#if defined _INC_MOVEMENT
	#endinput
#endif
#define _INC_MOVEMENT

/**
 * @header
 */

#define PLAYER_MOVEMENT: \
    __TAG(PLAYER_MOVEMENT):

enum PLAYER_MOVEMENT:__PLAYER_MOVEMENT {
    PLAYER_MOVEMENT_OTHER,
    PLAYER_MOVEMENT_IDLE,
    PLAYER_MOVEMENT_WALK,
    PLAYER_MOVEMENT_RUN,
    PLAYER_MOVEMENT_JUMP,
    PLAYER_MOVEMENT_FALL
};

static stock PLAYER_MOVEMENT:_@PLAYER_MOTION() {
    return __PLAYER_MOVEMENT;
}

forward OnPlayerMovementStateChange(playerid, PLAYER_MOVEMENT:newMovement, PLAYER_MOVEMENT:oldMovement);

/**
 * @API
 */

stock PLAYER_MOVEMENT:GetPlayerMovement(playerid) {
    static
        KEY:k, ud, lr
    ;

    GetPlayerKeys(playerid, k, ud, lr);

    new
        index = GetPlayerAnimationIndex(playerid)
    ;

    if (index == 1180) {
        return (!!ud || !!lr) ? (k & KEY_SPRINT) ? PLAYER_MOVEMENT_RUN : PLAYER_MOVEMENT_WALK : PLAYER_MOVEMENT_IDLE;
    }

    if ((!!ud || !!lr) && (index == 1061 || index == 1062 || index == 1129 || index == 1133 || index == 1196 || index == 1231 || index == 1266)) {
        return (k & KEY_SPRINT) ? PLAYER_MOVEMENT_RUN : PLAYER_MOVEMENT_WALK;
    }

    if (index == 1195 || index == 1197 || index == 1198) {
        return PLAYER_MOVEMENT_JUMP;
    }

    if (index == 1130 || index == 1132) {
        return PLAYER_MOVEMENT_FALL;
    }

    if (index == 1067 || index == 1189) {
        return PLAYER_MOVEMENT_IDLE;
    }

    return PLAYER_MOVEMENT_OTHER;
}

public OnPlayerUpdate(playerid) {
    static
        PLAYER_MOVEMENT:newMovement,
        PLAYER_MOVEMENT:oldMovement
    ;

    if ((newMovement = GetPlayerMovement(playerid)) != PLAYER_MOVEMENT_OTHER && newMovement != oldMovement) {
        CallRemoteFunction(
            !"OnPlayerMovementStateChange",
            !"iii",
            playerid, _:newMovement, _:oldMovement
        );
        
        oldMovement = newMovement;
    }

    #if defined Movement_OnPlayerUpdate
        return Movement_OnPlayerUpdate(playerid);
    #else
        return 1;
    #endif
}

/**
 * @ALS
 */

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate \
    Movement_OnPlayerUpdate

#if defined Movement_OnPlayerUpdate
    forward Movement_OnPlayerUpdate(playerid);
#endif
