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
		printf("�Է��� �ܾ��� ���ĺ� ���� �Է��Ͻÿ� (3~9): ");
		scanf_s("%d", &num);
		getchar();
		if (num > 2 && num < 10)
			break;
		printf("\n\t\t\t\t\t\t\t     ���ڸ� �߸� �Է��Ͽ����ϴ�.");
		Sleep(500);
	}
	word = (char*)calloc(num + 1, sizeof(char));
	printf("\n\t\t\t\t\t\t\t\t   �ܾ� �Է�: ");
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
			printf("\n\t\t\t\t\t\t            %s�� �̹� �ִ� �ܾ��Դϴ�.", word);
		}
		else {
			fputs(word, al);
			printf("\n\t\t\t\t\t\t         %s�� ���������� �߰��Ǿ����ϴ�.", word);
		}
		free(buffer);
		fclose(al);
	}
	else
		printf("\n\t\t\t\t\t      ���ĺ� ���� ���� �ʽ��ϴ�. �ܾ �߰����� �ʾҽ��ϴ�.");
	set = 0;
	Sleep(1000);
	free(word);
}