#include "all.h"

int set = 0, number, option;

int main() {
	system("mode con:cols=150 lines=40");
	while (option != 1) {
		Start();
		if (set == 0)
			Game();
		else if (set == 1)
			Plusword();
		else if (set == 2)
			Option();
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t");
	printf("게임이 종료되었습니다.");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}