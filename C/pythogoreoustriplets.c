#include<stdio.h>


void pythagorousTriplets(int sum)
{
	int a, b, c = 0;
	int m = 2;
	while (c < sum) {
		for (int i = 1; i < m; i++) {
			a = m * m - i * i;
			b = 2 * m * i;
			c = m * m + i * i;
			if (c > sum)
				break;
			if(sum == a + b + c)
				printf("%d %d %d\n", a, b, c);
		}
		m++;
	}
}


int main()
{
	int sum;
	printf("Enter sum of numbers: ");
	scanf("%d", &sum);
	pythagorousTriplets(sum);
	return 0;
}
