#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j;

    // Размеры
    int n = 10;
    int m = 3;

    // Способ 1 - сделайте один malloc, придумав свою нумерацию внутри этого куска памяти
    int* arr1 = (int*)malloc(sizeof(int)*n*m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            arr1[i*m + j] = j; // здесь [i*m + j] - 1d-номер, который для нас логически 2d-шное [i][j]
        }
    }

    // Способ 2 - сделать массив указателей, не запутавшись в типах по дороге
    int** arr2 = (int**)malloc(sizeof(int*)*n);
    for(i = 0; i < n; i++) {
        arr2[i] = (int*)malloc(sizeof(int)*m);
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            arr2[i][j] = j; // здесь [i*m + j] - 1d-номер, который для нас логически 2d-шное [i][j]
        }
    }

    // Проверим, что вышло
    printf("Option 1:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", arr1[i*m + j]);
        }
        printf("\n");
    }

    printf("Option 2:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
