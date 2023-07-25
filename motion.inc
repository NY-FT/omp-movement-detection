#if defined _INC_MOTION
	#endinput
#endif
#define _INC_MOTION

/**
 * @header
 */

#define PLAYER_MOTION: \
    __TAG(PLAYER_MOTION):

enum PLAYER_MOTION:__PLAYER_MOTION
{
    PLAYER_MOTION_OTHER,
    PLAYER_MOTION_IDLE,
    PLAYER_MOTION_WALK,
    PLAYER_MOTION_RUN,
    PLAYER_MOTION_JUMP,
    PLAYER_MOTION_FALL
};

static stock PLAYER_MOTION:_@PLAYER_MOTION() { 
    return __PLAYER_MOTION; 
}

forward OnPlayerMotionStateChange(playerid, PLAYER_MOTION:newMotion, PLAYER_MOTION:oldMotion);

/**
 * @API
 */

stock PLAYER_MOTION:GetPlayerMotion(playerid) 
{
    static 
        KEY:keys, 
        KEY:ud, 
        KEY:lr
    ;

    GetPlayerKeys(playerid, keys, ud, lr);

    new
        index = GetPlayerAnimationIndex(playerid)
    ;

    if (index == 1180) {
        return (!!ud || !!lr) ? (keys & KEY_SPRINT) ? PLAYER_MOTION_RUN : PLAYER_MOTION_WALK : PLAYER_MOTION_IDLE;
    }

    if ((!!ud || !!lr) && (index == 1061 || index == 1062 || index == 1129 || index == 1133 || index == 1196 || index == 1231 || index == 1266)) {
        return (keys & KEY_SPRINT) ? PLAYER_MOTION_RUN : PLAYER_MOTION_WALK;
    }

    if (index == 1195 || index == 1197 || index == 1198) {
        return PLAYER_MOTION_JUMP;
    }

    if (index == 1130 || index == 1132) {
        return PLAYER_MOTION_FALL;
    }

    if (index == 1067 || index == 1189) {
        return PLAYER_MOTION_IDLE;
    }

    return PLAYER_MOTION_OTHER;
}

public OnPlayerUpdate(playerid)
{
    static
        PLAYER_MOTION:newMotion,
        PLAYER_MOTION:oldMotion
    ;

    if ((newMotion = GetPlayerMotion(playerid)) != PLAYER_MOTION_OTHER && newMotion != oldMotion) {
        if (CallLocalFunction("OnPlayerMotionStateChange", "iii", playerid, _:newMotion, _:oldMotion)) {
            oldMotion = newMotion;
        }
    }

    #if defined Motion_OnPlayerUpdate
        return Motion_OnPlayerUpdate(playerid);
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
    Motion_OnPlayerUpdate

#if defined Motion_OnPlayerUpdate
    forward Motion_OnPlayerUpdate(playerid);
#endif
