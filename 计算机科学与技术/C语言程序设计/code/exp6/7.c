void RemoveSame(int* a, int* n)
{
	int* p = a;
	int i = 0;
    int j = 0;
	while (i<(*n)-1)
	{
		if (*(p+i+1)!=*(p+i))
		{
			i++;
		}
		else
		{
			for(j = i + 2; j < (*n); j++)
            {
                *(p + j - 1)= *(p + j);
            }
            (*n)--;
		}
	}
	return;
}

int main(void)
{
	int n;
	scanf("%d", &n);

    int a[20];
	int* p;
    p = a;
    for (int i = 0; i < n; i++)
    {
	    scanf("%d", p + i);
    }

    RemoveSame(a,&n);

    for (int i = 0; i < n; i++)
    {
	    printf("%d", *(p + i));
	    if (i!=n-1)
	    {
		    printf(" ");
	    }
    }
    printf("\n");


	printf("%d", n);

	return 0;
}