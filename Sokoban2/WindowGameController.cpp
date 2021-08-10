#include "WindowGameController.h"

char (*currentStage)[COL] = NULL;

HBITMAP hGameBit[BI];

void SetStage(int stageNumber)
{
	currentStage = Stage[stageNumber];
}

void LoadGameBitmap(HINSTANCE hInstance, int first)
{
	int i;
	for (i = 0; i < BI; i++) {
		hGameBit[i] = LoadBitmap(hInstance, MAKEINTRESOURCE(first + i));
	}
}

void DeleteGameBitmap()
{
	int i;
	for (i = 0; i < BI; i++) {
		DeleteObject(hGameBit[i]);
	}
}

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP oldBit;
	BITMAP bit;
	int bx, by;

	MemDC = CreateCompatibleDC(hdc);
	oldBit = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, oldBit);
	DeleteDC(MemDC);
}

void DrawScreen(HDC hdc)
{
	int i, j;
	BitmapIndex iBit;
	TCHAR Message[256];

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			switch (currentStage[i][j]) {
			case '#':
				iBit = WALL;
				break;
			case ' ':
				iBit = SPACE;
				break;
			case 'O':
				iBit = BOX;
				break;
			case 'o':
				iBit = INBOX;
				break;
			case '.':
				iBit = SLOT;
				break;
			case '@':
				iBit = PLAYER;
				break;
			}
			DrawBitmap(hdc, j*BW, i*BH, hGameBit[iBit]);
		}
	}
}

void MakeAction(HWND hWnd, MoveDirection md)
{
	RECT stageRect = {	/* 게임 영역 */
		0,				// left
		0,				// top
		COL*BW,			// right
		ROW*BH			// bottom
	};

	Move(currentStage, GetPlayerPosition(currentStage), md);
	InvalidateRect(hWnd, &stageRect, TRUE);
}