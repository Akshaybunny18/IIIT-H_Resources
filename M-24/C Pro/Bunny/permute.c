#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *x, char *y);
void permute(char *a, int l, int r);

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int n = strlen(str);
    permute(str, 0, n - 1);
    return 0;
}
void permute(char *a, int l, int r)
{
    int i;
    if (l == r){
        static int count = 1;       
        printf("%d %s\n", count++, a); 
    }
    else
    {   
        //sscanf(a, "%s %d", &i);
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i)); //backtrack
        }
    }
}
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}