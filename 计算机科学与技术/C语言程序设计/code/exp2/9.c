 #include <stdio.h>

int main(void)
{
	unsigned char c;
	while (scanf("%c", &c) >0 && c!='\n' && c != '\0'){
		unsigned char m;
        int cnt = c >> 6 & 0x3;
        unsigned char now0_c;
		m = (c >> 1 & 0x15) | (c << 1 & 0x2a);
        now0_c = m << cnt & 0x3f | m >> 6 - cnt & ~(~0 << cnt) | c & 0xc0;
        
		printf("%c", now0_c);

	}
    return 0;
}