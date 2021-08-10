#include <stdio.h>
#include "gameController.h"

void DrawStage(char (*stage)[COL])
{
	int i;
	for (i = 0; i < 18; i++) {
		printf("%s\n", stage[i]);
	}
}

Pos GetPlayerPosition(char (*stage)[COL])
{
	int i, j;
	Pos playerPos = {-1, -1};
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			if (stage[i][j] == '@') {
				playerPos.x = i;
				playerPos.y = j;
				return playerPos;
			}
		}
	}
	printf("[ERROR] return invalid Pos. GetPlayerPosition()\n");
	return playerPos;
}

// 움직인 경우 참(1)을 반환하고, 움직일 수 없는 경우 거짓(0)을 반환한다.
int Move(char (*stage)[COL], Pos srcPos, MoveDirection md)
{
	int ret = 0;
	Pos destPos;
	char temp;

	switch (md) {
	case LEFT:
		destPos.x = srcPos.x;
		destPos.y = srcPos.y - 1;
		break;
	case DOWN:
		destPos.x = srcPos.x + 1;
		destPos.y = srcPos.y;
		break;
	case UP:
		destPos.x = srcPos.x - 1;
		destPos.y = srcPos.y;
		break;
	case RIGHT:
		destPos.x = srcPos.x;
		destPos.y = srcPos.y + 1;
		break;
	default:
		break;
	}

	// 스테이지 경계를 설정한다.
	if ( (destPos.x < 0 || destPos.x > ROW-1) ||
		(destPos.y < 0 || destPos.y > COL-1) ) {
		return ret;
	}

/*
#define syntaxCheck(STR)	printf("'%c'와 '%c'를"STR"\n",\
							stage[srcPos.x][srcPos.y], stage[destPos.x][destPos.y])
*/

	switch (stage[destPos.x][destPos.y])
	{
	case '#':
		break;
	case 'o':
		Move(stage, destPos, md);
		break;
	case ' ':
		temp = stage[srcPos.x][srcPos.y];
		stage[srcPos.x][srcPos.y] = stage[destPos.x][destPos.y];
		stage[destPos.x][destPos.y] = temp;
		ret = 1;
		break;
	case 'O':
		if (Move(stage, destPos, md) == 1) {
			temp = stage[srcPos.x][srcPos.y];
			stage[srcPos.x][srcPos.y] = stage[destPos.x][destPos.y];
			stage[destPos.x][destPos.y] = temp;
			ret = 1;
		}
		break;
	case '.':
		if (stage[srcPos.x][srcPos.y] == 'O') {
			stage[destPos.x][destPos.y] = 'o';
			stage[srcPos.x][srcPos.y] = ' ';
			ret = 1;
		}
		else if (stage[srcPos.x][srcPos.y] == 'o') {
			stage[destPos.x][destPos.y] = 'o';
			stage[srcPos.x][srcPos.y] = '.';
			ret = 1;
		}
		break;
	}

	return ret;
}