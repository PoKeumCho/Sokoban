#include <cstdio>
#include "gameController.h"

int main()
{
	int i;
	int stageNumber = 0;
	char input;

	printf("q: ����, h: ����, j: �Ʒ�, k: ��, l: ������\n");

	DrawStage(Stage[stageNumber]);
	printf("����� �Է� : ");
	input = getchar();
	while (input != 'q') {	

		if (input != '\n')
			getchar();			// '\n'(���๮��)�� �Է� ��Ʈ������ �����Ѵ�.
	
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

		printf("����� �Է� : ");
		input = getchar();
	}
	return 0;
}