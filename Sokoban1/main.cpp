#include <cstdio>
#include "gameController.h"

int main()
{
	int i;
	int stageNumber = 0;
	char input;

	printf("q: 종료, h: 왼쪽, j: 아래, k: 위, l: 오른쪽\n");

	DrawStage(Stage[stageNumber]);
	printf("사용자 입력 : ");
	input = getchar();
	while (input != 'q') {	

		if (input != '\n')
			getchar();			// '\n'(개행문자)를 입력 스트림에서 제거한다.
	
		switch (input) {
		case 'h':
			Move(Stage[stageNumber], GetPlayerPosition(Stage[stageNumber]), LEFT);
			break;
		case 'j':
			Move(Stage[stageNumber], GetPlayerPosition(Stage[stageNumber]), DOWN);
			break;
		case 'k':
			Move(Stage[stageNumber], GetPlayerPosition(Stage[stageNumber]), UP);
			break;
		case 'l':
			Move(Stage[stageNumber], GetPlayerPosition(Stage[stageNumber]), RIGHT);
			break;
		}

		DrawStage(Stage[stageNumber]);

		printf("사용자 입력 : ");
		input = getchar();
	}
	return 0;
}