#include <stdio.h>

int main()
{
	char str[10];
	scanf("%s",&str[0]);
	printf("Read from console: %s\n", str);

	int i = 0;
	while(str[i] != '\0') {
		printf("str[%d] = %c\n", i, str[i]);
		i++;
	}

	char str2[100];
	scanf("%s",&str2[0]);
	printf("Read from console: %s\n", str2);

	if( strcmp(str, str2) == 0 ) {
		printf("Equal\n");
	} else {
		printf("Different\n");
	}

	return 0;
}
