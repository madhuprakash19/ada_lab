#include <stdio.h>
#include <string.h>

int main()
{
    char a[20];
    int n;

    printf("Enter a string\n");
    scanf("%s", a);

    n = strlen(a);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c", a[i]);
    }
    return 0;
}