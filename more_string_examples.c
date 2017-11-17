#include<stdio.h>
#include<string.h>

void func(char* str)
{
    int i = 0;
    while(str[i] != '\0') {
        printf("Char[%d] = %c\n", i, str[i]);
        i++;
    }
}

int main()
{
    char s[] = "test";
    func(s);
    if(strcmp(s, "test") == 0)
        printf("Equal\n");
    else
        printf("Not equal\n");
    return 0;
}
