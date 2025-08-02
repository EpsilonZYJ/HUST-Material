 #include<stdio.h>

int main() {
	int i = 0;
	char s[10050];
	scanf("%d", &i);
	int cnt=0;
	int j;
	for ( j = 0; j < i; j++)
	{
		scanf("%d", &s[j]);
	}
	for ( j = 1; j < i-1; j++)
	{
		if ((s[j]>s[j-1]&&s[j]>s[j+1])||(s[j]<s[j-1]&&s[j]<s[j+1]))
		{
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}