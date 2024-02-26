# Constants

```pwn
PLAYER_MOVEMENT_UNKNOWN
PLAYER_MOVEMENT_IDLE
PLAYER_MOVEMENT_NORMAL
PLAYER_MOVEMENT_WALK
PLAYER_MOVEMENT_RUN
PLAYER_MOVEMENT_JUMP
PLAYER_MOVEMENT_FALL
```

# Events

```pwn
forward OnPlayerMovementStateChange(playerid, PLAYER_MOVEMENT:newMovement, PLAYER_MOVEMENT:oldMovement)
```

# Natives

```pwn
native PLAYER_MOVEMENT:GetPlayerMovement(playerid);
```
