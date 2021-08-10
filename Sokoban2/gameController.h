#ifndef GAME_CONTROLLER_H_
#define GAME_CONTROLLER_H_

#include "stage.h"

typedef struct PosType {
	int x;	// row (��)
	int y;	// col (��)
} Pos;

enum MoveDirection {LEFT, DOWN, UP, RIGHT};

void DrawStage(char (*stage)[COL]);
Pos GetPlayerPosition(char (*stage)[COL]);
int Move(char (*stage)[COL], Pos srcPos, MoveDirection md);

#endif