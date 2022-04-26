#include "all.h"

extern int number = 3;

void spelling(int num) {
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t     ¡ã");
	printf("\n\n\t\t\t\t\t\t\t\t   ¾ËÆÄºª ¼ö  %d",num);
	printf("\n\n\t\t\t\t\t\t\t\t\t     ¡å");
}

void selectSpelling() {
	int n = 0;
	spelling(number);
	while (n != 13) {
		n = _getch();
		if (n == 72) {
			if (number < 9) {
				number += 1;
				spelling(number);
			}
			else {
				number = 9;
				spelling(number);
			}
		}
		else if (n == 80) {
			if (number > 3) {
				number -= 1;
				spelling(number);
			}
			else {
				number = 3;
				spelling(number);
			}
		}

	}
}