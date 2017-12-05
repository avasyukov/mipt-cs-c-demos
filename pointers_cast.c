#include<stdio.h>

void some_func(unsigned long long addr1, unsigned long long addr2)
{
    // Если адреса в силу чего-либо пришли без типа, 
    // то можно явным образом привести тип (если, конечно, известно, к чему приводить)
    long int *ptr1 = (long int*)addr1;
    long int *ptr2 = (long int*)addr2;

    // Дальше из них можно привычным образом читать
    long int buf;
    buf = *ptr1;

    // И не менее привычным образом писать в них
    *ptr2 = 42;
}

int main()
{
    long int a = 0;
    long int b = 1;
    // При тестировании из своего main-а, скорее всего, придётся тоже кастовать адреса к нужным типам
    some_func((unsigned long long)&a, (unsigned long long)&b);
    return 0;
}
