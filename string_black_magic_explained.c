#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t len = 10;
    char* str = malloc(sizeof(char)*len);;
    char c = 'A';
    int a = 10;

    int size = getline(&str, &len, stdin);
    printf("Read from user: %d\n", size);
    printf("Len value: %d\n", len);

    printf("String: %s\n", str);
    printf("Char: %c\n", c);
    printf("Int: %d\n", a);

	return 0;
}
