#include "all.h"

extern int set;

void StartGame() {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t**************행맨 게임**************");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t   ▶ 게임 시작 ◀");
	printf("\n\n\t\t\t\t\t\t\t\t      단어 추가");
	printf("\n\n\t\t\t\t\t\t\t\t        설 정\n");

}

void StartPlusword() {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t**************행맨 게임**************");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t      게임 시작");
	printf("\n\n\t\t\t\t\t\t\t\t   ▶ 단어 추가 ◀");
	printf("\n\n\t\t\t\t\t\t\t\t        설 정\n");

}

void StartOption() {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t**************행맨 게임**************");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t      게임 시작");
	printf("\n\n\t\t\t\t\t\t\t\t      단어 추가");
	printf("\n\n\t\t\t\t\t\t\t\t   ▶   설 정   ◀\n");

}

void Start() {
	int start = 0, n = 0;
	set = 0;
	StartGame();
	while (start != 13) {
		start = _getch();
		if (start == 80) {
			if (n == 0) {
				StartPlusword();
				n += 1;
				set = 1;
			}
			else if (n == 1) {
				StartOption();
				set = 2;
			}
		}
		else if (start == 72) {
			if (n == 0) {
				StartGame();
				set = 0;
			}
			else if (n == 1) {
				StartPlusword();
				n -= 1;
				set = 1;
			}
		}
	}
}