#include <stdio.h>
#define YES 1
#define NO 0
#define MAX 1000
#define N 10
#define K 4

int lr1(void)
{
    float  L, V, t;
    printf("L=");
    scanf("%f", &L);
    printf("v=");
    scanf("%f", &V);

    if(V > 0)
    {
        t = (2 * L) / V;
        printf("t=%f\n", t);
    }
    else
        printf("error");

    return 0;
}

int dop1(){}

int lr2(void)
{
    long double s, a;
    long long int n, i, x, x1, fak, cnt;

    printf("n=");
    scanf("%lld", &n);
    printf("x=");
    scanf("%lld", &x);

    s = 0;
    i = 0;
    cnt = 0;
    x1 = 1;
    fak = 1;

    while(cnt < n)
    {
        a = (x1) / (long double)fak;
        s = s + a;
        i++;
        fak = fak * i;
        x1 = x1 * x;
        cnt += 1;
    }

    printf("s=%Lf",s);
    return 0;
}

int dop2(){}

int lr3()
{
    int c;
    int prevletter;
    int endofword = YES;
    int count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '.' || c == '\n' ||  c == ',') 
        {
            endofword = YES;
            if (prevletter == 'a' || prevletter == 'o' || prevletter == 'e' || 
            prevletter == 'u' || prevletter == 'y' || prevletter == 'i')
                count += 1;
        }

        prevletter = c;
    }

    printf("count: %d", count);

    return 0;
}

int dop3(){}

int lr4() 
{
    char str[MAX];

    int prestart = -1;
    int preend = -1;
    int start = -1;
    int end = -1;
    int i;

    fgets(str, MAX, stdin);

    for (i = 0; str[i] != '\0'; i++) 
    {
        if ((str[i] != ' ' || str[i] != '.' || str[i] != ',') && start == -1) 
        {
            start = i;
        } 
        else if ((str[i] == ' ' || str[i] == '.' || str[i] == ',') && start != -1) 
        {
            end = i - 1;

            if (prestart != -1) 
            {
                prestart = start;
                preend = end;
            } 
            else 
            {
                prestart = preend = start;
            }

            start = -1;
            end = -1;
        }
    }

    if (prestart != -1 && preend != -1) 
    {
        int len = preend - prestart + 2;

        for (i = preend + 2; str[i] != '\0'; i++) 
        {
            str[i - len] = str[i];
        }
        str[i - len] = '\0'; 
    }

    printf("%s\n", str);

    return 0;
}

int dop4(){}

int lr5( void )
{ 
    long long int x[N];
    long long int max, i, indexmax; 

    for(i = 0; i < N; i++)
        scanf("%lld", &x[i]);

    max = x[0];
    for(i = 0; i < N; i++)
    {
        if(x[i] > max)
        {
            max = x[i];
            indexmax = i;
        }
    }

    for(i = 0; i < indexmax; i++)
    {
        x[i] = 0;
    }

    for(i = (indexmax + 1); i < N; i++)
    {
        x[i] = max;
    }

    for( i = 0; i < N; i++ )
    {
        printf("%4lld ", x[i]);
    }

return 0;
}

int dop5(){}

int lr6() 
{
    int x[K][K];

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++) 
        {
            scanf("%d", &x[i][j]);
        }
    }

    int sumab = 0, sumbel = 0;

    for (int i = 0; i < K; i++)
    {
        for (int j = i + 1; j < K; j++) 
        {
            sumab += x[i][j];
        }
        for (int j = 0; j < i; j++) 
        {
            sumbel += x[i][j];
        }
    }

    if (sumab < sumbel) 
    {
        for (int i = 0; i < K; i++) 
        {
            for (int j = i + 1; j < K; j++) 
            {
                x[i][j] = 0;
            }
        }
    }
    else 
    {
        for (int i = 0; i < K; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                x[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < K; i++) 
    {
        for (int j = 0; j < K; j++) 
        {
            printf("%4d ", x[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int dop6(){}

int lr7() 
{
    unsigned long int P;
    unsigned char bytes[4];
    int difference;

    scanf("%lx", &P);

    for (int i = 0; i < 4; i++) 
    {
        bytes[i] = (P >> (8*i)) & 0xFF;
    }

    difference = bytes[1] - bytes[0];
    for (int i = 2; i < 4; i++)
    {
        if (bytes[i] - bytes[i-1] != difference) 
        {
            printf("Байты числа P не образуют арифметическую прогрессию.\n");
            return 0;
        }
    }

    printf("Байты числа P образуют арифметическую прогрессию.\n");

    return 0;
}
