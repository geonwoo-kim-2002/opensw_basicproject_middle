#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include "all.h"

extern int option, revival = 0;

void RevivalNum() {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t       설 정");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   ▶ 부활 횟수 ◀");
	printf("\n\n\t\t\t\t\t\t\t\t      단어 출력");
	printf("\n\n\t\t\t\t\t\t\t\t      게임 종료\n");
}

void Print() {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t       설 정");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t      부활 횟수");
	printf("\n\n\t\t\t\t\t\t\t\t   ▶ 단어 출력 ◀");
	printf("\n\n\t\t\t\t\t\t\t\t      게임 종료\n");
}

void Finish() {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t       설 정");
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t      부활 횟수");
	printf("\n\n\t\t\t\t\t\t\t\t      단어 출력");
	printf("\n\n\t\t\t\t\t\t\t\t   ▶ 게임 종료 ◀\n");
}

void printWords(int num) {
	char* buffer;
	int size, count = 0;

	FILE* al = fopen(textAlphabet(num), "r");
	fseek(al, 0, SEEK_END);
	size = ftell(al);
	buffer = (char*)malloc(size + 1);
	memset(buffer, 0, size + 1);
	fseek(al, 0, SEEK_SET);
	count = fread(buffer, size, 1, al);

	for (int i = 0;i < size / num;i++) {
		printf("\n\t\t\t\t\t\t\t\t  ");
		for (int i = 0;i < 9 - num;i++) {
			printf(" ");
		}
		for (int j = 0;j < num;j++) {
			printf("%c", *(buffer+i * num + j));
		}
	}
	printf("\n\n\t\t\t\t\t\t\t  계속하려면 아무 키나 누르십시오");
	getch();
}

void Revival(int num) {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t     ▲");
	printf("\n\n\t\t\t\t\t\t\t\t   부활 횟수  %d", num);
	printf("\n\n\t\t\t\t\t\t\t\t\t     ▼");
}


void Option() {
	int op = 0, num = 0, n = 0;
	option = 0;
	RevivalNum();
	while (op != 13) {
		op = _getch();
		if (op == 80) {
			if (n == 0) {
				Print();
				n += 1;
				option = 2;
			}
			else if (n == 1) {
				Finish();
				option = 1;
			}
		}
		else if (op == 72) {
			if (n == 0) {
				RevivalNum();
				option = 0;
			}
			else if (n == 1) {
				Print();
				n -= 1;
				option = 2;
			}
		}
	}

	op = 0;
	if (option == 0) {
		Revival(revival);
		while (op != 13) {
			op = _getch();
			if (op == 80) {
				if (revival > 0)
					revival -= 1;
				else
					revival = 0;
			}
			else if (op == 72) {
				if (revival < 3)
					revival += 1;
				else
					revival == 3;
			}
			Revival(revival);
		}
	}
	else if (option == 2) {
		while (1) {
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ");
			printf("출력할 단어들의 알파벳 수를 입력하시오 (3~9): ");
			scanf_s("%d", &num);
			getchar();
			if (num > 2 && num < 10)
				break;
			printf("\n\t\t\t\t\t\t\t     숫자를 잘못 입력하였습니다.");
			Sleep(500);
		}
		printWords(num);
	}
}