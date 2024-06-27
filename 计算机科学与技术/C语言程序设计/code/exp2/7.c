#include<stdio.h>

int main() {
    char s[81];
    char c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    int m;
    scanf("%d", &m);
    m = m - 1;
    for (int j = 0; j < i; j++) {
        if (s[j] != ',' && s[j] != '.' && s[j] != '\x20') {
            s[j] += m;
            if (s[j]>90)
            {
                s[j] = (s[j] % 90) - 1 + 'A';
            }
        }
    }
    for (int j = 1; j < i ; j+=2) {
       char a;
       a = s[j - 1];
       s[j - 1] = s[j];
       s[j] = a;
    }
    for (int j = 0; j < i; j++) {
        printf("%c", s[j]);
    }

}