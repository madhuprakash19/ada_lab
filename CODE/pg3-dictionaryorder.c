#include <stdio.h>
#include <string.h>

int main()
{
    char a[5][50], temp[50];
    printf("Enter any 5 strings\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }
    }

    printf("\nIn sorted order\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", a[i]);
    }

    return 0;
}