#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Исходная строка, так или иначе полученная
    char str[] = "123";

    // Всю строку целиком разбираем в число
    int vali = atoi(str);
    printf("Int from string: %d\n", vali);

    // Можно в long вместо int, если это уместно
    long int vall = atol(str);
    printf("Long from string: %d\n", vall);

    // Для обратной операции - snprintf
    char buf[20];
    snprintf(buf, 15, "%d", vali);
    printf("String from number: %s\n", buf);

    // Добрые хаки над строками, основанные на таблице ASCII
    int i;
    char c;
    int a;
    for(i = 0; i < strlen(str); i++) {
        printf("original char: %c\n", str[i]);
        a = str[i] - '0';
        printf("int from char: %d\n", a);
        c = a + '0';
        printf("char from int: %c\n", c);
    }

    return 0;
}
