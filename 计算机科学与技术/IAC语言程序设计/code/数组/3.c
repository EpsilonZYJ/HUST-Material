#include<stdio.h>

int main()
{
	/**********  Begin  **********/
	    char c[40][2];
    int i = 0;
    char a;
    for (int j = 0; j < 40; j++) {
        c[j][1] = 0;
    }
    for (int j = 0; j < 10; j++) {
        c[j][0] = j + 48;
    }
    for (int j = 10; j < 36; j++) {
        c[j][0] = j + 55;
    }
    while ((a = getchar()) != EOF) {
        if ((a <= 90 && a >= 65) || (a <= 57 && a >= 48)) {
            for (int j = 0; j < 36; j++) {
                if (c[j][0] == a) {
                    c[j][1] += 1;
                }
            }
        }
        else if (a > 96 && a < 123) {
            for (int j = 10; j < 36; j++) {
                if (c[j][0] + 32 == a) {
                    c[j][1] += 1;
                }
            }
        }
        else {
            c[37][1] += 1;
        }
    }
    for (int j = 0; j < 36; j++) {
        if (c[j][1] != 0) {
            printf("%c:%d\n", c[j][0], c[j][1]);
        }
    }
    if (c[37][1] != 1) {
        printf("others:%d", c[37][1]-1);
    }

	/**********  End  **********/
	return 0; 
}
