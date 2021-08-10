#ifndef WINDOW_GAME_CONTROLLER_H_
#define WINDOW_GAME_CONTROLLER_H_

#include <Windows.h>
#include "gameController.h"

#define BW	32	// Bitmap Width
#define BH	32	// Bitmap Height

#define BI	6	// Bitmap Index count
enum BitmapIndex { WALL, SPACE, BOX, INBOX, SLOT, PLAYER };

// ���� ���������� ����Ű�� ������ ����
extern char (*currentStage)[COL];

// ���� ���������� �����Ѵ�.
void SetStage(int stageNumber);

// ����ȭ�鿡 ���� ��Ʈ��
void LoadGameBitmap(HINSTANCE hInstance, int first);
void DeleteGameBitmap();
void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit);

// ����ȭ���� �׸���.
void DrawScreen(HDC hdc);

void MakeAction(HWND hWnd, MoveDirection md);

#endif