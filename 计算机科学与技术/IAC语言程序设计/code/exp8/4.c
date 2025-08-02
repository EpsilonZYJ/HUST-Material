#include<stdio.h>

void store_float(FILE* fp);
void read_float(FILE* fp);

union u_tag
{
    float f;
    unsigned long l;
} u;

int main()
{
    float f;
    int i = 0;
    FILE* fp_in = fopen("float.dat", "wb");
    store_float(fp_in);
    fclose(fp_in);

    FILE* fp_out = fopen("float.dat", "rb");
    read_float(fp_out);
    fclose(fp_out);

    return 0;
}

void store_float(FILE* fp)
{
    float f;
    int i;
    for (i = 0; i < 10; i++)
    {
        scanf("%f", &f);
        fwrite(&f, sizeof(float), 1, fp);
    }

}

void read_float(FILE* fp)
{
    float lf;
    union u_tag m;
    int i;

    while (fread(&lf, sizeof(float), 1, fp) > 0) {
        //        fread(&m.f,sizeof(float),1,fp);
        //        printf("%f",m.f);
        m.f = lf;
        for (i = 0; i < 32; i++)
        {
            if ((m.l & 0x80000000) == 0)
            {
                putchar('0');
            }
            else
            {
                putchar('1');
            }
            m.l <<= 1;
        }
        printf("\n");
    }
}