#include <stdio.h>

typedef struct {
	float x;
	float y;
} point;

int main()
{
	point p[10];

	for(int i = 0; i < 10; i++) {
		p[i].x = i;
		p[i].y = i;
		printf("x = %.2lf y = %lf\n", p[i].x, p[i].y);
	}

	return 0;
}
