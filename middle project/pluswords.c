#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include "all.h"

int set;

void Plusword() {
	int num = 0, size, count, a;
	char* word;
	char* buffer;
	while (1) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ");
		printf("입력할 단어의 알파벳 수를 입력하시오 (3~9): ");
		scanf_s("%d", &num);
		getchar();
		if (num > 2 && num < 10)
			break;
		printf("\n\t\t\t\t\t\t\t     숫자를 잘못 입력하였습니다.");
		Sleep(500);
	}
	word = (char*)calloc(num + 1, sizeof(char));
	printf("\n\t\t\t\t\t\t\t\t   단어 입력: ");
	scanf_s("%s", word, sizeof(char) * (num + 1));
	getchar();
	if (word[num - 1] != NULL && word[num] == NULL) {
		FILE* al = fopen(textAlphabet(num), "r+");
		fseek(al, 0, SEEK_END);
		size = ftell(al);
		buffer = (char*)malloc(size + 1);
		memset(buffer, 0, size + 1);
		fseek(al, 0, SEEK_SET);
		count = fread(buffer, size, 1, al);

		count = 0;
		for (int i = 0;i < size / num;i++) {
			for (int j = 0;j < num;j++) {
				if (buffer[(num * i) + j] == word[j])
					count += 1;
			}
			if (count == num)
				break;
			count = 0;
		}
		if (count == num) {
			printf("\n\t\t\t\t\t\t            %s는 이미 있는 단어입니다.", word);
		}
		else {
			fputs(word, al);
			printf("\n\t\t\t\t\t\t         %s가 성공적으로 추가되었습니다.", word);
		}
		free(buffer);
		fclose(al);
	}
	else
		printf("\n\t\t\t\t\t      알파벳 수가 맞지 않습니다. 단어가 추가되지 않았습니다.");
	set = 0;
	Sleep(1000);
	free(word);
}