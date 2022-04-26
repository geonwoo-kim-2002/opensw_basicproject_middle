#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include "all.h"

int number, set, revival;

const char* textAlphabet(int num) {
	if (num == 3)
		return "3alphabet.txt";
	else if (num == 4)
		return "4alphabet.txt";
	else if (num == 5)
		return "5alphabet.txt";
	else if (num == 6)
		return "6alphabet.txt";
	else if (num == 7)
		return "7alphabet.txt";
	else if (num == 8)
		return "8alphabet.txt";
	else if (num == 9)
		return "9alphabet.txt";
}

void Game() {
	srand((unsigned)time(NULL));
	char* buffer;
	char* word;
	char* ans;
	int size, count = 0, a, life = 6, re = revival;
	char s;

	selectSpelling();

	ans = (char*)calloc(number + 1, sizeof(char));
	for (int i = 0;i < number;i++) {
		ans[i] = '_';
	}

	FILE* al = fopen(textAlphabet(number), "r");
	fseek(al, 0, SEEK_END);
	size = ftell(al);
	buffer = (char*)malloc(size + 1);
	memset(buffer, 0, size + 1);
	fseek(al, 0, SEEK_SET);
	count = fread(buffer, size, 1, al);

	a = (rand() % (size / number)) * number;
	word = (char*)calloc(number + 1, sizeof(char));
	for (int i = 0;i < number;i++) {
		word[i] = buffer[a + i];
	}

	while (1) {
		count = 0;
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ");

		for (int i = 0;i < 9-number;i++) {
			printf(" ");
		}

		for (int i = 0;i < number;i++) {
			printf("%c ", ans[i]);
		}

		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t      목숨 X %d", life);
		printf("\n\n\t\t\t\t\t\t\t    알파벳을 입력하시오 (Enter): ");

		scanf("%c", &s);
		getchar();
		if (s < 97 || s>122) {
			printf("\n\n\t\t\t\t\t\t\t\t  잘못 입력하였습니다.\n");
			Sleep(1000);
			continue;
		}

		for (int i = 0;i < number;i++) {
			if (word[i] == s) {
				ans[i] = s;
				count += 1;
			}
		}

		if (count == 0) {
			life -= 1;
			printf("\n\n\t\t\t\t\t\t\t\t      틀렸습니다.\n");
			Sleep(1000);
		}

		if (strcmp(word, ans) == 0) {
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\n\t\t\t\t\t\t\t          ");
			for (int i = 0;i < 9 - number;i++) {
				printf(" ");
			}
			for (int i = 0;i < number;i++) {
				printf("%c ", ans[i]);
			}
			printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t        ******************** 축하합니다!! ********************\n");
			break;
		}
		if (life == 0) {
			if (re > 0) {
				system("cls");
				re -= 1;
				life = 6;
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t^부활^");
				printf("\n\n\n\n\t\t\t\t\t\t\t\t   남은 부활 횟수: %d\n", re);
				Sleep(1000);
			}
			else {
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       ******************** 실패하였습니다 ********************");
				printf("\n\n\t\t\t\t\t\t\t\t");
				for (int i = 0;i < 9 - number;i++) {
					printf(" ");
				}
				printf("정답: %s\n", word);
				break;
			}
		}
	}

	fclose(al);
	free(buffer);
	free(ans);
	free(word);
	Sleep(1000);
}
