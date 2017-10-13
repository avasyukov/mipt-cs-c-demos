#include <stdio.h>
#include <string.h>

int main()
{
    // Part 1 - string is a null-terminated array of chars

    char str[10];
    scanf("%s",&str[0]);
    printf("Read from console: %s\n", str);

    int i = 0;
    while(str[i] != '\0') {
        printf("str[%d] = %c\n", i, str[i]);
        i++;
    }

    // Part 2 - basic string manipulation functions

    char str2[100];
    scanf("%s",&str2[0]);
    printf("Read from console: %s\n", str2);

    // NEVER do this!
    if(str == str2) {
        printf("Seems to be equal\n");
    } else {
        printf("Seems to be different\n");
    }

    // Do this!
    if( strcmp(str, str2) == 0 ) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are different\n");
    }

    char str3[100];
    strcpy(str3, str2);
    printf("Copied: %s\n", str3);

    char addstr[] = "TEST";
    strcat(str3, addstr);
    printf("Concated: %s\n", str3);

    printf("Length of concated: %d\n", strlen(str3));

	return 0;
}
