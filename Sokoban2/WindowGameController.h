#ifndef WINDOW_GAME_CONTROLLER_H_
#define WINDOW_GAME_CONTROLLER_H_

#include <Windows.h>
#include "gameController.h"

#define BW	32	// Bitmap Width
#define BH	32	// Bitmap Height

#define BI	6	// Bitmap Index count
enum BitmapIndex { WALL, SPACE, BOX, INBOX, SLOT, PLAYER };

// 현재 스테이지를 가리키는 포인터 변수
extern char (*currentStage)[COL];

// 현재 스테이지를 설정한다.
void SetStage(int stageNumber);

// 게임화면에 사용될 비트맵
void LoadGameBitmap(HINSTANCE hInstance, int first);
void DeleteGameBitmap();
void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit);

// 게임화면을 그린다.
void DrawScreen(HDC hdc);

void MakeAction(HWND hWnd, MoveDirection md);

#endif